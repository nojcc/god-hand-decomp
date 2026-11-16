#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cCamera.h"
#include "godhand/capVu0.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
/* Turn_dest with its target last: angle.h's order loads the position before
 * the angle here. */
extern float Turn_dest(void *from, float cur, float max, void *to);
extern float SetMotionStep(void *a0, float f12);
extern int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 matched TU. */















/* Phase machine on the step byte, 80 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, Turn_dest, Adjust_theta and 6 more.
 */
__attribute__((section(".text.func_00244FC8"))) void func_00244FC8(cEm00 *self)
{
    int s2v, s0v;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
        case 0: {
            int gb;
            switch (self->emNo) {
                default:
                    if (self->seqFlags & 0x200) {
                        char *b = self->pack;
                        s2v = EM_RES_REC(b, 0xD80);
                        s0v = EM_RES_REC(b, 0xD84);
                    } else {
                        char *b = self->pack;
                        s2v = EM_RES_REC(b, 0xD88);
                        s0v = EM_RES_REC(b, 0xD8C);
                    }
                    break;
                case 522:
                case 523:
                case 524:
                case 525:
                case 526:
                case 536:
                case 581:
                case 582:
                case 583:
                case 591:
                case 632:
                case 633:
                    if (self->seqFlags & 0x200) {
                        char *b = self->pack;
                        s2v = EM_RES_REC(b, 0x8A4);
                        s0v = EM_RES_REC(b, 0x8A8);
                    } else {
                        char *b = self->pack;
                        s2v = EM_RES_REC(b, 0x8AC);
                        s0v = EM_RES_REC(b, 0x8B0);
                    }
                    break;
                case 517:
                case 518:
                case 519:
                case 521:
                case 543:
                case 548:
                    if (self->seqFlags & 0x200) {
                        char *b = self->pack;
                        s2v = EM_RES_REC(b, 0x189C);
                        s0v = EM_RES_REC(b, 0x18A0);
                    } else {
                        char *b = self->pack;
                        s2v = EM_RES_REC(b, 0x18A4);
                        s0v = EM_RES_REC(b, 0x18A8);
                    }
                    break;
            }
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            func_002A8578(self, s2v, s0v, 5, 0.0f, gb & 0xFFFF, 0);
            moveMotion(self);
            self->step = self->step + 1;
        }
        case 1: {
            float r = Turn_dest(&self->unk580, self->rot.y,
                                self->speedRate * 0.39269909f, self->pos);
            self->rot.y = self->rot.y + r;
            self->rot.y = Adjust_theta(self->rot.y);
            if (moveMotion(self) != 0) {
                self->step = self->step + 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 2: {
            int gb, w;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->emNo;
            w -= 0x205;
            switch (w) {
                default: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0xD90);
                    s0v = EM_RES_REC(b, 0xD94);
                } break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 74:
                case 115:
                case 116: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x8B4);
                    s0v = EM_RES_REC(b, 0x8B8);
                } break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 26:
                case 31: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x18AC);
                    s0v = EM_RES_REC(b, 0x18B0);
                } break;
            }
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            if ((irand() & 1) != 0) {
                self->timer = 0.0099999998f;
            } else {
                self->timer = -0.019999999f;
            }
            self->step = self->step + 1;
        }
        case 3: {
            cVec *v580 = &self->unk580;
            float r;
            float mag;
            r = Turn_dest(v580, self->rot.y, self->speedRate * 0.39269909f,
                          self->pos);
            self->rot.y = self->rot.y + r;
            self->rot.y = Adjust_theta(self->rot.y);
            SetMotionStep(self, self->speedRate * 1.5f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            self->nullSpeed.z = self->timer * self->speedRate;
            cObjBase_addNullSpeed(self, 1.0f);
            mag = capVu0MagnitudeSqXZ(self->pos, v580);
            if (mag < 4.0f) {
                self->step = 4;
            } else if (self->unk590.z * self->unk590.z < mag) {
                self->step = 6;
            }
            break;
        }
        case 4: {
            int gb, w;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->emNo;
            w -= 0x205;
            switch (w) {
                default: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0xDA0);
                    s0v = EM_RES_REC(b, 0xDA4);
                } break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 74:
                case 115:
                case 116: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x8C4);
                    s0v = EM_RES_REC(b, 0x8C8);
                } break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 26:
                case 31: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x18BC);
                    s0v = EM_RES_REC(b, 0x18C0);
                } break;
            }
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            self->step = self->step + 1;
        }
        case 5:
            self->motionFlags = self->motionFlags | 8;
            if (moveMotion(self) != 0) {
                cVec *fp = self->pos;
                self->emFlags = self->emFlags | 0x10000;
                fp->y = fp->y - 10.0f;
                self->mode = 2;
                self->phase = 2;
                self->stepArg = 1;
                self->step = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->seqFlags = self->seqFlags | 0x400;
            break;
        case 6: {
            int gb, w;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->emNo;
            w -= 0x205;
            switch (w) {
                default: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0xD98);
                    s0v = EM_RES_REC(b, 0xD9C);
                } break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 74:
                case 115:
                case 116: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x8BC);
                    s0v = EM_RES_REC(b, 0x8C0);
                } break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 26:
                case 31: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x18B4);
                    s0v = EM_RES_REC(b, 0x18B8);
                } break;
            }
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            self->step = self->step + 1;
        }
        case 7:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
