#include "godhand/cEm00.h"
#include "godhand/cDamageUnit.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int irand(void);
extern void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(int a0, int a1);
extern int GetSeqSEBase(void *a0);
extern void func_002726F8(void *a0);
extern void func_00274FE8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* sn-2.95.3-136 matched TU. */

















/* Phase machine on the step byte, 57 case labels. Calls ReleaseField6ECByTag564_26B1E8,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, irand, Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0,
 * func_002A8578, cSnd_SeCall_2CBA48 and 8 more. */
__attribute__((section(".text.func_00257560"))) void func_00257560(cEm00 *self)
{
    cDamageUnit *s4;
    cGameObjVt *vt;
    int s1v;
    int s0v;
    int c17c1;
    int lim548;

    vt = cGameObj_vt((cGameObj *)self);
    s4 = vt->getDamageUnit((char *)self + vt->damageUnitDelta);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0: {
            int s3;

            ReleaseField6ECByTag564_26B1E8(self);
            s3 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default:
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x340);
                        s0v = EM_RES_REC(b, 0x344);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x338);
                        s0v = EM_RES_REC(b, 0x33C);
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
                case 0x250:
                case 0x251:
                case 0x278:
                case 0x279:
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0xACC);
                        s0v = EM_RES_REC(b, 0xAD0);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0xAD4);
                        s0v = EM_RES_REC(b, 0xAD8);
                    }
                    break;
                case 0x260:
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x31A4);
                        s0v = EM_RES_REC(b, 0x31A8);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x31A4);
                        s0v = EM_RES_REC(b, 0x31A8);
                    }
                    break;
                case 0x264: {
                    char *b = self->pack;
                    int t = self->subA;

                    s1v = EM_RES_REC(b, 0x33B0);
                    s0v = EM_RES_REC(b, 0x33B4);
                    if (t != 0) {
                        Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(t, 0);
                    }
                    break;
                }
                case 0x265: {
                    char *b = self->pack;

                    s1v = EM_RES_REC(b, 0x3988);
                    s0v = EM_RES_REC(b, 0x398C);
                    break;
                }
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                case 0x241:
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x1768);
                        s0v = EM_RES_REC(b, 0x176C);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x1760);
                        s0v = EM_RES_REC(b, 0x1764);
                    }
                    break;
                case 0x209:
                case 0x21F:
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x1768);
                        s0v = EM_RES_REC(b, 0x176C);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x1760);
                        s0v = EM_RES_REC(b, 0x1764);
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
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0xF0C);
                        s0v = EM_RES_REC(b, 0xF10);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0xF14);
                        s0v = EM_RES_REC(b, 0xF18);
                    }
                    break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    char *b = self->pack;

                    s1v = EM_RES_REC(b, 0x1D08);
                    s0v = EM_RES_REC(b, 0x1D0C);
                    break;
                }
                case 0x223: {
                    char *b = self->pack;

                    s1v = EM_RES_REC(b, 0x2E4C);
                    s0v = EM_RES_REC(b, 0x2E50);
                    break;
                }
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
                    if (irand() & 1) {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x1340);
                        s0v = EM_RES_REC(b, 0x1344);
                    } else {
                        char *b = self->pack;
                        s1v = EM_RES_REC(b, 0x1338);
                        s0v = EM_RES_REC(b, 0x133C);
                    }
                    break;
            }
            func_002A8578(self, s1v, s0v, 5, 0.0f, s3, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x112, self, 0, 0, 0, 0);
            c17c1 = self->slowFlinch;
            if (c17c1 == 0) {
                lim548 = self->hpMax;
                if (c17c1 >= lim548) {
                    self->hp = self->hpMax;
                } else {
                    self->hp = 0;
                }
            }
            if (self->hp <= 0) {
                func_002726F8(self);
                if (self->hp <= 0) {
                    cDamageUnit_SetDamageCollActive(s4, 0);
                }
            }
            self->step = self->step + 1;
        }
        case 1: {
            float one;

            self->hitFlash = 3.0f;
            self->motionFlags = self->motionFlags | 8;
            if (moveMotion(self) != 0) {
                if (self->hp <= 0) {
                    if (self->flags1644 & 0x800000) {
                        self->mode = 2;
                        self->phase = 3;
                        self->step = 0;
                        self->stepArg = 0;
                    } else {
                        func_0025FE30(self, 0x1000000, 0);
                        self->mode = 2;
                        self->phase = 2;
                        self->step = 0;
                        self->stepArg = 0;
                    }
                } else {
                    func_00274FE8(self);
                }
            } else {
                one = 1.0f;
                cObjBase_addNullSpeed_Rotation(self, one);
                cObjBase_addNullSpeed(self, one);
            }
            break;
        }
    }
}
