/* include/godhand/sceVu0.h - libvu0 matrix calls shared across the game code.
 *
 * Vectors are 16 bytes (x, y, z, w) and matrices 4x4 floats, both 16-byte
 * aligned: the SDK's sceVu0FVECTOR and sceVu0FMATRIX.
 */
#ifndef GODHAND_SCEVU0_H
#define GODHAND_SCEVU0_H

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* v0 = m0 * v1 (v0 may be v1). */
extern void sceVu0ApplyMatrix(void *v0, void *m0, void *v1);

typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

/* Copy the 4x4 matrix src to dst (the SDK's sceVu0CopyMatrix). */
extern void func_0030A548(void *dst, void *src);

/* dst = a * b for 4x4 matrices (MtxMultiply's callee). */
extern void func_0030A2E0(void *dst, void *a, void *b);

/* Integer screen position of v through the view-projection matrix m (x, y
 * and z in 12.4 fixed point). */
extern void sceVu0RotTransPers(void *out, void *m, void *v, int mode);

/* out = v in 12.4 fixed point. */
extern void sceVu0FTOI4Vector(void *out, void *v);

/* *a0 = *a1 scaled to length 1 (xyz). */
extern void sceVu0Normalize(void *a0, void *a1);

/* The dot product of *a0 and *a1 (xyz). */
extern float sceVu0InnerProduct(void *a0, void *a1);

/* *a0 = *a1 x *a2, w cleared. */
extern void sceVu0OuterProduct(void *a0, void *a1, void *a2);

/* v = m * v, in place. */
static __inline__ void cVec_applyMatrix(cVec *v, void *m) {
    sceVu0ApplyMatrix(v, m, v);
}

/* Zero all four components, stored in place. */
static __inline__ void cVec_zero(cVec *v) {
    VU0_SQC2_VF0_MEM(v, 0);
}

/* Length of v (x, y, z). */
extern float Tramp_001F7DF8_00101E28(void *v);

/* *out = v scaled to length 1, or zero when v has no length. */
static __inline__ void cVec_unitOf(cVec *out, cVec *v)
{
    float len;
    float inv;

    VU0_SQC2_VF0_MEM(out, 0);
    len = Tramp_001F7DF8_00101E28(v);
    if (len > 0.0f) {
        inv = 1.0f / len;
        out->x = v->x * inv;
        out->y = v->y * inv;
        out->z = v->z * inv;
        out->w = v->w;
    }
}

#endif /* GODHAND_SCEVU0_H */
