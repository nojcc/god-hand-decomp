#include "godhand/gameWork.h"

/* With
 * --assembler=sn: 85 differing insns, bitfield-op scheduling and the
 * format ?: register choice; register allocation otherwise matches. */
#include "include_asm.h"
#include "godhand/tim2.h"

#ifdef NON_MATCHING
void func_00151990(TexWork *w, Tim2File *tim, unsigned int *pa, unsigned int *pb, int type)
{
    unsigned int tbp;
    unsigned int cbp;
    Tim2Pic *pic;
    unsigned int n;
    unsigned int i;
    int psm;
    int width;
    int height;
    int bw;
    char *image;
    char *clut;
    GsTex0 t;

    n = tim->pictures;
    if (tim->format == 0) {
        pic = (Tim2Pic *)((char *)tim + 0x10);
    } else {
        pic = (Tim2Pic *)((char *)tim + 0x80);
    }
    tbp = *pa;
    i = 0;
    cbp = *pb;
    if (n != 0) {
        do {
            psm = D_0041ED68[pic->imageType - 1];
            width = pic->width;
            image = (char *)pic + pic->headerSize;
            pic->tex0.PSM = psm;
            height = pic->height;
            t = pic->tex0;
            bw = func_00309C30(psm, width);
            t.TBP0 = tbp;
            t.TBW = bw;
            t.TCC = 1;
            t.CPSM = 0;
            t.CSM = 0;
            t.CSA = 0;
            t.CLD = 1;
            t.CBP = cbp;
            w->pkt[w->nPkt][D_007474A0.frame & 1] = t;
            clut = (char *)pic + pic->headerSize + pic->imageSize;
            w->nPkt++;
            func_00150F68(w, image, psm, tbp, bw, width, height, 0, type);
            w->nImage++;
            if (pic->imageType == 5) {
                func_00150F68(w, clut, 0, cbp, 1, 16, 16, 0, type);
            } else if (pic->clutSize != 0x40) {
                func_00150F68(w, clut, 0, cbp, 1, 16, 16, 0, type);
            } else {
                func_00150F68(w, clut, 0, cbp, 1, 8, 2, 0, type);
            }
            cbp += 4;
            i++;
            w->nClut++;
            tbp += pic->imageSize >> 8;
            pic++;
        } while (i < n);
    }
    *pa = tbp;
    *pb = cbp;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00151990);
#endif
