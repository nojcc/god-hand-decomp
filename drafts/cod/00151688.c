/* func_00151688: same size and instruction sequence as retail;
* 165 insns
 * differ only by register assignment (retail: hdr s2, w s7, count fp, i s5,
 * ent s6).
 * 64-bit masks with a non-folded __muldi3 multiplier, pkt indexing forms,
 * separate loop counters.
* In SN, long is 64-bit and long long 128-bit. */
#include "include_asm.h"
#include "godhand/tim2.h"

#define TEX0_TBP0_MASK  0x3FFFUL
#define TEX0_CBP_SHIFT  37
#define TEX0_CBP_MASK   (0x3FFFUL << TEX0_CBP_SHIFT)
#define TEX0_TCC        (1UL << 34)

extern int D_007476B0;

#ifdef NON_MATCHING
void func_00151688(char *w, TexHdr *hdr, unsigned int *pa, unsigned int *pb, int type)
{
    unsigned int base;
    unsigned int cbase;
    unsigned int count;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int m;
    int size;
    TexEnt *ent;
    TexRef *ra;
    TexRef *rb;
    char *tbl;
    int buf;
    unsigned long t;
    unsigned long tbp;
    unsigned long cbp;

    unsigned long *pkt;

    i = 0;
    ent = hdr->ent;
    base = *pa;
    size = hdr->w * hdr->h;
    cbase = *pb;
    ra = (TexRef *)((char *)hdr + hdr->refOfsA);
    count = hdr->flags & 0x7FFFFFFF;
    *pa = base + size / 64;
    rb = (TexRef *)((char *)hdr + hdr->refOfsB);
    *pb += count * 4;
    buf = D_007476B0 & 1;
    if (count != 0) {
        pkt = (unsigned long *)(w + 0x3DC88);
        do {
            t = ent->tex0;
            i++;
            ent++;
            tbp = (t & TEX0_TBP0_MASK) + base;
            t = (t & ~TEX0_TBP0_MASK) | (tbp & TEX0_TBP0_MASK);
            cbp = ((t >> TEX0_CBP_SHIFT) & 0x3FFF) * 4 + cbase;
            t = (t & ~TEX0_CBP_MASK) | ((cbp & 0x3FFF) << TEX0_CBP_SHIFT);
            t |= TEX0_TCC;
            pkt[*(unsigned short *)(w + 0x3F8A8) * 2 + buf] = t;
            (*(unsigned short *)(w + 0x3F8A8))++;
        } while (i < count);
    }
    if ((int)hdr->flags >= 0) {
        tbl = (char *)ra;
        for (j = 0; j < hdr->nRefA; j++) {
            ra->p += (int)tbl;
            ra++;
        }
        tbl = (char *)rb;
        for (j = 0; j < hdr->nRefB; j++) {
            rb->p += (int)tbl;
            rb++;
        }
        hdr->flags |= 0x80000000;
    }
    ra = (TexRef *)((char *)hdr + hdr->refOfsA);
    rb = (TexRef *)((char *)hdr + hdr->refOfsB);
    for (k = 0; k < hdr->nRefA; k++) {
        func_00150DC8(w, ra, base, 0, type);
        (*(unsigned char *)(w + 0x3F8AA))++;
        ra++;
    }
    for (m = 0; m < hdr->nRefB; m++) {
        func_00150DC8(w, rb, cbase, 1, type);
        cbase += 4;
        (*(unsigned char *)(w + 0x3F8AB))++;
        rb++;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00151688);
#endif
