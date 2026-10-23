/* sn-2.95.3-136 */
/* NON_MATCHING func_001C7138: 20 differing words. Retail computes the address
 * of the sum temporary at the top of each block, before the first quadword
 * copy; here it is computed just before the copy out of it. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmSub.h"
#include "godhand/vu0.h"

/* *out = a + b in x, y and z, through two quadword temporaries. */
static __inline__ void cVec_sumOf(cVec *out, cVec *a, cVec *b)
{
    cVec ret;
    cVec sum;

    VU0_LQC2_SQC2_MEM(4, &sum, a);
    VU0_VADD_XYZ_IP(&sum, 0, b);
    VU0_LQC2_SQC2_MEM(4, &ret, &sum);
    cVec_copy3(out, &ret);
}

/* Set the walk's start and goal points: base plus travel at the far end,
 * the base points themselves at the near end, swapped when reversed. */
__attribute__((section(".text.func_001C7138")))
void func_001C7138(cOmSub *self)
{
    if (self->reverse == COMSUB_REVERSED) {
        cVec_sumOf(&self->goalA, &self->posA, &self->moveA);
        cVec_sumOf(&self->goalB, &self->posB, &self->moveB);
        cVec_copy3(&self->startA, &self->posA);
        cVec_copy3(&self->startB, &self->posB);
    } else {
        cVec_copy3(&self->goalA, &self->posA);
        cVec_copy3(&self->goalB, &self->posB);
        cVec_sumOf(&self->startA, &self->posA, &self->moveA);
        cVec_sumOf(&self->startB, &self->posB, &self->moveB);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C7138);
#endif
