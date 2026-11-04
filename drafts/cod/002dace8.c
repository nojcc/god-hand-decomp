/* NON_MATCHING func_002DACE8 (sn-2.95.3-136, fp_hazard_rules fdiv, -ffast-math): 161 words vs 159.
 * Retail keeps &p in a saved register (one more saved register, 0x10 more frame) and computes the
 * second square root's sum after the first sqrt.s; register numbering differs throughout. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
extern float capVu0Atan2(float y, float x);
extern void func_0030A700(void *dst, void *src, float rx);
extern void func_0030A7B8(void *dst, void *src, float ry);
extern void func_0030A538(cVec *dst, cVec *src);
extern void sceVu0InversMatrix(float *dst, float *src);

/* Whether pt lies in the box along the segment from -> to (its length deep, halfW + r wide and
 * halfH + r high, in the segment's own frame); on a hit, optionally report the distance from the axis
 * and the nearest point on the axis. */
__attribute__((section(".text.func_002DACE8")))
int func_002DACE8(cVec *from, cVec *to, cVec *pt, float *dist, cVec *onAxis, float halfW, float halfH,
                  float r)
{
    cVec d;
    cVec tmp;
    float m[16];
    float inv[16];
    cVec p;
    cVec q;
    cVec t;
    float flat;
    float len;

    VU0_ZERO_VSUB_XYZ_MEM(&tmp, 0, to, from);
    VU0_LQC2_SQC2_MEM(4, &d, &tmp);
    flat = __builtin_sqrtf(d.x * d.x + d.z * d.z);
    len = __builtin_sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m, 0x30);
    VU0_SQC2(5, m, 0x20);
    VU0_SQC2(6, m, 0x10);
    VU0_SQC2(7, m, 0x0);
    func_0030A700(m, m, -capVu0Atan2(d.y, flat));
    func_0030A7B8(m, m, capVu0Atan2(d.x, d.z));
    func_0030A538((cVec *)&m[12], from);
    sceVu0InversMatrix(inv, m);
    VU0_LQC2_SQC2_MEM(4, &p, pt);
    cVec_applyMatrix(&p, inv);
    VU0_LQC2_SQC2_MEM(4, &tmp, &p);
    if (!(0.0f < tmp.z) || !(tmp.z < len)) {
        return 0;
    }
    if (!(-(halfH + r) < tmp.y) || !(tmp.y < halfH + r)) {
        return 0;
    }
    if (!(-(halfW + r) < tmp.x) || !(tmp.x < halfW + r)) {
        return 0;
    }
    if (dist != 0) {
        *dist = __builtin_sqrtf(tmp.x * tmp.x + tmp.y * tmp.y);
    }
    if (onAxis != 0) {
        cVec_set4(&p, 0.0f, 0.0f, tmp.z, 1.0f);
        VU0_LQC2_SQC2_MEM(4, &q, &p);
        cVec_applyMatrix(&q, m);
        VU0_LQC2_SQC2_MEM(4, &t, &q);
        cVec_copy3(onAxis, &t);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002DACE8);
#endif
