/* sn-2.95.3-136 */
/* func_001329C0 (ground line test, fp_hazard_rules fdiv): everything but two spots matches. At
 * entry retail holds self->pos in v1 and &tmp in v0 (swapped here). Copying `to` into `from`
 * after the floor walk, retail reads to.y and to.z through the &to register and interleaves the
 * loads with the stores; this build folds them to stack offsets and loads all three first. */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

extern float sqrtf(float x);
extern float capVu0LengthSq(void *a0);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern int func_0012ED60(void *db, void *from, void *to, void *hit, int a4, int a5, int a6, void *out,
                         int max, void *count, int a10, int a11, int a12, int a13);
extern char D_005CAE50[];

/* Length of v. */
static __inline__ float cVec_length(cVec *v)
{
    return __builtin_sqrtf(capVu0LengthSq(v));
}

/* Tests the line from the object's last position to its current one at ground level: walks the
 * floor along the way in 1.5 steps to find the height to start from, then checks the line down by
 * drop. Returns 1 on a hit. */
__attribute__((section(".text.func_001329C0")))
int func_001329C0(cGameObj *self, void *hit, int mask, void *out, float drop)
{
    cVec from;
    cVec to;
    cVec dir;
    cVec ret;
    cVec tmp;
    cVec step;
    float len;
    float dist;
    float top;
    int useOut;

    cVec_zero(&from);
    cVec_zero(&to);
    cVec_zero(&dir);
    VU0_ZERO_VSUB_XYZ_TO(&tmp, 0, self->pos, &self->posA);
    VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
    dir.x = ret.x;
    dir.z = ret.z;
    dir.y = 0.0f;
    len = cVec_length(&dir);
    cVec_unitOf(&tmp, &dir);
    VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
    cVec_copy3(&dir, &ret);
    if (len >= 1.5f) {
        top = self->posA.y + 1.0f;
        dist = 1.5f;
        for (;;) {
            VU0_LQC2_SQC2_MEM(4, &step, &dir);
            VU0_VSCALE_XYZ_MEM(&step, 0, dist);
            VU0_LQC2_SQC2_MEM(4, &tmp, &step);
            VU0_LQC2_SQC2_MEM(4, &step, &self->posA);
            VU0_VADD_XYZ_IP(&step, 0, &tmp);
            VU0_LQC2_SQC2_MEM(4, &ret, &step);
            cVec_copy3(&from, &ret);
            from.y = top;
            cVec_copy3(&to, &from);
            to.y -= drop;
            cVec_zero(&ret);
            if (func_0012ED60(D_005CAE50, &from, &to, &ret, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) != 0)
                top = ret.y + 1.0f;
            dist += 1.5f;
            if (dist >= len)
                break;
        }
        cVec_copy3(&to, self->pos);
        cVec_copy3(&from, &to);
        from.y = top;
        to.y -= drop;
    } else {
        cVec_copy3(&to, self->pos);
        cVec_copy3(&from, &to);
        from.y += 1.0f;
        to.y -= drop;
    }
    useOut = 0;
    if (out != 0)
        useOut = 1;
    if (ChkLine(&from, &to, hit, mask, 2, 0x400, out, useOut, 0, 0, 0, 0, 1) != 0)
        return 1;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001329C0);
#endif
