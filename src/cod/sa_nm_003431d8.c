/* NON_MATCHING func_003431D8 (cygnus-2.96, -freorder-blocks dropped; PARK 74 at attempt 3, best 71): size the decode buffers ((w/16)*(h/16)*1024 for format 2, else *384, plus 0x40) and fill out[0..n) either from the preallocated pool D_00758A38 (after the pool count/size checks) or with func_00344568; -1 if any buffer is missing. Retail keeps the pool loop un-strength-reduced (index recomputed, entered at its test) and divides w in place; ours reduces it and copies the quotients. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[8];
    int width;
    int height;
    int nbuf;
    char pad14[0x10];
    int fmt;
} Cre3431D8;

extern int D_003EC7D0;
extern int D_003EC7D4;
extern int D_00758A38[];
extern int mwsfcre_ConvBufFmtFromMwsfd(int fmt);
extern int func_00344568(void *hdl, int size);

int func_003431D8(void *hdl, Cre3431D8 *cre, int *out)
{
    int w = cre->width;
    int h = cre->height;
    int n = cre->nbuf;
    int size;
    int ret = 0;
    int i;
    int b;

    int fmt = mwsfcre_ConvBufFmtFromMwsfd(cre->fmt);

    w /= 16;
    h /= 16;
    if (fmt == 2) {
        size = w * h * 1024;
    } else {
        size = w * h * 384;
    }
    size += 0x40;

    if (D_003EC7D0 != 0) {
        if (D_003EC7D0 < n + 2) {
            ret = -1;
        } else if (D_003EC7D4 < size) {
            ret = -1;
        } else {
            for (i = 0; i < n; i++) {
                b = D_00758A38[i];
                out[i] = b;
                if (b == 0) {
                    ret = -1;
                }
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            b = func_00344568(hdl, size);
            out[i] = b;
            if (b == 0) {
                ret = -1;
            }
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003431D8);
#endif
