/* NON_MATCHING func_001947C8 (sn-2.95.3-136, fp_hazard_rules mtc1): part follows the player inside a box. Remaining differences are scheduling and registers only: the early-exit branch takes its delay slot from the epilogue, the step byte and the constant 1 of the switch swap $v0/$v1, and retail sets up capVu0LengthSq's argument before the two vector copies. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cSnd.h"
#include "godhand/capVu0.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

/* An object whose part 1 slides after the player on x and z inside a box. */
typedef struct EmBoxFollow {
    cGameObj obj;                       /* 0x000 */
    char unk5AC[0xAF0 - 0x5AC];
    short timer;                        /* 0xAF0 frames left in the step */
    unsigned char prevPhase;            /* 0xAF2 phase before the follow ended */
    char unkAF3[5];
    float xMin;                         /* 0xAF8 */
    float xMax;                         /* 0xAFC */
    float zMin;                         /* 0xB00 */
    float zMax;                         /* 0xB04 */
    char unkB08[8];
    cVec home;                          /* 0xB10 where the part heads while the player is outside */
    int se;                             /* 0xB20 the sound started with the follow, 0 if none */
} EmBoxFollow;

/* Ends the follow: back to phase 2, remembering the phase it was in. */
#define BOXFOLLOW_END(self)                                         \
    {                                                               \
        (self)->prevPhase = (self)->obj.phase;                      \
        (self)->obj.phase = 2;                                      \
        (self)->obj.step = 0;                                       \
        (self)->obj.stepArg = 0;                                    \
    }

/* Moves p toward t by step, or by a quarter step once within 0.7. A macro on
 * the two fields: as an inline function the compiler keeps t in a register,
 * where retail reads it again after each store to p. */
#define BOXFOLLOW_STEP(p, t, step)                                  \
    {                                                               \
        float d_ = (p) - (t);                                       \
                                                                    \
        if (0.7f * 0.7f < d_ * d_) {                                \
            if ((t) < (p)) {                                        \
                (p) = (p) - (step);                                 \
            }                                                       \
            if ((p) < (t)) {                                        \
                (p) = (p) + (step);                                 \
            }                                                       \
        } else if (0.25f < d_ * d_) {                               \
            if ((t) < (p)) {                                        \
                (p) = (p) - (step) * 0.25f;                         \
            }                                                       \
            if ((p) < (t)) {                                        \
                (p) = (p) + (step) * 0.25f;                         \
            }                                                       \
        }                                                           \
    }

/* Part 1 follows the player's lock-on point on x and z, staying inside the
 * box; the follow starts a sound, runs a short wait and ends once the part
 * reaches the target or the step time runs out. */
__attribute__((section(".text.func_001947C8")))
void func_001947C8(EmBoxFollow *self)
{
    int frame[3];
    cOmBase *part;
    cGameObj *pl;
    cVec pos;
    cVec target;
    float step;

    if (cOmBase_childAt((cOmBase *)self, frame, 1) == 0) {
        return;
    }
    step = cEmManage_GetSpeedRate(&D_005864F0) * 0.06f;
    part = cOmBase_childAt((cOmBase *)self, frame, 1);
    VU0_LQC2_SQC2_MEM(4, &pos, part->pos);
    pl = Getplayer();
    VU0_LQC2_SQC2_MEM(4, &target, ((cVec *(*)(void *))pl->vt->lockOn)((char *)pl + pl->vt->lockOnDelta));
    if (target.x < self->xMin - 1.0f || self->xMax + 1.0f < target.x
        || target.z < self->zMin - 1.0f || self->zMax + 1.0f < target.z) {
        cVec_copy3(&target, &self->home);
    }
    switch (self->obj.step) {
    case 0:
        if (self->se == 0) {
            cOmBase *src = cOmBase_childAt((cOmBase *)self, frame, 1);

            self->se = cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xB5, self, 0, (int)src, 0, 0);
        }
        self->timer = 30;
        self->obj.step = 1;
        self->obj.stepArg = 0;
        /* falls through: the wait starts in the same frame */
    case 1:
        if (--self->timer < 0) {
            self->timer = 90;
            self->obj.step = 2;
        }
        break;
    case 2:
        BOXFOLLOW_STEP(pos.x, target.x, step);
        BOXFOLLOW_STEP(pos.z, target.z, step);
        {
            cVec a;
            cVec b;

            VU0_LQC2_SQC2_MEM(4, &a, &pos);
            VU0_LQC2_SQC2_MEM(4, &b, &target);
            a.y = 0.0f;
            b.y = 0.0f;
            VU0_VSUB_XYZ_IP(&a, 0, &b);
            if (capVu0LengthSq(&a) < 0.7f * 0.7f) {
                BOXFOLLOW_END(self);
            }
        }
        if (--self->timer < 0) {
            BOXFOLLOW_END(self);
        }
        break;
    }
    pos.x = pos.x < self->xMin ? self->xMin : (self->xMax < pos.x ? self->xMax : pos.x);
    pos.z = pos.z < self->zMin ? self->zMin : (self->zMax < pos.z ? self->zMax : pos.z);
    cVec_copy3(part->pos, &pos);
    self->obj.pos->z = pos.z;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001947C8);
#endif
