/* include/godhand/mtx.h - 4x4 matrix helpers (0x147xxx-0x150xxx).
 *
 * A matrix is 16 floats, row-major: rows 0 to 2 are the scaled axes, row 3
 * the translation. */
#ifndef GODHAND_MTX_H
#define GODHAND_MTX_H

/* Store (x, y, z, 1) at dst. */
void func_00150710(void *dst, float x, float y, float z);

/* Write the length of each of mtx's three axis rows to scale. */
void MtxGetScaleVec(void *scale, float *mtx);

/* Write the Euler angles of mtx's rotation, in the axis order order (0 to 5),
 * to rot. */
void func_00147C88(void *rot, float *mtx, unsigned char order);

/* Copy the 4x4 matrix src to dst. */
void MtxCopy(void *dst, void *src);

/* dst = a * b. */
void MtxMultiply(void *dst, void *a, void *b);

/* mtx = a rotation by angle about y, no translation. */
void MtxInitRotY(float *mtx, float angle);

#endif
