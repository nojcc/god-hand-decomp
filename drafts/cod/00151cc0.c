/* sn-2.95.3-136 (as sn). Differs from retail in 36 instructions: retail keeps
 * w in s5 and type in fp (ours swaps them), clears CSA a little later, and
 * adds the image size into the old *pa in v0. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/texWork.h"
#include "godhand/gameWork.h"

/* Load the one picture of a TIM2 file into the texture bank: record its
 * TEX0 (image at *pa, CLUT at *pb), queue the image and CLUT uploads, and
 * advance *pa and *pb past them. The CLUT is 8x2 only for a 16-colour
 * image whose CLUT holds 0x40 bytes, 16x16 otherwise. */
__attribute__((section(".text.func_00151CC0")))
void func_00151CC0(TexWork *w, Tim2FileHdr *tim, unsigned int *pa, unsigned int *pb, int type)
{
    Tim2PicHdr *pic = (Tim2PicHdr *)(tim + 1);
    int psm = D_0041ED80[pic->imageType - 1];
    unsigned int tbp;
    unsigned int cbp;
    int width;
    int height;
    int bw;
    char *image;
    char *clut;
    GsTex0 t;

    tbp = *pa;
    cbp = *pb;
    pic->tex0.PSM = psm;
    width = pic->width;
    height = pic->height;
    image = (char *)pic + pic->headerSize;
    t = pic->tex0;
    bw = func_00309C30(psm, width);
    clut = (char *)pic + pic->headerSize + pic->imageSize;
    t.TBP0 = tbp;
    t.TBW = bw;
    t.TCC = 1;
    t.CPSM = 0;
    t.CSM = 0;
    t.CSA = 0;
    t.CLD = 1;
    t.CBP = cbp;
    w->pkt[w->nPkt][D_007476B0 & 1] = t;
    w->nPkt++;
    func_00151168(&w->images, (int)image, psm, tbp, bw, width, height, 0, type);
    w->nImage++;
    if (pic->imageType == 5 || pic->clutSize != 0x40) {
        func_00150F68(&w->images, (int)clut, 0, cbp, 1, 16, 16, 0, type);
    } else {
        func_00150F68(&w->images, (int)clut, 0, cbp, 1, 8, 2, 0, type);
    }
    cbp += 4;
    w->nClut++;
    *pa = tbp + (pic->imageSize >> 8);
    *pb = cbp;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00151CC0);
#endif
