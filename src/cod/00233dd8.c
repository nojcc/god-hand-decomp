/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"

#define RES(off) EM_RES_REC(self->resource, off)

/* A swing with the held weapon: step 0 picks one of two swings at random (enemy
 * 0x21C swaps the first for a third, and takes a fourth at random when the
 * player is farther than 9), starts its motion, puts the weapon in the matching
 * swing state (stepArg 1 on level 5) and sets the turn time, shortened below
 * level 5; step 1 turns toward the player while it runs and ends the phase with
 * the motion. From level 3, func_00262AA8 may switch to another action when the
 * motion allows it (moveFlags 0x10) and nothing has hit the enemy. */
__attribute__((section(".text.func_00233DD8")))
void func_00233DD8(cEm00 *self)
{
    unsigned short sel;
    unsigned int pick;
    int recA;
    int recB;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->timerB = 0;
        pick = irand() & 1;
        if (self->emNo == 0x21C) {
            if (pick == 0) {
                pick = 2;
            }
            if (self->playerDist > 9.0f && (irand() & 1)) {
                pick = 3;
            }
        }
        switch (pick) {
        case 0:
        default:
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x14, 0x3E, 0, 0xF5);
            recA = RES(0x1170);
            recB = RES(0x1174);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1178);
            }
            func_002A8578((int)self, recA, recB, 10, 0.0f, sel, 0);
            if (self->fx0 != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    Obj1D00_SetState_6_2_a1(&self->fx0->base, 1);
                } else {
                    Obj1D00_SetState_6_2_a1(&self->fx0->base, 0);
                }
            }
            self->timerA = 0x28;
            break;
        case 1:
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x15, 0x45, 0, 0xF5);
            recA = RES(0x1188);
            recB = RES(0x118C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1190);
            }
            func_002A8578((int)self, recA, recB, 10, 0.0f, sel, 0);
            if (self->fx0 != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    Obj1D00_SetState6_Variant6_a1(&self->fx0->base, 1);
                } else {
                    Obj1D00_SetState6_Variant6_a1(&self->fx0->base, 0);
                }
            }
            self->timerA = 0x19;
            break;
        case 2:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0x14, 0x3E, 0, 0xF5);
            recA = RES(0x11A8);
            recB = RES(0x11AC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x11B0);
            }
            func_002A8578((int)self, recA, recB, 10, 0.0f, sel, 0);
            if (self->fx0 != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    Obj1D00_SetState_6_E_a1(&self->fx0->base, 1);
                } else {
                    Obj1D00_SetState_6_E_a1(&self->fx0->base, 0);
                }
            }
            self->timerA = 0x28;
            break;
        case 3:
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x15, 0x45, 0, 0xF5);
            recA = RES(0x1194);
            recB = RES(0x1198);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x119C);
            }
            func_002A8578((int)self, recA, recB, 10, 0.0f, sel, 0);
            if (self->fx0 != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    Obj1D00_SetState_6_C_a1(&self->fx0->base, 1);
                } else {
                    Obj1D00_SetState_6_C_a1(&self->fx0->base, 0);
                }
            }
            self->timerA = 0x19;
            break;
        }
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1:
        default:
            self->timerA = self->timerA * 0.75f;
            break;
        case 2:
            self->timerA = self->timerA * 0.8f;
            break;
        case 3:
        case 4:
            self->timerA = self->timerA * 0.9f;
            break;
        case 5:
            break;
        }
        self->step++;
        self->timerC = 0;
        /* fallthrough */
    case 1:
        if (self->timerA != 0) {
            self->timerA--;
            cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * 0.19634955f);
        }
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        /* fallthrough */
    default:
        break;
    }
    func_00260B30(self);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(self) == 0 && (self->moveFlags & 0x10)
        && self->unk1864 == 0 && func_00262AA8(self) != 0) {
        return;
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
