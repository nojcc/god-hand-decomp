"""fam_gen.py [--write] FN...: instantiate the sa_001932d8.c template with each function's constants/kind and report match_check."""
import os, re, subprocess, sys
os.makedirs('build/sa', exist_ok=True)
sys.path.insert(0, 'scripts/sa')
import fam_sig
write = '--write' in sys.argv
tmpl = open('src/cod/sa_001932d8.c').read()
for fn in [a for a in sys.argv[1:] if not a.startswith('--')]:
    consts, stack, scale, tail, calls = fam_sig.sig(fn)
    st = dict(s.split('=', 1) for s in stack)
    try:
        ca, cb = float(st['0']), float(st['1'])
    except (KeyError, ValueError):
        print(fn, 'shape?', stack[:8]); continue
    lst = subprocess.run(['python3', 'scripts/sa/lst.py', fn], capture_output=True, text=True).stdout
    kinds = re.findall(r'addiu\s+\$a2, \$zero, 0x(\w+)', lst)
    kind = int(kinds[-1], 16) if kinds else 0
    fl = lambda v: (f'{v:g}' if '.' in f'{v:g}' else f'{v:g}.0')
    s = tmpl.replace('func_001932D8', fn).replace('ca = 0.8f;', f'ca = {fl(ca)}f;').replace('cb = 1.7f;', f'cb = {fl(cb)}f;')
    s = s.replace('EM_SUB_KIND) = 4;', f'EM_SUB_KIND) = {kind};')
    out = f'src/cod/sa_{fn[5:].lower()}.c' if write else f'build/sa/fg_{fn}.c'
    open(out, 'w').write(s)
    r = subprocess.run(['python3', 'scripts/match_check.py', out, fn, '--compiler', 'sn-2.95.3-136'], capture_output=True, text=True)
    res = r.stdout.strip().splitlines()
    ndiff = sum(1 for l in res if l.startswith('!!'))
    print(fn, f'ca={ca:g} cb={cb:g} kind={kind}', res[-1] if res and res[-1].startswith('MATCH') else f'{ndiff} diffs')
