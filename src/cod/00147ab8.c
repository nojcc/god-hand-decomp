/* sn-2.95.3-136 matched TU. */
#include "godhand/mtx.h"

/* Build a transform in place: reset the translation, apply the rotation, then the scale. */

__attribute__((section(".text.MtxBuildTransRotScale")))
void MtxBuildTransRotScale(float *mtx, cVec *pos, float *q, cVec *scale)
{
    MtxInitTransVec(mtx, pos);
    BuildMatrixAndForward_147BB0(mtx, mtx, q);
    MtxMulScaleVec(mtx, mtx, scale);
}
