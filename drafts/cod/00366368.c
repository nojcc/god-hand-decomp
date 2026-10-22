/* cygnus-2.96 */
/*
 * NON_MATCHING: same length as retail; the table, head and branch code
 * match. In both ramp loops retail stores the alpha first and then r, b, g;
 * here the scheduler moves one of the level stores ahead of the alpha.
 * The head loop also swaps v0 and v1 between the level and the pointer.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
/* A Y level scaled by k into 1/64 units, rounded. */
#define SFX_CSC_Y(y, k) ((y) * 64.0f * (k) + 0.5f)

typedef struct SfxCscEnt {
    short r, g, b, a;
} SfxCscEnt;

/* Build the Cb and Cr colour-conversion tables and a Y table with a
 * 48-entry dark head and steeper ramps, with the alphas given for the head,
 * the rising ramp and the falling ramp. */
__attribute__((section(".text.func_00366368")))
void func_00366368(SfxCscEnt *tbl, unsigned char headA, unsigned char riseA, unsigned char fallA)
{
    SfxCscEnt *ytbl = tbl;
    SfxCscEnt *cbtbl = tbl + 256;
    SfxCscEnt *crtbl = tbl + 512;
    int i;
    float y;
    short v;

    for (i = 0; i < 256; i++) {
        float c = i - 128;

        cbtbl[i].a = 0;
        cbtbl[i].r = 0;
        cbtbl[i].b = c * 129.088f + 0.5f;
        cbtbl[i].g = c * -25.088f + 0.5f;
        crtbl[i].g = c * -52.032f + 0.5f;
        crtbl[i].r = c * 102.144f + 0.5f;
        crtbl[i].b = 0;
        crtbl[i].a = 0;
    }
    for (i = 0; i < 48; i++) {
        ytbl[i].b = -1160;
        ytbl[i].g = -1160;
        ytbl[i].r = -1160;
        ytbl[i].a = headA;
    }
    for (i = 48; i < 130; i++) {
        y = i - 68.0f;
        if (y < 0.0f) {
            v = 0;
        } else if (y > 255.0f) {
            v = SFX_CSC_Y(255.0f, 4.6363636f);
        } else {
            v = SFX_CSC_Y(y, 4.6363636f);
        }
        ytbl[i].a = riseA << 6;
        ytbl[i].r = v;
        ytbl[i].b = v;
        ytbl[i].g = v;
    }
    for (i = 130; i < 256; i++) {
        y = 247.0f - i;
        if (y < 0.0f) {
            v = 0;
        } else if (y > 255.0f) {
            v = SFX_CSC_Y(255.0f, 2.2972973f);
        } else {
            v = SFX_CSC_Y(y, 2.2972973f);
        }
        ytbl[i].a = fallA << 6;
        ytbl[i].r = v;
        ytbl[i].b = v;
        ytbl[i].g = v;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00366368);
#endif
