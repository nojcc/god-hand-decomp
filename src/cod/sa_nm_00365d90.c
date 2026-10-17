/* NON_MATCHING func_00365D90 (cygnus-2.96 dr): 63 diffs: retail spills arg/ny to stack and keeps dst in fp; ours uses s8 + caller-saved t0; outer-loop entry layout differs */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Dst365D90 {
    char *base;
    int pad4;
    int pitch;
} Dst365D90;

typedef struct Src365D90 {
    char *base;
    int h;
    int w;
    int stride;
} Src365D90;

extern void func_00363620(char *dst, int stride, char *src, int arg);

void func_00365D90(Dst365D90 *dst, Src365D90 *src, int arg)
{
    int y, x;
    int ny, nx, stride;
    char *d;

    stride = src->stride;
    ny = src->h / 16;
    nx = src->w / 16;
    for (y = 0; y < ny; y++) {
        d = dst->base + dst->pitch * y * 0x18;
        for (x = 0; x < nx; x++) {
            func_00363620(d, stride, src->base + y * 64 + x * stride * 16, arg);
            d += 0x180;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00365D90);
#endif
