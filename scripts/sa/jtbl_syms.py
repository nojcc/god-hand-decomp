#!/usr/bin/env python3
"""List the retail jump-table symbols a function dispatches through, in address order.

    python3 scripts/sa/jtbl_syms.py func_00107F58

Each switch compiled to a table shows in retail as `lui %hi(D_x)` / `addiu %lo(D_x)`
followed by an indexed `addu` and a `lw` of the target (cygnus folds the %lo into the
`lw`), then usually a `jr`. The D_x symbols,
in the order the dispatchers appear, are what compile_units[].extern_jtbl (sa_register.py
--extern-jtbl, nm_handoff meta.json "extern_jtbl") takes. cc1 emits tables in source order,
which is usually the same order; if match_check reports a table count or order mismatch,
reorder the list.

A switch whose every case lands in the same place can compile to a table load followed by a
plain branch instead of a jr; this script doesn't list those (see func_002B12A0), so check the
asm when match_check says cc1 emitted more tables than were given.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def jtbl_syms(fn: str) -> list[str]:
    asm = (ROOT / "asm" / "cod" / "000000.s").read_text(errors="ignore")
    m = re.search(rf"glabel\s+{re.escape(fn)}\b(.*?)endlabel", asm, re.S)
    if not m:
        raise SystemExit(f"jtbl_syms: {fn} not found in asm/cod/000000.s")
    lines = m.group(1).splitlines()
    out = []
    for i, line in enumerate(lines):
        s = re.search(r"%lo\((D_[0-9A-F]+|jtbl_\w+)\)", line)
        if not s:
            continue
        # cygnus folds the low half into the load: lw $r, %lo(D_x)($r) ... jr $r
        fold = re.search(r"\blw\s+(\$\w+),\s*%lo\(", line)
        if fold:
            if re.search(r"\bjr\s+" + re.escape(fold.group(1)) + r"\b", "\n".join(lines[i + 1:i + 3])):
                if s.group(1) not in out:
                    out.append(s.group(1))
            continue
        # a table dispatch: the address is indexed (addu), a word is loaded from it,
        # and the code jumps through the loaded register
        for j in range(i + 1, min(i + 5, len(lines))):
            ld = re.search(r"\blw\s+(\$\w+),\s*0x0\(", lines[j])
            if ld:
                after = "\n".join(lines[j + 1:j + 3])
                if re.search(r"\baddu\b", "\n".join(lines[i + 1:j])) and \
                        re.search(r"\bjr\s+" + re.escape(ld.group(1)) + r"\b", after):
                    if s.group(1) not in out:
                        out.append(s.group(1))
                break
    return out


def extern_words(start: int, size: int) -> list[tuple[str, str]]:
    """Blob entries that jump into [start, start + size): (blob path, label address).

    Once the function is carved out of the monolith its .L labels are gone, so
    every such `.word .L<addr>` must be listed in config/jtbl_extern_words.txt
    (scripts/apply_jtbl_extern_words.py turns them into raw retail words).
    """
    out = []
    for blob in sorted((ROOT / "asm" / "data" / "cod").glob("*.s")):
        for m in re.finditer(r"\.word \.L([0-9A-Fa-f]+)\b", blob.read_text(errors="ignore")):
            a = int(m.group(1), 16)
            if start <= a < start + size:
                key = (blob.relative_to(ROOT).as_posix(), f"{a:08X}")
                if key not in out:
                    out.append(key)
    return out


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit(__doc__)
    syms = jtbl_syms(sys.argv[1])
    print(" ".join(syms) if syms else "(no jump tables)")
