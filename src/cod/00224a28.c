/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/angle.h"
#include "godhand/motion.h"
#include "godhand/player.h"

extern void cCollisionSolidManage_SetActive(int mgr, int obj, int on);

#define EMFLAG_GUARDED      0x800000
#define EMFLAG_HIT          0x1000
#define EMFLAG2_ATTACKING   0x400u     /* unsigned: the clear needs the lui/ori mask */
#define PI_F                3.1415927f
#define FACING_MAX          0.5235988f  /* 30 degrees */
#define FX_KIND_ENEMY       0x58
#define FX_GRAB_MISS        0x1C
#define PL_CAUGHT_GRAB      10
#define EM_PHASE_RECOVER    0x6C

/* Grab rush phase machine: wind up while turning to the player, charge
 * (turning faster on harder levels) until the player is caught, gets away or
 * the charge runs out, then either hold the player or stumble out. */
__attribute__((section(".text.func_00224A28")))
void func_00224A28(cEm00 *self)
{
    cEffectParam prm;
    unsigned short sel;
    int motA;
    int motB;
    cVec *pos;
    float turn;
    float angle;
    cGameObj *player;

    cEffectParam_init(&prm);
    self->unk186A = 2;
    prm.size = self->unk114;
    self->emFlags2 |= EMFLAG2_ATTACKING;
    prm.unk70 = 0;
    prm.unk72 = 0;
    prm.unk74 = 0;
    prm.unk78 = 0;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(self->resource, 0x1E14);
        motB = EM_RES_REC(self->resource, 0x1E18);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            motB = EM_RES_REC(self->resource, 0x1E1C);
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, sel, 0);
        self->timerC = 0;
        self->timer = 15.0f;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1:
        default:
            self->timer = 15.0f;
            break;
        case 2:
            self->timer = 20.0f;
            break;
        case 3:
            self->timer = 25.0f;
            break;
        case 4:
        case 5:
            self->timer = 30.0f;
            break;
        }
        self->step++;
        /* fallthrough */
    case 1:
        self->unk16EC = 2;
        self->unk16E8 = 0;
        self->emFlags |= EMFLAG_GUARDED;
        if (self->timer > 0.0f) {
            self->timer -= self->speedRate;
            cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * 0.09817477f);
        }
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(self->resource, 0x1E20);
        motB = EM_RES_REC(self->resource, 0x1E24);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            motB = EM_RES_REC(self->resource, 0x1E28);
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, sel, 0);
        self->timerA = 8;
        self->step++;
        /* fallthrough */
    case 3:
        self->unk16EC = 2;
        self->unk16E8 = 0;
        pos = self->pos;
        self->emFlags |= EMFLAG_GUARDED;
        turn = Turn_dest((float *)pos, (float *)Getplayer()->pos, self->rot.y, PI_F);
        if (turn < 0.0f) {
            angle = -turn;
        } else {
            angle = turn;
        }
        if (angle < FACING_MAX && self->playerDist > 16.0f) {
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
            case 1:
            default:
                turn = 0.012271847f;
                break;
            case 2:
                turn = 0.024543693f;
                break;
            case 3:
                turn = 0.049087387f;
                break;
            case 4:
            case 5:
                turn = 0.09817477f;
                break;
            }
            cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, turn * self->speedRate);
        }
        if (self->playerDist < 16.0f && self->timerA >= 3) {
            self->timerA = 2;
        }
        if (cEmManage_CkPlSorry(&D_005864F0) != 0 || cEmManage_CkPlCatched(&D_005864F0) != 0) {
            self->step = 4;
        }
        if (moveMotion(self) != 0) {
            if (--self->timerA <= 0) {
                self->step = 4;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        func_00262750(self, 1);
        if ((self->moveFlags & 1) && func_00270DB0(self) != 0) {
            player = Getplayer();
            self->step = 6;
            func_00129718(player, self, PL_CAUGHT_GRAB);
            return;
        }
        if (func_00275888((cGameObj *)self, 2.0f) != 0) {
            self->step = 4;
        }
        break;
    case 4:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x96C), EM_RES_REC(self->resource, 0x970), 3, 0.0f, sel, 0);
        SetEffect(FX_KIND_ENEMY, FX_GRAB_MISS, self, &prm, -1, 0xFFFFFFFF);
        self->step++;
        /* fallthrough */
    case 5:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 6:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x1E2C), EM_RES_REC(self->resource, 0x1E30), 3, 0.0f, sel, 0);
        SetEffect(FX_KIND_ENEMY, FX_GRAB_MISS, self, &prm, -1, 0xFFFFFFFF);
        self->step++;
        /* fallthrough */
    case 7:
        self->unk16E8 = 0;
        self->unk16EC = 2;
        self->hitFlash = 2.0f;
        cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = EM_PHASE_RECOVER;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    if (self->moveFlags & 3) {
        self->unk16F8 = 10;
        self->timerC = 1;
        self->emFlags |= EMFLAG_HIT;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= ~EMFLAG2_ATTACKING;
    }
}
