/* B3190 float/eq6 schedule;
* D4248 a1 vs v1 for 0x5C (3 words).
* 83DD0 halfword scan / movn. */
#include "include_asm.h"

#ifdef NON_MATCHING

__attribute__((section(".text.func_002B3190")))
void func_002B3190(char *self)
{
    int n = *(int *)(self + 0x10) + 1;
    int sq = n * n;
    float f0 = (float)n;

    *(int *)(self + 0x10) = n;
    f0 = f0 / 6.0f;
    {
        float f1 = (float)sq / 36.0f;
        f0 = (f0 + f0) - f1;
        *(float *)(self + 0xA0) = f1;
        *(float *)(self + 0x9C) = f0;
        *(float *)(self + 0x98) = f0;
    }
}

#endif

#ifndef NON_MATCHING
INCLUDE_ASM("asm/nonmatching", func_002B3190);
#endif
