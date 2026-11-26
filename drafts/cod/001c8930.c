/* sn-2.95.3-136 */
/* NON_MATCHING func_001C8930 (sn-2.95.3-136, fp_hazard_rules fdiv): 2 instructions off. Retail forms
 * &tmp_ for the vel * rate copy in a0, this C in v1. The vel * rate block is operator* by a scalar
 * into the return slot, which cVec.h has no macro for yet. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cEmManage.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"
#include "godhand/fpu.h"
#include "godhand/capVu0.h"

#define FLY_SPIN_STEP   0.87266463f     /* 50 degrees per frame */
#define FLY_GRAVITY     0.013f
#define FLY_FRAMES      15.0f

/* A thrown piece that flies along its velocity until its timer runs out. */
typedef struct cOmFlyPiece {
    cOmBase base;
    char unk5E0[0x30];
    cVec vel;                           /* 0x610 */
    float timer;                        /* 0x620 frames left */
} cOmFlyPiece;

extern void func_001C8DD8(char *a0);

/* Fly the piece: face it along its velocity on the first frame, then spin the
 * collision body, move by the velocity under gravity and remove the piece when
 * its timer runs out. */
__attribute__((section(".text.func_001C8930")))
void func_001C8930(cOmFlyPiece *self)
{
    int frame[3];
    CVEC_TEMPS;
    float rate = cEmManage_GetSpeedRate(&D_005864F0);
    cOmBase *child = cOmBase_childAt(&self->base, frame, 0);
    float len;

    switch (self->base.step) {
    case 0:
        FPU_SQRT_S(len, self->vel.x * self->vel.x + self->vel.z * self->vel.z);
        self->base.rot.x = -capVu0Atan2(self->vel.y, len);
        self->base.rot.y = capVu0Atan2(self->vel.x, self->vel.z);
        self->timer = FLY_FRAMES;
        self->base.step++;
        self->base.rot.z = 0.0f;
    case 1:
        if (child != 0) {
            child->rot.x += rate * FLY_SPIN_STEP;
        }
        {
            cVec *a_ = &self->vel;
            cVec *t_ = &tmp_;

            VU0_LQC2(4, a_, 0);
            VU0_SQC2_MEM(4, &tmp_, 0);
            VU0_VSCALE_XYZ_MEM(&tmp_, 0, rate);
            VU0_LQC2(4, t_, 0);
            VU0_SQC2_MEM(4, &ret_, 0);
        }
        CVEC_ADD_TO(*self->base.pos, &ret_);
        self->timer -= rate;
        self->vel.y -= rate * FLY_GRAVITY;
        if (self->timer <= 0.0f) {
            func_001C8DD8((char *)self);
            cOmBase_dieCommon(&self->base);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C8930);
#endif
