# NM closer log

Scratch work lives in `progress/nm_work/` (tools in `progress/nm_work/tools/`; `mc.py` is
`scripts/match_check.py` with its cache redirected to `progress/nm_work/mc/`). Handoffs go to
`progress/nm_solved/<function>/`. Scores are differing instructions (plus word-count gap) vs retail.

| Function | Outcome | Time | Notes |
|---|---|---|---|
| cOmBase_setMeshAlphaFromLayer | solved | 1 min | C already exact; demoted at a halt only because its batch reseed/link failed. Re-verified, handed off. |
| func_001AA478 | solved | 1 min | Same: halt demote after batch link failure; C exact. |
| func_001BEB28 | solved | 1 min | Same: halt demote; C exact. |
| func_001DC710 | solved | 1 min | Same: halt demote; C exact. |
| func_001DD6D8 | solved | 1 min | Same: halt demote; C exact. |
| func_001EC8A8 | solved | 1 min | Same: halt demote; C exact. |
| func_001F0360 | solved | 1 min | Same: halt demote; C exact. |
| func_001F5E90 | solved | 1 min | Same: halt demote; C exact. |
| func_00200B20 | solved | 1 min | Same: halt demote; C exact. |
| func_002A4C38 | solved | 1 min | Same: halt demote; C exact. |
| func_003A7B48 | solved | 1 min | Same: halt demote; C exact. |
| func_003BAFD0 | gave up | 1 min | C already matches word for word; blocked by carving (the `D_003BAFE4` pointer table after it in `.text` loses its relocations). Not a C problem; main agent's call. |
| func_0032BE10 | solved | 5 min | Callee prototype: `func_00329EA8` takes `self` (was unprototyped `()`); beq became retail's annulled beql. Split out of 2-function NM file. |
| func_00356E98 | solved | 4 min | `return st->fC >= 3;` -> `if (st->fC < 3) return 0; return 1;` (slti+sltiu instead of slti+xori). Split out of 4-function NM file `sa_nm_00345250.c`. |
| func_00347FE0 | solved | 8 min | Callee arity: `func_00347968` takes 2 args (shared header `godhand/mwsfHn.h` declares 3; see header_changes.md). Split out of 2-function NM file. |
| func_001522C0 | solved | 3 min | Inverted the test: `if (type == 3) return pack+ofs; return pack;` (bnel became retail bne). |
| func_00143B70 | solved | 9 min | Callee return type: `cIDBase_initialize` returns int (was void); fixes $v0/$v1 choice for the %hi temp. Split from `batch38_nm.c`. |
| func_00312E88 | gave up (flagged) | 3 min | C fix found (callee `func_0014E598` returns void* not void) and matches, but the body uses the `VU0_SQC2_VF0` header macro (inline asm). Kept in `progress/nm_work/flagged/func_00312E88/` for the main agent to decide. |
| func_001582A0 | solved | 7 min | Signature: 7-param pass-through wrapper (was missing a3/f13) + 7-arg `setMotionInfo` prototype; float compare as `cur != (t0&4 ? -f12 : f12)`. |
| func_0033E5C0 | in progress | 20 min | 1 insn: retail bne with unannulled `li v0,1` delay slot, ours bnel. Tried switch/nesting/early-return/locals/int callees; permuter 15 min (manual PERM_RANDOMIZE on body) best 10 only via junk. |
| func_001C2408 | gave up | 0 min | Retail uses 2 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| InitObjVtableAndTypeFull_27EE68 | gave up | 0 min | Retail uses 5 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| InitObjVtableAndType_2772A8 | gave up | 0 min | Retail uses 3 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| InitObjVtable_27B768 | gave up | 0 min | Retail uses 6 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| Init_Vtable214_TypeName4AC_279CE8 | gave up | 0 min | Retail uses 5 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| Setup_278068 | gave up | 0 min | Retail uses 5 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| Setup_27DD88 | gave up | 0 min | Retail uses 12 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| cEmad_construct | gave up | 0 min | Retail uses 1 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_002C5338 | gave up | 0 min | Retail uses 1 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_0030A2E0 | gave up | 0 min | Retail uses 10 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_001BD1A0 | gave up | 0 min | Retail uses 7 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| Adjust_theta_vec | gave up | 0 min | Retail uses 11 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_0030A5D0 | gave up | 0 min | Retail uses 23 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_001F8080 | gave up | 0 min | Retail uses 25 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| capVu0Sin | gave up | 0 min | Retail uses 25 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| capVu0Cos | gave up | 0 min | Retail uses 26 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_00249770 | gave up | 0 min | Retail uses 12 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_0031C5C0 | gave up | 0 min | Retail uses 2 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_0024BDA0 | gave up | 0 min | Retail uses 1 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_002495E0 | gave up | 0 min | Retail uses 12 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| capVu0Atan2 | gave up | 0 min | Retail uses 28 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_0024BB68 | gave up | 0 min | Retail uses 9 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_00244398 | gave up | 0 min | Retail uses 3 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_00248D00 | gave up | 0 min | Retail uses 2 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_002299C0 | gave up | 0 min | Retail uses 19 VU0/COP2 instruction(s) (lqc2/sqc2/vf ops); no real-C form emits them, so it needs the VU0 inline-asm macros (not allowed for closer matches). Not attempted. |
| func_00201840 | solved | 3 min | Callee return type: `func_003A52F0` (memset) returns void*, not void. |
| func_001D9CA0 | solved | 4 min | State-byte stores written per branch with early return (cross-jump merges tails in retail order) instead of a goto tail. |
| func_00178E18 | in progress | 12 min | 0x5F4/0x5F6 halfword stores swap. Exhaustive order search of all 7 tail statements (5040 orders), store types, struct-member forms: none fix it. |
| func_00201960 | in progress | 8 min | Retail stores constant 1 from $v1 (and li v0,90 first); ours stores the call result $v0 (known ==1). Structured rewrites worse; trampoline arity (void) no effect. |
| func_00354B40 | in progress | 3 min | Clear loop: retail stores ent.b before the i+=8 increment. Loop forms tried: none. |
| func_0035A968 | in progress | 3 min | Prologue: retail `sd s0` before `li v0,-1`. Return-shape variants tried: none. |
| func_001DD340 | solved | 2 min | First call was missing its first argument: `(0x4D, 0)` -> `(arg0, 0x4D, 0)`. |
| func_001F3488 | solved (split) | 6 min | Callee prototype: CustomIDWork_SetColorAnimNormal_2D6898(void*, int color, unsigned short frames), colour passed as 0x80000000. |
| func_00331110 | solved | 5 min | `srd->d_mode = *mode;` instead of memcpy, and devtype assigned before stat. |
| func_00144B50 | solved (split) | 7 min | Asm loop increment rewritten as unsigned short for loop; `extern int cIDBase_initialize`; 0x364 store before 0x368. |
| func_0028E068 | solved | 3 min | `cSnd_SeStop(D_005FEE00, se)`: the 0x1550 field is the second argument. |
| func_001DBFB8 | gave up | 8 min | Only diff: the five int rank loads must stay lw (ours narrows to lhu). Only a volatile qualifier (BlackJack.h rank, or a volatile cast at each access) keeps lw without moving register allocation; an int temporary keeps lw but reallocates everything (121). Not a plausible original form. |
| func_0012BAF0 | gave up | 5 min | Retail keeps slti/nop/beqz/nop/bltz back to the shared return-0 block (bltz on an lbu value, so the sign test was not folded). Earlier agents tried &&, nested ifs, switch, goto, early returns, inlining; single inline nop placements and the SN assembler do not reproduce it. |
| func_0035A7A0 | gave up | 15 min | $v1/$a2 swap between the b->id load and the -1 constant. All rewrites, compilers and flags stay at 3; the permuter only zeroes it with a junk b->id++; b->id--; (rejected). |
| func_001F2A88 | solved | 2 min | First call was missing its first argument: `(0x12, 0)` -> `(arg0, 0x12, 0)`. |
| func_001346C8 | gave up | 6 min | Toolchain, not C: retail's assembler applied the R5900 short-loop pad (nop before bnel, 4 words before the branch) to a loop that has an internal exit branch (beqz). Our ee-as and ee-cc-wrap's --call-loop-pad only pad single-block loops; sn as gives the same 6 diffs. |
| func_003B9E10 | gave up | 30 min | Twin of ResetBufferOnFirstEnterA (identical C matches there). Retail keeps the counter in $a0 and the increment in $v0 ($v1 for %hi); ours folds into $v0. Compilers, allowed flags, int return all fail; permuter 10 min --all no improvement (30). Register allocation only. |

| func_003278E8 | solved | 3 min | C unchanged; needs drop-reorder (-f=-freorder-blocks dropped), recorded in meta.json. |
| func_001CD7A8 | solved (split) | 3 min | Final `-= 0.6f` goes through a fresh read of self->0xF0 instead of reassigning dst in the copy block. |
| func_001EA1A8 | solved (split) | 4 min | Table entry read as `*(short *)(idx + D_003BE528)` and function at `D_003BE528 + idx + 4` (two unmerged address calcs). |
| func_001573C8 | solved (split) | 6 min | Second compare `dx * pz > dz * px`; re-centring subtractions in order px, pz, bx, bz, dx, dz. |
| func_003526D0 | solved (split) | 5 min | Nested early returns: `if (now > start) { if (now < start + len) return 0; return 1; } return 1;`. |
| func_001A2630 | solved (FLAGGED) | 22 min | Tail call wrapped in `do { return ...; } while (0);` (permuter find; flagged as the allowed do-while(0) pattern). Swaps $s3/$s4 to retail. |
| BlackJack_UpdateNewRound | solved | 20 min | Stores duplicated into each branch (no mode temp) and flag test as separate 64-bit statements `tmp = flags; tmp = tmp >> 3; tmp = tmp & 1; if (tmp != 0)` — keeps lwu/dsra and avoids the dsll32/dsra32 truncation. |
| func_002B42F0 | gave up | 30 min | Head now matches retail with `int flags; unsigned long t; win->flags = flags & ~8; t = flags; t = t >> 6; t = t & 1; if (t != 0)` (progress/nm_work/func_002B42F0/i2.c). Blocker: retail keeps two identical `unk0F=0; state=7` blocks (if-branch and case 0x8000) that our jump2 cross-jumps into one. Early-return/goto/order variants fail; permuter manual-mode "zero" moved `state = 0` after the switch (changes semantics; its scorer ignores branch targets) — rejected. |
| func_002D5AD8 | solved (split) | 6 min | Semantics fix: mode 1 calls the hook with *(self+0x18); every other mode (0 and default) calls it with no args. `switch { case 0: default: ...; case 1: ...; }`. |
| cCoreSave_ckFightingRingClear | solved (split) | 12 min | `data->fightingRingClear[w] & (1 << bit)` via cCoreSaveData (removed the no-op `do {} while (0)`), with `bit &= 0x1F` before the `w >= 4` check (permuter find, plain reorder). |
| func_00201250 | solved (split) | 5 min | Goto-built loop `loop: i++; if (i >= 0x20) return; if (*(int *)(a0 + i * 0x88 + 4) == 0) goto loop;` — not a structured loop, so no strength reduction (retail keeps `mult` by 0x88). |
| func_002B4F38 | solved (split) | 8 min | Slot test as a `static inline unsigned char` helper (`if (*(int *)p != 0) return 1; return 0;`); inlining reproduces retail's branchy 0/1 + `andi 0xFF`. |
| func_00156508 | gave up | 3 min | Retail is hand-written asm (half->float bit conversion): runtime `srl` of a lui constant, trapping `add` (listing marks it handwritten), `daddu v0,a0` copy. Not reproducible from real C without asm. |
| func_0036DCE8 | gave up | 2 min | Retail is a timing loop of 5 consecutive nops + bgezl (`li v0,0x3F; loop: nop x5; bgezl v0,loop; addiu v0,-0x20`). Needs 5 inline nops (only one allowed); C loop bodies get deleted. |
| func_002BDF30 | solved (split, as=sn) | 9 min | `for (i = 0; i < n; i++) if (thresh <= (float)a1[i * 2 + 1]) return &a1[i * 2]; return 0;` plus SN assembler (`as: sn` in meta.json) for the mtc1 nop. |
| func_0030FB20 | solved (split) | 4 min | `if (obj != 0) { if (func_0030FCC0(obj) != 0) return obj; vcall(obj + vt->off, 3); } return 0;` — shared return-0 tail. |
| func_002736F8 | solved (split) | 3 min | `flag &= ~0x10000000; flag &= ~0x8000;` directly on the field, then `cEmSetParam_updateSetDataFlag(D_00586AB0, id, flag field)`. |
| func_00376A90 | gave up | 12 min | `for (i = 0; i < 0x30; i++) { char *p = D_00770850 + i * 0xE0; if (*(u16 *)p) { if (key == 0) return p; if (*(int *)(p + 4) == key) return p; } } return 0;` (progress/nm_work/func_00376A90/i1.c) is exact except retail has two padding nops before `beq v0,a0` (pads to a 16-byte boundary). No allowed flag or assembler (as=sn tried) emits that alignment. |
| func_00262980 | gave up | 30 min | Retail: `beq` with `li v0,0x49` in its delay slot, a `lw 0x680` duplicated in each arm, and the final stores ahead of the epilogue loads. if/else, duplicated-arm, and switch rewrites all score worse (31-36) than the goto version (15); permuter 10 min best 160/675, nothing clean. |
| RoundFloat | gave up | 8 min | Retail converts in-FPR with `cvt.w.s`/`cvt.s.w` twice (not CSE'd; our assembler can't even encode cvt.w.s, listing shows .word). Every compiler (sn, ee-2.9, cygnus; -ffast-math, drop-reorder) emits trunc.w.s + mfc1/mtc1. Looks like an inline-asm ftoi macro in the original. |
| func_00345250 | solved (split) | 3 min | `if (r->ent[i].stat != 1) return 0; return r->ent[i].val;` instead of a `v = 0` accumulator. |
| func_00350BE8 | solved (FLAGGED, drop-reorder) | 15 min | Early-return chain ending `if (s->f58 != 1 \|\| mode != 1 \|\| s->f968 <= s->f96C) return 0; return 1;`, `-f=-freorder-blocks` dropped (meta), and the file-local extern `func_003554E8` declared as returning `long` (its definition says int; one-line getter). Flagged for the int/long declaration mismatch. |
| func_002B4228 | gave up | 8 min | Code is right: with `as: sn` only the divide pad differs (retail mtc1/nop/div.s at the first divide, nop/nop/div.s at the second). Best hazard combination (ee-as + `mtc1,fdiv`) is 7 off, and nm_handoff doesn't take fp_hazard_rules from meta.json for cut functions anyway. Toolchain-only. |
| func_001FFEB8 | solved | 8 min | Real parameter widths (`unsigned short id`, `unsigned char a3`, `unsigned char a5`) give retail's entry `andi`s; id stored via `(id == D_00747A50) ? 0xFFFF : id`; pos[0..2] then f12 in field order (order found by brute force). |
| func_0035F5F0 | gave up | ~35 min | two.c at 5 diffs (prologue scheduling only). Permuter (10 min, then rotated) found only junk (uninitialized-variable branches). |
| func_002AC538 | solved | 10 min | Old source had the first comparison inverted. Retail: `for (i = 1; i < a2; i++) if (key at i >= key) { i--; break; }  return i;` |
| func_0033E5C0 | gave up | ~30 min total | 1 diff: retail fills the first branch's delay slot with plain `bne`, ours uses `bnel` (reorg annul choice). Tried else-if/early-return/switch/nested, local mode of short/int/long/char, int vs void callee and caller types. Shared file (sa_nm_00345250.c), so per-function flags can't be used. |
| func_00178E18 | gave up | ~30 min total | 2 diffs: retail schedules `sh -1 -> 0x5F4` before `sh 5 -> 0x5F6`. Brute-forced 109 placements of the two stores plus field-type variants; none matched. Scheduler only. |
| func_0019A0B8 | gave up | ~25 min (family) | 2 diffs: retail emits `sw 7 -> 0x5EC` before `sb 7 -> 0x60C`, ours is reversed. Same scheduler tie as func_00178E18. Tried 89 placements of the pair, a shared assignment, char vs unsigned char, and a struct overlay for the tail stores. |
| func_0019A328 | gave up | ~25 min (family) | 2 diffs: retail emits `sw 7 -> 0x5EC` before `sb 7 -> 0x60C`, ours is reversed. Same scheduler tie as func_00178E18. Tried 89 placements of the pair, a shared assignment, char vs unsigned char, and a struct overlay for the tail stores. |
| func_0019A590 | gave up | ~25 min (family) | 2 diffs: retail emits `sw 7 -> 0x5EC` before `sb 7 -> 0x60C`, ours is reversed. Same scheduler tie as func_00178E18. Tried 89 placements of the pair, a shared assignment, char vs unsigned char, and a struct overlay for the tail stores. |
| func_001C2280 | solved | 10 min | Natural stores of 0x630/0x634, then `if ((float *)(self + 0x640) != a3) { dst = ...; copy }` for both vectors. Replaces the comma-expression hack. |
| func_00201960 | gave up | ~30 min total | 2 diffs: after `v0 == 1`, our cse stores v0 to 0x110C where retail stores the constant register v1. Tried structured rewrites, statement order, and callee return types int/uint/long/short/uchar. |
| func_00354B40 | gave up | ~25 min total | 2 diffs: in the loop tail retail keeps `sw 0(v1)` before the bgez and the pointer increment in the delay slot; ours swaps them. Tried for/do-while/count-down, chained assignment, pointer local, unsigned index. Shared file (sa_nm_00345250.c). |
| func_0035A968 | gave up | ~25 min total | 2 diffs: prologue order (retail `sd s0` before `li v0,-1`). Tried early return vs nested, re-reading o->id, chained assignment, split calls, drop-reorder. |
| func_0027DB20 | gave up | ~30 min total | 3 diffs: retail fills the a1==1 branch's delay slot with `li v0,5` (plain beq); ours annuls with the 0x2F7 store. Tried goto orders, switch with case 0/default, per-case value variable, with and without the existing barrier. |
| cSceAtUnit_AreaSet | gave up | ~25 min total | Current source uses an asm register hack and scores 4. The plain call `func_001F88A8((char *)u + 4, v, (unsigned char)n, a, a, b);` (nm_work/cSceAtUnit_AreaSet/clean.c) scores 2: andi and mov.s swapped around the jal. Tried uchar param, & 0xFF, a copied float, int* arithmetic. |
| func_00123908 | gave up | ~20 min total | 4 diffs: prologue order (retail builds &D_00463050 in v0 then moves it to s0). The current source relies on asm register hacks; no real-C form reproduces it. |
| func_00307118 | gave up | ~25 min total | Retail branches (`bne` with v0=0 in the delay slot, plus an unfilled `jr ra; nop`). Every real-C form (if/return, result variable, switch, return types uchar/char/short/long/uint) compiles branchless (6 words vs 9). |
| func_0030F518 | gave up | ~25 min total | A plain float constant (2^-31) gives 4-5 diffs: retail converts through $f4 into $f1 before the constant load. Tried operand order, float locals, unsigned temp. The current source uses an asm hack. |
| func_00347C80 | gave up | ~25 min total | 4 diffs: retail schedules `addiu %lo(D_004590D8)` right after its lui, ours after the argument moves. Tried varargs/const/void* prototypes, int returns, if/else orders, result local, drop-reorder (worse). |
| func_00347E58 | gave up | ~30 min total | 5 diffs: retail reloads concat (lb) after the concatSave store and hoists the sfd load into a delay slot. Tried natural if-chains, ok vs 1 compares, a local sfd before or after the first block, nested ifs (5-10 diffs). |
| func_00307060 | gave up | ~20 min total | 5 diffs, register allocation only (a0/v0/v1 rotation in the merge test). Tried operand orders, shift vs multiply, subtraction form. |
| func_0037D298 | gave up | ~15 min | 8 diffs, register allocation only (v0/v1/a1 roles in the table index). Tried direct and indirect calls, char param, (char) fn-pointer table, void* table with cast, unsigned index, typedef. |
| func_002FEBE8 | gave up | ~20 min | Natural ushort form scores 7 (current source 8): retail hoists the base load above `a2 == 1` and puts cur-base in the beq delay slot. Tried || and if/else chains, a switch, int vs ushort locals, a hoisted diff local. |
| cSnd_IsEnemyAlive | gave up | ~40 min | Best v_k1.c at 34 diffs: early-return inline helpers returning unsigned char, plus a caller local `k = em->kind`. Retail routes each helper result through a separate temp (a0) before the `andi 0xFF`; ours coalesces into v0. Tried 8 helper bodies, param types, flattened ifs. Permuter 15 min, no improvement. |
| func_00164238 | solved | 25 min | Switch in 0..3 order; case 0 `*(unsigned short *)(self+0x134) = 0xFFFF;` before the 0x60 store; case 3 `goto clear` into case 2's shared `0x134 = 0` tail (FLAGGED). |
| func_0035EB60 | solved | 25 min | `0x51U` literals keep 0x51 in a register for the final xor; last check `{ r = 4; return r; }` (FLAGGED). Found via permuter (manual ablation of its zero). Registered unit, file settings. |
| func_001C2328 | gave up | ~40 min total | Best s1.c (switch on 2/3/6/7) at 11-12 diffs: retail has a stray nop between slti and bnez plus an unfilled bnez slot, and shares the early return-0 block. Tried the if-chain, the switch, as=sn. |
| func_00352C78 | gave up | ~30 min total | 13 diffs: retail materializes &rec[0] in v0 for the time subtract and keeps time in a register (no stack writeback). Every no-writeback form (last->time = time - first->time, SftimWork *w, r0 pointer) re-lays out the earlier copies (78-79 words vs 81). Shared file (sa_nm_003525f0.c). |
| func_0018EF58 | gave up | ~15 min | 19 diffs: frame store order and register pairing for the two Vec constructions (retail stores half.y/z before size). Tried half(size), half = size, swapped declarations, ofs from half, -0.5 factoring. Family-wide behavior of the shared cDamageVec.h class, which belongs to the main agent. |
| func_00150418 | solved | 8 min | Natural `for (o = first; o; o = next) { next = iter(o); virtual delete(o, 2); }` then free; replaces the hand-rotated do/while. |
| func_002BEAA8 | gave up | ~20 min | 19 diffs: retail has a nop before the 4-insn search loop plus a different register assignment for the two walking pointers. Tried struct table with for/pointer/nested forms (20-25 words vs 21); SN assembler doesn't add the nop; shared file. |
| func_002D0B88 | solved | 12 min | Fallback stores id then param[0..4] in natural order, `found = &D_003C3120;` last (store order found by brute force). |
| func_00377FA0 | gave up | ~20 min | Retail keeps three separate loads of the 0x20 field (lh, lhu, lhu) and returns the low byte of the value before the +1 adjust (the current source returns it after, a semantic mismatch). Making only the middle read volatile reaches 4 diffs, but that isn't plausible source, so rejected. All-volatile or no-volatile forms give 18-25. |
| func_00182690 | gave up | ~10 min | 25 diffs: same damage-volume family. Retail copies each Create* result to a0 before the beqz and schedules the frame stores differently. Tried assignment-in-condition, chained assignments, re-reading the stored pointer; no change. |
| sceGsSetHalfOffset | gave up | ~10 min | 23-26 diffs, scheduling of the ee-gcc 2.9 sign-extension and shift sequences. Tried w/h and ofx/ofy statement orders and if/else vs ternary for the halfoff store (best 23). |
| Adjust_theta | gave up | ~3 min | Retail is inline asm (`add` flagged as hand-written, raw cvt.w.s .word, t-regs, trailing mov.s). Can't be reproduced in real C. Semantics: n=(trunc(th/pi)+(th>0))&~1; return th-n*pi. The current src drops the rounding step. |
| func_001552F0 | gave up | ~35 min | m1.c is structurally right (d var for first div, literal 24 for second, n=cnt/24+1), only register allocation left. Permuter 15 min: base 175 -> 55 via junk (cnt & 0xFFFF), rejected. |
| func_001551E0 | gave up | ~10 min | Sibling of func_001552F0, same register-allocation gap (m4 = 9). |
| F32toF16 | gave up | ~25 min | Best 21 (s2/t31: ushort sign, reuse absv for mant). Retail keeps andi 0xFFFF on the early sign|0x7FFF return; every type combo (ret ushort/int/short x sign int/uint/ushort/short, three sign exprs, sign assigned twice) lets combine fold it. With int sign the rounding order matches (mant + (bit + 0xFFF)). |
| func_0034C890 | permuter queue | ~20 min | Needs drop_reorder (standalone). Best: b1 with dr = 6 (busy==0 tail call first, `(Entry34C *)(self+0x1310) + idx`, but adds self+off then 0x1310). Two-step e1 (`e = base; *out = 0; e += idx;`, sibling 0034C930 style) with dr = 11: address order right, v0/v1 swapped. |
| func_0034F8D0 | permuter queue | ~15 min | Needs drop_reorder. a2 (ternaries + `if (call < lim) return 0; return 1;`) with dr = 18. Retail materializes cfg = hn+0xA0C in s0 and loads maxFill once via 0x58(s0) in the bgtz delay slot. Every max/cfg->maxFill mix folds the offset or loads twice. |
| func_001DF7D0 | permuter queue | ~15 min | py1: three separate tests `if (v==0) A else if (v<0) A else if (v<7) B else A` = 12 (the combined || form folds into a range check). Left: retail keeps the value in a1 and copies cond to v1; ours copies the result to a1. Select form and declaration order don't matter. |
| func_00331070 | gave up | ~10 min | Retail fills the 3rd stat beq's delay slot with `lui a0` while the beq reads a0. Our cygnus reorg refuses (branch-needed resource). Callee protos, volatile, switch, nested ifs, dr all unchanged. Not reachable from C. |
| cObjBaseArray_SearchOM | SOLVED | ~20 min | cGameObj_idInRange(o,0x300,0x500) & 0xFF (header helper) + for loop re-reading end. |
| func_001E3758 | SOLVED | ~8 min | Natural switch with ushort fields + void displayScrollLayer prototype (implicit int decl was the last diff). |
| func_00170F60 | SOLVED | ~8 min | SetVec4 + CopyVec3 inline helpers (repo idiom), gives the f[2] reload. |
| func_002C0B38 | gave up | ~10 min | 27: FP register choice (x0/z0 f9/f6) and last test sharing the return-0 block (v0=1 in delay). Tried test operand order, subtract order, return !(...), -ffast-math via mc --wrap-arg. No movement. |
| func_002CA5D8 | SOLVED (manual pkg) | ~10 min | static inline unsigned long SndVoice_flagBit2(fl) keeps the dsrl. Needs call_loop_pad (meta.json can't carry it; noted in the handoff README). |
| func_00195850 / func_001AA058 | permuter queue | ~35 min | w4 = 4 diffs on both: natural form, no asm barrier, `sub` var for the first vcall, `fn` var only for the player calls. Retail wants the player-call fn in a1. Permuter zero was junk (`if (vt || fn)` on uninit vars), rejected. Tried CopyVec3, CEM00_VCALL0, fn sharing variants. |
| func_001DEB08 | permuter queue | ~12 min | k2 = 16: `to` built field by field (r,g,b=0xFF, a=0x80) instead of from|0xFFFFFF, which gives retail's or-with-0x80000000. Left: register naming (self t0, consts a2/a3). |
| func_002BECB0 | permuter (2nd run) | | dw.c = 7: do { if ... } while (0) around the slot test (permuter idea, FLAG if used). Register naming only. |
| func_00171B70 | SOLVED | ~3 min | SetVec4 + CopyVec3 helpers (00170F60 family). |
| func_0017C508 | SOLVED | ~4 min | SetVec4/CopyVec3 + corrected constants 4.22f/3.812f. |
| func_001BD1A0 | SOLVED | ~12 min | Twin of cOmBase_startKnockStep (001599b0.c). FLAG: do { VU0_LQC2 } while (0), same as the registered twin. |
| func_0031D3D0 | src/cod/sa_nm_0031d2f8.c | SOLVED | scalar-arg SetVec4xyz for pos/rot/scale (79->4), vcall typed `int (**)()` like 001ee780.c -> MATCH 161 |
| func_003077E8 | src/cod/batch30_nm.c | SKIP | no NM source any more (already resolved) |
| func_00156550 | src/cod/batch29_nm.c | GAVE UP | retail is EE MMI (psllw/pand/paddw/por) - inline asm in original, not real-C reproducible |
| func_002FA350 | src/cod/sa_nm_002fa350.c | GAVE UP | cvt.w.s in-FPR conversion (assembler emits .word) - same inline-asm ftoi as RoundFloat; no compiler emits it for (int) |
| func_002FA3E0 | src/cod/sa_nm_002fa350.c | GAVE UP | twin of func_002FA350, same cvt.w.s blocker |
| func_001F8810 | src/cod/sa_nm_001f8810.c | BLOCKED (flag) | current source MATCHES (35 insns) with -ffast-math + fp_hazard_rules sqrt + `-f=-malign-loops=2` (the do{}while(0) loop note aligns the return-0 label to 8; retail unaligned). Twin TU 001f8550.c still matches under that flag. Flag not in SUPPORTED_C_FLAG_ADDS, so no handoff; proof in nm_work/func_001F8810/proof_malign_loops2.txt |
| func_001F32A0 | src/cod/sa_nm_001f32a0.c | PERM QUEUE | uninitialised bitfield colour temps, reg choice only (38); order/scope/inline-maker variants no help |
| func_002B4028 | src/cod/sa_nm_002b4028.c | PERM QUEUE | clamp -> movz where retail branches; 10 shape/type variants; best t2.c (unsigned short w) 9 |
| func_002C0C28 | src/cod/sa_nm_002c0b38.c | PERM QUEUE | 1 insn with -ffast-math + fdiv: reorg drops redundant v0=0 in last bc1t slot; 10 shape/flag variants no help |
| func_002BECB0 | src/cod/batch30_nm.c | PERM ROTATED | 15 min on dw.c, stuck at base 45 |
| func_00312DB8 | src/cod/inbox_nm_func_00312DB8.c | SOLVED | rewritten as SGI STL random-access find (unrolled trip loop + fallthrough switch) -> MATCH 52 first try |
| func_0032C1E0 | src/cod/sa_nm_0032be10.c | SOLVED | load out+in before combined `out == 0 \|\| in == 0` early return (in load lands in first delay slot) -> MATCH 50 |
| func_003A5148 | src/cod/sa_nm_003a5148.c | PERM QUEUE | newlib memcpy: retail keeps dst0/dst/aligned_dst in 3 regs (t0/v1/a3); return-dst0, len typing, 6 compilers no help |
| func_00352790 | src/cod/sa_nm_003525f0.c | PERM QUEUE | with drop-reorder (header says no -freorder-blocks; inventory says false) + decl order drop,rate,ofs: 47 -> 5 (o2.c); left: v0/v1 swap in fld[].fieldB copy, 7 shape variants no help |
| func_00352AA0 | src/cod/sa_nm_003525f0.c | PERM QUEUE | 39 under drop-reorder; load order/association differences, expression variants no help |
| func_0032F988 | src/cod/sa_nm_0032f988.c | GAVE UP | retail saves ra in a 0x10 frame with no calls (inlined BE32/BE16); static/extern/plain inline all frameless, static non-inline makes real calls. Remaining scheduling looks like per-call arg eval. Likely build quirk (inline-after-expand), not reachable with supported flags |
| func_0035ED08 | src/cod/0035e8.c (registered) | GAVE UP | retail lowers the switch to a compare tree (count 6, range 21 -> table in every compiler here); dropping case 0 / GNU ranges still table; if-chain 27-29, explicit goto tree 28 (epilogue threading differs) |
| func_001DC4C0 | src/cod/sa_nm_001dbeb0.c | PERM QUEUE | regressed 2 -> 55 when BlackJackCard.flags became unsigned (SN builds ~4 with lui/ori); header revert would break 001d2ee0.c (long f = flags). `flags = (int)flags & ~4` restores 2 (k1.c); left: outer-loop back-edge i copy vs slti order, 6 loop shapes no help |
| func_003542B8 | src/cod/sa_nm_00353928.c | PERM QUEUE | needs drop-reorder (header says no -freorder-blocks; inventory false). Only real diff is the picture-type index: retail lbu/dsrl 3/andi 7/sll 2; `unsigned long ty = p[5]; D[(int)(ty >> 3) & 7]` (f3.c) gets lbu/andi/sll split but dsll29+dsra32 for the shift (36, rest is a 2-word shift + pad). 20 index spellings tried |
| func_0034C890 | src/cod/sa_nm_0034c890.c | PERM ROTATED | 15 min on b1.c (drop-reorder): best 290 from base 495 was a dead temp (`*out = (new_var = e->value)`), rejected |
| func_00155AE8 | src/cod/sa_nm_00155ae8.c | PERM QUEUE | retail copies id to t3, tests the copy, narrows t3 in place (1-insn shift); short/char/long param, hoisted idx no help |
| func_00298F88 | src/cod/sa_nm_00298f88.c | GAVE UP | retail keeps hi(D_00754C58)/hi(D_0044AC30) (multi-use) in s1/s0 but builds the final call args late; ours with gcse hoists all four his into s0-s3, with -fno-gcse none (66). Dropping the tbl local (as matched twin func_002990A0) no help |
| func_0030D258 | src/cod/sa_nm_0030d1f8.c | GAVE UP | retail second loop not strength-reduced/reversed, n = 0x400000>>8 computed at runtime (lui/dsra), short args kept <<16 in s3-s5; ours folds n and reverses the loop (48 vs 64 words). call-loop-pad no help. Different optimisation profile |
| func_001EDC28 | src/cod/inbox_nm_func_001EDC28.c | PERM QUEUE | rewritten from m2c: CidColor bitfields (as matched sa_001f3488.c), single switch {case 0/default, 1, 2, 3} reproduces retail case tree + block order: 76 -> 20 (y2.c). Left: uninitialised colour temps register choice (from built v1->a1, to in a2), same as func_001F32A0; 8 decl/build/scope combos + 3rd param no help |
| func_001D5E08 | src/cod/inbox_nm_func_001D5E08.c | SOLVED | rewritten from m2c as switch (unsigned short mode) {case 0/default; 1; 2; 3} with real prototypes -> MATCH 82 |
| func_00257E90 | src/cod/inbox_nm_func_00257E90.c | PERM QUEUE | was non-compiling m2c; rewritten with real prototypes from retail (func_002A8578 7-arg w/ float, cSnd_SeCall 8-arg): w1.c 119 (2 short), v_i.c (mask at call site) right length 26 diffs: retail keeps call result live across the 0x3AC flag test (flag in v1, andi t0 in beqz delay slot, p reloaded per branch); 15 variants tried |
| func_001DB440 | src/cod/inbox_nm_func_001DB440.c | SOLVED | TickDown static inline (from 001db558.c) + case 1 fallthrough into case 0 -> MATCH 70 |
| func_003404B0 | src/cod/inbox_nm_func_003404B0.c | GAVE UP | non-compiling m2c rewritten (cygnus): body identical, only prologue scheduling differs (retail: addiu sp first, sd ra after lui a0; ours: lui a0 first, sd ra last); 8 source variants (arg types, array/ptr, param from caller 00322f58.c) no effect |
| func_0030D190 | src/cod/inbox_nm_func_0030D190.c | SKIP | needs sync + ei instructions (inline asm only) |
| func_001DC4C0 | src/cod/blackjack | PERM ROTATED | pk1.c PERM_RANDOMIZE outer loop 15 min: base 340 no improvement; k1.c (2 diffs) stays best |
| func_00322F80 | src/cod/inbox_nm_func_00322F80.c | SOLVED | non-compiling m2c fixed (externs/prototypes) -> MATCH 31 |
| func_0030B698 | src/cod/inbox_nm_func_0030B698.c | SOLVED | non-compiling m2c fixed (externs/prototypes) -> MATCH 36 |
| func_00325818 | src/cod/inbox_nm_func_00325818.c | SOLVED | non-compiling m2c fixed; extern volatile int D_003C8148 (thread id) gives retail addiu+lw 0; drop_reorder -> MATCH 37 |
| func_0017EAF8 | src/cod/inbox_nm_func_0017EAF8.c | SOLVED | near-clone of sa_0017c508.c (SetVec4 + CopyVec3 self-check inline) -> MATCH 39 |
| func_00349840 | src/cod/inbox_nm_func_00349840.c | SOLVED | non-compiling m2c rewritten; no local for D_003EC7DC (literal 1 compares), p init in for header; drop_reorder -> MATCH 42 |
| func_0014E818 | src/cod/inbox_nm_func_0014E818.c | SKIP | needs VU0 lqc2/vsub.xyz/sqc2 (inline asm only) |
| func_00330A68 | src/cod/inbox_nm_func_00330A68.c | SOLVED | rewritten; permuter (15 min run, 4 min) found len+1 computed in else branch; reduced to clean C; drop_reorder -> MATCH 25 |
| func_0016C678 | src/cod/inbox_nm_func_0016C678.c | SOLVED | rewritten with CopyVec3 inline + prototypes; +0x2C store before +0x28 -> MATCH 46 |
| func_0017B010 | src/cod/inbox_nm_func_0017B010.c | SOLVED | non-compiling m2c rewritten with prototypes -> MATCH 50 |
| func_001A7940 | src/cod/inbox_nm_func_001A7940.c | SOLVED | C rendering of g++ PMF dispatch (Pmf table struct copy, aligned(8) VtEnt, int off ternary) -> MATCH 50 |
| func_001689E8 | src/cod/inbox_nm_func_001689E8.c | SOLVED | twin of func_0016C678 (CopyVec3 inline, swapped zero stores) -> MATCH 52 |
| func_00167FA8 | src/cod/inbox_nm_func_00167FA8.c | SOLVED | non-compiling m2c rewritten with prototypes -> MATCH 54 |
| cOl0e_setFake | src/cod/inbox_nm_cOl0e_setFake.c | PERM QUEUE | non-compiling m2c rewritten (long flags idiom from 001a6188.c, int on, unsigned char bit != 1 keeps the compare-with-1): e.c right length; left: retail keeps tail stores 2F5/5B8/2F6/2F7/24C in source order with mtc1 hazard nop (ours hoists the float store), and f=5B8 load reg order |
| func_0032AFB0 | src/cod/inbox_nm_func_0032AFB0.c | SOLVED | rewritten; volatile D_003D140C + count-up for loop over 0xC8 records; drop_reorder -> MATCH 59 |
| func_0032D250 | src/cod/inbox_nm_func_0032D250.c | SOLVED | rewritten; count-up loops over 0x278 records; drop_reorder -> MATCH 59 |
| func_00324AC8 | src/cod/inbox_nm_func_00324AC8.c | SOLVED | rewritten; count-up loop over 0xC8 records; drop_reorder -> MATCH 74 |
| func_0025E600 | src/cod/inbox_nm_func_0025E600.c | SOLVED | rewritten; PMF dispatch rendering (as func_001A7940) + unsigned 0x16D4 mask -> MATCH 99 |
| func_0024BF20 | src/cod/inbox_nm_func_0024BF20.c | SKIP | needs VU0 lqc2/vadd.xyz/sqc2 (inline asm only) |
| func_00347218 | src/cod/inbox_nm_func_00347218.c | SOLVED | rewritten with prototypes + section -> MATCH 40 |
| func_0033BDD8 | src/cod/inbox_nm_func_0033BDD8.c | SOLVED | rewritten; pointer-stepping clear loop -> MATCH 42 |
| func_0033BEC0 | src/cod/inbox_nm_func_0033BEC0.c | PERM QUEUE | rewritten (volatile counter, reload into a0); with drop_reorder 1 diff: retail bnez + ld ra in slot, ours bnel; as=sn / no-gcse no effect (e.c) |
| func_0033F5B8 | src/cod/inbox_nm_func_0033F5B8.c | SOLVED | rewritten; volatile state word -> MATCH 46 |
| func_0033F4C8 | src/cod/inbox_nm_func_0033F4C8.c | SOLVED | rewritten with prototypes; drop_reorder -> MATCH 49 |
| func_00345610 | src/cod/inbox_nm_func_00345610.c | SOLVED | rewritten; count-up loop over 0x304 records; drop_reorder -> MATCH 79 |
| func_00245538 | src/cod/inbox_nm_func_00245538.c | BLOCKED (flag) | rewritten from scratch (jump tables decoded: default / 11-case / 17-case arms); a.c 16 diffs, all the same 0xFFFF-mask-after-0x564-load scheduling as func_00257E90; also needs extern_jtbl [D_0043D0F0, D_0043D2B0], which meta.json cannot carry |
| func_0024C0F0 | src/cod/inbox_nm_func_0024C0F0.c | SOLVED | rewritten from retail on the func_0025E600 template (PMF dispatch, emNo switches); 2F4 store before 2F5 -> MATCH 181 |
| func_00257E90 | perm | PERM ROTATED | 15 min, best 780 from 1070 relies on a junk volatile local -> rejected |
| func_00208858 | perm | PERM RUNNING | aa.c: rewritten from retail; only prologue `lui s0` vs `sq s2` order differs (2 insns); decl/loop variants no help |
| func_00217560 | f.c | PERM QUEUE | rewritten from retail; prologue/regs right (block-scoped `pp` for Getplayer()->F0); case-0 selection: ours cross-jumps identical 0x1670 blocks and loads x/y straight into a1/a2, retail keeps v1/a0 and adds at join (same unexplained shape as func_00257E90). Tried combined conditions, types, p+x order, inline GetPair: no change |
| func_00307840, func_003077B0 | - | ALREADY DONE | registered by main agent in sa_003077b0.c (-O0, as=sn, register params); found -O0+register for 00307840 independently |
| func_002ACF30 | h1.c | PERM QUEUE | semantics fixed (pointer mismatch returns 0); 5 diffs, register allocation only (entry ptr a3 vs a2) |
| func_00208858 | perm | PERM ROTATED | 15 min, ~7.6k iterations, no improvement below base 60 (prologue lui/sq order) |
| func_003A51F4 | b.c | PERM QUEUE | newlib memmove; params used directly (src/len), long=64-bit for ld/sd loop -> same shape and length; remaining = register alloc (retail dst_void->t0, -1 const in a0), same quirk as memcpy sibling |
| func_001F50A0 | src/cod/inbox_nm_func_001F50A0.c | SOLVED | rewritten from retail; m/sec locals for time/60, time%60; self + (id*0x174 + off) -> MATCH 92 |
| func_001C6A90 | src/cod/inbox_nm_func_001C6A90.c | SOLVED | rewritten from retail; char 5th arg, CopyVec3 inline, fp_hazard_rules mtc1, 0x138/0x13C stores written before 0x130/0x134 -> MATCH 54 |
| func_00192270 | cur.c | GAVE UP | -fno-gcse sibling of 00173ad8.c family; cc1 folds f[9]=f[1]*half (and rematerialises 0.5f) while retail keeps 0.5f live in f21 and multiplies a mov.s copy at run time; literal/order/cb variants identical (53 diffs) |
| func_00352888 | src/cod/sa_nm_003525f0.c | SOLVED | cygnus drop-reorder; parity before separate >>=1/-=ofs; sec/min/hour via %= chain; stores hour,min,sec,frame -> MATCH 133 |
| func_00353928 | cur.c | GAVE UP | stack layout same; retail computes used=after-before before the func_0035BA58 call (extra live reg -> dec spilled at 0x40, frame 0xA0), ours sinks it after the call (frame 0x90); source order/temp/flag variants unchanged (155) |
| func_002ABDC0 | cur.c | GAVE UP | no jump table; retail div.s padding is mixed (2 nops when div.s does not read the preceding cvt, 0 when it does) - fits no fp_hazard_rules set (mtc1,fdiv = 165 words vs 162); loop flag is sltu-bool + xori, ours bit-extract; reg alloc differs throughout |
| func_001F7360 | - | BLOCKED (flag) | file notes say it needs call_loop_pad (loop-top nop), which meta.json cannot carry |
| func_002ACF30 | perm | PERM ROTATED | ~12 min, no improvement below base 35 (register-only) |
| func_0030D358 | - | BLOCKED (flag) | language switch compiles to a jump table (.rodata reloc) -> needs extern_jtbl |
| func_00151990 | cur.c | GAVE UP | as=sn now expressible (85 diffs); remaining = TEX0 bitfield mask scheduling (retail CPSM before CSM, TCC elsewhere) + pic-select reg reuse; field-order swaps no help |
| func_001C3778 | f5.c perm | PERM EXHAUSTED | manual PERM_GENERAL x4 + LINESWAP space fully enumerated (1024 its), best stays 50 (7 diffs) |
| cOl0e_setFake | k1.c | GAVE UP | 17 diffs: single-expr f fixes arms to 2 reg-swap diffs; tail stores scheduled (retail in-order + mtc1 nop); all 120 tail orders, all hazard rules, as=sn, 3 compilers no change |
| func_0033BEC0 | e.c | GAVE UP | cygnus+drop_reorder 1 diff (bnel vs retail bnez w/ ld ra slot); 6 control-flow shapes, 5 prototype variants, all allowed flags, as=sn: no change |
| func_002B4028 | u_int.c | GAVE UP | int w removes andi; sole real diff = SN if-converts final arm to movz/movn where retail branches (rest is 1-word shift); 5 comparison spellings, ternary, temps, allowed flags no help |
| func_003542B8 | f3.c (cygnus, drop_reorder; now TU sa_00353928 split) | GAVE UP | +12 more index spellings (ulong/long/bitfield/casts/temps): fold to srl1+andi0x1c or dsll32/dsra32 truncation; retail dsrl3/andi7/sll2 not reproduced |
| func_00155AE8 | nA2.c | MATCH -> nm_solved | int id; `id = (unsigned char)id;` in each arm; TAG64 written low|high (w1 part first) |
| func_0034F8D0 | e3.c (cygnus, drop_reorder) | PROGRESS 18->15 | sequential fallbacks `if(n<=0) n=inf->minFill; if(n<=0) n=max; lim=n; if(n>=max) lim=max;` gives retail CFG/movz; left: retail keeps cfg=hn+0xA0C in s0 and loads 0x58(s0) — ours folds to lw 0xA64; inline helpers / repeated cfg reads no help |
| func_002A4BA0 | r1.c perm | PERM ROTATED | 15 min random: best 110 via junk r->lim++/--, rejected |
| func_0032FC38 | cur.c | SKIP (far) | 224/274 diffs under cygnus drop_reorder; not near |
| func_00155800 | cur.c | SKIP (far) | 166 diffs |
| func_001DEB08 | r4.c (7 diffs) | PERM ROTATED | 18->7 via `to.v = from.v;` then r,g,b,a fields (exact retail insns); left: struct-copy temps t3/t2 vs ours t2/t1 (retail has a gap at t1). Perm best 5 used uninitialised var on else path (UB, rejected) |
| func_00352AA0 | cur.c | GAVE UP | 39; %=-chain, association (f+1+half, separate f+=half), field order, decl order: 39-51; retail loads fieldA first + 4 separate 60 consts in t0/t2/t4/t3 |
| func_00271148 | y7.c | MATCH -> nm_solved | twin of matched func_00271298: z=0.0f local, r=dy copy of Turn_dest result, if/else abs into t/u, m reused for *(self+0x618) |
| func_0030D1F8 | src/cod/sa_nm_0030d1f8.c | MATCH | existing C matches with as=sn (ps2eeas leaves the AddIntcHandler delay slot empty); meta as=sn. Siblings 0030D258/0030D358 remain INCLUDE_ASM |
| func_001DF7D0 | - | PERM ROTATED | 15 min, best 350 (semantics-changing junk), base 885 |
| Turn_dest_dir | src/cod/sa_nm_turn_dest_dir.c | MATCH | permuter (manual PERM_RANDOMIZE on tail) found result reuse of d: d = spd * s; return d; meta as=sn |
| func_00270D00 | src/cod/sa_nm_00270d00.c | MATCH | abs computed into t then stored back into d (d = t) before compare; same family fix as Turn_dest_dir |
| func_002DB7E0 | src/cod/sa_nm_002db7e0.c | MATCH | abs of Turn_dest result into t, stored back into a (a = t) before compare |
| func_003A9498 | src/cod/sa_nm_003a9498.c | GAVE UP | strtok_r: only assembler load-delay nop placement differs (retail nop before bnez in first delim loop, none at second-loop label); loop spellings (while/for/break) don't move it |
| func_00376370 | src/cod/sa_nm_00376370.c | PROGRESS | reorg fills beq slot with shared a0=s copy before call slots are filled; retail fills call slots first. if/else nesting, int f, inverted test, as=sn, cygnus don't move it. Queue for permuter |
| func_00342E50 | src/cod/sa_nm_00342e50.c | PROGRESS | cygnus sched hoists li 0x600 first; retail natural order. Locals/comma/reordered stores don't move it. Queue for permuter |
| func_00328BB0 | src/cod/sa_nm_00328bb0.c | PROGRESS | only the final flag clear: retail rematerialises &D_003D04C4 (addiu v0,s3,lo; sw zero,0(v0)), ours folds lo into sw. extern int[]/struct/cast/unsigned don't move it; int *flag local worse (30). Queue for permuter |
| func_00298EF8 | src/cod/sa_nm_00298ef8.c | PROGRESS | 13 = a1/v1 swap of idx vs v. int idx narrowed in place (top: 13, after test: 34), unsigned/ushort v (13), separate switch key + result var (24). Queue for permuter |
| (sweep) | all 235 unregistered NM fns | INFO | existing C x {sn,cygnus,ee-2.9} x {as ee,sn} x {reorder,drop}: no new matches beyond func_0030D1F8 (as=sn) and func_003BAFD0 (already known, carve-blocked). func_0021A538 false positive (guard not stripped); real NM ~5580 diffs |
| func_00274150 | src/cod/sa_nm_00274150.c | PROGRESS | 14: only switch decision-tree direction (retail LT->left, falls into right subtree; ours GT->right, falls into left). All 24 case orders, individual labels, default:break, case 0x260 break + default body (23) don't move it. Queue for permuter |
| func_001DCE68 | src/cod/sa_nm_001dce68.c | MATCH | r = irand() local, n = lo - 1 temp, hi -= n (blocks the (hi+1)-lo fold and fixes s-reg rotation) |
| func_00365D18 | src/cod/sa_nm_00365d18.c | PROGRESS | 15: load schedule of the 8 source words only. Queue for permuter (random) |
| func_0034C890 | src/cod/sa_nm_0034c890.c | PROGRESS | 15 -> 6 with drop-reorder + busy==0 test first + *out=0 after e (best6.c). Left: retail adds self+0x1310 first (a3) then offset; ours reassociates. two-step base/char* base/tbl local worse. Queue for permuter |
| func_0013D288 | src/cod/sa_nm_0013d288.c | PERM ROTATED | 15 min manual PERM_RANDOMIZE on the 3 calls: best 240 (base 275) = junk do{}while(0) insert; first drawPolyF arg order unchanged |
| func_0035DAA0 | src/cod/sa_nm_0035daa0.c | MATCH | early return 0 on failure, memset + struct copy, return 1 (no r variable) |
| func_00328BB0 | src/cod/sa_nm_00328bb0.c | MATCH | D_003D04C4 declared volatile: combine won't fold %lo into a volatile store, giving retail's addiu+sw 0(v0) |
| func_0036D1A8 | src/cod/sa_nm_0036d1a8.c | PROGRESS | 17. char *volatile D_0076A588 fixes the materialised store address but then the sw leaves the jal slot (26); volatile flag reorders prologue (33). Retail = store via full addr in jal slot + a0=4 reused from compare. Queue for permuter |
| func_003780F8 | src/cod/sa_nm_003780f8.c | PROGRESS | 17 -> 2 (best2.c: branch1 locals, branch2 block-local ts/tc). Left: retail computes &tbl[r].c before the first lwc1. Permuter hit 0 only with an empty do{}while(0) between the stores (REJECTED as junk); real do-while wraps / inline SetSinCos helper stay at 2-4 |
| func_0013DF70 | src/cod/sa_nm_0013df70.c | PROGRESS | 17: retail p = off+self in v0, store, then copies to s0 (off's reg) for the delay-slot sh. Tried off/p reuse (char* p from int, off += self, store-before-assign, outer decl, p = self + i*0x50): 17-20 |
| func_00368A28 | src/cod/sa_nm_00368a28.c | MATCH | return directly from each switch case (+ default if c >= 0xBC return PES), return 0 at end; cygnus drop-reorder |
| func_00376720 | src/cod/sa_nm_00376720.c | PROGRESS | 19. do/while with i-- at end, for(;;) i-- in body, while(--i), up-counting for (reversal), unsigned short i, -fno-gcse, goto forms (30), f preloaded do-while (27): none move it. Retail: i-- at bottom, nop after lhu kept, f|2 after inner test |
| func_0037D1A8 | src/cod/sa_nm_0037d1a8.c | PROGRESS | 17 -> 12 (best12.c: if (id == 0) return e; if (e->id == id) return e;). Left: retail id-compare block has 2 nops before beq and an unfilled beq slot (ours fills with i++ addiu). All compiler/as/reorder combos stay 12 |
| func_001DAE18 | src/cod/sa_nm_001dae18.c | MATCH | s->msgSub = 0; s->msg = X; written in every branch (5 leaves); cross-jumping yields retail's shared tail and no movz/movn |
| func_002C3058 | src/cod/sa_nm_002c3058.c | PROGRESS | 18: retail loads link word into v0 and copies to v1 (bne slot copy, top lw+copy+nop); ours bnel with duplicated lw. while/for/do/if-do forms and separate w/v vars in all 6 mixes: all 18 (CSE coalesces) |
| func_002CBD10 | src/cod/sa_nm_002cbd10.c | MATCH | nested if (key == 0 || key == ent.key) { if (id == ent.id) {...} } with one i++ at loop bottom |
| func_003A93F8 | src/cod/sa_nm_003a93f8.c | SKIP | strstr: only two retail hazard nops at the outer loop head differ; no toolchain setting emits them (same class as func_003A9498) |
| func_003454F0 | src/cod/sa_nm_003454f0.c | PROGRESS | 21 (no dr) -> 7 with drop-reorder -> 4 (best4.c: else order mode, vhz, disp=1, max=1). Brute 6 then x 24 else store orders: min 4 (then-path mode/vhz store pair swapped vs retail). Queue for permuter |
| func_002BECB0 | src/cod/batch30_nm.c | PROGRESS | 20 -> 11 (best11.c): entries are 64-bit (*(long *)base == 0, *(long *)slot = (long)val -> ld/sd), ((char *)*a0)[(i << 4) + 0x618] = 1. Left: base in a2 (retail v1) so retail's sll a2 delay-slot fill can't happen. Decl/assign orders don't move it. Queue for permuter |
| func_00307840 | ALREADY SOLVED | Main agent matched it in sa_003077b0.c (register param, -O0, as=sn) before handoff; my scratch match was the same. No handoff written. |
| func_001C26B8 | PERM ROTATED | 15 min PERM_RANDOMIZE around Turn_dest call; best score 20 added a junk 'else if (self)' duplicate branch, rejected. best2.c (2 diffs, arg load order) stands. |
| func_003234D0 | src/cod/sa_nm_003234d0.c | PROGRESS | 10 -> 2 (best2.c: struct with volatile f0..f3/f8/f18..f20 members, f2C plain; cygnus, drop-reorder, as=sn). Remaining: li v0,0x200 scheduled one slot after first sb (retail before). 512 volatile masks, 0x2C placement, locals, chained bytes, allowed flags all tried. |
| func_00320948 | src/cod/sa_nm_00320948.c | PROGRESS | 25 -> 24 but 35 words (w1.c: direct t->type[i] loop test gets the entry 'i -> a2' copy right, but the post-loop test recomputes &types[i] instead of reusing the loop's v0). Pointer-p forms keep size but leave i in a0. Tried ~20 shapes, param types, copy local. Queue for permuter. |
| func_00349EF0 | src/cod/sa_nm_00349ef0.c | PROGRESS | 2 (s0.c = current NM body; cygnus, drop-reorder). a3=&used / a0=self swap around the bnez. Tried conditional assignment, pu local, (*fp)() call, nested if, store order, chained *size = len. Queue for permuter. |
| func_00360200 | src/cod/sa_nm_00360200.c | PROGRESS | 27 / 30 vs 32 words (cygnus, drop-reorder, as=sn). Root cause: the s1 = len copy is scheduled into the first branch's delay slot (retail: just after s0 copy), which kills the bnel duplicate of *data = 0. Tried struct copy, inverted test, early return, split ifs, len alias local, -fno-gcse. |
| func_00360520 | src/cod/sa_nm_00360520.c | MATCH | Indexed loop dst[i] = src[i] >> 15 inside if (==1) / else error; cygnus, as=sn, drop-reorder. Handed off. |
| func_003BA370 | src/cod/sa_nm_003ba370.c | MATCH | Indexed for-loop scan (p[i] / p[i+1], break, return i); loop strength reduction makes retail's p copy. cygnus, drop-reorder. Handed off. |
| func_0033B978 | src/cod/sa_nm_0033b978.c | PROGRESS | 36 -> 1 (best1.c: D_00758620[a0][a1].x/.y/.z = 0 directly; cygnus, as=sn). Only diff: second range-check branch is bnel in ours, bnez in retail (same delay insn sll v1,a1,1). Tried callee/caller return types, prototypes, drop-reorder, -fno-gcse, as=ee, structure/else forms, signedness. |
| func_002B8D88 | src/cod/sa_nm_002b8d88.c | MATCH | self as struct with int mask[] at 0x1C, indexed self->mask[a] in each branch (no hoisted mask pointer). sn defaults. Handed off. |
| func_003454F0 | PERM ROTATED | 15 min manual PERM_LINESWAP over both branch store blocks (~8k of 17k orders sampled): nothing below base 80. Store order alone cannot fix it; best4.c stands. |
| func_00332A60 | src/cod/sa_nm_00332a60.c | PROGRESS | 3 (s0.c). lui temp v0 vs retail v1 (ready load sits between lui/addiu in retail). Tried dst local (top / in body), early return, !ready, pointer-to-st, file copy, nested if, -fno-gcse. Queue for permuter. |
| func_00307878 | src/cod/sa_nm_00307878.c | PROGRESS | -O0, as=sn. Current NM body (plain int r) matches every temp up to sltu but spills r (sw/lbu, 32-byte frame). Direct return gets the 16-byte frame but loses the v0 copy + andi 0xFF; any register local takes a1 and shifts temps (19). Tried !!, ?:, casts, & 0xFF, register char/uchar/uint/long, nested-block register, operand order, w/m register temps. |
| func_001F6A80 | src/cod/sa_nm_001f6a80.c | MATCH | Second loop with its own counter j and condition j > s->cur (reloaded each pass). sn defaults. Handed off. |
| func_001DBEB0 | src/cod/sa_nm_001dbeb0.c | PROGRESS | 25 (24 vs 26 words). as=sn drops the needed short-loop pad (ee as gives it). Card-pointer, count-down, 51-i index, flags-anchored pointer forms all compile identically; the in-loop li 9 and work->a3 copy not reproduced. Flags tried. |
| func_001DBFB8 | src/cod/sa_nm_001dbeb0.c | PROGRESS | 5: retail lw of obj->rank (int at 0x604) before sh; ours narrows to lhu. Volatile rank (per file note) matches but would need a private volatile struct copy - not adopted. Tried int temps (size changes), (int) cast, & 0xFFFF, C++ build. |
| func_001DC4C0 | src/cod/sa_nm_001dbeb0.c | PROGRESS | NOTE for main agent: with the current header (BlackJackCard.flags unsigned int) this is 55 diffs / 80 vs 78 words, because ~4 becomes lui/ori 0xFFFFFFFB; with 'int flags' (scratch copy progress/nm_work/hdr2/godhand/BlackJack.h) it is back to 2 (outer back-edge i copy vs slti order). Tried ++i, do-while, return-in-loop, k=i+1 local, <=3. |
| Motion_seq_readSpdData | src/cod/sa_nm_002c7d20.c | MATCH | B8 {uchar b[8]} buffer, *(B8 *)&r = d into SpdData r, return r; sn + as=sn (ps2eeas dli expansion gives addiu -1/dsrl32 mask). Handed off. |
| INFO | as=sn sweep | progress/nm_work/tools/assweep.py: 31 standalone sn NM files without as=sn compared default-as vs as=sn. Only Motion_seq_readSpdData (now matched) and func_00151990 (242 -> 85, still far) improve. |
| func_002948E8 | src/cod/sa_nm_002948e8.c | PROGRESS | 25 -> 12 (best12.c: inline helper 'if (id < 0x200) return 0; return id < 0x300;' reproduces the slti/flag/andi shape and size). Left: flag lands in v0 (retail a0 then copy) and o in a3 + copy (retail a2). Tried helper taking Obj*, id local, continue form, explicit flag locals (lose shape), C++ bool. |
| func_00356F48 | src/cod/sa_nm_00356f48.c | PROGRESS | 31/38w -> 20 same size (best20.c: ternary inside if (on) arm, else-arm return/mode=0; constant 1 is no longer kept in s2). Left: retail computes mode=1 / movn 2 before testing on and keeps f50 in a0 for the second test. Tried mode default at decl, cur local, char/short mode types, -fno-gcse, sn/ee compilers. |
| func_00356FD8 | src/cod/sa_nm_00356fd8.c | MATCH | unsigned int mode param (bounded switch -> linear beq chain) + separate func_00357068 call per case; cygnus, drop-reorder. Handed off. |
| func_00368CE8 | src/cod/sa_nm_00368ce8.c | MATCH | FLAG volatile: extern char *volatile D_00766CD4[] (materialized address + sw 0). cygnus, drop-reorder. Handed off. |
| func_00340A60 | src/cod/sa_nm_00340a60.c | PROGRESS | 24 -> 17 (best17.c: clamp q in place, no n). Left: retail copies rate into a0 (ours v1), tests q<97 on the unclamped q with an xori 0 before the movz. 20 condition spellings + 6 ternary/nested forms all canonicalize to 24 or 32. |
| func_00349EF0 | PERM ROTATED | 15 min PERM_RANDOMIZE over first call..feed call: best (score 60) took &used into a local after the first call; under mc that is 4 diffs (worse than 2), rejected. |
| func_00332A60 | PERM REJECTED | PERM_RANDOMIZE run hit score 0 in seconds by inserting an empty 'if (st.ready) { }' before the second history push - junk no-op, rejected. |
| func_00359480 | src/cod/sa_nm_00359480.c | SKIP (for now) | 34 renames; retail copies all three params (a0->a3, a1->t0, a2->t1) so locals take a0..a2. Not attempted beyond inspection; candidate for permuter random mode. |
| func_0030B090 | src/cod/sa_nm_0030b090.c | SKIP (for now) | 39 / 40 vs 46 words. Retail reloads p[-8] after every store through b (aliasing unknown) and addresses -8(a1) directly; ours folds the symbol+offset and anchors at a1-0x8000. Inspection only. |
| func_0013DE90 | src/cod/sa_nm_0013de90.c | PROGRESS-NONE | 30. Explicit if+do-while with bound copy, end computed from begin, plain while: all identical. Likely a g++ array-dtor expansion; would need a C++ class source. |
| func_002C9E78 | src/cod/sa_nm_002c9e78.c | PROGRESS | 34->27 (best27.c): explicit short locals y0,x1,y1,x0 in retail load order fix load regs for x1/y1; y0/x0 still land in a2/a3 + daddu copies to a0/a1 (3 extra words). Store-order sweep (720) and short prototypes don't help. |
| func_002C31D0 | src/cod/sa_nm_002c31d0.c | PROGRESS-BLOCKED | Retail = delay-slot fill from target (bc1tl + stolen sub.s) AND R5900 short-loop pad of 3 nops (loop counted incl. delay slot). sn-2.95.3: fill, no pad (40w/24). ee-2.9-991111: pad 3 but no dbr -> bc1t to sub.s (44w, 8 diffs; c.c). cygnus: fill + pad 4 (counts excl. delay slot) + .p2align nop after j (48w). Use 3.1415928f under cygnus (3.1415927f rounds to ..0fda). No allowed flag (-fdelayed-branch not allowed) bridges it; no fp_hazard_rule adds compare pads. |
| func_0012EC58 | src/cod/sa_nm_0012ec58.c | BLOCKED-TOOL | The +0x34 nop is the R5900 short-loop pad (loop 0x28..0x38: lw, beql, lq, nop -> 4 pre-branch words). The loop is multi-block (beql exit inside); neither ee-as nor ps2eeas nor --call-loop-pad pads multi-block loops, but retail's assembler did. C is otherwise exact. Needs a wrapper rule (main agent), not C. |
| func_002AFED0 | src/cod/sa_nm_002afed0.c | MATCH | sn, as=sn. Real while (count <= n) { if (*p>>15) { if ((*p&0xFF00)==0x8000) break; } else ruby=call; step } replaces the goto layout (loop note gives .p2align 3 head + slot fill); floats x,y declared before n fix prologue copy order. Handed off. |
| func_002B2588 | src/cod/sa_nm_002b2588.c | MATCH | sn defaults. for (;;) { if (!(*mc->cur >> 15)) return 1; switch {0: call; 1: return 0; 2: return 1;} } -- loop note gives the aligned head. Handed off. |
| func_001C3C58 | src/cod/sa_nm_001c3c58.c | SKIP | Retail's 2 nops sit AT the beql target (+0x30, label before the nops; the next insn lands 16-aligned) after a beql whose slot loads v0 used at the target: assembler-inserted, no compiler/as combo reproduces. |
| func_003234D0 | perm | PERM REJECTED | PERM_RANDOMIZE over the store block, 15 min: 11 outputs all at base score 60, no improvement. |
| func_0026A3D8 | src/cod/sa_nm_0026a3d8.c | MATCH | sn, as=sn. Inline getter (i<n, stack temp of n), bitfield flag bit 11, switch(self->motion){default: sway*=0.6f; case 0x223/0x275/0x276: sway*=-0.6f;}. Handed off. |
| func_002B00A0 | src/cod/sa_nm_002b00a0.c | PROGRESS-NONE | 66 (same size). Retail writes the uv header off sp directly and materialises sp+0x10 late; struct-uv spelling is worse (87). Scheduling-dominated; permuter queue. |
| func_0036D0F8 | src/cod/sa_nm_0036d0f8.c | MATCH | cygnus dr. buf = p after the len<=0 test. Handed off. |
| func_0033A618 | src/cod/sa_nm_0033a618.c | PROGRESS-NONE | 1 (bnel vs bne at used!=0). Retail's reorg treats v0 as live on the error-call fallthrough (annuls the stolen sltiu). Tried 6 func_0033A048 prototypes (int/void/unprototyped/variadic/long long/const), all compilers x dr x as, -fno-gcse/-ffast-math: no change. Same class as func_0033B978 (opposite polarity). |
| func_0036C0B0 | src/cod/sa_nm_0036c0b0.c | MATCH | cygnus default. chbuf/pool assigned after the func_00366C50 call. Handed off. |
| func_003B2080 | src/cod/sa_nm_003b2080.c | PROGRESS-NONE | 2 (ee-2.9 sched swap addiu %lo(D_00460040) vs lw %lo(D_0077E520)). Tried temps both orders, store reorders (17), row pointer (44w), decl types for both globals, ee-2.9-990721. Permuter queue. |
| func_00332AE8 | src/cod/sa_nm_00332ae8.c | PROGRESS-NONE | 3 (lui %hi(D_003D9C90) gets v0 in ours, v1 in retail, schedule follows). found local (6), early return (50w), !found, assignment-in-if: no gain. Permuter queue. |
| func_003566E8 | src/cod/sa_nm_003566e8.c | PROGRESS | 5 -> 1 (best1.c): viBufAddDMA and sfmpvp_PutVibuf declared int-returning fixes the v0/v1 temp choice. Left: busy test bnel (ours) vs bnez (retail), slot li v0,1. Nested/early-return/accessor forms no help. |
| func_00336218 | src/cod/sa_nm_00336218.c | PROGRESS-NONE | 2 (bnel vs bne before each call). Tried sub->cur macro (27), o->sub.slot (49w), inline state helper (27), merged guards, single nested if, final call in if: no gain. Same reorg-liveness class as 0033A618/0033B978/003566E8. |
| func_0034E090 | src/cod/sa_nm_0034e090.c | MATCH | cygnus dr. int return; r = check(hn); if (r) return func_0034DD70(...) (int); ...; return r. Live v0 moves temps to a0/v1. Handed off. |
| func_00344C98 | src/cod/sa_nm_00344c98.c | MATCH | cygnus dr. Shared mode=2 block after the if-chain with goto done / goto error (error block before done). Handed off. |
| func_0033B978 | perm | PERM REJECTED | 15 min whole-body random: 6 outputs, all 16-17 mc diffs (baseline 1). |
| func_00352008 | src/cod/sa_nm_00352008.c | SKIP (flag) | Its best 7 needs -fno-strict-aliasing, which is not on the allowed c_flags list; strict-aliasing best is 17. Not pursued further. |
| func_002E2800 | src/cod/sa_nm_002e2800.c | PROGRESS | 7 -> 5 (best5.c): volatile timer byte too (sched won't hoist the volatile word load past a volatile sb). Left: retail loads the word before materialising ~4 (lw v1; lui/ori v0; and v1,v1,v0); every &= spelling and bitfield clears tried. Flag: volatile timer. |
| func_00347AF8 | src/cod/sa_nm_00347af8.c | PROGRESS-NONE | 9 (s0/s1 swap buf vs hn/sj). Inverted error tests (48w), if/else nesting (25), type local, hn->sj at use (47w): no gain. |
| func_0034C2D0 | src/cod/sa_nm_0034c2d0.c | PROGRESS-NONE | 9. b = base; b += no fixes the address order but sj then lands in v0 + copy (42w). f10 type (void*/char*/float/unsigned) doesn't move its store; split/nested guards worse. |
| func_002CB278 | src/cod/sa_nm_002cb278.c | PROGRESS-NONE | 11. ret=-1 after the EmSeFind call (via slot/f locals, assignment-in-compare): 12 or size changes. |
| func_0035FAD8 | src/cod/sa_nm_0035fad8.c | PROGRESS-NONE | 15. Volatile DecWork stores give retail's exact store order but let the epilogue lds interleave and swap a1/a2 (20). sn/ee-2.9: 30. |
| func_0033ABD0 | src/cod/sa_nm_0033abd0.c | SKIP (class) | Same used!=0 bnel/bne reorg-liveness issue as func_0033A618 plus a shared-sltiu tail; not attempted separately. |
| func_003253C0 | src/cod/sa_nm_003253c0.c | MATCH | cygnus default. func_003B0BA8 + func_00325360 int-returning. FLAG: discarded volatile reads (void)D_003C8138 kept from NM source. Handed off. |
| func_0034A400 | src/cod/sa_nm_0034a400.c | PROGRESS-NONE | s-reg assignment already matches; retail schedules the a3->s3 copy first (prologue) and swaps v0/v1 at the tail. Tail orders, n long, int return, dec/skip placement, decl order all 16 or worse. Permuter queue. |
| func_00351A08 | src/cod/sa_nm_00351a08.c | PROGRESS 14->3 | tm=&hn->tm after the branch fixes the s0/s1 swap; locals total/x read before the store, with tm->total = t[0] + total, fix load order; left: v0/v1 swap for total/t[0] (best3.c). Permuter queue. |
| func_0032F178 | src/cod/sa_nm_0032f178.c | PROGRESS-NONE | store-flag fold persists across if/else, ternary, i<n test, switch continue, char return, all allowed flags and all 4 compilers. |
| func_00349590 | src/cod/sa_nm_00349590.c | MATCH | cygnus dr. MWSFD_GetReqSvrBdrLib() called with no args; volatile int *hn (FLAG) blocks the bnel steal. Handed off. |
| func_003B2080 | perm | PERM REJECTED | 15 min: 2 outputs (5/6 mc diffs vs 2 baseline), junk duplicated-branch form. |
| func_00342E88 | src/cod/sa_nm_00342e88.c | PROGRESS 22->4 | m=E80() local, then one += per term (a=s1+s2; a+=s3; a+=0x40; a+=n; a+=s0+s4; b=d0+0x40; b+=d1+s5; a+=b; a+=m; return a+0x800) defeats fold/simplify_plus_minus. Left: s4/s5 temp regs swapped (t0/a3) (best4.c). Permuter queue. |
| func_00349328 | src/cod/sa_nm_00349328.c | MATCH | cygnus dr. extern volatile int D_003EE09C (FLAG) keeps the counter store out of the delay slot. Handed off. |
| func_00342FF8 | src/cod/sa_nm_00342ff8.c | PROGRESS 5->2 | req.d = 0 at the end of each arm (cross-jumped into the join) fixes the join order. Left: third arm loads c2 before kind2 (bnel slot steals c2, retail kind2) (best2.c). |
| func_003301B0 | src/cod/sa_nm_003301b0.c | PROGRESS 25->1 | switch (d->mode) { case 0: retry; case 1: sibcall } reproduces retail's layout. Left: stat==1 test bnel (ours) vs bne (retail), li v0,2 slot - same reorg-liveness class; prototypes/stat forms/char types no change (best1.c). |
| func_0034FB70 | src/cod/sa_nm_0034fb70.c | MATCH | cygnus dr. pic = &obj->pic inside the now != LLONG_MAX block. Handed off. |
| func_003517D0 | src/cod/sa_nm_003517d0.c | MATCH | cygnus dr. int index = seek->index before the test. Handed off. |
| func_00336B00 | src/cod/sa_nm_00336b00.c | PROGRESS 36->20 | Extra 'case 0xCA:' on the default label moves the root pivot to 0xCB; under sn-2.95.3-136/ee-2.9 the left subtree and bodies then match (20). Right subtree still pivots on 0x12B (retail 0xCD with the empty-left slti); adding 0xCC emits real code. (best20_sn.c, sn compiler) |
| func_00337A00 | src/cod/sa_nm_00337a00.c | PROGRESS 38->4 | in[0] assigned in each arm with 'if (call == 0) in[0] = rate; else in[0] = 0xBB80;' and res = &D_003E0750 after it gives retail's branch + hoisted DTX args (also fixes blez); out[1]/out[2] read into locals fixes the load regs. Left: scheduler puts the D_003E0748[0] store first, retail last (after the two zero stores). volatile variants worse. (best4.c) |
| func_00331DB8 | src/cod/sa_nm_00331db8.c | PROGRESS-NONE | retail sets a0/(int)b/a2/a3=mode before the mode==1 branch (a1 overridden in the jal slot), i.e. args shared across both calls; not reproducible with two direct calls in tried forms. |
| func_00351A08 | perm | PERM NONE | 15 min PERM_RANDOMIZE over the tail (from best3): no improvement over base. |
| func_00330D58 | src/cod/sa_nm_00330d58.c | PROGRESS-NONE | Two identical D_00453470 error stubs: retail keeps both inline (a0 built directly), ours cross-jumps them into one and builds %hi in v0. Direct-return, nested, if/else forms x dr x -fno-gcse: 38-42. |
| MtxInitRotQuaternion | src/cod/sa_nm_mtxinitrotquaternion.c | SKIP (far) | 48 FP-scheduling diffs (sn); permuter-only candidate. |
| func_001F75D0 | src/cod/sa_nm_001f75d0.c | SKIP | best needs -fno-strength-reduce (not an allowed flag). |
| func_0021A538 | src/cod/0021a538.c | SKIP | 3400-line m2c body with 13 jump tables; not a closer task. ("guard" in the queue was this file's comment, not a function.) |
| func_001FE370 / func_002BE028 | - | BLOCKED-TOOL | R5900 short-loop pad on loop heads (same tooling gap as 0012EC58). |
| func_00274018 | src/cod/sa_nm_00274018.c | PROGRESS 35->20 | isEnemyType as 'if (type < 0x300) return 0; return type < 0x500;' keeps the range test a branch (no movn). Left: ret in v0 not a0, type reloaded for 0x3D1, iterator copy (daddu v0,s1) and bnel back-edge. Type-local / helper variants worse. (best20.c) |
| func_0033B878 | src/cod/sa_nm_0033b878.c | PROGRESS 41->2 | cygnus dr + as=sn (gives the short-loop nops). ent = &D_00758620[grp][i] inside the loop (slot pointer copy, t2-hoisted default), name test as 'if (name != 0) ... else default'. Left: addu operand order for the row base (a0,a0,v0 vs a0,v0,a0) and the final i==6 bnel (retail) vs bne (liveness class). Row pointer / signed grp / unsized array: no change. (best2.c) |
| func_00306D18 | src/cod/sa_nm_00306d18.c | BLOCKED-TOOL | Retail has short-loop pad nops inside the node-clear and slot loops (0x7C, 0xB4, 0xC4) that neither as=sn nor default produce, plus w/tail s-reg swap; same multi-block short-loop pad gap as 0012EC58. |
| func_00359628 | src/cod/sa_nm_00359628.c | SKIP (far) | 48: registers shifted by one throughout (retail t7 buf, t6 count copy, lt in t0 copied to v1) and a shared return block; no quick structural lever. |
| func_002D3BA8 | src/cod/sa_nm_002d3ba8.c | SKIP (far) | 50 (sn, jump-thread/unfolded busy flag); not attempted this pass. |
| func_00342FF8 | order search | PROGRESS (2) | all 120 orders of the third arm's five field stores: none below 2. |
| func_00342E88 | perm | PERM NONE | 15 min PERM_LINESWAP over the sum statements (best4): no improvement. |
| func_00337A00 | perm | PERM REJECTED | PERM_RANDOMIZE over the tail stores reached score 0 only by duplicating 'D_003E0748[1] = o2;' after the [0] store (meaningless redundant store) - rejected. Hint: a later dependence on [1] after the [0] store gives retail's order. |
| func_00342FF8 | PERM | manual PERM_RANDOMIZE third arm, 15 min: best output uses uninitialized locals (junk) — rejected; best2.c (2 diffs) stands |
| func_00332AE8 | PROGRESS-NONE | dir local (15), inner block found/dir (46), early return (36, lw before addiu but regs swapped), !found, assign-in-if (6), goto (3), -fno-gcse (3), ee/sn compilers (29-30). Queue for permuter. |
| func_002948E8 | PROGRESS-NONE | unsigned char local r (25), helper on Obj* (14/12), ushort param (14), if/else r (25). Retail keeps helper result in a0 and o in a2; ours v0/a3. |
| func_00340A60 | MATCH | clamp as `if (q > 96) q = 96; else if (q <= 0) q = 1;` (upper bound first) with drop_reorder; matches with as=sn and default as. Handed off to nm_solved/func_00340A60. |
| func_0034A400 | PERM | whole-body PERM_RANDOMIZE, stopped at 6 min: base 180, best 140 (no new outputs since ~1 min); far — dropped in favour of 00356F48. |
| func_00332AE8 | MATCH | func_00333C00 declared int-returning (its real definition in sa_00333c00.c returns int) fixes the lui v0/v1 choice. Handed off. |
| func_00332A60 | MATCH | same fix (func_00333C00 int) + drop_reorder. Handed off. |
| func_00349EF0 | PROGRESS-NONE | feed int-returning (7), func_0034AA20 int (7); va..vf still 2. |
| func_0034C890 | PROGRESS (6) | sibling two-step base (e = base; e += idx) fixes add order but swaps v0/v1 on idx/busy (11); base local / &arr[idx] / char* p / idx copy / !busy / unsigned idx: 6-18. Queue for permuter (y1.c region). |
| func_00342E88 | PROGRESS (4) | b before a terms (14), operand swaps (5), decl order (4). |
| func_0033D870 | PROGRESS-NONE (1) | first test bne (ours) vs bnel (retail): reorg liveness class, reverse direction. Proto sweep (int returns) no gain. |
| func_00350528 | PROGRESS (2) | store order swap (3), 2+i index forms (2), j=i+2 (4), buf=buf+size (2), e=ctx->ent (51w). Queue permuter (loop body). |
| func_002D50E8 | MATCH | size = count*0x58 after the p->count/p->base stores (52->2), then sema.maxCount=1 before initCount=0. sn-2.95.3-136, either as. Handed off. |
| func_002BEBC8 | BLOCKED-TOOL | the one extra retail nop is inside the 5-insn two-branch loop (0x40..0x54): R5900 short-loop pad for a multi-block loop. No assembler/compiler combo emits it (sn/ee as, all 4 compilers). Same gap as 001FE370/002BE028/00306D18. |
| func_001FDEA8 | PROGRESS-NONE (11) | loop3 init order / increment order / d++ in body (11), indexed (59w), direct c flag stores (53w), clearC order (12), inline initD helper (12-13). |
| func_002FD530 | PROGRESS-NONE (10) | vset(pv, src) (20), direct field stores / helper taking Obj (54w: folds dest to s1 offsets), order swaps (54w). |
| func_00356F48 | PERM | manual PERM_RANDOMIZE (decls + cur/if region), 15 min: no output below base. c1.c stays at 4. |
| func_00140638 | PROGRESS-NONE (19) | flags & 0x80000000 always folds to bgez under sn: 64-bit masks, != mask, >>31, bitfield, inline helpers (uint/int/uchar/mask arg) all 19; other compilers 60w. |
| func_002CBF78 | MATCH | goto loop -> for loop (loop-invariant slti/li 2 hoisted) + flag as unsigned on:1 bitfield (no fold of ==1). (int)(flags&1)!=1 also matches. sn-2.95.3-136. Handed off. |
| func_00140638 | PROGRESS 19->57w/16 | x1.c: g[2] & 0x80000000 instead of < 0 shares the lui constant so the flags test keeps lui/and/beqz (top now matches). Left: child loop base (retail s1 = s2+0x35C direct; ours copy + nop, or swapped s1/s2 with c local: 16). |
| func_001BD430 | PROGRESS-NONE (47) | early-return helper (50), uchar helper (52), cached n + walking pointer (52), constant per-range helpers (51-53): ifcvt still makes movn for both ranges; layout also differs. |
| func_001EBB78 | PROGRESS-NONE (19) | for down-count (19), i-- > 0 (20), uchar r (19), int helper + cast (19), unsigned up-count for (15: bottom increment but sltiu/up), int up-count (reversed, 19). andi on countdown result never kept. |
| func_001F6680 | PROGRESS-NONE (22 w/ -fno-gcse) | retail sets a0=o->ids before the *on branch and after each call (shared arg), loop-align nop, on++ at bottom; not reproduced quickly. |
| func_00379838 | MATCH | int y; cases y = (T + o->idx)->y + 3 (pointer-plus form makes sched1 order cross-jump at mult); short sy = y after the switch for both calls. sn-2.95.3-136. Handed off. |
| func_00366840 | PROGRESS-NONE (53) | for/while/do outer loop forms all 52-53w / 54 diffs; retail rotates outer loop with in->buf in bnel slot and differs in inner-loop pointer setup. |
| func_00350528 | PERM | manual PERM_RANDOMIZE loop body: score-0 output needs ctx++; ctx--; and a & 0xFFFFFFFFu mask in the loop test (junk) — rejected; its clean parts (zero variable, e pointer) stay at 2 / 51w. |
| cIDBase_transSprite | PROGRESS-NONE (40) | GNU compound-literal SprVec2 args (62w, .rodata relocs). Stack-arg layout (two 16-byte {w,h,0,1} blocks) not reproduced. |
| func_0032F178 | MATCH | goto fail for both return-0 exits (no store-flag), loop over p->strm[i] (giv after hoisted const 5). cygnus dr. Handed off. |
| func_00351A08 | PROGRESS (3) | total + t[0] (4), += (8), t0 locals both orders (3-4). |
| func_00337A00 | MATCH | store order: D_003E073C=0; D_003E0740=0; D_003E0748[0]=out[1]; [1]=out[2] (found by 24-perm brute); handed off |
| func_00353550 | PROGRESS 45->29 | x11.c: st initialized at its declaration (keeps o and st in separate regs), hdr hoisted above mode test, early return 0, return 0 on r==0. Left: retail computes st after the call and threads the early return; sched1 interblock hoists hdr when st is moved inside. |
| func_00374720 | NONE (59) | compiler sweep (sn/cygnus/ee-991111/ee-990721, both as, dr, -fno-gcse) no better than 57; retail leaves bne/bc1f delay slots unfilled where every build uses branch-likely, plus per-arm &tgt recompute. Deferred. |
| func_00376438 | MATCH (FLAGGED) | for(;;){ if (wait==0) {...} else {wait--; break;} } so the rotated loop puts the decrement before the test; in-body wait test. Retail's extra nop is the R5900 short-loop pad on a multi-block backward bnez (tool gap); reproduced with one inline asm nop after the wait load + 'goto again' into the if body so the in-body path skips it. No-asm R2 form saved as alt_no_asm_1nop_short.c (off only by that nop). |
| func_0033F3F0 | MATCH | store order D_003EB830, D_003EB708, D_003EB834, D_003EB838, D_003EB83C=-1, D_003EB840=1 (brute.py over 720 orders); handed off |
| func_003454F0 | PERM ROTATED | 15+ min manual regions: best output 4 diffs under mc (same as best4.c); no gain. |
| func_0034C890 | NONE | sibling spellings (char *base + idx*0x74, &tbl[idx] via char*, int* t) all 20 diffs/26 words; best6 stays 6. |
| func_00351A08 | NONE | 8 forms of the total/x block (+=, temp, decl order): best 4; best3 stays. |
| func_00342E88 | NONE | brute 32 operand/decl orders of s0+s4 / d1+s5: stays 4 (t0/a3 swap). |
| create (002BA300) | MATCH (FLAGGED) | one inline asm nop after p = p->next reproduces the multi-block short-loop pad; as=sn. |
| func_002BEBC8 | MATCH (FLAGGED) | explicit entry test + do-while; one inline asm nop between the two loop tests = multi-block short-loop pad; as=sn. |
| func_0012EC58 | MATCH (FLAGGED) | one inline asm nop at end of the search loop body = multi-block short-loop pad; as=sn. |
| func_001346C8 | MATCH (FLAGGED) | for(;;) with explicit exits; one inline asm nop (memory clobber) after the key load = short-loop pad on a loop with an internal exit. |
| func_00376A90 | MATCH | i1.c index loop + call_loop_pad (meta.json now carries it; the 2 nops are the short-loop pad over the return-p epilogue block). solve.py gained --call-loop-pad. |
| func_001F7360 | NOTE | call_loop_pad is now carriable in meta.json, but the current body is 140 diffs off (s6 constant hoist, next-temp) - not near. |
| func_003A9498 | MATCH (FLAGGED) | strtok_r: first delim loop as entry test + do-while, one inline asm nop after the delimiter load = short-loop pad. |
| func_002BEAA8 | PROGRESS | g.c: while(1) with != key arm continuing, goto out to a shared return 0 - loop body now identical to retail. Left: retail loads n into v0 and copies to a3 (ours loads into a3) + the alignment nop that follows; re-read count / test-then-assign forms keep the tie. |
| func_00353550 | PERM ROTATED | 15 min PERM_RANDOMIZE over st/early-return/hdr: best outputs change the return type to long long (junk); nothing under 29. |
| func_001C2328 | NOTE | the stray nop is the short-loop pad on the backward bnez to the shared early-return block (jr ra + slot) - call_loop_pad supplies it. Still 12+: retail cross-jumps every return 0 into the first block; switch/if-chain/result-var forms keep a separate tail. |
| func_00332508 | MATCH | delay-loop bound in a local 'end = -1' set right before the for (permuter find, cleaned). |
| func_0035A7A0 / func_0035A968 | NONE | constant-in-local (none = -1 / r = -1) forms: no change (3 / 2). |
| func_00305858 | MATCH | batch44 store order brute (vary, 24 perms): +0xC, +4, +8, +0=5 (sn). |
| func_001641B8 | MATCH | batch43: cSnd_SeCall_2CB8A0 prototype returns int (keeps v0 live, -1 lands in v1) (sn). |
| func_002D4248 | MATCH | batch36: func_00344E88 called with its real 2nd arg (0x5C value) per src/cod/00344e88.c (sn). |
| func_002A4E58 | MATCH | batch35: store-order brute; near-ascending order 2074,2078,2080,207C,2084,2088 (sn). |
| cEmSetParam_updateSetDataPos | BLOCKED | batch41: retail cvt.w.s (in place); every compiler emits trunc.w.s for (int) casts (sa_precheck SKIP cvtws). |
| JukeBox_Release | MATCH | batch39: cIDBase_release returns int (phase_a_sn.c) + F4/F0 store order (sn). |
| func_001B81A8 | MATCH | batch40: func_001B6FB8 returns int (retail sets v0) — voidint sweep (sn). |
| func_002BEAA8 | NONE | permuter 15 min, PERM_RANDOMIZE over the n-load/init region: no improvement over base (220). |
| func_002B2158 | MATCH | batch45: store order +0x20 before +0x30; trailing clears ascending 0xC..0xF (sn). |
| func_002949E8 | MATCH | batch43: inverted condition (>= branch first) (sn). |
| func_001ECFE8 | MATCH | batch35: plain `self + 0x4BC + w * 0x7C` form, unsigned short w (sn). |
| func_00377530 | MATCH | batch33: struct-field rewrite of the flag logic; flags store before mode=2 (sn). |
| func_003A79F8 | NONE | sa_nm: beql lands before the loop-align nop; 20 shape variants (case order, cond forms, goto loop, fmt pre-inc), flags, permuter (scores base 0, blind to branch target). |
| func_001482C0 | MATCH | batch42: trailing matrix stores in ascending offset order (sn). |
| func_002BEB00 | MATCH | batch37: b = *self; r = b + b->ofs8; r += (e[3]+idx)*0x30 (sn). |
| func_002D51F0 | MATCH | batch31: plain for loop over 0x58-byte array (drops the inline-asm daddu) (sn). |
| func_002D56A8 | MATCH | batch31: same as 002D51F0 with int index (sn). |
| func_00133AA8 | MATCH | batch41: struct rewrite, min[0..2], max[0..2], flags &= ~2 (5040-order brute) (sn). |
| func_0015FCB8 / func_00140BF0 | PROGRESS | batch32/35: retail keeps a copy of the slot pointer (daddu v1,a0) and s1=a1; struct-array forms worse (16+). Queued for permuter. |
| func_00394D00 | MATCH | batch31: natural for-loop table search, D_003F5520 as struct, clears a,key,c (sn). |
| func_002831C8 | PROGRESS | batch32: unsigned switch with default on case 0 (21->9); left: case 2 reloads v0=3 instead of reusing the compare delay slot. |
| func_00383DD0 | MATCH | batch36: natural struct loop rewrite (sn). |
| func_002B3190 | BLOCKED | batch36: returns n == 6 (natural rewrite fixes regs); retail pads only the first div.s (2 nops), second none; no fp_hazard_rules set reproduces it (best mtc1,div1: 7). |
| func_00375988 | NONE | permuter 15 min (PERM_RANDOMIZE over tbl3 if + copy block, 12.8k iters): no improvement; ternary/struct-copy/global-direct forms worse. |
| func_002B2C98 | MATCH | batch37: cEvent_getCutFrame returns float (cutCmd.h); hw <= frame -> 0; as sn (sn). |
| func_0028E7C8 | PROGRESS | batch45: rewrite on cScenario.h/cTaskWork (20->18); left: s0/s1 (hi(D_003C2F84) vs arg) swap and id copied to a0. |
| Motion_seq_readEffectData | MATCH | batch43 (no C before): struct-by-value return; memset prototype returns void* (sn). |
| MoveEffect | MATCH | batch44 (no C before): fresh decomp; FLAG volatile read of hardware timer 0x10000800 (sn). |
| func_003057D0 | MATCH | batch44 (no C before): fresh decomp (sn). |
| func_002AE990 | MATCH | batch44 (no C before): fresh decomp, D_007474A0 via local pointer (sn). |
| objScroll_Set_test | MATCH | NOC: fresh decomp, mesh for-loop (sn). |
| objScroll_Set_test | MATCH | (packaged after solve.py _nm.c fallback) |
| func_00319CC0 | MATCH | NOC: fresh decomp; Forward155AE8_148F00 void extern; local g base (sn). |
| func_003757A0 | MATCH | NOC: static init/destroy of D_0076A600[3]; call_loop_pad (sn). |
| func_0017FC58 | NONE | permuter PERM_RANDOMIZE 15 min, ~12k iters, no improvement over 20. |
| func_00126918 | MATCH | NOC: fresh decomp, 166C before 1668 (sn). |
| func_00144FD8 | MATCH | NOC: fresh decomp, if/else-if>=0x24/else; func_001451A0 3-arg extern (sn). |
| func_003778D8 | MATCH | NOC: indexed table copy, &S[i] then &D[i], zero case first (sn). |
| func_0037CE20 | MATCH | NOC: indexed table copy, &S[i] then &D[i], zero case first (sn). |
| objScroll_Set_test | SKIP | already registered as src/cod/sa_objScroll_Set_test.c; handoff withdrawn (batch46 INCLUDE_ASM line is stale). VanishEffect (sa_vanisheffect.c) and func_0031C438 (sa_0031c350.c) likewise stale in batch49/batch46. |
| func_001B1BD0 | MATCH | NOC: fresh decomp (sn). |
| func_001B0BD0 | MATCH | NOC: fresh decomp; inline V3 copy with self-assign guard (sn). FLAG. |
| func_001FF3A0 | MATCH | NOC: fresh decomp, se[10] loop (sn). |
| func_002009E8 | MATCH | NOC: static init; nested ifs, inline vec4 init via p/p++ (sn). |
| SetEffectParts | BLOCKED | needs sqc2 $vf0 stores (only reachable via the VU0_SQC2_VF0 inline-asm macro). |
| func_002831C8 | PROGRESS | 9->3: switch where case 2 does b=4; goto into case 1's shared stores (q3.c); left: retail sets v0=3 before v1=2 and case 2 jumps past both (redundant v0=3 deleted). |
| func_001A6F00 | BLOCKED | retail copies a vector via lqc2/sqc2 $vf4 (VU0 inline-asm copy); not reachable from C. |
| (inbox_nm_func_0020*-0025* x55) | SKIP | halt-demote stubs with no C anywhere (inbox/done C files are empty); functions are 116-2600 insns. Not attempted as fresh decomps. |
| func_001D6A70 | PROGRESS | 76->2: CidColor bitfield params, switch on unsigned char mode, from/to/col locals (func_001D6A70/y_ftc_tc_col.c); left: one and/or pair swapped (scheduler tie). |
| func_001E7660 | PROGRESS | 76->2 with the same rewrite (alpha 0x48); same scheduler tie. |
| func_00321F48 | BLOCKED | only matches with a compiler flag outside the allowed list (see earlier flag notes). |
| func_002CCB58 | PERM | random permuter ~10 min on inline-helper base: 935->635 (word count still off); hand variants stuck at 2-4 words short. |
| func_001D6A70 | MATCH | CidColor rewrite + interleave search (order 2345_tf) (sn). FLAG local CidColor prototypes. |
| func_001E7660 | MATCH | same rewrite, alpha 0x48 (sn). |
| func_0015FCB8 | PROGRESS | 15: retail computes slot pointer into a0 and stores +0 through a copy (v1); inline setter/struct copy/explicit copy variants don't reproduce it. |
| func_002CCB58 | gave up | ~30 min: inline chk helper + separate hit/ret (func_002CCB58/h_int_2.c) gets the early y load and explicit ret=1; still 3 words short: retail uses movz with CSE'd const-1 reg for the else result and a shared epilogue. |
| cIDParam_initialize | GAVE UP | permuter (PERM_LINESWAP over stores) 15 min: base 830 -> best 815, no usable output. |
| func_002831C8 | GAVE UP | permuter manual (LINESWAP per case + b type + const casts) 12 min: nothing below base 20 (3 diffs). |
| func_0015FCB8 / func_00140BF0 | GAVE UP | random permuter reached 1 diff only via junk `e++; e--;` between stores (rejected); 16 real-C address/inline/int-array forms all stay at 15 diffs. |
| func_0028E7C8 | MATCH | handed off: copied the matched sibling cOmScripted_startSeq's form (unused works read + no*SIZE+(int)works). FLAG: dead read. |
| func_00151688 | GAVE UP | random permuter 15 min: base 6265 -> best 5220 (register-only, 165 diffs); no usable direction. |
| (checkpoint 71-80) | INFO | headers: sndSys76A790.h only; no NM file uses D_0076A790 and no give-up was type/prototype-blocked -> no retries. 68 new NM fns queued. Inventory parser now reads (sn/cygnus/dr/call-loop-pad) header tags. |
| func_002BB2D8 | GAVE UP | ~25 min: 1 diff (retail dsra, ours dsrl after andi 0xFF). 16 forms of t (long/int/short/u16/u32 casts, /2, &1, !=0), signed/plain char flags, bitfields, ee-2.9/cygnus: all dsrl or worse. |
| func_0033A618 / func_0033D870 | GAVE UP | 1 diff each, cygnus reorg bne vs retail bnel (annulled slot); allowed-flag sweep, switch/direct-field forms: no change. Same class as func_0033E5C0/func_0033BEC0. |
| func_00394F20 | GAVE UP | ~15 min: 5 diffs (short-loop nop+bne vs our bnel; first beqz threads straight to return 5; D_003F8528 hi in v1). 8 list-walk forms, 3 tail forms, as=sn: no better. |
| func_0034C2D0 | GAVE UP | ~15 min: 9 diffs. Struct-member array/address forms keep 9; base-pointer forms fix the address order but the guard grows (11-25). |
| func_00379F00 | PROGRESS | split `pp = c->pos; pp += c->page;` gives retail's exact shape, 17 diffs all a1/a2/a3 rotation. 641 decl orders + 8 stmt orders + types: no change. Queued for permuter. |
| func_002D40F8 | MATCH | handed off: memset func_003A52F0 declared returning void* (as criStm.h). FLAG: prototype. |
| func_001331B8 | GAVE UP | ~20 min: best 8 diffs (k3: k=0 and a copied walk pointer inside the if). Inline helper, loop shapes, address forms no better; permuter 15 min 435->250 only via an empty do{}while(0) statement (rejected). |
| func_0031C238 | MATCH | handed off: memcpy func_003A5148 declared returning void*. FLAG: prototype. |
| func_00379F00 | MATCH | handed off: `base = c->pos; pp = &base[c->page];` (permuter hinted a second pointer; junk parts dropped). |
| func_002BB2D8 | MATCH | handed off: `(t >> 1) % 2UL == 1` (permuter hit used a junk all-ones mask; the unsigned-long modulus is the real form). |
| func_00335F20 | MATCH | handed off: func_003281C8 declared returning int (matches its definition). Found via permuter prototype mutation. FLAG: prototype. |
| func_00375988 | MATCH | handed off: func_003758E8 declared returning int (its definition). FLAG: prototype. |
| func_00375380 | MATCH | handed off: func_00377FA0 (rand, returns a byte) declared int as in registered callers. FLAG: prototype. |
| func_002E2800 | MATCH | handed off: `int t = o->resetTime; o->timer = t ? t : 30;`, volatile dropped (permuter hinted the temp). |
| func_003566E8 | PROGRESS | real callee protos (viBufAddDMA/sfmpvp_PutVibuf int, from their definitions) 5->1: only the busy-test bnel vs retail bnez remains; 4 guard shapes, 4 int/void combos no better. Queue for permuter. |
| func_00394F20 | NOTE | void->int on func_003951D0 gives 3, but that callee is an empty void stub; not used. |
| (tools) | INFO | viall.py was silently scoring nothing for the new sa_nm files (cached blk copies without a section attribute); now uses the inventory copies. Inventory header parser reads loose 'cygnus dr;' too. |
| func_002E2800 | MATCH | resubmitted: first handoff falsely rejected for '.word' (union member `word`); member renamed to `flags`. |

- 16:16Z func_0032D720: MATCH via block-scoped local `Sj32D720 *t = adxt->sji[i];` in the sji loop (7 diffs -> 0). Handoff written.
- func_0033AA48: int return type for the function (bare returns) tried for the bnel annul: no (4 diffs). Left to permuter.
- func_0016F4A8: all 6 orders + chained assignments of unk5EC/hp/hpMax: no. Queued for permuter.
- func_00103760: MATCH. Case 1 computes phase/objFlags/flags/timer into locals, then stores timer, objFlags, flags, phase (7 stays in a1, 300 in v0). ~20 min. Handoff written.
- func_0019AD00: float groups were reversed vs source; writing f[0..2] before f[4..6] fixes them (8 -> 2). Left: the two stores of a2=7 (sw 0x5EC vs sb 0x60C) around the COL_A store. Tail-order and do-while variants no better than 2. Permuter next.
- func_0033AA48: hoisting `ch < 4` before the init test flips bnel to bne, but sltiu writes a0 not v0 (2 diffs). Same live-range class as func_0033A8D0. Not given up; permuter not started.
- func_00377AC0: sibling spelling, reversed compare, nested if, char*+0x14: best still 2 (independent loads in one block). Not given up.
- func_003BA3D8: two opposite likely-bits, registers already match. Global flag cannot fix both polarities. Not given up.
- func_00327A50: stat-before-unk2 puts sb/sb/sw in retail's relative order, but sw size stays first (4 diffs vs base 3). do{}while(0) on the size store delays it and scrambles the div (19). char* store, if, temp: still 4. Not given up.
- func_003977C8: all 6 orders of the RPC stores plus a local stay at 3. Not given up.
- func_003315D8: ret stays in a0 with a final move to v0 (18 diffs, 72 vs 71 words). Early return 26; register/unsigned/decl swap still 18. Not given up.
- func_002D3C78: reversed tail (consts before the i2C load, retail-ish order) 8-17 diffs vs base 7. Left at 7.
- func_002FBB78: saving flag to a local first still 32 diffs (slot pointer in a3, extra daddu a2,a3). Main-agent sweep stands. Not given up.
- func_0019AD00: PERM_RANDOMIZE on the 10 tail stores, 9759 iterations, best score stayed at the base 120. No output better than the 2-diff float-fixed C. Run killed on stop; no permuter left in godhand-nix. Best real C is still the float-order fix at 2 diffs. Not given up.
- STOP 17:38Z: permuter killed and confirmed gone. func_00103760 handoff already in progress/nm_solved/func_00103760/. Nothing else solved and unhanded.

## Rebase 2026-10-17

The tree moved to `/Users/joncaceres/god-hand-decomp` (branch `work`). NM drafts whose functions upstream had matched were dropped:
batch26_nm.c, batch35_nm.c, batch46_nm.c, batch49_nm.c, inbox_nm_func_001A6F00.c, inbox_nm_func_00201960.c,
inbox_nm_func_00262980.c, sa_nm_00103760.c, sa_nm_0013de90.c, sa_nm_0014e5d0.c, sa_nm_00274018.c,
sa_nm_002948e8.c, sa_nm_002d3ba8.c. batch31_nm.c keeps only func_002C5338. Before working on a function, check that it isn't
already carved in `compile_config.json` under its current name.

- func_003780F8: MATCH (~15 min). Even branch wrapped in `do { ts = tbl[r].s; tc = tbl[r].c; *s = ts; } while (0); *c = tc;`. FLAG do-while(0). Permuter score 0 also had `ts++; ts--;` around that wrap; the increments are junk and are not in the handoff. sn-2.95.3-136. Handoff progress/nm_solved/func_003780F8/. Permuter killed; none left in godhand-nix.
- func_0016F4A8: GAVE UP (~45 min). 2 diffs: `sw unk5EC` and `sh hpMax` swapped; `sh hp` in the jal delay slot already matches. All 6 orders of the three v0=1 stores stay at 2 or worse (source order unk5EC, hpMax, hp is a 3-diff rotation). A second `self->unk5EC = 1` after `hpMax = 1; hp = 1` matches (79 insns, 9 relocs) but the compiler deletes that store after scheduling; rejected as a redundant store. Permuter 900s, base 60, best permuter-score 10, only that family. sn-2.95.3-136. Permuter finished; none left in godhand-nix.
- func_003A79F8: GAVE UP (~20 min). 1 diff: `beql` into the range-fill loop targets the `.p2align 3` nop (BB label `$L18` sits before the align; loop-back `$L23` is after it). Retail's beql and the back-edge share the post-align label. goto/for/while/user-label forms, ee-2.9, cygnus, `-fno-align-loops`, `-fno-align-jumps` do not move the target. sn-2.95.3-136.
- func_003B2080: GAVE UP (~25 min). 2 diffs: `addiu %lo(D_00460040)` and `lw %lo(D_0077E520)` swapped; the two `lui %hi` already match. Source order, do-while, reused temp, volatile, and a memory barrier do not fix it (best stays 2). Permuter 15 min, base 60, best permuter-score 30 only via a duplicate if/else or `if (0) {}` (junk, rejected). ee-2.9-991111. Permuter finished; none left in godhand-nix.
- func_0033FB78 / func_0033AA48 / func_00341EC0 / func_003566E8: GAVE UP. 1 diff each, cygnus reorg `bnel` vs retail `bne`/`bnez` with the same delay-slot insn. Same class as func_0033E5C0 / func_0033A618 / func_0033D870. Guard shapes, callee int/void, and (0033FB78) the odd-result test were already tried; not sent through another permuter.
- func_00352258: GAVE UP (~20 min). 2 diffs: `mult` and `sd ra` swapped. `long long`/`int` return on func_003B7FE0, two-arg call, local product, and `do {} while (0)` in place of the barrier all stay at 2 (dropping the barrier tail-calls, 14 vs 15 words). Permuter 15 min, base 60, 17696 iters, no output. cygnus-2.96 drop-reorder. Permuter finished; none left in godhand-nix.
- func_00327A50: GAVE UP (~25 min). 3 diffs: `sw size` / `sb stat` / `sw sj` rotated around a matching `sb unk2`. Retail source order and do-while groupings are 5 to 59. Permuter 15 min, base 230; best permuter scores (40, 70) re-score as 4 and 7 under match_check, and the score-40 source needs `e++; e--;` plus an empty `if (e)` (junk, rejected). Clean chained `nsct2 = (nsct = nsct)` stays at 3. cygnus-2.96 drop-reorder. Permuter finished; none left in godhand-nix.
- func_00321F48: GAVE UP (~15 min). find_fde. Default ee-2.9 deletes the post-loop `ob == 0` test (35 diffs). `-fno-thread-jumps` is not a handoff flag; under it, 2 diffs remain: the loop-exit `beqz` targets the test with a nop slot, retail targets the `return 0` with `v0 = 0` in the slot. goto/while forms are 18 and 35. ee-2.9-991111.
- func_00377AC0: do-while around the owner load, and owner/id locals, jump to 51-54 diffs (loads leave the compare). Operand swap stays at 3. Best remains 2. Queued for permuter.
- func_00340580: inverting the two early guards optimizes back to the same 9 diffs (prologue copy order plus beql vs beq). cygnus-2.96 drop-reorder.
- func_00377AC0: GAVE UP (~20 min). 2 diffs: `lw` of voice owner at 0x14 and `lw` of track id at 0x4 swapped. Permuter 15 min, base 20, best 10 only via `if (n) { ... } else { same }` and `(ch / 2) ^ 0` (junk, rejected). Clean `2 & kind` stays at 2. sn-2.95.3-136. Permuter finished; none left in godhand-nix.
- func_00336218: GAVE UP. 2 diffs, both `bne` (retail) vs `bnel` (ours) with the same delay-slot insn. Same reorg class as func_0033E5C0. cygnus-2.96 drop-reorder.
- func_003977C8: do-while around `unk10 = 0; cmd = 0x10` grows the function (42). Swapping those two stores, and `void *func_003B63A0`, stay at 3. ee-2.9-991111.
- func_0034F4C0: `int ret = 1; return ret` leaves the 6 diffs (slti/0x40000 in v0, retail v1, plus one beql). Named 0x40/0x10000/0x40000 locals go to 22. cygnus-2.96 drop-reorder.
- func_0033D090: GAVE UP (~25 min). 7 diffs, v0/v1 swapped in the default-code copy block. Temps, a pointer copy, store order, and signed globals or fields all stay at 7. Permuter 15 min, base 40, best 20 only via `o++; o--;` or a duplicate store (junk); reusing `ch` as the temp gives 6 with different registers. cygnus-2.96 drop-reorder. Permuter finished; none left in godhand-nix.
- func_0017AC90: MATCH (~10 min). New NM file from batches 85-91. Statement order only: `0x548 = 0x78; 0x54A = 0x78; 0x250 = bits;` (was 54A, 250, 548). 84 insns, 6 relocs. sn-2.95.3-136, no meta.json. Handoff progress/nm_solved/func_0017AC90/. Note: build/SLUS_215.03.map was briefly 0 bytes during a main-agent build; scratch scores in that window show bogus reloc errors. Re-verified after the map came back.
- func_0016F4A8: all 5040 orders of the last seven tail stores (unk5F6, work, workNum, unk5F4, unk5EC, hp, hpMax): best 2. Sibling (0016fd68/00170050) orders: 27-31. Stays given up.
- func_0016F790: GAVE UP (~10 min). New file; same sw 0x5EC / sh 0x548 tie as func_0016F4A8. All 5040 orders of the last seven stores (split chained COL_A/COL_B): best 2. sn-2.95.3-136.
- func_003BA3D8 / func_0019AD00 / func_00342FF8: GAVE UP (over 30 min total across sessions). 003BA3D8 has opposite likely-bit choices on two branches. 0019AD00 (2 after the float-order fix) is the same short-store tie as func_00178E18. 00342FF8 (2 after req.d=0 per arm) is a load-order tie: 120 orders and a permuter found only junk.
- func_003977C8: GAVE UP (~30 min). 3 diffs: `sw zero, 0x10` scheduled after the arg setup. Permuter 15 min over the RPC store block, base 335, best 225 (`intr = 0x10` temp), which re-scores at 6 under match_check. ee-2.9-991111. Permuter finished; none left in godhand-nix.
- QUEUE ~17:30Z: what remains open is register-allocation or schedule noise at 7-18 diffs (func_00340580, func_00347AF8, func_003454F0, func_0036D1A8, func_003315D8, func_003552D0) plus far drafts (45+). New batch 85-91 files: func_0017AC90 solved, func_0016F790 gave up; func_0028A780 (71), func_0032D868 (66), func_00347498 (47), and func_0034C3A8 (60) are far. Waiting 20 min, then re-checking src/ and PROGRESS.md. No permuter running.
- STATUS 15:58Z: about 25 NM functions tried this session; 1 solved (func_003780F8, registered per nm_solved/handoff_log.tsv), 14 gave up, the rest open at 3-9 diffs. No tool blockers.
- func_0034F4C0: GAVE UP (~20 min). Permuter 15 min on the len2/len tail, base 225, best 155. The clean pieces (`arg = len < 0x40`, `return (unsigned long)1`) re-score at 28 and 6. No match_check improvement. cygnus-2.96 drop-reorder. Permuter finished; none left in godhand-nix.
- RECHECK ~17:50Z: func_0017AC90 registered (handoff_log 12:23). New NM files since last check: func_001FF858, func_002B3D70, func_003511F8 (PARK 79), func_00354650, func_00386DE0 (PARK 65).
- func_00354650: MATCH (87 insns, 23 relocs), handed off to nm_solved/func_00354650/ (solved.c + meta.json: cygnus-2.96, drop -freorder-blocks, because the header says "-freorder-blocks dropped" rather than the drop-reorder keyword). The only fix is the callee prototype: `extern int func_0036C450(int, int, int)`, matching its real definition in src/cod/00324108.c. The NM declared it void, which put the a1/a2 setup for the second call in the wrong order. Found through the permuter, which had also slipped in redundant `new_var = sf` copies; those are not needed. Caution: an earlier multi.py batch scored the int prototype at 2; mc.py says MATCH, so trust mc.py.
- func_002B3D70: open. Join-block ordering brute force (48 variants) gets 11 -> 9: putting `D_003C2550 = 0` after the flags clears helps, but the flags load still schedules above the counter store.
- func_001FF858: open. The header's 5-word gap closes once `p` is reassigned inside the name loop: `for (i = 0; p[i] != 0; i++) p[i] = tolower((p = self->name)[i]);` gives 87 words and 19 diffs. Retail hoists self->name as a copy ($7) and walks the store pointer; ours recomputes s1+25 inside the loop. 288 while/do/goto/for shapes all floor at 19.
- func_00354650: registered by the main agent (handoff_log 13:01).
- TOOL CAVEAT: multi.py takes the preamble (types and prototypes) from v0.c only, so prototype changes in v1..vN are silently ignored. That is why the int prototype for func_00354650 scored 2 in multi.py. Added progress/nm_work/tools/protosweep.py: it flips each extern's return type (void/int/void*/long, plus all-int) and scores each variant with mc.py. Re-swept this session's open and given-up functions where the base score reproduces the known count (0033FB78, 0033AA48, 00341EC0, 003566E8, 00347AF8, 003454F0, 00352258, 00327A50, 00377AC0, 0034F4C0, 0033D090, 003977C8, 0016F790, 003A79F8, 003B2080, 0016F4A8, 003BA3D8, 0019AD00, 002B3D70): no improvement from any flip. Not re-swept because my guessed flags gave the wrong length: 00340580, 0036D1A8, 003315D8, 00321F48, 00336218, 00342FF8.
- func_001FF858: GAVE UP (~35 min). Best is 19 diffs at 87 words, using `p[i] = tolower((p = self->name)[i])`. A 15-min permuter got 845 -> 670, which re-scores worse (74 diffs, 89 words) because of a hoisted name pointer. Inline strlwr helpers (13 shapes) all strength-reduce back to 82 words. Retail keeps a self->name copy in $7, reassigns p from it in the back-edge delay slot, stores and tests through a walking pointer, and loads p[i] by index.
- func_002B3D70: GAVE UP (~30 min). Join-block order brute force 11 -> 9, prototype sweep no change. A 15-min permuter got 1095 -> 820, but only through junk (a `new_var = self` alias plus a hoisted f8C pointer). Rejected.
- func_00386DE0: GAVE UP (PARK 65, register-pair swap). Int params, callee prototypes, memcpy or pointer copy, and a goto split don't help; the best of 72 tail-order variants is 61. Too far.
- func_003511F8 (sfmpv_SearchDelim, PARK 79): skipped as too far.
- QUEUE ~17:55Z: no new near-misses. Waiting 20 min, then re-checking src/ and PROGRESS.md. No permuter running.
- RECHECK ~18:20Z: checkpoint batches 92-100 (17:37Z). Its only header change is newlibMalloc.h, which none of my give-ups use, so no retries. New NM files: 001DCC30, 001FC810 (STOP 82), 001FFF80 (cDoor_setDoorJump, 9), 0028E858 (8), 0034E9B0 (18), 00353630 (PARK 82).
- func_001DCC30: MATCH (93 insns, 1 reloc), handed off to nm_solved/func_001DCC30/solved.c (sn from the header, no meta). Fix: drop the `tbl` local and index self->slot directly at all three sites (search compare, clear loop, final marks). Using self->slot only for the marks reshaped the loop; doing it everywhere matches. Found by brute-forcing tbl declaration position x use sites (72 variants). The `if (k < N) do {} while (++k < N)` shape was already in the NM.
- cDoor_setDoorJump (func_001FFF80): MATCH (94 insns, 21 relocs), handed off to nm_solved/cDoor_setDoorJump/solved.c (sn from the header, no meta). Fix: statement order only, with `SYS_LOCK2() |= 0x100000;` after the four SYS_LOCK() ors instead of before them. Found by brute-forcing all 720 orders of the lock block plus the task-flag store; this was the only exact one.
- func_0028E858: MATCH (94 insns, 24 relocs), handed off to nm_solved/func_0028E858/solved.c (sn, no meta). Fix: pass `(int)v.z` as the float heading argument. sn folds away the float->int->float round-trip, but it moves the f12 load ahead of D_003C2F84 and gives the retail f0/f1/f2 constant allocation. FLAG: the cast is semantically odd (v.z is 0.0, so the value is unchanged), but it is real C, not a no-op statement. A one-line constraint comment at the call explains it. The permuter found it as `se = v.z;` (reusing the int `se`); an `int z = v.z` local and the cast match too. Before that, 144 store-order/scope/arg-form variants and 9 prototype/vector-type variants all stayed at 8.
- func_0034E9B0: s/in callee-saved swap (18). Declaring `in` at 4 positions x 3 `s->in` use sites gives 17 at best; the prototype sweep doesn't help. Permuter next.
- func_0034E9B0: GAVE UP (~30 min). A 15-min permuter got 160 -> 105, but only with `in->unk154++; in->unk154--;` junk. Rejected. Same s1/s2 swap as noted.
- func_0016F790: still given up. A 15-min permuter (11.7k iterations) stayed at base 60.
- func_00347AF8: GAVE UP. A 15-min permuter got 60 -> 20, but only through junk (an identical if/else on buf, or an if (1)). Rejected.
- func_00333CE0: MATCH (95 insns, 23 relocs), handed off (solved.c + meta.json: cygnus-2.96, drop -freorder-blocks). Fix: declare memset func_003A52F0 as returning void* (as in criStm.h) instead of void. Found by protosweep. FLAG: prototype.
- func_0030B298: MATCH (97 insns, 34 relocs), handed off (sn, no meta). Fix: declare func_001FF858 as returning int (its definition returns 1) instead of void. Found by protosweep. FLAG: prototype.
- cSnd_BgmControl (func_002D0938): skipped. The one missing short-loop pad nop is an assembler behavior; --as=sn with call-loop-pad scores 35 vs 25, and the prototype sweep doesn't help.
- func_002D4C20: skipped. Its header documents a splitter false reloc pair (%hi/%lo D_70000040) that C cannot reproduce honestly; schedule diff 18; the prototype sweep doesn't help.
- Prototype sweep redone with correct flags: 00340580 (9), 0036D1A8 (17 -> 16 with func_0036D7C0 int, still far), 00336218 (2), 00342FF8 (5 in this copy): no fix. 00321F48 stays flag-blocked. New files with no prototype fix: cSnd_BgmControl, 002D4C20, 00377150, 002C21A0, 0015ADA0, 00339AE8.
- func_00377150: GAVE UP (~25 min). A 15-min permuter got 105 -> 55 by holding 0x17 in a local for unk2E, which fixes the tail loads (19 -> 11). The rest is the ch/data-pointer s1/s2 swap. 315 variants (0x17 local position x `one` local x decl order) all floor at 11.
- func_002D4C20, cSnd_BgmControl: skipped (see above). Remaining new files are far drafts: 002C21A0 (47), 0015ADA0 (62), 00339AE8 (69), 00300458 (97), 003520D8 (90), 001FC810 (82), 00353630 (82), 003511F8 (79).
- QUEUE ~19:15Z: this session's handoffs 001DCC30, cDoor_setDoorJump, 0028E858 registered at 14:19 per handoff_log; 00333CE0 and 0030B298 pending. Waiting 20 min, then re-checking. No permuter running.
- RECHECK ~19:40Z: new NM files 00159300 (PARK 107), 00325638 (4), 00333880 (7), 0037D3C8 (PARK 27), 00382660 (PARK 51). No new checkpoint.
- func_00325638: MATCH (100 insns, 38 relocs), handed off (solved.c + meta.json: cygnus-2.96, drop -freorder-blocks). Fix: declare D_00755C20 and D_00755C28 as the {fn, arg} callback struct that src/cod/0031f4e0.c uses (local typedef Cb325638), with the extern for D_00755C28 before D_00755C20, and clear them in field order (C20.fn, C20.arg, C28.fn, C28.arg). With the externs in address order it stays at 4; a block with two struct-pointer locals also matches.
- func_00333880: GAVE UP (~30 min). Declaring LogPrintf as int brings 7 -> 5 (the v0/v1 swap around the volatile `ng` spill remains). A non-volatile ng gives 99 words; 432 branch statement orders x ng++ forms floor at 5; a 15-min permuter stayed at base 30.
- func_0037D3C8: GAVE UP (PARK 27). Case 4 is 3 words short: retail keeps the divide-by-zero beql/break checks and copies through a1 for both divisions there; ours drops the checks. 7 ternary forms and 48 temp-variable variants (type x scope x operand order) don't help (27 best, 36 with a temp).
- func_00159300 (PARK 107), func_00382660 (PARK 51): skipped as too far.
- QUEUE ~20:25Z: 00325638 handed off (pending), plus 00333CE0 and 0030B298 pending. Waiting 20 min. No permuter running.
- func_0030B298, func_00325638, func_00333CE0: registered by the main agent (handoff_log 15:34). No pending handoffs.
- RECHECK ~20:50Z: one new NM file, func_00332178 (27). No new checkpoint.
- func_00332178: GAVE UP (~40 min). Two partial findings for whoever retries: reusing the `id` parameter for `size` (`id = bufsize - 0x40; e->size = id; ...`) puts id in t0 like retail, and the permuter likes `e->used = e->unk02 = 1;`. What remains is reorg delay-slot filling on the arg2/bufsize checks: retail fills each beqz slot from the branch target (the next check's andi/sltiu), ours from the fall-through (the error lui), and that shifts everything after it (29-32 diffs by mc). Prototype variants (log int, dtx_create_rmt(void), memset void/uint, SyncDCache/func_003B0640 int), goto error tails (87) and nested ok-conditions (33) don't help. Two 15-min permuter runs: 955 -> 425 -> 280.
- RECHECK ~21:00Z: new NM files 00150DC8 (103/104 words), 0032B888 (39), 003356B0 (2), 00373BA8 (104/103 words). Prototype sweep: no fixes.
- func_00373BA8: MATCH (103 insns, 10 relocs), handed off (sn, no meta). Fix, in the stereo/non-mode-1 arm: write the product as `25000 * nch * (freq / 1000)` (keeps freq in a1 and the constant in a3; same value mod 2^32), and hoist the header term into a block-local `int hdr = nch * 0x40C0 + 0x24;` added as `... + hdr + 0x40`. Found by brute-forcing the product order (12) and then header-term forms. The mono arm is unchanged.
- func_00150DC8: open. Retail uses xori+andi for the mode parity test; 32 spellings x arm orders give 103 or 107 words, never 104.
- func_003356B0: GAVE UP (~25 min). 2 diffs (0x0C/0x1C store pair). All 528 placements of `e->arg2 = arg2` (in the block and earlier in the function) x chained-zero forms floor at 2; a 15-min permuter stayed at base 20.
- func_0032B888 (39), func_00150DC8: left open as too far / no lead.
- QUEUE ~21:35Z: func_00373BA8 handed off (pending). Waiting 20 min. No permuter running.
- func_00373BA8: registered (handoff_log 17:04).

## Batch ~22:10Z (prototype sweep found no fixes for any of these)
- func_001AA510 (sn): GAVE UP at 9 diffs. Retail loads kind once and tests it as `li 5; slt; beqz`, storing kind to the stack argument slot in the delay slot. A literal `kind > 5` always becomes `slti 6`/`xori`. A local `int lim = 5;` does produce `li 5`/`slt` (12 diffs), but it hoists the `D_005FEE00` address above the branch, and the local is a magic-constant hack anyway. Best real C is k/v5.c: two unsigned-char loads, 9 diffs.
- cEmManage_SetEmAnger (sn): GAVE UP at 108 vs 110 words. In both abs tests retail keeps the source and the result in separate registers (`mov.s` in the bc1f delay slot, then `neg.s dst,src`). We always fold them into one register (`bc1tl` + `neg.s` in place). Tried 9 abs spellings, inline helpers, ABS-macro expansions, every compiler, and drop-reorder/sn-as. None changed it. A float-type or volatile difference in the original source is probable.
- 0013E0B0 (27 diffs), cCoreSave_spawnItems (104/106 words), 002A6FF8 (102/110), TransEsp (55), 0037E4C0 (106/108): PARKED. Too far off for an order or prototype fix. The prototype sweep was clean.
- func_00334310 (cygnus, drop-reorder): GAVE UP (~45 min) at 1 diff. Partial fix (from the permuter, then cleaned up): `int *psize; ... func_003351C0(name, &info); psize = &info.size; if (info.size == 0) {...} else size = *psize;` brings back retail's second `lw s1,4(sp)`. A `FileInfo334 *ip` pointer does not; it needs the int*. What remains is the success return: retail uses `bgezl s0` with `move v0,s1` annulled in the delay slot, ours uses a plain `bgez`. Tried tail forms (r >= 0 return, size = 0, goto fail, early return size), varargs/int/K&R prototypes for the log functions, and a protosweep on both versions: no change. Two 15-min permuter runs: 400 -> 200, then stuck at 200. Scratch: progress/nm_work/func_00334310/p/v0.c.
- Turn_dest (sn, as=sn, fdiv): GAVE UP (~30 min) at 2 diffs. Same idiom as cEmManage_SetEmAnger. Retail's final abs compares and negates the original d (`bc1t` with `mov.s r,d` in the delay slot, then `neg.s r,d`). With a plain `-d`, gcc copies d into r first and compares and negates r (114-116 words). `0.0f - d` keeps the right shape but emits sub.s. Tried 11 final forms and a 4x4 grid of ABS_F definitions x final forms: no fix. The 15-min permuter reached 200 only with junk (an alias variable, `if (1) {}`, split subtraction); rejected. Turn_dest_Y, the next function, uses the identical tail, so whoever cracks this idiom should be able to fix all three.
- func_0039B960 (ee-2.9-991111): MATCH. Handed off as progress/nm_solved/func_0039B960/solved.c. The fix is a chunk-size local, `u_int qwc = 0xFFC0;` (1023 quadwords x 64; the madr step 0xFFC00 is the same chunk in bytes), stored with `D3_QWC = qwc;`. That keeps the DMA register values in v1 and the addresses in a0/a1, as in retail. The permuter found it in about 2 minutes (it used a temp set right after ch.madr); every placement of the local matches, including an int type and the declaration initializer handed off. No meta.json is needed (the header names the compiler).
- func_00350F48 (50 diffs, 112/111 words) and func_00148D30 (PARK, 41 diffs): PARKED, too far off.
- QUEUE ~23:55Z: func_0039B960 handed off (pending). Waiting 20 min. No permuter running.
- func_0039B960: registered (handoff_log 18:33).
- Draw_Line_sc (sn, as=sn): MATCH. Handed off as progress/nm_solved/Draw_Line_sc/solved.c with meta.json {"compiler": "sn-2.95.3-136", "as": "sn"}, because the header says "as sn" rather than "as=sn". The fix is a screen-offset local, `int ofs = 0x800;`, used as `(float)(ofs - D_003C1180 / 2)`. It moves the %hi(D_00586B80) hoist ahead of the &v and &pts[i-1] setups, as in retail. The header said a 0x800 local didn't work; every placement I tried matches (top of the loop, before count++, before attr, initializer). Found by the permuter in about 3 minutes, after rewriting the `float (*pts)[4]` parameter as `float pts[][4]`, which the permuter cannot otherwise parse (base.c only; same code).
- LESSON: twice today a local holding a constant (0xFFC0, 0x800) fixed hoist-order and register-assignment diffs. Worth trying early on loop pre-header and volatile-store register swaps.
- 0035CC80 (88), 003090F8 (29): PARKED. 003B0EF8: blocked on the per-file extern_double setting (main agent's call), skipped.
- QUEUE ~00:50Z: Draw_Line_sc handed off (pending). Waiting 20 min. No permuter running.
- QUEUE ~00:50Z: Draw_Line_sc handed off (pending). Waiting 20 min. No permuter running.
- Draw_Line_sc: registered (handoff_log 19:02).
- Checkpoint 22:45Z header change (emPhaseTable.h) doesn't affect any prototype-blocked give-up; no retries needed.
- func_00283C70 (sn): PARKED (~25 min). The whole gap is retail keeping a second constant-2 register (s2) for entry 1's b2/b3 bytes, plus its save/restore (122 vs 119 words). Tried chained and reordered byte stores, a byte parameter on InitEnt, float x/y locals, and indexed or direct &D_00585660[n] forms: none add s2. The 15-min permuter went 1685 -> 1095, all junk (an alias pointer, `do {} while (0)`, a 0.1f local).
- func_002C1AE0 (sn, as=sn): PARKED (~15 min). Retail leaves the pi constant load unscheduled (after sub.s/abs.s); our scheduler moves it up into the lwc1 shadow. Tried 11 forms (pi local, d > pi, separate fabs statement, 2*pi spellings, ternary, the -(d - 2pi) form at 121 words/15 diffs) and the allowed fno-gcse/fast-math flags: no fix. 0030F8B0 (77), 0013C318 (90), 00383F50 (56): PARKED, too far off.
- QUEUE ~01:40Z: nothing pending. Waiting 20 min. No permuter running (confirmed PERM=0).
- func_003B3650 (ee-2.9-991111): PARKED (~20 min). The req/pkt s0/s1 swap survives the prototype sweep (no change). The 15-min permuter went 1220 -> 540, but only through junk (`do {} while (0)`, chained `pkt->f18 = (n = 0)`); cleaned versions of the n = 0 placement score 41 by mc (base 40).
- QUEUE ~02:25Z: nothing pending. Waiting 20 min. No permuter running.
- func_001C3988 (sn, -fno-gcse): PARKED (~10 min). Tried rewriting both loops around an inline bounds-checked part accessor modeled on matched sa_00194558.c (GetPart194558, `on[3]` stack copy) and sa_0026a3d8.c (SwayOwner_part, `hold[16]` copy). All three accessor forms land at 102 words vs retail 132, much further off than the NM's 129. Not pursued further.
- QUEUE ~03:10Z: nothing pending. Waiting 20 min. No permuter running.
- func_003563B8 (cygnus, drop-reorder): GAVE UP (~35 min) at 3 diffs (from 7). Setting constant locals right after the func_00355E88 call (`one = 1; m1 = -1;`, used for the st+0 and ix+0 stores) gets 5. A pairwise-swap hill-climb of the 13 reset stores (new tool progress/nm_work/tools/swapclimb.py) then reaches 3. Single-statement moves and a climb including the constant lines stay at 3. What remains: retail's st[0x12] byte store falls before the ix stores. The 15-min permuter "70" output is worse by mc (9 diffs). Note that the one/m1 locals are borderline anyway. Natural group order (st bytes / st+0 / st+0x20, then ix, then the rest; all 120 orders of the first group) floors at 11. Scratch: progress/nm_work/func_003563B8/b3.c.
- TOOL: progress/nm_work/tools/swapclimb.py SRC FUNC START END [mc args]: pairwise-swap hill-climb of a line block, scored with mc.py using 6 threads.
- func_00356C68 (cygnus, drop-reorder): GAVE UP (~15 min) at 1 diff (the final bnel vs bnez with the s0 restore in the delay slot). The prototype sweep, 7 condition shapes (early returns, nested, skip temp, De Morgan), a block-scoped loop pointer, and char/short/uchar `end` all stay at 1. It's a reorg liveness difference I can't reach from source.
- func_00159DA0 (sn, as=sn): GAVE UP (~25 min) at 8 diffs (v0/v1 alternation of the four lhu/sw pairs that fill r). Direct p->src indexing, an offset h, reversed fill order and comma fill all stay at 8 (the alternation doesn't follow statement order). Block temps give 9, and hoisting h above the calls breaks things. The 15-min permuter found no improvement at all.
- 0019AF80 (50), 0033EE30 (51), 0035A2B0 (46): PARKED, too far off.
- QUEUE ~05:00Z: nothing pending. Waiting 20 min. No permuter running (PERM=0 confirmed).
- func_00159DA0 (sn, as=sn): GAVE UP (~25 min) at 8 diffs (v0/v1 alternation of the four lhu/sw pairs that fill r). Direct p->src indexing, an offset h, reversed fill order and comma fill all stay at 8 (the alternation doesn't follow statement order). Block temps give 9, and hoisting h above the calls breaks things. The 15-min permuter found no improvement at all.
- 0019AF80 (50), 0033EE30 (51), 0035A2B0 (46): PARKED, too far off.
- QUEUE ~05:00Z: nothing pending. Waiting 20 min. No permuter running (PERM=0 confirmed).
- func_001AD5C8 (sn): MATCH. Handed off as progress/nm_solved/func_001AD5C8/solved.c (no meta.json; the header names sn). Fix: the four-byte state reset is a `static inline void Reset1AD5C8(char *p)` called from both case 0's early exit (`if (p[0x60D] == 0) { Reset1AD5C8(p); break; }`) and the end of case 1, instead of a shared `reset:` label. sched1 then sees the reset stores in case 1's block, which puts the 0x60D clear before the lui as in retail, and the later cross-jump merges the two copies into retail's single tail. Lead from the permuter (score 15 moved the 0x2F5 store above the label); the rest by reasoning. No goto remains.
- LESSON: when a shared tail reached by goto schedules differently from retail, try duplicating the tail at each source path (as an inline helper or a macro) and let cross-jumping merge it.
- func_002A6DA8 (sn): PARKED (~15 min). A swap-climb of the 25-statement loop body and all 576 single moves floor at 10. The %hi(D_003C1190)/%hi(D_003C1184) order and the attr+0x30 sd placement don't respond to statement order.
- 00140E58 (120), 0039CCC0 (147): PARKED, too far off.
- QUEUE ~06:15Z: func_001AD5C8 handed off (pending). Waiting 20 min. No permuter running.
- func_001AD5C8: registered (handoff_log 22:18).
- func_0027BB78 (sn): MATCH. Handed off as progress/nm_solved/func_0027BB78/solved.c. Fix: the TU-local prototype `extern float Turn_dest(void *a0, float f12, float f13, void *a1);` (the same order matched sa 002705d8.c uses), called as `Turn_dest(pos, rot, 3.1415927f, dst)`. Under EABI, float and integer arguments take separate register sequences, so only the source order of the argument moves changes: the lw a1 now lands in the jal delay slot as in retail. `(void *, float, void *, float)` also matches.
- LESSON: when argument-register setup order around a call differs and the callee mixes float and integer arguments, try reordering the prototype's float and integer parameters (the registers stay the same under EABI).
- func_001C26B8 (sn, as=sn): GAVE UP (~35 min) at 24 diffs with the correct size (54 words; the NM is at 64). Partial fixes: (1) prototype `Turn_dest(void *a0, float f12, float f13, void *a1)` makes the call setup match retail exactly (lwc1 f12, lw a1, then f13, with a0 in the delay slot); (2) an explicit `float b; if (a < 0.0f) b = -a; else b = a;` gives retail's bc1f + delay-slot mov.s + neg.s shape. The permuter matched in seconds, but only with a dead `b = a;` before `return 1` (verified: that statement alone gives MATCH). Keeping `a` alive past the abs is what retail needs, so the abs result must not fold into a's register. A dead store is not allowed, and the legitimate alternatives (inline Absf in 3 forms, a ternary, reusing d, `0.0f > a`, `a <= 0`, `0.0f - a`, `-1.0f * a`) all stay at 24 or 52 words. Probably the same root cause as Turn_dest and cEmManage_SetEmAnger: something in the original keeps the pre-abs value alive.
- ObjTrans (sa_nm_0030f650.c, sn): GAVE UP (~35 min), still 7 diffs. Two spots: (1) the toggle path, where retail does `addiu s1` before the shared `sw` (sw goes in the b delay slot); (2) the slot-3 VCall0 path, where retail increments `it` after the call and ours hoists it before. Tried 25 toggle/tail combinations (it++ first, an nf temp, ternary, `|=`, `*it++`, a common it++ after the if/else, `VCall0(*it,3)`, inverted condition), plus --as=sn, --drop-reorder and ee-2.9 (155 words). None beat 7. Permuter: base.c needed `sizeof(f[0])` in place of `sizeof(char *)` (the permuter parser mangles it); in 15 min the best was 180->100, but only by doubling `it++` on the 2C3190 path, which changes behavior, so rejected.
- func_001A5540 (sn): SOLVED (~10 min), handed off to progress/nm_solved/func_001A5540/solved.c. Fix: case 3 fills both vectors through float-param static inline setters, `SetV3((float *)(self + 0x5C0), 0, 0, 10)` and `SetV4(rot, 0, 0.86, 0, 1)`, and passes `(float *)(self + 0x5C0)` straight to VecRotVec (no `v` local). The inlined float params give retail's f2/f1/f0 constant allocation and store order. Setters alone (keeping `v`) stay at 7; dropping `v` without setters gives 153 words.
- func_0034A0F0 (cygnus dr): in progress, best 5 (from 4-with-wrong-d). Not reassigning d (`d = -d`) keeps d in v1 as in retail, but the negated value then gets v0 instead of a0; reusing `n` gives s1. Declaration order, block-local decls and equivalent arithmetic forms are all stuck at 5-6.
- func_0033A730 (cygnus dr): GAVE UP (~10 min), 1 diff. Retail fills the used-test bnez slot with sltiu without annulling; ours annuls (bnel). This is reorg's opposite-thread liveness, insensitive to source: tried !used, inverted and `> 3` id tests, `id < 0 || id >= 4`. The sibling func_0033ABD0 shows the mirror image of the same quirk.
- func_002CABE8 (sn): SKIPPED: the header notes retail's second lui (SeLoadNo fallback path) has no relocation in the split asm (raw 0x45), so it can't reloc-match even with the registers fixed.
- func_0029FDE0 (sn): in progress, best 2 (from 7). Fix so far: `int zz = 0xFFFF;` local for the XYZ z (hoists the two 64-bit constants before the i*32+0x1F giv init). Left: the `-1` (sign test for D_003C1180/64) is still hoisted after the giv init in ours, before it in retail.
- func_0036DFF0 (cygnus dr): SOLVED (~5 min), handed off with meta.json (cygnus-2.96, drop -freorder-blocks). Fix: `while (c->ready == 0 && (d = MPV_GoNextDelimSj(sj)) != 0)` rewritten as `for (;;) { if ((d = MPV_GoNextDelimSj(sj)) == 0) break; ... if (c->ready != 0) break; }`, which is equivalent because ready was just zeroed. Retail enters straight at the MPV call, and the putChunk/ungetChunk arg order also matches. A `while (MPV) {...; if (ready) break;}` form gives 132 words. (Note: mc's left column is retail, the right is ours.)
- func_0033D720 (cygnus dr): SOLVED (~5 min), handed off with meta.json. Fix: the header callback field type `void (*hdrcb)(...)` becomes `int (*hdrcb)(int obj, int *a, int *b, int *c)` (return value ignored). With an int return, retail's hdrobj load comes before the hdrcb load. An unprototyped `void (*)()`, void* obj, `(*fp)()` call syntax and explicit offsets don't help. The struct is file-local, so no header change is needed.
- func_0033DD78 (cygnus dr): GAVE UP (~25 min), 2 diffs. Retail reloads the spilled `rate` pointer (lw a0,4(sp)) before the channels lbu; ours after. Tried rate/ch statement orders, a pointer local, swapclimb over the field-store block, and 15 types of r/c temps. Permuter 15 min (base.c needed the signature joined onto one line, since the parser rejects multi-line params): no improvement over 60.
- func_00345BE0 (cygnus dr): -f=-fno-align-jumps fixes the size (76 words) and brings it to 32 diffs (from 56). Left: sched1 hoists `a1 = 0` for func_003487C0 above the error beqz (retail leaves it for the delay slot), plus the final sw 0x2D4 / sb play order.
- func_00334D68 (cygnus dr): SKIPPED after a look. cc1 output is identical; only reorg leaves the first bne slot empty where retail puts the lui a1. My guess is that reorg's target-liveness search (find_basic_block) gives up in our compiler and treats a1 as live, so this is the same class as func_0033A730. No source lever, since there is no barrier between function start and the target in either build.
- func_0037CF00 (sn): GAVE UP (~10 min), 3 diffs (the header's near-miss). Retail forms loop 2's pointer as (D+0x1E)+base*32 with a separate addiu 0x1E; ours folds 0x1E into the lb offset. Tried direct indexing, a prio pointer, an int prio temp, `D + base + i`, `&D[base] + i`, char* byte math, a tbl local (83-86 words), i from base to base+last (92 words), and `min >= prio`.
- func_00141B18 (sn): GAVE UP (~15 min), 10 diffs. Inline InitWorks(b, w, n) helpers (with and without a Restart helper) give 14-20 or 110 words: the `w[i]` operand order flips the addu, and the pre-loop hoist order changes. Other tries: `b = p + 0x190` (13), reusing w1 (12), `for (b = b2, ...)` (10), and using b2 directly (10). Retail's surviving `daddu s2,s4` copy needs b to stay one pseudo across loops 2 and 3; cse copy-propagates it in ours.
- func_002AF218, func_001F3118: skipped for now (heavily searched near-misses with multiple independent diffs).
- func_00358368 (cygnus dr): GAVE UP (~10 min), 11 diffs, all in the schedule of the align-and-copy block (retail: work+0x1F, then the -0x20 mask, then the struct-copy alignment test andi cprm,7 early). Tried the bufSize/hn/w4C/w48 orders (hn first: 37-47), unsigned/char* align casts, `& -0x20` / `& 0xFFFFFFE0` / `/32*32` masks, and a shared mask local (35).
- func_0029FDE0 (sn): PARKED at 2 diffs (from 7), partial in progress/nm_work/func_0029FDE0/i.c (`int zz = 0xFFFF;` z local). The permuter (15 min) found nothing below base 20. The remaining -1/giv-init order also didn't move with condition forms, decl orders, `<< 5`, or `+ -1`.
- func_003B9F60: SOLVED (~15 min), handed off with meta.json overriding the header's sn to cygnus-2.96 with -freorder-blocks dropped (the address range is SDK/library code; the same C under sn/ee is 19-20 words). C: `for (i = 0; i < 1; i++) { p = &D_003FC7B8[i]; if (p->word == 0) break; } return i != 1 ? p : 0;`. Assigning p inside the loop keeps retail's separate result giv and the delay-slot copy. Forms that assign p after the loop constant-fold to 5-6 words.
- func_00345BE0 (cygnus dr): SOLVED (~25 min), handed off with meta.json. Fixes: (1) final stores ordered unk84, unk2D4, play, stat (from a 24-way order search); (2) pass `m->buf1` directly to the two buf1 calls instead of through the `b1` local (`b0` stays a local). Fix 2 removes the sched1 hoist of `a1 = 0` above the error beqz. Found by the permuter in 3 min. Default flags: retail does align jumps, so -fno-align-jumps was a red herring.
- func_00188B50 (sn): SOLVED (~25 min), handed off. The tail becomes a file-local `static inline void InitDmgVol(char *p, int col, char *sub, int kind, int w)` called as `InitDmgVol(p, 1, p + EM_SUB_BUF, 6, 0xC9)`. Its body: the four zero stores, COL_A = col, TARGET = -1 (a literal, not a param), COL_B = col, SUB_PTR, SUB_KIND, 5EC. The inlined params give retail's "constants materialized first" schedule; the store order came from a 720-way permutation (best 2) and then making -1 a body literal (0). FLAG: the head keeps the existing NM's vector setup (`sz = size; size[0] = ...; sz[1] = ...` alias split plus the `one` local) unchanged. A cleaner SetV4 head is 1 off (size[2] goes via s1). Same idiom as func_0019AA80, which should be retried with this helper.

## func_0034A0F0: GAVE UP (5 diffs)
- 15-minute permuter on the v0 base (cygnus dr, base score 20) found no improvement. Best scratch result: func_0034A0F0/b4.c (5 diffs).

## func_0019AA80: in progress
- The InitDmgVol-style tail helper plus a 720-way store-order search reached 8 diffs (from 12), at progress/nm_work/func_0019AA80/perm6/q033.c. The head and constant materialization now match retail (a1=1, a2=7 shared, v1=p+0x620).
- The remaining diffs are the placement of the -1 and a0 moves among the zero stores, plus the 548/60C/5F4 store order.
- Signature variants (an unsigned char kind, a short col, a single kind param, -1 as a param, all literals) don't do better. Permuter launched.

## emDamageVol tail family: 7 MATCHES via one shared static inline helper (sn-2.95.3-136)
All seven use the identical helper below. Its params make retail's "constants materialized first" schedule come out.
```c
static inline void InitDmgVol(char *p, int col, char *sub, int kind, int w, int t)
{ 5E8=t; 5E4=0; 5F0=t; 5F6=0; COL_A=col; COL_B=col; SUB_PTR=sub; SUB_KIND=kind; 5EC=w; TARGET=-1; }
```
- func_00188B50: MATCH, handoff re-issued with the shared helper. Call: (p,1,p+EM_SUB_BUF,6,0xC9,0).
- func_0019A0B8 / func_0019A328 / func_0019A590: MATCH. These were earlier given up at 2 diffs. Call: (p,1,p+EM_SUB_BUF,7,7,0). Found with a 720-way helper store-order search; 7 of the 720 orders match.
- func_0019AA80: MATCH (was 8 diffs with a struct-field helper). The char* + EM_ offset helper matched. meta: sn.
- func_0019AD00: MATCH. Helper plus the head order swapped (f[0..2] stored before f[4..6]). meta: sn.
- func_0016F790: MATCH (was 2 diffs). Call: (p,1,p+EM_SUB_BUF,9,1,0x259).
- Suggestion for the main agent: the helper could move into include/godhand/emDamageVol.h. Each handoff keeps its own static copy, so no header change is required.
- func_00178E18 is not covered: its tail has 5F6=5 and a 5B8 |= 0x800 interleaved. Still to try.

## func_0016F4A8: MATCH (sn, meta sn)
- Same InitDmgVol helper with numeric offsets. emDamageVol.h isn't included because this file declares func_001C28A0 with a void* param. Call: ((char *)self, 1, self->workBuf, 6, 1, 600).

## func_00182690: MATCH (sn; header names the compiler, no meta)
- Changes: the InitDmgVol helper (call (p,1,p+EM_SUB_BUF,8,7,0)); `f[3] = one` moved before f[5]/f[6]; `float *nv` declared block-scoped inside each of the take and give blocks instead of shared across both. The shared nv was what put the slot in v0 instead of a0.

## func_002F48A8: still parked (13)
- Retail reloads MOT(self) after the frame-count join; ours CSEs it into a0. Tried a ternary, no mi local, an o/m2 local, int-typed loads for alias sets, and -fno-gcse (worse, and changes the size). No progress.

## func_0034A0F0 / func_0019AA80 permuters: see the entries above. func_00178E18: permuter running from the 5-diff base (only a col/s register swap left).

## func_00178E18: GAVE UP (helper approach)
- The InitDmgVol variant with a 5F6 param, plus a 5040-way order search, reached 5 diffs (a col/s register swap only). Signature reorders, short params, block-scoped nv, and 5F6 outside the helper all stay at 5 or worse. The 15-minute permuter found nothing (base 25). The original NM at 2 diffs remains the best; this enemy's tail likely isn't the shared helper.

## func_003769B0: MATCH (sn, meta {"compiler": "sn-2.95.3-136", "call_loop_pad": true})
- Rewrote as `for (i = 0, p = D_0076F050; i < 0x60; i++, p++) { if (p->id != 0 && !(p->flags & 0x10)) { if (key == 0) return p; if (p->key == key) return p; } } return 0;`.
- The last 2 words were R5900 short-loop nops (the backward beq to the shared `return p`). `--call-loop-pad`, the existing unit key, supplies them.
- New lever: sweeping all NMs with call_loop_pad.

## func_003A93F8: MATCH (meta {"compiler": "sn-2.95.3-136", "as": "sn", "call_loop_pad": true})
- The NM C is unchanged. The "two hazard nops at the outer loop head" are the R5900 short-loop pad that `call_loop_pad` emits. Found by padsweep (progress/nm_work/tools/padsweep.py).
- Note for the main agent: func_003A9498 (registered, flagged for one inline asm nop as a short-loop pad) would likely match without the nop under call_loop_pad. It's a registered unit, so I left it alone.

## padsweep (call_loop_pad over all NMs' best configs): results in progress/nm_work/padsweep_results.txt
- Improved: func_003A93F8 (MATCH, handed off), func_00347AF8 12->9, func_002CB278 15->11, cSnd_BgmControl (size fixed, 25), func_0035F418 41->39.
## func_002CB278: GAVE UP (12)
- Moving `ret = -1` after the find call (a found local) gives 12. Retail reloads a0/a1 from s-regs before cSnd_EmSeFind; ours reuses the incoming arg regs.
- The 15-minute permuter only reached `return ret = -1;` (junk; not better under mc).
## func_00347AF8: GAVE UP (9, cygnus dr)
- s0/s1 priority swap between buf and hn/sj. Tried no sj local, local order, a block-scoped type, an inverted test, and a hdr local: no change.
## func_003B21D0: permuter running (ee, 13). A pkt pointer local and buf/opt store order don't change it.
## func_003B21D0: GAVE UP (13, ee)
- The permuter went from 335 to 260 only via junk (duplicated loop body under `if (iopbuf)`), so rejected.
## func_003B4AD8: GAVE UP (27, ee)
- All 240 declaration orders of sid/mode/async/nowait/head stay at 27 (s4-s7 rotation). Note: the file has a doubled `#ifdef NON_MATCHING` (the outer and inner blocks are both open). The main agent may want to clean it up.

## func_0031CDC0: MATCH (sn; header names the compiler) (was PARK at 26)
- Changes: an early `if (base == 0) return 0;`. No explicit `n != 0` test: it's the rotated `for (i = 1; i <= n; i++)` entry check.
- `p = &base[n];` with `p++;` at the top of the loop body.
- Return written `(int *)(base[i] + (int)base)`, which puts the loaded value first in the addu.
## cFont_setTextureAddr: parked (20)
- Inline setter shapes (5 forms x 2 loop spellings) are all 21. Also tried C++ (cc1plus, extern "C") under sn/ee/cygnus: no better, and a handoff can't be .cc anyway.
## func_00376370: GAVE UP (8)
- Tried all 32 int/void callee return-type combinations: all 8. The permuter's best (120 from 790) moved a call out of the loop (semantic change), so rejected.
## func_00291D48: not C-fixable
- The output is identical except the retail short-loop pad nop in the two-branch inner list-scan loop (beqz exit + beqzl back edge). call_loop_pad intentionally skips multi-block loops. Needs a toolchain rule change.
## func_00394F20: still parked (5)
- Retail fills the loop bne delay slot with the redundant `lw v0,0(a0)` shared by both paths (plus the short-loop nop). Our reorg uses bnel and keeps the fallthrough copy.

## func_0034A5E0: MATCH (cygnus-2.96 dr, meta) (was 19)
- The only change: `i = 0` moved from before the GetTri78 early-out into the for-init (`for (i = 0; i < len - 0x12; i += 0x12)`). A while form with `i = 0;` just before the loop also matches.
## func_00376720: parked (19)
- for/while/do-while (`--i >= 0`) all compile identically (19). m2c-style goto forms with f preloaded give 26-38. Our i-- lands at the loop top and ori/args are scheduled ahead of the timer test.
## func_001FCBA0: not C-fixable (size off by 1)
- The retail nop-led loop head is a short-loop pad on a multi-block loop (same class as func_00291D48).
## 2026-10-19T05:29:21Z queue of promising NMs exhausted; waiting 20 min (PERM=0 confirmed)
## func_001F20F8: MATCH -> nm_solved/func_001F20F8 (sn, no meta)
- Fix: declare `extern int cRoomSave_clearEmDeadFlag(...)`, the real return type from cRoomSave.c, instead of void. The permuter found it via a junk `volatile unsigned` return, which I reduced to plain int.
- Permuter note: base.c must not carry `__attribute__((section))`; pycparser moves it after the declarator and cc1 rejects that.
## func_00276F18: MATCH -> nm_solved/func_00276F18 (sn, no meta)
- Fix: `extern void *func_003A52F0(void *, int, int);` (memset returns void*, as criStm.h declares) instead of void. The entry-6 v0/v1 swap goes away.
## Return-type sweep (tools/retsweep.py, retsweep_batch.py)
- Toggled each extern prototype's return type (void/int/void*/uint/short/char) across 17 parked regalloc NMs (results: nm_work/retsweep_batch1.txt). Only one improved:
  - func_00394F20: `extern int func_003951D0(void)` takes it 5 -> 3. The remaining 3 are the multi-block short-loop pad (retail nop+bne where ours has bnel), not fixable from C. The prototype is worth keeping if it is ever fixed.
- func_0028E0E0: `extern void espSys_effDataRegist(...)` takes it 16 -> 1. The remaining diff is bit-6 `dsrl` vs ours `srl`. 20+ expression forms tried (casts to 64-bit, bitfields, masks, byte loads): all give srl, lhu/lbu, or a size change. Permuter running.
## func_0028E0E0: parked at 1 (from 16)
- Best is nm_work/func_0028E0E0/w0.c: `extern void espSys_effDataRegist(...)` fixes the switch register (a0) and all branches. The one remaining diff is case 0x802 `lw; dsrl 6`, where ours emits `srl 6`. A 15-minute permuter run stayed at base.
- Standalone tests (nm_work/dsrl/): `unsigned long x = flags; (x>>6)&1` gives dsrl but adds dsll32/dsra32, and in context the function grows to 210 words. No form found that emits a plain dsrl.
## func_00337400: MATCH -> nm_solved/func_00337400 (cygnus dr meta) [FLAG]
- Fix: named constant locals. `int one; int two;`, with `one = 1;` before the loop and `for (i = 0, two = 2, e = base; ...)`. `one` replaces the literal 1 in `p->active != 1` and `p->u50.h == 1`; `two` replaces the literal in both `e->type = 2` stores.
- FLAG for the main agent: these are real value-carrying locals, not no-ops, but they are unusual source. The permuter found `one` (13 -> 3). Hand placement of e's init gave 2, and `two` closed it. Reject if you consider it perturbation.
## func_0034F4C0: MATCH -> nm_solved/func_0034F4C0 (cygnus dr meta)
- Fix: early-return tail. `if (len >= 0x40) return 1; if (code != 0x10000 && code != 0x40000) return 1; func_0034F658(w, 0); return 0;` replaces the combined `if (len < 0x40 && (...)) {...} return 1;`.
## func_0033D090: parked (7)
- Extern type sweep (27 combos), inline setKey helper (by value and by pointer), and a pointer temp: no change. The permuter's best (20 from 40) duplicates `o->k.s.a = D_003E9D54;`. Junk, rejected.
- Permuter note: base.c needs a single-line signature or permuter.py reports "does not contain any function".
## func_002CABE8: parked (5)
- The 6 assignment orders of hit/se/bgm and two placements: no better. Return-type sweep: nothing.
## func_001331B8: parked (7)
- Loop forms (while/for/++k/explicit (char*)+0xC), node pointer, name-array index test: no better.
## func_0034A0F0: MATCH -> nm_solved/func_0034A0F0 (cygnus dr meta)
- Fix: negate into a new local before the flag test. `} else { int nd = -d; if (flag) { int m = nd / 32 * 32; ... } }` replaces `} else if (flag) { d = -d; m = d / 32 * 32; ... }`. The permuter pointed at this (`new_var = -d` hoisted above `if (flag)`); the handoff uses the natural rewrite.
- func_001331B8: permuter (15 min) best was an empty `do { } while (0);` after `s = ...name;`. That's a no-op perturbation, and it scores 14 under mc anyway. Parked at 7.
## func_003315D8: MATCH -> nm_solved/func_003315D8 (cygnus dr meta)
- Fix: drop the `ret` variable and use returns: `if (D_003D845C == 0) return 0; if (req->kind != 2) return 0;` then the body, ending `if ((unsigned)(r+1) >= 2 && r != 0x20) { ...; return 1; } return 0;`. A combined `||` early test was 2 words short; the two separate tests match.
## func_001F4CA8: MATCH -> nm_solved/func_001F4CA8 (sn, no meta)
- Fix: the inline helper takes (self, idx) and computes `char *w = self + (idx * 0x7C + 0xF64);` internally. Call sites are `setItem(self, idx, ...)`. Passing `self + idx*0x7C + 0xF64` from the caller doesn't match, and neither does a hoisted local.
## func_003977C8: parked (3)
- The inline setReq(b, cmd, arg) helper in all 6 store orders: still 3. The permuter's best routes 0x10 through the `intr` local (junk), and scores 6 under mc.
## func_0015AF30: MATCH -> nm_solved/func_0015AF30 (meta: sn, c_flags_add -f=-ffast-math, fp_hazard_rules sqrt)
- Fix: move the last two calls into `static inline void setTrans(float (*out)[4], float *pos) { Vec15AF30 v; sceVu0ApplyMatrix(v, out, pos); sceVu0SubVector(out[3], pos, v); }`. Giving the helper its own `v` stops `&v` from being CSE'd into s0 across the call.
## func_002AC878 / cFont_setTextureAddr: parked
- 002AC878: dist() inline helpers (by points and by dx/dy, both add orders) stay at 18-19. The sqrt.s scheduling limit is as noted in its header.
- cFont_setTextureAddr: relocate()/setSlot()/setInfo() inline helpers and a swapped first-loop base/cursor give 20-21 or 81 words. Parked at 20.
## classCFILTER_TAG_Filter_main (002A0940): parked at 180
- sz=0xE00 stays REG_EQUIV-constant and is rematerialized at the srl. Tried an init+assign, placing it before or after the D_00747A80 load, int/short/long/ulong types, the register keyword, /32 instead of >>5, and -fno-gcse: all unchanged (201 vs 199 words).
## Turn_dest_Y (002DA468): in progress
- A shared inline turnStep(d, cur, max) helper for both blocks (d -= cur in place) takes it from 58 to 55. The first half matches. The remaining gap is in the clamp: retail evaluates ABS(d) as a two-arm select from d and multiplies into f12.
- No change from: Absf/ABS mixes, if/else forms, an output pointer, or r *= s. Best is nm_work/Turn_dest_Y/h6.c. Permuter running (15 min).
- Turn_dest_Y permuter (15 min, from h6): the base score of 1190 reached 1150 only by inserting an empty do{}while(0), which is junk. PARKED at 55 (best h6.c). Perm note: the sn assembler needs an `include` symlink in the scratch directory.
## LightData_Load (002D6A60): parked at 165
- Conflicting signals:
  - With -fno-gcse (as in the header), d+off is recomputed at each use, like retail, but loop.c strength-reduces the inner j*0x70.
  - Without -fno-gcse, the inner loop takes retail's shape (a mult each iteration, i+1 early, s+0x70/s+0x60/&d->p[i] hoisted before the block-copy arms), but d+off is CSE'd into an s-reg. That gives 197 words vs 199, but 186+ diffs.
- No change from: base=SearchData();s=base (swap), s+=0x70;p[i]=s;tag@0x104;s+=0x108 (identical code), or short/ushort/uint/schar/long types for j.
- A clean for-loop rewrite gives 177-187 words. Scratch: nm_work/LightData_Load/.
- 2026-10-19 04:25 queue check: no new NM files, no new header checkpoint (last 111-120), 8 handoffs still pending in nm_solved, PERM=0. Waiting 20 min.
- 2026-10-19 04:46 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 05:06 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 05:26 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 05:46 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 06:07 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 06:27 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 06:47 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 07:07 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
- 2026-10-19 07:28 queue check: unchanged (no new NM files or checkpoint, 8 handoffs pending, PERM=0). Waiting 20 min.
## func_00319970: 167 -> 12 (in progress)
- Fixes (nm_work/func_00319970/n2.c):
  - isScroll returns int, and the caller tests `(unsigned char)isScroll(self)` (retail andi on both paths).
  - `g = D_007474A0` local for the 0x574 load and the frame counter.
  - Block-local `float s = SPDx(self)` in the wrap branches.
  - Block-local `float t = SPDx(self) * sp` in the cos branches.
  - Separate block locals i2/n2/m2 in the else loop.
  - The sn assembler (`"as": "sn"`) is needed for the mtc1/cvt nops.
- Remaining: retail keeps g in s0 and copies it to s5 before the loop, with 3600 hoisted after f24. Ours keeps g in s5 throughout. A second pointer (w=g at several spots, inline wave() helper, block h) gets copy-propagated away.
- Permuter running.
- func_00319970 permuter (15 min, from n2): 285 -> 270 only via `new_var = 3600` (plus an `m - -0x390` junk edit). By hand, a named `mod = 3600` local is worse (15). PARKED at 12 with --as=sn. Best: nm_work/func_00319970/n2.c, a much closer NM body than the current src (12 vs 167 diffs); worth swapping in as the NM source with `"as": "sn"`.
## func_001846D8: 119 -> 18 (in progress)
- Fixes (nm_work/func_001846D8/q0.c, n1p.c):
  - `d = PART0->0x4C` local.
  - `g = D_007474A0` local for the first loop.
  - Clamp: `mx = D_00422F70; if (x548 <= mx) 54A = x548; else 54A = mx;` then `61C = 62A = D_00422F70` chained.
  - Inline `subHit(short *h, unsigned i, short d)` helper containing the `if (i < 7)` check. This avoids the strength-reduced 8th s-reg (7 s-regs, like retail).
  - `for (i = 1, parts = self+0x600; ...)`.
- Remaining:
  - The second D_00422F70 load is lh in retail, lhu in ours.
  - lwu vs lw for parts[i]->0x60 (`& 1L` doesn't help).
  - The hit block load is scheduled before the compare.
  - Level test register swap and parts+i*4 operand order.
- Permuter running.
- func_001846D8 permuter (15 min, from q0): 935 -> 640 by moving `f = 3.0f` above subHit. By hand that fixes the level-test registers but hoists the 3.0f load (20 diffs). Ternary, if/else, and && forms give 208 words.
- PARKED at 18. Best: nm_work/func_001846D8/n1p.c (18) and q0.c (19, retail's lh-in-delay-slot form). Either is far closer than the current src NM body (119); worth swapping in as the NM source.
## Status 2026-10-19 ~08:30: main agent active again; all 8 pending handoffs registered (0015AF30, 001F20F8, 001F4CA8, 00276F18, 003315D8, 00337400, 0034A0F0, 0034F4C0).
## func_002B1890 (2 diffs): the x1 = x0+21 / wm = w-42 schedule order is unchanged by reordering, `21.0f + x0`, `w - 21.0f*2`, or moving the pair after call 0 (`w + -42.0f` gives 212 words). Permuter running (15 min).
- func_002B1890 SOLVED (handed off, no meta; the header has "as": "sn"). The permuter hit score 0 in 24 iterations: move `xe = x0 + w;` from before the x1/wm pair to just after the first func_002B2058 call. MATCH (213 insns, 31 relocs). Clean statement move, no junk.
## func_003B4D98: skipped. Retail's constant 1 in s5 is used only by the switch decision tree's cmd==1 compare; reproducing it needs a variable compare (if-chain, which the main agent found worse) or a named-constant local. Not attempted further.
## cModel_setupModel (00149738): parked at 82
- Same frame (0xD0) and 9 s-regs as retail, but retail also spills arg (sp+0x24) and d (sp+0x20, never reloaded). Global alloc treats d as live across the func_0014C328/BFE0 calls.
- No change from: an inline isMulti(&d) helper (the ADDRESSOF is optimized away) or `multi = d->num >= 2` (sltiu/xori). Diffs are mostly a slot shift.
## func_0037B918 / func_001F2D60: skipped
- 0037B918: which %hi gets hoisted into fp across a dozen string symbols under -fno-gcse. Low odds.
- 001F2D60: retail reads uninitialized a2/a3 (a phantom by-value parameter), so it's not reproducible in clean C.
- 08:45 queue check: PERM=0; func_002B1890 handoff pending. Waiting 20 min.

## 2026-10-20 21:10 new session (rules: cursor_agent_rules.md)
- func_002B1890: the handoff was rejected at 08:34 (re-verify built it without the sn assembler, 211 vs 213 words; the NM header no longer carries flag notes). Resubmitted with meta.json {"compiler":"sn-2.95.3-136","as":"sn"} and typed `extern cMessDrawFont D_005E7510;` + `font->sizeW/sizeH`. MATCH.
  - Note for main: D_005E7510 is declared as char[] in 002b1c80.c and as int in 001d0fd8.c, 002aa6e0.c, 002ab9a8.c and id/cIDBase.c. It is a cMessDrawFont, so these should be unified.
  - The `long t = flags; ((unsigned long)t >> 3) & 1` idiom is required (retail lw;dsrl;andi). Inline without the temp gives 1 diff (sra). The same idiom is in 9 matched files (e.g. 002b1c80.c).
  - The `font`/`spr` pointer-to-global locals are needed too; without them it is 214 words.
- func_00337400 (earlier handoff with `int one; int two;`, now banned): no longer in src/ (reverted to asm upstream). Nothing to do. Don't retry with named-constant locals.
- Conflict noted: cursor_agent_rules.md tells the closer to register matches and build with compile.py, but my standing boundaries forbid compile.py, sa_register and src/ edits. Following the boundaries and handing off via nm_solved.
- func_0034AC60 (cygnus dr, src/cod/0034ac60.c): GAVE UP (~30 min), 10 diffs. Retail forms cb (s1+0x365C) between the %lo halves and stores hn->cb and fn[4] before the adxt->id load; ours loads id first.
  - Tried: real callee prototypes (callbacks take one int per 00322a38.c; sfadxt_CreateEx returns void*), plain stores instead of the inline setter (same 10, so the setter isn't needed), placement of cb/hn->cb/rec stores (24 variants), reading id via rec->adxt or hn->cb, and id/fn field types (int, void*, unsigned, fn-pointer) x 6 store orders x 4 pre-orders. Floor 10.
  - Permuter 15 min (random mode): best 155 vs 165 only via a fake `volatile short` return on func_00329D38 (rejected).
  - Header note for main: the handle is SfdHn (mwsfd.h), which only names 0x2004; the draft's AdxOpenHn adds rec 0x2004, cb 0x2114, recbuf 0x35A8, info 0x35B0, cbbuf 0x365C.
- _initSeq (ee-2.9, src/cod/003a0018.c): GAVE UP at 2 diffs (from 12). Writing the uncached-branch frame stores in natural order (fr[0]..fr[8]) fixes 10 diffs; nm_work/_initSeq/m0_o2.c is a clean improvement the main agent could take.
  - Left: retail `mult s0,s5,s6; mult s0,s4,s0` (ht*384, then w*that). fold reassociates every spelling to (w*384)*ht: parenthesized, unsigned 0x180U, casts, size from h->w/h->h, staged size, swapped decls.
  - Permuter (manual PERM_RANDOMIZE on the size block) hit 0 only via `new_var = 0x180` (constant in a local, banned). Rejected.
- func_00150C10 (sn, src/cod/00150c10.c): SOLVED -> progress/nm_solved/func_00150C10/ (solved.c + meta.json compiler sn-2.95.3-136). MATCH 88 insns, 9 relocs (ee or sn as).
  - 17 -> 0 in three steps: read the 0x14 header pointer into a local before the ch store (retail loads it into a3 early, pushing r to t0); keep the short lookup result in its own `s` with `if (s != -1) r = s; else {...}`; scope a separate entry pointer to each mode block.
  - Real prototypes: func_00150D78 returns short (00150d78.c), func_003090F8(unsigned char, char *, char *, unsigned int) (003090f8.c), func_00309D88 reads 5 args (asm).
  - The draft's glyph names were wrong: the cursor is {count, ch, addr, spu} over the D_00747BA0 0xB0 channel table.
  - Note for main: D_00747BA0 has 5 different types across the tree (SndRateCh in 003090f8.c, GifPktEnt in 0030a200.c, unsigned char[] in 00150d78.c, BankCh here). One shared header type is needed.
- func_003B7400 (ee, src/cod/003b7400.c): SKIP (blocked). Retail does `sw $gp,0x2C(a)` (the alarm records the caller's gp). Plain C can't read $gp, and the rules ban asm beyond the sync.h/vu0.h intrinsics. Needs a project intrinsic (e.g. GH_GET_GP) from main before it can match.
- cScenario_execUpCutData (sn + as sn): 1 real diff (17 counted from a 1-insn shift). Retail copies the taskExec result into t1 (`daddu t1,v0`, the incoming slot register) and uses t1; ours uses v0. Clone-form index (slot*TASKMGR_WORK_SIZE + (int)works, as in 002c3c10.c), separate local, assignment in condition, early return: all 17. Permuter running.
- cScenario_execUpCutData: GAVE UP (~20 min). The permuter hit 0 only with `do { } while (0);` after the taskExec call (banned fence). So retail has a block or loop-note boundary there. Static inline helpers (mark-task, exec+mark) and an argument-position call don't reproduce it. The clean draft (clone index form) is nm_work/cScenario_execUpCutData/clone_param.c.
- func_00359848 (cygnus dr): 20 -> 12 by loading rate before ch in the video/ADX paths (nm_work/func_00359848/x_v_chfirst_rateload.c). Left: reorg threads `blez num` to the ch-load block, filling its slot with the `rate = v` copy; retail keeps `lw scale` in the slot and branches to the shared `b; rate = v` block. Permuter next.
- func_002C9950 (sn, src/cod/002c9950.c): SOLVED -> progress/nm_solved/func_002C9950/ (solved.c + meta.json compiler sn-2.95.3-136). MATCH 71 insns (ee or sn as).
  - 24 -> 9: read t = order[i] inside the swap instead of before the compare (both passes).
  - 9 -> 0: write the first pass as `items[order[i]].key > items[order[i+1]].key`.
  - Declaration order and t's type made no difference. The trailing order array is written [0] (sn 2.95 rejects []; [1] gives the same code).
- func_00359848 (cygnus dr, src/cod/00359848.c): SOLVED -> progress/nm_solved/func_00359848/ (solved.c + meta.json cygnus-2.96, c_flags_drop -freorder-blocks). MATCH 89 insns, 6 relocs.
  - 20 -> 12: load rate before ch in the video/ADX paths.
  - 12 -> 4: cache `int scale = aud->scale` before the num test (a hint from a permuter new_var result, rewritten cleanly).
  - 4 -> 1: store order rate, ch, done.
  - 1 -> 0: `if (num > 0 && scale > 0) rate = f(); else rate = aud->rate;` (the v temp lets jump2 cross-jump the rate copy onto the /2018 path's identical copy).
  - The permuter scores the 1-diff base as 0 (blind to branch targets). Callee prototypes copied from their definitions (003272c0.c, 0034d6f0.c, 0034d8.c), casts at the calls.
- func_00383170 (sn, src/cod/00383170.c): SOLVED -> progress/nm_solved/func_00383170/ (solved.c + meta.json sn-2.95.3-136). MATCH 68 insns, 5 relocs (ee or sn as).
  - 28 -> 0: the flags at c+0xBC are CtlList.on[] (list+0x18, as func_00383280's scan shows), read as `l->on[i + 1]` in a plain `for (i++)` loop. The `n = i + 1; i = n` loop and the hoisted flags pointer were the mismatch.
  - Third param is `unsigned char enable` (retail andi on entry; callers pass 0/1). Callee prototypes from their definitions (002b62f8.c, 00302918.c).
- func_00137BB8 (sn): GAVE UP (~25 min), 28 diffs, all an s1..s6 permutation (retail: found s1, list s2, best s3, pt s4, off s5, i s6). Insensitive to declaration order (72 combos), best type, hit-variable/nested/while forms, allowed flags.
  - Permuter 15 min: best 35 only via a dead `list->cur = 0` after `continue` and duplicated found/best branches (banned). Retail seems to weight found/best/list refs higher; no natural form found.
  - Note: `timeout 900` did not stop this run (it was still going at ~25 min). The kill loop must anchor its patterns ("/src/.venv/bin/python /src/tools/decomp-permuter"*) or it kills its own shell first.
- func_003090F8 (sn): 29 diffs. Switch forms (if/else, default, case order, int cast) no better. Retail uses plain beq with 4/5 in a1/v1 and bumps i/ch before the record stores. Parked for a permuter slot.
- func_0028EBF0 (sn, as sn): 32 -> 18 with the header idiom `cGameObj_idInRange((cGameObj *)self, 0x2A0, 0x300) & 0xFF` (self is a cGameObj subclass: pos 0xF0, actorId 0x2FE, posA 0x490). Left: our scheduler hoists the unk630 = 1.0f and unk574 = 2 stores; retail keeps source order. Store position sweep no better. Permuter running.
- func_0028EBF0 follow-up: these did not move the two hoisted stores (all 18): flags -fno-schedule-insns/-insns2/-fno-gcse/-fno-strict-aliasing (worse or same), C++ (same 19), raw `*(T *)((char *)self + off)` stores for any subset, the store groups moved into static inline helpers. The permuter's best (225 from 480) only adds a duplicate unk644 store and a float->unsigned cast (steering).
- func_003066D0 (sn, as sn): 35 diffs. Retail builds the loop sentinel as `li 0xFFFFFFFF` (lui/ori, the unsigned 0xFFFFFFFFU form seen in matched SetEffect calls) hoisted into s5, separate from the `state != -1` constant, and puts `e++` in the continue delay slots before the bottom `n--; bne n,s5`.
  - int n: the -1 is hoisted but shared with the state compare (35, every while/for/pre/post form). unsigned n: right constant, never hoisted (82). long/unsigned long: 84. Up-counting index forms: 31-84, wrong loop shape (slt/blez). Parked for a permuter slot.
- func_0033D3D0 (cygnus dr): 40 diffs, register numbering only (retail: pos t0, blk t1, nin t2, nend t3, room t4, nout t5; in->a1). Declaration/load-order search (300 random orders) best 39. Direct field reads without locals: 56-61; dropping the `in` local: 61. Permuter next.
- func_0033D3D0 update: 40 -> 33 by loading `room = in->room` after the nout line (a clean permuter reorder; retail reads 0x24 late). `in` now lands in a1 as in retail. Left: register renaming (retail pos t0, blk t1, nin t2, nend t3, room t4, nout t5) plus `pos += nend * blk` sitting in the slot. A second declaration-order search (300) stayed at 33. Draft nm_work/func_0033D3D0/r1.c; permuter restarted from it.
- func_0033EBD0 (cygnus dr, ADX loop-info decode): 42 -> 18.
  - The draft read leOfst at leSmpl+8 (an extra `pos += 4`); retail reads leSmpl+4, i.e. lptype, lsSmpl, lsOfst, leSmpl, leOfst back to back. That is a real bug in the src draft.
  - Reading each 32-bit field straight from memory (`*lsSmpl = SWAP32(*(Sint32 *)(ibuf + pos));`) instead of through the shared v: 41 -> 18. Mixed v/direct forms (16 combos) are worse.
  - Left: retail issues the lptype lhu early and its lbu only after the lsSmpl store (a char load blocked by an int store), storing lptype between lsSmpl and lsOfst. Operand order, casts, SWAP16 vs SWAP16B and moved pos math don't reproduce it. Draft nm_work/func_0033EBD0/w_iArD.c; permuter candidate.
- func_0032D430 (cygnus dr): SKIP for now, 44 diffs. Retail reloads each constant into v0 right before its store (0x2000, 0x40, 1, 1), which looks like reload rematerialising REG_EQUIV constants; ours keeps them in separate registers. Store reorders (f2 before f1A0, matching retail's char-store order) don't help (46). cyg with reorder, -fno-gcse, sn and ee are all far worse. The draft also needs cleanup (the `*(int *)((char *)p - 0x8C)` handle-array store, an unused I() macro).
- func_0033D3D0 (cygnus dr, src/cod/0033d3d0.c): SOLVED -> progress/nm_solved/func_0033D3D0/ (solved.c + meta.json cygnus-2.96, c_flags_drop -freorder-blocks). MATCH 65 insns, 3 relocs.
  - 40 -> 33: load `room` after the nout line (permuter reorder).
  - 33 -> 31: the `wpos < room` flag gets its own variable (`full`) instead of overwriting wpos; the min chain clamps nin directly (no separate n).
  - 31 -> 5: don't update pos (it was only used in the end test). That moves pos from last to first in allocation (t0).
  - 5 -> 0: `len = nend * blk;` before the if and `nend += pos + len - tail < end;` inside it (the add then lands in the beqz delay slot as in retail).
  - Callee prototypes from their definitions: ADXB_EvokeExpandSte (0033d3.c), int func_0033D378(int, int) (002c54e8.c), int func_0033D2D0(int *, int) (0033d2d0.c), with casts at the calls.
- func_0035AD20 (cygnus dr): 46 -> 27 (nm_work/func_0035AD20/v_r2.c): compute t after the ret test (fixes the prologue order) and keep the get() result in its own r2 with `ret = r2` at the end.
  - Left: retail returns through v0 directly, loads cnt before the -5 test, reloads t->last after it, and doesn't hoist the t->total load above the last/flag stores. Inline helpers (delta, whole update), nested ifs, if/else delta and flags -fno-gcse/-fno-strict-aliasing/-fno-cse-follow-jumps don't reproduce it. Permuter candidate.
- func_00383F50 (sn): 56 diffs. The real layout is func_00383170's ListCtl: s = o+0x370 is the ListCtl (cur at 4, vals at 8), c = &s->list (0xA4), c2 = a second CtlList at 0xCC (draft t1.c). The last loop should be `for (i = 0; i < c->count; i++) f(c->obj, i, s->vals[i + 1])` like 00383170.
  - Left: s/c/&c->on[0] rotate across s0/s1/s2 (retail s, c, on). Declaration/assignment order (36 combos), explicit on pointers (117) and the j = i + 1 loop (68) don't fix it. Permuter candidate; the sibling func_00382660 is NM with the same layout.
- func_00342D00 (mwsfcre size calc): the header says cygnus and cygnus dr scores 36 (the scanner's sn_as 57 was misleading). 36 -> 35 by computing mb after the size0 math.
  - Left: retail keeps a copy of mb before `<< 10` and puts the 0x400 product before the fmt branch. Ternary, if/else, a shared v factor, shift/decimal constants, unsigned mb/n/v and inlined mb don't reproduce it. Permuter candidate.
- MoveEsp (sn): SKIP for now, 61 diffs. Retail hoists the 0x4000000 mask (s7) and the D_0071B840 base (fp) out of the loop but rebuilds D_0071B8C0 each pass, and computes ok as `andi 0x8000; sltiu`. Ours hoists both bitmap bases and computes ok via sra/xori. The ok spellings (&& form 85, ! form 61, if/else 62) don't change the hoisting. Same loop.c invariant-choice issue as the NM MoveEmitter; needs a structural idea, not order tweaks.
- func_0012D1A8 (sn): 62 -> 17 (nm_work/func_0012D1A8/e1.c).
  - 62 -> 20: the guarded copies are the header's cVec_copy3(&p->min, ...) / cVec_copy3(&p->max, &p->min) with min/max addressed off p (no mn/mx locals).
  - 20 -> 17: keep `c0 = p->c; sq = D_00462F00; c = c0;` in that order (retail builds c0 in s5 first, then copies it to the loop pointer).
  - Left: retail reads the first min-copy word as 0xC0(s1) and runs the bbox loop on one giv p + i*16 with 0xC0/0xC4/0xC8 offsets and the counter in v1. Ours uses &p->c[1] with offsets 0 and the counter in s4. Indexing p->c[i] directly makes one giv per component (112-127); `p->c + i` is the same as e1 (17); `&c0[i]` 28; passing p->c to the copy 20.
  - Note: host load was ~55 from 22:39 on (not my permuter; PERM=0 confirmed), so compiles took 1-2 min each and this got less search than usual.
- func_0015ADA0 (quaternion rotate, ee-2.9-991111; sn-2.95.3-136 scores the same): 62 -> 2 (nm_work/func_0015ADA0/q_yzxw.c). Copying q into qq in the order y, z, x, w fixes the register allocation (all 24 orders tried; only yzxw gets below 26).
  - Left: retail stores qq.x (f9 to 0x40) before qq.y (f10 to 0x44); ours stores y first. None of these change it: the order of the conjugate assignments (72 combos), building the conjugate from q (24 qq orders), interleaving those reads with the qq copy (840 combos, best 49), struct copy `qq = *q` (95, becomes ldl/sdl), by-value inline helpers (96), or moving qq before vq (33).
  - Permuter (perm/func_0015ADA0) hit 0 in about 2 minutes, but only by adding a duplicate `qq.y = q->y;` after qq.x, a dead store, so REJECTED. It does show what retail wants: y loaded first, y stored after x. Parked; I haven't found a clean source shape that does that.
  - Host load was ~50-60 again (not mine), so the 840-combo search took 45 minutes.
- __deregister_frame_info (ee-2.9-991111): SOLVED, handed off to nm_solved/__deregister_frame_info (30 insns, 5 relocs; also verified without -D NON_MATCHING). This is libgcc frame.c; the GCC source verbatim (thread-mutex no-ops dropped) matches: walk `struct object **ob`, test and read through `*ob` each pass, keep `r = *ob` for the free/return. The draft's `ob = *p` local was what produced the bnel loop and the prologue-schedule diffs. Callees: UpdateGlobalPtrWithParam_3A7CC0 = free(void *), func_003A7B48 = abort (noreturn). sn/cygnus come out 28-29 words, so ee is the right compiler.
- func_0031AFE0 (pad state update): the compiler is sn-2.95.3-136, not the cygnus in the draft header (cygnus is 4-6 words off). 32 -> 12 (nm_work/func_0031AFE0/d_int.c); a 0-diff probe exists but isn't handed off (see below).
  - The Mask64 union isn't needed: plain `unsigned long cur/f38/f40` scores the same (sn doesn't strict-alias here).
  - 32 -> 12: D_00747A78 typed as the SysFlagWords struct (int f78/f7C/f80, the type matched 001496c0.c already uses). As a scalar int global, GCC 2.95's fixed-scalar-vs-varying-struct alias rule let its load hoist above the st->dirTrg store; as an aggregate it stays after the stores, as in retail.
  - The remaining 12 diffs are all in the prologue and have the same cause: retail loads D_00747A0C after the six st stores, but a scalar int global gets hoisted above them. Probe f_probe.c (D_00747A0C as a one-field struct) MATCHES (191 insns, 17 relocs). Not handed off: no file gives D_00747A0C an aggregate type (they all use int, one uses signed char), so the wrapper is a type change made only to reorder loads.
  - Also blocking: the `long t` / `long u` temporaries the draft uses for the `(unsigned long)x >> 5` / `>> 4` tests (banned long temporaries). Inlining them gives sra instead of retail's lw + dsrl (e_nolocal.c, 73).
  - Layout note: 0x747A0C = GameWork+0x56C (language), 0x747A34 = +0x594 (debugFlags), 0x747A78 = +0x5D8. Accessing them as D_007474A0 fields shares one %hi in our code (184 diffs), but retail addresses each through its own symbol, so they were separate objects in the original. Retry if main gives D_00747A0C / D_00747A78 aggregate types in a header (header checkpoint).
- cIDBase_transTex (sn_as, 46): PARKED, it would need dead stores. The draft's "outgoing stack args" reading is wrong: func_002C5EA8 reads only incoming 0x140/0x148 (f70[3], f80) and nothing above, and retail sets no t0/t1 pointer. So the callee's real signature has 14 args (draw, tex, color, b89, x, y, w, h, rot, u0, v0, u1, v1, f80), and the two {w, h, 0, 1.0} blocks at sp+0x10/0x20 are caller locals that are written but never read (f14/f15 reuse the w/h registers).
  - Reproducing that needs struct fields written and never read (dead stores). A by-value cVec inline param gives ldl/sdl copies (41); nested inlines 46; a compound literal 41; two initialized cVec locals 66w vs 64. cIDBase_transSprite (002aaff0.c) has the same pattern. Not pursued further.
  - func_0031AFE0 follow-up: D_00747A78 as a bitfield struct doesn't remove the long temporaries. 64-bit fields load with ld plus dsll32/dsra32 (143); 32-bit fields merge the two tests into one combined mask and use srl (94).
- func_0033EBD0 permuter (perm/func_0033EBD0, cygnus dr, w_iArD base): 15 min, no improvement (stuck at base 425; host load 55-85, so ~1k iterations). Rotated out.
- func_0012D1A8 permuter (perm/func_0012D1A8, sn, e1 base): 15 min, no improvement (base 200; host load ~85). Rotated out.
- func_0036EB58 (MPV bitstream re-sync): cygnus-2.96 with reorder dropped is the right setup. It's 71 words vs retail 72 with 62 diffs; cygnus with reorder is 73w, sn_as 71w, plain sn 65 diffs but the wrong layout.
  - Left: ours spends an extra register (bs in t4 and buf in t5; retail uses t3 and t4). Retail issues all eight byte loads (lb, lbu x3, lb, lbu x3, each with its own addiu) before any shift/or, keeps the last p++ and the p += 4 as two addius, and computes the shifted word before testing shift (the store sits in the branch delay slot).
  - PARKED without a search: host load was 55-85 (not mine), so each compile took 45-90 s. Ideas to try when load drops: read the bytes into b0..b7 locals before combining, the bits/word math order, an unsigned hi.
  - func_0036EB58 follow-up once load dropped to ~30: 62 -> 55 -> 53.
    - b8.c (55): read the bytes into b0..b7 first (signed char b0/b4, unsigned char the rest), then combine. This fixes the bs/buf registers (t3/t4) and the load order.
    - w01.c (53): compute `word = (hi << shift) | (lo >> (32 - shift))` before the if and store `bs->code = 0; bs->ext = 0;` in that order (that gives retail's 0x30C-then-0x308 tail). But cygnus now if-converts the two word stores into one movz store, while retail keeps a beqz/b pair with an unreachable nop after the b's delay slot.
    - Computing ret before the if (b8r, 56) and the store order alone don't help.
    - Left: the uncombined `addiu 1; addiu 4` and the branchy word store. Parked at 53 after ~30 min.
- New drafts since the 21:15 scan (21 files, scored with tools/nmscan_new.py into nmscan_new.tsv): 001346C8 6, 00136458 7, 00192588 8, 001334A8 9, 002DAF68 10, 001321D8 11, 00276DC8 11, 00136030 13, 001EFED0 23, 00133BC8 41, the rest 113+ or a size mismatch.
- func_001346C8 (sn as, 6): SKIP, toolchain-blocked. Retail's short-loop pad nop sits in a loop that also holds the beqz exit branch, so the loop is multi-block. ee-as doesn't pad it, and --call-loop-pad only handles single-block loops with calls (tried: still 6). No C change applies.
- func_00136458 (sn): 5 -> 6 diffs, but structurally closer (nm_work/func_00136458/z1.c). Each "zero, then subtract" triple is one VU0_ZERO_VSUB_XYZ_MEM statement: retail computes &tri[1] before the zeroing sqc2, which only an operand of a single asm does. With `e = &f.e` before the first one, what's left is register choice: retail holds &tri[1] in v0 before s1 = &f.e, keeps &tri[2] in v1 and &f.d2 in v0; ours swaps both pairs.
  - Permuter 15 min: 50 -> 30 only by wrapping the tail in do { } while (0) (banned fence), REJECTED. Parked.
- func_00136030 (sn, 13 -> 5, nm_work/func_00136030/c4.c): the last test is `if (!(__builtin_fabsf(d) < 1e-6f)) return 0;` (retail's c.lt.s |d|, eps; the draft's `>=` gives c.le.s).
  - Left: retail branches on true with v0 = 1 in the delay slot (scc-style) where ours does bc1f with v0 = 0, and retail's first bc1t keeps a nop where ours makes bc1tl + abs.s. `return fabsf(d) < eps`, goto, if/else and `!(>=)` forms all reshape the earlier flow (22). Permuter next.
- func_00192588 (sn, 7): the draft's `long flags` temporary is what gives retail's lwu + dsra; inlining `(unsigned long)take->flags >> n` narrows to lw + srl (10 diffs; it does fix the second load's v0). Else-arm store order (24 combos), a shared step/stepArg tail and then-arm orders don't fix the random arm's sb order. Parked.
  - QUESTION for main, also relevant to 0031AFE0: matched TUs (0018c370, 00296530, 00174a78...) use `long` flag locals to get 64-bit dsra/dsrl tests, but the rules list `long` temporaries as banned. When the 64-bit shift itself is visible in retail, is a long local the real type (u_long-style) or steering? Until told otherwise I'm treating it as banned.
- func_001334A8 (sn, fdiv hazard rule): SOLVED, handed off to nm_solved/func_001334A8 (113 insns, 12 relocs; verified without -D NON_MATCHING). The draft put `n = 3;` / `n = 4;` between the corner copies; at the end of each arm (natural order) the allocator gives color s4 and the hoisted %hi(D_005CAFF0) s5, as in retail. n first in each arm stays at 6. Callees checked against retail: func_0030A538 is a 16-byte lq/sq copy (dst, src), Gp_draw_poly3 reads a0..t0 and sets v0, Gp_draw_poly4 as in 001de7c8. meta: compiler + fp_hazard_rules fdiv.
- func_002DAF68 (sn -ffast-math, sqrt rule, 10): the only difference is where the radii add.s goes. Retail keeps it after the nop/nop/sqrt.s template; ours schedules it into the first load's delay, ahead of the y load. No header sqrt asm exists that would act as a scheduling barrier, and operand-order spellings don't move it. Parked (looks like a vendor-cc1 scheduling difference around the sqrt template).
- func_001321D8 (sn, 10): SKIP for now. The draft carries steering a handoff couldn't keep (an `unsigned int row[2]` placeholder array for the spill slots, and a `top = &hi` alias written as `top->w`). The remaining diffs are spill-slot order (&result vs y + 1 at 0x38/0x40), `list + count` operand order and the debug-draw load order. It needs a cleanup pass first.
- func_00136030 (sn, 5): permuter ran ~20 min from c4.c (base 660). Its 400 result was junk (`d = 1; return d;`) and its 360 result added a do{}while(0) fence, a `new_var` alias and a junk `if (!d)`. Both rejected. PARKED at 5.
- func_00276DC8 (sn, 10 -> 0): SOLVED, handed off (nm_solved/func_00276DC8, meta compiler sn-2.95.3-136). The in-place apply goes through a static inline `cVec_applyMatrix(v, m)` that calls `sceVu0ApplyMatrix(v, m, v)`. The inline parameter pseudo lands in a0 and the copy recomputes &f.v from sp, as retail does. A direct call keeps &f.v in s0 across the call. MATCH 50 insns, 4 relocs.
  - LESSON: when retail passes a fresh sp+N to a later use instead of keeping &local in a saved register, try routing the earlier use through an inline helper.
- func_00133BC8 (sn, 39): PARKED. Retail keeps self in s0, dst/src in s1/s2 (src incremented first) and passes a fresh sp+0x40 to func_0030A548 while the parent-copy sqc2s use s4. Tried: indexed loop / split increments / swapped init (39-41); matrix copy as an inline helper (47; the call then shares the copy's register); copy + call as one inline with a stack temporary (66). Draft clean base is nm_work/func_00133BC8/base.c.
- func_001EFED0 (sn as=sn, 17): register swap only (retail &self->unit in s2, pos in s3, v1/v0 temps). Early return and `!= 0` drop didn't help; callee prototypes match their definitions. Permuter queued.
- func_00283AA8 (sn, size mismatch -> 0): SOLVED, handed off (nm_solved/func_00283AA8: solved.c, meta compiler sn-2.95.3-136, header_changes.md). MATCH 80 insns, 5 relocs.
  - The fix has three parts: f.v accessed as `&f, 0x40` in the VU0 macros; both in-place applies through `cVec_applyMatrix`; and the holder->pos subtract as a single asm. That last one is the new `VU0_VSUB_XYZ_IP` in vu0.h (header_changes.md adds it right after its vadd twin, VU0_VADD_XYZ_IP). Verified with the macro defined in a check copy, since mc has no -I.
  - The helper's parameters are now (cVec *v, void *m); func_00276DC8/solved.c was updated to match and re-verified.
  - QUESTION for main: `cVec_applyMatrix` (static inline, `sceVu0ApplyMatrix(v, m, v)`) is now defined locally in two handoffs (00276DC8, 00283AA8). The rule says it belongs in a header once, but there's no shared sceVu0ApplyMatrix prototype: about 10 different declarations exist, some with cVec * / float * params, so adding one to cOmBase.h or vu0.h would break units that include it. Please move it at a header checkpoint, once sceVu0ApplyMatrix has one declaration.
- func_001EFED0 (sn as=sn, 17): PARKED. The permuter's best (40 from 115) only adds `self->next++; self->next--;` (junk, rejected). A `cHitSet_cur(self)` getter inline (17) and a quadword-copy inline for the pos -> at copy (56) didn't help. Clean draft: nm_work/func_001EFED0/base.c; permuter case: nm_work/perm/func_001EFED0.
- STOPPED on maintainer request (2026-10-21 02:05). Permuter killed, PERM=0 confirmed. Every solved function is in nm_solved/ (func_001334A8, func_00276DC8, func_00283AA8). Nothing solved is left un-handed-off.
