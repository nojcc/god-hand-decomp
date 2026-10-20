/* NON_MATCHING _initSeq (ee-2.9-991111;
 * PARK, 12 diffs): libmpeg sequence/frame setup; size multiply operands come out swapped (w*384 first, retail ht*384) and the scheduler pairs the fr[2]/fr[5] b2 stores differently in the uncached-address branch */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    unsigned int addr;
    int w;
    int h;
    int mbw;
    int mbh;
    char pad14[0x68 - 0x14];
} MpFrame;

typedef struct {
    char pad0[0x10C];
    unsigned int buf0;
    unsigned int buf1;
    unsigned int buf2;
    char heap[0x134 - 0x118];
    int width;
    int height;
    int mbw;
    int mbh;
    char pad144[0x14C - 0x144];
    int progSeq;
    int f150;
    int f154;
    char pad158[0x184 - 0x158];
    int f184;
    char pad188[4];
    int f18C;
    char pad190[0x198 - 0x190];
    int f198;
    char pad19C[0x1F8 - 0x19C];
    MpFrame fr[9];
    char pad5A0[0x858 - 0x5A0];
    int mpeg2;
    char pad85C[0x87C - 0x85C];
    int mode;
} MpDec;

typedef struct {
    int w;
    int h;
    char pad8[0x40 - 8];
    MpDec *dec;
} MpHdl;

extern void func_0039ADD0(void *heap);
extern unsigned int func_0039ADE0(MpDec *d, void *heap, unsigned int size, int align);

static inline void setFr(MpFrame *f, int w, int h)
{
    f->w = w;
    f->h = h;
    f->mbw = w >> 4;
    f->mbh = h >> 4;
}

void _initSeq(MpHdl *h)
{
    MpDec *d;
    int w;
    int ht;
    unsigned int size;
    unsigned int b0;
    unsigned int b1;
    unsigned int b2;
    int mbh;

    d = h->dec;
    if (d->mpeg2 == 0) {
        d->progSeq = 1;
        d->f150 = 1;
        d->f198 = 1;
        d->f184 = 3;
        d->f18C = 1;
        d->f154 = 5;
    }
    d->mbw = (d->width + 15) >> 4;
    if (d->mpeg2 != 0 && d->progSeq == 0)
        mbh = ((d->height + 31) >> 5) * 2;
    else
        mbh = (d->height + 15) >> 4;
    d->mbh = mbh;
    ht = mbh << 4;
    w = d->mbw << 4;
    if (w == h->w && ht == h->h)
        return;
    size = (unsigned int)(w * (ht * 0x180)) >> 8;
    h->w = w;
    h->h = ht;
    func_0039ADD0(d->heap);
    d->buf0 = func_0039ADE0(d, d->heap, size, 64);
    d->buf1 = func_0039ADE0(d, d->heap, size, 64);
    d->buf2 = b2 = func_0039ADE0(d, d->heap, size, 64);
    if (d->mode == 0) {
        int off = h->w * h->h / 512 * 0x180;
        b0 = (d->buf0 & 0x0FFFFFFF) | 0x20000000;
        b1 = (d->buf1 & 0x0FFFFFFF) | 0x20000000;
        b2 = (b2 & 0x0FFFFFFF) | 0x20000000;
        d->fr[0].addr = b0;
        d->fr[1].addr = b1;
        d->fr[3].addr = b0;
        d->fr[4].addr = b1;
        d->fr[5].addr = b2;
        d->fr[6].addr = b0 + off;
        d->fr[7].addr = b1 + off;
        d->fr[8].addr = b2 + off;
        d->fr[2].addr = b2;
    } else if (d->mode == 1) {
        int off = h->w * h->h / 512 * 0x180;
        d->fr[0].addr = d->buf0;
        d->fr[1].addr = d->buf1;
        d->fr[3].addr = d->buf0;
        d->fr[4].addr = d->buf1;
        d->fr[2].addr = b2;
        d->fr[5].addr = b2;
        d->fr[6].addr = d->buf0 + off;
        d->fr[7].addr = d->buf1 + off;
        d->fr[8].addr = b2 + off;
    }
    setFr(&d->fr[0], w, ht);
    setFr(&d->fr[1], w, ht);
    setFr(&d->fr[2], w, ht);
    setFr(&d->fr[3], w, ht / 2);
    setFr(&d->fr[4], w, ht / 2);
    setFr(&d->fr[5], w, ht / 2);
    setFr(&d->fr[6], w, ht / 2);
    setFr(&d->fr[7], w, ht / 2);
    setFr(&d->fr[8], w, ht / 2);
}
#else
INCLUDE_ASM("asm/nonmatching", _initSeq);
#endif
