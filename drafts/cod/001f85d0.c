/* sn-2.95.3-136 */
#include "godhand/cArea.h"
#include "godhand/cVec.h"
#include "include_asm.h"

/* waiting: function-level cVec temporaries. The chained sum below has one
 * return slot per operator (0x50..0x80, outermost first) and one shared
 * temporary (0x90); the block-local temporaries here get a slot each. */

/* r = *a + *b; (operator+: a copy of *a, added to in place, into the return slot r) */
#define CVEC_ADD_INTO(r, a, b)                                  \
    {                                                           \
        cVec tmp_;                                              \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VADD_XYZ_IP(&tmp_, 0, b_);                          \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &(r), 0);                               \
    }

/* r = *a * s; (operator* by a scalar: a copy of *a, scaled in place, into the return slot r) */
#define CVEC_MUL(r, a, s)                                       \
    {                                                           \
        cVec tmp_;                                              \
        cVec *a_ = (a);                                         \
        float s_ = (s);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VSCALE_XYZ_MEM(&tmp_, 0, s_);                       \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &(r), 0);                               \
    }

/* d = r; (operator=, xyz only) */
#define CVEC_ASSIGN(d, r)                                       \
    {                                                           \
        if (&(d) != &(r)) {                                     \
            (d).x = (r).x;                                      \
            (d).y = (r).y;                                      \
            (d).z = (r).z;                                      \
        }                                                       \
    }

extern int func_001573C8(float *pt, cVec *a, cVec *b, cVec *c, cVec *d);

#ifdef NON_MATCHING
/* Is point pt inside the quad area scaled by scale about its centre: inside
 * the scaled height band, then inside the four corners pulled toward their
 * centroid. */
__attribute__((section(".text.func_001F85D0")))
int func_001F85D0(cArea *self, float *pt, float scale)
{
    cVec q[4];
    cVec c;
    cVec quarter;
    cVec sum3;
    cVec sum2;
    cVec sum1;
    float mid;
    float lo;
    float hi;

    CVEC_ZERO(q[0]);
    CVEC_ZERO(q[1]);
    CVEC_ZERO(q[2]);
    CVEC_ZERO(q[3]);
    CVEC_ZERO(c);
    mid = self->height * 0.5f + self->y;
    lo = (self->y - mid) * scale + mid;
    hi = (self->y + self->height - mid) * scale + mid;
    if (pt[1] < lo) {
        return 0;
    }
    if (hi < pt[1]) {
        return 0;
    }
    q[0].x = self->corner[0].x;
    q[0].y = 0.0f;
    q[0].z = self->corner[0].z;
    q[1].x = self->corner[1].x;
    q[1].y = 0.0f;
    q[1].z = self->corner[1].z;
    q[2].x = self->corner[2].x;
    q[2].y = 0.0f;
    q[2].z = self->corner[2].z;
    q[3].x = self->corner[3].x;
    q[3].y = 0.0f;
    q[3].z = self->corner[3].z;
    CVEC_ADD_INTO(sum1, &q[0], &q[1]);
    CVEC_ADD_INTO(sum2, &sum1, &q[2]);
    CVEC_ADD_INTO(sum3, &sum2, &q[3]);
    CVEC_MUL(quarter, &sum3, 0.25f);
    CVEC_ASSIGN(c, quarter);
    q[0].x = (q[0].x - c.x) * scale + c.x;
    q[0].y = 0.0f;
    q[0].z = (q[0].z - c.z) * scale + c.z;
    q[1].x = (q[1].x - c.x) * scale + c.x;
    q[1].y = 0.0f;
    q[1].z = (q[1].z - c.z) * scale + c.z;
    q[2].x = (q[2].x - c.x) * scale + c.x;
    q[2].y = 0.0f;
    q[2].z = (q[2].z - c.z) * scale + c.z;
    q[3].x = (q[3].x - c.x) * scale + c.x;
    q[3].y = 0.0f;
    q[3].z = (q[3].z - c.z) * scale + c.z;
    return func_001573C8(pt, &q[0], &q[1], &q[2], &q[3]) != 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F85D0);
#endif
