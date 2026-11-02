/* sn-2.95.3-136 */
#include "godhand/cCollisionSolid.h"
#include "godhand/cVec.h"

/* The larger of a and b. */
static __inline__ float maxf(float a, float b)
{
    return a < b ? b : a;
}

/* Whether the sphere at center with the given radius touches the triangle a b c. A bounding
 * sphere around the centroid rejects far triangles first. On a hit the closest point of the
 * triangle goes to hit (if given). */
__attribute__((section(".text.SphereTriangle")))
int SphereTriangle(cVec *center, float radius, cVec *a, cVec *b, cVec *c, cVec *hit)
{
    cVec near;
    cVec mid;
    cVec sum;
    CVEC_TEMPS;
    float da;
    float db;
    float dc;
    float m;
    float rr;

    CVEC_ZERO(near);
    CVEC_INIT_ADD(ret_, a, b);
    CVEC_INIT_ADD(sum, &ret_, c);
    CVEC_INIT_MUL(mid, &sum, 0.333333343f);
    da = cVec_distSq(&mid, a);
    db = cVec_distSq(&mid, b);
    dc = cVec_distSq(&mid, c);
    m = maxf(db, da);
    m = maxf(m, dc);
    rr = radius * radius;
    if (m + rr < cVec_distSq(center, &mid)) {
        return 0;
    }
    func_00135348(&near, center, a, b, c);
    if (cVec_distSq(center, &near) <= rr) {
        if (hit != 0) {
            cVec_copy3(hit, &near);
        }
        return 1;
    }
    return 0;
}
