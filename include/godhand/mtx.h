/* include/godhand/mtx.h - 4x4 matrix helpers.
 *
 * A matrix is 16 floats, row-major: rows 0 to 2 are the scaled axes, row 3
 * the translation. */
#ifndef GODHAND_MTX_H
#define GODHAND_MTX_H

#include "godhand/cVecType.h"

/* mtx = a rotation by angle about y, no translation. */
void MtxInitRotY(float *mtx, float angle);

/* dst = the inverse of src. */
void MtxInverse(float *dst, float *src);

/* mtx = a translation by pos (x, y, z). */
void MtxInitTransVec(float *mtx, cVec *pos);
/* mtx = the rotation by the angles rot (x, y, z), applied in the given axis order (0-5). */
void MtxInitRotVec(void *mtx, cVec *rot, unsigned char order);
/* m = the rotation of the unit quaternion q (x, y, z, w). */
void MtxInitRotQuaternion(float m[4][4], float q[4]);
/* mtx = a scale by scale (x, y, z). */
void MtxInitScaleVec(void *mtx, cVec *scale);
/* mtx = a translation by pos, then the rotation of q, then a scale by scale. */
void MtxBuildTransRotScale(float *mtx, cVec *pos, float *q, cVec *scale);

/* These forward to the sceVu0 matrix calls and take their pointer types. */
/* dst = src. */
void MtxCopy(void *dst, void *src);
/* dst = a * b. */
void MtxMultiply(void *dst, void *a, void *b);
/* dst = mtx * src (dst may be src). */
void Tramp_func_0030A2B0_001508D8(void *dst, void *mtx, void *src);

/* dst = src times the matrix of a translation, rotation, quaternion or scale. */
void MtxMulTransVec(void *dst, void *src, cVec *pos);
void MtxMulRotVec(void *dst, void *src, cVec *rot, int order);
void BuildMatrixAndForward_147BB0(void *dst, void *src, float *q);
void MtxMulScaleVec(void *dst, void *src, cVec *scale);
/* dst = src rotated by the angles rot in the given axis order. */
void VecRotVec(void *dst, void *src, cVec *rot, int order);

#endif /* GODHAND_MTX_H */
