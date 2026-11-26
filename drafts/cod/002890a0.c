/* sn-2.95.3-136 */
/* NON_MATCHING func_002890A0 (sn-2.95.3-136, fp_hazard_rules fdiv): same length, 56 instructions off,
 * all register choices, the same pairs as its siblings func_0027D400 and func_0028AE18: retail gives
 * &tmp_ s1, inv s0, &bustVel s5 and &v s4 (this C swaps each pair) and keeps the clamped tilt in $f2.
 * Retail's vadd addresses bustVel from s2 although s5 already holds it; binding &bustVel before the
 * add (as here) gets its early addiu, CVEC_ADD_TO by name gets 63 off. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/mtx.h"
#include "godhand/capVu0.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"
#include "godhand/fpu.h"

extern float D_003C0460;                /* the bust spring's rest offset along z */

#define EMBUST_KIND_A    0x2A7
#define EMBUST_KIND_B    0x2AB
#define EMBUST_CHILD     29
#define EMBUST_MAX_TILT  0.5235988f

/* View of the enemies 0x2A7 and 0x2AB past cOmBase: their bust state. cEm00.h
 * names 0x15F4 and 0x1603 for other enemies' fields. */
typedef struct cEmBust {
    cOmBase base;
    char unk5E0[0x15F0 - 0x5E0];
    cVec bustVel;                       /* 0x15F0 bust velocity, kept in the bust's local frame */
    float bustSwing;                    /* 0x1600 bust swing angle rate */
} cEmBust;

#ifdef NON_MATCHING
/* Enemies 0x2A7 and 0x2AB: swing child 29 (the bust) like cObjSimple_MoveBust,
 * scaled by the enemy's speed rate. */
__attribute__((section(".text.func_002890A0")))
void func_002890A0(cEmBust *self)
{
    int frame[3];
    float inv[16];
    cVec v;
    CVEC_TEMPS;
    cOmBase *bust;
    float len;
    float tilt;

    if (self->base.emNo != EMBUST_KIND_A && self->base.emNo != EMBUST_KIND_B) {
        return;
    }
    bust = cOmBase_childAt(&self->base, frame, EMBUST_CHILD);
    if (bust == 0) {
        return;
    }
    CVEC_ZERO(v);
    CVEC_SUB(self->base.pos, &self->base.posA);
    v.x = ret_.x;
    v.z = ret_.z;
    v.y = 0.0f;
    {
        cVec *d_ = &self->bustVel;

        CVEC_ADD_TO(*d_, &v);
    }
    MtxInverse(inv, bust->mtx);
    {
        cVec *a_ = &self->bustVel;
        void *m_ = inv;
        cVec *t_ = &tmp_;

        VU0_LQC2(4, a_, 0);
        VU0_SQC2_MEM(4, &tmp_, 0);
        sceVu0ApplyMatrix(t_, m_, t_);
        VU0_LQC2(4, t_, 0);
        VU0_SQC2_MEM(4, &ret_, 0);
    }
    v.x = ret_.x;
    v.y = ret_.y;
    v.z = ret_.z;
    FPU_SQRT_S(len, v.x * v.x + v.z * v.z);
    tilt = -capVu0Atan2(v.y, len);
    if (tilt > EMBUST_MAX_TILT) {
        tilt = EMBUST_MAX_TILT;
    }
    if (tilt < -EMBUST_MAX_TILT) {
        tilt = -EMBUST_MAX_TILT;
    }
    bust->rot.x += tilt * 0.5f * self->base.speedRate;
    bust->rot.x += self->bustSwing * self->base.speedRate;
    if (bust->rot.x > EMBUST_MAX_TILT) {
        bust->rot.x = EMBUST_MAX_TILT;
        self->bustSwing = 0.0f;
    }
    if (bust->rot.x < -EMBUST_MAX_TILT) {
        bust->rot.x = -EMBUST_MAX_TILT;
        self->bustSwing = 0.0f;
    }
    self->bustSwing *= 1.0f - self->base.speedRate * 0.2f;
    v.x = 0.0f;
    v.y = 0.0f;
    self->bustSwing += -bust->rot.x * 0.5f * self->base.speedRate;
    v.z = D_003C0460;
    sceVu0ApplyMatrix(&v, bust->mtx, &v);
    CVEC_ASSIGN_VEC(self->bustVel, v);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002890A0);
#endif
