/* NM, not registered. cygnus-2.96 (drop-reorder): twin of ResetBufferOnFirstEnterA (0x3B9E10).
 * Control flow matches; retail loads the enter counter into a0 (test and increment), ours into v0.
 * memset prototype (void/int/void * return) does not change it. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/criStm.h"

extern int D_003FC7A8;
extern char D_003FC7B8[];

__attribute__((section(".text.func_003B9E10")))
void func_003B9E10(void)
{
    if (D_003FC7A8 == 0) {
        func_003A52F0(D_003FC7B8, 0, 0x3C);
    }
    D_003FC7A8 = D_003FC7A8 + 1;
}

#else
INCLUDE_ASM("asm/nonmatching", func_003B9E10);
#endif
