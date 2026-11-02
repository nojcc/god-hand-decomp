/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cVec.h"
#include "godhand/gameWork.h"
#include "godhand/motion.h"
#include "godhand/mtx.h"
#include "godhand/pl00.h"
#include "godhand/sceVu0.h"

#define ROOM_CATCH_AT_ORIGIN 0x4E   /* the catch happens at the origin */
#define ROOM_CATCH_FIXED     0x602  /* the catch happens at a fixed point */

extern void CallWithAndClearField698_12AC28(char *a0);
extern void cCollisionSolidManage_SetActive(int mgr, int obj, int on);
extern void func_0012B928(char *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_002DB7A8(void);
extern void func_00124EC0(void *obj);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);

/* A catch of the player: step 0 puts the player at the catch point (the
 * enemy's position, or a fixed point in two rooms), the enemy beside it
 * turned to face it, and starts the player's caught motion; steps 1, 3 and 5
 * carry the enemy along with the player's velocity. Step 3 is the struggle:
 * the face buttons pressed in each 10-frame window set the pace (0.7 to 2.0)
 * and it ends with the motion once the 90-frame minimum has run out. */
__attribute__((section(".text.func_001191A0")))
void func_001191A0(cEm00 *self)
{
    float mtx[16];
    cVec pos;
    cVec ofs;
    CVEC_TEMPS;
    pl00 *pl;
    int goal;

    pl = self->catchPl;
    CVEC_ZERO(pos);
    CVEC_ZERO(ofs);
    self->objFlags |= 0x10000;
    self->hitFlash = 5.0f;
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->unk15F4 |= 0x80000;
    switch (self->step) {
    case 0:
        CallWithAndClearField698_12AC28((char *)self);
        func_0012B928((char *)self);
        switch (D_007474A0.room) {
        default:
            CVEC_ASSIGN(pos, self->pos);
            break;
        case ROOM_CATCH_AT_ORIGIN:
            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.z = 0.0f;
            break;
        case ROOM_CATCH_FIXED:
            pos.y = -13.575f;
            pos.z = -20.0f;
            pos.x = 0.0f;
            break;
        }
        CVEC_PUT(pl->base.pos, pos);
        MtxInitRotY(mtx, self->rot.y);
        ofs.x = 1.8033f;
        ofs.z = -4.3902f;
        ofs.y = 0.0f;
        cVec_applyMatrix(&ofs, mtx);
        CVEC_SET_ADD(*self->pos, pl->base.pos, &ofs);
        pl->base.rot.y = self->rot.y + 3.1415927f;
        pl->base.rot.y = Adjust_theta(pl->base.rot.y);
        cEm00_GetPlMotion(pl, 0x49, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(&D_00569B70, 100);
        self->unk56A = 1;
        self->step++;
    case 1:
        func_002DB7A8();
        if (pl != 0) {
            CVEC_ADD_TO(*self->pos, &pl->base.vel);
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    case 2:
        cEm00_GetPlMotion(pl, 0x4A, 0.0f, 0.0f);
        self->unk568 = 90;
        self->gotoFlags = 0;
        self->step++;
        self->stepVar.count = 0;
        self->unk15B8 = 0;
    case 3:
        func_002DB7A8();
        if (pl != 0) {
            CVEC_ADD_TO(*self->pos, &pl->base.vel);
        }
        if (self->unk568 != 0) {
            self->unk568--;
        }
        if (self->unk15B8 != 0) {
            self->unk15B8--;
        }
        self->gotoFlags++;
        if (D_007474A0.padBtn & 0xF0) {
            switch (self->stepVar.count) {
            case 0:
            default:
                goal = 999;
                break;
            case 1:
                goal = 6;
                break;
            case 2:
                goal = 5;
                break;
            case 3:
                goal = 4;
                break;
            case 4:
                goal = 3;
                break;
            case 5:
                goal = 2;
                break;
            }
            if (self->gotoFlags < goal) {
                self->stepVar.count++;
            }
            if (goal < self->gotoFlags) {
                self->stepVar.count--;
            }
            if (self->stepVar.count < 0) {
                self->stepVar.count = 0;
            }
            if (self->stepVar.count >= 5) {
                self->stepVar.count = 4;
            }
            self->gotoFlags = 0;
            self->unk15B8 = 10;
        } else if (self->unk15B8 <= 0) {
            self->unk15B8 = 5;
            self->stepVar.count--;
            if (self->stepVar.count < 0) {
                self->stepVar.count = 0;
            }
        }
        switch (self->stepVar.count) {
        case 0:
        default:
            self->speedRate = 0.7f;
            break;
        case 1:
            self->speedRate = 1.0f;
            break;
        case 2:
            self->speedRate = 1.3f;
            break;
        case 3:
            self->speedRate = 1.6f;
            break;
        case 4:
            self->speedRate = 2.0f;
            break;
        }
        SetMotionStep(self, self->speedRate);
        func_00124EC0(self);
        if (moveMotion(self) != 0 && self->unk568 <= 0) {
            self->step = 4;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    case 4:
        cEm00_GetPlMotion(pl, 0x4B, 0.0f, 0.0f);
        self->followTimer = 15;
        self->step++;
    case 5:
        /* retail checks the player here but adds the enemy's own velocity */
        if (self->followTimer != 0 && pl != 0) {
            self->followTimer--;
            CVEC_ADD_TO(*self->pos, &self->vel);
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 0, 0);
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    }
}
