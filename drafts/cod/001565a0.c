/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cVec.h"

/* The direction in the plane of a, b, c perpendicular to b - a:
 * (b - a) x ((b - a) x (c - a)), w = 1; returns out. Retail copies the
 * second difference out of the return slot without operator='s self-check.
 * Still differs from retail: the first cross product reads the return slot
 * in x, y, z order and stores y, z, x by stack offset; here it reads z
 * first and stores y and z through the slot pointer, so the float
 * registers differ throughout. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_001565A0")))
cVec *func_001565A0(cVec *out, cVec *a, cVec *b, cVec *c) {
    cVec e1;
    cVec e2;
    CVEC_TEMPS;
    float x;
    float y;
    float z;

    CVEC_ZERO(e1);
    CVEC_ZERO(e2);
    CVEC_SET_SUB(e1, b, a);
    CVEC_SUB(c, a);
    e2.x = ret_.x;
    e2.y = ret_.y;
    e2.z = ret_.z;
    x = e1.y * e2.z - e1.z * e2.y;
    y = e1.z * e2.x - e1.x * e2.z;
    z = e1.x * e2.y - e1.y * e2.x;
    CVEC_INIT_XYZ(ret_, x, y, z);
    x = e1.y * ret_.z - e1.z * ret_.y;
    y = e1.z * ret_.x - e1.x * ret_.z;
    z = e1.x * ret_.y - e1.y * ret_.x;
    CVEC_INIT_XYZ(*out, x, y, z);
    return out;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001565A0);
#endif
