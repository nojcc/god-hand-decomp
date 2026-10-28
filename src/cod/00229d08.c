/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"
#include "godhand/motion.h"

#define EMFLAG_RUSH             0x800000
#define EM_TURN_RATE            0.09817477f /* pi / 32 per frame at full speed */
#define EM_FAR                  99999.9f
#define GAME_LEVEL_HARDEST      5

/* Starts the motion pair at off and tells the enemy's sub-object (unk744)
 * which part of the move it is in. A macro: as an inline function the
 * registers move. */
#define EM_START_PART(self, off, part)                                  \
    {                                                                   \
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);                  \
        motA = EM_RES_REC((self)->resource, (off));                     \
        motB = EM_RES_REC((self)->resource, (off) + 4);                 \
        if ((self)->unk744 != 0) {                                      \
            ForwardAnimParamPairByIndex_27EA50((void *)(self)->unk744, (part)); \
        }                                                               \
        func_002A8578((int)(self), motA, motB, 3, 0.0f, sel, 0);        \
    }

/* Rush attack phase machine: wind up turning to the player, rush up to four
 * motions long while still far away, then one of three finishers chosen by
 * how the rush ended, each going back to idle when its motion ends. */
__attribute__((section(".text.func_00229D08")))
void func_00229D08(cEm00 *self)
{
    int motA;
    int motB;
    unsigned short sel;

    self->unk186A = 2;
    switch (self->step) {
    case 0:
        EM_START_PART(self, 0x3758, 0x11);
        self->timerA = 1;
        self->unk568 = 0;
        self->step++;
        /* fallthrough */
    case 1:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(self->resource, 0x37AC);
        if (cCoreSave_getGameLevel(&D_00569B70) == GAME_LEVEL_HARDEST) {
            motB = EM_RES_REC(self->resource, 0x37B0);
            if (self->unk744 != 0) {
                ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x12);
            }
        } else {
            motB = EM_RES_REC(self->resource, 0x37B4);
            if (self->unk744 != 0) {
                ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x13);
            }
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, sel, 0);
        StoreMotionParamsBoth_2609A8(self, 0x28, 0x38, 0x3E, 0, 0xF0);
        self->posB.x = EM_FAR;
        self->posB.y = EM_FAR;
        self->posB.z = EM_FAR;
        self->unk568 = 1;
        self->unk56A = 4;
        self->step++;
        self->timerB = 0;
        /* fallthrough */
    case 3:
        self->emFlags |= EMFLAG_RUSH;
        if (self->playerDist > 25.0f && self->unk568 != 0) {
            cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        } else {
            self->unk568 = 0;
        }
        if (moveMotion(self) != 0) {
            if (--self->unk56A <= 0) {
                self->step = 10;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        func_00260B30(self);
        if (func_00275888((cGameObj *)self, 5.0f) != 0) {
            self->step = 4;
        }
        break;
    case 4:
        EM_START_PART(self, 0x37B8, 0x14);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1:
        default:
            self->idleTimer = 180.0f;
            break;
        case 2:
            self->idleTimer = 150.0f;
            break;
        case 3:
            self->idleTimer = 120.0f;
            break;
        case 4:
            self->idleTimer = 120.0f;
            break;
        case 5:
            self->idleTimer = 90.0f;
            break;
        }
        self->step++;
        /* fallthrough */
    case 5:
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 6:
        EM_START_PART(self, 0x37C0, 0x15);
        self->step++;
        /* fallthrough */
    case 7:
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 8:
        EM_START_PART(self, 0x37C8, 0x16);
        self->step++;
        /* fallthrough */
    case 9:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 10:
        EM_START_PART(self, 0x3760, 0x17);
        self->step++;
        /* fallthrough */
    case 11:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}
