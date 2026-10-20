/* NON_MATCHING func_0033D3D0: cygnus dr: 40 diffs, structure and schedule right, register numbering of the block counters differs (retail keeps the sub-struct pointer in a1) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct AdxbIn33D3D0 {
    int unk0;
    int nbyte;      /* 0x04 */
    int nch;        /* 0x08 */
    int unkC;
    int blk;        /* 0x10 */
    int unk14;
    int end;        /* 0x18 */
    int unk1C;
    int pos;        /* 0x20 */
    int room;       /* 0x24 */
    int wpos;       /* 0x28 */
} AdxbIn33D3D0;

typedef struct Adxb33D3D0 {
    char unk0[0x48];
    AdxbIn33D3D0 in;    /* 0x48 */
    char unk74[0x74];
    int ext;            /* 0xE8 */
} Adxb33D3D0;

extern void ADXB_EvokeExpandSte(Adxb33D3D0 *b, int n);
extern void func_0033D378(Adxb33D3D0 *b, int n);
extern void func_0033D2D0(Adxb33D3D0 *b, int n);

void func_0033D3D0(Adxb33D3D0 *b)
{
    AdxbIn33D3D0 *in = &b->in;
    int nch = in->nch;
    int blk, end, pos, wpos, room;
    int n, nin, nout, nend, nroom, tail;

    nin = in->nbyte / nch;
    end = in->end;
    pos = in->pos;
    blk = in->blk;
    wpos = in->wpos;
    room = in->room;
    nend = (end - pos + blk - 1) / blk;
    nout = (wpos + blk - 1) / blk;
    tail = blk - (wpos + blk - 1) % blk - 1;
    wpos = wpos < room;
    pos += nend * blk;
    if (nout < nend)
        nend += pos - tail < end;
    room += wpos * tail;
    nroom = room / blk;
    n = nin;
    if (nroom < n)
        n = nroom;
    if (nout < n)
        n = nout;
    if (nend < n)
        n = nend;
    if (nch == 2) {
        ADXB_EvokeExpandSte(b, n);
        return;
    }
    if (b->ext != 0) {
        func_0033D378(b, n);
        return;
    }
    func_0033D2D0(b, n);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033D3D0);
#endif
