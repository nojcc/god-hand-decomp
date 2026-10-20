/* func_0035F5F0: same length; entry base/index register pair swapped (s0/s1) and the
 * prologue saves are interleaved differently. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/sfxlib.h"

extern int func_0035EA88(SfxStm *stm);

__attribute__((section(".text.func_0035F5F0")))
void func_0035F5F0(SfxStm *stm, SfxInf *inf, int val, SfxTbl *tbl, int idx)
{
    int rate;

    tbl->ent[idx].val = val;
    rate = inf->rate;
    tbl->ent[idx].rate = rate;
    if (func_0035EA88(stm, rate) == 1) {
        tbl->ent[idx].size = inf->size / 2;
    } else {
        tbl->ent[idx].size = inf->size;
    }
    tbl->ent[idx].outRate = stm->rate ? stm->rate : inf->rate;
}

#else

INCLUDE_ASM("asm/nonmatching", func_0035F5F0);

#endif
