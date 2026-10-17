#!/usr/bin/env python3
"""fam_build.py FN...: build a func_001C28A0-family setup function from its listing values, then
order-search the volume stores and the tail stores. Matches land in build/sa/win_FN.c."""
import itertools
import os
import re
import struct
import subprocess
import sys
os.makedirs('build/sa', exist_ok=True)

TMPL = open('src/cod/sa_001932d8.c').read()
HEAD = TMPL[:TMPL.index('__attribute__')]
TAILN = {0x5EC: ('int', 'EM_WORK_5EC'), 0x5E8: ('int', 'EM_WORK_5E8'), 0x5E4: ('int', 'EM_WORK_5E4'),
         0x5F0: ('int', 'EM_WORK_5F0'), 0x5F6: ('short', 'EM_WORK_5F6'), 0x60C: ('unsigned char', 'EM_SUB_KIND')}
STD_CALLS = ['func_001B6FB8', 'cDamageManage_CreateDamageTake', 'func_001FD9D8', 'func_001C28A0']


def fl(v):
    s = f'{v:.7g}'
    if 'e' not in s and '.' not in s:
        s += '.0'
    return s + 'f'


def parse(fn):
    lst = subprocess.run(['python3', 'scripts/sa/lst.py', fn], capture_output=True, text=True).stdout
    lines = [l.split(None, 1) for l in lst.splitlines() if l and not l.startswith(('glabel', 'endlabel', '.', ' '))]
    calls = [a.strip() for op, a in lines if op == 'jal']
    if calls != STD_CALLS:
        return None, f'calls {calls}'
    freg, order, hi, slots = {}, [], 0, {}
    regs = {'$zero': 0}
    kind = None
    i_take = next(i for i, (op, a) in enumerate(lines) if op == 'jal' and 'CreateDamageTake' in a)
    i_fd = next(i for i, (op, a) in enumerate(lines) if op == 'jal' and 'func_001FD9D8' in a)
    for i, (op, a) in enumerate(lines[:i_take + 2]):
        args = [x.strip() for x in a.split(',')]
        if op == 'lui' and args[0] == '$at':
            hi = int(re.search(r'0x([0-9A-F]+)', args[1])[1], 16) & 0xFFFF0000
        elif op == 'ori' and args[0] == '$at':
            hi |= int(re.search(r'0x([0-9A-F]+) &', args[2])[1], 16)
        elif op == 'mtc1':
            v = struct.unpack('<f', struct.pack('<I', hi if args[0] == '$at' else 0))[0]
            freg[args[1]] = v
            if v not in order and v not in (0.0, 1.0):
                order.append(v)
        elif op == 'addiu' and args[0] == '$a2' and args[1] == '$zero':
            kind = int(args[2], 16)
        elif op in ('swc1', 'sw') and args[1].endswith('($sp)'):
            off = int(args[1].split('(')[0], 16)
            if off < 0x30:
                slots[off // 4] = 0.0 if args[0] == '$zero' else freg.get(args[0])
        elif op == 'mul.s':
            return None, 'mul.s'
    tailv = {}
    for op, a in lines[i_fd + 2:]:
        args = [x.strip() for x in a.split(',')]
        if op == 'addiu' and args[1] == '$zero':
            regs[args[0]] = int(args[2], 16)
        elif op in ('sw', 'sh', 'sb') and args[1].endswith('($s0)'):
            off = int(args[1].split('(')[0], 16)
            if off in TAILN:
                tailv[off] = regs.get(args[0])
    if set(tailv) != set(TAILN) or None in tailv.values() or any(slots.get(k) is None for k in (0, 1, 2, 4, 5, 6, 8, 9, 10)):
        return None, f'shape slots={slots} tail={tailv}'
    return dict(order=order, slots=slots, kind=kind, tail=tailv), None


def build(fn, d, body_order=None, tail_order=None):
    names = {v: f'c{i}' for i, v in enumerate(d['order'])}
    names[1.0] = 'one'

    def val(v):
        return '0.0f' if v == 0.0 else names[v]
    body = [f'    f[{k}] = {val(d["slots"][k])};\n' for k in (0, 1, 2, 4, 5, 6)] + ['    f[3] = one;\n']
    if body_order:
        body = [body[i] for i in body_order]
    tail = [f'    *({TAILN[o][0]} *)(p + {TAILN[o][1]}) = {d["tail"][o]};\n' for o in sorted(TAILN)]
    if tail_order:
        tail = [tail[i] for i in tail_order]
    decl = ', '.join(['one'] + [names[v] for v in d['order']])
    assign = ''.join(f'    {names[v]} = {fl(v)};\n' for v in d['order'])
    m = ''.join(f'    f[{k}] = {fl(d["slots"][k])};\n' if d['slots'][k] else f'    f[{k}] = 0.0f;\n' for k in (8, 9, 10))
    bo = '' if body_order else '/*ORDER*/\n'
    be = '' if body_order else '/*END*/\n'
    to = '' if tail_order or not body_order else '/*ORDER*/\n'
    te = '' if tail_order or not body_order else '/*END*/\n'
    return (HEAD + f'__attribute__((section(".text.{fn}")))\nint {fn}(char *p)\n{{\n'
            f'    float f[16];\n    float *m;\n    float *nv;\n    float *t;\n    void *slot;\n    float {decl};\n\n'
            f'    func_001B6FB8(p);\n    one = 1.0f;\n{assign}    t = &f[4];\n    m = &f[8];\n'
            + bo + ''.join(body) + be + '    t[3] = one;\n' + m + '    m[3] = one;\n'
            f'    slot = cDamageManage_CreateDamageTake(D_00574380, p, {d["kind"]});\n'
            '    *(void **)(p + EM_DMG_TAKE) = slot;\n    if (slot != 0) {\n        nv = &f[12];\n'
            '        f[12] = 0.0f;\n        f[13] = 0.0f;\n        f[14] = 0.0f;\n        nv[3] = one;\n'
            '        func_001FD9D8(slot, p + 0x80, m, nv, t);\n    }\n'
            '    *(short *)(p + EM_COL_A) = 1;\n    *(short *)(p + EM_COL_B) = 1;\n'
            '    *(char **)(p + EM_SUB_PTR) = p + EM_SUB_BUF;\n'
            + to + ''.join(tail) + te + '    *(short *)(p + EM_TARGET) = -1;\n    func_001C28A0(p);\n    return 1;\n}\n')


def search(path, fn):
    r = subprocess.run(['python3', 'scripts/sa/order_search.py', path, fn, '--compiler', 'sn-2.95.3-136', '--max', '6000'],
                       capture_output=True, text=True)
    m = re.search(r'best v(\d+) \((\d+)\)', r.stdout)
    return (int(m[1]), int(m[2])) if m else (None, None)


def perm(n, k):
    return list(next(itertools.islice(itertools.permutations(range(n)), k, None)))


for fn in sys.argv[1:]:
    d, why = parse(fn)
    if not d:
        print(fn, 'SKIP', why, flush=True)
        continue
    open(f'build/sa/fb_{fn}.c', 'w').write(build(fn, d))
    v, s1 = search(f'build/sa/fb_{fn}.c', fn)
    if v is None:
        print(fn, 'compile fail', flush=True)
        continue
    bo = perm(7, v)
    open(f'build/sa/fb_{fn}.c', 'w').write(build(fn, d, body_order=bo))
    v2, s2 = search(f'build/sa/fb_{fn}.c', fn)
    print(fn, f'body {s1} -> tail {s2}', flush=True)
    if s2 == 0:
        open(f'build/sa/win_{fn}.c', 'w').write(build(fn, d, body_order=bo, tail_order=perm(6, v2)))
