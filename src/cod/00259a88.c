/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"

extern float fRand0_1(void);
extern int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern char *Getplayer(void);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);

/* sn-2.95.3-136 matched TU. */























/* Phase machine on the step byte, 92 case labels. Calls fRand0_1, cCoreSave_getGameLevel, irand,
 * func_002740D8, Obj0000_Get_Byte_17C3_NZ_2_276468, cSnd_SeCall_2CBA48 and 15 more. */
__attribute__((section(".text.func_00259A88"))) void func_00259A88(cEm00 *self)
{
    int p1;
    int p2;

    switch (self->emNo) {
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24E:
        case 0x25A:
            if (self->step == 0) {
                if (fRand0_1() < 0.25f) {
                    self->step = 2;
                }
            }
            break;
        case 0x213:
        case 0x217:
            if (self->step == 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    if (irand() & 1) {
                        self->step = 8;
                    }
                }
            }
            break;
    }

    switch (self->step) {
        case 0: {
            int nb;

            if (func_002740D8(self) != 0) {
                if (irand() & 1) {
                    self->unk17C3 = 1;
                } else {
                    self->unk17C3 = 0;
                }
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x618);
                        p2 = EM_RES_REC(b, 0x61C);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x620);
                        p2 = EM_RES_REC(b, 0x624);
                    }
                    break;
                case 0x20A:
                case 0x20B:
                case 0x20C:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247:
                case 0x24F:
                case 0x278:
                case 0x279:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xB2C);
                        p2 = EM_RES_REC(b, 0xB30);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xB34);
                        p2 = EM_RES_REC(b, 0xB38);
                    }
                    break;
                case 0x250:
                case 0x251:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xB2C);
                        p2 = EM_RES_REC(b, 0xB30);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xB34);
                        p2 = EM_RES_REC(b, 0xB38);
                    }
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                    break;
                case 0x260:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xB2C);
                        p2 = EM_RES_REC(b, 0xB30);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xB34);
                        p2 = EM_RES_REC(b, 0xB38);
                    }
                    break;
                case 0x264:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x326C);
                        p2 = EM_RES_REC(b, 0x3270);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x326C);
                        p2 = EM_RES_REC(b, 0x3270);
                    }
                    break;
                case 0x265:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x3818);
                        p2 = EM_RES_REC(b, 0x381C);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x3818);
                        p2 = EM_RES_REC(b, 0x381C);
                    }
                    break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x17A8);
                        p2 = EM_RES_REC(b, 0x17AC);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x17A8);
                        p2 = EM_RES_REC(b, 0x17AC);
                    }
                    break;
                case 0x241:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x3AEC);
                        p2 = EM_RES_REC(b, 0x3AF0);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x3AEC);
                        p2 = EM_RES_REC(b, 0x3AF0);
                    }
                    break;
                case 0x209:
                case 0x21F:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x17A8);
                        p2 = EM_RES_REC(b, 0x17AC);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x17A8);
                        p2 = EM_RES_REC(b, 0x17AC);
                    }
                    break;
                case 0x20F:
                case 0x210:
                case 0x211:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xF54);
                        p2 = EM_RES_REC(b, 0xF58);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0xF5C);
                        p2 = EM_RES_REC(b, 0xF60);
                    }
                    break;
                case 0x220:
                case 0x221:
                case 0x222:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x618);
                        p2 = EM_RES_REC(b, 0x61C);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x618);
                        p2 = EM_RES_REC(b, 0x61C);
                    }
                    break;
                case 0x223:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x2E7C);
                        p2 = EM_RES_REC(b, 0x2E80);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x2E7C);
                        p2 = EM_RES_REC(b, 0x2E80);
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
                case 0x252:
                case 0x25A:
                    if (self->seqFlags & 0x200) {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x1380);
                        p2 = EM_RES_REC(b, 0x1384);
                    } else {
                        int b = (int)self->pack;
                        p1 = EM_RES_REC(b, 0x1388);
                        p2 = EM_RES_REC(b, 0x138C);
                    }
                    break;
            }
            self->timer = 1.0f;
            if (self->slowFlinch != 0) {
                self->timer = 1.5f;
            }
            func_002A8578(self, p1, p2, 3, 0.0f, nb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, self->timer);
            if (self->seqFlags & 8) {
                self->hitFlash = 2.0f;
            }
            break;
        case 2: {
            int b = (int)self->pack;

            func_002A8578(self, EM_RES_REC(b, 0x1400), EM_RES_REC(b, 0x1404), 3, 0.0f, 0, 0);
            self->hitFlash = 10.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 3:
            self->emFlags2 |= 0x80000;
            if (moveMotion(self) != 0) {
                self->step = 4;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 4: {
            int b = (int)self->pack;

            func_002A8578(self, EM_RES_REC(b, 0x1408), EM_RES_REC(b, 0x140C), 3, 0.0f, 0, 0);
            self->unk568 = 5;
            self->step += 1;
        }
            /* fallthrough */
        case 5: {
            char *g;
            float t;

            self->emFlags2 |= 0x80000;
            g = Getplayer();
            t = Turn_dest(*(void **)(g + 0xF0), self->rot.y,
                          self->speedRate * 0.098174773f, self->pos);
            self->rot.y = self->rot.y + t;
            self->rot.y = Adjust_theta(self->rot.y);
            if (moveMotion(self) != 0) {
                self->unk568 = self->unk568 - 1;
                if (self->unk568 <= 0) {
                    self->step = 6;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 6: {
            int b = (int)self->pack;

            func_002A8578(self, EM_RES_REC(b, 0x1410), EM_RES_REC(b, 0x1414), 3, 0.0f, 0, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 7:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 8:
            if (self->seqFlags & 0x200) {
                int b = (int)self->pack;
                cOmWeapon *o = self->fx6;

                p1 = EM_RES_REC(b, 0x2F74);
                p2 = EM_RES_REC(b, 0x2F78);
                if (o != 0) {
                    Obj1D00_SetState_7_E_a1(&o->base, 1);
                }
            } else {
                int b = (int)self->pack;
                cOmWeapon *o = self->fx6;

                p1 = EM_RES_REC(b, 0x2F7C);
                p2 = EM_RES_REC(b, 0x2F80);
                if (o != 0) {
                    Obj1D00_SetState_7_E_a1(&o->base, 0);
                }
            }
            func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
            self->hitFlash = 10.0f;
            self->step += 1;
            /* fallthrough */
        case 9:
            if (moveMotion(self) != 0) {
                self->step = 0xA;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 10: {
            int b = (int)self->pack;
            cOmWeapon *o;

            func_002A8578(self, EM_RES_REC(b, 0x2F94), EM_RES_REC(b, 0x2F98), 3, 0.0f, 0, 0);
            o = self->fx6;
            if (o != 0) {
                Obj1D00_SetState_7_14(&o->base);
            }
            self->step += 1;
        }
            /* fallthrough */
        case 11:
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                self->step = 0xC;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 12: {
            int b = (int)self->pack;
            cOmWeapon *o;

            func_002A8578(self, EM_RES_REC(b, 0x2F84), EM_RES_REC(b, 0x2F88), 3, 0.0f, 0, 0);
            self->unk568 = 5;
            o = self->fx6;
            if (o != 0) {
                Obj1D00_SetState_7_10(&o->base);
            }
            self->timer = 3.0f;
            switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
                case 0:
                default:
                    self->timer2 = 60.0f;
                    break;
                case 1:
                    self->timer2 = 90.0f;
                    break;
                case 2:
                    self->timer2 = 120.0f;
                    break;
                case 3:
                    self->timer2 = 120.0f;
                    break;
                case 4:
                    self->timer2 = 120.0f;
                    break;
            }
            self->step += 1;
        }
            /* fallthrough */
        case 13: {
            char *g = Getplayer();

            cGameObj_SetTgtTurn(self, *(cVec **)(g + 0xF0), self->speedRate * 0.049087387f);
            moveMotion(self);
            self->nullSpeed.z = self->speedRate * -0.05f;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->timer = self->timer - self->speedRate;
            if (self->timer <= 0.0f) {
                func_0026BEF0(self, 0x12, 0);
                self->timer = 20.0f;
            }
            self->timer2 = self->timer2 - self->speedRate;
            if (self->timer2 <= 0.0f) {
                self->step = 0xE;
            }
            break;
        }
        case 14: {
            int b = (int)self->pack;
            cOmWeapon *o;

            func_002A8578(self, EM_RES_REC(b, 0x2F8C), EM_RES_REC(b, 0x2F90), 3, 0.0f, 0, 0);
            o = self->fx6;
            if (o != 0) {
                Obj1D00_SetState_7_12(&o->base);
            }
            self->step += 1;
        }
            /* fallthrough */
        case 15:
            if (moveMotion(self) != 0) {
                self->phase = 0x49;
                self->step = 2;
                self->mode = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
