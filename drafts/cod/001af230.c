/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmSubGimmick.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cCamera.h"
#include "godhand/angle.h"
#include "godhand/capVu0.h"
#include "godhand/motion.h"
#include "godhand/rand.h"
#include "godhand/vu0.h"
#include "include_asm.h"

/* A trap that waits under the floor and rises when the player stands over it. */
typedef struct cOmRiseTrap {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageUnit *damage;                /* 0x600 */
    char unk604[4];
    short motionDelay;                  /* 0x608 frames before the rise motion starts */
    char unk60A[0x376];
    int waitKind;                       /* 0x980 0 until a wait is drawn, then 1..3 */
    short timer;                        /* 0x984 */
    char unk986[2];
    float height;                       /* 0x988 */
    char move[0x160];                   /* 0x990 cOmSub move work */
    unsigned char rising;               /* 0xAF0 */
    char unkAF1[3];
    int se;                             /* 0xAF4 rise sound handle */
} cOmRiseTrap;

/* Wait for the player to come within 5 units, wait a random 0, 150 or 300
 * frames, then rise 2.4 units with the hit volume on, turned to face the
 * player, and go back to the idle phase once the move ends.
 * One instruction short of retail: retail schedules the abs.s of d.y right
 * after its load, ahead of the 1.5f constant, and keeps the nop after the
 * mtc1; ours moves the abs.s into that slot. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_001AF230")))
void func_001AF230(cOmRiseTrap *self)
{
    cVec d;
    cGameObj *pl;
    cVec *target;
    cVtEnt *vt = &self->base.vtable[16];

    VU0_LQC2_SQC2_MEM(4, &d, ((cVec *(*)(void *))vt->pfn)((char *)self + vt->delta));
    pl = Getplayer();
    target = ((cVec *(*)(void *))cGameObj_vt(pl)->lockOn)((char *)pl + cGameObj_vt(pl)->lockOnDelta);
    VU0_LQC2(4, &d, 0);
    VU0_LQC2(5, target, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &d, 0);

    switch (self->base.step) {
    case 0:
        self->base.stepArg = 0;
        self->base.step = 1;
        /* fallthrough */
    case 1:
        if (__builtin_fabsf(d.y) < 1.5f && d.x * d.x + d.z * d.z < 25.0f) {
            if (self->waitKind == 0) {
                float r = fRand0_1();

                if (r <= 0.33f) {
                    self->waitKind = 1;
                } else if (r <= 0.66f) {
                    self->waitKind = 2;
                } else {
                    self->waitKind = 3;
                }
                switch (self->waitKind) {
                case 0:
                case 1:
                    self->timer = 0;
                    break;
                case 2:
                    self->timer = 150;
                    break;
                case 3:
                    self->timer = 300;
                    break;
                }
            }
            self->base.stepArg = 0;
            self->base.step = 2;
        }
        break;
    case 2:
        if (self->timer <= 0) {
            cVec rise;
            cVtEnt *get;

            cVec_set4(&rise, 0.0f, 2.4f, 0.0f, 1.0f);
            cOmSub_initMove1_pos(self->move, (char *)self, 0, 0x50, &rise, 0.2f, 0.0f);
            cOmSub_setVibration(self->move, 0, 5, 0.0f, 2.0f, 4.0f);
            if (self->damage != 0) {
                cDamageUnit_SetDamageCollActive(self->damage, 1);
            }
            SetEffect(0, 0x4A, self, 0, -1, 0xFFFFFFFF);
            self->base.objFlags &= 0xFFFFFFFD;
            self->rising = 1;
            self->motionDelay = 30;
            self->base.flags2 &= ~0x2000;
            {
                cVec *from = self->base.pos;

                self->base.rot.y += Turn_dest(&from->x, &Getplayer()->pos->x, self->base.rot.y, 3.1415927f);
            }
            self->base.rot.y = Adjust_theta(self->base.rot.y);
            self->se = cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x106, self, 0, 0, 0, 0);
            get = &self->base.vtable[17];
            self->height = ((cVec *(*)(void *))get->pfn)((char *)self + get->delta)->z;
            self->base.stepArg = 0;
            self->base.step = 3;
        } else if (capVu0LengthSq(&d) >= 25.0f) {
            self->base.stepArg = 0;
            self->base.step = 1;
        }
        self->timer--;
        break;
    case 3:
        if (self->motionDelay > 0) {
            if (--self->motionDelay == 0) {
                int res = self->base.texKey;

                func_002A8578((int)self, *(int *)(res + 0xC) + res, 0, 0, 0.0f, 0, 0);
            }
        } else {
            moveMotion(self);
        }
        if (cOmSub_move(self->move) == 0) {
            if (self->se != 0) {
                cSnd_SeStop(&D_005FEE00, self->se);
                self->se = 0;
            }
            self->base.stepArg = 0;
            self->base.step = 4;
        }
        break;
    case 4:
        self->timer = 600;
        self->base.phase = 1;
        self->base.stepArg = 0;
        self->base.step = 0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001AF230);
#endif
