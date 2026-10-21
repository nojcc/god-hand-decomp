/* NON_MATCHING SphereTriangle (sn-2.95.3-136): sphere against triangle test. Retail copies each
 * vector temporary with lqc2 from a register and sqc2 straight to its stack slot; the vu0.h copy
 * macros take the destination in a register, so ours computes the slot address first. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void func_00135348(cVec *out, cVec *p, cVec *a, cVec *b, cVec *c);

/* dst = a + b, through a temporary. */
static __inline__ void cVec_add(cVec *dst, cVec *a, cVec *b)
{
    cVec t;

    VU0_LQC2(4, a, 0);
    VU0_SQC2(4, &t, 0);
    VU0_VADD_XYZ_IP(&t, 0, b);
    VU0_LQC2(4, &t, 0);
    VU0_SQC2(4, dst, 0);
}

/* dst = a * s, through a temporary. */
static __inline__ void cVec_scale(cVec *dst, cVec *a, float s)
{
    cVec t;

    VU0_LQC2(4, a, 0);
    VU0_SQC2(4, &t, 0);
    VU0_VSCALE_XYZ_MEM(&t, 0, s);
    VU0_LQC2(4, &t, 0);
    VU0_SQC2(4, dst, 0);
}

static __inline__ float cVec_distSq(cVec *a, cVec *b)
{
    float x = a->x - b->x;
    float y = a->y - b->y;
    float z = a->z - b->z;

    return x * x + y * y + z * z;
}

/* Whether the sphere at center with the given radius touches the triangle a b c. A bounding
 * sphere around the centroid rejects far triangles first. On a hit the closest point of the
 * triangle goes to hit (if given). */
int SphereTriangle(cVec *center, float radius, cVec *a, cVec *b, cVec *c, cVec *hit)
{
    cVec near;
    cVec mid;
    cVec ab;
    cVec abc;
    float da;
    float db;
    float dc;
    float m;
    float rr;

    VU0_SQC2_VF0(&near, 0);
    cVec_add(&ab, a, b);
    cVec_add(&abc, &ab, c);
    cVec_scale(&mid, &abc, 0.333333343f);
    da = cVec_distSq(&mid, a);
    db = cVec_distSq(&mid, b);
    dc = cVec_distSq(&mid, c);
    m = db < da ? da : db;
    m = m < dc ? dc : m;
    rr = radius * radius;
    if (m + rr < cVec_distSq(center, &mid)) {
        return 0;
    }
    func_00135348(&near, center, a, b, c);
    if (!(cVec_distSq(center, &near) <= rr)) {
        return 0;
    }
    if (hit != 0) {
        cVec_copy3(hit, &near);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", SphereTriangle);
#endif
