/* sn-2.95.3-136 (C++ unit, -fno-exceptions, as sn). NON_MATCHING func_001646C0: same length as retail (173 words), 23 instructions off. The only difference is where two address loads land: retail sets s2 = sp+0x10 next to the first point load and s1 = sp+0x20 next to the second, ahead of the vector copies; the build sets each just before the copy that reads through it, after the scale. Binding the temporary's address first in the helper, building the product in a caller's slot, function-level y/prod, and moving the copy-out into the helper all give the same 23. Without as sn the unsigned compare's branch slots differ (174 words); the plain-macro form without the helper is 39 off. */
extern "C" {

#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cVec.h"
#include "godhand/libm.h"

/* A Hermite curve: num points, each with its tangent. */
typedef struct cHermiteCurve {
    cVec *point;                        /* 0x0 */
    cVec *tangent;                      /* 0x4 */
    int num;                            /* 0x8 */
} cHermiteCurve;

/* (0, 0, 0, 1). 002a9df8.c reads it as const float[4]; symbol_addrs and the data
 * split still size it as one word. */
extern cVec D_003BD880;

/* *d = *a * s (operator* by a scalar: a copy of *a scaled in x, y and z). */
static __inline__ void cVec_scaleTo(cVec *d, cVec *a, float s)
{
    cVec t;

    CVEC_COPY(t, a);
    CVEC_MUL_SCALAR(t, s);
    CVEC_COPY(*d, &t);
}

/* *ret = the curve c at t (segment int(t), Hermite blend of its two points and
 * tangents); D_003BD880 past the last point. Returns ret. */
__attribute__((section(".text.func_001646C0")))
cVec *func_001646C0(cVec *ret, cHermiteCurve *c, float t)
{
    unsigned char seg;
    int last;

    if ((float)(unsigned int)(c->num - 1) < t) {
        CVEC_COPY(*ret, &D_003BD880);
        return ret;
    }
    seg = (int)t;
    t -= seg;
    last = c->num - 1;
    if (seg == last) {
        seg = last - 1;
    }
    cVec r;
    cVec_scaleTo(&r, &c->point[seg], 2.0f * func_003A1F38(t, 3.0f) - func_003A1F38(t, 2.0f) * 3.0f + 1.0f);
    {
        cVec y;
        cVec_scaleTo(&y, &(c->point + seg)[1], func_003A1F38(t, 3.0f) * -2.0f + func_003A1F38(t, 2.0f) * 3.0f);
        CVEC_ADD_TO(r, &y);
    }
    {
        cVec y;
        cVec_scaleTo(&y, &c->tangent[seg], func_003A1F38(t, 3.0f) - 2.0f * func_003A1F38(t, 2.0f) + t);
        CVEC_ADD_TO(r, &y);
    }
    {
        cVec y;
        cVec_scaleTo(&y, &(c->tangent + seg)[1], func_003A1F38(t, 3.0f) - func_003A1F38(t, 2.0f));
        CVEC_ADD_TO(r, &y);
    }
    CVEC_COPY(*ret, &r);
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001646C0);
#endif

}
