/* offset it by a scaled global (0x2FA350).
 * Both: retail converts with cvt.w.s kept in an FPR; every compiler here emits
 * trunc.w.s for an (int) cast, so 29 insns differ (same as RoundFloat). */
#include "include_asm.h"

#ifdef NON_MATCHING

extern float D_00741DC0;
extern float D_00747A14;

void func_002FA350(float *p)
{
    int i;

    *p *= 100.0f;
    i = *p;
    if (*p - (float)i != 0.0f) {
        i++;
    }
    *p = (float)(i + (int)(D_00741DC0 * D_00747A14 * 100.0f)) / 100.0f;
}

void func_002FA3E0(float *p)
{
    int i;

    *p *= 100.0f;
    i = *p;
    if (*p - (float)i != 0.0f) {
        i++;
    }
    *p = (float)(i - (int)(D_00741DC0 * D_00747A14 * 100.0f)) / 100.0f;
}

#else

INCLUDE_ASM("asm/nonmatching", func_002FA350);
INCLUDE_ASM("asm/nonmatching", func_002FA3E0);

#endif
