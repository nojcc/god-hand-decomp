/* NON_MATCHING cOmBase_calcParabolaVector (sn-2.95.3-136, -ffast-math, fp_hazard_rules sqrt):
 * 97 differing words; retail finishes the first sqrt.s before starting the second time
 * term (fixed nop/nop/sqrt.s template), and addresses the work vectors from sp where
 * ours keeps the frame base in a register. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* out = a - b (xyz), through the work vectors f[0] and f[1]. */
static __inline__ void cVec_sub3(cVec *out, cVec *a, cVec *b, cVec *f)
{
    VU0_ZERO_VSUB_XYZ_MEM(f, 0x10, a, b);
    VU0_LQC2(4, &f[1], 0);
    VU0_SQC2(4, f, 0);
    cVec_copy3(out, &f[0]);
}

/* f[slot] = in * s (xyz), through the work vector f[2]. */
static __inline__ void cVec_scale3(cVec *f, int slot, cVec *in, float s)
{
    VU0_LQC2(4, in, 0);
    VU0_SQC2(4, f, 0x20);
    VU0_VSCALE_XYZ_MEM(f, 0x20, s);
    VU0_LQC2(4, &f[2], 0);
    VU0_SQC2(4, f, slot * 0x10);
}

/* Launch velocity that carries an object from `from` to `to` over an arc
 * `height` above the higher end, under `gravity`. */
__attribute__((section(".text.cOmBase_calcParabolaVector")))
void cOmBase_calcParabolaVector(cOmBase *self, cVec *out, cVec *from, cVec *to, float height, float gravity)
{
    cVec f[3] __attribute__((aligned(16)));
    float top;
    float t;

    if (height <= 0.0f) {
        cVec_sub3(out, to, from, f);
        return;
    }
    if (to->y < from->y) {
        top = height + from->y;
    } else {
        top = height + to->y;
    }
    t = __builtin_sqrtf((top - from->y) * -2.0f / gravity);
    t += __builtin_sqrtf((top - to->y) * -2.0f / gravity);
    cVec_sub3(out, to, from, f);
    cVec_scale3(f, 1, out, 1.0f);
    cVec_scale3(f, 0, &f[1], 1.0f / t);
    cVec_copy3(out, &f[0]);
    out->y = __builtin_sqrtf(gravity * -2.0f * (top - from->y));
}
#else
INCLUDE_ASM("asm/nonmatching", cOmBase_calcParabolaVector);
#endif
