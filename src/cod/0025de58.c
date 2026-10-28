/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cHeatSys.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

extern void cCollisionSolidManage_SetActive(int mgr, int obj, int on);

#define EM_HELD_SPARK_CHILD     4
#define EM_HELD_SPARK_EFFECT    0x4F
#define EM_HELD_FOLLOW_FRAMES   15
#define EM_HELD_DAMAGE_PER_TICK 20.0f

/* Held by the player: the enemy runs at the player's speed and moves with
 * the player's velocity. Step 3 counts the motion loops it struggles for and
 * follows the player's step; at the end of the throw (steps 4 and 5) it
 * sparks from its fifth child, takes 20 damage per loop counted, fills the
 * player's heat gauge by the same count and falls down. */
__attribute__((section(".text.func_0025DE58")))
void func_0025DE58(cEm00 *self)
{
    cGameObj *player;
    cOmBase *child;
    int frame[3];
    cVec spark;

    player = Getplayer();
    self->speedRate = player->speedRate;
    SetMotionStep(self, self->speedRate);
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    switch (self->step) {
    case 0:
        ReleaseField6ECByTag564_26B1E8(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x39A0),
                      EM_RES_REC(self->resource, 0x39A4), 0, 0.0f, 0, 0);
        if (self->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x19);
        }
        self->unk16EC = 0;
        self->unk56A = 0;
        self->step++;
        /* fallthrough */
    case 1:
        VU0_VADD_XYZ_IP(self->pos, 0, &player->vel);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        ReleaseField6ECByTag564_26B1E8(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x39A8),
                      EM_RES_REC(self->resource, 0x39AC), 0, 0.0f, 0, 0);
        if (self->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x1A);
        }
        self->timerA = 1;
        self->timer = 0.0f;
        self->step++;
        /* fallthrough */
    case 3:
        VU0_VADD_XYZ_IP(self->pos, 0, &player->vel);
        if (moveMotion(self) != 0) {
            self->timer += 1.0f;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->step = player->step;
        break;
    case 4:
        ReleaseField6ECByTag564_26B1E8(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x39B0),
                      EM_RES_REC(self->resource, 0x39B4), 0, 0.0f, 0, 0);
        if (self->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x1B);
        }
        self->timerA = 1;
        self->followTimer = EM_HELD_FOLLOW_FRAMES;
        self->step++;
        /* fallthrough */
    case 5:
        if (self->followTimer != 0) {
            self->followTimer--;
            VU0_VADD_XYZ_IP(self->pos, 0, &player->vel);
        }
        if (moveMotion(self) != 0) {
            child = cOmBase_childAt((cOmBase *)self, frame, EM_HELD_SPARK_CHILD);
            if (child != 0) {
                cVec_zero(&spark);
                spark.x = fRand1_1() * 0.1f;
                spark.y = fRand1_1() * 0.1f + 0.1f;
                spark.z = fRand0_1() * 0.1f + 0.2f;
                cVec_applyMatrix(&spark, child->mtx);
                SetEffectPos(0, EM_HELD_SPARK_EFFECT, 0, &spark, -1, 1.0f);
            }
            CEM00_VCALL(self, hit, (int)(self->timer * EM_HELD_DAMAGE_PER_TICK), player, 0, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, self->timer);
            self->mode = 1;
            self->phase = 4;
            self->stepArg = 2;
            self->step = 0;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}
