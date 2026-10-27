#!/usr/bin/env python3
"""Take NM-closer handoffs from progress/nm_solved/ into the matching build.

    python3 scripts/sa/nm_handoff.py            # verify only, print verdicts
    python3 scripts/sa/nm_handoff.py --apply    # also splice, register, file folders

Folder format: see progress/nm_solved/README.md.

The NON_MATCHING source holding the function is found by its INCLUDE_ASM line.
- Standalone draft (drafts/cod/<addr>.c, not a compile unit): the solved C,
  with the .text.<fn> section attribute, becomes src/cod/<addr>.c, and the
  draft is removed (or keeps its other functions). Compiler and per-file settings come from meta.json, else the NM
  header. Per-file flags must be in compile.py's per-file vocabulary, and the
  compiler must already be used by some registered unit.
- Function inside a registered TU: its `#ifdef NON_MATCHING ... #endif` block is
  replaced by the solved C (include line dropped). The unit's own compiler and
  flags are used; meta.json may not change them.

header_changes.md: each old declaration must occur exactly once in its header.
A handoff that changes a header is verified with one full build (compile.py):
build/SLUS_215.03.elf and build/rel/r207.rel must stay byte-identical to retail.
Handoffs without header changes share one full build at the end of the run.

Transactional: every file is copied into build/sa/handoff/journal/ before its
first write. A handoff that fails is rolled back to its own snapshot; an error,
Ctrl-C or SIGTERM rolls the whole run back; a run that was killed outright is
rolled back at the start of the next one. Folders move to done/ or rejected/
and the log is written only after the final build passes.

The final spliced text is what gets verified (match_check: instruction words
and relocation targets). Real C only. Results append to
progress/nm_solved/handoff_log.tsv (date, fn, verdict, reason) for checkpoints.
"""
from __future__ import annotations

import argparse
import datetime
import fcntl
import json
import re
import hashlib
import shutil
import signal
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

ROOT = Path(__file__).resolve().parents[2]
INBOX = ROOT / "progress" / "nm_solved"
LOG = INBOX / "handoff_log.tsv"
CFG = ROOT / "compile_config.json"
WORK = ROOT / "build" / "sa" / "handoff"

ASM_RE = re.compile(r"__asm__|\basm\s*(volatile\s*)?\(|\.word\b")
ALLOWED_ASM_RE = re.compile(r'__asm__\s*(__volatile__|volatile)?\s*\(\s*"(nop)?"\s*(:::\s*"memory"\s*)?\)\s*;')
GUARD_RE = r"#ifdef NON_MATCHING\n.*?#else\n[^#]*?INCLUDE_ASM\(\"[^\"]+\",\s*{fn}\);\n#endif\n?"
UNIT_KEYS_MODELED = {"path", "compiler", "c_flags_drop", "c_flags_add", "as", "fp_hazard_rules", "call_loop_pad",
                     "extern_jtbl"}
C_WORDS = set("""auto break case char const continue default do double else enum extern float for goto if
inline int long register restrict return short signed sizeof static struct switch typedef union unsigned
void volatile while u8 u16 u32 u64 s8 s16 s32 s64 f32 f64 __attribute__ section aligned packed""".split())


def asm_problem(text: str) -> str | None:
    code = re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)
    allowed = ALLOWED_ASM_RE.findall(code)
    rest = ALLOWED_ASM_RE.sub("", code)
    if ASM_RE.search(rest):
        return "contains inline asm or .word"
    if len(allowed) > 1:
        return "more than one inline nop/barrier"
    return None


def extra_definitions(text: str, fn: str) -> list[str]:
    code = re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)
    code = re.sub(r"__attribute__\s*\(\(.*?\)\)", "", code, flags=re.S)
    out = []
    for m in re.finditer(r"^([A-Za-z_][^;{}()]*?)\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{", code, re.M):
        if m.group(2) != fn and not re.search(r"\bstatic\b", m.group(1)):
            out.append(m.group(2))
    return out


def supported_flag_sets() -> tuple[set[str], set[str]]:
    text = (ROOT / "compile.py").read_text()
    out = []
    for name in ("SUPPORTED_C_FLAG_ADDS", "SUPPORTED_C_FLAG_DROPS"):
        m = re.search(rf"^{name} = frozenset\(\{{(.*?)\}}\)", text, re.M | re.S)
        out.append(set(re.findall(r'"([^"]+)"', m.group(1))) if m else set())
    return out[0], out[1]


def find_nm_source(fn: str) -> Path | None:
    pat = re.compile(rf"INCLUDE_ASM\(\"[^\"]+\",\s*{fn}\);")
    for p in sorted((ROOT / "drafts").rglob("*.c")) + sorted((ROOT / "src").rglob("*.c")):
        t = p.read_text(errors="ignore")
        if "NON_MATCHING" in t and pat.search(t):
            return p
    return None


def already_matched_in(fn: str, nm_rel: str, cfg: dict) -> str | None:
    """The registered owner TU, if it is not the NM source and defines fn in C (not via INCLUDE_ASM)."""
    owner = next((c.get("tu") for c in cfg.get("carved_funcs", []) if c.get("name") == fn), None)
    if not owner or owner == nm_rel or not (ROOT / owner).is_file():
        return None
    t = (ROOT / owner).read_text(errors="ignore")
    if re.search(rf"INCLUDE_ASM\(\"[^\"]+\",\s*{re.escape(fn)}\);", t):
        return None
    return owner if re.search(rf"\b{re.escape(fn)}\s*\([^;{{]*\)\s*\{{", t) else None


def handoff_addr(src: Path, fn: str, cfg: dict) -> str | None:
    """Lower-case 8-digit address for the new <addr>.c, never derived from a symbol's name text."""
    if (m := re.fullmatch(r"\w+_([0-9A-Fa-f]{8})", fn)):
        return m.group(1).lower()
    for c in cfg.get("carved_funcs", []):
        if c.get("name") == fn and c.get("vaddr"):
            return f"{int(c['vaddr'], 16):08x}"
    syms = ROOT / "config" / "symbol_addrs.txt"
    if syms.is_file():
        m = re.search(rf"^{re.escape(fn)}\s*=\s*0x([0-9A-Fa-f]+);", syms.read_text(errors="ignore"), re.M)
        if m:
            return f"{int(m.group(1), 16):08x}"
    return None


def header_opts(text: str) -> dict:
    head = text.split("\n", 1)[0]
    m = re.search(r"\((sn-[\w.\-]+|ee-[\w.\-]+|cygnus[\w.\-]*|gcc[\w.\-]*)", head)
    return {"compiler": m.group(1) if m else None,
            "c_flags_drop": ["-f=-freorder-blocks"] if "drop-reorder" in head else [],
            "c_flags_add": ["-O0"] if re.search(r"[\s,(]-O0\b", head) else [],
            "as": "sn" if "as=sn" in head else None,
            "fp_hazard_rules": (m.group(1) if (m := re.search(r"fp_hazard_rules[ =]([\w,]+)", head)) else None),
            "call_loop_pad": "call_loop_pad" in head,
            "extern_jtbl": []}


def check(path: Path, fn: str, o: dict) -> tuple[bool, str]:
    cmd = ["python3", "scripts/match_check.py", str(path), fn, "--compiler", o["compiler"]]
    if "-f=-freorder-blocks" in o.get("c_flags_drop", []):
        cmd.append("--drop-reorder")
    cmd += [f"--wrap-arg={f}" for f in o.get("c_flags_add", [])]
    if o.get("as") == "sn":
        cmd += ["--as", "sn"]
    if o.get("fp_hazard_rules"):
        cmd += ["--fp-hazard-rules", o["fp_hazard_rules"]]
    if o.get("call_loop_pad"):
        cmd.append("--wrap-arg=--call-loop-pad")
    cmd += [f"--extern-jtbl={s}" for s in o.get("extern_jtbl", [])]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    m = re.search(rf"^MATCH {fn} .*$", out, re.M)
    if m:
        return True, m.group(0)
    fails = [l for l in out.splitlines() if l.startswith(("FAIL", "COMPILE-FAIL"))]
    return False, "; ".join(fails) or (out.strip().splitlines() or ["no output"])[-1]


def remove_function(text: str, fn: str) -> str | None:
    """Drop fn's definition (with its section attribute) and INCLUDE_ASM line from a multi-function NM file."""
    inc = re.compile(rf"^INCLUDE_ASM\(\"[^\"]+\",\s*{fn}\);\n", re.M)
    m = re.search(rf"^(__attribute__\(\(section\(\"\.text\.{fn}\"\)\)\)\n)?[A-Za-z_][^\n;{{}}]*\b{fn}\s*\([^;{{]*\)\s*\{{", text, re.M)
    if not inc.search(text):
        return None
    if not m:
        # Older batch NM files list bare INCLUDE_ASM lines with no C attempt beside them.
        return inc.sub("", text, count=1)
    depth, k = 0, m.end() - 1
    while k < len(text):
        depth += {"{": 1, "}": -1}.get(text[k], 0)
        k += 1
        if depth == 0:
            break
    if depth:
        return None
    end = k + (1 if text[k:k + 1] == "\n" else 0)
    end += 1 if text[end:end + 1] == "\n" else 0
    return inc.sub("", text[:m.start()] + text[end:], count=1)


def with_section(text: str, fn: str) -> str:
    if f'section(".text.{fn}")' in text:
        return text
    m = re.search(rf"^[A-Za-z_][^\n;{{}}]*\b{fn}\s*\([^;{{]*\)\s*\{{", text, re.M)
    if not m:
        raise ValueError("cannot find function definition")
    return text[:m.start()] + f'__attribute__((section(".text.{fn}")))\n' + text[m.start():]


# ---------------------------------------------------------------- header changes

def parse_header_changes(path: Path) -> list[dict]:
    """`## <header path>`, then an old and a new label (`### old`, `Old:`, `**Old**`), each followed by one fenced block."""
    text = path.read_text()
    if re.fullmatch(r"\s*(none|n/a|-)?\.?\s*", text, re.I):
        return []
    changes = []
    label = r"^[ \t]*(?:#+[ \t]*)?\**{w}\**:?\**[ \t]*\n\s*```[a-z]*\n(.*?)\n```"
    for sec in re.split(r"^## ", text, flags=re.M)[1:]:
        hdr = sec.split("\n", 1)[0].strip().strip("`")
        old = re.search(label.format(w="old"), sec, re.M | re.S | re.I)
        new = re.search(label.format(w="new"), sec, re.M | re.S | re.I)
        if not (old and new):
            raise ValueError(f"header_changes.md: section {hdr!r} needs an old and a new code block")
        changes.append({"header": hdr, "old": old.group(1), "new": new.group(1)})
    if not changes:
        raise ValueError("header_changes.md has no '## <header>' sections")
    return changes


def declared_names(decl: str) -> set[str]:
    code = re.sub(r"/\*.*?\*/|//[^\n]*", "", decl, flags=re.S)
    names = set(re.findall(r"\b(?:struct|union|enum)\s+([A-Za-z_]\w*)", code))
    names |= set(re.findall(r"([A-Za-z_]\w*)\s*\(", code))
    names |= set(re.findall(r"#define\s+([A-Za-z_]\w*)", code))
    for stmt in re.findall(r"[^;{}]*;", re.sub(r"\{[^{}]*\}", " ", code)):
        ids = re.findall(r"[A-Za-z_]\w*", re.sub(r"\[[^\]]*\]|\([^()]*\)", " ", stmt))
        if ids:
            names.add(ids[-1])
    return {n for n in names if n not in C_WORDS}


def enclosing_names(header_text: str, snippet: str) -> set[str]:
    """Struct/union/enum names around `snippet` when it sits inside a braced body."""
    i = header_text.find(snippet)
    if i < 0:
        return set()
    depth, j = 0, i - 1
    while j >= 0:
        c = header_text[j]
        if c == "}":
            depth += 1
        elif c == "{":
            if depth == 0:
                break
            depth -= 1
        j -= 1
    if j < 0:
        return set()
    names = set(re.findall(r"\b(?:struct|union|enum)\s+([A-Za-z_]\w*)\s*$", header_text[max(0, j - 200):j]))
    depth, k = 1, j + 1
    while k < len(header_text) and depth:
        depth += {"{": 1, "}": -1}.get(header_text[k], 0)
        k += 1
    m = re.match(r"\s*([A-Za-z_]\w*)\s*;", header_text[k:])
    if m:
        names.add(m.group(1))
    return names


class Journal:
    """Copies of every file before its first write, kept on disk so an interrupted run can be undone."""

    def __init__(self, path: Path):
        self.path = path
        self.index: dict[str, str | None] = {}

    def save(self, f: Path) -> None:
        key = f.resolve().relative_to(ROOT).as_posix()
        if key in self.index:
            return
        self.path.mkdir(parents=True, exist_ok=True)
        if f.exists():
            copy = self.path / f"{len(self.index):04d}"
            shutil.copy2(f, copy)
            self.index[key] = copy.name
        else:
            self.index[key] = None
        (self.path / "index.json").write_text(json.dumps(self.index, indent=1))

    def save_from(self, key: str, copy: Path | None) -> None:
        """Adopt another journal's snapshot of key (the state before that handoff touched it)."""
        if key in self.index:
            return
        self.path.mkdir(parents=True, exist_ok=True)
        if copy is None:
            self.index[key] = None
        else:
            dst = self.path / f"{len(self.index):04d}"
            shutil.copy2(copy, dst)
            self.index[key] = dst.name
        (self.path / "index.json").write_text(json.dumps(self.index, indent=1))

    def write(self, f: Path, text: str) -> None:
        self.save(f)
        f.write_text(text)

    def unlink(self, f: Path) -> None:
        self.save(f)
        f.unlink()

    def restore(self) -> list[str]:
        for key, copy in self.index.items():
            f = ROOT / key
            if copy is None:
                f.unlink(missing_ok=True)
            else:
                f.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(self.path / copy, f)
        touched = sorted(self.index)
        self.discard()
        return touched

    def discard(self) -> None:
        shutil.rmtree(self.path, ignore_errors=True)
        self.index = {}

    @classmethod
    def recover(cls, path: Path) -> list[str]:
        """Undo a run that was killed before it could restore its files."""
        if not (path / "index.json").is_file():
            shutil.rmtree(path, ignore_errors=True)
            return []
        j = cls(path)
        j.index = json.loads((path / "index.json").read_text())
        return j.restore()


def sha(p: Path) -> str:
    return hashlib.sha256(p.read_bytes()).hexdigest() if p.is_file() else "missing"


def full_build() -> str | None:
    """One full compile.py build; None when the ELF and r207.rel match retail."""
    r = subprocess.run(["./scripts/container_run.sh", "python3", "compile.py"], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        return "full build failed: " + (r.stdout + r.stderr).strip()[-300:]
    for built, retail in (("build/SLUS_215.03.elf", "disc_extract/SLUS_215.03"),
                          ("build/rel/r207.rel", "disc_extract/rel/r207.rel")):
        if sha(ROOT / built) != sha(ROOT / retail):
            return f"full build: {built} no longer matches retail"
    return None


def apply_header_changes(changes: list[dict], j: Journal) -> str | None:
    for c in changes:
        h = ROOT / c["header"]
        if not h.is_file() or not h.resolve().is_relative_to(ROOT) or not c["header"].startswith(("include/", "src/")):
            return f"header {c['header']} not found under include/ or src/"
        txt = h.read_text()
        if txt.count(c["old"]) != 1:
            return f"old declaration occurs {txt.count(c['old'])}x in {c['header']} (need exactly 1)"
        j.write(h, txt.replace(c["old"], c["new"], 1))
    return None


# ---------------------------------------------------------------- one handoff

def process(folder: Path, apply: bool, j: Journal) -> tuple[str, str]:
    """Verify one handoff; with apply, splice and register it, writing every file through j."""
    fn = folder.name
    cs = sorted(folder.glob("*.c"))
    solved = folder / "solved.c" if (folder / "solved.c").is_file() else (cs[0] if len(cs) == 1 else None)
    if solved is None:
        return "rejected", "no single solved .c file in folder"
    text = solved.read_text()
    meta = json.loads((folder / "meta.json").read_text()) if (folder / "meta.json").is_file() else {}
    if (p := asm_problem(text)):
        return "rejected", p
    if (extra := extra_definitions(text, fn)):
        return "rejected", f"also defines non-static {', '.join(extra)} (duplicate symbols at link); one function per folder"
    src = find_nm_source(fn)
    if src is None:
        return "rejected", "no NON_MATCHING source with INCLUDE_ASM for it"
    rel = src.relative_to(ROOT).as_posix()
    cfg = json.loads(CFG.read_text())
    if (owner := already_matched_in(fn, rel, cfg)):
        return "rejected", f"already matched in {owner}; the NON_MATCHING block in {rel} is stale"
    unit = next((u for u in cfg["compile_units"] if u.get("path") == rel), None)
    old = src.read_text()
    WORK.mkdir(parents=True, exist_ok=True)

    rest = None
    if unit is None:
        if len(re.findall(r"INCLUDE_ASM\(", old)) != 1:
            rest = remove_function(old, fn)
            if rest is None:
                return "rejected", f"cannot cut {fn} out of multi-function {rel}; split by hand"
        o = header_opts(old)
        for k in ("compiler", "as", "c_flags_add", "c_flags_drop", "fp_hazard_rules", "call_loop_pad", "extern_jtbl"):
            if k in meta:
                o[k] = meta[k]
        if not (isinstance(o["extern_jtbl"], list) and all(isinstance(s, str) for s in o["extern_jtbl"])):
            return "rejected", f"meta extern_jtbl must be a list of symbol names, got {o['extern_jtbl']!r}"
        if not isinstance(o.get("call_loop_pad", False), bool):
            return "rejected", f"meta call_loop_pad must be true or false, got {o['call_loop_pad']!r}"
        if meta.get("drop_reorder") and "-f=-freorder-blocks" not in o["c_flags_drop"]:
            o["c_flags_drop"] = o["c_flags_drop"] + ["-f=-freorder-blocks"]
        if not o.get("compiler"):
            return "rejected", "compiler unknown (no meta.json, no NM header)"
        if o["compiler"] not in {u.get("compiler") for u in cfg["compile_units"]}:
            return "rejected", f"compiler {o['compiler']!r} is not used by any registered unit"
        adds, drops = supported_flag_sets()
        bad = [f for f in o["c_flags_add"] if f not in adds] + [f for f in o["c_flags_drop"] if f not in drops]
        if bad:
            return "rejected", f"per-file flags not in compile.py's vocabulary: {bad}"
        body = re.sub(r'^#include "include_asm.h"\n', "", text, flags=re.M)
        body = re.sub(r"^/\* NON_MATCHING[^\n]*\*/\n", "", body)
        try:
            body = with_section(body, fn)
        except ValueError as e:
            return "rejected", str(e)
        tag = ", ".join([o["compiler"]] + (["as=sn"] if o.get("as") == "sn" else [])
                        + ([f"extern_jtbl {' '.join(o['extern_jtbl'])}"] if o.get("extern_jtbl") else [])
                        + ([f"fp_hazard_rules {o['fp_hazard_rules']}"] if o.get("fp_hazard_rules") else [])
                        + (["call_loop_pad"] if o.get("call_loop_pad") else [])
                        + [f"+{f}" for f in o["c_flags_add"]] + [f"-{f}" for f in o["c_flags_drop"]])
        body = re.sub(r"^/\* (?:sn-|cygnus-|ee-)[^\n]*\*/\n", "", body.lstrip("\n"), count=1)
        new = f"/* {o['compiler']} */\n" + body.lstrip("\n")
        addr = handoff_addr(src, fn, cfg)
        if addr is None:
            return "rejected", f"cannot derive an address-based file name for {fn}"
        dest = ROOT / "src" / "cod" / f"{addr}.c"
        if dest.exists() and dest != src:
            return "rejected", f"{dest.relative_to(ROOT)} already exists"
        if dest == src and rest is not None:
            return "rejected", f"{rel} holds other drafts; move them to their own <addr>.c files first"
    else:
        extra = set(unit) - UNIT_KEYS_MODELED
        if extra:
            return "rejected", f"unit {rel} has settings match_check can't model ({sorted(extra)}); process by hand"
        o = {"compiler": unit["compiler"], "c_flags_drop": unit.get("c_flags_drop", []),
             "c_flags_add": unit.get("c_flags_add", []), "as": unit.get("as"),
             "fp_hazard_rules": unit.get("fp_hazard_rules"), "call_loop_pad": unit.get("call_loop_pad", False),
             "extern_jtbl": unit.get("extern_jtbl", [])}
        for k in ("compiler", "as", "c_flags_add", "c_flags_drop", "call_loop_pad", "extern_jtbl"):
            if k in meta and meta[k] not in (o.get(k), None, [], False):
                return "rejected", f"meta {k}={meta[k]!r} differs from registered unit {rel}; units are never changed"
        if meta.get("drop_reorder") and "-f=-freorder-blocks" not in o["c_flags_drop"]:
            return "rejected", f"meta drop_reorder=True but registered unit {rel} keeps reorder; units are never changed"
        body = re.sub(r'^#include "include_asm.h"\n', "", text, flags=re.M)
        new, n = re.subn(GUARD_RE.format(fn=re.escape(fn)), lambda _: body.strip("\n") + "\n", old, count=1, flags=re.S)
        if n != 1:
            return "rejected", f"cannot isolate the NON_MATCHING block for it in {rel}"
        dest = src

    hc = folder / "header_changes.md"
    changes = []
    if hc.is_file():
        try:
            changes = parse_header_changes(hc)
        except ValueError as e:
            return "rejected", str(e)
        if (err := apply_header_changes(changes, j)):
            return "rejected", err

    probe = WORK / (dest.stem + ".c")
    probe.write_text(new)
    ok, why = check(probe, fn, o)
    if not ok:
        return "rejected", f"re-verify failed: {why}"
    if changes:
        hs = ", ".join(sorted({c["header"] for c in changes}))
        why += f"; header change {hs}"
    if not apply:
        return "verified", f"{why} -> {dest.relative_to(ROOT)}"

    j.write(dest, new)
    if rest is not None:
        j.write(src, rest)
    elif dest != src:
        j.unlink(src)
    for f in (CFG, ROOT / "progress" / "sa_registered.json", ROOT / ".gitignore", ROOT / "config" / "symbol_addrs.txt",
              ROOT / "config" / "jtbl_extern_words.txt"):
        j.save(f)
    cmd = ["python3", "scripts/sa_register.py", "add", "--compiler", o["compiler"]]
    if unit is None:
        cmd += [f"--c-flags-drop={f}" for f in o["c_flags_drop"]]
        cmd += [f"--c-flags-add={f}" for f in o["c_flags_add"]]
        if o.get("as") == "sn":
            cmd += ["--as", "sn"]
        if o.get("fp_hazard_rules"):
            cmd += ["--fp-hazard-rules", o["fp_hazard_rules"]]
        if o.get("call_loop_pad"):
            cmd.append("--call-loop-pad")
        cmd += [f"--extern-jtbl={s}" for s in o.get("extern_jtbl", [])]
    cmd += [dest.relative_to(ROOT).as_posix(), fn]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        return "rejected", f"register failed: {(r.stdout + r.stderr).strip()[-200:]}"
    r = subprocess.run(["python3", "scripts/checks/carve_allowlist.py", "--fix"], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        return "rejected", f"allowlist failed: {(r.stdout + r.stderr).strip()[-200:]}"
    if changes and (err := full_build()):
        return "rejected", err
    if changes:
        why += ", verified by a full build"
    if rest is not None:
        why += f"; cut from {rel}"
    return "registered", f"{why} -> {dest.relative_to(ROOT)}"


def _interrupted(signum, frame):
    raise KeyboardInterrupt(f"signal {signum}")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    # Another run's journals look like an interrupted run to the recovery below, which would undo its work.
    WORK.mkdir(parents=True, exist_ok=True)
    lock = open(WORK / ".lock", "w")
    try:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except BlockingIOError:
        print("nm_handoff: another nm_handoff run is in progress; try again when it finishes")
        return 1
    run_journal = WORK / "journal"
    undone = []
    for d in sorted(WORK.glob("journal-*")):         # a handoff that was killed midway
        undone += Journal.recover(d)
    undone = sorted(set(undone) | set(Journal.recover(run_journal)))
    if undone:
        print(f"nm_handoff: an earlier run was interrupted; restored {len(undone)} files: {', '.join(undone)}")
    (INBOX / "done").mkdir(parents=True, exist_ok=True)
    (INBOX / "rejected").mkdir(parents=True, exist_ok=True)
    folders = [p for p in sorted(INBOX.iterdir()) if p.is_dir() and p.name not in ("done", "rejected")]
    if not folders:
        print("nm_handoff: nothing in progress/nm_solved/")
        return 0
    signal.signal(signal.SIGTERM, _interrupted)
    run = Journal(run_journal)
    results = []
    try:
        for f in folders:
            # each handoff gets its own snapshot so a rejection undoes only its own edits
            one = Journal(WORK / f"journal-{f.name}")
            try:
                verdict, why = process(f, args.apply, one)
            except Exception as e:
                verdict, why = "rejected", f"error: {e}"
            except BaseException:
                one.restore()
                raise
            if verdict == "registered":
                for key, copy in one.index.items():
                    if key not in run.index:
                        run.save_from(key, None if copy is None else one.path / copy)
            else:
                one.restore()
            one.discard()
            results.append((f, verdict, why))
            print(f"{f.name}\t{verdict}\t{why}", flush=True)
        if args.apply and any(v == "registered" for _, v, _ in results) and (err := full_build()):
            touched = run.restore()
            print(f"nm_handoff: final build failed ({err}); restored {len(touched)} files, nothing registered")
            return 1
    except BaseException as e:
        touched = run.restore()
        print(f"nm_handoff: stopped ({e!r}); restored {len(touched)} files: {', '.join(touched)}")
        raise
    run.discard()
    if not args.apply:
        return 0
    for f, verdict, why in results:
        sub = "done" if verdict == "registered" else "rejected"
        target = INBOX / sub / f.name
        if target.exists():
            target = INBOX / sub / f"{f.name}.{datetime.datetime.now():%Y%m%d%H%M%S}"
        shutil.move(str(f), str(target))
        if sub == "rejected":
            (target / "REJECTED.txt").write_text(why + "\n")
        with LOG.open("a") as fh:
            fh.write(f"{datetime.datetime.now():%Y-%m-%d %H:%M}\t{f.name}\t{verdict}\t{why}\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
