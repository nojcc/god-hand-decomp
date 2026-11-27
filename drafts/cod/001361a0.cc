/* sn-2.95.3-136 (C++ unit, -fno-exceptions). NON_MATCHING func_001361A0: 176 words vs retail 173, frame and slots exact. Two differences: n (0x20) and the 0x30 address swap s7/fp, and the first three corner tests branch with bc1tl (abs.s pulled into the slot) where retail has bc1t with the next block's load in the slot. Only a loop around the tests gives retail's non-likely bc1t (reorg predicts a jump out of a loop as not taken), and that is not a form to ship. Nested ifs and early returns: 177 words. */
extern "C" {

#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cVec.h"
#include "godhand/sceVu0.h"

/* w = a x b; returns the dot product of n and w. */
static __inline__ float cVec_turn(cVec *w, cVec *n, cVec *a, cVec *b)
{
    sceVu0OuterProduct(w, a, b);
    return sceVu0InnerProduct(n, w);
}

/* 1 if p lies inside the quad q[0..3] seen along the quad's normal: each
 * corner-to-corner turn, taken from p, agrees with the normal (or is within
 * 1e-6 of square). */
__attribute__((section(".text.func_001361A0")))
int func_001361A0(cVec *q, cVec *p)
{
    cVec e[2];
    cVec n;
    float d;
    int i;

    {
        cVec *z = e;

        for (i = 1; i != -1; i--) {
            VU0_SQC2_VF0(z, 0);
            z++;
        }
    }
    CVEC_ZERO(n);
    {
        cVec r;
        cVec t;

        VU0_ZERO_VSUB_XYZ_MEM(&t, 0, &q[1], &q[0]);
        CVEC_COPY(r, &t);
        sceVu0Normalize(&e[0], &r);
    }
    {
        cVec r;
        cVec t;

        VU0_ZERO_VSUB_XYZ_MEM(&t, 0, &q[3], &q[0]);
        CVEC_COPY(r, &t);
        sceVu0Normalize(&e[1], &r);
    }
    sceVu0OuterProduct(&n, &e[0], &e[1]);
    cVec a;
    cVec b;
    cVec c;
    cVec dd;

    CVEC_ZERO(a);
    CVEC_ZERO(b);
    CVEC_ZERO(c);
    CVEC_ZERO(dd);
    {
        cVec r;
        cVec t;

        VU0_ZERO_VSUB_XYZ_MEM(&t, 0, &q[0], p);
        CVEC_COPY(r, &t);
        sceVu0Normalize(&a, &r);
    }
    {
        cVec r;
        cVec t;

        VU0_ZERO_VSUB_XYZ_MEM(&t, 0, &q[1], p);
        CVEC_COPY(r, &t);
        sceVu0Normalize(&b, &r);
    }
    {
        cVec r;
        cVec t;

        VU0_ZERO_VSUB_XYZ_MEM(&t, 0, &q[2], p);
        CVEC_COPY(r, &t);
        sceVu0Normalize(&c, &r);
    }
    {
        cVec r;
        cVec t;

        VU0_ZERO_VSUB_XYZ_MEM(&t, 0, &q[3], p);
        CVEC_COPY(r, &t);
        sceVu0Normalize(&dd, &r);
    }
    if ((d = cVec_turn(&e[0], &n, &a, &b)) < 0.0f
        || (d = cVec_turn(&e[0], &n, &b, &c)) < 0.0f
        || (d = cVec_turn(&e[0], &n, &c, &dd)) < 0.0f
        || (d = cVec_turn(&e[0], &n, &dd, &a)) < 0.0f) {
        return __builtin_fabsf(d) < 1e-6f;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001361A0);
#endif

}
