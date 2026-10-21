/* NON_MATCHING func_00136458 (sn-2.95.3-136): segment against the front of a triangle.
 * Retail computes &tri[1] and &tri[2] before the zeroing stores and holds &tri[2] in v1;
 * ours computes them after and uses v0. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void sceVu0OuterProduct(void *a0, void *a1, void *a2);
extern float sceVu0InnerProduct(void *a0, void *a1);
extern int func_00135EC8(void *a0, void *a1, void *a2, void *a3, void *a4);
extern int func_00136030(void *a0, void *a1);

/* Whether the segment p0 p1 crosses the front of triangle tri; the crossing point goes to out when given. */
int func_00136458(cVec *p0, cVec *p1, cVec *tri, cVec *out)
{
    struct {
        cVec n;                         /* 0x00 face normal */
        cVec hit;                       /* 0x10 */
        cVec e;                         /* 0x20 */
        cVec d;                         /* 0x30 */
        cVec d2;                        /* 0x40 */
    } f;
    cVec *e;

    VU0_SQC2_VF0(&f, 0x00);
    VU0_SQC2_VF0(&f, 0x10);
    VU0_SQC2_VF0(&f, 0x30);
    e = &f.e;
    VU0_LQC2(4, &tri[1], 0);
    VU0_LQC2(5, &tri[0], 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &f, 0x30);
    VU0_LQC2(4, &f.d, 0);
    VU0_SQC2(4, &f, 0x20);
    VU0_SQC2_VF0(&f, 0x40);
    VU0_LQC2(4, &tri[2], 0);
    VU0_LQC2(5, &tri[0], 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &f, 0x40);
    VU0_LQC2(4, &f.d2, 0);
    VU0_SQC2(4, &f, 0x30);
    sceVu0OuterProduct(&f.n, e, &f.d);
    VU0_SQC2_VF0(&f, 0x30);
    VU0_LQC2(4, p1, 0);
    VU0_LQC2(5, p0, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &f, 0x30);
    VU0_LQC2(4, &f.d, 0);
    VU0_SQC2(4, &f, 0x20);
    if (0.0f <= sceVu0InnerProduct(&f.n, e)) {
        return 0;
    }
    if (func_00135EC8(p0, p1, &f.n, tri, &f.hit) == 0) {
        return 0;
    }
    if (func_00136030(tri, &f.hit) == 0) {
        return 0;
    }
    if (out != 0) {
        cVec_copy3(out, &f.hit);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00136458);
#endif
