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

## 2026-10-21 10:00 new session (drafts now in drafts/cod/)
- Scanner: tools/draftscan.py scores drafts/cod/ (skips CRI range and anything already in this log). 61 unlogged drafts scored into nm_work/draftscan.tsv: 0010CD38 3, 00154DA0 54, 001B7568 69, 0030CF10 72, 001FC810 85, 002D4340 97, the rest 113+ or a size mismatch.
- func_0010CD38 (sn): SOLVED -> nm_solved/func_0010CD38 (solved.c, meta compiler sn-2.95.3-136, header_changes.md). MATCH 234 insns, 23 relocs.
  - The 3 diffs were the int return on func_002A8578. Its definition (00134880.c) only forwards setMotionInfo's 0/1, so `void` builds the same (verified: MATCH func_002A8578 35 insns), no caller reads the result, and every matched caller already declares it void. header_changes.md makes the definition void.
  - Other callee prototypes now from their definitions: cSnd_SeStop(cSnd *, int), Obj0000_Clear_Fields_640_648_124E58(char *), func_001268F0(int *), cObjBase_addNullSpeed[_Rotation](cObjBase *, float); D_00569B70 from cCoreSave.h. func_00124540/func_00123938/moveMotion/SetEffect return 0/1 in retail (int kept).
  - header_changes.md adds cEm00 fields `unk61F` (0x61F) and `stepScale` (0x15C0) by splitting padding.
  - 0x640 kept as `*(int *)((char *)self + 0x640)` like the matched sibling 0010d0e0.c: cEm00.h/cEmWrap.h type it as `unsigned short entryNo`, but here it is the held-link pointer that Obj0000_Clear_Fields_640_648_124E58 clears. Note for main: 0x640 needs a decision (union or a second view).
  - Note for main: D_005FEE00 is declared five ways across the tree (char[] 157, unsigned char[] 64, int 23, int[] 13, cSnd 7). It's the cSnd manager; it needs one header declaration. func_002A8578 likewise has 4+ local prototypes with the float in different positions.
- func_00374210 (sn): SOLVED -> nm_solved/func_00374210 (solved.c, meta compiler sn-2.95.3-136). MATCH 65 insns, 5 relocs. ~15 min.
  - Direct `return 1` / `return 0` instead of the `ret` accumulator (fixes the tail and the v0 constants).
  - Size math in separate statements: `bps = rate / 1000 * 25000; hdr = s->nch * 0x40C0 + 0x24; sz = s->nch * bps / 44 * (sec + 1);` then the 0x800 rounding and `(sz + hdr) * n + 0x40`. One expression let fold reassociate both products; with `bps` its own statement the saved-but-unused s0 appears as in retail.
  - Callees: func_0031C928(void *, void *) and func_0032D340 int(int x4) from their definitions; D_00754210 as the heapArena.h HeapArena. func_0031C8E0's C definition (001b5160.c) is a `int (void)` tail forwarder, so I used the 3-argument `void *(int size, int align, void *heap)` that matched 00373ba8.c declares. Note for main: that definition should take (size, align, heap).
- Tools: tools/draftscan.py (scores drafts/cod/), tools/permsetup.py (permuter case from a C file + retail listing, preprocessed, section attribute stripped), tools/run_perm.sh (run / --kill inside godhand-nix).
- func_001B7568 (sn; the draft named no compiler): SOLVED -> nm_solved/func_001B7568 (solved.c, meta compiler sn-2.95.3-136). MATCH 69 insns, 0 relocs. ~5 min.
  - The draft's local `inrange()` is the header's `cGameObj_idInRange(obj, 0x100, 0x1FF)`, tested as `== 1` (retail compares the long flag with 1; `& 0xFF` gives andi/beq, 2 diffs).
  - Types from headers: `cOmBase *self` (hitFlags 0x5B4, COMBASE_HIT_STRONG/PLAYER/KNOCKBACK) and `cDamageTake *hit` (attacker 0x34, kind 0x46, power 0x4C). This is the hit classifier cOmBase_checkDamage (001b7380.c) calls; note for main: its prototype there is (void *, void *) and belongs in cOmBase.h.
- func_0030CF10 (sn): PARKED (~15 min), 72 diffs, scheduling only. Retail hoists the next entry's D_003C1180/D_003C118C lhu loads above the previous entry's tex0 sd and the `e += 0xB0` bump; ours keeps them after (alias analysis can't disambiguate the bumped pointer). Tried: a TexEnt struct (0xB0: on/alpha/unk02/w/h/unk08/tex0/unk20) with three store orders (72-81), fixed-address `&D_00752780[i]` (156 words), the macro as a static inline (164-182 words; constants don't fold, as the draft says). Drafts: nm_work/func_0030CF10/A_ptr.c.
- func_0014B810 (sn): PARKED (~10 min), 56 vs 66 words. Retail keeps start in t1 and copies it to a3 in each of the six call blocks (each ending `b epilogue; ld ra`); ours keeps start in a3 and cross-jumps the blocks. Tried an inline queuePacket(kind, id, start, end) helper, `end = start; end += 0xA0` (the matched sibling 0014b9a0.c uses a running `w`), ee/cygnus/cygnus dr/sn dr/-fno-gcse (44-64 words).
- func_00154DA0 (sn, as sn): 56 -> 55, size 64 vs 61. The packet table is `PktQw *pkt[2][16]` at MdlObj+0x300 (gives retail's idx*4 + buf*0x40 then + self); texBank at 0x384 and MdlRec.texNo at 0x16 also fit the padding (patched copy in nm_work/func_00154DA0/godhand/mdlPkt.h). Left: retail keeps self in a0 through the call; ours copies it to t1 and uses a0 for 0x11000000. Permuter candidate.
- func_0012A578 (sn): GIVEN UP (~40 min incl. permuter). One word short. Retail moves pl a1 -> a2 and keeps &f.d in a1 between the first two VU0 asm blocks. `cVec_copy3(&f.v, &f.d)` gets the copy loads right. The permuter (from dafterzero_vf.c, 10:16-10:28, best 105) only found steering: a duplicated `if (d || out)` branch, `do { } while (0)` fences and new_var aliases. All rejected.
- func_001FE748 (sn): retail is 85 words. Ours is 83 with ee-as and 84 with `--as sn` (the SN assembler supplies retail's alignment nop before the inner loop head). The one missing word: retail rebuilds the outer `i * 0x5C` constant in v0 each pass (it isn't hoisted), while the inner loop's giv constant is hoisted into s7. Ours shares one hoisted s6. Tried 5 outer x 5 inner loop forms (pre-decrement for, n-1 for, `while (i-- != 0)`, `while (i--)`, `>= 0`), continue vs nested if, a per-pass slot pointer, cygnus/ee/drop-reorder and --call-loop-pad (77-86 words). The permuter on pair/pre_pre.c (sn, as sn, base 490) started 10:28.
- func_002E0DE8 (sn): SKIPPED. Retail divides by a long-lived s4 = 8 (a real div with the trap test on a fresh 8), which is what a constant held in a local gives. That form is banned, and the draft already tried int/short/inline-helper divisors.
- func_003BBEC0 (sn): SOLVED -> nm_solved/func_003BBEC0 (solved.c, meta compiler sn-2.95.3-136). MATCH 23 insns, 0 relocs. ~10 min.
  - This is libstdc++'s basic_string<char>::rfind(c, pos), written as the 2.9x template: `if (1 > length) return npos; xpos = length - 1; if (xpos > pos) xpos = pos; for (++xpos; xpos-- > 0;) if (eq(...)) return xpos;`.
  - The dead `sb` of c is traits::eq taking both chars by address (`stdChar_eq(const char *, const char *)` static inline). npos is 0xFFFFFFFFU (retail's lui/ori). Types are from StdString.h (StdString, STDSTRING_REP).
  - The signature (StdString *, char, unsigned int) returning unsigned int fits the caller 003863b8.c, which declares (void *, char, unsigned int).
- func_0013C318 (sn): PARKED (~12 min), the draft is 124 vs 123 words. Retail never threads the else-if into the first test (it re-tests the mask). In parts 1-3 it re-reads part->flags through a second copy of the part pointer, and the 0x8000000 constant is shared by the test and the `or`. Plain mask tests (direct `o->part[i]->`, a local p, an inline per-part helper, a loop) all get threaded (50-101 words), and so do bitfields for hidden/hide0..3 (101). A volatile req probe (not handoff-able) gives 110. Work: nm_work/func_0013C318.
- func_001FE748: PARKED. The permuter (10:28-10:43, base 490) has one useful lead: best 120 with an empty `do { } while (0)` right after the func_001FF110 call. That is banned, but it gives retail's constant handling (the outer 0x5C is rebuilt in v0, the inner one is hoisted to s7) and leaves 6 diffs: s5 = i - 1 is computed after the first call instead of before it. So the real source has an extra loop or block construct in the outer body. Inline helpers for the inner loop, for the whole step (by pointer or by index), and guarded do-while / `while (--i != -1)` outer forms don't reproduce it (83-84 words).
- func_002C21A0 (sn): retail stage arms put cmd->bit in different registers (v1 set, a1 clear; the clear load sits in the bnel delay slot). Ours shares one register, so reorg hoists the common lhu into a plain bne (98 vs 99 words). Trying the 16 set/clear statement orders gives the right size with the set arm as the draft and the clear arm as `m = cmd->bit; w = ...; if (m < 0x40)` (arms/draft_mw.c, 21 diffs), but registers and order are still off. Reusing the global path's n in the clear arm: 53 diffs. The permuter on arms/draft_mw.c (base 1500) started 10:43.
- func_002C21A0: PARKED (~20 min). The permuter (10:36-10:45) best was 785 from 1500. Its clear arm indexes `((unsigned int *)(D_00569B70 + 0x14))[...]` without w, and its set arm has a junk `(0, cmd->bit)` comma. Built with mc it is 98 words / 43 diffs, worse than arms/draft_mw.c (99 words / 21 diffs). Clean versions (no-w clear arm, SET/CLR_FLAG macros on the cast base, an inline `flagCmd_bit` getter, `(int)` cast) give 96-98 words. For a later handoff: D_00569B70 is `cCoreSave` in cCoreSave.h (stage words = data->flags at 0x14 plus unk18), D_003C2F84 is `cScenario *`, and func_002C5028's definition is `void *(int, unsigned short)` (first argument not read; matched caller 002be708.c declares it `(cScenario *, unsigned short)`).
- func_00379910 / func_0037BC90 (sn): SKIPPED (~10 min together). Retail holds the always-3 column as 3 << 16 in a saved register (`lui s2, 3`, or `li 3; sll 16` unfolded) and extracts it with srl 16 for some calls and sra 16 for others. That is a two-short value packed in one register (column in the upper half). The drafts reach it only with per-call casts. A `short`/`unsigned short` local and a `short x` prototype give 124-133 vs 130 words. Needs the real packed type (a 4-byte struct or union of two shorts?).
- func_001FC810: PARKED (~15 min). The right setup is sn with `--as sn`, not cygnus: retail's nops are the SN assembler's loop-head alignment and c.lt.s hazard pads, and retail reloads child.count after the float stores (no type-based aliasing, which cygnus has). Plain `for (i = 0; i < l->count - 1; i++) for (j = i; j < l->count; j++)` gets the reloads right (90 vs 93 words). The remaining 3 words are the draft's note: retail loads count into v0, copies it to v1 (the value the outer test uses after the inner loop) and compares with v0, while ours loads straight into one register. Comma-condition, unsigned cnt, swapped compare and outer-reads-count forms are all 90 words.
- func_00150F68 (sn): SKIPPED. Retail has a divide-by-zero trap on bpr (`beql t7, zero; break 7`) with no div instruction, so the source divided by bpr and never used the quotient. Reproducing it needs a dead expression (banned). Without it the register and frame choices differ (src in s0 with a 0x20 frame, vs retail t4 with 0x10).
- func_002D4340 (sn as sn): DEFERRED. The draft is placeholder arrays (`float v[2][4]`, `int iv[2][4]`) plus hand-walked pointers, 97 diffs throughout. It needs a rewrite with real types (a cVec pair for the rect, FTOI4 output) before it can be scored meaningfully.
- func_00140860 (sn): PARKED (~20 min). The 0x200..0x2FF test only gets retail's lhu + signed slti when the kind goes through an int: an inline `isEmKind(int kind)` with early returns (k_int_ret_shared.c, 189 words / 134 diffs, the same count as the draft). Retail also threads that helper's 0/1 result into direct branches (ours keeps `v0 = 0` and a bne), keeps obj in a0 for both the lhu and checkDeadFlag, keeps `((t >> 1) & 1) == 1` as a beq against 1, and tests D_00747A84 in each arm. An obj local, per-arm D tests (195 words), `&&`-returning helpers (unsigned range fold) and the header cGameObj_idInRange (187/188 words, flag build) don't give that. Header notes for a later handoff: f5B0 is cOmBase.flags0 (0x5B0), type is actorId (unsigned short 0x2FE), the array copy is cVec_copy3, and cEmBase_checkDeadFlag is declared `int (void *)` in ColiseumBattle.h.
- func_00135040 (sn, -ffast-math): PARKED (~10 min). Hazard rules `sqrt,cmpfull` (no --as sn) give the right size, 102 words / 19 diffs, where the draft's `sqrt` gives 103 / 74 and `div1` gives 102 / 20. What's left is the draft's note: retail issues sqrt.s right after its 2-nop pad and loads `reach` (0x10(sp)) and mtc1 0.0 after the root, while ours hoists both above it. That changes f-register numbering and inverts the `depth <= 0` test (ours bc1fl, retail bc1t with `return 0` in the delay slot). -fno-gcse / drop-reorder / --as sn / no fast-math don't help.
- func_00134CB0 (sn, -ffast-math): PARKED (~20 min). Pass the flag to mc.py as `--wrap-arg=-f=-ffast-math` (`-ffast-math` without the `-f=` is ignored). Best is the draft as written, 88 vs 90 words / 65-67 diffs (`div1` or `sqrt`). Retail branches over each early return (`bc1f body; move a0,v0; b exit; v0=0`, and the same for `priority == 0` → 1), and the delay slot holds a copy of &b, v0 → a0. Then come two nops and an R5900-encoded sqrt.s (`c1 0x10004`). cc1 instead threads both returns into `bc1t/bnez exit` with the return value in the delay slot. These were all 77-78 diffs: plain locals with an inline cVec_copy, an inline `cVec_distSqXZ(&a, &b)`, if/else single-exit, negated compares, distSq before r, ee/cygnus, drop-reorder, and the rule sets sqrt,cmpfull / fdiv / div1 / cmppad with and without --as sn. It's the same family wall as 00135040 and 00134E18. Work: nm_work/func_00134CB0.
- func_00134E18 (sn, -ffast-math): PARKED (~5 min). Same family. Best is 138 words / 113 diffs (sqrt with --as sn, or sqrt,cmpfull with --as sn), the same scheduling-around-sqrt issue.
- func_002A6CA8 (sn): PARKED (~15 min). The draft's "same instructions, only order/numbering" note is stale: as written it is 62 vs 63 words / 49 diffs. Retail materializes 0.0 with `mtc1 zero, f0` and stores it with swc1, while ours stores the zero vertex fields with integer `sw zero`. Literal stores per vertex, per component, inline cVec_set4 (65 words) and reversed set4 all give sw zero; cygnus/ee/drop-reorder are worse (62-78 words, 55+ diffs). The zeros probably come from a non-constant float source in the original (a rect or screen struct?). Holding them in locals is banned. Work: nm_work/func_002A6CA8.
- func_00154DA0: PARKED (~25 min incl. permuter). The permuter on base.c (10:43-10:54) produced only new_var aliases and constants held in locals; nothing usable. It was killed, and PERM=0 is confirmed.
- func_00180CD8 (sn, as sn): PARKED (~20 min). Moving the `(o, 5, 0)` call into each of the three display branches (nm_work/func_00180CD8/five_in.c) gives retail's cross-jump (only the jal is shared). With `--fp-hazard-rules=mtc1`, everything through 0x1A0 matches (186 vs 190 words, 72 diffs, all in the colour tail). Two things are left:
  - Retail pads its divides by the constants 0.3 and 0.7 with the two-nop fdiv template, but its two hp/max divides are bare. No single rule does that: `mtc1,fdiv` is +2 over retail per ratio divide (192/194), and div1/cvtdiv pad the ratio divides too.
  - The tail allocates differently: retail keeps 1.0 in f22, 0.2 in f21 and a in f20, and b reuses f22. Tried a single-expression a, `1.0f - a` inline and t-only arguments (69-73 diffs).
- func_00137670 (sn): PARKED (~25 min), 93 words / 77 diffs (nm_work/func_00137670/dotpt.c, clean).
  - Retail's frame comes from `ax`, `step`, `t` and `h` being declared inside the loop body. GCC 2.95 gives block locals temp slots, so `ax` reuses cVec_sub's freed 0x10 temp, `step` is at 0x20 and cVec_scale's temp at 0x30 (blk.c). A function-level `ax` puts it at 0x10 and shares the sub and scale temps at 0x30, as in the draft.
  - A `cVec_dotPoint(d, v)` inline (`v->w = 1.0f; return sceVu0InnerProduct(d, v);`) gives the right size and retail's second `&ax` pointer for the w store and the product argument.
  - Left: retail keeps the sub temp's pointer (s7) alive as the scale source and spills `&r` to 0x40 (0x100 frame; ours is 0xF0 and rematerializes `sp+16` in the loop). Retail also stores r and step `sp`-relative (`sqc2 0x30(sp)`, `0x20(sp)`), which the "r"-constrained VU0_SQC2 gives only when the base is the frame itself.
  - Tried: a whole-axis inline helper (frame 0x100 but ax at 0x20), a setPoint inline, cVec_copy3 + w, h before the product, else-if clamp, function-level t/h.

## 11:10 rule update (maintainer)
- goto is allowed only when no clean form (if/else, loops, early return, single exit) matches. Only forward jumps to a shared exit or cleanup label, with a one-line comment on the label saying the clean form was tried and doesn't match. If a goto version only reaches 90-99%, park the clean form as a NON_MATCHING draft instead.
- The CRI middleware PR was merged, so 0x322C68-0x36EE90 is open again.
- Tool note: at 11:11 mc's symbol cache was rebuilt while build/SLUS_215.03.map was being rewritten, so it came out empty and every relocation showed as unresolvable. Fix: delete nm_work/mc/symaddr.json.
- 11:12 correction: the CRI range (0x322C68-0x36EE90) is off-limits again until further notice, including its headers (mwsfd.h, criSj.h, ADXF types), because the maintainer restructured those types upstream. The 11:10 "CRI open" note above is void.
- func_001EBA20 (sn): PARKED (~8 min). This is PROGRESS.md's recurring "retail rebuilds the stack address at each use" blocker. Retail rebuilds &pos (`addiu v1, sp, 0x30`) in the obj-test delay slot, while ours keeps it in s3 (an extra saved register, 0xB0 frame vs 0xA0). VU0_SQC2_VF0_MEM(&pos, 0) for the zeroing gives retail's sp-relative `sqc2 vf0, 0x30(sp)` but is 87 vs 85 words (the draft's pointer form is 84). Loop-body or else-arm scoped locals change nothing.
- func_002AC9B8 (sn): PARKED (~10 min). The draft (raw offsets, int flags) is 137 vs 139 words: retail hoists ~0x2000/~0x1000/~0x800/~0x400 into fp/s7/s6/s5 and reloads ~0x4000 each pass, ours hoists three masks. A typed rewrite (cIDBaseObj/cIDBaseEnt, jit[], callee prototypes from cIDBase.c, three loop shapes, an inline clear helper) is 147-163 words. cIDBaseEnt.flags is `unsigned int` in cIDBase.h, so every `~0x4000`-style mask becomes lui/ori where retail uses a sign-extended `addiu -0x4001`. This function reads flags as signed, which is PROGRESS.md's open "cIDBaseEnt.flags signedness" conflict, so the header has to be settled before a typed version can match.
- func_002BAE98 (sn): BLOCKED (tooling, ~8 min). Apart from one word, the draft matches retail instruction for instruction (62 vs 63 words; the 48 "diffs" are the shift). Retail has a `nop` at the unlink loop's back-branch target (0x50, `bnel ... .L002BAEE8`), which makes the loop 7 words. That is the R5900 short-loop errata pad, PROGRESS.md's "short-loop pad nops" blocker. Neither `--as sn` nor `--wrap-arg=--call-loop-pad` (call-bearing loops only) adds it. For a later handoff, the draft also needs real names in place of IsLive2BAE98/Unlink2BAE98 (address-suffixed) and a header comment; cVtEnt in cModel.h covers its MgrVtEnt.
- func_002BF948 (sn): DEFERRED (~3 min). 206 vs 205 words / 175 diffs (shift). Retail copies the combo and skill blocks with 16-byte lq/sq. The draft gets that only through local wrapper typedefs with `__attribute__((aligned(16)))` cast over cCoreSave.h's arrays, which is a type change made for codegen. A clean version needs header struct types for those blocks (combo at 0x1B0 and skill at 0xB0 are both 16-aligned in the save record, which fits real 16-aligned member types). Decide that in the header first, then retry the register-allocation spill (retail spills cont/allCont and keeps &skill in fp).
- func_0038F200 (ee-2.9): PARKED (~6 min). 118 vs 117 words / 98 diffs. Retail loads D_003FA62C (the reent std-stream pointer) only after each record's field stores and walks the destination in the 0x60 copy loop (src from sp, dst a1/s0); ours hoists the load above the stores. Testing whether the alias sets decide it: `void **D_003FA62C` with a `void *stream` field (101 diffs), and a reent struct with File pointers or `void *` streams (99). No change. For a later handoff the draft also needs real type names (File38F200 is address-suffixed) and should drop its `d = &D_...` locals.
- func_0012DCB8 (sn): PARKED (~25 min incl. permuter). A named `cVec *corner = self->corner;` used for both loops and the min copy (nm_work/func_0012DCB8/corA.c) gives the right size and frame, 131 words / 17 diffs, down from 142/117. The min/max loop then counts down with one induction pointer as in retail. Left: retail's pointer is self-based (`self + 16*i`, displacements 0x110..0x118) and its min copy reads x as `0x110(self)`, while ours uses corner-based `0(v0)`. Loop-2 or copy through self->corner directly (134-144 words) and five loop-1 shapes (for-inc, while, do-while, indexed u, end pointer: all 17) don't change it. The permuter (11:05-11:21, base 200) only reached 175, through a banned `do { } while (0)` in loop 1. Killed, PERM=0 confirmed.
- SphereTriangle / 0x135B18 (sn): IN PROGRESS. A memory-operand store macro closes the draft's blocker. With a proposed `VU0_SQC2_MEM(reg, v, off)` (sqc2 $vf<reg> to an `"=m"` quadword at v+off; tested in a local copy, nm_work/func_00135B18/godhand/vu0.h) used for both stores in the add and scale helpers, and `abc` declared before `ab` (retail slots: near 0, mid 0x10, abc 0x20, ab 0x30, temp 0x40), it is 141/141 words, 78 diffs (mem3.c). Left: FP scheduling and numbering in the three distSq sums (retail adds b's terms before a's), and the VSCALE memory operand as `0x40(sp)` (ours `0(v1)`). Max forms (if-chain, four ternary orders) give 79-93. The permuter on mem3.c started 11:19:45.
- func_0019AF80 (sn): PARKED (~15 min). The draft is all banned constructs: a placeholder `float f[16]`, int stores through `*(int *)&f[4]` and comma-expression dead stores. A clean rewrite (nm_work/func_0019AF80/a.c) uses 00193800.c's `cVec v[4]` setup and cOmHitVolume types, and a `partAt` inline over an in-range test returning `unsigned char`, which gives retail's andi 0xFF bool (it reads like a C++ bool helper). It is 142 vs 137 words. What's left:
  - Retail keeps the dead child-count stores at 0x10(sp), the size vector's slot, so the setup vectors' scope has ended by the loop and the count lives in a real addressable object. With `int num` the stores vanish after inlining. Matched callers (001ad818.c, 0014b640.c, 001a5208.c) only get the store through `char frame[N]` buffers cast to `int *`, which is now banned as a placeholder.
  - The outer j loop: retail recomputes j*2 with t1 = table and t3 = table + 1, and enters the inner loop at a bottom test.
  - The child flag word at 0x154 needs a cOmBase field (it is inside unk14C).
- func_003B6290 (ee-2.9): BLOCKED. Retail's strlen loop carries the R5900 short-loop 3-nop pad. Our ee-as has the short-loop check disabled, so the bytes can't be reproduced. Same blocker as 002BAE98.
- func_001A6FB0 (sn): PARKED (~10 min). The draft relies on a placeholder `char hold[16]` and address-suffixed types and names. It shares the parts[] range-check idiom with 0019AF80, and I tried 7 helper forms in nm_work/func_001A6FB0/f1..f7.c:
  - f5 (`if (i < 0) return 0; return i < n;` returning unsigned char) is the only form that gives retail's branch plus andi 0xFF. It tests with bgez, though; retail computes `slt i, zero_reg` with the zero hoisted into t4, then bnez.
  - The other forms give movz/movn or srl/and.
  - The dead count store to 0(sp) disappears whenever the count lives in an `int`, because GCC 2.95 purges the ADDRESSOF. Only a BLKmode buffer keeps it, which the rules ban as a placeholder.
  - The real out-param object for this cOmBase child-lookup idiom is still unknown. That is the key question for this family (001A6FB0, 0019AF80, and the matched 001ad818/0014b640/001a5208, which use `char` buffers).
- cSnd_GetStageBgmReq (002D0D70, sn): SOLVED, handed off to nm_solved/cSnd_GetStageBgmReq (75 insns, 12 relocs).
  - The fixes were the idle helper as an early return (`if (m->busy != 0) return 0; return 1;`, returning unsigned char), which gives retail's bnez/li/andi 0xFF byte bool, and `case 0:` grouped with `default:`, which gives retail's pivot-2 decision tree.
  - The real callee signatures come from their definitions: func_002D0B88(unsigned short) and cSnd_BgmReqFromEnemies(void *). Both prototypes go into cSnd.h (header_changes.md).
  - self is cSnd, and kind is cSnd.bgmState (0x13C).
  - D_003BD930 and D_00586B28 have no header and are declared as void*/char*/unsigned char* elsewhere, so solved.c uses local views BgmGameMode and BgmOverride.
  - For the reviewer: `case 0:` is a real label (bgmState 0) that changes the bytes; without it the switch pivots on 3.
- func_002CAF28 (sn, as sn): IN PROGRESS. Best is nm_work/func_002CAF28/c.c: 81/81 words, 36 diffs (the draft was 74/81).
  - Fixes so far: the quiet test as an unsigned-char early-return helper (retail's bnez/li/andi 0xFF), `if`/`else` stores for target[3], float literals, the else branch written in index order 1, 2, 3 (it then schedules to retail's order exactly), and loop pointers assigned cur, target, step (loop registers now match).
  - Left: self is copied to a2 in retail, and the first branch's stores and the D_003BD930 load are scheduled differently. All 24 orders of the first branch's four stores give the same output. Every ternary placement is 80 words.
  - Header question for a handoff: the draft's local `cSnd` view (cur[5] at 0x60, target[5] at 0x74, step[5] at 0x88) clashes with cSnd.h, which names cur[3] as f6C (step[5] ends at 0x9B, before f9C). That would need splitting cSnd.h's unk4C/unk70 into the three arrays, with the f6C users renamed to cur[3].
  - Permuter case: perm/func_002CAF28.
- SphereTriangle (00135B18): permuter rotated out at 11:40 after 15 min stuck at 1325. Its best outputs are all steering (new_var temporaries, a constant held in a variable, an empty `do {} while (0)` block), so I rejected them. The best clean version is still mem3.c (141/141 words, 78 diffs) with the proposed VU0_SQC2_MEM macro. PARKED.
- func_0037E4C0 (sn): PARKED (~13 min), 106 vs 108 words. Map of the two count copies:
  - Retail computes n = (end - begin) >> 3 into a1 and copies it to a0 in the delay slot of the cancel test.
  - a1 serves the wrap `cur == 0 -> n - 1` and page-down's `n / 10` (divu, so n is unsigned in that division).
  - a0 serves `cur < n - 1`, `n > 10` and page-up's `(n - 1) / 10`.
  - Tried without effect: an int n with typed 8-byte entries (wrong: it gives div), unsigned n from an inline count accessor, the count recomputed at the a1 sites (CSE folds it back), n computed after the cancel test, and the initializer form.
  - Callee: func_0037E670 is defined as `void (char *self)`, so the call needs `(char *)m`. menuCtl.h's MenuPad doesn't fit (trg is at 0x38; here 0x34 is trig and 0x38 is rep).
- func_002B4A50 (sn): PARKED (~10 min), 86 vs 92 words. Best is nm_work/func_002B4A50/h1.c:
  - The alive test as an early-return unsigned-char helper `liveEnt_isAlive` (`if (e->alive == 0) return 0; return 1;`) gives retail's bnez/li/andi 0xFF exactly.
  - Inverting it (`if (!liveEnt_isAlive(e)) { slot path } else { call; busy = 1; }`) gives retail's block layout, with the call block out of line and reached by bnel.
  - Left: loop-invariant hoisting. Retail hoists all 8 masks plus %hi(D_00747A80), putting 5 in s-regs and a1-a3/t0 in caller-saved registers spilled with sq around the call. It keeps `1` for sllv inside the loop. Ours hoists 5 masks, %hi and the constant 1 (CSE shares it with busy = 1). Swapping busy/call order, `1U << i` and the `m->mask = m->mask & ...` form change nothing.
  - func_002D3750 has no C definition; the draft's `void (LiveEnt *)` has not been checked against retail's entry yet.
- func_002A6FF8 (sn): PARKED (~15 min). The draft's `long ok` / `ok & 0xFF` helpers are steering. Best clean version is nm_work/func_002A6FF8/o8.c, 105 vs 110 words.
  - Finding for the cOmBase/parts range-check family: retail's vertex lookups compute `slti i, 0` as a value and then bnez, the same shape as 001A6FB0's `slt i, zero_reg`. Only a helper that takes the lower bound as a parameter reproduces this: `isInRange(int v, int lo, int hi)` called with lo = 0. o8's body (`if (lo <= v) return v < hi; return 0;`) gives slti/bne/slt/andi 0xFF. With no lo parameter, GCC folds `i < 0` for the unsigned-short index or uses bltz.
  - Left:
    - Retail reloads the count (lw 0x19C(s1), via self) inside each lookup's conditional path and holds the result in v1 (`daddu v1, v0`). Ours loads nVerts once before the branch. The `ok = 0; if (...) ok = ...` forms if-convert to movn.
    - Retail keeps self (s1) and t (s2) in separate registers and hoists 0x7FFFFFFF/0x80000000 into s3/s5, with a 0xA0 frame against our 0x80.
  - ChkLine has no header. Matched units declare it with 13 args, and 0017d488.c types a6 as `void *` while 00280be0.c and 0025adc0.c use `int`.
- func_0010B2E8 (sn): PARKED (~6 min), 171 vs 179 words. Retail computes the 0x200..0x2FF test into a separate register: `slti 0x200; bnez L; a2 = 0; slti 0x300; a2 = v0; L: andi a2, 0xFF`. The draft's early-return helper computes straight into v0. The `ok = 0; if (h >= 0x200) ok = h < 0x300` forms (unsigned char or int, with if/else) if-convert to movn, and the `&&` form becomes `addiu -0x200; sltiu 0x100`. isInRange(h, 0x200, 0x300) with bounds as parameters is identical to the draft. The draft's CHECK(i) macro (five pasted copies) also needs replacing with real C, probably a per-slot inline that returns a tri-state.
- func_001A6FB0: retried with isInRange(i, 0, n), lo as a parameter (r1..r4). The loop index is unsigned 1..31, so the lower test still comes out as bgez/bltz, never retail's `slt i, t4 = 0`. No change.
- func_0037B0E0 (sn): BLOCKED BY RULES (~4 min). Retail sets `addiu s0, zero, 3` separately in each case of the first switch (0xAC, 0xBC, 0x118), then passes s0 as the x column to every later func_002E0DE8 call. So the original had a local column variable assigned 3 per case. A matching form needs exactly that, which the rules ban ("no constants held in variables, even when the local is assigned more than once"). Not attempted further.
- func_0026EB20 (sn): SOLVED, handed off to nm_solved/func_0026EB20 (80 insns, 6 relocs). The compiler comes from the draft's header.
  - Two fixes: both vectors are zeroed in place with the project macro VU0_SQC2_VF0_MEM (sp-relative, so &back isn't materialised early), and both transforms use sceVu0.h's cVec_applyMatrix inline, so &back is rebuilt after the second apply as in retail.
  - The raw offsets are replaced with cEm00 fields via header_changes.md: mtx[16] at 0x80 (same name as cOmBase.mtx) split from unk000, and pitch at 0x1708 split from unk16FC. Nothing in src/ or drafts/ uses cEm00's unk000 or unk16FC.
  - The callee externs match their definitions (Pos_probeGroundBelow in 0013bc28.c, capVu0MagnitudeXZ in 001f7e80.c) and the existing capVu0Atan2 declarations.
- cSnd_IsEnemyAlive (draft 002d0c10.c, sn): PARKED (~6 min), 46 vs 47 words, best u1.c using isInRange(v, lo, hi) as an early-return unsigned char helper. Same open shape as 0010B2E8: retail puts the bool in its own register (`a0 = 0` in the bnez delay slot, `a0 = v0` after the second slti, `andi a0, 0xFF`), while ours computes into v0. The matched ColiseumBattle_DefeatAllEnemies (001ef8b8.c) gets this shape only with the pre-rules `long ok; ... if (ok & 0xFF)` form. C++ `bool` (mc --lang c++) can't be used because it mangles the callees. Open question for this family: which clean C keeps the bool in a separate register without if-converting to movn.
- func_002CAF28: permuter rotated out at 11:53, stuck at 880 since 11:43. Every output is steering (`D_003BD930++/--`, new_var aliases of s and of &D_003BD930) and all were rejected. PERM=0 confirmed. The best clean version is still c.c (81/81 words, 36 diffs).
- func_001569A0 (sn): IN PROGRESS, 4 diffs, from the draft's 9 (best is nm_work/func_001569A0/w2.c).
  - The draft's EdgeFrame placeholder struct and EDGEFRAME_OFFSET are replaced with plain locals e1, e2, n and an inline `cVec_sub(d, a, b)`: a work vector zeroed and subtracted with VU0_ZERO_VSUB_XYZ_MEM, VU0_LQC2, then a store to d with the proposed `VU0_SQC2_MEM(4, d, 0)` ("=m" operand, from the SphereTriangle work). That gives retail's sp-relative `sqc2 vf4, 0x20(sp)`.
  - Left: only the build order of two addresses. Retail builds &n (v1) at 0xC and &work (v0) right before the lqc2; ours is the other way round.
  - Tried: the "r"-based VU0_SQC2 store (&n comes early, but the store becomes 0(v1)), and the helper returning d nested in cVec_copy3 (77 vs 72 words).
  - Permuter started 11:54 on w2.c.
- func_00192700 (sn, as sn): BLOCKED (tooling). Apart from one missing word, it matches retail. Retail's three-instruction loop over the child count has the R5900 short-loop nop before its bnel, which our assembler path never adds. Same blocker as 002BAE98 and 003B6290.
- func_001CE6C8 (sn): IN PROGRESS, 8 diffs, right length (nm_work/func_001CE6C8/a3.c). Using the proposed VU0_SQC2_MEM for both stores in cVec_scale3 (to &work and to out) closes the draft's memory-operand blocker. Left:
  - The register for &work is a1 in retail and v1 in ours. Retail also computes it at 0xBC, before &drop (v0).
  - The pos pointer is v1 in retail and v0 in ours.
  - The drop.x store is ordered against the a1 = mtx argument setup.
  - All 6 drop-field orders and 24 declaration orders were tried: 8 at best.
  - Next for the permuter after 001569A0. Like 001569A0 and SphereTriangle, it needs VU0_SQC2_MEM added to vu0.h.
- F32toF16 (001563F0, sn): SOLVED, handed off to nm_solved/F32toF16 (38 insns, 0 relocs). meta.json gives the compiler, since the draft has no header line.
  - The return type is unsigned short: retail ends both paths with `andi v0, 0xFFFF`.
  - The fix was the standard float-to-half form: one unsigned short result `h` (so the zero-extend stays at the shared return, giving retail's `ori; jr ra; andi`), a `shift = 113 - (a >> 23)` local in the denormal branch, and rounding written as `(a + 0xFFF + ((a >> 13) & 1)) >> 13`.
  - This replaces the draft's int return with `& 0xFFFF` masks. No callers in C.
- func_001569A0: permuter rotated out at 12:02 (8 min) for func_0026EF60's 1-diff draft. Its only improvements (60, 155, 205) alias &n with new_var, which is steering, so all were rejected. PERM=0 confirmed. Best clean version is still w2.c (4 diffs).
- func_0026EF60 (sn, as sn): PARKED at 1 diff (~12 min, nm_work/func_0026EF60/vE.c = the draft with `if (0.0f > angle)`).
  - Retail copies angle into the result in the bc1f delay slot, then computes `neg.s f2, f20` from angle (f20). Ours computes `neg.s f2, f2` from the copy.
  - Tried with no gain:
    - 15 abs forms: if/else in both comparison orders, copy-then-negate, ternary, in-place, and the Absf inline from Turn_dest_dir (002da1f8.c) plus three variants. The copy-first forms drop to 94 words.
    - Split atan/turn variables: 4 diffs.
    - One scratch float reused for the distance tests: still 1 diff.
  - The permuter found a 0 only with a dead `off = angle;` after the half-angle test, which is a banned dead store; rejected.
  - For the hand-off, Turn_dest's declaration should use the draft definition's names (from, to, cur, max).
- func_002BCF28 (sn): IN PROGRESS, 4 diffs, from the draft's 9 (nm_work/func_002BCF28/v.c).
  - The SegFrame placeholder struct is replaced with plain locals startA/endA/startB/endB/out, plus an inline `cVec_transform(dst, v, m)`: a work vector loaded with VU0_LQC2, stored with the proposed VU0_SQC2_MEM, sceVu0ApplyMatrix in place, then stored to dst with VU0_SQC2_MEM. Then cVec_copy3(&endX, &out). This fixes the early &work build.
  - Callee signature: func_002BC0F8 is (startA, endA, lowA, highA, startB, endB, lowB, highB). The argument setup order in retail (f12/f13 before a2/a3) only matches with this order; the floats are in the same registers either way.
  - Left: the first xyz copy loads x/y into f2/f1, where ours uses f1/f2; the second copy matches.
  - Tried with no gain: copy3 against field-by-field copies, 3 declaration orders, 3 helper parameter orders, and a per-segment helper (79 words).
  - Permuter started 12:11 on v.c (base 20). Like the others, it needs VU0_SQC2_MEM in vu0.h.
- func_002BCF28: PARKED at 4 diffs (~20 min). Best clean versions: nm_work/func_002BCF28/v.c, or n1.c with a cVec_transform3 inline that owns `out` (same score).
  - The permuter hit 0 at 12:14 only with `do { } while (0);` between `endB.y = highB;` and the second transform, which is a banned fence; rejected. PERM=0 confirmed. So retail has a block or loop-note boundary there.
  - Tried for that boundary:
    - A segInit(start, end, m, height) inline (ForwardVec + y store) on B only or on both. The first copy then gets retail's f2/f1/f0, but &startB stops living in s2 (79 words).
    - Swapping the y store and the ForwardVec call per segment (6-11 diffs).
    - Per-segment helpers (79 words).
  - The callee signature finding stands: func_002BC0F8(startA, endA, lowA, highA, startB, endB, lowB, highB).
- func_00276478 (sn): NEEDS A RULING. It is 1 diff clean, and matches (103 insns, 6 relocs) only with a 64-bit flags local. Files: nm_work/func_00276478/o3.c (clean, 1 diff) and l2.c (MATCH).
  - Fixes from the draft's 19:
    - An `isScreenGhost(self)` inline returning `self->emNo == 0x26A` gives retail's xori + bnel.
    - `#define OBJFLAG_SEE_THROUGH 0x10u` gives the lui/ori `~0x10u` (a non-canonical unsigned constant on this host).
    - Writing animRate before objFlags in both arms gives the merged tail store order.
  - Left: the bit-6 test is `dsrl` in retail. It is srl for every 32-bit form tried: a flags local, the global read directly, `== 0`, a signed cast, and a bitfield view.
  - It closes only with `extern int D_00747A84;` (signed, so `lw` sign-extends for free) plus `unsigned long flags;`.
    - `long flags` gives lwu/dsra (2 diffs), and `unsigned long` with an unsigned global gives 105 words.
    - dsrl can only come from a 64-bit operation, so the original probably held the word in a 64-bit u_long. But agent-rules lists "long temporaries" among the banned type changes. Main has the same idiom in 001627d8.c (`unsigned long t`), 002bb1f0.c and 002aa480.c (`long t`).
  - Not handed off. If the maintainer accepts a 64-bit flags local, l2.c is ready. Its D_00747A84 would be `int` here, against `unsigned int` in drafts 0013d288/00291d48/002fb310 and `int` in 002cb278.
  - The GhostFrame struct (target plus the childAt count) has to stay; plain locals give 100 words.
- func_002951B0 (sn, as sn): IN PROGRESS, 43 diffs, same as the draft (nm_work/func_002951B0/B.c).
  - The draft's EmSetFrame placeholder struct (with `char pad34[0xC]`) is replaced with plain `SET_EM_DATA data; cVec pos;` and a block-local work vector stored with VU0_SQC2_MEM. That gives retail's 0x40/0x50 layout with no padding.
  - Left: retail keeps entry in t0 and converts x, y, z strictly in order after the `entryNo = 0xFF` byte store. Ours hoists all three lh loads above it, and entry lands in v1.
  - Tried with no gain: cVec_set4 against field stores, 5 field-assignment orders (41-51), a SetEmData_init(d) inline (pos zero + entryNo) before and after objId, and cygnus-2.96 / ee-2.9 (54 / 43).
  - The neighbours 00294968.c and 002955f0.c are cygnus, but 00294b60/00294f70/00294970 are sn. Queued for the permuter.
- func_0026F328 (sn): IN PROGRESS (nm_work/func_0026F328).
  - The draft's cEmSight local view is replaced with cEm00 (emNo 0x564, emFlags 0x16D0), with no change.
  - An if-chain instead of the switch (e3.c) gives the right length and registers, 20 diffs, but retail's decision tree (slti 0x266 / 0x264) proves it was a switch.
  - The switch form (e0.c: 84 vs 83 words, s1/s2 swapped) only lacks retail's early `addiu s2, sp, 0x30` (&me) before the two vf0 zeroing stores, which reorg puts into the last case's beq delay slot.
  - Tried with no gain: cases breaking into the shared `|=; return 1` tail with the sight test in default (85 words), 2 declaration orders × an eyePos inline × the ChkLine test polarity (65-70). Queued for the permuter on e0.c.
- func_0026F328 (sn): SOLVED, handed off to nm_solved/func_0026F328 (83 insns, 2 relocs). The compiler comes from the draft's header.
  - The fix is a `cVec_zero(cVec *v)` inline (VU0_SQC2_VF0_MEM through the pointer) in place of the in-place macro calls. It puts &me in a register before the zeroing stores, as retail does (`addiu s2, sp, 0x30` in the last case's beq delay slot).
  - The switch form is kept (retail's slti decision tree), and the cEmSight local view is replaced with cEm00 (emNo, emFlags).
  - header_changes.md adds cVec_zero (plus `#include "godhand/vu0.h"`) to cOmBase.h. Verified through a local cOmBase.h copy included first.
  - ChkLine's declaration is copied from 00255eb0.c.
- func_00275888 (sn): SOLVED, handed off to nm_solved/func_00275888 (60 insns, 5 relocs), with the same cVec_zero fix and header change. The draft's blocker (&eye in s1 from the prologue) was this same shape.
  - Callees match their definitions: MtxInitRotY (00147988.c) and CopyVec3ToField30_147C40 (00147c40.c).
  - Finding: when retail builds a zeroed local's address before its `sqc2 vf0` store, try cVec_zero. Retry it on the other drafts with that shape: 002BCF28, 001569A0, 001CE6C8, SphereTriangle, 0026EF60.
- func_0026E7D8 (sn): IN PROGRESS, 19 diffs at the right length (108 words), from 79 diffs / 106 words (nm_work/func_0026E7D8/b.c).
  - Fixes:
    - An `isRetreater(self)` inline (`return self->emNo == 0x211;`) replaces the draft's `(self->emNo ^ 0x211) != 0`. Same code: xori + bnez.
    - A `cVec_initCopy3(d, s)` inline (`cVec_zero(d); cVec_copy3(d, s);`, a zero-then-copy constructor) for dest. It gives retail's &dest built in a register before the zero store and then moved to s3, and fixes the self/&dest s-register swap.
  - The draft's "call-loop pad" note doesn't apply: --wrap-arg=--call-loop-pad changes nothing, and the length is already right.
  - Left: the spot[] setup only. Retail builds &spot[1] in a1, stores spot[1]'s w, z, y through it (in that order), then reuses a1 for &dest. Ours uses v0 and v1, stores y, w, z, and builds &dest early.
  - Tried with no gain: `spot + 1`, field stores (106 words), the spots in reverse order (21), and initCopy3's parameter order or `&spot[0]`.
  - Queued for the permuter. cVec_initCopy3 would also go in cOmBase.h, after cVec_zero.
- func_001CE6C8: permuter rotated out at 12:33 after 17 min. No output beat the base (90). PERM=0 confirmed. Best clean version is still a3.c (8 diffs). cVec_zero for its work vector changes nothing.
- func_001A4650 (sn, as sn): IN PROGRESS, 10 diffs at the right length (105 words), from 77 diffs / 104 words (nm_work/func_001A4650/a.c).
  - The DoorReachFrame placeholder struct and the DOORFRAME_OFFSET stores are replaced with plain locals me/pl/d, stores with the proposed VU0_SQC2_MEM, and a `cVec_sub(d, a, b)` inline: cVec_zero(&work); lqc2 a/b; vsub.xyz; store to work; copy to d.
  - Left: address build order. Retail builds &work (v0) and &d (a0, kept for capVu0LengthSq) before the subtraction, and passes &me as plain sp. Ours copies sp into v0 for &me, uses v1 for &work, and builds &d in the jal delay slot.
  - Tried with no gain:
    - The helper's parameter order: same 10.
    - VU0_ZERO_VSUB_XYZ_MEM inside the helper, or the whole sequence written in place with plain locals: 104 words.
    - fabs moved into the test: 15.
  - Permuter started 12:33 on a.c. Like the others, it needs VU0_SQC2_MEM in vu0.h and cVec_zero in cOmBase.h.
- func_001C20D8 (sn): IN PROGRESS, 16 diffs at the right length (98 words), from 83 diffs / 99 words (nm_work/func_001C20D8/u30.c).
  - Fixes:
    - A `cVec_copy(d, s)` inline (VU0_LQC2 s, VU0_SQC2_MEM d) for the two vtable-getter position copies. It builds &me in s0 right after the first call, as retail does, and fixes the s0/s1 swap.
    - Plain locals me/pl/d/diff/work replace the draft's `cVec f[2]` placeholder array and its 4-parameter cVec_sub3.
    - `VU0_ZERO_VSUB_XYZ_MEM(&work, 0, &me, &pl); cVec_copy(&diff, &work); cVec_copy3(&d, &diff);` gives the sp-relative work stores.
  - Left:
    - Retail builds &work (v0) early.
    - Retail keeps the bit-2 test as `li 1; bne` (`== 1` not folded to `!= 0`).
    - Retail tests 0x3EC/0x3ED with an equality chain where ours uses the switch's slti range.
  - Tried with no gain:
    - An if-chain for the ids: frame 0xD0 and an extra saved register (88-98).
    - cVec_subXYZ inline variants (60).
    - A named bit local (63-64).
    - `& EM_SIGHT_FAR` forms (60-63).
    - ee-2.9 / cygnus (57+).
  - Still uses the draft's `long flags`, needed for retail's dsra. That is the same 64-bit-local question as func_00276478.
- func_0012A3C0 (sn): PARKED (~10 min), 101 diffs, same as the draft.
  - The FireBoxFrame placeholder is replaced with plain locals and the cVec_transform inline from 002BCF28 (nm_work/func_0012A3C0/a.c). The integer side and the vector part line up.
  - All the diffs come from loop-invariant motion. Retail hoists -32, -3, -0.5 and 0.5 into f20-f23 and reloads only 3.0 (used twice, CSE'd) inside the loop. Ours hoists three and reloads 0.5 too, so every FPR and the prologue shift.
  - Tried with no gain: separate continue tests, `>` comparisons, nested actor tests, and int i (all 101), plus a positive in-box test (97, 108 words).
  - Next idea: whatever changes loop.c's insn_count or the lifetime of the 0.5 pseudo, e.g. the copy3 guard or the call order inside the loop.
- func_001299F0 (sn): SOLVED, handed off to nm_solved/func_001299F0 (107 insns, 7 relocs). The compiler comes from the draft's header.
  - The HoldFrame placeholder struct is replaced with plain locals (mtx[16], at, out) and a file-local `cVec_transform(dst, v, m)` inline: lqc2 v, sqc2 to work as a memory operand, sceVu0ApplyMatrix(work, m, work), then copy work to dst. Then cVec_copy3(&at, &out).
  - That builds &work in a saved register before the first copy and gives the larger frame, as retail does. The draft was 100 diffs from exactly that.
  - The OBJ_VEL raw-offset macro is replaced with a cGameObj `cVec vel` field at 0x550 (from unk550), zeroed x, y, z. Only that order matches; z,x,y (the draft's order) leaves 6 diffs.
  - header_changes.md adds VU0_SQC2_MEM to vu0.h and names vel in cGameObj.h.
  - Callees: Turn_dest uses the draft definition's parameter names (from, to, cur, max); MtxInitRotY matches 00147988.c; Adjust_theta comes from cCamera.h.
- func_001A4650: ROTATED OUT of the permuter at 12:41 (12:29-12:41, base 460, best 190). Every low score uses a `new_var = &d` alias and a `do { } while (0)` around the pl copy, both banned. Nothing clean.
- func_001C8930 (sn, -ffast-math, sqrt): IN PROGRESS. Clean equivalent of the draft at the same 2 diffs: nm_work/func_001C8930/k2.c. It keeps the FlyFrame frame struct, the same pattern as DropFrame in 0026bdd0.c, because retail keeps the childNum store at 0(sp). It drops the `work = &f.work` alias for a file-local `cVec_scaleVia(d, w, s, k)` inline (cVec_copy w = s, VU0_VSCALE_XYZ_MEM w, cVec_copy d = w). What's left: retail builds &f.work in a0, before the `child != 0` test, and ours uses v1. The other forms were worse: plain locals drop the childNum store (93 words), a helper that owns its work vector (14-25 diffs), and inline cVec_copy calls on f.work (10 diffs). The permuter on f1.c reached 10 only with a `new_var = &f.work` alias (banned). The permuter on k2.c started 12:48.
- func_003219D0 (cygnus, merge of a sorted KeyList): IN PROGRESS. The draft is 51 vs 63 words. Writing every access through the struct (`dst->ent[...]`, `src->ent[j]`, `dst->num += src->num`, with an `e = src->ent[j]` local) gives 62 words / 57 diffs (nm_work/func_003219D0/r2.c). That also removes the draft's `d`/`i = nd`/`j = ns` copies. Retail keeps three copies of the dst->ent base (t9/t7/s2), so three &d[i-1] pointer givs, plus an &d[j] giv for the shifting store, and saves s0-s2 in a 0x30 frame. Neither the 16 d-local/dst->ent mixes, the index orders, nor the for/while/break inner loops reproduce it.
- Tooling note: build/SLUS_215.03.map was truncated to 0 bytes at 12:47, outside nm_work. Since then, mc.py reports every relocation as "unresolvable" (its symaddr cache rebuilt from the empty map). Instruction diffs were still valid. The map was restored at 12:49, and k2.c rechecks at 2 instruction diffs with relocations resolving again.
- cCoreSave_spawnItems (sn): PARKED again (~15 min). It needs `--fp-hazard-rules=mtc1`: retail pads each mtc1 → cvt/mul with a nop. With that, the draft is 104 vs 106 words. Read the area guard as a byte (`game()[0x5B1]`, as the file-local `game()` inline in the matched 00294f70.c does); `D_007474A0.room >> 8` gives lhu+srl. The 2 missing words:
  - Retail keeps only %hi(D_007474A0) in s4 and redoes the %lo add every pass before `lhu 0x5B0`. Ours CSEs the guard's full address into s4.
  - Retail adds `(i << 4) + data` with the shift as the first operand, and it reloads obj->pos before each of the three stores.
  - These didn't change it: typed `D_007474A0.room` for the stage, `cVec *pos` with ->x/y/z, drop-reorder, --as sn, cygnus/ee (89-96 words).
  - Header mapping for a later rewrite (draft name → header name): the draft's SaveItem is cCoreSaveItem in cCoreSave.h (id → kind, kind → flag, heading → yaw, flags → serial, param → extra), and CoreSaveView/SaveItemData are cCoreSave/cCoreSaveData. The object is a cGameObj (pos 0xF0, rot[1] 0x104, vt 0x214, dropItem 0x560). 0x662/0x676 are beyond cGameObj, and the vt slot at 0x40 has no name yet. Work: nm_work/cCoreSave_spawnItems.
- cOmBase_setMeshAlphaFromLayer (sn): BLOCKED ON TOOLING (~5 min). The draft and the for/while forms all give the same instructions apart from one nop: 22 vs 23 words. Retail's loop (0x30-0x44: `beql layer; swc1 alpha; lw next; nop; bnel; lbu`) carries the R5900 short-loop pad that brings it to 4 instructions before the branch. Our assemblers pad only single-block loops, and this body has the inner `beql`. --as sn, `--call-loop-pad` (calls and `j $31` only) and ee don't add it either. It needs a wrapper pad rule for short loops with an internal forward branch, and no C change gives the nop. Work: nm_work/cOmBase_setMeshAlphaFromLayer.
- MtxInitRotQuaternion (sn): SOLVED, handed off to nm_solved/MtxInitRotQuaternion (54 insns, 0 relocs). meta.json gives the compiler, because the draft header has none.
  - The draft's hand-shuffled statement order was the problem. Plain textbook order matches: the nine doubled products as `2.0f * (a * b)`, the 3x3 block row by row, `m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f`, then `m[3][3] = 1.0f`.
  - The chained zero gives retail's single `mtc1 zero` + swc1 stores (separate `= 0.0f` statements give `sw zero`). Of the 6 rotations of the chain, only this order matches.
  - Leaving the q[] components unparenthesized gives 47 words.
  - For the maintainer: the only caller, BuildMatrixAndForward_147BB0 in src/cod/00147bb0.c, calls it with no prototype in scope, passing `int buf[16]` and an int. No header declares it yet.
- func_002A6CA8 (sn): SOLVED, handed off to nm_solved/func_002A6CA8 (63 insns, 12 relocs), with meta.json for the compiler (the draft header has no `(compiler)` form).
  - The 0.0f stores are chained assignments, one chain per value. Chains give retail's single `mtc1 zero` + swc1, where separate statements give `sw zero`. That also removes the draft's banned constant locals (x1, y1, z, w):
    `vt[0].y = vt[2].y = vt[0].x = vt[1].x = 0.0f; vt[2].x = vt[3].x = D_003C1184; vt[1].y = vt[3].y = D_003C1190; vt[0..3].z = 65535.0f; vt[0..3].w = 1.0f`.
  - Of the 24 zero-chain orders only that one matches. The others are natural order: index order gives 4 diffs.
  - Callee signatures:
    - cDvd_stepState is `unsigned char (cDvdState *)`, as defined in 00139910.c. cDvdState is private to that file, so solved.c forward-declares `struct cDvdState` and casts D_00583F20, which other files declare `char[]`.
    - func_003A52F0 comes from cIDManager.h (criStm.h's `void *` version is a CRI header I'm avoiding).
    - cTaskWork_sleep comes from gameWork.h. D_00752C04 is `cTaskWork *`, as in 00138fc8.c.
    - The sole caller passes &D_005CAC90, which is not read (noted in the function comment).
  - PolyCtx stays a local view: no header covers Gp_draw_poly4's 0x48-byte context.
  - `ctx.mode = 0` before the memset is retail's own store (the sw zero in the jal delay slot), not steering.
- Tip for other drafts: when retail stores float zeros with `mtc1 $zero` + swc1 where ours emits `sw $zero`, try a chained assignment.
- func_002A6DA8 (sn): MATCHES, NEEDS A RULING, not handed off. The draft's stated blocker (vertex store order and %hi(D_003C1190)/%hi(D_003C1184) order) is solved by 002A6CA8's loop body: PolyCtx ctx, cVec vt[4], the same five chained assignments. With that, nm_work/func_002A6DA8/t1.c is a full MATCH (148 insns, 29 relocs). t1.c keeps two constructs from the draft that need a decision:
  1. `unsigned long t = gw[0]; t >>= 3; t &= 1;` gives retail's lw + dsrl + andi bit test. This is the same 64-bit question as 00276478 and 001C20D8. An int bitfield gives srl; an `unsigned long` bitfield gives ld + dsra32; both are wrong.
  2. `unsigned int *gw = D_00747A24; g = (unsigned char *)gw - 0x584;`. Retail materializes &D_00747A24 (the GameWork flags word) and reaches every other GameWork field relative to it (0x60/0x64 off a1, then `addiu s1, a1, -0x584`). Typed `D_007474A0.field` accesses make gcc materialize &D_007474A0 itself, so the clean rewrite with GameWork fields is 85 diffs (nm_work/func_002A6DA8/c1.c).
  - c1.c needs four new GameWork fields: unk008 (0x008, resume-button bits 0x20/0x40), unk014 (0x014, u8), flags5E0 (0x5E0, cDoor.h's name) and flags5E8 (0x5E8). A local copy with those is at nm_work/func_002A6DA8/godhand/gameWork.h.
  - Callees: cCockMess_SetMessNo is `void (char *, unsigned short, unsigned char, float, float)` (00107ec8.c). func_00140E58 and func_001410A8 take the game object pointer. The task is D_00752C00.task (cTaskWorkRef in gameWork.h).
- func_001C8930: permuter on k2.c (12:48-13:10) produced no outputs (no improvement on base). Rotated out.
- cIDParam_initialize (sn): IN PROGRESS, 5 diffs (was a bare INCLUDE_ASM draft, and the earlier permuter attempt was at 815). nm_work/cIDParam_initialize/best.c:
  - It uses a local cIDParam view (no header has the type; offsets from the stores, size 0x2E0) and memset func_003A52F0 from cIDManager.h.
  - The defaults are written as chained assignments. Retail keeps separate registers for the byte 1s and the short 1s, which only chains give (each chain's constant takes its target's type).
  - The chains: `2DC = 050 = 0x80808080; 003 = 002 = -1; 030 = 02C = 028 = 04C = 048 = 1.0f; 069 = 06B = 06A = 1; 278 = 214 = 1B0 = 06C = 06E = 1`. The zeros at 010/014/018 are separate statements.
  - What's left: the 6 and 5 constants swap v0/v1, and the 0x2DC store sits two slots later than retail's.
  - A greedy move search went 14 → 5. The positions of the 6 / 5 / 0x80808080 statements were swept partway (stopped at 13:26, still 5).
  - The permuter on best.c started 13:26.
- func_0027DB20 (sn): SOLVED, handed off to nm_solved/func_0027DB20 (12 insns, 0 relocs), with meta.json for the compiler (the multi-function draft 00123908.c has no `(compiler)` header). It matches the shape of its matched sibling func_0027DBF8 (001fb2d8.c): `switch (unsigned int mode) { case 0: default: ...; case 1: ... }` with all four state bytes in each arm, here through the cGameObj names mode/phase/step/stepArg (0x2F4-0x2F7). `case 0:` is needed: without it there's no `beqz` test, 10 words. That replaces the draft's goto ladder. Both callers (0x24FB60, 0x24FC28) are still asm, so no declarations change.
- func_002831C8 (sn): rechecked (~5 min) with the matched sibling's shape (func_002832A0: `switch (unsigned int mode) { case 0: default: ...}`) on cGameObj fields. All 24 uniform per-arm store orders give at best 10 diffs, no better than the earlier 9 (clean) or 3 (goto). Stays given up.
- cIDParam_initialize (00308f40.c): PARKED, ~30 min. Best clean form nm_work/cIDParam_initialize/best.c, 5 diffs: the 6/5 halfword-and-byte constants swap v0/v1 and the 0x2DC store schedules after 0x050. Permuter plateaued at 80 (output-80-1 = moving the 0x80808080 chain after unk00C, 7 diffs under mc.py). Killed, PERM=0.
- func_00178E18: rechecked with chained tail zeros (all 3! x 3! x 4 = 144 placements of `5E8 = 5E4 = 5F0 = 0`): best 10 diffs, worse than the draft's 2. Chains don't help here. Draft itself still uses alias locals (size/ofs/rot) and cVec v[4]; a clean version would need cOmHitVolume_initWork.
- cOmSub_setVibration (001c7d50.c): BLOCKED, tooling (~8 min). Retail is unscheduled: lbu/ori/sb, then each mtc1/nop/cvt.s.w/swc1 in source order (flag, count 0x140, z 0x150, period 0x144, x 0x148, y 0x14C in the jr slot). Our sched2 hoists both conversions and sinks the sb in every compiler, assembler mode and allowed c_flags_add (-fno-gcse, -ffast-math): 12-13 diffs. Needs something like -fno-schedule-insns2, which is not in SUPPORTED_C_FLAG_ADDS. Only a volatile flag byte would pin it, and that is banned. Retail order is nm_work/cOmSub_setVibration/o1.c.
- func_0026EF60: cz_vE.c (cVec_zero) also 1 diff; stays parked.
  - Same blocker as cOl0e_setFake (tail stores in source order with mtc1 nop). ee-2.9-990721 and -O0 also tried: no. Tooling note for maintainer: 0x1738xx and 0x1C7Dxx have unscheduled-looking stores, which may mean a no-sched2 TU setting that compile.py can't express.
  - Diagnostic only (flags not allowed): with -O1 or -fno-schedule-insns{,2} plus as=sn, cOmSub_setVibration drops to 4 diffs (order period, z, x, y), and retail still puts the z swc1 between period's cvt.s.w and its swc1. So it is near-unscheduled but not plain no-sched. Not pursued further.
- cEmSetParam_getSetDataPos (00295510.c): BLOCKED, same family (~6 min). Retail converts x/y/z in sequence (mtc1/nop/cvt, scale constant loaded after the first cvt), stores all four at the end, and restores ld ra before lq s0. sn is closest at 25 diffs; ee-2.9 x2 and cygnus are worse; -O1 is 50 words. Not attempted further.
- func_00304C48 (00304c48.c): SOLVED, handed off (nm_solved/func_00304C48, sn, no as key needed; 63 insns, 2 relocs). ~15 min.
  - KEY FINDING: retail's branchy byte bool (`li v0,1` / `move v0,zero` around a bne, then `andi 0xFF`, then beqz) comes from an inline predicate written `if (x != n) return 0; return 1;` with an unsigned char return. `return x == n;`, a ternary, a result variable and if/else-return-1 all fold to xori/sltiu; an int return folds too. Retry it on displayOmLayer (002db478) and func_001BE498 (andi 0xFF child checks).
  - Local view cFxStateWatch (cNode base, cOmBase *anchor at 0x108, int state[4] at 0x240). No header covers this effect node; 003033a8.c's cFxDrift has the same 0x108 anchor.
  - For the main agent: func_00302918 is now declared in three files (00302918.c defines it with `int *a0`, 003039e8.c uses `void *`, this one `int *` with a cast). It is an effect-node method; a shared declaration taking the node pointer would remove the cast. func_003029C0 reads only a0 and doesn't set v0 (void).
- displayOmLayer (002db478.c): PARKED, ~12 min. nm_work/displayOmLayer/hf.c: an inline `isLayerId(int id) { if (id < 0x300) return 0; return id < 0x500; }` with an unsigned char return gives retail's signed slt/slti range test and branchy byte bool (33 vs 39 words). Still open: retail keeps 0x300 in a register (slt with t3, xori, beqz) instead of slti/bne. It also reloads D_00754C58 at the loop latch, as if the objFlags int store aliases the global, and copies om into a3 for the if body. Ours hoists the global, so this looks like a different alias picture; no clean type found.
- func_001BE498 (001be498.c): IN PROGRESS, 166 -> 106 diffs (167 vs 169 words), nm_work/func_001BE498b/p1.c.
  - A local childAt using the predicate `childInRange(int idx, int n) { if (idx < 0) return 0; return idx < n; }` (unsigned char) gives retail's byte bounds check. q1-q4 and r1-r4 (other predicate forms and parameter types) are no better.
  - Left: retail keeps 0x60 in s2 and recomputes idx*0x60 at the end (self in s4, idx in s3, +0x10 frame) where ours CSEs the product. -fno-gcse and piece-address forms t1-t4 don't change it.
  - Note for main agent: cOmBase_childAt's `&&` form doesn't give this function's code. If more units show the andi-0xFF child check, the header helper may need this predicate shape (it must stay identical for its 14 users).
  - Permuter started 13:44 on p1.c.
- func_0030B420 (0030b420.c): PARKED, ~12 min. The draft doesn't compile as is: func_002B4A30 is void(void) in 001b5160.c, but the draft passes D_005E79D0. Fixed (d2.c): 57 diffs, though only with the banned `*(int *)((char *)&D_007474A0 + 0x584)` macro, which gives a CONST address (%lo(sym+0x584), retail's %lo(D_00747A24)).
  - Every typed form (D_007474A0.flags as int (c2.c) or unsigned, or a nested struct at 0x584 (c3.c)) makes CSE keep &D_007474A0 in s0 and address 1412(s0): 65 diffs.
  - Retail = flags direct via %lo(D_00747A24), s0 = &D_00747A24 set in classFADE_kill's delay slot, flags2 as 4(s0), room/0x5A0 via a2 = s0 - 0x584.
  - Same derived-base question as 002A6DA8 (pending ruling). Also: flags must be int (masks -3/-9/-0x81 as addiu); about 30 callee prototypes still need checking for a handoff.
  - Correction: the early-return unsigned char predicate was already known (func_002B4F38, 001A6FB0 family, entries above). 00304C48 confirms it. displayOmLayer's and 001BE498's open parts are the known "bool in its own register" family (0010B2E8, cSnd_IsEnemyAlive), not a new problem.
- 001f7da0.c (5-function draft), ~12 min:
  - func_002A4BA0: PARKED at 19 vs 21 words. Clean view nm_work/x001f7da0/a1.c: FontSlot (16 bytes, info at 4, u16 at 0xE) and FontInfo (8-byte header + glyph words). This is the cFont_setTextureAddr layout, and sibling 002a4b20.c is ee-2.9.
    - Retail moves base a0->a2 at entry so the masked id lives in a0, copies the row pointer v0->v1, and puts the id==0 return at the end.
    - Inline-helper splits b1-b4 and --drop-reorder under all three compilers: still 19 words.
  - func_002BEAA8: PARKED. Retail: straight-line entry into a do-while with two pointer givs (load and result), n cached in a3, and a nop pad before the loop label. Best is the draft under ee-2.9 (14 diffs): ours moves both return blocks ahead of the loop. Pointer/index forms e1-e5, --drop-reorder and --call-loop-pad don't help.
- func_003978C8 (003978c8.c, ee-2.9, libpad DMA send): PARKED, ~8 min. `PadDma dma[16]` (16 x 16 = retail's 0x100 bytes of locals, only dma[0] sent with n = 1) gives the exact 0x150 frame: 69 -> 67 diffs (a16.c). That may be how the SDK source declares it, but it reads as a placeholder array under the rules, so it needs a maintainer ruling before any handoff.
  - Left: retail keeps port/slot in s2/s0 and recomputes slot*0x1C + port*0x70 (mult/mult1) after SifDmaStat. Ours keeps the combined offset in a saved register. -fno-gcse: no change.
- func_001BE498: permuter rotated out at 13:56 (12 min). Best 2450 from base 3320; every output is steering (`idx & 0xFFu` / `& 0xFFFF` index masks, new_var float and pointer aliases). m1.c (mask alone) is 134 diffs under mc.py. All rejected; PERM=0 confirmed.
- func_00178E18: tail fixed with the shared helper. `cOmHitVolume_initWork(em, 1, em->tableData, 18, 17, 0); em->base.flags2 |= 0x800; em->unk5F6 = 5;` (h1.c) gives retail's exact tail store order: flow deletes the helper's 5F6 = 0 store.
  - 5 diffs left: the 17 and 5 constants come out in a2/a1 where retail has a1/a2. A local helper with a 5F6 parameter (g1) and flags2 before the helper (g2/h3) are worse.
  - The head still uses the draft's steering (cVec v[4] and the size/ofs/rot aliases), like registered sibling 00178368.c. This damage-volume family has no known clean head yet, so this is not a handoff.
  - Clean head attempts (k1-k3, with the h1 tail): k1 (a box local set and struct-copied to size) is 84 vs 79 words / 60 diffs; k2 (cVec_set4 on size/ofs/rot) 72 words / 79; k3 (initializer + copy) 77, plus a .rodata reloc. Retail = all four stores to an unused v[0] via sp, xyz of size/ofs via sp, and each w via the pointer that is later passed to func_001FD9D8. Only the draft's alias form gives that. Parked.
- RESUBMITTED (14:00) func_001299F0, func_0026F328, func_00275888. They were rejected at 13:22 only for header_changes.md format; the solved.c files are unchanged.
  - Re-verified against an overlay of the current include/ with the changes applied (nm_work/hdr_overlay, nm_work/resub): all three MATCH (107/7, 83/2, 60/5).
  - Format is now `## <file>` + `### old` / `### new` blocks; every old block appears exactly once.
  - func_001299F0: vu0.h VU0_SQC2_MEM, inserted after VU0_SQC2_VF0_MEM; cGameObj.h vel at 0x550.
  - func_0026F328: cOmBase.h `#include "godhand/vu0.h"` + cVec_zero after cVec_set4, and src/cod/00302790.c's identical local cVec_zero removed (it would clash). func_00302790 still MATCHes (86/3) with the overlay.
  - func_00275888 has no header_changes and depends on func_0026F328 being applied first (sorted order puts it first).
  - Note: build/SLUS_215.03.map was 0 bytes at 13:58 (a main-agent rebuild). mc.py reported every reloc unresolvable until it came back at 13:59; checks were rerun after that.
- func_001034E0 (001034e0.c): quick sweep only (~3 min). sn and ee-2.9 give 150 words with every flag (drop-reorder, as=sn, -fno-gcse); cygnus gives 156 (154 with drop-reorder) against retail's 159. The neighbouring units are all sn. Retail keeps the branch bodies unmerged (no cross-jump), which no allowed flag controls. Not attempted further.
  - Retried the tail in the registered siblings' explicit order (001a06f0.c: hpMax, hp, table, count, 5EC, 5F6, 5E8, 5E4, 5F0, 5F4) with flags2 in each of the 11 positions. Best is 2 diffs (flags2 at 6-10), i.e. the draft's 5F4/5F6 sh swap again.
  - So it is either the helper form (store order right, constants 17/5 in swapped registers, 5 diffs) or the explicit order (registers right, sh pair swapped, 2 diffs). The head mirrors registered 0019a0b8.c and needs no change. Parked.
- func_002951B0 (14:05): re-examined B.c (43 diffs).
  - Retail loads x, y and z one at a time into the same $v0 and stores objId/entryNo before the conversions, so its order follows the source. Ours hoists the three lh into separate registers.
  - The pattern looks like no first scheduling pass (sched1). That can't be tested here, because --as=sn and --wrap-arg are mutually exclusive, and without as=sn the length is 66/67 words vs 71.
  - Same family as the no-sched2 request (cOmSub_setVibration and others). Parked pending a scheduling-flag ruling.
- func_002769A8 (new draft, 14:05-14:10): PARKED, best nm_work/func_002769A8/j0.c, 137 diffs, 182/184 words (draft: 153 diffs, 180 words, 0xA0 frame). Findings for the next pass:
  1. The draft passes &self->unk2E4 as func_00107C68's third argument, but retail passes self+0x5B0. j0 splits unk2F5 into a field at 0x5B0.
  2. Retail's 0x60 frame (block 2's child count at sp+0, overlapping block 1's offset vector) comes out when each block is its own static __inline__ helper (heldFollowChild / heldFollowHolder): the inlined frames' stack slots get reused. Two block-scope cHeldFrame locals give 0xA0.
  3. The holder index test is a byte bool (slt; andi 0xFF after a join with a preset v0 = 0). An early-return unsigned char predicate gives the andi with bgez instead of bltz-to-join. `return idx >= 0 && idx < n` gives the right shape but no andi, a byte local gives movn, and a nested int inline gives no andi.
     - The call through vtable[11].pfn+delta is g++ 2.95 ABI, so this TU may really be C++ with a `bool` return. That can't be tested because the headers aren't C++-clean (the --lang c++ compile fails in cModel.h macros).
  4. Retail keeps cVec_copy3's d != s test (beq sp, sp+0x20), so ofs and tmp are distinct objects in retail. As fields of one cHeldFrame, gcc folds the test away. Separate locals inside the helper give a 0x90 frame.
- func_0026E7D8 permuter (started ~13:56): ended early. The process was gone by 14:10, probably after the container restart that came with the 14:05 rebuild. Base 450, best 250, and every output under 300 relies on steering (`do { } while (0)` fences, new_var aliases). Nothing usable. Not restarting it, since the remaining diff is the same do-while-fence family.
- func_0017F6C0 (new draft, ~14:10-14:13): PARKED at 5 diffs, nm_work/func_0017F6C0/m6.c (draft: 9). Uses only existing macros.
  - m6 replaces the draft's two-local cVec_assignSub with `cVec_sub(cVec *d, a, b) { cVec r; ZERO_VSUB(&r); LQC2(&r); SQC2(4, d, 0); }` plus a caller-local tmp and cVec_copy3(&f.target, &tmp). That hoists &r (v1) and &tmp (a0) above the asm, as in retail.
  - What remains: retail's memory operands are sp-based (0x30(sp), 0x20(sp)), while ours go through v1/a0, and retail computes v1 before a0.
  - Tried without success:
    - VU0_SQC2_MEM for the tmp store (8 diffs as a two-local inline; 11 with the m5 split).
    - Caller-local r/tmp with explicit macros (10 and 13).
    - The four local declaration orders.
    - A nested cVec_assignSub over cVec_sub (7 with SQC2_MEM, 60 with SQC2).
  - The same subtract sequence appears in func_002769A8's block 1, so a fix here should carry over.
- func_002F6CF8 (new draft, ~14:13-14:15): PARKED at 11 diffs, the same as the draft.
  - Retail keeps the lw 0x220(self) behind both fabs stores (2B8 and 2BC) and then loads data+0x18C. Ours hoists the 0x220 load to the second instruction in every statement order I tried: 24 orders of the four statements, with and without the fromEye local. Best is 10 diffs, with the fromEye store first.
  - Also tried an inline seed setter and an inline range setter (11 each) and a seed pointer local (43).
  - Retail looks like it sees a memory dependence between the float stores and the seed load, maybe because the stores go through a typed field of a different struct. That needs the real self type; the draft is all raw offsets with no header type found.
- func_0013B5F0 (untouched draft): SKIPPED. Its player-state test reads the 64-bit word at player+0x2F0 (`long stateWord` & 0xFFFF00000000), the same question as the pending 64-bit flags-temporary ruling (00276478, 001C20D8).
- func_00158CD0 and func_00158FC8 (untouched drafts): triaged, not worked.
  - func_00158CD0 is 180/185 words with 155 diffs; func_00158FC8 is 132/141 with 135.
  - Both are loop-heavy key-curve searches. The 00158CD0 draft also uses goto ladders and address-suffixed type names (Key158, Curve158, Hdr158), so it needs a rewrite before closing.
  - Low priority.
  - 0017F6C0 diagnostic: with caller-local r/tmp, the asm memory operands are sp-based as in retail (m2). With non-volatile local copies of the three VU0 macros (nv.c), the &r address also moves above the subtract, as in retail. That gives 8 diffs; &tmp for copy3's d != s test still isn't hoisted.
    - Lead for the maintainer: retail's VU0 inline asm may not have been volatile.
    - Changing the shared vu0.h macros is project-wide, so I'm not proposing it from one function.
- func_003219D0 permuter on r2.c (14:14-14:41): GAVE UP. Base 2735, best 1805, and every improvement relies on steering: new_var/new_var2/new_var3 aliases of dst, src and i, `j = j;`, `(i ^ 0) + j`, a dead `if (!new_var->ent)`, and a dst->ent alias used only in the compare. Nothing usable; parked at r2.c's 57 diffs.
- func_0017F6C0 permuter on m6.c (14:41-14:59): rotated out after 15 min without a usable improvement. Base 100 (5 diffs), best 90, and that one needs an unused file-scope `cVec ofs`, a new_var alias of &f.ofs and a duplicated `step = 0` store. Steering, rejected. Stays parked at m6.c.
- 14:59: queue is empty of anything closable without a ruling. Waiting 20 min, then rechecking drafts/, nm_solved/ and PROGRESS.md.
- 15:29: STOPPED on the user's request. Nothing was in progress: the 20-minute wait after 14:59 was interrupted with no function open. No new solves to hand off; func_001299F0, func_0026F328 and func_00275888 are still waiting in nm_solved/ from the 13:5x resubmission. Permuter killed in godhand-nix, PERM=0 confirmed. Waiting for the user's reply.

## 2026-10-22 00:38 new session
- State at start: the three resubmitted handoffs (func_001299F0, func_0026F328, func_00275888) were registered at 20:47, so VU0_SQC2_MEM, cVec_zero and cGameObj.vel are now in the headers. Every draft's mtime moved after 15:00 (a main-agent pass), so I rescanned: 18 drafts not in this log (nm_work/draftscan2.tsv). Map/cache note: build/SLUS_215.03.map went to 0 bytes again at 00:55 and mc rebuilt symaddr.json empty; deleting it after the map returned fixed it.
- func_00137F38 (sn): IN PROGRESS, 2 diffs, clean (nm_work/func_00137F38/m1.c).
  - Rewrite: plain locals `cVec ref, rot; float pathTurn, pathHeight;` (they land at 0x0/0x10/0x20/0x24 as in retail, so the cPathTurnFrame struct goes), VU0_SQC2_MEM for both stores, and header fields instead of the local cCamManager view and offset macros. Local overlay nm_work/func_00137F38/godhand/: cCamManager dist/turn/height at 0x444/0x450/0x460 (split from unk000), PathHost turn/rate/dist at 0x14/0x18/0x1C (split from unk14), PathRec rate at 0x34 and dist at 0x5C (dir becomes `char dir[0xC]` + `float dist`; calcTurn still copies the 16 bytes as one blob). Nothing else reads that padding.
  - Left: retail puts &player->rot in v1 (player->pos still in v0); ours reuses v0. Store macro choices and a cVec_copy inline give the same 2. An inline taking both sources (i1) gets v0/v1 but evaluates &rot before the first copy (9). No allowed flag changes it. Looks like the non-volatile VU0 asm lead from 0017F6C0 (the addiu crossing the asm).
  - func_00137BB8 is itself a draft: `int (AreaList *, float *)`, where AreaList is the same object as PathHost (cur at 0x30 is PathHost.rec).
  - Permuter 00:43-00:58 on m1.c (base 10): no improvement. Rotated out, PERM=0.
- func_00381F18 / func_00383878 (sn, twins): PARKED (~12 min). Retail order is dec, test 0x40000000, inc, shared level tail, then the index arms. a.c (if/else-if chain, tail repeated per arm) gets exactly that order but cross-jumping merges the dec arm's two stores (104 vs 105 words). c.c (index arm returns on its own) gets the dec block right but places the level tail after the index arms (110). The draft's `||` form puts the tests first (106). drop-reorder changes nothing. Same conclusion as the draft: no clean structure found.
- func_0013E0B0 (sn): IN PROGRESS. Needs `fp_hazard_rules: "mtc1,fdiv"` (retail's mtc1/nop/cvt and nop/nop/div.s): 108/108 words, 27 diffs. Typed rewrite t1.c: work entries are cIDBaseEnt (0x3C = posY), cIDBase_getIDWork(cIDBaseObj *, int) / cIDBase_move(cIDBaseObj *) from src/cod/id/cIDBase.c, a cIDBaseSlot view (cIDBaseObj + 8 bytes, stride 0x50) and a cIDTimedSet owner view. Left: register naming and load order in the slope expression (retail j+1 in v1, loads key[j] before key[j+1]). Eight spellings (operand order, casts, an inline keySlope) all 27. Permuter started 00:58 on t1.c (base 905).
- func_00277348: SKIP. Raw m2c-style (char buf[0x20] placeholder, `s1` alias, raw offsets); its stated blocker is the constant 1 held in s0, which needs a banned constant local.
- func_003B3F50 (ee): SKIP, tooling. The split asm records the delay loop's lui 0x10 / addiu -1 as %hi/%lo of an auto symbol D_FFFFF, so relocations can't match from C.
- func_0039CCC0 (ee): SKIP, tooling. Its second poll loop carries the R5900 short-loop pad nops. (The draft also calls func_0039C5B8 with 4 of its declared 7 args.)
- func_00274FE8 (sn): PARKED (~10 min). Retail routes every phase set through one tail (phase v0, sub v1; stores 2F4, 2F5, 2F7, 2F6) and keeps both (2,2) blocks, each jumping to the tail's last store. Brute force of the 24 helper store orders x 3 dying-branch shapes (draft, if/else-if, early returns): 116-139 words, none 120. Same cross-jump wall as func_002B42F0.
- func_00149C20: SKIP. PROGRESS.md's "parameter homed to the stack" blocker (hdr reloaded from sp+0 at every use).
- func_002D34A8: SKIP for now. 99 diffs of loop register allocation; its record doesn't fit the file-local StreamBuf in 001e3858.c (here 0x78/0x7C act as pos/left, 0x74 as a flag), so it needs its own type first.
- func_0030F8B0 (sn): MATCHES, NEEDS A RULING, not handed off. Files nm_work/func_0030F8B0/s11.c (clean, 4 diffs), t1.c and t3.c (MATCH, 121 insns, 20 relocs).
  - Callee finding for main: func_00312DB8 is the g++ 2.9x STL `__find(first, last, val, random_access_iterator_tag)`. Every caller sets a3 = 0 (the empty tag's slot), so its definition in src/cod/00312db8.c should take a 4th, unread parameter. The draft's 3-parameter prototype with 4-argument calls didn't compile.
  - Fixes from the draft: the erase as SGI STL `vector::erase` (`if (pos + 1 != end) copy(pos + 1, end, pos); --end;` with copy = memmove of `sizeof(T) * (last - first)`), the find result passed straight into the erase for the 0xC38/0xC58 lists, and the flag update as an else-if chain with `it++` in each arm (gives retail's merged `addiu; b; sw` tail). That is s11, 4 diffs.
  - Left: retail loads D_00754C50 only after the 0xC38 list's `--end` store; ours hoists it. That is GCC 2.95's fixed-scalar vs varying-struct alias heuristic: the global load must not be MEM_SCALAR_P. It matches when the load is an aggregate access: `extern ObjVec *D_00754C50[1]` (t1) or the tree's existing `extern char D_00754C50[]` read as `*(ObjVec **)D_00754C50` (t3, as in 0030eee8.c). Both are type changes made for codegen under the rules, so not handed off. Retail has separate 4-byte symbols at C30/C38/C50/C58 (no table), and the tree declares these globals five different ways (char[], char *, SideCounter, cMcObjList *, ObjList *).
  - Also blocked by scope: a typed version needs cGameObj fields (objFlags 0x250, actorId 0x2FE, vt 0x214) plus a cGameObjVt delete slot at 0x8/0xC, which is in the open PR's header.
- func_00320AE8 (ee): SKIP. Only matches through banned forms: the walk is a backward-goto loop (body/next labels), the key update uses `long` temporaries, and the draft keeps retail's dead `lb; li 2` tail with an empty `if (... == 2) {}`.
- func_003B0EF8 (ee): SKIP. Needs the per-file extern_double setting for its rodata doubles, which is not on the approved list.
- func_00300458 (sn, as sn): PARKED again (~15 min). The draft already has retail's shape (control flow, switch compare tree, strength-reduced slot pointer); retail's loop.c moves `kind < 2` and the constants 1/2/3 into s2-s5, ours moves only 1. No change from: case 0 merged with default (both orders), `-f=-fno-gcse`, an inline factory helper for the switch (c.c/d.c bring in a madd), ee-2.9 or cygnus-2.96. Same invariant-choice wall as MoveEmitter/MoveEsp. Permuter not tried yet.
- func_00321AD0 (ee): IN PROGRESS. Two prototype/form fixes: func_003A7B48 is `noreturn` (as declared in 003224f8.c/003a7b58.c), which gives retail's `beql; lw n` block and drops the duplicate n load; children indexed as `a[i * 2 + 1]` / `a[i * 2 + 2]` with bounds on `c = i * 2` (retail's `sll a3, i, 3`). nm_work/func_00321AD0/na.c: 147/153 words, 32 opcode-only diffs (tools/opdiff.py); the rest is delay-slot filling and register numbering in the first sift. Outer/sift loop spellings (x_*.c) don't beat it.
- func_001A5208: SKIP, game-object family (cOmBase_childAt / hit-volume spheres; tied to the open PR).
- Draw_Line2 / Draw_Line_sc (0015ef10.c, sn, as sn): IN PROGRESS. nm_work/Draw_Line/sc1.c: `float v[4]` in Draw_Line_sc becomes `cVec v` (placeholder-array rule), same bytes. Draw_Line_sc: 3 diffs, only the preheader order (retail `lui fp, %hi(D_00586B80)` before `&v` and `&pts[-1]`; ours hoists the lui last). Swapping the v.x/v.y lines hoists 0x800 into fp instead (27); `i <= count` and a walking point pointer both worse (84-91). Draw_Line2: 106 vs 103 words; retail rebuilds `&v` at each call, ours hoists it into s3 and needs s8. Direct VU0_SQC2_VF0_MEM(&v, 0) or VU0_SQC2_VF0_AT(v) instead of cVec_zero, and a loop-scoped v/out, change nothing. Both are loop.c invariant choices.
- func_00137F38 (sn): SOLVED, handed off (progress/nm_solved/func_00137F38: solved.c, meta.json, header_changes.md). MATCH 92 insns, 3 relocs.
  - The last 2 diffs were the two quad copies: retail does each as one asm statement (lqc2 + sqc2, destination as a memory operand). New vu0.h macro VU0_LQC2_SQC2_MEM(reg, dst, src), added after VU0_LQC2; a non-volatile version gives 23 diffs.
  - The second parameter is `struct cPlCamera *`: cCamManager_update passes the manager, whose first member is the player camera (func_00138BE8 runs cPlCamera(a0); PathHost is at 0xFF4 via func_00137A48). The writes at 0x444/0x450/0x460 are cam->nextPose.ofs.y / rotOfs.x / dist (0010c930.c sets them to 1.06 / 0.07 / 4.0). So no cCamManager.h change.
  - pathRec.h: PathRec.rate (0x34), dir split into `char dir[0xC]` + `float ofsY` (0x5C); PathHost.turn/rate/ofsY (0x14/0x18/0x1C); PathHost_calcTurn prototype moved into the header (plus `#include "godhand/cOmBase.h"` for cVec). Checked: every function in 00137cb8.c and 00137e70.c still matches with the new header.
  - func_00137BB8 is still a draft defined as `int (AreaList *, float *)`, views of the same PathHost and cVec; declared here as `int func_00137BB8(PathHost *self, cVec *pos)` (same registers, int return unused).
  - Lead, not worked (game-object family, open PR): func_0017F6C0's remaining diffs are the same shape. Retail's tail is `lqc2 $vf4, 0($v1)` (src in a register) then `sqc2 $vf4, 0x20($sp)` (dst as memory), i.e. VU0_LQC2_SQC2_MEM(4, &tmp, &r) after VU0_ZERO_VSUB_XYZ_MEM, instead of m6.c's VU0_LQC2 + VU0_SQC2 pair. Retry once the cOmBase PR lands and the macro is in vu0.h.
- func_001CE6C8 (cEmSink, a cGameObj subclass, so borderline for the family skip): tried VU0_LQC2_SQC2_MEM for cVec_scale3's copies (nm_work/func_001CE6C8/cp/). 23 diffs, worse than a3.c's 8. Retail keeps &work in a1 across both scale calls; that's a different problem from 00137F38's.
- func_00321AD0 permuter on pm.c (na.c without scaffolding), 01:17-01:36: rotated out. Base 3230, best 2630; every improvement (2995, 2985, 2630) wraps part of a loop body in `do { ... } while (0)`, and one also adds an `i = b != base` reuse. Steering, rejected. Parked at na.c (32 opcode diffs). Note: run_perm.sh --kill reported PERM=9 one second after the signal; a listing a few seconds later showed none of them left.
- Draw_Line2 permuter on nm_work/Draw_Line/pm2.c started 01:37.
- Tooling: the first Draw_Line2 run (01:37-01:43) permuted the wrong function. With no func_name, decomp-permuter picked `cVec_unitOf`, a sceVu0.h inline. Killed (PERM=0). permsetup.py now writes `func_name` into settings.toml. Restarted Draw_Line2 at 01:44, base 805.

### Draw_Line2 permuter result (01:55)
- Clean lead from the permuter: declaring `cVec v` before `LineAttr attr` takes Draw_Line2 from 95 differing insns to 11. The remaining diffs are stack layout only: retail has attr at sp+0 and v at sp+0x50. The swapped order puts v at sp+0, so `&v` becomes a plain `sp` copy and is never hoisted. File: nm_work/Draw_Line/o1.c.
- With retail's layout (attr first), the only thing the permuter found that stops the `&v` hoist is `do { } while (0)` between the w test and sceVu0DivVector (score 600). That is banned, so it's rejected.
- No effect (still 95): -fno-gcse; ternary / if-else / reordered `out = 0`; `!(v.w >= 0.1f)`; VU0_SQC2_VF0_MEM directly instead of cVec_zero.
- Parked. Started the Draw_Line_sc permuter (base: sc1, 3 diffs).

### func_003257C8 SOLVED (02:05)
- Six stop-request flag stores. Retail's `addiu %lo` followed by `sd 0(reg)` comes from volatile: combine won't fold %lo into a volatile store (same as func_00328BB0). The header already has D_003C8158/78/88/98 as `volatile long`. Matches on the band's default cygnus-2.96 with no flags (also with drop-reorder).
- Handoff: nm_solved/func_003257C8 (solved.c, meta.json compiler cygnus-2.96, header_changes.md adding D_003C8168 and D_003C81A8 to adxmThread.h as volatile long).
- FLAG for review: D_003C8168 and D_003C81A8 are referenced only here (their server threads aren't in this build). They're declared volatile like the other four stop requests in the same table; without volatile, the %lo folds and the function doesn't match.
- Dependents checked with an overlay header: 00324eb0.c (6 functions) and 003258b8.c (3) still MATCH.

### func_00353348 SOLVED (02:15)
- The draft used a parameter alias (`int p = ptype`) and an if-chain. Retail is GCC's case tree for `switch (work->skipLevel)` rooted at 3: ==3, then >3 to default, then ==2. CSE turns `ptype == 3` in case 3 into `ptype == kind` (the xor). With two case nodes GCC roots the tree at the lowest one (2), so retail must have a third node. An empty `case 4: break;` is that node; it matches with cygnus-2.96 and drop-reorder (15 diffs without the drop).
- Handoff: nm_solved/func_00353348 (solved.c, meta.json cygnus-2.96 + c_flags_drop -freorder-blocks, header_changes.md splitting SfdWork.unk004 to add `unsigned int skipLevel` at 0x74). Not carved yet, so it becomes a new unit src/cod/00353348.c.
- FLAG for review: `case 4: break;` has the same effect as the implicit default. Value 4 fits MPEG picture_coding_type D (I/P/B = 1/2/3), so an explicit no-skip case for it is plausible original source. No other form tried (cases 0, 1, 0+1, explicit default, signed kind) gives the root-3 tree.
- Overlay check: 00353bd8.c (6 functions, a sftim.h dependent) still MATCHES. Callers 00353bd8.c and draft 00353928.c declare `int func_00353348(SftimHn *, int)`, the same as the definition. 003381b0.c calls it with no prototype in scope (older file, left alone).

### Draw_Line_sc permuter (01:57-02:01): zero found, REJECTED
- The permuter reached 0 with `new_var2 = 0x800;` before the loop and `(float)(new_var2 - D_003C1180 / 2)` (a constant held in a variable, banned), plus `new_var = v.x` (not needed: 3 diffs without it).
- Clean tries, all still 3 diffs: an in-loop computed `xofs = 0x800 - D_003C1180 / 2`; `half = D_003C1180 / 2`; `sx = v.x` locals; all 24 orders of the v.x/y/z/w stores (12 stay at 3, the rest are worse). `-(D/2) + 0x800` gives 22.
- So retail's preheader order (%hi(D_00586B80) before &v and &pts[-1]) depends on 0x800 not being an in-loop constant movable. Parked at 3.

### MPV_SearchDelim (cygnus, drop-reorder)
- Clean version (no `p = buf` alias), nm_work/MPV_SearchDelim/a.c: 1 real diff (31 counted from the shift). The case-3 `beq` slot is filled from the fall-through (sltu); retail uses beql from the target (q = p - 4), which means reorg predicted the EQ branch taken.
- Tried, no better: int st (56), returning p - 4 directly (31), inverted case 3 (50), explicit default (31), for loop (31), int c (31), case 0 placed later (44). Queued for the permuter.

### func_00363528 (cygnus): PARKED at 44
- Retail loads dst->data before dst->h in the outer loop, as a preheader copy (scheduled above the first `blez`) plus the latch `bnel` slot. The preheader enters the body with `b` and the h load in its slot. dst is in s5 and mbw in s6; ours has them swapped.
- Tried, all 44: 7 forms of the d expression (operand orders, &data[...], split d = data; d += ...), 24 declaration orders of mbw/mbh/s/d, and 6 assignment orders, each with and without drop-reorder. Putting the load in the loop condition as a diagnostic (`d = dst->data, i < mbw`): 39, still not it.
- Note: retail never sets v0, so the function is void, but caller 003634e0.c (registered) returns its result with no prototype in scope.

### func_0035F970 SOLVED (02:25)
- The draft didn't compile: func_0035FB78 was declared with 1 parameter but called with 3, and the error path used a comma expression. Clean rewrite with separate error returns; cross-jumping merges the two error tails into retail's shared block. Steps (cygnus, drop-reorder): 6 diffs (registers); counter increment before the 0x30 store, 3 (scheduling); 0x30 handle typed `int *`, MATCH. Type-based aliasing lets the scheduler move the handle store between the counter's lw and sw.
- The 0x30 handle really is a pointer: its consumer func_0036CBC0 (0036c8d0.c) takes `int *a0`. sfxlib.h SfxCtx has it as `int unk30`, and changing that ripples into 0035e8.c, so solved.c uses a local view `SfxOpenView` (documented as a view of SfxCtx).
- Prototypes follow the current definitions: func_0035FB88(int) (00325360.c), so the call passes `(int)s`; func_0036CAB0 returns int (0032f938.c), so the store is `(int *)h2`; func_0035FA88 returns void *. D_003EE338 is declared `unsigned char[]` as in 0035fa88.c; the open counter at +0 is read through `*(int *)`, since no header names it.
- header_changes.md (src/cod/00297fb8.c): func_0035FB78 gets two unread parameters plus the house "not read" comment line. Retail moves a1..a3 into a0..a2 before the call, and this is its only caller. All 18 functions in 00297fb8.c still MATCH with the change.
- FLAG for review: the two bridging casts come from legacy int-typed definitions (func_0036CAB0 and func_0035FEF0 return `(int)ptr`; func_0035FB88 takes int). Retyping those definitions to pointers would remove the casts.

### func_00365D90 (cygnus): SKIPPED, same blocker as func_00363528
- Sibling macroblock converter with the same outer-loop entry: dst->base is loaded in the preheader before the first blez and again in the latch's bnel slot, and the preheader enters with `b` and the pitch load in the slot. In func_00363528, a diagnostic with the load in the loop condition (`d = dst->data, i < mbw`) reproduces the preheader load-before-blez but not the rest (39 diffs). Not a shippable form. Both are parked together.

### func_00343E28 (cygnus): deferred
- The draft doesn't compile (func_00344278 is declared with one parameter, called with none). It also uses a goto into a block and an `int w[6]` placeholder for the mwsfcre_CalcWorkStmBuf outputs, so it needs a full rewrite. Low priority.

### func_00366730 (sn): SKIPPED, same family blocker
- Third cftraw-style converter (with func_00363528 and func_00365D90) with the outer-loop shape: the row base `p->data` is loaded before the first exit test and again in the latch bnel slot, never at the body top, and the preheader jumps into the body with `b`. The draft also uses a backward `goto loop` (banned).
- Working theory for all three: in retail's RTL the data load sits in the loop's exit-test region, which expand_end_loop rolls to the end and duplicate_loop_exit_test copies ahead of the loop. That needs the read to be in the for-condition or increment. No natural C form found yet; worth a maintainer look since it affects three functions.

### MPV_SearchDelim permuter (02:03-02:18): ROTATED
- Base 420. Best 200 used junk: an unreachable `c = 4;` before case 3 and `q = p - c`. Rejected. Parked at 1 real diff (the case-3 beq delay slot).

### func_00344948 (cygnus): PARKED, not reworked
- Retail copies prm -> stack info and info -> work one word at a time through v0 (lw v0/sw v0 pairs). prm and work are plain incoming arguments (s2/s1 copies of a1/a2), so alias analysis should separate them from the stack, yet retail doesn't batch. This looks like scheduling or register allocation that clean C can't reach with the allowed flags. Not pursued further.

### func_00330920 (cygnus, drop-reorder; the scan's sn result was wrong)
- On cygnus with drop-reorder, the draft logic is 29 counted diffs (83 vs 81 words), all in the dev copy loop. Retail fills the `fname[j] == 0` exit beqz from the fall-through (daddu a3,s1) and has its loop-top label before the lbu; ours steals the exit block's subu and gets lbu + nop + label. for/while forms of the second loop: no change. Permuter started 02:18 (base pm.c, f1 form).

### func_003431D8 (cygnus, drop-reorder): PARKED at 18 opcode diffs (from 66)
- Progress (nm_work/func_003431D8/p3.c): `mbw = w / 16; mbh = h / 16;` as new locals, `size = (fmt == 2 ? mbw * mbh * 1024 : mbw * mbh * 384) + 0x40;`, and `if ((out[i] = f()) == 0) ret = -1;` loop bodies. Everything except the pool loop now matches, including the func_00344568 loop (reversed, strength-reduced).
- Left: retail's pool loop (D_00758A38) isn't optimized by loop.c. It's entered by a jump to its test (no copied blez pre-test), %hi(D_00758A38) and the i*4 index are recomputed each pass, and there's no strength reduction. GCC does that when it treats the loop as phony or the loop has no loop notes (a backward-goto loop, banned). for, while, and three body forms all get rotated and hoisted.

## func_0036DE80 — PARKED (02:22)
- Decoder-state copy p+0x160 -> info record p+0x58 (cygnus band). Draft 83 diffs.
- s1/s2 (typed DecHn with DecInfo/DecState, pointer locals in either order): 83, same as draft; no load moves past any store.
- s3 (direct p->info.x = p->dec.y): 91; all loads hoisted, s-regs used. Mixed forms s4/s5: 91/90.
- ee-2.9/sn compilers: 90. Retail has pointer bases (v1=p+0x160, a0=p+0x58) AND partial load/store disambiguation; no clean source form found that gives both. Best: s1.c.

### sfmpv_BsearchDelim (00351350, cygnus): PARKED at 72
- Draft (77 under cygnus; the scan's sn score was wrong) uses a goto into a block, which is banned. Clean structured rewrite nm_work/sfmpv_BsearchDelim/b.c: 72.
- Retail: the early hit does `b` to one shared CheckDelim tail (followed by two nops), and the in-buffer hit block sits before the straddle setup. The loop bound compare reuses s1 (p == 0) as i = 0.
- A forward goto to a shared `check:` label (c.c) still gets its tail duplicated: 90 words vs 89. Same unsolved shape as the twin sfmpv_SearchDelim (parked at 79).

### func_00350D08 (cygnus, drop-reorder): PARKED at 6 (prologue only); type-blocked
- Draft 127 (4 opcode diffs). Fixes found, nm_work/func_00350D08/best_clean.c (h1.c):
  - Empty `case 0x40:` and `case 0x80:` (both) gives retail's tree including the dead `addiu v0,0x40` slot: 127 -> 11, 0 opcode diffs.
  - Tail `if (*dist > 0) *flag = 1; return 0;` fixes the v0/v1 diff. h as `SfdHn *` with `buf = h->seek.index` (mwsfd.h, 0x1FC8): same bytes.
- Left: prologue arg-copy order (retail copies h first). Retail lets the 0x1FC8 load float free of the `*dist = 0` store, so the field has an alias set different from int.
  - MATCH (144 insns, 11 relocs) if the field is read as `void *` (h2.c) or as an enum (e1.c). Rejected: func_0034C6D8, func_0034C748 and func_0034C2D0 all use it as an index (a1*116), so it is an int; retyping it only to reorder the load is a banned type change. `const int` read, long/short/unsigned dist: no.
  - All 48 orders of the four entry statements x 2 tail forms: best 4 (buf first) still reorders lw above the dist store.
- Retry if a header checkpoint gives SfdSeek+0x10 a real non-int type (e.g. a CRI enum).

### func_00330920 permuter (02:18-02:21 and 02:23-02:34): ROTATED
- Base 200; ~14 min total, no output better than base. Parked with the earlier notes.

### func_00345848 (cygnus, drop-reorder): IN PROGRESS
- 3 opcode diffs; pure register allocation. Retail: obj s0, err s1, full D_00758B50 address in s0 (case F40), its %hi in a fresh s4 (hence the sd/ld s4 and an alignment nop after the first `b`). Ours: err s0, obj s1, %hi reuses s1.
- No change (158): MWSFSVM_Error from mwsfHn.h / mwsfd.h, obj or hn as pointers, `if (err != 0)`, else-arm order, 4 forms of the obj/hn stores (single store after the if, ternary). s-init/s-block forms worse (163).
- Permuter started 02:35 (perm/func_00345848, base from pm.c).

### func_0034E4B0 (cygnus): looking
- 11 opcode diffs. The hl clamp: retail `lw v0,hl; blezl v0; li v0,1`; ours if-converts to slti/movn in 9 source forms (ternary, if/else, n=1 first, store orders). Draft also holds its locals in a stack struct `v` (layout steering), which would need a rewrite anyway.
- func_0034E4B0: PARKED. Plain locals instead of the struct `v` (l1.c): 46 opcode diffs (ret goes to a register; retail keeps ret at 0x14(sp) next to the address-taken locals). The draft's 11 relies on the struct, and the clamp still if-converts. Not pursued further.
- func_00352298 (cygnus): SKIP, tooling-blocked. Retail's call-free reset loop (`addiu; sh; nop x3; bgez; addiu` with a cc1-filled delay slot) carries 3 short-loop pad nops. Neither ee-as nor sn-as (--as sn) pads it here, and the --call-loop-pad pass only handles call-bearing loops. Not matchable with the current toolchain regardless of C.
- func_00198D40: SKIP, game-object family (cOmHitVolumeSetup).
- 00295380.c: holds only cEmSetParam_updateSetDataPos (already BLOCKED, cvt.w.s); the cCollisionSolid_updateBounds line in its header is stale. Skip.
- func_002A87E8: SKIP, game-object family (cGameObj).
- func_00326890 (cygnus): SKIP, tooling-blocked: retail assembler padded a multi-block zero-skip loop with 3 nops (per draft header); everything after shifts by 3 words.
- func_00354EC8 (cygnus): PARKED (124). Retail reorders the record stores and hoists src/ctx loads above them, yet reloads *out after every store. Diagnostic: the callee declared __attribute__((malloc)) frees the loads but also removes the *out reloads (115 words vs 130), so a unique-pointer explanation doesn't fit. The draft's "no pointer typing reproduces both" stands. Related to func_0036DE80 (same partial disambiguation).
- func_0036AE70 (cygnus): SKIP, 30 opcode diffs; the draft holds a dead store (`acc <<= bitpos;` overwritten on both paths) and would need a rewrite of the bit reader first.

### RECHECK ~02:40: checkpoint seen (src/cod/00137f38.c registered, vu0.h + pathRec.h changed). New drafts 001EB7B8, 002000F8, 001E4970.
- func_001EB7B8 (sn): 10 diffs, prologue only: retail schedules `addiu s0,sp,0x10` (&pos, kept for cVec_copy3's same-pointer test) among the register saves, ahead of the ZERO_VSUB asm; ours puts it after.
  - No change: VU0_ZERO_VSUB_XYZ_MEM (12, worse), split VU0_LQC2 + VU0_SQC2 / VU0_SQC2_MEM (10), local declaration orders (10; pos-first 118), -fno-gcse, drop-reorder. Queued for the permuter.
- func_002000F8 (sn): SKIP for now, 91 opcode diffs (226). Retail bases world fields off &flags5D8.
- Slot2_Execute (001E4970, sn): SKIP for now, 254 words vs 246 (allocation and loop-test copy).
- Type-blocked retries after this checkpoint: none of my type-blocked give-ups touch vu0.h/pathRec.h changes beyond func_00137F38 itself; no retries.
- func_00345848 permuter (02:35-02:50): zero found but rejected. It needs `new_var` copying obj before the call and then reused as a copy of err for the F40 sprintf (a parameter alias). Best non-zero, 145, uses identical `if (obj) strncat else strncat` branches (also banned). Takeaway: retail keeps obj live longer than our clean C does. PARKED at 3 opcode diffs (158).
- func_001EB7B8 permuter started 02:50 (sn, base 10 diffs).
- func_001EB7B8 permuter (02:50-03:05): ROTATED. Best 420 adds an extra func_001EC388 call (semantic change), rejected. PARKED at 10 (prologue &pos placement).
- QUEUE ~03:05: no unlogged near-misses left. Permuter killed (PERM=0). Waiting 20 min, then re-checking drafts/, src/ and headers for a checkpoint.

### RECHECK ~03:25: handoffs func_003257C8 / func_00353348 / func_0035F970 all registered (handoff_log). New drafts 0033D598, 003407A0, 002AD2B8.
### func_0033D598 (cygnus, no drop): 41 -> 4 (prologue save order only), nm_work/func_0033D598/ord3/o_12034.c
- `pad = blkLen - rest - 1;` computed right after rest (a real quantity: padding samples in the last block) gives retail's mfhi-first order and the movn select: 41 -> 70 raw, but 16 opcode diffs from 22.
- Load order obsize, obuf, obdist, blkSmpl, wpos (120 orders brute-forced) and `adx->ndata = ndec * blkSmpl;` after the nsmpl computation: 61.
- Re-reading `prm->nch == 2` in the replay test gives retail's extra `daddu v0,v1` copy (CSE replaces the load with a copy): 61 -> 4.
- Left: retail saves fp before s7 (s7 after s1/s2); ours saves s7, fp, s1, s2. 120 load orders x this, and 4 declaration orders: all 4. Permuter next.
- func_002AD2B8 (sn): PARKED (102, 20 opcode). The fdiv pads are absent at all three div.s sites in our output even with fdiv in the rule set (the first follows a join label); point-loop forms (i<n, !=0, n-- > 0) don't give retail's bnez. Draft's own notes stand.
- func_003407A0 (cygnus): PARKED (57, 26 opcode with a `dl = &w->bufL[w->pos]` local, xd.c). Retail computes &bufL[pos] once and copies it (daddu) for the load while storing through the original; looks like allocation, not source shape. Caching bufL/bufR/pos in locals is worse (80+).
- func_0033D598: SOLVED (98 insns, 3 relocs), handed off to nm_solved/func_0033D598/ (solved.c + meta.json cygnus-2.96; matches with or without drop-reorder, so no flag). The permuter (03:31-03:38) found the last piece: a shared `last = prm->total + blkLen - 1;` numerator for nblk/rest, plus obsize loaded right after it, fixes the prologue save order. Its `new_var` was rewritten as `last` (the round-up numerator, used twice), which also matches. Symbol entry already present. No header changes.
  - FLAG: the replay test reads `prm->nch == 2` although `nch` holds the same value. That re-read gives retail's `daddu v0,v1` copy. Plain C with no steering construct, but the maintainer should judge it.
- QUEUE ~03:45: empty again. Permuter killed (PERM=0). Waiting 20 min.
- func_00273960 (new draft 00273960.c, sn-2.95.3-136; a cEm00 function, not in a skipped family): PARKED (~30 min). Same 181 instructions as retail; the 20 differences are all register choice. Retail allocates self to s0, &to to s1 and &from to s2, and loads &to straight into s1. Ours puts &from in s0 and self in s2, and loads &to through a1.
  - Tried: swapping the from/to declarations, declaring m last, computing len first, `-len`, swapping the zeroing order, moving the len declaration (20-55 diffs or a length change). A static inline ray-end helper makes 184 words; a non-inline one makes 128.
  - Permuter (sn, -j8, ~15 min): base 355, best 80/85. Both need a `cVec *new_var = &to` alias for every later use of &to (one assigns it inside the ChkLine argument). That is a banned alias, so rejected. Work: nm_work/func_00273960.
- func_002DACE8 (new draft 002dace8.c, sn-2.95.3-136, -ffast-math, fp_hazard_rules fdiv; a geometry helper that only uses cOmBase.h for cVec, so not in a skipped family), in progress:
  - Writing the six box tests as one `&&` condition around the hit body gives retail's `c.lt.s` + `bc1f`/`bc1fl` exit shape. The draft's `!(a < b) || ...` early returns invert to `c.le.s`/`bc1tl`.
  - A single-exit `hit = 0; if (...) { ...; hit = 1; } return hit;` puts v0 = 0 in the first branch's delay slot, as retail does.
  - Declaring t before q gives retail's slots (q at 0xC0, t at 0xB0). Now 157 vs 159 words (c_hitswap.c).
  - What's left: retail keeps &p in s3 and &q in s0 across the sceVu0ApplyMatrix calls, so it computes each address once. Ours recomputes it after each call.
  - No change from: direct sceVu0ApplyMatrix(&p, inv, &p), -fno-gcse, -fforce-addr/-fforce-mem (not in the supported set anyway). A flag sweep with the draft's control flow had no length match.
- func_002DACE8: PARKED (~50 min). Best clean version is nm_work/func_002DACE8/best_clean.c, 157 vs 159 words, with retail's control flow, exits and stack slots. It's closer than the draft (161 words, inverted compares) and worth folding into the draft. Missing: retail keeps &p (s3) and &q (s0) in saved registers across sceVu0ApplyMatrix.
  - No change from: declaring p/q as aligned float[4] with direct sceVu0ApplyMatrix calls, or -fno-gcse.
  - Permuter (sn, -ffast-math, -j8, ~15 min): base 2475, best 1700, using do { } while (0) fences only; rejected. Permuter killed, PERM=0.
- QUEUE 04:35: empty after 00273960/002DACE8. Permuter killed (PERM=0). Waiting 20 min.
- sceGsSetDefDispEnv (new draft 00396570.c, ee-2.9-991111): PARKED (~30 min), type-blocked. Best clean version is nm_work/sceGsSetDefDispEnv/best_clean.c, 227 vs 221 words (draft: 235): the interlaced dh goes in its own `dh = ff ? h * 2 - 1 : h - 1;` local.
  - Retail does the DISPLAY x-term adds in 64 bits: dxOfs + 636/656 with daddiu then daddu magh*dx, and dx*2 + 232 with daddiu in the DTV path. The y terms stay 32-bit. Only a u_long cast on dxOfs or an `L` suffix on the x constants reproduces that (223 words with the dh local). Both are banned type changes unless the SDK source really declared those types.
  - Retail also cross-jumps the NTSC and PAL interlaced tails, with the dh ternary evaluated last. No clean variant merges them (switch/dh/ternary forms, drop-reorder no effect).
  - Prototype fix to record for the handoff: src/cod/00396560.c defines func_00396560 (syscall 0x80) as void(void), but callers pass (int mode, int *dx, int *dy, int *dw, int *dh). The syscall stub's bytes don't depend on its parameters.
- func_00323050 (new draft 00323050.c, cygnus-2.96 with drop-reorder; ADXF, not in a skipped family): PARKED (~20 min), type-blocked plus structural. 248 vs 265 words.
  - Type block: the draft declares D_003EB838 as signed char * and D_003C5298 as unsigned char *. 00322c68.c and 00322f80.c declare them int, so adxf.h needs one pointer type for each before this can be handed off.
  - Structure, retail vs ours:
    - The header check builds buf+4 as `addu a3, buf, s2`, with s2 = 4 also used for the error store. It builds buf+5 in t0 and re-reads bytes 4 and 5 through those registers for nfile.
    - i is in s1. The loop test `slt s3, i, nword` stays in s3 and is reused for the `if (i < nword)` exit.
    - Every `return D_003EB840` merges into one reload at the shared epilogue.
  - Writing the header reads through `i * 4` (i is 1 there): 248-250 words, no gain.
  - Retry after an adxf.h checkpoint gives these globals real types.
- QUEUE 04:59: empty. No permuter running. Waiting 20 min.
- func_002BEDE8 (new draft 002bede8.c, sn; cRoomSave, not in a skipped family), in progress:
  - The "cvt.w.s vs trunc.w.s" in the draft note is only disassembler naming. Both encodings use funct 0x24, and opdiff shows no opcode differences.
  - The real gap is one instruction: retail adds the em[] offset 0xC after `data + i*0x18`, with the induction variable starting at 0. Ours folds 0xC into the induction start.
  - `em = self->data->em; em += i;` reaches 72 words with 20 differences: (data+12)+t0 instead of retail's (data+t0)+12, the counter updates scheduled earlier, and f3 instead of f0. That reassignment is borderline steering, so I'm not counting it as clean.
  - No length change from: `em = self->data->em + i`, a data local, signed i, walking a src pointer (69 words).
  - Permuter on the draft (~12 min, base 595): no improvement. Restarted it from the emfirst version.
- func_00161D08 (new draft 00161d08.c, sn; God Reel menu, not in a skipped family), in progress:
  - Prototype fix verified: cCoreSave_getReelSlot(cCoreSave *self, unsigned char slot), with the body testing `slot >= 0xA` directly. src/cod/0015fd68.c still matches with it (cCoreSave_getReelSlot and func_0015FD68 both MATCH, using a local header copy in nm_work/reelslot). No registered C callers.
  - With that prototype the draft is 346 vs 347 words. Declaring `unsigned int j` (retail compares j with sltiu and masks only at the call) fixes the inner loop shape, at 342 words.
  - Open: retail doesn't strength-reduce D_003BD938[i] in the outer scan. It keeps s1 = i*4 and reloads base + s1 after each call, and computes s5 = i + 1 at the top with `i = s5` at the end. Ours walks two pointers. No change from: continue, while forms, `list[num++] = i` (344).
- func_002BEDE8: PARKED (~45 min). Best clean is the draft, 71 vs 72 words. The borderline best (em assigned then advanced) is nm_work/func_002BEDE8/best_borderline.c: 72 words, 20 differences. Permuter from it (~15 min): base 625, best 375, needing a `do { } while (0)` fence plus a new_var copy of self->data; rejected. Permuter killed, PERM=0.
- func_00201290 (new draft 00201290.c, sn; cDvd, not in a skipped family): PARKED (~25 min), header-dependent plus structural. 284 vs 289 words.
  - The draft's `(unsigned int)` casts on arg6C are banned type changes. The real fix is `unsigned int arg6C` in cDvd.h, tested here through a local header copy (nm_work/func_00201290/cDvd_mod.h).
  - Opcode alignment shows the 5 missing words are all duplicate copies of &self->job[0] (self+4): an extra saved s5 = s3 with its sq/lq, a separate t0 = a1 induction pointer with its own +0x88 in the pack loop, and t4/t5 = s3 in the sort loop.
  - A `job = self->job` local (outer test only, outer plus inner, or all uses): 272-284. -fno-gcse: 277. drop-reorder: no change.
- func_00161D08: PARKED (~45 min). Best is nm_work/func_00161D08/v_uj.c (unsigned int j plus the unsigned char getReelSlot prototype), 342 vs 347 words. The outer scan's missing strength reduction is still open.
  - Permuter (sn, -j8, ~15+ min): base 7915, best 6840. Its only change is a chained `HELP_B->msg = HELP_A->msg = cond ? 0x20BB : 0x20BC`, which is legal C but makes the function shorter (338). No usable gain. Permuter killed, PERM=0.
  - The prototype fix cCoreSave_getReelSlot(cCoreSave *self, unsigned char slot) is verified independently and should go in with whatever closes this.
- cCamera_update (new draft 00138740.c, sn): SKIP, tooling. The draft identifies retail's context-dependent 0/1/2-nop padding of div.s, which no fp_hazard_rules set reproduces. Same wall as func_002AD2B8.
- QUEUE 05:44: empty. Permuter killed (PERM=0). Waiting 20 min.

## func_00159AD0 — PARKED (register-class wall around the ceiling of t)
- sn-2.95.3-136 with fp_hazard_rules=mtc1,fdiv: same length as retail (179); the only differences are the ceiling block and the one-word shift after it (37 words).
- Retail keeps the cvt.w.s result in an FPR (cvt.s.w $f1,$f0, then mfc1 $s1) and skips the increment with bc1tl/nop. Ours always does mfc1/mtc1 through a GPR and uses bc1fl with addiu in the delay slot.
- Tried without success:
  - the comparison swapped; an if/else (183); `frame += (cond)` (183); `!(==)`;
  - frame as int (42 diffs); a float temporary (177-183); an assignment inside the condition;
  - cygnus-2.96 (same wall); rules mtc1/div1/fdiv/div/cvtdiv/cmpfull/cmppad combinations.
- permsetup has no fp-rules option, so the permuter can't score it. Retry if tooling gains fp-rules.

## func_0013E970 — SKIP (tooling)
- The remaining difference is the div.s padding/hazard wall; no supported fp_hazard_rules option reproduces it. Retry if the hazard tooling changes.

## func_002FE8A0 — PARKED (159 vs 157 words; register allocation)
- Best clean form: nm_work/func_002FE8A0/best_clean.c. The draft started at 149 vs 157 with 147 differing words; this form has 96.
- What got closer:
  - `vtx` as `int (*vtx)[4]` instead of the invented QuadVtx struct. Retail reloads the screen globals after the vtx stores; a struct store lets GCC 2.95 assume a varying in-struct address doesn't alias a scalar global. All callers pass global 4-vertex GS buffers (D_0061B500, D_0061B6A0, D_0061B760). FLAG: type choice.
  - Store x/y into vtx as they are computed (`vtx[i][0] = x = ...`).
  - A walking `cVec *p` alongside i, which removes the extra &v[i].y pointer.
  - Chained `v[0].w = ... = 1.0f; v[0].z = ... = 0.0f;`, which gives retail's mtc1 zero/swc1 z stores.
  - z/w stores at the end of the body, with the `bottom` update first; this hoists 0xFFF00 like retail.
- Still differs:
  - %hi(D_00586B80) is re-materialized; retail reuses it across the range check (1 word).
  - We spill `bottom`; retail spills `left`.
  - Counter registers and the layout of the fail branch.
- Sweeps:
  - Counter/zw orders (360 variants): no exact form.
  - Permuter run 1: best 2920, by a global ++/-- pair and a change to what the code does. Rejected.
  - Permuter run 2: best 2890, by reusing counters as scratch, which changes what the code does. Rejected. Clean base is about 3335.

## func_00366110 — PARKED (scheduler tie on the ramp-loop stores)
- cygnus-2.96 with fp_hazard_rules=cmpfull: same length as retail; only the 4 halfword stores in each ramp loop differ (8 words). The best store order (r,b,g,a and others) gets this to 4.
- Measured scheduler rule across all 24 source orders: the last `v` store is always scheduled first and the rest keep source order. So the output always starts with a `v` store, but retail starts with the alpha store (a,r,b,g). No source order reaches it.
- Tried without success:
  - chain assignments (4 orders), int v / (short) casts, int alpha params, an unsigned alpha field;
  - a walking entry pointer; the alpha store at the top of the loop;
  - other rule combinations; the ee-2.9 and sn compilers (wrong length).
- Probably needs a different body structure that keeps v live past the stores; nothing natural found.

## func_00366368 — PARKED (same wall as func_00366110)
- With cygnus-2.96 and cmpfull, 15 words differ: the same ramp-store order, plus v0/v1 swapped in the head loop (-0x488 level vs pointer).

## func_002956F0 — PARKED (load narrowing, FPU register allocation, kind-flag copy)
- Correction to the draft note: cvt.w.s vs trunc.w.s is not a real difference (same 0x24 encoding; the objdump label is misleading).
- Best clean form: nm_work/func_002956F0/best_clean.c (ternary vital store; same length, 57 differing words).
- Still differs:
  1. Retail stores objNo/seBank from full-width loads (lhu 0x2FE, lw 0x564); ours narrows to lbu. Retail's actorId reload after the call looks like a REG_EQUIV reload of a pseudo set before the call.
     - An actorId local lands in s2 instead; `- EMSET_OBJ_BASE` is folded away.
  2. The kind flag goes through a0 before `andi 0xff`.
     - The draft's helper is closest; a result variable gives movn, and `&&` gives a range check.
  3. Retail converts in place (cvt.w.s $f0,$f0) and loads lwc1 before the constant; ours converts into f2.
  4. Retail reads vital once (lh a0 + blezl); ours reloads with lhu.
- Merged return conditions and the mtc1/cvtdiv/fdiv rules change nothing.
- 2026-10-22 06:50 queue empty after 00159ad0/002fe8a0/00366110/00366368/002956f0; waiting 20 min (permuter PERM=0).

## func_002C45A8 — PARKED (s0/s1 swap: no vs self)
- sn-2.95.3-136, same length; the only difference is that retail allocates `no` to s0 and `self` to s1 (29 words).
- Tried without success:
  - wrapping the body in `if (!self->jumping)`;
  - `no` first or `angle` before `no` in each case.
- Permuter reached 0 only with forbidden constructs: `new_var = 0x4D` constant locals, an `if (self)` with identical arms, `ofs.x * 0.0f`. Rejected.
- Real fix unknown; retail `no` probably has higher allocation priority from some source shape we haven't found.

## func_00329490 — PARKED (missing cross-jump of the two error calls)
- Use --drop-reorder, as every CRI neighbour does (c_flags_drop -freorder-blocks). That gives retail's block layout: inline parameter-error block, bnel search loop.
- Remaining: retail's parameter-error path branches into the too-many-handles path's `jal func_0033F130` (shared call with a nop delay slot). Ours keeps two calls, so it is 200 vs 198 words.
  - The compiler does cross-jump in 00323cf0.c, where the error blocks are adjacent.
  - Here it doesn't, even with the fail path removed (diagnostic only).
- The for-loop and `>=` search variants don't help. The store schedule in the buffer setup also differs.
- 2026-10-22 07:14 queue empty after 002c45a8/00329490; waiting 20 min (PERM=0).
- 2026-10-22 07:20 queue empty after 002c45a8/00329490; waiting 20 min (PERM=0).
- 2026-10-22 07:41 recheck: nothing new; waiting 20 min (PERM=0).
- 2026-10-22 07:54 recheck: nothing new; waiting 20 min (PERM=0).

## func_0032A1B0 — SOLVED (handoff in progress/nm_solved/func_0032A1B0/)
- cygnus-2.96, c_flags_drop -freorder-blocks (like every CRI neighbour), fp_hazard_rules libm-mtc1,cmpfull. MATCH: 189 insns, 29 relocs.
- Fix: in the playing branch, `*ncount += (int)(adxt->baseCount + 1);`.
  - Without the conversion, fold reassociates `n + (baseCount + 1u)` into `(n + baseCount) + 1`.
  - FLAG: the cast converts the unsigned sum to *ncount's own type (int). It is a real conversion, not a cast on a constant, but review it against the type-change rule.
- No header changes. Externs follow the callees' definitions: Obj3270_GetVia4_* take void* (003270.c); Obj0000_PostInc_D_003D1428_32A148 is int(void) (000000.c).
  - func_0032A018 is declared with this file's handle view (AdxtTimeHn *). Its definition in 0032a018.c uses its own view (AdxDecHn *); there is no shared ADXT handle header.
- NOTE for maintainer: config/symbol_addrs.txt has no func_0032A1B0 entry; add `func_0032A1B0 = 0x0032A1B0; // type:func` with the registration.

## cSnd_UpdateListener (draft 002cc150) — SOLVED (handoff in progress/nm_solved/cSnd_UpdateListener/)
- sn-2.95.3-136, no extra flags. MATCH: 152 insns, 17 relocs, verified against the header changes through a local overlay (nm_work/func_002CC150/hdr_test).
- Header changes (header_changes.md):
  - add `cVecQuad` (`typedef struct cVec cVecQuad __attribute__((aligned(16)))`) to cOmBase.h;
  - cSnd.h includes cOmBase.h, and listenPos becomes cVecQuad.
  - Safe because no other unit uses listenPos, no header includes cSnd.h, no src/draft defines its own cVec, and the name cVecQuad is unused. (cVecQ was taken by a different local typedef in drafts/cod/0031c5c0.c.)
- What closed it:
  - The listener flags are read into an `unsigned long` local, as in cEvent_updateRelease, with a separate branch per bit and the bit-6 test written as `((flags >> 6) & 1) == 1`. Retail's dsrl proves a 64-bit value.
  - `mode = self->f110; if (pl == 0) mode = LISTEN_AT_CAMERA;` produces the movz.
  - Two static inline helpers: unitMatrix(m), and subVecXYZ(out, a, b), which returns out and uses VU0_ZERO_VSUB_XYZ_TO.
  - The camera-target copy is a u_long128 store; a struct store doesn't reload D_005CAFF0 the way retail does.
- FLAGS for review:
  - (1) `unsigned long flags`: precedent on main, but it is a wider local.
  - (2) The if/else-if ladder repeats `f110 = LISTEN_AT_CAMERA` in three arms. No two arms of the same if are identical; the `||` form folds the two masks together (150 words).
  - (3) `*(u_long128 *)&...` pun with a local `u_long128` typedef, the same as 00396158.c and 003bad80.c.
  - (4) func_0030A548 and the sceVu0 Add/Scale/CameraMatrix prototypes stay local (void*, matching their definitions). sceVu0.h can't take them yet: 001b5160.c declares func_0030A548(void) and includes sceVu0.h, and 002d4ef8.c/00138648.c declare the sceVu0 ones with cVec* parameters.

## func_003AD348 (fdlibm __ieee754_fmod) — SKIP (tooling)
- as=ee gives 3 diffs.
  - Two are the `dli 0xffffffff` expansion inside the INSERT_WORDS register union: ee-as emits lui 0xffff, retail has addiu -1.
  - The third is bgtz vs bnez on the fixed-point loop. Stock `while (n--)` changes the loop shape (+2 words).
- as=sn fixes dli but drops the R5900 short-loop pads on the call-free ilogb loops (262 vs 273 words).
- as=gnu is not available for SN units.
- Needs a wrapper route that pads short loops AND expands dli as ps2eeas/GNU does (or a short-loop pad option on the sn route). Not a C problem; revisit when tooling lands.

## cFont_setTextureAddr (draft 002a4cb0) — PARKED
- 21 diffs, all register allocation. Retail copies font to v1 at entry, builds the slot address in a0, and stores info through a v0 copy.
- No effect (all 21): index forms `((cFontTexSlot *)font)[slot]`, `&...[slot]`, a slot-table view, and inline texSlot/texSlotSet helpers.
- Inline validity predicates make it worse (84 vs 82 words).
- Permuter run1 (perm_run1): best 260 from 470, only through `info->b7 == (info->h2 * 0)` plus a do-while (forbidden). Other hits are new_var hoists of info->h2 or res->w4 (forbidden).

## sceGsSetHalfOffset (draft 00396048) — PARKED
- ee-2.9-991111 (the neighbouring libgraph units use it). 26 diffs, same instructions, scheduled differently: retail computes the y half first, with scissor and h in v0.
- Statement reordering changes nothing. Single-expression and if/else store forms are longer. The halfoff `if (halfoff) ofy += 8` form is 32 vs 34 words.

## cEmManage_SetEmAnger (draft 00291b90) — PARKED
- 108 vs 110 words. Retail's two absolute values are `bc1f` with `mov.s` in the delay slot and then neg.s into a separate register; every form here gives bc1tl with neg.s in place.
- Forms tried for the abs: ternary, inline absf, `ady = (dy = ...)` (the idiom that matches in 0014b640.c), and an ABSF macro on the expression.
- A clean for/continue rewrite with an isAngerKind inline folds the range check to an unsigned compare (103 words).
- Needs real cleanup in any case: AngerEm/AngerEmNode local views instead of the enemy headers, a goto ladder, and ok/tt temporaries.

## cScenario_execUpCutData (draft 002c4150) — PARKED
- sn-2.95.3-136. 29 vs 30 words, 17 diffs. Retail copies the cScenario_taskExec_2C3890 result into t1 (the slot parameter's register) and indexes from there; ours keeps it in v0.
- Note: the draft has no section attribute, so mc.py reports "no section" until one is added.
- No effect (all 29 words): works indexing forms (including 002c3c10.c's `(cTaskWork *)(v * TASKMGR_WORK_SIZE + (int)works)`), a new local for the result, a switch on asTask, an early return, and the assignment inside the condition.
- Permuter run1: score 0 only by inserting `if (1) { do { } while (0); }` before the call (forbidden). A block or loop-note boundary there is what changes the allocation.

## RoundFloat (draft 00157498) — SKIP (compiler)
- Retail computes (float)(int)x twice and keeps the int in an FPR both times (cvt.w.s, then cvt.s.w). sn-2.95.3-136, ee-2.9-991111 and cygnus-2.96 all emit one trunc.w.s with mfc1/mtc1 through a GPR.
- Only 4 functions in the binary have the FPR-only round trip, and none is matched, so there's no C idiom to copy. Draft also lacks the section attribute (mc "no section").

## func_00365EC0 (draft 00365ec0) — SOLVED
- cygnus-2.96 with -freorder-blocks dropped. MATCH (148 insns, 1 reloc); handoff in nm_solved/func_00365EC0.
- What closed it: retail's down ramp starts its counter at `lo + (hi - lo)`, so the source is `(range - (i - lo)) * scale` with `range = hi - lo` shared with the scale division. That restores the strength-reduced counter and the lo/tbl/hi -> s0/s1/s2 allocation. Also `if (mode == 1)` with the down ramp first.
- Steps: draft 150 words (146 with drop-reorder); `int left = hi - i` per iteration made the length equal (38 diffs); the range form matched.
- Callee func_00360D50 is `int (void)` per src/cod/0031f4e0.c; it's only used here, so the prototype stays local. Symbol entry already exists. No header changes.
- Tooling note: `--wrap-arg=-Werror`/`-Wall` reach cygnus cc1 as a bare `error`/`all` argument and fail, so warnings weren't checked with that compiler.

## MPV_SearchDelim (draft 00369370) — PARKED
- cygnus-2.96 --drop-reorder. Case order 0123 gives 67 vs 66 words; the only gap is that retail fills the case-3 beq delay slot with a beql from the target (`addiu s0,s1,-4`). Order 0321 is the same length with 22 diffs.
- No effect: other st types, a default label, case-3 reorders, if-chains.
- Permuter run1 (base o_0123, score 420): no improvement after more than 15 minutes, stopped. Archived at nm_work/MPV_SearchDelim/perm_run1.

## cIDBase_transTex (draft 002aaef0) — SKIP (ABI)
- Passes a struct by value; hits the same struct-passing ABI wall as the earlier skips.

## MoveEmitter (draft 00300628) — SOLVED (review flag)
- sn-2.95.3-136. MATCH (129 insns, 17 relocs); handoff in nm_solved/MoveEmitter. Symbol entry already exists.
- Changes from the draft:
  - Owner test written `ok = own != 0 && (flags & 0x8000) == 0`, which keeps retail's second test and reload. This made the length equal (87 diffs).
  - The `mode & 0x40` arms are swapped so the `ok == 0` test is the fall-through (86 diffs).
  - Types follow the tree: `cVtEnt` from cModel.h with prototyped casts (as in 002fbb78.c), `int` bit arrays, and `unsigned char D_0071B940[]` (as in 00300d20.c and 001612c8.c).
- What closed it: a `flagTest(flags, mask)` inline used for every masked flag test in the function. The inline sets which loop invariants retail hoists (the masks and the D_00741960/D_00741980 bases, but not the D_00741940/D_0071B940 bases), and that gives the mtlo/madd slot address.
  - Found by permuter run1 (best score 575 out of 2575; its output used a generic inline at 5 sites).
  - Bisecting showed only the e->flags and D_00747A84 & 0x4000000 sites change the bytes. Using the helper at all 9 masked tests also matches, so the handoff uses it uniformly.
  - The `(mode >> 6) & 1` bit extract stays a shift; `flagTest(mode, 0x40)` changes the code.
- FLAG for review: the helper is readable and used consistently, but its effect on the bytes is on loop-invariant motion. If the maintainer counts that as steering, park the function instead; the clean form without the helper sits at 86 diffs.
- FLAG: DebugPrintfWrapper isn't in a header. It is defined as `int (int, int, int, int, int fmt, ...)` in 0012bfb8.c and declared `void (..., char *fmt, ...)` in 0012e990.c and 00143b70.c; this file uses the latter. Its return value isn't read here.
- Bit-array comments corrected from this function's logic: a set D_00741960 bit means destroy next frame, a set D_00741980 bit means destroy this frame.
- Permuter output archived at nm_work/MoveEmitter/perm_run1.

## func_001FB1C0 (draft 001fb1c0) — PARKED
- sn-2.95.3-136, 66 vs 69 words. The cvt.w.s vs trunc.w.s lines in the diff are only a disassembler display difference.
- Retail forms the pos[1], pos[2] and yaw store addresses as (i*16 + data) + 0x28A with the field offset kept separate, and computes the address before loading the float operand. extra and flag stores fold the offset normally.
- No effect so far: an inline item accessor (65 words), and a per-iteration item pointer (52 words; it drops the self->data reloads).

## Turn_dest (draft 002da038) — SOLVED
- sn-2.95.3-136 with as=sn and fp_hazard_rules=div, the same settings as the neighbour 002da7a8.c. MATCH (112 insns, 1 reloc); handoff in nm_solved/Turn_dest. Symbol entry already exists.
- The draft's 107-vs-112 gap was mostly the missing as/fp-hazard settings (2 diffs with them). The rest was the final clamp: `d = max < ABS_F(d) ? max : ABS_F(d); return d * sign;`, reusing d instead of a separate r.
- Forms that missed: separate r with `0.0f - d` or `-d`, if/else, an absf inline (mixed with the macro, 2–3 diffs; used for both, 108–110 words), and early returns.
- FLAG: func_003A1648 (newlib atanf, defined `float (float)` in 003a1648.c) is also declared locally in 002da7a8.c with the same signature. There's no libm header yet; a shared declaration would need one.
- Tooling note: in zsh, a `for o in "--as sn" ...` loop passes "$o" as one argument; use ${=o}.
- Follow-up for func_001FB1C0: an inline `&self->data->item[i]` accessor reproduces the unfolded offsets for the pos stores, but it also strength-reduces the item address to a second giv (65 words). Retail unfolds only pos[1], pos[2] and yaw; extra and flag fold 0x28A normally.
- Permuter run1 (base 2270, best 1080): it improved only by dropping a self->data reload (`new_var`), which moves away from retail. Stopped; archived at nm_work/func_001FB1C0/perm_run1.

## MoveEsp (draft 002fb0e8) — SOLVED (same review flag as MoveEmitter)
- sn-2.95.3-136. MATCH (137 insns, 26 relocs); handoff in nm_solved/MoveEsp. Symbol entry already exists.
- Same treatment as MoveEmitter: `flagTest` inline for the masked flag tests, cVtEnt with prototyped casts, and `int` bit arrays with `char D_0061B7C0[]` (the most common declarations in the tree).
- Draft (61 diffs) to 4 diffs with flagTest; then `ok = 0;` moved before `if (paused)` with `if (own != 0) ok = ...` inside it, which matched.
- Without flagTest the matching form goes back to 61 diffs. The same helper being needed in both sibling movers supports it being in the original source.
- The draft's `long t = (int)D_00747A84; ... ((unsigned long)t >> 6)` is replaced with `extern int D_00747A84` (18 files declare it int, 21 unsigned int) and `unsigned long flags = D_00747A84;`. This is the same idiom as main's func_00160F38 and the cSnd_UpdateListener handoff, and it gives retail's dsrl. Declared `unsigned int`, the global costs two extra zero-extension instructions. That test uses plain `&` because flagTest takes unsigned int.
- func_00305C20's real parameter type is cAreaFx, which is local to 00305c20.c. The prototype here uses a forward-declared `struct cAreaFx *` rather than copying the type. Note: 001398d0.c calls func_00305C20 with no prototype in scope (existing issue).
- Bit-array comments corrected as in MoveEmitter (D_0071B840 means destroy next frame, D_0071B8C0 means destroy this frame).

## cCoreSave_spawnItems (draft 001fb330) — PARKED
- sn-2.95.3-136; `--as sn` takes it from 100 to 104 words (retail 106), and retail's mtc1 hazard nops appear.
- Gaps:
  - Retail hoists only %hi(D_007474A0) (in s4) and redoes the %lo add each iteration; ours hoists the full address.
  - Retail adds `(i << 4) + data` with the giv first, the same operand-order problem cCoreSave_initItem on main solved with a raw cast form.
  - Retail loads obj->pos after the multiply.
- D_007474A0 + 0x5B0 is GameWork.room (gameWork.h), and the 0x5B1 byte is its high byte, the same byte func_001FB1C0 reads as D_00747A50[1]. Using `D_007474A0.room` or an inline returning `&D_007474A0` doesn't change the hoisting (101–103 diffs).
- The draft's `gw1FB330` inline and the local ItemVtEnt/SaveItem copies of cVtEnt/cCoreSaveItem need replacing in any eventual match.

## cOl0e_setFake (draft 00173820) — SKIP (family)
- Raw m2c output. cOl0e embeds cOmBase (cOl0e.h), so it falls under the skipped game-object families.

## Queue status
- All 70 unvisited non-family drafts are now either visited or out of scope (59 empty placeholders or drafts without a section attribute). Waiting 20 minutes, then rechecking drafts/cod, include and nm_solved for changes.

## Stop (maintainer request, 2026-10-22 09:16)
- Stopped during the 20-minute queue wait; no function was in progress.
- Handoffs this session in nm_solved/: func_0032A1B0, cSnd_UpdateListener, func_00365EC0, MoveEmitter, Turn_dest, MoveEsp. MoveEmitter and MoveEsp carry the flagTest review flag.
- Permuter killed; PERM=0 confirmed. This session's run directories were moved into nm_work/<func>/perm_runN. The older directories still in nm_work/perm/ are from earlier sessions and were left alone.

## Session 2026-10-22 15:20 (work order: re-sweep jump-table / 64-bit drafts)
- Tooling: nm_work/tools/mc.py regenerated from scripts/match_check.py (adds --extern-jtbl; cache still nm_work/mc). New nm_work/tools/order_search.py: copy of scripts/sa/order_search.py that writes only to nm_work/os and uses mc.py. order_search can't be used with extern_jtbl (all variants share one TU, so the table count is wrong).
- Permuter note: pycparser drops `__attribute__((mode(TI)))`, so 128-bit qword types silently become int in candidates. perm/func_0030E660/compile.sh re-adds it with sed before compiling.

## func_0030E660 (draft 0030e660) — SOLVED (handoff in progress/nm_solved/func_0030E660/)
- sn-2.95.3-136, as=sn, extern_jtbl D_004508F0 (meta.json). MATCH: 422 insns, 20 relocs.
- Started from sceGsExecStoreImage (003958d8.c) with this copy's strings, qword and callees. What closed it:
  - BITBLTBUF and TRXREG are whole u_long words that the code masks itself: `w = sp->trxreg & 0xFFF`, `h = (sp->trxreg >> 32) & 0xFFF`, `switch ((sp->bitbltbuf >> 24) & 0x3F)`, and `(sp->trxreg & 0xFFF) | ((u_long)hh << 32)` for the uncached write-back. The bitfield record sign-extends RRW and schedules the entry differently. The record is a local view `GsStoreImageWords` (comment says it is 003958d8.c's sceGsStoreImage with the two registers as words).
  - IMR: `imr = func_00396008((Tramp_GsGetIMR_3964A0() | 0x200) & 0x7E00);` with `u_long imr`. Only a u_long return on Tramp_GsGetIMR_3964A0 matches (tested 36 type combinations).
  - The final GIF reset stores D_003C3CE0 directly (no iv temporary), and as=sn supplies the retail delay slots and pad.
- Header changes (header_changes.md), both in src: the two IMR wrappers take the SDK's u_long signatures (sceGsGetIMR/sceGsPutIMR):
  - 00150078.c: `extern unsigned long GsGetIMR(void)` and `unsigned long Tramp_GsGetIMR_3964A0(void) { return GsGetIMR(); }` (was void, which dropped the value its callers read). Verified locally: all code/data sections of the unit identical (only .mdebug differs).
  - 00396008.c: `unsigned long func_00396008(unsigned long newMask)` with u_long GsGetIMR/GsPutIMR. match_check MATCH (15 insns, 2 relocs).
- func_003B1F28 is declared `void (const char *fmt, ...)`: retail spills a1..t3, so it is variadic. 003958d8.c and 00331ce0.c declare it `void (char *)`; the bytes are the same either way.
- FLAG for main agent: GsGetIMR/GsPutIMR are declared four different ways (003958d8.c u_int, 003951f8.c u_long, 00150078.c void, 00396008.c int), and the two wrappers are now used by two files each. They belong in one libgraph header (e.g. include/godhand/sceGs.h: `u_long GsGetIMR(void); u_long GsPutIMR(u_long); u_long Tramp_GsGetIMR_3964A0(void); u_long func_00396008(u_long);`). I can't create headers, so solved.c declares them locally with the corrected definitions' signatures.

## func_0012C000 (draft 0012c000) — PARKED (~30 min)
- sn-2.95.3-136, extern_jtbl. Draft 52 vs 53 words, 34 diffs.
- Retail differs in three ways: the default path passes a1 as a register (v0), where ours propagates the constant 0; the tail is a branch (`slt s0; beqz; li 1; li 0`) where ours uses store-flag xori; and cur/want are in v1/v0, the other way round from ours.
- No effect: tail forms (`>=`, an ok flag, returning the compare, `&&`), return types, an inline helper, duplicating the code per case, a `want = 0` default, per-case checks with a shared tail.
- Permuter best (635) needs `count = 1; return count;`, a constant held in a local (banned). Rejected.

## func_002BF420 (draft 002bf420) — PARKED
- 2 diffs: retail emits `li 4` before `li 1`; ours emits them the other way round. An order search over all 24 statement orders and the store-type variants made no difference.

## cOl0e_setFake (draft 00173820) — PARKED (re-sweep for the 64-bit idiom)
- 39 diffs. Retail reuses the constant 1 (already in v1) for the `fake == 1` test. A `long gone` compare is DImode and can't share it; `int gone` shares it but adds a sign extension retail doesn't have. A `long fake` parameter didn't help.
- The tail also needs the mtc1 hazard pad and a different store order.

## func_001F7680 (draft 001f7680) — PARKED
- An inline `gameView()` returning `&D_003BD6E8->view` reproduces retail's 0x1380 pointer (52 diffs, 59 vs 70 words).
- Blocker: retail keeps switch cases 0–3 as separate copies; our cc1 cross-jumps them into one. Reordering the statements made no difference.

## func_001EBB78 (draft 001ebb78, main agent's new version) — PARKED
- 2 diffs: retail loads f12 (args.step) before a0 (m->obj) for SetMotionStep.
- No effect: an inline helper (by pointer and by value), `(&args)->step`, a float return type.
- Every zero-score permuter result reads args.step into a throwaway float temp (`new_var`) or adds a dead `if (args.step)`. Both are banned; rejected. Output in nm_work/perm/func_001EBB78.

## func_002B4228 (draft 002b4228; func_002B42F0 in the same draft was given up earlier) — PARKED (tooling)
- The C is final. Its only diffs are divide pads:
  ```c
  win->step++; rest = 6 - win->step;
  t = (float)rest / 6.0f; t2 = (float)(rest * rest) / 36.0f;
  win->alpha = t2; win->scaleY = win->scaleX = 2.0f * t - t2;
  return win->step == 6;
  ```
- Retail pads its two div.s sites differently: one nop before the first, which directly follows its `mtc1 at,$f0` (as=sn puts that nop in by itself), and two before the second, which comes while the first divide is still in flight.
- Every wrapper rule applies one depth to every site, so all 64 combinations of mtc1/fdiv/div/div1/fpfence, with and without as=sn, miss (best: 7 diffs with mtc1,div; 1 missing nop with as=sn,div1).
- To close it the wrapper needs a new rule, for example "two nops before a div.s that follows another div.s within its latency, none otherwise". That is a wrapper change for the main agent or the maintainer; it would need verifying across the 62 div1 sites.

## 002956f0 — skipped: cvt.w.s (waiting on maintainer)

## 00366368 — skipped: off-limits (CRI middleware range 0x322000–0x36FFFF)

## cSubScr_SubScrOn (draft 00160020) — SOLVED (handoff in progress/nm_solved/cSubScr_SubScrOn/)
- sn-2.95.3-136, extern_jtbl D_0041F0B0 (meta.json). MATCH: 109 insns, 10 relocs. Verified against a local copy of gameWork.h with the header change applied.
- What closed it:
  - One `unsigned long f` read of flags5E4 shared by all five early-out tests (the lw + dsrl idiom), with the shifted bits named (`bit = (f >> 6) & 1; if (bit != 0)`). The draft's per-test reads added a register copy; testing the shift directly added sign extensions.
  - Copy order saved5D8, saved5E0, kind, depth (order search over 24).
  - OR order: the six flags5D8 ORs, then flags5E0, then flags5E4 (search over 56 placements).
- Header change (header_changes.md): gameWork.h gains `unsigned int flags5D8` (0x5D8) and `unsigned int flags5E0` (0x5E0), split out of pad5D4. No other file names pad5D4. This replaces the draft's GameWorkView and its `extern char D_007474A0[]`, which contradicted the header's GameWork type.
- The flag tests and ORs read through `GAMEWORK_AT(field)`, a named macro that takes the header's field name and reads it through its constant address. Plain `D_007474A0.field` access anchors on D_007474A0 instead of the field (+20/+23 diffs); the macro's comment gives the reason, as with IDWORK_F1C. The two copies use plain field access.
- FLAG for main agent: the callers 002006b8.c and 001f7900.c declare `void cSubScr_SubScrOn(void *scr, int a, int b, int c)`. The definition takes `(cSubScr *, int, unsigned char, unsigned char)`; retail masks a2/a3 at entry. Both callers pass constants, so their bytes don't change. Once registered, a shared prototype (with cSubScr in a header) should replace the two local declarations.

## func_002BEDE8 (draft 002bede8) — skipped: cvt.w.s (waiting on maintainer)
- Retail converts the three positions and the rotation with cvt.w.s (0x46000024); our compilers emit trunc.w.s. A second gap is the em[] offset: retail starts the induction value at 0, not 0x0C.

## func_00285C58 (draft 00285c58) — PARKED (~20 min)
- sn-2.95.3-136, extern_jtbl D_00448AD0. Draft at 7 diffs, all in the 0x200..0x2FF actor-id test.
- Retail: `slti v0,id,0x200; bnez; daddu a0,zero,zero` / `slti v0,id,0x300; daddu a0,v0,zero` / `andi v0,a0,0xFF`. The 0/1 result is kept in a separate variable and masked.
- Closest: an inline helper with the bounds as parameters, `static inline unsigned char inRange(int v, int lo, int hi) { return lo <= v && v < hi; }`. RTL-level inlining keeps the two compares unfolded. It comes out one word short: the compare writes the result register directly and the andi is dropped.
- No effect: constant-bound helpers (all fold to the addiu/sltiu range test or if-convert to movn); every combination of value/bound/return type over int/short/unsigned short/unsigned int and unsigned char/char/signed char/unsigned short; early-return, ternary, ifelse, init and nested bodies; callers using `!= 0` or `== 1`; a C++ `bool` build (as a check only).
- 001d0818 (cOmWeapon_SetBreak) has the same 0/1 + andi 0xFF shape. A fix for one likely fixes both.
- Note: the draft's `char frame[16]` placeholder and the EM00_DAMAGE_TAKE raw offset would both need replacing in a handoff (cEm00.h field at 0x670, real frame type).

## func_00201290 (draft 00201290, cDvd) — PARKED (~25 min)
- sn-2.95.3-136. Draft 284 vs 289 words.
- Retail keeps &self->job[0] in s3 and a second copy in s5 (frame 0x100, one more saved register). The packing loop's state test indexes that copy (`s5 + i*0x88`); the copies index from self.
- No effect: a local `cDvdJob *job = self->job` (all loops, first loop only, state tests only, plus cur/startJobHeap); per-element dst/src pointers; `continue` form; copy-after-search form (290 words, wrong layout).
- Permuter run (perm/func_00201290, base 1575, best 950 after ~8 min): the 950 candidate reads the state tests through an inline accessor `inline_fn(self)[i].state` returning `self->job`. That is the same kind of accessor as gameView() in 001F7680; a named accessor could be legitimate if one exists in the original. Not pursued further yet; rotated to cOmWeapon_SetBreak.

## func_001F0A28 (draft 001f0a28, ColiseumBattle) — PARKED
- 14 diffs, all the same pair in each of the 7 wave arms: retail stores D_00586AA5 before the stack action byte; ours stores the stack byte first. Source order changes the lui/li order but never the store order; `char` vs `unsigned char` for both made no difference.
- `char buf[0x10]` is the same action-record idiom main uses (001f15c0.c, 001a4430.c), so it can stay.
- Next step: a permuter slot.

## func_001F0A28 (draft 001f0a28, ColiseumBattle) — SOLVED (handoff in progress/nm_solved/func_001F0A28/; replaces the PARKED entry above)
- sn-2.95.3-136, extern_jtbl D_0042BEA0 (meta.json). MATCH: 116 insns, 33 relocs. Verified against a local copy of cEmWrap.h with the header change applied.
- The store order came from wrong callee prototypes. The draft declared `void cEmSetParam_setEm(cEmSetParam *, int)`; its definition (enemy/cEmSetParam.c) is `cEmActor *cEmSetParam_setEm(cEmSetParam *self, unsigned char no)`. With the real prototype, retail's D_00586AA5-first order comes out. (The permuter found it by trying non-void returns; the fix is the real signature.)
- The action record is a cEmWrap handle. FindResolveActor_295978 reads byte 0 (lbu) as cEmManage_GetEm's key and stores the actor at 4. `char buf[0x10]` becomes `cEmWrap wrap; wrap.entryNo = n; cEmWrap_StartAction(&wrap)`, declared `void (cEmWrap *self)` as in cEmWrap.c.
- Header changes (header_changes.md):
  - cEmWrap.h: `int unk00` becomes `unsigned char entryNo; char unk01[3];`. No file reads cEmWrap.unk00.
  - src/cod/001ef8b8.c: ColiseumBattle_DefeatAllEnemies goes from `(void)` to `(ColiseumBattle *self) /* self is not read */`. Every caller passes self in a0. Verified: code and data sections of 001ef8b8.c identical.
- FLAG for main agent:
  - 15 files declare `void cEmSetParam_setEm(void * or cEmSetParam *, int)` and `void cEmWrap_StartAction(void *)` locally: 001a4430, 001f15c0, 001f20f8, 0012c7d0, 0018f488, 0010a2c8, 001b2708, 001f1918, 001895d8, 0012cc70, 001f0e18, 001f1ee0, 001731b8 (StartAction only). Only 001a7f58.c has the real signatures.
  - These belong in cEmSetParam.h and cEmWrap.h, but adding them there would conflict with the local declarations in files that include those headers. As this function shows, the void return can change a caller's bytes, so each caller has to be re-checked when switched. func_001F1918 is on the off-limits list.
- Permuter killed.

## Note on the 0x200..0x2FF "0/1 then andi 0xFF" blocker (func_00285C58, cOmWeapon_SetBreak)
- Main's matched ColiseumBattle_DefeatAllEnemies (src/cod/001ef8b8.c) has the same retail shape and reproduces it with `long ok; ... ok = 0; if (k >= 0x200) { t = (k < 0x300); ok = t; } if (ok & 0xFF)`. That is a long temporary plus an int copy, which the current rules ban. So the shape is reachable, but only through a form the maintainer would have to accept; most likely the original was a C++ bool helper. Both drafts stay parked until he decides. If a clean form is ever agreed, the same helper also cleans up 001ef8b8.c.

## cOmWeapon_SetBreak (draft 001d0818) — PARKED (~30 min; work in nm_work/cOmWeapon_SetBreak/best.c)
- sn-2.95.3-136, extern_jtbl D_0042A930. Draft 3 words short; best now 174 words with 10 diffs, all in the debris loop's child lookup.
- Fixed:
  - The body stores go in the order owner, posPrev.x, posPrev.y, posPrev.z (search over 24 orders).
  - The loop is `i = 0; do { if (childAt(...i + 1) == 0) break; ... } while (++i < COMWEAPON_PIECE_NUM);`, which gives retail's top entry.
  - The lookup tests the index through an early-return helper (`if (v < lo) return 0; return v < hi;`), which reaches the right length.
- Remaining: the same 0/1 + andi 0xFF shape as func_00285C58 (see the note above). Retail sets r = 0 before the branch and has a two-instruction then-block (slt v0; move a0,v0). Every clean form with a preset becomes a movn/movz conditional move.
- Also blocked by scope: retail's lookup is not cOmBase_childAt's code (a separate bool range test), and cOmBase.h is off-limits. A match would need a second shared lookup helper, or a change to cOmBase_childAt once the open PR merges.
- Permuter (PERM_RANDOMIZE on the helpers, base 645): no improvement in 5 min; killed.

## func_00129718 — PARKED (2026-10-22)
- Draft at 159 words vs retail's 181, 110 differing instructions (extern_jtbl D_0041CE10). Every case body is right. Retail cross-jumps the state stores only among the mode 1 cases; each of its twelve mode 0 cases (28..39) keeps its own `li v0,P; sb zero,0x2F4; b tail; sb v0,0x2F5`. Ours merges the mode 0 tails as well (22 words shorter).
- Tried, all 159 words or more and no fewer diffs: phase stored before mode (in mode 0 cases only, in mode 1 cases only, in every case); mode 0 cases first; case labels in numeric order; an inline setState(self, mode, phase) taking int or unsigned char; -fno-gcse (the only supported flag that could matter).
- Blocker: unknown source shape that stops the final jump pass from cross-jumping the mode 0 arms. Still needed for a handoff: pl00.h fields for 0x694 (catcher) and 0x1620 (held sound effect handle) in place of the raw-offset macros.

## func_00262750 — PARKED (2026-10-22)
- Draft is 4 of 140 instructions off (extern_jtbl D_004440E0). In the motion vector block, retail holds &posA in v1 and &delta in v0 for the copy; ours has them the other way round.
- Tried, all 4 diffs or worse: the VU0_ZERO_VSUB_XYZ_TO form; cVec_copy3 for the hit copy; delta in a block scope; an inline vsubTo(out, a, b); VU0_LQC2 + VU0_SQC2_MEM split as in main's cOmBase_startKnockStepF (4); an inline diffOf helper doing both steps (9: hoists &delta into a0); hit zeroed after the vsub (8) or after the copy (11); local test-only copies of the vsub macro with its operands reordered (4 and 6).
- Permuter: about 64 iterations at the base score of 20, then hung with idle workers. Killed.
- Handoff also blocked: GIVE_KIND (0x46) and GIVE_POWER (0x4C), and the 0x40/0x44 stores, need fields in cDamageGive.h, which is off-limits (open objects/minigames PR). cEm00.h needs a field at 0x690 (the cDamageGive pointer). Retry after the PR merges.

## func_001A4010 — SOLVED (2026-10-22), handoff progress/nm_solved/func_001A4010
- MATCH: 129 insns, 5 relocs (sn-2.95.3-136, fp_hazard_rules fdiv).
- The draft's last 2 diffs: the in-place 0.2 scale took its "m" input operand through v0 (the register already holding &unit) instead of 0x50(sp). An input-only memory operand lets cc1 substitute that register; an output operand keeps the stack address. Expanding the helper in place fixes the address but moves the constant load after the copy (5 diffs), so the inline helper stays.
- header_changes.md adds VU0_VSCALE_XYZ_TO to vu0.h: VU0_VSCALE_XYZ_MEM's five instructions with a "+m" in-out operand (named after VU0_ZERO_VSUB_XYZ_TO, the output-operand twin of the vsub). It is a new macro, so no other unit changes. "=m" with or without the "m" input also matches; "+m" is the honest read-modify-write.
- Cleanups against the rules:
  - The private method table (cOm49Vt) is replaced by cGameObj.h's cGameObjVt, called through lockOn with main's `(cVec *(*)(void *))` cast.
  - cOm49 now embeds cGameObj and keeps only 0x5E4 effNo and 0x600 link.
  - The cOm49StepWork struct is split into plain ret/diff/unit locals (same layout).
  - Prototypes now follow their definitions: SetEffectPos takes (int, int, void *owner, cVec *pos, int, float); cSnd_SeCall_2CBA48's fifth argument is void *.

## func_00129EB0 — PARKED (2026-10-22)
- Draft: 151 words vs retail 150, 123 diffs. Best structural lead: `it = begin; while (it != end) { obj = *it++; ...` gives retail's early iterator increment (v0 = it, it += 4, then the load) and its loop shape, but it is 146 words with 139 diffs (fewer continue-path increments; the rest is register allocation).
- What retail does that we can't reproduce:
  - It keeps `om` as a separate copy of `obj` (`daddu s0,s1` before cOm60_ckParent): s0 is used for ckParent and om->base.pos, s1 for setThrow and the flag tests. Our CSE folds the copy in every form tried: a cast, an inline cOm60_isFree(om), setThrow(om), obj->pos.
  - Its loop-invariant choices: it hoists &tmp (s5) for the sceVu0ApplyMatrix arguments and the copy after it, spills &ret to 0x80(sp), and keeps &D_005FEE00 in the loop. Ours hoists &D_005FEE00 and not &tmp.
- Also tried, no effect: splitting the range test and the 0x364 test; one `||` chain for all the skip tests; direct sceVu0ApplyMatrix; inline cVec_applyMatrixTo(out, m, v); an inline cVec_transform with a local.
- Permuter (on the `obj = *it++` version): base 2080, best 1420, only by `new_var = &tmp` (a pointer alias, i.e. steering, rejected). It hung after about 1170 iterations with every worker asleep, the same hang seen on func_00262750. The container's PID 1 is `sleep infinity` and is holding about 2000 orphaned zombies; there is no PID limit, so the cause is unclear.

## func_0012B328 — PARKED (2026-10-22)
- Draft: 160 words vs retail 165, 162 diffs (fp_hazard_rules fdiv,mtc1). Retail keeps &fwd in a saved register across the loop (one more saved register, 0x10 more frame); ours rematerialises it. This is the same loop-invariant/register-pressure gap as func_00129EB0 in the same player code range.
- -fno-gcse: no change here or on 00129EB0 (the wrapper does pass flags; -O0 changes the output).
- Prototype: cOmBase_canCarry is defined in src/cod/0013c618.c (cygnus-2.96) as `long long`. SN cc1 rejects `long long`; `extern long` (64-bit here) is the faithful caller declaration and gives the same code as the draft's `int`. A handoff should declare it `long` and test it `!= 0`.

## func_0028E580 — PARKED (2026-10-22)
- Draft: 144 words vs retail 145. Everything up to the height test matches. Retail does sub.s, abs.s, then loads 2.0 into f1 (reusing the register the sub freed; hazard nop, c.lt.s). Ours gets 2.0 in f2 and sched1 hoists it above the sub.s.
- Tried, no change: `2.0f > fabs(...)`; a dy local; the abs test and the length test in separate ifs; --fp-hazard-rules mtc1 and fdiv,mtc1; --as sn; -fno-gcse. The ternary abs is 158 words (branches; retail has abs.s).
- Permuter: base 230, best 180/190, only by holding 2.0f or 14 in a variable (constants in variables, rejected).
- Handoff cleanup still owed: the private ObjPosVt duplicates cGameObj.h's cGameObjVt. The pair at 0x80 there is lockOn; the draft's getRot at 0x88/0x8C needs a field in cGameObj.h. The cScenario+0x14 byte is a raw offset.

## func_00271518 — PARKED (2026-10-22), best progress/nm_work/func_00271518/best.c: 174 words (right length), 19 diffs
- Stack layout fixed without placeholders: `float mtx[16]` at function level, declared first (retail sp+0), passed as the child-count frame `cOmBase_childAt(..., (int *)mtx, n)`. This is main's idiom (`(int *)vb` in 001b0de8.c). It gives retail's 0xC0 frame with three saved registers.
- Branch layout fixed: `if (self->unk698 != 0) { hit path } else { child path }`, and in the second switch the `default:` body comes before the 0x260/0x264/0x265/0x26A jitter cases.
- Left, part 1 (15 diffs): the first height test. Retail is a three-node case tree (pivot 0x264, then 0x260 below and 0x265 above, each preceded by a 0.4 load, with two copies of the 0.8 store), so 0x264 and 0x265 are not grouped into a range. Results so far:
  - A plain switch groups 0x264..0x265 and pivots on 0x260.
  - The if-chain (best) tests the three values in sequence.
  - These were worse: default 0.4 followed by a switch; separate case bodies for 0x265 or 0x264 (which would also hit the identical-branches rule).
- Left, part 2 (4 diffs): the v0/v1 swap in the vsub block (self->pos in v1 and &diff in v0 in retail), the same as func_00262750. These didn't help: the VU0_ZERO_VSUB_XYZ_TO form (worse) and the VU0_LQC2 + VU0_SQC2_MEM split.

## func_001F8DF8 — PARKED (2026-10-22), best progress/nm_work/func_001F8DF8/best.c: 155 words vs 157
- Two fixes found:
  - `m[12] = m[13] = m[14] = 0.0f;` gives retail's mtc1 $zero,f0 + swc1 (the draft's three separate stores give sw zero).
  - The corner loop as `for (i = 0; i < 8; i++)` over `&pts[i]` counts up from 0 as retail does (153 words alone; 155 with the chained zero).
- Left: retail keeps &w in s0 across the sceVu0ApplyMatrix call (set at entry, used for both arguments and the copy after it). It also writes each corner through its own address register (x at the sp offset, y/z/w through the register), which is what an inline's pointer parameter does when it keeps a register. Ours substitutes the stack address everywhere.

## Finding that applies to several drafts: retail keeps stack-vector pointers in registers (2026-10-22)
- func_001F8DF8 (&w), func_00129EB0 (&tmp, hoisted into s5) and func_0012B328 (&fwd, in a saved register across the loop) all pass a stack vector to cVec_applyMatrix. Retail keeps that pointer in a register (a saved register when a call intervenes) and reuses it afterwards. Our build substitutes the sp offset into each use: integrate.c sets a constant equivalence for FIXED_BASE_PLUS_P arguments.
- Diagnostic only (a pointer alias, not shippable): `wp = &w; sceVu0ApplyMatrix(wp, mtx, wp); copy from wp` reproduces retail's s0 pattern in 001F8DF8. Many matched units on main use cVec_applyMatrix on stack vectors with the folded form, so the original source of these functions differs somehow (perhaps a pointer that really exists in the source, such as a loop cursor or a returned pointer). Worth looking for that shape before retrying these three.

## func_0026B240 — PARKED (2026-10-22), not retried
- Same blocker as func_00285C58: retail masks a 0/1 child-index range result with andi 0xFF. Only the banned `long ok` form (main's 001ef8b8.c) or a C++ bool reproduces it, so this waits for the maintainer's decision on that idiom.

## func_003099D8 — PARKED (2026-10-22)
- Draft: 134 words vs retail 149 (as sn, extern_jtbl D_004501F0). Retail stores the scratchpad packet in source order with each quadword's address materialised on its own, and spills bitbltbuf in a 0xB0 frame. A volatile packet pointer (diagnostic only; scratchpad isn't a hardware-register range, so the rules don't allow it) changes nothing, so the ordering is not a volatile effect. Not pursued further: it is far off and the cause is unknown.

## cOmBase_calcParabolaVector (001b7c48) — PARKED (2026-10-22), not attempted
- 97 diffs from the fixed sqrt.s template (nop/nop/sqrt.s) and the frame-base register. This is the cOmBase subsystem, and the fix probably needs cOmBase.h, which is off-limits while the open PR is in review.

## func_0013DB50 — PARKED (2026-10-22), best progress/nm_work/func_0013DB50/best.c: 207 words (right length), 4 diffs
- Fix found: case 3's second SetColorAnimNormal_2D68D8 call takes a real zero colour (`CustomIDColor off; off.r = 0; off.g = 0; off.b = 0; off.a = 0;`) instead of the literal 0. That colour's pseudo raises register pressure: `on` then spills to sp+0, the frame becomes 0xB0 and fp is saved but unused, exactly as in retail. Case 3 now matches.
- Left (4 diffs): case 2's func_002D69A8 call. Retail emits lui/mtc1 f12, a0, mtc1 f13, then jal with `lhu a1, 0x390(s7)` (flashTimer) in the delay slot. Ours loads flashTimer first and puts the a0 copy in the delay slot.
- Tried, no change: an explicit `(unsigned short)` cast, `self->panel + 2`, integer float literals, a named panel pointer, an inline scale-in helper (three signatures), and the per-unit options fp_hazard_rules (fdiv, mtc1, div+mtc1), as sn, drop-reorder, -fno-gcse, -ffast-math and call_loop_pad. Moving the timer store between the SetDisp calls is worse (11 diffs).
- Permuter: on the draft, its best result passed an unread `new_var = 0` placed in dead code (steering, rejected; it led to the zero-colour fix). On best.c: base 120, no improvement in 3400 iterations.

## func_00241908 — PARKED (2026-10-22), best progress/nm_work/func_00241908/best.c: 196 words (right length), 28 diffs, all in step 1's `done` block
- The draft note "the rest follows retail" was wrong: the draft also differed in step 1's flag ORs and done logic and in the step 3 order (about 100 diffs once the table is fixed).
- Level switch: cc1 groups adjacent cases that share a label before counting nodes, so `case 3: case 4: case 5:` counts 2 and the switch falls under the table threshold. Retail's five-entry table needs 3, 4 and 5 (or 3 and 4..5) on separate labels whose bodies are cross-jumped together. That reproduces retail's table and dispatch exactly, but it means writing the same arm (`timer = 450.0f`) two or three times: identical branches. best.c keeps that split, so even at 0 diffs it would need the maintainer's OK on the repeated switch arms.
- Fixes found (all plain C):
  - `self->emFlags |= 0x10000; self->emFlags |= 0x20000;` as two statements (retail ORs the two constants separately; `x | 0x10000 | 0x20000` folds to 0x30000).
  - Step 3 sets `unk617 = 1` before `hitFlash = 3.0f`.
  - The state reset is `mode, step, stepArg` (sibling 002412a8's order).
  - An inline `emIsDown(cEmActor *em) { return em == 0 || em->vital <= 0; }` gives conditional moves for the partner tests and fixes the length.
- Left: retail builds done as `a1 = 1; done = a1; movz done, zero, (flags & 0x20000000)`, then per slot `beqz slot -> done = 1`, else `movz done, one, (vital > 0)`. That is jump.c's conditional move written straight into done. Ours computes the flag with sra/andi (or sltu) and the helper's result into a temporary, then uses movn.
- Tried, worse or no change: an if form or a `? 1 : 0` form for the flag; `done = 1; if (!flag) done = 0`; char/short done; `!(p && p->vital > 0)`; five other helper bodies (with both flag forms); and the draft's plain `||` test.
- Permuter (10 min, base 2020 because it has no extern table): best 1945, from a dead `done = 0` store (rejected).

## cSceAtUnit_AtInit (002c0d18) — PARKED (2026-10-22), 4 diffs (the draft as is)
- Only the saved-register choice for the last two parameters differs (retail: param3B a3 in s1, actType t0 in s4; ours swaps them). The stores land in the same slots.
- Tried, all worse: all 24 orders of the four parameter stores (the draft's order is best; the next best are 5 diffs).
- Global allocation runs after sched1, so source order only loosely sets the live lengths it ranks by.
- Permuter: base 20, no improvement in 5400 iterations.

## cSaveLoad_openSave (002bf1a0) — PARKED (2026-10-22), 10 diffs (the draft as is)
- Tail only. Retail sets the phase 1 (a1) and the return value 1 (v0) before the busy-flag or, keeps the flag word in a0 and the mask in v1, and stores arg3 before arg2.
- Tried, all ≥10:
  - All 120 orders of the five tail statements.
  - A single exit with an `ok` variable: 17 diffs, and the phase and the return value share one register, which retail doesn't do.
  - An if/else single return (48 words).
  - An inline `cSaveLoad_open(self, slot, mode)` helper: 23 diffs, 50 words.
- Permuter (5 min): its best (score 10) holds the mode constant 3 in a variable set before func_002BF170, which is a constant held in a variable (rejected). So retail has the mode value live across the reset call, but no plain form found produces that.

## SearchData (0031ccf0) — PARKED (2026-10-22), 6 diffs (the draft as is)
- Return operand order: only `(void *)(((int *)pack)[i] + (int)pack)` gives retail's (offset + pack), at 5 diffs, and that mixes int and pointer for one value. Five other return forms stay at 6: the pointer first, `&((char *)pack)[off]`, and unsigned offsets in either order.
- Key setup (retail computes pack + count*4 straight into s0 in the beqz delay slot, then +4) and the compare's argument order: seven key forms stay at 6 or are worse. They were a separate init, `(unsigned int *)pack + count + 1`, `&[count + 1]`, `(count + 1) * 4`, `4 + count * 4`, the init before `found = 0`, and the increment in the body.
- Permuter (8 min, base 100): its best (80) is `key++; key--;` in the loop body (steering, rejected).

## func_001377E8 — PARKED (2026-10-22), the draft as is (149 vs 150 words, 129 diffs, all from the stack layout)
- Retail's vector slots, read from the asm: A@0x00, B@0x10, C@0x20, D@0x30, E@0x40, five in all. Retail saves s5 as well, and ra sits at 0x50; ours uses six slots and ra at 0x60.
  - B = start - center, then A = B. D = end - start, then C = D.
  - D is zeroed and gets unitOf(C), then B = D (B is now u; s3 = &B, s5 = &C).
  - dot(A, B) and dot(A, A).
  - E = B, scaled by t, then D = E. E = start + D, then C = E, and hit = C.
- So each slot holds two values in turn (B: first difference, then u; D: second difference, unit result, step; C: dir, then the hit point). Ours keeps the named vectors at entry slots and puts every inline helper's temporary in one shared slot (0x30, freed per statement).
- Tried: a 16-byte-aligned struct type for every local and helper temporary, to get TImode vectors that take their stack slot only when their address is first taken. The layout didn't change at all.
- Next idea: five named vectors with that reuse would match, but reusing a named vector for an unrelated value probably counts as steering. Not tried.

## func_0030D358 — PARKED (2026-10-22), new draft (extern_jtbl D_00450550): 148 vs 155 words
- The old BLOCKED (jump table) entry is superseded: the draft compiles to retail's table.
- Retail detail, read from the asm:
  - The flags |= 0x44000 goes through hi/lo of D_007474A0+0x584 (splat names it D_00747A24), and CSE then derives &sysData (s1 - 0x30) and the base (s1 - 0x584, for language) from that register.
  - Each of the seven language arms does `lui v1, %hi(D_007474A0); addiu a2, v1, %lo(D_007474A0)` and loads its file name. The cross-jumped tail adds 0x558 separately and keeps the hi half (s0 = v1) for the later base uses.
  - Ours folds &langData into one lui/%lo(sym+0x558) per arm and keeps &D_007474A0 in s0 from the start.
- Tried: -fno-gcse (140 words), a local `GameWork *gw` (143), and an inline `gameWork()` accessor (148, no change).
- Not tried: the 001a7ec0.c pattern (fields as byte offsets from D_00747A24, as main does for the system flag words). It would explain the start but not the arms.

## cModel_calcParts (00149eb8) — SOLVED (2026-10-22), handoff nm_solved/cModel_calcParts (MATCH, 96 insns, 5 relocs; meta: sn-2.95.3-136, as sn)
- Fix: retail's `bc1f` takes the partFlags load into its delay slot and jumps past the bit-4 test's own load. Reorg does that only when the fall-through and the target both start with the same insn, and both loads have to be the `unsigned long f` (lw, sign-extended) read.
  - The plain form, a nested `if (self->blend > 0.0f) { f = part->partFlags; if ((f & CPARTS_NO_BLEND) == 0 && ...) }`, does it.
  - Loading f before the blend test leaves 1 diff (the branch doesn't skip the reload).
  - `((f = part->partFlags) & ...)` in the condition also matches, but its value is overwritten unread: a dead store in a condition, rejected.
- For the reviewer: f (the maintainer's lw/dsrl `unsigned long` idiom for the two bit tests) is also read for the CPARTS_NO_BLEND mask test. An int read there gives a different load and 98 words.
- The callers (002816e0.c, 0012c540.c, 001799f8.c) declare `void cModel_calcParts(void *a0)`, but the definition takes `cModel *self`. A shared prototype in cModel.h would be the follow-up; I left them alone (src/ is off-limits to me).

## func_0028CB90 — PARKED (2026-10-22), best progress/nm_work/func_0028CB90/best.c: 143 words (right length), 20 diffs (draft: 39)
- Fixes found (plain C):
  - The spring term written `-head->rot.x * self->speedRate * 0.5f`. With -ffast-math, fold reassociates multiplications: the draft's `-rot.x * 0.5f * rate` comes out as -rot.x * (0.5 * rate), and `-(rot.x * 0.5f) * rate` negates after the multiply.
  - The pitch-speed update comes before the three look stores.
  - Together these keep 0.5 in $f5 and the rate in $f4, as retail does.
- Left, with no form found:
  - The multiply order in that term: retail is (-rot.x * 0.5) * rate, ours (-rot.x * rate) * 0.5. Not reachable with float literals, `/ 2.0f`, or a double 0.5; eight other spellings tried.
  - The target copy: retail stores it at 0x70($sp) but keeps &target in s0 for the matrix call and the reload. VU0_SQC2_MEM or VU0_LQC2_SQC2_MEM gives the sp form but drops the s0 pointer (141 words). This is the stack-vector-pointer pattern logged before.
  - The atan2 argument load order (x, z, then y straight into $f12) and the final copy3 store order. Five local/look spellings of the atan2 arguments compile identically.
- Permuter (10 min, base 760): its best (580) needs a `new_var` temporary (rejected).
- For a handoff later: 0x15A0 is read as a float speed (`gotoPos.x` in cEm00.h), so it needs a per-class view.

## func_0012A610 — PARKED (2026-10-22), the draft as is (172 vs 177 words)
- Main blocker: retail keeps &at (the reach centre) in s4 from before the matrix call to the distance test in the loop, which also gives the 0x10-larger frame. This is the stack-vector-pointer pattern (see the cross-cutting finding above). The shared `cVec_applyMatrix(&at, self->mtx)` helper compiles identically to the direct sceVu0ApplyMatrix call.
- Absolute value: `if (d < 0.0f) d = -d;` (171 words) and `0.0f <= d ? d : -d` (172) don't help. Turn_dest's argument order wasn't attempted while the frame is off.

## func_00269B50 — PARKED (2026-10-22), the draft as is (294 vs 305 words)
- The only gap is the one the draft names: at each child lookup but the last of its case arm, retail copies the cOmBase_childAt result from $v0 into $a0 and tests that. Ours ties both into one register at every site, so we are short one word at each of 11 sites. The rest of the function matches.
- Tried, none of which gives the copy (all 294 words unless noted):
  - an inline `twistPart(p, angle)` wrapping the null test (288: the angle is evaluated before the lookup);
  - an inline setter called inside `if (p != 0)` (295, but the copy lands in the wrong place);
  - a wrapper inline `emPart(self, frame, idx)` returning the child, as 00194558.c and 001ad5c8.c do;
  - `p` as a function-level variable, a shared function-level `cOmBase *child` copied into the per-site `p`, assignment in the condition, a statement expression, the lookup spelled out by hand (281);
  - five local versions of the childAt body (ternary, result local, early return): 282–294;
  - cygnus-2.96 and ee-2.9-991111 are wrong (they save registers with `sd` where retail uses `sq`); -fno-gcse and drop-reorder change nothing.
- Permuter: not run usefully (the first run was fed the #ifdef'd draft and found no function).

## func_0012B618 — SOLVED (2026-10-22), handoff nm_solved/func_0012B618 (MATCH, 195 insns, 3 relocs; meta: sn-2.95.3-136, fp_hazard_rules fdiv)
- Fixes:
  - The start position is `self->base.pos` (retail reads 0xF0($s0)), not the held object's pos.
  - The fdiv hazard rule gives retail's second nop before the `div.s` (cVec_unitOf). Without it the function is 194 words; with it, the one-word shift goes away.
  - cVec_subTo and cVec_unitTo are `void` helpers, followed by a plain `cVec_copy3(&f.dir, &f.unit)`. The compiler then knows the copy's source is the stack slot and reads it off $sp; the pointer-returning form read it through a register.
  - The subtraction uses VU0_ZERO_VSUB_XYZ_TO (vu0.h's non-volatile form). The volatile _MEM form keeps the temporary's address computation behind the asm, or puts its store through $v0 (2 diffs). The temporary is a local of cVec_subTo (0x50), so the frame record has no `diff` field.
- Cross-cutting: this is the "stack-vector pointer in an s-register" shape. Here it came from inline helper parameters (s1 = &unit, s2 = &u.unit) once the helpers stop returning the pointer. Worth retrying on func_0012A610 and func_0028CB90.
- Draft-header note for the reviewer: pl00ThrowView is still a local view (pl00.h doesn't name 0x640/0x6A0).

## func_00275978 — SOLVED (2026-10-22), handoff nm_solved/func_00275978 (MATCH, 251 insns, 8 relocs; meta: sn-2.95.3-136, as sn; header_changes.md for cEm00.h)
- Fix: no wrapper rule is needed. The SN assembler (`as sn`) puts the c.lt.s → bc1f nop after the shared label itself, as retail does. The draft's C matches unchanged with `as sn` (250 words without it; cmppad was the wrong tool).
- Cleanup for the handoff:
  - EM_AIM (0x1680) becomes a header field `cVec aimPos`, split out of `unk1651[0x3F]` (no unit uses unk1651). header_changes.md has the exact text.
  - EM_PARTNER (0x744) reads the existing `int unk744` field, as 00247e60.c does with `(void *)self->unk744`. Retyping it as `cEm00 *partner` would mean changing 002580b8.c, 00252070.c and 00247e60.c, which pass it as an int to ForwardAnimParamPairByIndex_27EA50 (int, int). That's a follow-up for the maintainer.
  - em_child (the result-in-a-local childAt) stays: the shared cOmBase_childAt gives 246 words.
- Checked: the typed version matches against a patched copy of cEm00.h in nm_work/func_00275978/godhand/, which a quoted include picks up ahead of include/.

## func_002A0C60 — PARKED (2026-10-22), the draft as is
- Retail loads 0xE00 into $s4 with `addiu` and keeps it for the whole function. It uses it as TEX0's TBP0 and shifts it at run time (`srl $s4, $s4, 5`) for the second FRAME's FBP. So the compiler did not know the value there: a constant-folded literal can't produce that.
- The only plain C that does it is a local holding the constant (`int page = 0xE00;`), which the rules ban. func_0029E2C0 (drafts/cod/002a0940.c) has the same shape. Neither is matched on main, so there's no maintainer form to copy.
- Needs: the real source shape (a field or return value that is 0xE00 at run time), or a maintainer ruling on this pattern.

## func_0012AFE8 — PARKED (2026-10-22), best nm_work/func_0012AFE8/Am.c: 2 diffs (draft: 6); needs fp_hazard_rules fdiv
- Best form: void helpers `cVec_subTo(tmp, ret, a, b)` (VU0_ZERO_VSUB_XYZ_MEM, then the quad copy) and `cVec_unitTo(ret, v, tmp)`, as in func_0012B618. That puts `addiu $s0, $sp, 0x50` ahead of the subtract as retail does, but the subtract's two stores go through 0($s0) where retail has 0x50($sp).
- The non-volatile VU0_ZERO_VSUB_XYZ_TO gets the $sp stores but computes $s0 after the asm (6 diffs), with the helpers, the macros in place, or helper-local temporaries (which do share the 0x50 slot).
- The difference from func_0012B618: here the same 0x50 slot is the subtract's and the normalise's temporary, so one long-lived $s0 holds its address. Retail's cVec_unitOf zero-store does reach it as 0x50($sp) while $s0 is live; only the subtract doesn't in ours.
- Permuter (on Am.c, base 2 diffs): stalled at iteration 480, nothing better.

## func_0024BB68 — PARKED (2026-10-22), the draft as is (3 diffs). The old "VU0 not allowed" entry above is stale; the draft uses the vu0.h macros.
- The `neg.s $f1, $f0` diff: ours negates the copy (`neg.s $f1, $f1`) after `mov.s $f1, $f0` in the bc1f delay slot. None of the 5 if/else and ternary spellings, the 3 inline absf helpers, declaration order, or the flags (drop-reorder, -fno-gcse, -ffast-math, as sn) changes it. 00124c30.c on main uses the same if/else form.
- The vadd diff is the func_0012AFE8 shape: retail builds &ofs in $v1 before the in-place add (for cVec_copy3's overlap check) and still addresses the add as 0xB0($sp).
  - A non-volatile VU0_VADD_XYZ_IP twin ("=m" output, "m" input), tested locally, gets the $sp addressing but builds &ofs after the asm (7 diffs).
  - The volatile macro in place: 12 diffs.
  - The only form left would keep the helper's returned pointer in a local for the copy, a pointer alias. Not done.

## cIDBase_getIDWork (002aa410) — PARKED (2026-10-22), the draft as is (25 vs 28 words; as sn: 26)
- Retail strength-reduces the loop into two induction pointers: the entry ($a2, returned) and &entry->flags ($v1, with id read at -2). Ours folds both into one pointer.
- Tried, all 25 words: an entry pointer in the loop body, a walking `e++` pointer, nested ifs, `self->ent + i`, a while loop. Also ee-2.9 (25) and cygnus-2.96 (26). The flags change nothing. With as sn it's 26 (the loop-top alignment nop); the giv split is still missing.

## func_001C86E8 — PARKED (2026-10-22), the draft as is (10 diffs; -ffast-math, fp_hazard_rules sqrt)
- Gap: retail builds &step in $a0 at the top of the step block (in the spin test's delay slot) and addresses the vel copy and the scale off $sp. &step is then the register source of the copy into move, and &move is built fresh (0x70) for the vadd.
- Helper findings (same family as func_0012B618, func_0012AFE8, func_0024BB68): an inline helper parameter that holds a stack address gets an early pointer register. Non-stack parameters (&self->vel) don't. Its memory operands stay $sp-based.
  - `cVec_scaleTo(tmp, ret, v, s)` (copy into tmp, scale, copy to ret) and its local-tmp and reordered forms give every $sp operand right. But they also make &move an early pointer, which retail doesn't have (16 diffs).
  - A helper that only scales into dst, with the copy in the caller, or returning dst for the copy: the draft's 10 diffs.
- Not tried: a frame struct with VU0_SQC2(4, &f, off) stores (base = $sp itself, no pseudo), as 0028CB90's best.c does.
- For the handoff later: `int frame[3]` (the childAt count) is a placeholder array; it needs a real frame type.

## Maintainer ruling, 2026-10-22: no unions in stack-frame structs
- func_0012B618's handoff was rejected. A union inside a stack-frame struct, used only to make two locals share retail's stack slot (the childAt count and a cVec at 0x30), counts as steering, and the same goes for any handoff that does this.
- Allowed instead: real locals in separate `{ }` blocks with non-overlapping lifetimes, so GCC can share the slot on its own. The main agent tried that once on func_0012B618 and it gave 146 diffs (the count store is dropped, 193 vs 195 words), so it stays a draft in drafts/cod/0012b618.c. The handoff folder moved to progress/nm_solved/rejected/func_0012B618.
- Decisions that need the maintainer now go in progress/decisions_needed.md (function, question, recommendation); the function is skipped meanwhile.

## func_0012B618 — REJECTED by maintainer ruling (2026-10-22), stays a draft
- Ruling: the union in the stack-frame struct (childNum and the copied unit vector sharing 0x30) only reproduces retail's slot sharing, so it is steering. Block-scoped locals with separate lifetimes give 146 diffs (the child-count store is dropped).
- Rule for me from now on: no union frame records that exist only to share a stack slot. The helper findings above (void helpers, VU0_ZERO_VSUB_XYZ_TO, helper-local temporary) still hold and can be reused once the slot sharing has a plain form.

## func_00162298 — PARKED (2026-10-22), the draft as is (2 diffs, as sn)
- Left: in the left-scroll wrap, retail builds the 5 stored in sel in $a0, ours in $v1. The right-scroll branch's 5 is in $a0 in both. Storing top before sel: same 2. Moving the sel store after the clamp: 7.
- Permuter (10 min, as sn, base 10): ~550 iterations, nothing better.

## func_001B51B0 — PARKED (2026-10-22), the draft as is (27 diffs, fdiv)
- Retail builds &diff ($s3, 0x20) early and &tmp ($s1, 0x30) only after the subtract. Every helper form makes &tmp early too:
  - the draft's tmp parameter: 27;
  - a helper-local tmp in both helpers: 27 (the two locals do share 0x30);
  - the volatile _MEM form: 28–29 (&tmp still hoisted);
  - local tmp in subTo only: 160 words;
  - the macros in place: 155–157 words (a saved register goes away).
- The rest of the diff (the node offset add order, the branch-likely exits) wasn't looked at while the start is off.

## func_001B0540 — PARKED (2026-10-22), the draft as is (182 vs 189 words, sqrt)
- Retail tests falling == 0 && rolling == 1 with `ld 0x620` and a mask: fold_truthop merged the two field tests into a single 64-bit access. Ours merges them into one `lhu 0x624`.
- `unsigned long` bitfields for 0x620..0x625 (with and without unk620/smokeWait) give the 64-bit container, but every other read then adds dsll32/dsra32 extensions: 197–199 words. Not the right layout either. Next idea: a plain 8-byte record type at 0x620, if one exists elsewhere.

## func_001D7560 — PARKED (2026-10-22), the draft as is (11 diffs, as sn)
- Left: in the three payouts that compile to movz (×8, ×8, ×2), retail loads the bet into $v0 and the constant into $v1; ours swaps them. Everything else matches.
  - Tried: `bet == 0 ? K : bet * K`, `!bet ? K : bet * K`, `bet != 0 ? ...` (on all lines and on the movz lines only), `(bet ? bet : 1) * K`. All 11.
  - An inline `payout(bet, k)` helper, in either parameter order, turns every payout into movz: 274 words.
- Blocker for any handoff even when matched: the draft declares SetBlendField1D4_1DDB10 and NoOp_1DCE60 differently from their definitions (an extra unused int; (void) while callers pass self). The definitions in src/ need correcting first, which is outside my scope.

## func_00169DF8 — PARKED (2026-10-22), not attempted in depth (428 vs 440 words; as sn 430)
- The draft's note: the switch and setup match. In the row loop, retail walks the item table with a pointer and keeps the row bases in stack slots. That's a whole-loop restructure, left for a longer session.

## cvt.w.s re-check after the maintainer's ruling (2026-10-22 23:30)
Ruling: trunc.w.s and cvt.w.s are the same word (0x46000024 form). A float-to-int conversion whose int result is only used as an int is ordinary C. Retail that keeps the converted value in an FPR still waits for fpu.h.
- I re-checked every draft logged as skipped for cvt.w.s: cEmSetParam_updateSetDataPos (00295380), func_002956F0 and func_002BEDE8. All three are the FPR case, so they stay skipped (waiting on fpu.h).
  - In all three, retail converts the position values in place (`cvt.w.s $f0,$f0`, then `mfc1`). The int result was allocated to the FPR, which is the fix_truncsfsi2 `*f` alternative. Our (int) cast always takes the GPR alternative, with a separate FP scratch: `trunc.w.s $f2,$f0` / `mfc1 v0,$f2`.
  - The rotation conversions in 002956F0 and 002BEDE8 (`$f0`→`$f1`/`$f3`) are the ordinary form. So is the matched sibling cEmSetParam_updateSetDataRot.
- cEmSetParam_updateSetDataPos, corrected C (progress/nm_work/d_00295380/s.c): 6 diffs, all the three in-place conversions (3 × cvt + mfc1 register). Implicit, (short) and (short)(int) stores give the same result. With fpu.h this should close at once.
  - Real signature: `(cEmSetParam *self, unsigned int id, float *pos)`. Retail passes a1 through to cRoomSave_findEm as the id; self is not read. The draft called findEm with one argument and didn't compile.
- FLAG for main agent:
  - cRoomSave_findEm has no prototype in any header. Its definition (00168080.c) is `cRoomSaveEm *cRoomSave_findEm(cRoomSave *self, unsigned int id)`. 00294b60.c and 001344a0.c call it with no declaration in scope; cEmSetParam.c and cemsetparam_updatesetdataflag.c declare it K&R or with cEmSetTable/cEmSetEntry types.
  - D_005E8658 is the cRoomSave object, but cEmSetParam.h declares it as cEmSetTable. cEmSetEntry duplicates cRoomSaveEm field for field (0x18 bytes). One type per record: merge them, and put the prototype in cRoomSave.h.
- Other log entries that mention cvt.w.s are not retryable: RoundFloat, Adjust_theta, func_002FA350/002FA3E0 and func_00159AD0 keep the value in an FPR; func_0036DE80 is CRI (off-limits); for func_001FB1C0 the cvt was only display.

## func_002FBFB0 (draft 002fbfb0, effect frame tick) — SOLVED (handoff in progress/nm_solved/func_002FBFB0/)
- sn-2.95.3-136, no per-unit settings. MATCH: 124 insns, 10 relocs.
- What closed it: the frame index store as a plain implicit conversion, `self->frameIdx = self->frameT;`. The draft's `(int)self->frameT` drops the copy retail keeps for the end test. A local idx (unsigned short/int/unsigned int, with or without the cast) gives 122–123 words.
- Header changes (header_changes.md):
  - espSys.h gains EspData/EspAnim (the fields of 0011a820.c's view plus the vtable, pos/vel, frameIdx, frameT, frameEnd and the keys), ESP_DATA_PAUSE, SYSFLAG_SLOWMO, and the prototypes of func_002FA350 and EspAnim_step. It also includes cModel.h for cVtEnt. The only file that includes espSys.h, 00306030.c, still matches with it (func_00306030, espSys_getEffT32Addr).
  - gameWork.h gains `extern unsigned int D_00747A84; /* D_007474A0.flags5E4 under its own symbol */`, following the D_00747A24 line; retail relocates against that symbol. It's unsigned because 002c32f0.c includes gameWork.h and declares it unsigned; that file still matches.
- Callees as defined: UpdateObjByIndexedOp_2FBE50(void *) (00292f38.c); func_002FC1A0 reads a0 and its caller tests v0, so `int (EspAnim *)`.
- FLAG for main agent: 0011a820.c and 001496c0.c keep private EspData/EspAnim (and EspAnim2) types and local func_002FA350/D_00747A84 externs. Once this lands they should include espSys.h; the tag EspAnim then has one definition. 001496c0.c's EspAnim2 is a different view (flags at 0x11C, frame at 0x240), so it stays separate under its own name. The other D_00747A84 externs (48 files, int and unsigned int) should move to the gameWork.h line.

## cSnd_CalcListenerPanDist (draft 002cf058) — SOLVED (handoff in progress/nm_solved/cSnd_CalcListenerPanDist/)
- sn-2.95.3-136, fp_hazard_rules mtc1 (meta.json; 110 words without it). MATCH: 111 insns, 7 relocs, with or without as=sn.
- What closed it: an inline accessor for the sound system object, `static __inline__ cSnd *sndSys(void) { return &D_005FEE00; }`, read for listenMtx, f110 and listenPos. Retail builds the base and adds the field offset separately, in both blocks. It's the same accessor form as game() in matched 00294f70.c. A plain `cSnd *snd = &D_005FEE00;` local gives 46 diffs (one base kept across both blocks).
- FLAG for main agent: D_005FEE00 is declared locally in 39 files, 15 as `cSnd` and 24 as `int`. It belongs in cSnd.h as `extern cSnd D_005FEE00;`, but 002cc728.c, 002cc830.c and 0013eba0.c include cSnd.h and declare it int, so they need fixing first. The handoff keeps the local `extern cSnd D_005FEE00;` like the other cSnd users. capVu0Atan2/capVu0LengthAB have no header either (18 local copies of `float capVu0Atan2(float y, float x)`, 2 of `(float x, float z)`).

## func_002FDDA8 (draft 002fdda8, project a point to the screen) — SOLVED (handoff in progress/nm_solved/func_002FDDA8/)
- sn-2.95.3-136, no per-unit settings. MATCH: 46 insns, 3 relocs.
- What closed it: after the depth test, read both screen coordinates into named locals (`x = pos.x; y = pos.y;`), then test x and y. Reading y before the x test lets reorg fill the x branch's delay slot with the y load, as retail does.
  - The permuter (base 60, about 10 min) found this as `new_var = pos.y;` placed alone before the x test. I rejected that form and rewrote it as the two named locals read together. Both orders (x then y, y then x) match; reading them before the depth test gives 9 diffs.
  - Earlier forms without the locals: combined conditions, a single return expression, nested ifs, else-if chains and an onScreen() helper are 4 diffs or the wrong length.
- Types: ViewVec is now `typedef cVec ViewVec __attribute__((aligned(16)));` (a plain cVec gives 54 words: the frame needs the alignment). That is the same type as cSnd.h's cVecQuad. FLAG for main agent: cVecQuad belongs next to cVec (cOmBase.h is off-limits to me) or in sceVu0.h; then this file should use it. ScreenPos (4 ints, aligned) has no header type yet.
- sceVu0DivVector/sceVu0FTOI4Vector are declared as defined (0030a468.c, 0030a570.c); this is their only caller.

## ColiseumBattle_ApplyRingRules (draft 001efa50) — PARKED (tooling, ~10 min)
- Settings: as=sn. With fp_hazard_rules div1 it's the right length (125 words) with 54 diffs; every other hazard combination is 124 or 128 words.
- Retail pads its div.s sites differently: none before the first divide (0xA0), padding before the later ones. That is the same per-site rule gap as func_002B4228; it needs a new wrapper rule, not C.
- Separately, in the first life branch retail keeps the new hpMax in $v1 and vitalPct in $a0, swapped against ours. Comparing vitalPct directly, in either branch order, gives 55.

## func_001F4248 (draft 001f4248) — PARKED (signature)
- The draft's own note: retail passes cCoreSave_getReelItem's int to func_001F5650's short `num` without narrowing it, which only a declaration that contradicts the definition reproduces. Under the rules that isn't a match until the definitions are reconciled (either func_001F5650 takes an int, or the retail caller is understood). Not attempted further.

## func_003781F8 (draft 003781f8, sound volume curve lookup) — PARKED (~25 min)
- sn-2.95.3-136 + fp_hazard_rules mtc1: the draft is 102 vs 104 words, 72 diffs. The fp_hazard_rules setting is right; all the diffs are block order.
- Layout: retail is the loop, then the `*out = 0; return -1` tail (shared with the x < 0 exit), then the interpolation, then one `*out = pt->y` store shared by the last-point and exact-point cases, then a shared `return 0`. Ours cross-jumps the two y stores but puts that block and the interpolation before the loop, with the loop at the end.
- No better: wrapping the body in `if (x >= 0)` with one -1 tail (106 words); the last-point case as an else around the loop (106); break-to-shared-store forms (109/113); a search loop with post-loop dispatch (111/116).
- Permuter (~12 min, base 5500, best 2975): only steering (an identical if/else on the -1 tail, a no-op `& 0xFFFFFFFFFFFFFFFF` mask). Rejected.

## func_003187D8 (draft 003187d8, objScroll init) — PARKED (~12 min)
- sn-2.95.3-136: 219 vs 224 words, 138 diffs (as=sn: 220).
- The last test: retail tests 0x4000000 and 0x2000000 one at a time (lui + and, twice), then bit 5 with dsrl, all from one load of set->flags. fold_truthop merges the first two into one 0x6000000 mask. `!= 0` and `== mask` forms merge too.
- A generic inline helper `scroll_hasFlag(f, mask)` keeps the tests separate (inlining happens after tree folding) but overshoots: 229/232 words. Neither bit has a name in cModel.h, so a named predicate would be invented anyway.
- The draft needs rule fixes before any handoff: the unused `long v`, the union in ScrollSet (flags/flagByte[4]) and the `bit = flagByte[1]; if (bit >> 7)` byte read through an unsigned long. SCROLL_FLAGS2F0 is a raw-offset macro for cObj 0x2F0, which has no field yet.

## func_002F1758 (draft 002f1758, lens flare occlusion) — PARKED (~35 min)
- sn-2.95.3-136, as=sn. The draft is 28 diffs. Best clean form: 21 diffs (progress/nm_work/d_002f1758/best_o2.c). It computes and clamps x (with skip) first, then computes and clamps y; that fixes the convert/clamp stretch.
- What's left: retail sets up the memset arguments before the x clamps and computes `8 - skip` across the memset call (8 loaded in the delay slot, subtracted after).
  - Moving `center = 8 - skip;` after the memset, or moving the taps copy, makes it worse (27–47). `-skip + 8` and `8 + -skip` give 24.
- Permuter (from the 21-diff form, base 1350, ~15 min): score 0 only with `center = 8; center = center - skip;`. That's a constant held in a variable, banned, so rejected. No other candidate below 1155.
- For a handoff later: sceGsStoreImage is defined locally in 003958d8.c, 00395618.c and 0030e660.c already. It needs a shared header (libgraph-style) before a fourth copy goes in.

## func_001AC370 (draft 001ac370, breakable guard shells) — PARKED (tooling)
- as=sn. With fp_hazard_rules div1: 304 vs 305 words, 93 diffs; fdiv 308. The draft's note: retail pads the second and third div.s with two nops and the first with none. That is the per-site pad gap again (func_002B4228, ColiseumBattle_ApplyRingRules): it needs a wrapper rule. The colour tail's FP register choice (c, 1 - c, 0.2) differs as well.

## func_002C78F0 (draft 002c78f0, rotated screen quad) — PARKED (not attempted in depth)
- extern_jtbl D_0044C3D0. sn: 285 vs 253 words, 222 diffs; as=sn 286; ee-2.9 284; cygnus-2.96 268. The draft's "shape matches" doesn't hold: it's 32 words longer.
- In the prologue every like pair is swapped (x/y in s2/s3, f22/f23, f24/f25), as the draft says. The length gap is a separate problem in the body. Left for a longer session.

## func_002F7E30 (draft 002f7e30, esp ring effect setup) — PARKED (tooling)
- sn, with or without as=sn: 434 vs 464 words, 320 diffs. The draft's note says everything else matches apart from the div.s padding and two small items (the owner equality kept as a 0/1 value; the owner part range check through a byte flag).

## Divide padding — wrapper rule proposal for the main agent / maintainer (2026-10-23)
Four parked drafts are blocked only on per-site div.s padding: func_002B4228, ColiseumBattle_ApplyRingRules (001efa50), func_001AC370 and func_002F7E30. The draft notes and the diffs agree on one pattern:
- retail puts two nops before a div.s, except when the div.s directly follows a cvt.s.w, an lwc1 or another div.s; then it puts none.
- Each existing rule (fdiv, div, div1) pads every site the same way.
A rule such as `div2_unless_after(cvt.s.w|lwc1|div.s)` would need checking against the existing fdiv/div1 units before it's used. If it holds, these four should re-run as soon as it exists.

## func_002FBFB0 — handoff re-verify failure was environmental (2026-10-23)
- handoff_log.tsv, 01:55: "re-verify failed: 2 differing insns; @98/@a8 R_MIPS_26 against unresolvable 'UpdateObjByIndexedOp_2FBE50' / 'EspAnim_step'". The two diffs are those two jal relocations: match_check couldn't find the callee symbols in build/SLUS_215.03.map.
- The map (and build/mc/symaddr.json) were rewritten at 01:56, a minute later. They now list all four callees (UpdateObjByIndexedOp_2FBE50 0x2FBE50, EspAnim_step 0x2FCAC8, func_002FC1A0, func_002FA350). The run probably read a map that was being rebuilt.
- Re-checked now against the current include/ headers with header_changes.md applied: MATCH, 124 insns, 10 relocs. The folder is unchanged in progress/nm_solved/func_002FBFB0/ and should pass the next nm_handoff run.

## func_00309568 (draft 00309568, TIM2 palette upload) — PARKED (~15 min)
- sn, as=sn: 280 vs 283 words, 140 diffs (without as=sn: 276, 252). No fp_hazard_rules combination, drop-reorder or call_loop_pad changes the count.
- Everything up to the 256-colour loop matches; the first real difference is at 0x270. Retail builds the step (0x400/0x200) in v0 and copies it to s5 after the empty-palette test. It also has a nop before the loop head (0x294), which may be loop-head alignment. Ours sets s5 directly and has no nop. The 16-colour loop's i & 0xF register choice (the draft's note) comes after that.
- Not tried yet: a step computed from cpsm after the switch (for example a ternary), and a while loop for the 256-colour upload.
