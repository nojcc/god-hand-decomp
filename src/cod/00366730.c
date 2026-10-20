/* NON_MATCHING func_00366730: structure ~matched (goto outer loop disables SR; dst offset as j giv); left: p/d in t8/t7 swapped vs retail, p->data load placed after mult (retail: before, bnel reload) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { int unk0; unsigned char *data; int w; int h; } LutPic;
typedef struct { int unk0; unsigned char *buf; int unk8; int unkC; int pitch; } LutDst;

void func_00366730(LutPic *p, LutDst *d, unsigned char **tbl)
{
    int i, j, k, l;
    int nx = p->w / 16;
    int ny = p->h / 32;
    int pitch = d->pitch;
    unsigned char *t = *tbl;
    unsigned char *s;
    unsigned char *o;

    i = 0;
    if (nx <= 0) return;
loop:
    {
        s = p->data + ny * i * 0x300 + ny * 0x180;
        for (j = 0; j < ny; j++) {
            o = d->buf + (i << 6) + j * pitch * 16 + 3;
            for (k = 0; k < 16; k++) {
                for (l = 0; l < 16; l++) {
                    *o = t[*s++];
                    o += 4;
                }
                o += pitch - 0x40;
            }
            s += 0x80;
        }
    }
    if (++i < nx) goto loop;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00366730);
#endif
