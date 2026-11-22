/* Control flow matches; retail loads the enter counter into a0 (test and increment), ours into v0.
* memset prototype (void/int/void * return) does not change it. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/criStm.h"

extern int D_003FC7A8;
extern char D_003FC7B8[];

__attribute__((section(".text.AC3CNV_Init")))
void AC3CNV_Init(void)
{
    if (D_003FC7A8 == 0) {
        func_003A52F0(D_003FC7B8, 0, 0x3C);
    }
    D_003FC7A8 = D_003FC7A8 + 1;
}

#else
INCLUDE_ASM("asm/nonmatching", AC3CNV_Init);
#endif
