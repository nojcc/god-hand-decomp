/* sn-2.95.3-136 */
/* ChkLine (stepped line test, fp_hazard_rules fdiv): the stack layout and the call sequence match.
 * Retail holds the point scratch address in two registers (one per point) and spills the a2/a3
 * arguments to the stack, where this build keeps them in s7/s8. Retail also branches around the
 * piece = 1.0 clamp without branch-likely and loads 1.0 after the divide; this build moves the
 * clamp out of line with bc1tl and hoists the constant above the divide. */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

extern float capVu0Length(void *v);
extern int func_0012ED60(void *db, cVec *from, cVec *to, void *hit, int a4, int a5, int a6, void *a7,
                         int a8, int a9, int a10, int a11, int a12, int stepped);
extern char D_005CAE50[];

/* Distance from a to b. */
static __inline__ float cVec_dist(cVec *b, cVec *a)
{
    cVec d;
    cVec t;

    VU0_ZERO_VSUB_XYZ_TO(&t, 0, b, a);
    VU0_LQC2_SQC2_MEM(4, &d, &t);
    return capVu0Length(&d);
}

/* Line test from a to b against the collision manager. With step set, walks the line in pieces
 * about 8 long (each overlapping the last by 1%) and returns 1 at the first piece that hits;
 * otherwise tests the whole line at once. */
__attribute__((section(".text.ChkLine")))
int ChkLine(cVec *a, cVec *b, void *hit, int a3, int a4, int a5, void *a6, int a7, int a8, int a9,
            int a10, int a11, unsigned char step)
{
    float len;
    float piece;
    float t0;
    float t1;

    if (step != 0) {
        len = cVec_dist(b, a);
        {
        cVec seg[2];
        cVec dir;
        cVec ret;
        cVec tmp;
        cVec pt;
        cVec *p;
        float dist;
        int i;

        p = seg;
        i = 1;
        do {
            cVec_zero(p);
            p++;
        } while (--i != -1);
        VU0_ZERO_VSUB_XYZ_TO(&tmp, 0, b, a);
        VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
        cVec_unitOf(&tmp, &ret);
        VU0_LQC2_SQC2_MEM(4, &dir, &tmp);
        if (len == 0.0f)
            return 0;
        piece = 8.0f / len;
        if (piece > 1.0f)
            piece = 1.0f;
        else if (piece <= 0.0f)
            return 0;
        t0 = 0.0f;
        t1 = piece;
        for (;;) {
            dist = len * t0;
            VU0_LQC2_SQC2_MEM(4, &pt, &dir);
            VU0_VSCALE_XYZ_MEM(&pt, 0, dist);
            VU0_LQC2_SQC2_MEM(4, &tmp, &pt);
            VU0_LQC2_SQC2_MEM(4, &pt, a);
            VU0_VADD_XYZ_IP(&pt, 0, &tmp);
            VU0_LQC2_SQC2_MEM(4, &ret, &pt);
            cVec_copy3(&seg[0], &ret);
            dist = len * t1;
            VU0_LQC2_SQC2_MEM(4, &pt, &dir);
            VU0_VSCALE_XYZ_MEM(&pt, 0, dist);
            VU0_LQC2_SQC2_MEM(4, &tmp, &pt);
            VU0_LQC2_SQC2_MEM(4, &pt, a);
            VU0_VADD_XYZ_IP(&pt, 0, &tmp);
            VU0_LQC2_SQC2_MEM(4, &ret, &pt);
            cVec_copy3(&seg[1], &ret);
            if (func_0012ED60(D_005CAE50, &seg[0], &seg[1], hit, a3, a4, a5, a6, a7, a8, a9, a10,
                              a11, step) != 0)
                return 1;
            if (t1 >= 1.0f)
                return 0;
            t0 = t0 + piece - piece / 100.0f;
            t1 = t0 + piece;
            if (t1 > 1.0f)
                t1 = 1.0f;
        }
        }
    }
    return func_0012ED60(D_005CAE50, a, b, hit, a3, a4, a5, a6, a7, a8, a9, a10, a11, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", ChkLine);
#endif
