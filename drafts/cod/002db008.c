/* NON_MATCHING func_002DB008 (sn-2.95.3-136; -f=-ffast-math, fp_hazard_rules fdiv): cylinder
 * overlap, sibling of func_002DAF68. Retail takes the root before the radius add (as a volatile
 * sqrt.s does) and fills the two height tests' early returns with branch-likely v0 = 0 delay
 * slots; this C uses plain branches there. CVEC_INIT_SUB is in the held cVec.h overlay. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cVec.h"

/* Whether a cylinder of radius ra at a, half height h, overlaps one of radius rb at b
 * (heights summed). On a hit the ground-plane distance goes to *dist and a to *pos. */
int func_002DB008(cVec *a, cVec *b, float *dist, cVec *pos, float ra, float h, float rb)
{
    cVec d;
    CVEC_TEMPS;
    float len;

    CVEC_INIT_SUB(d, a, b);
    if (d.y < -(h + rb)) {
        return 0;
    }
    if (h + rb < d.y) {
        return 0;
    }
    len = __builtin_sqrtf(d.x * d.x + d.z * d.z);
    if (!(len < ra + rb)) {
        return 0;
    }
    if (dist != 0) {
        *dist = len;
    }
    if (pos != 0) {
        CVEC_ASSIGN(*pos, a);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002DB008);
#endif
