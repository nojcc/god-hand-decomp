/* B3190 float/eq6 schedule;
 * D4248 a1 vs v1 for 0x5C (3 words).
 * 83DD0 halfword scan / movn. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];
extern int func_003447A8(void *a0, void *a1, void *a2);
extern void func_00344E88(void *a0);

__attribute__((section(".text.func_002B3190")))
void func_002B3190(char *self)
{
    int n = *(int *)(self + 0x10) + 1;
    float f2 = 6.0f;
    float f3 = 36.0f;
    int sq = n * n;
    float f0 = (float)n;
    int eq = n ^ 6;

    *(int *)(self + 0x10) = n;
    eq = (unsigned)eq < 1u;
    f0 = f0 / f2;
    {
        float f1 = (float)sq / f3;
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
