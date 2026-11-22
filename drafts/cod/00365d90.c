/* NON_MATCHING CFT_Ycc420mbToArgb8888UserTable (cygnus-2.96: ): retail spills arg/ny to stack and keeps dst in fp; ours uses s8 + caller-saved t0; outer-loop entry layout differs */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct CnvDst {
    char *base;
    int pad4;
    int pitch;
} CnvDst;

typedef struct CnvSrc {
    char *base;
    int h;
    int w;
    int stride;
} CnvSrc;

extern void cftraw_CnvMbRAW8toPlaneARGB(char *dst, int stride, char *src, int arg);

void CFT_Ycc420mbToArgb8888UserTable(CnvDst *dst, CnvSrc *src, int arg)
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
            cftraw_CnvMbRAW8toPlaneARGB(d, stride, src->base + y * 64 + x * stride * 16, arg);
            d += 0x180;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", CFT_Ycc420mbToArgb8888UserTable);
#endif
