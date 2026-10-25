/* NON_MATCHING func_001F8810 (sn-2.95.3-136; -f=-ffast-math, fp_hazard_rules sqrt, as its twin
 * func_001F8550): 13 instructions differ. Retail loads the radius after sqrt.s; with
 * __builtin_sqrtf cc1 loads it before and swaps the centre registers. Waiting on FPU_SQRT_S. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cArea.h"

/* 1 when pt, its height scaled by scale, lies inside the circle area: inside the height band, then
 * within radius of the scaled centre in XZ. */
int func_001F8810(cArea *self, float *pt, float scale) {
    float py;
    float top;
    float dx;
    float dz;

    py = pt[1] * scale;
    top = self->y + self->height;
    if (py < self->y)
        return 0;
    if (top < py)
        return 0;
    dx = pt[0] - self->corner[0].x * scale;
    dz = pt[2] - self->corner[0].z * scale;
    if (__builtin_sqrtf(dx * dx + dz * dz) < self->radius)
        return 1;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F8810);
#endif
