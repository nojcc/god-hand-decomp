/* sfxcnv_MakeDstBufInf: same length; entry base/index register pair swapped (s0/s1) and the
 * prologue saves are interleaved differently. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/sfxlib.h"

extern int sfxcnv_IsCnvUpHalf(SfxStm *stm);

__attribute__((section(".text.sfxcnv_MakeDstBufInf")))
void sfxcnv_MakeDstBufInf(SfxStm *stm, SfxInf *inf, int val, SfxTbl *tbl, int idx)
{
    int rate;

    tbl->ent[idx].val = val;
    rate = inf->rate;
    tbl->ent[idx].rate = rate;
    if (sfxcnv_IsCnvUpHalf(stm, rate) == 1) {
        tbl->ent[idx].size = inf->size / 2;
    } else {
        tbl->ent[idx].size = inf->size;
    }
    tbl->ent[idx].outRate = stm->rate ? stm->rate : inf->rate;
}

#else

INCLUDE_ASM("asm/nonmatching", sfxcnv_MakeDstBufInf);

#endif
