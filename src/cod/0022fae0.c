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

/* An attack: step 0 sets the attack's motion parameters and picks its motion
 * for the enemy type (at random for some, the level 5 alternate for most),
 * the turn time and the effect it starts with, then scales the turn time by
 * the level; step 1 counts the hold time down, turns toward the player while
 * the turn time runs and ends the step with the motion. A motion hit ends the
 * attack's lock flag. */
__attribute__((section(".text.func_0022FAE0")))
void func_0022FAE0(cEm00 *self)
{
    int mode = 3;
    int fxKind = FX_KIND_NONE;
    int fxNo = 1;
    int fxMode = 0;
    void *fxFollow = 0;
    unsigned short sel;
    int recA;
    int recB;
    float angle;
    cVec *from;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->timer2 = 0.0f;
        self->timerA = 0x19;
        switch (self->emNo) {
        case 0x214:
        case 0x215:
            if (self->stepArg != 0 && fRand0_1() < 0.75f) {
                StoreMotionParamsBoth_2609A8(self, 0x14, 2, 0x3E, -1, 0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recA = RES(0x1B30);
                    recB = RES(0x1B34);
                } else {
                    recA = RES(0x1B38);
                    recB = RES(0x1B3C);
                }
                self->timerA = 0x19;
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x14, 0xC, 0x3E, -1, 0);
                recA = RES(0x1B40);
                recB = RES(0x1B44);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1B48);
                }
                self->timerA = 0x14;
            }
            break;
        case 0x20C:
        case 0x24F:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0x13, 0x3E, 0, 0xF0);
                recA = RES(0x1F5C);
                recB = RES(0x1F60);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1F64);
                }
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x1F3C);
                recB = RES(0x1F44);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1F44);
                }
                break;
            case 2:
                StoreMotionParams_2609E0(self, 0xF, 0, 0x3D, 0, 0xF0);
                Set_Fields_1884_1894_2609F8(self, 0xF, 0, 0x3E, 0, 0xF0);
                recA = RES(0x1EE0);
                recB = RES(0x1EE4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1EE8);
                }
                self->timerA = 0x14;
                break;
            }
            /* retail sets the turn time again after the pick */
            self->timerA = 0x19;
            break;
        case 0x20E:
            StoreMotionParams_2609E0(self, 0x14, 2, 0x3E, -1, 0);
            Set_Fields_1884_1894_2609F8(self, 0x14, 2, 0x3E, -1, 0);
            recA = RES(0x3000);
            recB = RES(0x3004);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3008);
            }
            self->timerA = 0x32;
            break;
        case 0x278:
            if (irand() & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0xB, 0x42, 0, 0xF5);
                recA = RES(0xCE4);
                recB = RES(0xCE8);
                self->timerA = 0xA;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0xCEC);
                    self->timerA = 8;
                }
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0x29, 0x3E, 0, 0xF6);
                recA = RES(0x200C);
                recB = RES(0x2010);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2014);
                }
            }
            break;
        case 0x279:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0x1B, 0x3E, 0, 0xF5);
                recA = RES(0x2054);
                recB = RES(0x2058);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x205C);
                }
                self->timerA = 0xF;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    self->timerA = 0xC;
                }
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0xA, 0x43, 0, 0xF5);
                recA = RES(0x203C);
                recB = RES(0x2040);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2044);
                }
                self->timerA = 0x19;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    self->timerA = 0x16;
                }
                break;
            case 2:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0xA, 0x3E, 0, 0xF5);
                recA = RES(0x2048);
                recB = RES(0x204C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2050);
                }
                self->timerA = 0xF;
                break;
            }
            break;
        case 0x218:
        case 0x246:
            if (irand() & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0xB, 0x42, 0, 0xF5);
                recA = RES(0xCE4);
                recB = RES(0xCE8);
                self->timerA = 0xA;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0xCEC);
                    self->timerA = 8;
                }
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0x29, 0x3E, 0, 0xF6);
                recA = RES(0x3B48);
                recB = RES(0x3B4C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3B50);
                }
            }
            break;
        case 0x256:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x2A3C);
                recB = RES(0x2A40);
                if (self->emFlags2 & 0x04000000) {
                    recB = RES(0x2A44);
                }
                self->timerA = 0x14;
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x1E, 0, 0x3E, -1, 0);
                recA = RES(0x2A30);
                recB = RES(0x2A34);
                if (self->emFlags2 & 0x04000000) {
                    recB = RES(0x2A38);
                }
                self->timerA = 0xA;
                break;
            case 2:
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0xA, 0x3E, -1, 0);
                recA = RES(0x2670);
                recB = RES(0x2674);
                self->timerA = 0x1E;
                break;
            }
            break;
        case 0x27E:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x2A3C);
                recB = RES(0x2A44);
                self->timerA = 0x14;
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x1E, 0, 0x3E, -1, 0);
                recA = RES(0x2A30);
                recB = RES(0x2A34);
                if (self->emFlags2 & 0x04000000) {
                    recB = RES(0x2A38);
                }
                self->timerA = 0xA;
                break;
            case 2:
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0xA, 0x3E, -1, 0);
                recA = RES(0x2670);
                recB = RES(0x2674);
                self->timerA = 0x16;
                break;
            }
            break;
        case 0x275:
        case 0x276:
            if (self->emFlags2 & 0x80) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 3, 0x3E, -1, 0);
                recA = RES(0x22EC);
                recB = RES(0x22F0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x22F4);
                }
                self->timerA = 0xF;
            } else {
                recA = RES(0x2324);
                recB = RES(0x2328);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x232C);
                }
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0xA, 0x3E, -1, 0);
                self->timerA = 0x1B;
            }
            break;
        case 0x223:
            if (irand() & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0x2D, 0x3E, -1, 0);
                recA = RES(0x2DAC);
                recB = RES(0x2DB0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2DB4);
                }
                self->timerA = 0x23;
                mode = 0xA;
                self->timer2 = 35.0f;
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0x2C, 0x3E, -1, 0);
                recA = RES(0x2D88);
                recB = RES(0x2D8C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2D90);
                }
                self->timerA = 0x23;
                mode = 0xA;
                self->timer2 = 35.0f;
            }
            break;
        case 0x209:
        case 0x21F:
            fxFollow = self->fx5;
            StoreMotionParamsBoth_2609A8(self, 0x32, 0x18, 0x3E, -1, 0);
            fxMode = 2;
            fxKind = 0x61;
            recA = RES(0x34A0);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                fxNo = 8;
                recB = RES(0x34A8);
            } else {
                fxNo = 7;
                recB = RES(0x34A4);
            }
            self->timerA = 0x1E;
            break;
        case 0x225:
        case 0x24D:
            StoreMotionParamsBoth_2609A8(self, 0x1E, 2, 0x3E, 0, 0xF0);
            recA = RES(0x3D04);
            recB = RES(0x3D08);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3D0C);
            }
            self->timerA = 0x1E;
            break;
        case 0x22B:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x260);
                recB = RES(0x264);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x268);
                }
                self->timerA = 0x14;
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x26C);
                recB = RES(0x270);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x274);
                }
                self->timerA = 0x14;
                break;
            case 2:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x278);
                recB = RES(0x27C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x280);
                }
                self->timerA = 0x14;
                break;
            }
            break;
        case 0x24A:
            if (irand() & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x290);
                recB = RES(0x294);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x298);
                }
                self->timerA = 0xF;
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0, 0x3E, -1, 0);
                recA = RES(0x2C4);
                recB = RES(0x2C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2CC);
                }
                self->timerA = 0x14;
            }
            break;
        case 0x228:
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
            recA = RES(0x284);
            recB = RES(0x288);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x28C);
            }
            self->timerA = 0x1E;
            break;
        case 0x23A:
            switch (irand() & 1) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x718);
                recB = RES(0x71C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x720);
                }
                self->timerA = 0x1E;
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x70C);
                recB = RES(0x710);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x714);
                }
                self->timerA = 0x1E;
                break;
            }
            break;
        case 0x25B:
            switch ((unsigned int)irand() & 3) {
            case 0:
            default:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x718);
                recB = RES(0x71C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x720);
                }
                self->timerA = 0x1E;
                break;
            case 1:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x70C);
                recB = RES(0x710);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x714);
                }
                self->timerA = 0x1E;
                break;
            case 2:
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x290);
                recB = RES(0x294);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x298);
                }
                self->timerA = 0xF;
                break;
            case 3:
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0, 0x3E, -1, 0);
                recA = RES(0x2C4);
                recB = RES(0x2C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2CC);
                }
                self->timerA = 0x14;
                break;
            }
            break;
        default:
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
            recA = RES(0x718);
            recB = RES(0x71C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x720);
            }
            self->timerA = 0x1E;
            break;
        case 0x24B:
            if (irand() & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x718);
                recB = RES(0x71C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x720);
                }
                self->timerA = 0x1E;
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
                recA = RES(0x70C);
                recB = RES(0x710);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x714);
                }
                self->timerA = 0x1E;
            }
            break;
        case 0x241:
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
            recA = RES(0x3A78);
            recB = RES(0x3A7C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3A80);
            }
            self->timerA = 0x32;
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                StoreMotionParamsBoth_2609A8(self, 0x50, 0x38, 0x3E, 0, 0x123);
                recA = RES(0x3908);
                recB = RES(0x390C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3910);
                }
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x50, 0x39, 0x3E, 0, 0xF0);
                recA = RES(0x380C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3814);
                    if (self->unk744 != 0) {
                        ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0xF);
                    }
                } else {
                    recB = RES(0x3810);
                    if (self->unk744 != 0) {
                        ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x10);
                    }
                }
            }
            self->timerA = 0x1E;
            self->timer2 = 30.0f;
            break;
        case 0x22C:
        case 0x25A:
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
            recA = RES(0x120C);
            recB = RES(0x1210);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1214);
            }
            self->timerA = 0x23;
            break;
        }
        func_002A8578((int)self, recA, recB, mode, 0.0f, sel, 0);
        if (fxKind_isSet(fxKind)) {
            InitRenderStruct_2A8608((cGameObj *)self, fxKind, (void *)fxNo, 0, fxMode, fxFollow);
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
        self->timerC = 0;
        self->timer = self->rot.y;
        self->step++;
        /* fallthrough */
    case 1:
        if (0.0f < self->timer2) {
            self->emFlags |= 0x800000;
            self->timer2 -= self->speedRate;
        }
        if (self->timerA != 0) {
            self->timerA--;
            from = self->pos;
            angle = Turn_dest(&from->x, &Getplayer()->pos->x, self->timer, self->speedRate * 0.19634955f);
            self->timer += angle;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += angle;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    if (self->unk1864 == 0) {
        func_00260B30(self);
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
