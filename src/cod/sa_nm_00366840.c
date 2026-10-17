/* NON_MATCHING func_00366840 (cygnus dr,loop-sched): MPV LUT copy; retail rotates the outer loop with in->buf load in bnel slot and keeps mult cols*j per row; ours differs in schedule/regalloc */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int unk0;
    unsigned char *buf;
    int height;
    int width;
} Pic366840;

void func_00366840(Pic366840 *in, Pic366840 *out, unsigned char **lutp)
{
    int j = 0;
    int rows = in->height / 16;
    int cols = in->width / 32;
    unsigned char *lut = *lutp;
    unsigned char *src;
    unsigned char *dst;
    int base, i, k;

    if (rows <= 0) {
        return;
    }
next_row:
    src = in->buf;
    dst = out->buf;
    base = cols * j;
    dst += (base << 10) + 3;
    src += base * 0x300 + cols * 0x180;
    for (i = 0; i < cols; i++) {
        for (k = 255; k >= 0; k--) {
            *dst = lut[*src++];
            dst += 4;
        }
        src += 0x80;
    }
    j++;
    if (j < rows) {
        goto next_row;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00366840);
#endif
