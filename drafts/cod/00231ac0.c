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

#define RES(off) EM_RES_REC(EM_RES(self), off)

/* A turn in place: step 0 picks the turn motion for the enemy type and sets the
 * facing to turn to, step 1 turns toward the player for a level-scaled number of
 * frames until the motion ends, step 2 starts the turn back and step 3 turns
 * toward the player until it ends. */
__attribute__((section(".text.func_00231AC0")))
void func_00231AC0(cEm00 *self)
{
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
        self->timer3 = 0.0f;
        self->timer = self->rot.y + 3.14159274f;
        self->timer = Adjust_theta(self->timer);
        self->timerC = 0;
        switch (self->emNo) {
        default:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x3E, -1, 0);
            recA = RES(0x8FC);
            recB = RES(0x900);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x904);
            }
            break;
        case 0x20C:
        case 0x24F:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x3E, 0, 0xF0);
            recA = RES(0x8FC);
            recB = RES(0x900);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x904);
            }
            break;
        case 0x218:
        case 0x246:
        case 0x278:
        case 0x279:
            StoreMotionParamsBoth_2609A8(self, 0x14, 0x24, 0x3E, -1, 0);
            recA = RES(0xCD8);
            recB = RES(0xCDC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0xCE0);
            }
            self->timer2 = 30.0f;
            break;
        case 0x209:
        case 0x21F:
            StoreMotionParamsBoth_2609A8(self, 0x32, 0x24, 0x3E, 0, 0xF0);
            recA = RES(0x34E8);
            recB = RES(0x34EC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x34F0);
                InitRenderStruct_2A8608((cGameObj *)self, 0x61, 0x14, 0, 2, self->fx5);
            } else {
                InitRenderStruct_2A8608((cGameObj *)self, 0x61, 0x13, 0, 2, self->fx5);
            }
            self->timer3 = 16.0f;
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                self->timer3 = 13.0f;
            }
            self->timer2 = 30.0f;
            break;
        case 0x264:
            if (1.9198622f < self->unk760) {
                if (0.0f < self->unk75C) {
                    StoreMotionParamsBoth_2609A8(self, 0x3C, 0x34, 0x3E, -1, 0);
                    recA = RES(0x32F4);
                    recB = RES(0x32F8);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x32FC);
                    }
                } else {
                    StoreMotionParamsBoth_2609A8(self, 0x3C, 0x34, 0x3E, -1, 0);
                    recA = RES(0x32E8);
                    recB = RES(0x32EC);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x32F0);
                    }
                }
            } else {
                if (0.0f < self->unk75C) {
                    StoreMotionParamsBoth_2609A8(self, 0x3C, 0x35, 0x3E, -1, 0);
                    recA = RES(0x32C4);
                    recB = RES(0x32C8);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x32CC);
                    }
                    self->timer = self->rot.y + 0.785398185f;
                    self->timer = Adjust_theta(self->timer);
                } else {
                    StoreMotionParamsBoth_2609A8(self, 0x3C, 0x35, 0x3E, -1, 0);
                    recA = RES(0x32D0);
                    recB = RES(0x32D4);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x32D8);
                    }
                    self->timer = self->rot.y + -0.785398185f;
                    self->timer = Adjust_theta(self->timer);
                }
            }
            self->timer2 = 30.0f;
            break;
        case 0x265:
            if (0.0f < self->unk75C) {
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0x38, 0x3E, -1, 0);
                recA = RES(0x3800);
                recB = RES(0x3804);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3808);
                }
                self->timer = self->rot.y + 1.57079637f;
                self->timer = Adjust_theta(self->timer);
            } else {
                StoreMotionParamsBoth_2609A8(self, 0x3C, 0x38, 0x3E, -1, 0);
                recA = RES(0x37F4);
                recB = RES(0x37F8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x37FC);
                }
                self->timer = self->rot.y + -1.57079637f;
                self->timer = Adjust_theta(self->timer);
            }
            self->timer2 = 30.0f;
            break;
        case 0x21C:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x24D:
        case 0x252:
        case 0x25A:
            StoreMotionParamsBoth_2609A8(self, 0x14, 9, 0x3E, -1, 0);
            recA = RES(0x1200);
            recB = RES(0x1204);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1208);
            }
            self->timer2 = 30.0f;
            break;
        }
        func_002A8578(self, recA, recB, 3, 0.0f, sel, 0);
        self->timerA = 30;
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
        /* fallthrough */
    case 1:
        if (0.0f < self->timer2) {
            self->emFlags |= 0x800000;
            self->timer2 -= self->speedRate;
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
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if (self->emNo == 0x21F) {
            self->timer3 -= self->speedRate;
            if (self->timer3 <= 0.0f) {
                self->step = 2;
            }
        }
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        StoreMotionParamsBoth_2609A8(self, 0x32, 0x1A, 0x37, 0, 0xF0);
        recA = RES(0x35A0);
        recB = RES(0x35A4);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            recB = RES(0x35A8);
        }
        func_002A8578(self, recA, recB, 3, 0.0f, sel, 0);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            InitRenderStruct_2A8608((cGameObj *)self, 0x77, 0x18, 0, 2, self->fx5);
        } else {
            InitRenderStruct_2A8608((cGameObj *)self, 0x77, 0x17, 0, 2, self->fx5);
        }
        self->timerA = 30;
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
        self->timer = self->rot.y + 3.14159274f;
        self->timer = Adjust_theta(self->timer);
        self->step++;
        self->timerC = 0;
        /* fallthrough */
    case 3:
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
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    }
    if (self->unk1864 == 0) {
        func_00260B30(self);
    }
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
