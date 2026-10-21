/* NON_MATCHING func_0036DE80: copy the decoder state at +0x160 into the info record at +0x58 (sizes, rates, flags, and a format byte from the D_0045A570[a][b][c] table).
* Stores and offsets match; retail keeps the source base in v1 and the record base in a0 (ours swaps them) and hoists some loads above earlier stores, which suggests distinct alias sets for some fields. sn-2.95.3-136 is worse (91). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int w00, w04, w08, w0C, w10, w14, w18, w1C;
    int w20, w24, w28, w2C, w30, w34, w38, w3C;
    int w40, w44, w48, w4C;
    unsigned short h50, h52;
    unsigned char b54, b55, b56, b57, b58, b59, b5A, b5B;
    unsigned char b5C, b5D, b5E, b5F, b60, b61, b62, b63;
    unsigned char b64;
    char pad65[3];
    int w68;
} DecInfo;

#define S(off) (*(int *)((char *)s + (off)))

extern unsigned char D_0045A570[][2][2];

void func_0036DE80(char *p)
{
    DecInfo *d = (DecInfo *)(p + 0x58);
    char *s = p + 0x160;

    d->w40 = 0;
    d->w00 = S(0x2C4);
    d->w04 = S(0x2C8);
    d->w08 = S(0x2CC);
    d->w0C = S(0x2D0);
    d->w14 = S(0xDC);
    d->w10 = S(0x10);
    d->w1C = S(0xBC);
    d->w18 = S(0xE0);
    d->w20 = S(0xC0);
    d->w24 = S(0xC4);
    d->w28 = S(0xC8);
    d->w2C = S(0xCC);
    d->w30 = S(0x43C);
    d->w34 = S(0x42C);
    d->w38 = S(0x118);
    d->w3C = S(0x4C);
    d->w44 = 1;
    d->w48 = S(0x2D4);
    d->w4C = S(0x2D8);
    d->h50 = S(0x80);
    d->h52 = S(0x84);
    d->b54 = D_0045A570[S(0x48)][S(0x134)][S(0x11C)];
    d->b55 = S(0x13C);
    d->b56 = S(0x11C);
    d->b57 = S(0x134);
    d->b58 = S(0x3C4);
    d->b59 = S(0xC);
    d->b5A = S(0x20);
    d->b5B = S(0x64);
    d->b5C = S(0x68);
    d->b5D = S(0x44);
    d->b5E = S(0x48);
    d->b5F = S(0x60);
    d->b60 = S(0x6C);
    d->b61 = S(0x70);
    d->b62 = S(0x74);
    d->b63 = S(0x78);
    d->b64 = S(0x7C);
    d->w68 = S(0x4AC);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0036DE80);
#endif
