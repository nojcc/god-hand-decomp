/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/cCamera.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/angle.h"
#include "godhand/rand.h"

#define RES(off) EM_RES_REC(self->resource, off)

/* An attack: step 0 picks the attack motion and its phase for the enemy type
 * (at random for some), step 1 turns toward the player while the turn timer
 * runs and ends the step with the motion; every frame the phase starts the
 * attack's hit volumes when the motion flags say so. */
__attribute__((section(".text.func_002269F0")))
void func_002269F0(cEm00 *self)
{
    cGameObj *player = Getplayer();
    unsigned short sel;
    int recA;
    int recB;
    unsigned int pick;
    float angle;
    cVec *from;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->timerB = 0;
        switch (self->emNo) {
        case 0x250:
        case 0x251:
            if (self->stepArg != 0) {
                recA = RES(0x19A4);
                recB = RES(0x19A8);
            } else {
                recA = RES(0x19C8);
                recB = RES(0x19CC);
            }
            self->timerA = 0x32;
            self->timerB = 0x3C;
            break;
        case 0x220:
        case 0x221:
        case 0x222:
        default:
            if (self->vital <= self->vitalMax / 2) {
                recA = RES(0x1CDC);
                recB = RES(0x1CE0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1CE4);
                }
            } else {
                recA = RES(0x1CD0);
                recB = RES(0x1CD4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1CD8);
                }
            }
            self->timerA = 0x19;
            self->stepArg = 2;
            break;
        case 0x252:
            if (Obj0000_IsSet_Field_15F4_Bit_1000_12C530((char *)player) == 0) {
                pick = (unsigned int)irand() % 3;
            } else {
                pick = irand() & 1;
            }
            switch (pick) {
            case 0:
            default:
                recA = RES(0x250C);
                recB = RES(0x2510);
                self->stepArg = 3;
                self->timerA = 0x34;
                break;
            case 1:
                recA = RES(0x2514);
                recB = RES(0x2518);
                self->stepArg = 4;
                self->timerA = 0x34;
                break;
            case 2:
                recA = RES(0x24FC);
                recB = RES(0x2500);
                self->stepArg = 5;
                self->timerA = 0x20;
                break;
            }
            break;
        case 0x256:
            if (self->unk186B != 4 && (irand() & 1)) {
                /* always true here; retail repeats the test the 0x27E case makes */
                if (self->emNo == 0x256) {
                    recA = RES(0x278C);
                    recB = RES(0x2790);
                    self->timerA = 0x50;
                    self->timerB = 0x50;
                    self->stepArg = 9;
                } else {
                    recA = RES(0x29E0);
                    recB = RES(0x29E4);
                    self->timerA = 0x50;
                    self->timerB = 0x50;
                    self->stepArg = 0xB;
                }
            } else {
                if ((irand() & 1) || cCoreSave_getGameLevel(&D_00569B70) < 2) {
                    recA = RES(0x28A8);
                    recB = RES(0x28AC);
                    self->stepArg = 6;
                } else {
                    recA = RES(0x2910);
                    recB = RES(0x2914);
                    self->stepArg = 7;
                }
                self->timerA = 0x19;
                self->timerB = 0x1E;
            }
            break;
        case 0x27E:
            if ((unsigned int)irand() % 3 == 0) {
                if (self->emNo == 0x256) {
                    recA = RES(0x278C);
                    recB = RES(0x2790);
                    self->timerA = 0x50;
                    self->timerB = 0x50;
                    self->stepArg = 9;
                } else {
                    recA = RES(0x29E0);
                    recB = RES(0x29E4);
                    self->timerA = 0x50;
                    self->timerB = 0x50;
                    self->stepArg = 0xB;
                }
            } else {
                if ((unsigned int)irand() % 3 != 0) {
                    recA = RES(0x28A8);
                    recB = RES(0x28AC);
                    self->stepArg = 6;
                } else {
                    recA = RES(0x2910);
                    recB = RES(0x2914);
                    self->stepArg = 7;
                }
                self->timerA = 0x19;
                self->timerB = 0x1E;
            }
            break;
        case 0x260:
            recA = RES(0x30C4);
            recB = RES(0x30C8);
            self->timerA = 0x32;
            self->timerB = 0x3C;
            self->stepArg = 8;
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                recA = RES(0x38E8);
                recB = RES(0x38EC);
                self->timerA = 0x32;
                self->timerB = 0x3C;
                self->stepArg = 0xA;
            } else {
                recA = RES(0x37E8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x37F0);
                    if (self->unk744 != 0) {
                        ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0xE);
                    }
                } else {
                    recB = RES(0x37EC);
                    if (self->unk744 != 0) {
                        ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0xD);
                    }
                }
                self->timerA = 0x32;
                self->timerB = 0x3C;
                self->stepArg = 0xA;
            }
            break;
        }
        func_002A8578((int)self, recA, recB, 10, 0.0f, sel, 0);
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
        self->unk5F8 = 1;
        self->timer = self->rot.y;
        self->step++;
        self->timerC = 0;
        self->timer2 = 0.0f;
        self->unk568 = 0;
        /* fallthrough */
    case 1:
        if (self->emNo == 0x256 || self->emNo == 0x27E) {
            self->emFlags2 |= 0x400000;
        }
        if (self->timerA != 0) {
            self->timerA--;
            from = self->pos;
            angle = Turn_dest(&from->x, &Getplayer()->pos->x, self->timer, self->speedRate * 0.196349546f);
            self->timer += angle;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += angle;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if ((self->moveFlags & 1) && self->timerB >= 0xB) {
            self->timerB = 10;
        }
        if (self->timerB != 0) {
            self->timerB--;
            self->emFlags |= 0x800000;
        }
        if (moveMotion(self) != 0) {
            /* retail asks for the game level here and drops it */
            cCoreSave_getGameLevel(&D_00569B70);
            if (self->emNo == 0x265) {
                if (func_00262AA8(self) == 0) {
                    func_002705D8(self);
                }
                return;
            }
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    }
    switch (self->stepArg) {
    case 0:
    default:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0, 0);
        }
        break;
    case 1:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 1, 0);
        }
        break;
    case 2:
        if ((self->moveFlags & 3) && self->unk5F8 != 0) {
            if (self->moveFlags & 1) {
                func_0026BEF0(self, 2, 0);
            }
            if (self->moveFlags & 2) {
                func_0026BEF0(self, 3, 0);
            }
            self->unk5F8 = 0;
        } else {
            self->unk5F8 = 1;
        }
        break;
    case 3:
        if (self->moveFlags & 1) {
            self->timer2 -= self->speedRate;
            if (self->timer2 <= 0.0f) {
                self->unk5F8 = 0;
                self->timer2 = 2.0f;
                func_0026BEF0(self, 7, self->unk568);
                if (++self->unk568 >= 5) {
                    self->unk568 = 0;
                }
            }
        }
        break;
    case 4:
        if (self->moveFlags & 1) {
            self->timer2 -= self->speedRate;
            if (self->timer2 <= 0.0f) {
                self->unk5F8 = 0;
                self->timer2 = 3.0f;
                func_0026BEF0(self, 0x10, 0);
            }
        }
        break;
    case 5:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0x11, 0);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                func_0026BEF0(self, 0x11, 1);
                func_0026BEF0(self, 0x11, 2);
            }
        }
        break;
    case 6:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0xE, 0);
            if (self->emNo == 0x27E) {
                func_0026BEF0(self, 0xE, 1);
                func_0026BEF0(self, 0xE, 2);
            }
        }
        break;
    case 7:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0xF, 0);
        }
        break;
    case 8:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0x14, 0);
        }
        break;
    case 9:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0x17, 0);
        }
        break;
    case 10:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0x18, 0);
        }
        break;
    case 11:
        if ((self->moveFlags & 1) && self->unk5F8 != 0) {
            self->unk5F8 = 0;
            func_0026BEF0(self, 0x1B, 0);
            func_0026BEF0(self, 0x1B, 1);
        }
        break;
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
