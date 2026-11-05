#include "godhand/vu0.h"
#include "godhand/cNode.h"

/* func_002B6080 — zero a stack vector, run cNode_updateWorldMatrix(a1), fetch the scale
 * vector of the matrix at a1+0xB0 into the stack buffer, copy it to a0, and
 * return a0.  sn-2.95.3-136. */

extern void MtxGetScaleVec(void *, void *);

__attribute__((section(".text.func_002B6080")))
cVec *func_002B6080(cVec *dst, cNode *self) {
    cVec scale;
    VU0_SQC2_VF0(&scale, 0);
    cNode_updateWorldMatrix(self);
    MtxGetScaleVec(&scale, self->matWorld);
    VU0_LQC2(4, &scale, 0);
    VU0_SQC2(4, dst, 0);
    return dst;
}
