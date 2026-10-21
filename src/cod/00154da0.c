/* NON_MATCHING func_00154DA0 (sn-2.95.3-136, sn as): model record packet. Ours moves self out of a0
 * into t2 and adds the packet table index to self before the buffer offset; retail keeps self in a0. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/mdlPkt.h"

#define GIF_TAG(n, hi)  ((n) | ((unsigned long)(hi) << 46))
#define DMA_ADDR(p)     ((unsigned long)((unsigned int)(p) & 0x0FFFFFFF) << 32)

#define MDLOBJ_PKT(o, buf, idx)  (*(PktQw **)((char *)(o) + 0x300 + (idx) * 4 + (buf) * 0x40))
#define MDLOBJ_TEXBANK(o)        (*((unsigned char *)(o) + 0x384))
#define MDLREC_TEXNO(r)          (*((unsigned char *)(r) + 0x16))

/* One A+D qword: data and the GS register it goes to. */
typedef struct PktAd {
    unsigned long data;
    unsigned long addr;
} PktAd;

extern MdlPktBuf D_00747BB8[];
extern PktQw *func_00154E98(MdlObj *self, PktQw *q, int idx);

/* Build the packet for record idx into packet buffer buf: the texture set-up, the record body and
 * the closing return tag. Returns nothing; the start is kept in the object's packet table. */
void func_00154DA0(MdlObj *self, PktQw *q, int idx, int buf)
{
    PackRef r;
    PktQw *top;

    MDLOBJ_PKT(self, buf, idx) = q;
    top = q;
    q->s.lo = 0x10000002;
    q->s.w8 = 0x11000000;
    q->s.wC = 0x50000002;
    q[1].s.lo = GIF_TAG(0x8001, 0x4000);
    q[1].s.w8 = 0xE;
    q[1].s.wC = 0;
    r.base = self->pack;
    r.rec = (MdlRec *)(r.base->ofs[idx] + (char *)r.base);
    ((PktAd *)&q[2])->data = D_00747BB8[MDLOBJ_TEXBANK(self) + MDLREC_TEXNO(r.rec)].q[0];
    ((PktAd *)&q[2])->addr = 6;
    q += 4;
    top->s.lo = DMA_ADDR(q) | 0x50000002;
    q = func_00154E98(self, q, idx);
    q[-1].all = 0;
    q[-1].s.lo = 0x60000000;
    q[-1].s.wC = 0;
    q[-1].s.w8 = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00154DA0);
#endif
