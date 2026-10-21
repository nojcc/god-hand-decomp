/* NON_MATCHING func_002DAF68 (sn-2.95.3-136 -ffast-math, sqrt rule): sphere overlap. Retail adds the
 * radii after the fixed nop/nop/sqrt.s sequence; ours schedules the add before the squares. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* Whether spheres of radius ra at a and rb at b overlap. On a hit the centre distance goes to
 * *dist and a to *pos, when given. */
int func_002DAF68(cVec *a, cVec *b, float *dist, cVec *pos, float ra, float rb)
{
    struct {
        cVec d;                         /* 0x00 */
        cVec t;                         /* 0x10 */
    } f;
    float len;

    VU0_ZERO_VSUB_XYZ_MEM(&f, 0x10, a, b);
    VU0_LQC2(4, &f.t, 0);
    VU0_SQC2(4, &f, 0x00);
    len = __builtin_sqrtf(f.d.x * f.d.x + f.d.y * f.d.y + f.d.z * f.d.z);
    if (len < ra + rb) {
        if (dist != 0) {
            *dist = len;
        }
        if (pos != 0) {
            cVec_copy3(pos, a);
        }
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002DAF68);
#endif
