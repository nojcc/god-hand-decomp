/* NON_MATCHING func_001569A0 (sn-2.95.3-136): 9 differing words, one moved instruction.
 * Retail builds &f.n (addiu v1, sp, 0x20) before the first subtraction; here it is built
 * after the copy into f.n. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* The frame: both edges, the cross product and the subtraction's work vector. */
typedef struct EdgeFrame {
    cVec e1;
    cVec e2;
    cVec n;
    cVec work;
} EdgeFrame;

#define EDGEFRAME_OFFSET(field) ((int)&((EdgeFrame *)0)->field)

/* d = a x b, with w set to 1. */
static __inline__ void cVec_cross(cVec *d, cVec *a, cVec *b)
{
    d->x = a->y * b->z - a->z * b->y;
    d->y = a->z * b->x - a->x * b->z;
    d->z = a->x * b->y - a->y * b->x;
    d->w = 1.0f;
}

/* The in-plane direction across the edge a-b of triangle a, b, c: e1 x (e1 x e2). */
__attribute__((section(".text.func_001569A0")))
cVec *func_001569A0(cVec *out, cVec *a, cVec *b, cVec *c)
{
    EdgeFrame f;

    VU0_SQC2_VF0_MEM(&f.e1, 0);
    VU0_SQC2_VF0_MEM(&f.e2, 0);
    VU0_ZERO_VSUB_XYZ_MEM(&f.work, 0, b, a);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, EDGEFRAME_OFFSET(n));
    cVec_copy3(&f.e1, &f.n);
    VU0_ZERO_VSUB_XYZ_MEM(&f.work, 0, c, a);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, EDGEFRAME_OFFSET(n));
    cVec_copy3(&f.e2, &f.n);
    cVec_cross(&f.n, &f.e1, &f.e2);
    cVec_cross(out, &f.e1, &f.n);
    return out;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001569A0);
#endif
