/* NON_MATCHING func_00136030 (sn-2.95.3-136): point inside a triangle. Retail leaves a nop
 * after the first bc1t; ours turns it into bc1tl with abs.s in the delay slot. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void sceVu0Normalize(void *a0, void *a1);
extern void sceVu0OuterProduct(void *a0, void *a1, void *a2);
extern float sceVu0InnerProduct(void *a0, void *a1);

/* Whether pt, on the plane of triangle tri, lies inside it. */
int func_00136030(cVec *tri, cVec *pt)
{
    struct {
        cVec a;                         /* 0x00 corners seen from pt */
        cVec b;                         /* 0x10 */
        cVec c;                         /* 0x20 */
        cVec n1;                        /* 0x30 */
        cVec n2;                        /* 0x40 */
        cVec n3;                        /* 0x50 */
    } f;
    float d;

    VU0_ZERO_VSUB_XYZ_MEM(&f, 0x10, &tri[0], pt);
    VU0_LQC2(4, &f.b, 0);
    VU0_SQC2(4, &f, 0x00);
    VU0_ZERO_VSUB_XYZ_MEM(&f, 0x20, &tri[1], pt);
    VU0_LQC2(4, &f.c, 0);
    VU0_SQC2(4, &f, 0x10);
    VU0_ZERO_VSUB_XYZ_MEM(&f, 0x30, &tri[2], pt);
    VU0_LQC2(4, &f.n1, 0);
    VU0_SQC2(4, &f, 0x20);
    sceVu0Normalize(&f.a, &f.a);
    sceVu0Normalize(&f.b, &f.b);
    sceVu0Normalize(&f.c, &f.c);
    VU0_SQC2_VF0(&f, 0x30);
    VU0_SQC2_VF0(&f, 0x40);
    sceVu0OuterProduct(&f.n1, &f.b, &f.c);
    sceVu0OuterProduct(&f.n2, &f.c, &f.a);
    d = sceVu0InnerProduct(&f.n1, &f.n2);
    if (!(d < 0.0f)) {
        VU0_SQC2_VF0(&f, 0x50);
        sceVu0OuterProduct(&f.n3, &f.a, &f.b);
        d = sceVu0InnerProduct(&f.n1, &f.n3);
        if (!(d < 0.0f)) {
            return 1;
        }
    }
    if (__builtin_fabsf(d) >= 1e-6f) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00136030);
#endif
