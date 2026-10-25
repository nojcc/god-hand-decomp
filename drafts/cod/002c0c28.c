/* NON_MATCHING func_002C0C28 (sn-2.95.3-136; -f=-ffast-math, fp_hazard_rules fdiv, as its matched
 * sibling func_002C0CB0): 1 instruction differs. Retail fills the root test's branch delay slot
 * with v0 = 0 (as the height test before it); here it is a nop. */
#include "include_asm.h"

#ifdef NON_MATCHING

/* func_002C0C28: return 1 when the point at a1 lies inside the upright cylinder
 * at a0 (centre a0[0]/a0[1] in x/z, radius a0[2], heights a0[8]..a0[9]), else 0. */
int func_002C0C28(float *a0, float *a1) {
    float dx;
    float dz;

    if (a1[1] < a0[8])
        return 0;
    if (a0[9] < a1[1])
        return 0;
    dx = a1[0] - a0[0];
    dz = a1[2] - a0[1];
    if (a0[2] < __builtin_sqrtf(dx * dx + dz * dz))
        return 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C0C28);
#endif
