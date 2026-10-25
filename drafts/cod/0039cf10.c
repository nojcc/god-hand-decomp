/* ee-2.9-991111 */
/* _getRef0: 285 of 290 words. Retail keeps `left` and `avg * 4` on the stack
 * and `n` in a temporary; this C gives `left` a saved register instead. The
 * records are the ones src/cod/0039d398.c uses; the two join one unit when
 * this matches. */
#include "include_asm.h"

typedef struct MpegMcArg {
    unsigned char *dst;                 /* 0x00 */
    int x;                              /* 0x04 column inside the macroblock */
    int rows;                           /* 0x08 rows read from the first block */
    int rowsNext;                       /* 0x0C rows read from the block below */
    int stride;                         /* 0x10 */
    unsigned char *src;                 /* 0x14 */
    unsigned char *srcNext;             /* 0x18 */
} MpegMcArg;                            /* 0x1C */

typedef struct MpegMcSet {
    unsigned char *work;                /* 0x000 */
    void *residual;                     /* 0x004 */
    unsigned char *refA[4];             /* 0x008 */
    unsigned char *refB[4];             /* 0x018 */
    void (*predA[4])(MpegMcArg *arg);   /* 0x028 */
    void (*predB[4])(MpegMcArg *arg);   /* 0x038 */
    MpegMcArg argA[4];                  /* 0x048 */
    MpegMcArg argB[4];                  /* 0x0B8 */
    void *dst;                          /* 0x128 */
    int num;                            /* 0x12C */
    int intra;                          /* 0x130 */
    int unk134;
    int predict;                        /* 0x138 */
    int skipped;                        /* 0x13C */
} MpegMcSet;                            /* 0x140 */

typedef struct MpegMcState {
    char unk000[0x5A0];
    MpegMcSet mc[2];                    /* 0x5A0 */
    int cur;                            /* 0x820 */
    char unk824[0xC];
    unsigned char *pred;                /* 0x830 */
    char unk834[0x48];
    int unk87C;                         /* 0x87C */
} MpegMcState;

typedef struct MpegRefImage {
    unsigned char *mb;                  /* 0x00 */
    char unk04[0xC];
    int height;                         /* 0x10 */
} MpegRefImage;

extern void (*D_003FA238[])(MpegMcArg *arg);
extern void (*D_003FA258[])(MpegMcArg *arg);

#ifdef NON_MATCHING
/* Queue one luma and one chroma prediction step for the current set. */
__attribute__((section(".text._getRef0")))
void _getRef0(MpegMcState *s, MpegRefImage *ref, int top, int dstRow, int row, int rows,
              int left, int col, int mvx, int mvy, int field, int avg)
{
    int n;
    MpegMcArg *la;
    MpegMcArg *ca;
    int x, y, mbx, mby, mb;
    unsigned char *lumaA, *lumaB, *base;
    int n1, off, t;
    int cmvx, cmvy, kind, cbx, cby;
    unsigned char *pred;

    n = s->mc[s->cur].num;
    pred = s->pred;
    la = &s->mc[s->cur].argA[n];
    ca = &s->mc[s->cur].argB[n];

    x = (mvx >> 1) + left;
    if (field) {
        y = (mvy >> 1) * 2 + col + (row + top);
    } else {
        y = (mvy >> 1) + col + (row + top);
    }
    mbx = x >> 4;
    mby = y >> 4;
    mb = mbx * ref->height + mby;
    lumaA = ref->mb + mb * 0x180;
    lumaB = ref->mb + (mb + ref->height) * 0x180;
    s->mc[s->cur].refA[n] = lumaA;
    s->mc[s->cur].refB[n] = lumaB;
    la->x = x - mbx * 16;
    y -= mby * 16;
    la->dst = pred + ((dstRow + row) << 5);
    if (mvy & 1) {
        if (y + (rows << field) >= 16) {
            n1 = (16 >> field) - (y >> field) - 1;
            la->rows = n1;
            la->rowsNext = rows - n1;
        } else {
            la->rows = rows;
            la->rowsNext = 0;
        }
    } else {
        if (y + (rows << field) > 16) {
            n1 = (16 >> field) - (y >> field);
            la->rows = n1;
            la->rowsNext = rows - n1;
        } else {
            la->rows = rows;
            la->rowsNext = 0;
        }
    }
    if (s->unk87C == 0) {
        base = s->mc[s->cur].work + n * 0x600;
        la->src = base + y * 16;
        la->srcNext = base + (y * 16 + 0x300);
    } else {
        base = lumaA;
        la->srcNext = lumaB + y * 16;
        la->src = lumaA + y * 16;
    }
    kind = avg * 4 | (mvx & 1) * 2 | (mvy & 1);
    la->stride = 16 << field;

    cmvx = mvx / 2;
    cmvy = mvy / 2;
    rows >>= 1;
    x = (cmvx >> 1) + (left >> 1);
    if (field) {
        y = (cmvy >> 1) * 2 + (col >> 1) + ((row >> 1) + top);
    } else {
        y = (cmvy >> 1) + (col >> 1) + ((row >> 1) + top);
    }
    cbx = x >> 3;
    cby = y >> 3;
    ca->x = x - cbx * 8;
    ca->dst = pred + ((dstRow + (row >> 1)) * 16 + 0x200);
    y -= cby * 8;
    if (cmvy & 1) {
        if (y + (rows << field) >= 8) {
            n1 = (8 >> field) - (y >> field) - 1;
            ca->rows = n1;
            ca->rowsNext = rows - n1;
        } else {
            ca->rows = rows;
            ca->rowsNext = 0;
        }
    } else {
        if (y + (rows << field) > 8) {
            n1 = (8 >> field) - (y >> field);
            ca->rows = n1;
            ca->rowsNext = rows - n1;
        } else {
            ca->rows = rows;
            ca->rowsNext = 0;
        }
    }
    off = ((cbx - mbx) * 2 + (cby - mby)) * 0x180;
    if (s->unk87C == 0) {
        ca->srcNext = base + off + (y * 8 + 0x400);
        ca->src = base + off + (y * 8 + 0x100);
    } else {
        t = y * 8 + 0x100;
        if ((unsigned int)(off + t) <= 0x300) {
            ca->src = lumaA + off + t;
        } else {
            ca->src = lumaB + off + t - 0x300;
        }
        ca->srcNext = lumaB + off + (y * 8 + 0x100);
    }
    ca->stride = 8 << field;

    s->mc[s->cur].predA[n] = D_003FA238[kind];
    s->mc[s->cur].predB[n] = D_003FA258[avg * 4 | (cmvx & 1) * 2 | (cmvy & 1)];
    s->mc[s->cur].num++;
}
#else
INCLUDE_ASM("asm/nonmatching", _getRef0);
#endif
