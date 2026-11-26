/* sn-2.95.3-136 */
/* NON_MATCHING func_0027D400 (sn-2.95.3-136, fp_hazard_rules fdiv): same length, 38 instructions off,
 * all register choices, the same pairs as its sibling func_0028AE18: retail gives &tmp_ s1, inv s0,
 * the swing vector s5 and &push s4 (this C swaps each pair), and keeps the clamped angle in $f2. The
 * inv * swing block is CVEC_SET_APPLY without the operator= (the copy into push has no self-check). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/fpu.h"

/* This enemy keeps a swing vector at 0x15C0 and its angular speed at 0x15D0, over the cEm00 words
 * named stepScale and hitWait. */
#define EM_SWING(self) ((cVec *)((char *)(self) + 0x15C0))
#define EM_SWING_SPD(self) (*(float *)((char *)(self) + 0x15D0))

#define SWING_PART  0x13
#define SWING_MAX   0.5235988f

/* Swings a hanging part: the body's movement pushes the swing vector, which tilts the part about x
 * within 30 degrees; the tilt springs back and its speed is damped. */
__attribute__((section(".text.func_0027D400")))
void func_0027D400(cEm00 *self)
{
    int frame[3];
    float inv[16];
    cVec push;
    CVEC_TEMPS;
    cParts *part;
    cVec *swing;
    float len;
    float a;

    part = (cParts *)cOmBase_childAt((cOmBase *)self, frame, SWING_PART);
    if (part == 0) {
        return;
    }
    CVEC_ZERO(push);
    CVEC_SUB(self->pos, &self->posA);
    push.x = ret_.x;
    push.z = ret_.z;
    push.y = 0.0f;
    swing = EM_SWING(self);
    CVEC_ADD_TO(*swing, &push);
    MtxInverse(inv, part->mtx);
    {
        cVec *a_ = swing;
        void *m_ = inv;
        cVec *t_ = &tmp_;

        VU0_LQC2(4, a_, 0);
        VU0_SQC2_MEM(4, &tmp_, 0);
        sceVu0ApplyMatrix(t_, m_, t_);
        VU0_LQC2(4, t_, 0);
        VU0_SQC2_MEM(4, &ret_, 0);
    }
    push.x = ret_.x;
    push.y = ret_.y;
    push.z = ret_.z;
    FPU_SQRT_S(len, push.x * push.x + push.z * push.z);
    a = -capVu0Atan2(push.y, len);
    if (a > SWING_MAX) {
        a = SWING_MAX;
    }
    if (a < -SWING_MAX) {
        a = -SWING_MAX;
    }
    part->rot.x += a * 0.5f * self->speedRate;
    part->rot.x += EM_SWING_SPD(self) * self->speedRate;
    if (part->rot.x > SWING_MAX) {
        part->rot.x = SWING_MAX;
        EM_SWING_SPD(self) = 0.0f;
    }
    if (part->rot.x < -SWING_MAX) {
        part->rot.x = -SWING_MAX;
        EM_SWING_SPD(self) = 0.0f;
    }
    EM_SWING_SPD(self) *= 1.0f - self->speedRate * 0.2f;
    EM_SWING_SPD(self) += -part->rot.x * 0.5f * self->speedRate;
    push.x = 0.0f;
    push.y = 0.0f;
    push.z = 0.03f;
    sceVu0ApplyMatrix(&push, part->mtx, &push);
    CVEC_PUT(swing, push);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0027D400);
#endif
