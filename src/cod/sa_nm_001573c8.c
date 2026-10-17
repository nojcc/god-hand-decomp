/* NM, not registered. sn-2.95.3-136: XZ quad test and RoundFloat (0x1573C8..).
 * func_001573C8: 13 differing insns, bz/dz FP registers swapped (f7/f8).
 * RoundFloat: retail keeps the truncated int in an FPR (cvt.w.s ->
 * cvt.s.w, twice); ours goes trunc.w.s/mfc1/mtc1. */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct Vec4f {
    float x, y, z, w;
} Vec4f;

/* 1 when pt lies inside the quad a-b-c-d on the XZ plane. */
float RoundFloat(float x, float scale)
{
    float frac;
    float i;

    x *= 1.0f / scale;
    frac = x - (float)(int)x;
    i = (float)(int)x;
    if (0.5f <= frac) {
        return (i + 1.0f) * scale;
    }
    return i * scale;
}
#else
INCLUDE_ASM("asm/nonmatching", RoundFloat);
#endif
