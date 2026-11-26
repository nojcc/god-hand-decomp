/* sn-2.95.3-136 (as: sn) */
/* NON_MATCHING func_00151FA0: 196 of 199 words, about 33 instructions off.
 * Retail loads the pack's count once (lw, then andi for the byte counter);
 * cc1 reads the counter with its own lbu. Retail also keeps the work in $fp
 * and spills the offset-table pointer before the picture index. */
#include "include_asm.h"
#include "godhand/texWork.h"
#include "godhand/pack.h"
#include "godhand/gameWork.h"

#ifdef NON_MATCHING
/* Load a pack of 4-bit pictures (func_00151630 kind 3): upload the shared
 * image block at *pa, then each picture's CLUT at *pb (16x16 for type 5,
 * else 8x8) and queue its TEX0; advance *pa and *pb past them. */
__attribute__((section(".text.func_00151FA0")))
void func_00151FA0(TexWork *w, Pack *pack, unsigned int *pa, unsigned int *pb, int type)
{
    unsigned int tbp;
    unsigned int cbp;
    unsigned char n;
    unsigned char i;
    int psm;
    int bw;
    char *image;
    char *clut;
    Tim2PicHdr *pic;
    GsTex0 t;
    int *ofs = pack->ofs;

    n = pack->count;
    image = (char *)pack + pack->ofs[0] + pack->count * 0x40;
    tbp = *pa;
    cbp = *pb;
    func_00151168(&w->images, (int)image, 0x14, tbp, 2, 0x80, (unsigned int)pack->unk08[1] / 0x2000 * 0x80, 0, type);
    i = 0;
    w->nImage++;
    image += pack->unk08[1];
    do {
        pic = (Tim2PicHdr *)((char *)pack + ofs[i] + 0x10);
        psm = D_0041ED98[pic->imageType - 1];
        pic->tex0.PSM = psm;
        t = pic->tex0;
        bw = Tim2CalcBufWidth(psm, pic->width);
        t.TBP0 = tbp;
        t.TBW = bw;
        t.TCC = 1;
        t.CPSM = 0;
        t.CSM = 0;
        t.CSA = 0;
        t.CLD = 1;
        t.CBP = cbp;
        clut = image;
        image += pic->clutSize;
        if (pic->imageType == 5) {
            func_00150F68(&w->images, (int)clut, 0, cbp, 1, 16, 16, 0, type);
        } else {
            func_00150F68(&w->images, (int)clut, 0, cbp, 1, 8, 8, 0, type);
        }
        w->nClut++;
        i++;
        cbp += 4;
        n--;
        w->pkt[w->nPkt][D_007474A0.frame & 1] = t;
        w->nPkt++;
        tbp += pic->imageSize >> 8;
    } while (n != 0);
    *pa = tbp;
    *pb = cbp;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00151FA0);
#endif
