/* cygnus-2.96 */
/*
 * NON_MATCHING: 150 vs 148 words. The table loop is identical to retail.
 * Retail keeps lo/tbl/hi in s0/s1/s2 (here hi/lo/tbl), tests mode == 1 with
 * the stereo ramp as the fall-through block, and strength-reduces (hi - i)
 * into a down-counter.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int func_00360D50(void);

typedef struct SfxCscEnt {
    short r, g, b, a;
} SfxCscEnt;

/* Build the Y, Cb and Cr colour-conversion tables and the Y alpha ramp between lo and hi. */
__attribute__((section(".text.func_00365EC0")))
void func_00365EC0(int mode, int lo, int hi, SfxCscEnt *tbl)
{
    SfxCscEnt *ytbl = tbl;
    SfxCscEnt *cbtbl = tbl + 256;
    SfxCscEnt *crtbl = tbl + 512;
    int i;
    short y;
    int c;
    int alpha;
    float scale;

    alpha = func_00360D50();
    for (i = 0; i < 256; i++) {
        y = (i - 16) * 74.496f + 0.5f;
        c = i - 128;
        ytbl[i].b = y;
        ytbl[i].g = y;
        ytbl[i].r = y;
        cbtbl[i].b = c * 129.088f + 0.5f;
        cbtbl[i].g = c * -25.088f + 0.5f;
        cbtbl[i].r = 0;
        cbtbl[i].a = 0;
        crtbl[i].g = c * -52.032f + 0.5f;
        crtbl[i].r = c * 102.144f + 0.5f;
        crtbl[i].b = 0;
        crtbl[i].a = 0;
    }
    scale = (float)alpha / (float)(hi - lo);
    if (mode != 1) {
        for (i = 0; i < 256; i++) {
            if (i < lo) {
                ytbl[i].a = 0;
            } else if (i > hi) {
                ytbl[i].a = alpha << 6;
            } else {
                ytbl[i].a = (int)((i - lo) * scale) << 6;
            }
        }
    } else {
        for (i = 0; i < 256; i++) {
            if (i < lo) {
                ytbl[i].a = alpha << 6;
            } else if (i > hi) {
                ytbl[i].a = 0;
            } else {
                ytbl[i].a = (int)((hi - i) * scale) << 6;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00365EC0);
#endif
