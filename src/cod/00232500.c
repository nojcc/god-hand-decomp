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

/* An attack: step 0 sets the attack's motion parameters, picks its motion
 * for the enemy type (at random for some, the level 5 alternate for most)
 * and the effect it starts with, then scales the turn time by the level;
 * step 1 counts the hold time down, turns toward the player while the turn
 * time runs and ends the step with the motion. Every frame enemy 0x222
 * takes its motion's hit flag, enemy 0x208 checks its weapon, a counter can
 * cut the attack short from level 3 up, and enemy 0x264 starts its hit
 * volume once. */
__attribute__((section(".text.func_00232500")))
void func_00232500(cEm00 *self)
{
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
        self->timerB = 0;
        self->unk5F8 = 1;
        self->timerC = 0;
        self->timerA = 0xF;
        self->timer3 = 1.0f;
        StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
        self->timer2 = 0.0f;
        self->unk60C = 0.0f;
        switch (self->emNo) {
        default:
            StoreMotionParamsBoth_2609A8(self, 0x14, 1, 0x37, -1, 0);
            recA = RES(0x144);
            recB = RES(0x148);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x14C);
            }
            break;
        case 0x202:
        case 0x203:
        case 0x213:
        case 0x216:
        case 0x217:
        case 0x229:
        case 0x22A:
        case 0x24B:
            StoreMotionParamsBoth_2609A8(self, 0x14, 2, 0x37, -1, 0);
            recA = RES(0x6F4);
            recB = RES(0x6F8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x6FC);
            }
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x25A:
            if ((irand() & 1) && self->fx0 == 0) {
                StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
                recA = RES(0x1134);
                recB = RES(0x1138);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x113C);
                }
                self->timerA = 0xF;
            } else {
                StoreMotionParams_2609E0(self, 0xF, 0, 0x3D, -1, 0);
                Set_Fields_1884_1894_2609F8(self, 0x14, 0, 0x3E, -1, 0);
                recA = RES(0x1158);
                recB = RES(0x115C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1160);
                }
                self->timerA = 0x32;
            }
            break;
        case 0x205:
        case 0x207:
        case 0x224:
        case 0x241:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
            recA = RES(0x15DC);
            recB = RES(0x15E0);
            self->timerA = 0xF;
            break;
        case 0x206:
            StoreMotionParams_2609E0(self, 0xF, 5, 0x37, 0, 0xF0);
            Set_Fields_1884_1894_2609F8(self, 0xF, 4, 0x37, 0, 0xF0);
            recA = RES(0x1884);
            recB = RES(0x1888);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x188C);
            }
            self->timerA = 0x28;
            break;
        case 0x209:
        case 0x21F:
            fxFollow = self->fx5;
            StoreMotionParamsBoth_2609A8(self, 0x32, 0x19, 0x3E, -1, 0);
            fxKind = 0x61;
            fxNo = 0xC;
            fxMode = 2;
            recA = RES(0x34B8);
            recB = RES(0x34BC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x34C0);
            } else {
                fxNo = 0xB;
            }
            self->timerA = 0xF;
            break;
        case 0x208:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
            recA = RES(0x15DC);
            recB = RES(0x15E0);
            self->timerA = 0xF;
            if (self->fx4 != 0 && Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08((cOmBase *)self->fx4) == 0) {
                StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
                recA = RES(0x1E70);
                recB = RES(0x1E74);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1E78);
                }
                SetOrientByType_26AF20(self, (int)self->fx4, 1);
            }
            /* retail sets the turn time again after the weapon check */
            self->timerA = 0xF;
            break;
        case 0x20F:
            StoreMotionParamsBoth_2609A8(self, 2, 2, 0x37, 1, 0x20);
            recA = RES(0xDB0);
            recB = RES(0xDB4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0xDB8);
            }
            break;
        case 0x210:
        case 0x211:
        case 0x226:
            StoreMotionParamsBoth_2609A8(self, 0xF, 2, 0x37, -1, 0);
            recA = RES(0xE24);
            recB = RES(0xE28);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0xE2C);
            }
            break;
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            StoreMotionParamsBoth_2609A8(self, 5, 2, 0x37, -1, 0);
            recA = RES(0xDB0);
            recB = RES(0xDB4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0xDB8);
            }
            break;
        case 0x20A:
        case 0x20C:
        case 0x20D:
        case 0x20E:
        case 0x218:
        case 0x245:
        case 0x246:
        case 0x247:
        case 0x24F:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0x29, 0x42, 0, 0xF6);
            recA = RES(0x8F0);
            recB = RES(0x8F4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x8F8);
            }
            break;
        case 0x20B:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0x29, 0x42, 0, 0x111);
            recA = RES(0x8F0);
            recB = RES(0x8F4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x8F8);
            }
            break;
        case 0x278:
        case 0x279:
            StoreMotionParamsBoth_2609A8(self, 0x28, 0x29, 0x3E, 0, 0xF6);
            recA = RES(0x200C);
            recB = RES(0x2010);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x2014);
            }
            break;
        case 0x250:
        case 0x251:
            StoreMotionParamsBoth_2609A8(self, 0x32, 0x1B, 0x45, -1, 0);
            recA = RES(0x19E8);
            recB = RES(0x19EC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x19F0);
            }
            self->timer2 = 35.0f;
            break;
        case 0x260:
            StoreMotionParamsBoth_2609A8(self, 0x46, 0x1B, 0x45, -1, 0);
            recA = RES(0x30D8);
            recB = RES(0x30DC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x30E0);
            }
            self->timer2 = 35.0f;
            break;
        case 0x264:
            StoreMotionParamsBoth_2609A8(self, 0x50, 0x37, 0x45, -1, 0);
            recA = RES(0x32DC);
            recB = RES(0x32E0);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x32E4);
            }
            self->timer2 = 32.0f;
            self->timerA = 0x14;
            if (self->subA != 0) {
                func_0027DD10((void *)self->subA, 60.0f);
            }
            break;
        case 0x220:
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
            recA = RES(0x1C30);
            recB = RES(0x1C34);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1C38);
            }
            break;
        case 0x221:
            StoreMotionParamsBoth_2609A8(self, 0x32, 0, 0x3E, 0, 0xF0);
            if (self->emFlags & 0x10000000) {
                self->unk17C3 = 1;
            } else {
                self->unk17C3 = 0;
            }
            sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            recA = RES(0x1CB8);
            recB = RES(0x1CBC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1CC0);
            }
            break;
        case 0x222:
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x22, 0x37, 0, 0xF0);
            recA = RES(0x1C70);
            recB = RES(0x1C74);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1C78);
            }
            break;
        case 0x223:
            StoreMotionParamsBoth_2609A8(self, 0x3C, 0x2A, 0x3E, -1, 0);
            recA = RES(0x2DC4);
            recB = RES(0x2DC8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x2DCC);
            }
            break;
        case 0x275:
        case 0x276:
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x2A, 0x39, 0, 0xF5);
            recA = RES(0x2310);
            recB = RES(0x2314);
            self->timer2 = 40.0f;
            break;
        case 0x256:
        case 0x27E:
            if (cCoreSave_getGameLevel(&D_00569B70) < 3 || (irand() & 1)) {
                StoreMotionParamsBoth_2609A8(self, 0x32, 0x1B, 0x45, -1, 0);
                recA = RES(0x2668);
                recB = RES(0x266C);
                self->timer2 = 32.0f;
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x32, 0x1B, 0x45, -1, 0);
                recA = RES(0x2A48);
                recB = RES(0x2A4C);
                self->timer2 = 32.0f;
            }
            break;
        case 0x252:
            recA = RES(0x2504);
            recB = RES(0x2508);
            self->stepArg = 3;
            self->timerA = 0;
            self->timer2 = 52.0f;
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x1D, 0x3E, -1, 0);
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
        func_002A8578((int)self, recA, recB, 10, 0.0f, sel, 0);
        if (fxKind_isSet(fxKind)) {
            InitRenderStruct_2A8608((cGameObj *)self, fxKind, (void *)fxNo, 0, fxMode, fxFollow);
        }
        self->timer = self->rot.y;
        self->step++;
        /* fallthrough */
    case 1:
        if (0.0f < self->timer2) {
            self->timer2 -= self->speedRate;
            self->emFlags |= 0x800000;
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
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        self->stepVec.z *= self->timer3;
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    }
    if (self->emNo == 0x222 && (self->moveFlags & 2)) {
        self->moveFlags &= ~2;
        self->unk1865 = 2;
        self->unk17D4 = 6.0f;
    }
    if (self->emNo == 0x208 && self->fx4 != 0
        && Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08((cOmBase *)self->fx4) == 0) {
        self->emFlags |= 0x80000000;
    }
    func_00260B30(self);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(self) == 0
        && (self->moveFlags & 0x10) && self->unk1864 == 0) {
        if (func_00262AA8(self) != 0) {
            return;
        }
    }
    if (self->emNo == 0x264 && (self->moveFlags & 1) && self->unk5F8 != 0) {
        self->unk5F8 = 0;
        func_0026BEF0(self, 0x16, 0);
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
