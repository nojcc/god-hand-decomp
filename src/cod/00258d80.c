#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int irand(void);
extern void func_0026ECD0(void *a0, int a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */














/* sn-2.95.3-136 matched TU. */

/* Phase machine on the step byte, 60 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468, irand,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, func_002A8578, cGameObj_SetTgtTurn and 5 more. */
__attribute__((section(".text.func_00258D80"))) void func_00258D80(cEm00 *self)
{
    int s2;
    int s1;

    switch (self->step) {
        case 0: {
            int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;

            switch (self->emNo) {
                default:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x5F8);
                        s1 = EM_RES_REC(b, 0x5FC);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x600);
                        s1 = EM_RES_REC(b, 0x604);
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
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xAF4);
                        s1 = EM_RES_REC(b, 0xAF8);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xAFC);
                        s1 = EM_RES_REC(b, 0xB00);
                    }
                    break;
                case 0x250:
                case 0x251:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xAF4);
                        s1 = EM_RES_REC(b, 0xAF8);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xAFC);
                        s1 = EM_RES_REC(b, 0xB00);
                    }
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                    break;
                case 0x260:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xAF4);
                        s1 = EM_RES_REC(b, 0xAF8);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xAFC);
                        s1 = EM_RES_REC(b, 0xB00);
                    }
                    break;
                case 0x264:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3300);
                        s1 = EM_RES_REC(b, 0x3304);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3300);
                        s1 = EM_RES_REC(b, 0x3304);
                    }
                    break;
                case 0x265:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3818);
                        s1 = EM_RES_REC(b, 0x381C);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3818);
                        s1 = EM_RES_REC(b, 0x381C);
                    }
                    break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1778);
                        s1 = EM_RES_REC(b, 0x177C);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1780);
                        s1 = EM_RES_REC(b, 0x1784);
                    }
                    break;
                case 0x241:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3ACC);
                        s1 = EM_RES_REC(b, 0x3AD0);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3AD4);
                        s1 = EM_RES_REC(b, 0x3AD8);
                    }
                    break;
                case 0x209:
                case 0x21F:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1778);
                        s1 = EM_RES_REC(b, 0x177C);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1780);
                        s1 = EM_RES_REC(b, 0x1784);
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
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xF24);
                        s1 = EM_RES_REC(b, 0xF28);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xF2C);
                        s1 = EM_RES_REC(b, 0xF30);
                    }
                    break;
                case 0x220:
                case 0x221:
                case 0x222:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x5F8);
                        s1 = EM_RES_REC(b, 0x5FC);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x600);
                        s1 = EM_RES_REC(b, 0x604);
                    }
                    break;
                case 0x223:
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x2E34);
                        s1 = EM_RES_REC(b, 0x2E38);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x2E3C);
                        s1 = EM_RES_REC(b, 0x2E40);
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
                    if (irand() & 1) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1350);
                        s1 = EM_RES_REC(b, 0x1354);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1358);
                        s1 = EM_RES_REC(b, 0x135C);
                    }
                    break;
            }
            func_002A8578(self, s2, s1, 3, 0.0f, nb, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->timerA = 0;
            {
                cDamageTake *hit = self->unk698;

                if (hit != 0) {
                    cGameObj *atk = hit->attacker;

                    if (atk != 0) {
                        cVec *d = &self->posB;
                        cVec *sv;

                        self->timerA = 0xA;
                        sv = atk->pos;
                        if (d != sv) {
                            d->x = sv->x;
                            d->y = sv->y;
                            d->z = sv->z;
                        }
                    }
                }
            }
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            int t = self->timerA;

            if (t != 0) {
                self->timerA = t - 1;
                cGameObj_SetTgtTurn(self, &self->posB, self->speedRate * 0.39269909f);
            }
            if (moveMotion(self) != 0) {
                switch (self->emNo) {
                    case 0x20E:
                    case 0x213:
                    case 0x217:
                        self->unk16E8 = self->unk16E8 + 0x3E7;
                        func_0026ECD0(self, 0);
                        break;
                }
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
}
