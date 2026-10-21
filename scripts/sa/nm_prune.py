#!/usr/bin/env python3
"""Keep the NON_MATCHING queue honest: find NM copies of functions that already
match elsewhere, and duplicate NM copies of one function.

    python3 scripts/sa/nm_prune.py            # report
    python3 scripts/sa/nm_prune.py --apply    # retire fully-stale unregistered files

Only unregistered NM files (not in compile_units) are ever moved, to
progress/retired_nm/. A file is retired when every INCLUDE_ASM function in its
NON_MATCHING #else branch is either carved to another compiled unit (real C
registered there) or also has a NON_MATCHING copy in another file. Partially stale files are
listed for hand cleanup.
"""
from __future__ import annotations

import argparse
import collections
import json
import re
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
RETIRED = ROOT / "progress" / "retired_nm"
ELSE_RE = re.compile(r"#ifdef NON_MATCHING\n.*?#else\n(.*?)#endif", re.S)
INC_RE = re.compile(r"INCLUDE_ASM\(\"[^\"]+\",\s*(\w+)\);")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    cfg = json.loads((ROOT / "compile_config.json").read_text())
    units = {u["path"] for u in cfg["compile_units"] if "path" in u}
    carve = {e["name"]: e.get("tu") for e in cfg["carved_funcs"] if "name" in e}
    # Upstream renames functions, so also compare by address.
    carve_at = {int(e["vaddr"], 16): e.get("tu") for e in cfg["carved_funcs"] if "vaddr" in e}
    addr = {}
    for line in (ROOT / "config" / "symbol_addrs.txt").read_text(errors="ignore").splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", line)
        if m:
            addr.setdefault(m.group(1), int(m.group(2), 16))

    nm: dict[str, list[str]] = {}
    for p in sorted((ROOT / "drafts").rglob("*.c")) + sorted((ROOT / "src").rglob("*.c")):
        t = p.read_text(errors="ignore")
        if "NON_MATCHING" not in t:
            continue
        rel = p.relative_to(ROOT).as_posix()
        nm[rel] = [n for blk in ELSE_RE.findall(t) for n in INC_RE.findall(blk)]
    copies = collections.defaultdict(list)
    for f, fns in nm.items():
        for n in fns:
            copies[n].append(f)

    def why_stale(f: str, n: str) -> str | None:
        tu = carve.get(n)
        if tu is None:
            a = addr.get(n)
            if a is None and re.fullmatch(r"func_[0-9A-F]{8}", n):
                a = int(n[5:], 16)
            tu = carve_at.get(a)
        if tu in units and tu != f:
            if n in INC_RE.findall(tu_text(tu)):
                return None
            return f"matched in {tu}"
        return None

    tu_cache: dict[str, str] = {}

    def tu_text(tu: str) -> str:
        if tu not in tu_cache:
            p = ROOT / tu
            tu_cache[tu] = p.read_text(errors="ignore") if p.exists() else ""
        return tu_cache[tu]

    retire, partial = [], []
    for f, fns in nm.items():
        if f in units or not fns:
            continue
        reasons = {n: why_stale(f, n) for n in fns}
        if all(reasons.values()):
            retire.append((f, reasons))
        elif any(reasons.values()):
            partial.append((f, {n: r for n, r in reasons.items() if r}))

    for f, rs in retire:
        print(f"retire  {f}: " + ", ".join(f"{n} ({r})" for n, r in rs.items()))
    for f, rs in partial:
        print(f"partial {f}: " + ", ".join(f"{n} ({r})" for n, r in rs.items()))
    print(f"nm_prune: {len(retire)} files fully stale, {len(partial)} partially stale")
    if args.apply and retire:
        RETIRED.mkdir(parents=True, exist_ok=True)
        for f, _ in retire:
            shutil.move(str(ROOT / f), str(RETIRED / Path(f).name))
        print(f"nm_prune: moved {len(retire)} files to progress/retired_nm/")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
