/* 156 words vs 167: loop-invariant hoisting differs.
 * Retail hoists 13
 * constants (0x01000404, 0x0FFFFFFF, 0x01000103, the four UNPACK words,
 * C0BB<<46, 0x01000000, 0x30000000 twice, 0x17000000) and leaves
 * 0x10000002, 0x412, 0x26 and the other GIF PRIM words inline. */
#include "include_asm.h"
#include "godhand/mdlPkt.h"

#define GIF_TAG(n, hi)  ((n) | ((unsigned long)(hi) << 46))
#define DMA_ADDR(p)     ((unsigned long)((unsigned int)(p) & 0x0FFFFFFF) << 32)

#ifdef NON_MATCHING
PktQw *func_00155800(MdlObj *self, PktQw *q, int idx)
{
    PackRef r;
    char *vtx;
    char *nrm;
    char *uv;
    int cnt;
    unsigned int n;
    unsigned long tag;
    unsigned int n8;

    r.base = self->pack;
    r.rec = (MdlRec *)(r.base->ofs[idx] + (char *)r.base);
    vtx = (char *)r.rec + r.rec->ofsVtx;
    nrm = (char *)r.rec + r.rec->ofsNrm;
    uv = (char *)r.rec + r.rec->ofsUv;
    cnt = r.rec->nVtx;
    do {
        if (cnt < 0x26) {
            n = cnt;
        } else {
            n = 0x26;
        }
        q->s.lo = 0x10000002;
        q->s.w8 = 0x01000404;
        q->s.wC = 0x6C028000;
        q++;
        tag = (unsigned int)(n | 0x8000);
        q->s.lo = GIF_TAG(tag, 0xC0F9);
        if (self->flags & 0x10) {
            q->s.lo = GIF_TAG(tag, 0xC0B9);
        }
        q->s.w8 = 0x412;
        q->s.wC = 0;
        q++;
        q->s.lo = GIF_TAG(tag, 0xC0FB);
        if (self->flags & 0x10) {
            q->s.lo = GIF_TAG(tag, 0xC0BB);
        }
        q->s.w8 = 0x412;
        q->s.wC = 0;
        q++;
        n8 = (n + 7) >> 3;
        if (!(self->flags & 0x1000000)) {
            q->s.lo = (unsigned int)(n8 * 8 | 0x30000000) | DMA_ADDR(vtx);
            q->s.wC = (n8 * 8 << 16) | 0x6C008002;
        } else {
            q->s.lo = (unsigned int)(n8 * 4 | 0x30000000) | DMA_ADDR(vtx);
            q->s.wC = (n8 * 8 << 16) | 0x6D008002;
        }
        q->s.w8 = 0x01000103;
        q++;
        q->s.lo = (unsigned int)(n8 * 2 | 0x30000000) | DMA_ADDR(uv);
        q->s.wC = (n8 * 8 << 16) | 0x6E00C003;
        q->s.w8 = 0x01000103;
        q++;
        q->s.lo = (unsigned int)(n8 * 2 | 0x30000000) | DMA_ADDR(nrm);
        q->s.wC = (n8 * 8 << 16) | 0x65008004;
        q->s.w8 = 0x01000103;
        q++;
        q->s.lo = 0x30000000;
        q->s.w8 = 0x17000000;
        q->s.wC = 0x01000404;
        q++;
        cnt -= 0x24;
        if (self->flags & 0x1000000) {
            vtx += 0x120;
        } else {
            vtx += 0x240;
        }
        nrm += 0x90;
        uv += 0x90;
    } while (cnt > 0);
    q->all = 0;
    q->s.lo = 0x70000000;
    q->s.w8 = 0;
    q->s.wC = 0;
    return q + 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00155800);
#endif
