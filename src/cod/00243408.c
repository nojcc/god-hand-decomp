/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/capVu0.h"
#include "godhand/player.h"
#include "godhand/motion.h"

extern void cCollisionSolidManage_SetActive(int mgr, int obj, int on);

#define EMFLAG_NO_SOLID         0x10000
#define EMMOVE_HIT_FRAME        0x1
#define EMMOVE_HIT_FRAME2       0x2
#define EM_TURN_RATE            0.09817477f /* pi / 32 per frame at full speed */
#define EM_BOB_STEP             0.17453292f /* 10 degrees per frame */
#define EM_BOB_HEIGHT           0.02f
#define EM_PHASE_IDLE           0x7F

/* Enemy 0x211's weapon-throw phase machine. It floats with the solid off,
 * turning to the player: a throw that drops one weapon per hit frame, then
 * a 90-frame wait, rounds of throws counted down by unk568 with 45-frame
 * waits, a double throw, and a 45-frame wait before going idle. The body
 * bobs up and down every frame. */
__attribute__((section(".text.func_00243408")))
void func_00243408(cEm00 *self)
{
    unsigned short sel;
    float bob;

    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    self->emFlags |= EMFLAG_NO_SOLID;
    switch (self->step) {
    case 0:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x2474), EM_RES_REC(self->resource, 0x2478), 3, 0.0f, sel, 0);
        self->timerA = 1;
        self->unk60C = 0.0f;
        self->step++;
        /* fallthrough */
    case 1:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if ((self->moveFlags & EMMOVE_HIT_FRAME) && self->timerA != 0) {
            self->timerA = 0;
            func_0026B600(self);
        }
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x247C), EM_RES_REC(self->resource, 0x2480), 3, 0.0f, sel, 0);
        self->unk568 = 2;
        self->timer = 90.0f;
        self->step++;
        /* fallthrough */
    case 3:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->step++;
        }
        break;
    case 4:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x2484), EM_RES_REC(self->resource, 0x2488), 3, 0.0f, sel, 0);
        self->timerA = 1;
        self->step++;
        /* fallthrough */
    case 5:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        if (moveMotion(self) != 0) {
            if (--self->unk568 <= 0) {
                self->step = 6;
            } else {
                self->step = 4;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->moveFlags & (EMMOVE_HIT_FRAME | EMMOVE_HIT_FRAME2)) {
            if (self->timerA != 0) {
                self->timerA = 0;
                EmWeaponHolder_dropWeapons(self, 1, 0);
            }
        } else {
            self->timerA = 1;
        }
        break;
    case 6:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x247C), EM_RES_REC(self->resource, 0x2480), 3, 0.0f, sel, 0);
        self->timer = 45.0f;
        self->step++;
        /* fallthrough */
    case 7:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->step++;
        }
        break;
    case 8:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x248C), EM_RES_REC(self->resource, 0x2490), 3, 0.0f, sel, 0);
        self->timerA = 1;
        self->step++;
        /* fallthrough */
    case 9:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->moveFlags & (EMMOVE_HIT_FRAME | EMMOVE_HIT_FRAME2)) {
            if (self->timerA != 0) {
                self->timerA = 0;
                if (self->moveFlags & EMMOVE_HIT_FRAME) {
                    EmWeaponHolder_dropWeapons(self, 1, 0);
                }
                if (self->moveFlags & EMMOVE_HIT_FRAME2) {
                    EmWeaponHolder_dropWeapons(self, 1, 0);
                }
            }
        } else {
            self->timerA = 1;
        }
        break;
    case 10:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x2464), EM_RES_REC(self->resource, 0x2468), 3, 0.0f, sel, 0);
        self->timer = 45.0f;
        self->step++;
        /* fallthrough */
    case 11:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->mode = 0;
            self->phase = EM_PHASE_IDLE;
            self->step = 0;
            self->stepArg = 0;
        }
        break;
    }
    bob = capVu0Sin(self->unk60C) * EM_BOB_HEIGHT;
    self->unk60C += self->speedRate * EM_BOB_STEP;
    self->unk60C = Adjust_theta(self->unk60C);
    self->pos->y += bob * self->speedRate;
}
