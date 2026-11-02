/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING: 165 of 168 words; retail keeps a second clamp compare (slti 0x1B) and zero-extends n | 0x8000 once per GIF tag, which also changes the schedule. */
#include "godhand/mdlPkt.h"

#ifdef NON_MATCHING

#define GIF_TAG(n, hi)  ((n) | ((unsigned long)(hi) << 46))
#define DMA_ADDR(p)     ((unsigned long)((unsigned int)(p) & 0x0FFFFFFF) << 32)

/* Record idx's vertex packet body at q, five streams per block of 24
 * vertices; returns the qword after the closing tag. */
__attribute__((section(".text.func_00154E98")))
PktQw *func_00154E98(MdlObj *self, PktQw *q, int idx)
{
    PackRef r;
    char *vtx;
    char *s4;
    char *nrm;
    char *s10;
    char *uv;
    int cnt;
    unsigned int n;
    unsigned int n8;
    unsigned int tag;

    r.base = self->pack;
    r.rec = (MdlRec *)(r.base->ofs[idx] + (char *)r.base);
    vtx = (char *)(r.rec->ofsVtx + (int)r.rec);
    s4 = (char *)(r.rec->unk04 + (int)r.rec);
    nrm = (char *)(r.rec->ofsNrm + (int)r.rec);
    s10 = (char *)(r.rec->unk10 + (int)r.rec);
    uv = (char *)(r.rec->ofsUv + (int)r.rec);
    cnt = r.rec->nVtx;
    do {
        n = cnt < 0x1A ? cnt : 0x1A;
        q->s.lo = 0x10000002;
        q->s.w8 = 0x01000404;
        q->s.wC = 0x6C028000;
        q++;
        tag = n | 0x8000;
        q->s.lo = GIF_TAG(tag, 0xC0F9);
        q->s.w8 = 0x412;
        q->s.wC = 0;
        q++;
        n8 = (n + 7) >> 3;
        q->s.lo = GIF_TAG(tag, 0xC0FB);
        q->s.w8 = 0x412;
        q->s.wC = 0;
        q++;
        q->s.lo = (unsigned int)(n8 * 8 | 0x30000000) | DMA_ADDR(vtx);
        q->s.wC = (n8 * 8 << 16) | 0x6C008002;
        q->s.w8 = 0x01000106;
        q++;
        q->s.lo = (unsigned int)(n8 * 2 | 0x30000000) | DMA_ADDR(s4);
        q->s.wC = (n8 * 8 << 16) | 0x6E008007;
        q->s.w8 = 0x01000106;
        q++;
        q->s.lo = (unsigned int)(n8 * 2 | 0x30000000) | DMA_ADDR(uv);
        q->s.wC = (n8 * 8 << 16) | 0x6E00C003;
        q->s.w8 = 0x01000106;
        q++;
        q->s.lo = (unsigned int)(n8 * 2 | 0x30000000) | DMA_ADDR(nrm);
        q->s.wC = (n8 * 8 << 16) | 0x65008004;
        q->s.w8 = 0x01000106;
        q++;
        q->s.lo = (unsigned int)(n8 * 4 | 0x30000000) | DMA_ADDR(s10);
        q->s.wC = (n8 * 16 << 16) | 0x6E00C005;
        q->s.w8 = 0x01000206;
        q++;
        q->s.lo = 0x30000000;
        q->s.w8 = 0x17000000;
        q->s.wC = 0x01000404;
        q++;
        cnt -= 0x18;
        vtx += 0x180;
        s4 += 0x60;
        nrm += 0x60;
        s10 += 0xC0;
        uv += 0x60;
    } while (cnt > 0);
    q->all = 0;
    q->s.lo = 0x70000000;
    q->s.w8 = 0;
    q->s.wC = 0;
    return q + 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00154E98);
#endif
