/* NON_MATCHING func_001377E8 (sn-2.95.3-136, fp_hazard_rules "fdiv", c_flags_add "-f=-ffast-math" for the bare sqrt.s): the stack slots differ. Retail puts the first difference at sp+0x10 and later reuses it for the unit direction, the second difference at sp+0x30, and the hit point in the direction slot at sp+0x20; ours gives each vector its own slot or shares one slot for every temporary. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/sceVu0.h"

extern float sceVu0InnerProduct(void *v0, void *v1);

/* *out = a - b (x, y, z; w zero). */
static __inline__ void cVec_subOf(cVec *out, cVec *a, cVec *b)
{
    cVec d;

    VU0_ZERO_VSUB_XYZ_MEM(&d, 0, a, b);
    VU0_LQC2_SQC2_MEM(4, out, &d);
}

/* *out = v scaled to length 1. */
static __inline__ void cVec_normal(cVec *out, cVec *v)
{
    cVec n;

    cVec_unitOf(&n, v);
    VU0_LQC2_SQC2_MEM(4, out, &n);
}

/* *out = v with x, y and z scaled by f. */
static __inline__ void cVec_scaledOf(cVec *out, cVec *v, float f)
{
    cVec t;

    VU0_LQC2_SQC2_MEM(4, &t, v);
    VU0_VSCALE_XYZ_MEM(&t, 0, f);
    VU0_LQC2_SQC2_MEM(4, out, &t);
}

/* *out = a + b (x, y, z). */
static __inline__ void cVec_addOf(cVec *out, cVec *a, cVec *b)
{
    cVec t;

    VU0_LQC2_SQC2_MEM(4, &t, a);
    VU0_VADD_XYZ_IP(&t, 0, b);
    VU0_LQC2_SQC2_MEM(4, out, &t);
}

/* Tests the segment start..end against the sphere (center, radius). On a hit it returns 1 and,
 * when hit is given, stores the first point of contact there. */
__attribute__((section(".text.func_001377E8")))
int func_001377E8(cVec *start, cVec *end, cVec *center, float radius, cVec *hit)
{
    cVec toStart;
    cVec dir;
    cVec u;
    float b;
    float c;
    float disc;
    float t;
    float dx, dy, dz;

    cVec_subOf(&toStart, start, center);
    cVec_subOf(&dir, end, start);
    cVec_normal(&u, &dir);
    b = sceVu0InnerProduct(&toStart, &u);
    c = sceVu0InnerProduct(&toStart, &toStart) - radius * radius;
    if (c > 0.0f && b > 0.0f)
        return 0;
    disc = b * b - c;
    if (disc < 0.0f)
        return 0;
    t = -b - __builtin_sqrtf(disc);
    dx = end->x - start->x;
    dy = end->y - start->y;
    dz = end->z - start->z;
    if (dx * dx + dy * dy + dz * dz < t * t)
        return 0;
    if (t < 0.0f)
        t = 0.0f;
    if (hit != 0) {
        cVec step;
        cVec at;

        cVec_scaledOf(&step, &u, t);
        cVec_addOf(&at, start, &step);
        cVec_copy3(hit, &at);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001377E8);
#endif
