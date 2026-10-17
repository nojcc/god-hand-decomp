# Functions waiting for a real-C match (former inline-asm matches)

The project rule is real C only: no `__asm__` that pastes the retail listing. A single `nop` or barrier is fine, and so is
an instruction C cannot express. No forced-register pins.

On 2026-10-17, when this tree was rebased onto upstream, the inline-asm matches below were reverted to
`INCLUDE_ASM("nonmatching", <name>)` in the same file. Their carve entries stay, so link placement is unchanged. Each
one counts as unmatched until real C replaces the `INCLUDE_ASM` line and the reseed hash check passes.

Kept on purpose (single instructions with no C equivalent):

- `src/cod/0032f938.c` func_003B06C8: `mfc0 $12`, a privileged COP0 read.
- `src/cod/phase_a_sn.c` func_002D4DA0: `sync`.
- `src/cod/phase_a_sn.c` func_002F1AA0: `sqc2 $vf0`, the same form as `VU0_SQC2_VF0` in `include/godhand/vu0.h`.

| File | Compiler | Functions | Asm the old match used | Status |
|------|----------|-----------|------------------------|--------|
| src/cod/phase_a_sn_192.c | sn-2.95.3-136 | func_00312F70, func_00313150, func_00313210, func_003132D0, func_00313390, func_00313450 (were macro PHASE_A_192) | `daddu s0, s1, $zero` move | INCLUDE_ASM, open |
| src/cod/phase_a_sn_batch26.c | sn-2.95.3-136 | func_00317D50, func_003181A8 (were macro B26_300) | `daddu` move, `addiu %0, %1, 0x3000` | INCLUDE_ASM, open |
| src/cod/phase_a_sn_batch26.c | sn-2.95.3-136 | func_0030A538, func_0030A548 | `lq`/`sq` noreorder block | INCLUDE_ASM, open |
| src/cod/phase_a_sn_batch31.c | sn-2.95.3-136 | func_003182D8 | `lui`/`sw` noreorder block | INCLUDE_ASM, open |
| src/cod/phase_a_sn_batch31.c | sn-2.95.3-136 | func_002BF420 | `dsrl %0, %0, 6`; try the long-widening recipe from 0013c950.c | INCLUDE_ASM, open |
| src/cod/phase_a_sn_batch34.c | sn-2.95.3-136 | func_00375318 | `lui`/`addiu`/`sw`/`jal` noreorder block | INCLUDE_ASM, open |
| src/cod/phase_a_sn_batch52.c | sn-2.95.3-136 | func_00313030 | `daddu` move | INCLUDE_ASM, open |
| src/cod/000000.c | cygnus-2.96 | func_003951B0, func_003951C0, func_003951D0 | `nop; nop` (two nops; upstream's own code, predates this work) | linked, open |

func_001B0CE8 and func_001E7368 are no longer listed: upstream matched both in real C (cObj_initVuFields610 and
SlotUi_release), so they left this tree.
