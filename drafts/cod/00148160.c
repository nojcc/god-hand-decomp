/* sn-2.95.3-136 */
#include "godhand/libm.h"
#include "godhand/mtx.h"
#include "include_asm.h"

/* Length of each of mtx's three axis rows, stored to scale as (x, y, z, 1).
 * Differs from retail in scheduling: retail finishes each row's sum and
 * sqrt.s before loading the next row; ours (with -ffast-math, which drops the
 * errno call) interleaves the three rows. */
#ifdef NON_MATCHING
__attribute__((section(".text.MtxGetScaleVec")))
void MtxGetScaleVec(void *scale, float *mtx)
{
    func_00150710(scale,
                  __builtin_sqrtf(mtx[0] * mtx[0] + mtx[1] * mtx[1] + mtx[2] * mtx[2]),
                  __builtin_sqrtf(mtx[4] * mtx[4] + mtx[5] * mtx[5] + mtx[6] * mtx[6]),
                  __builtin_sqrtf(mtx[8] * mtx[8] + mtx[9] * mtx[9] + mtx[10] * mtx[10]));
}
#else
INCLUDE_ASM("asm/nonmatching", MtxGetScaleVec);
#endif
