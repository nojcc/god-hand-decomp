#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */












/* Phase machine on the step byte, 64 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, func_002A8578, cGameObj_SetTgtTurn, moveMotion and 3 more. */
__attribute__((section(".text.func_002591F8"))) void func_002591F8(cEm00 *self)
{
    int s2;
    int s1;

    switch (self->step) {
        case 0: {
            int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;

            if (self->hp <= 0) {
                self->hp = 1;
            }
            switch (self->emNo) {
                default: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x640);
                    s1 = EM_RES_REC(b, 0x644);
                } break;
                case 0x214:
                case 0x215: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x1B98);
                    s1 = EM_RES_REC(b, 0x1B9C);
                } break;
                case 0x242:
                case 0x243:
                case 0x244: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x36B0);
                    s1 = EM_RES_REC(b, 0x36B4);
                } break;
                case 0x256:
                case 0x27E: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x2BC0);
                    s1 = EM_RES_REC(b, 0x2BC4);
                } break;
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
                case 0x279: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0xB6C);
                    s1 = EM_RES_REC(b, 0xB70);
                } break;
                case 0x250:
                case 0x251: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0xB6C);
                    s1 = EM_RES_REC(b, 0xB70);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                } break;
                case 0x260: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0xB6C);
                    s1 = EM_RES_REC(b, 0xB70);
                } break;
                case 0x264: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x326C);
                    s1 = EM_RES_REC(b, 0x3270);
                } break;
                case 0x265: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x3724);
                    s1 = EM_RES_REC(b, 0x3728);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x17F0);
                    s1 = EM_RES_REC(b, 0x17F4);
                } break;
                case 0x241: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x3B14);
                    s1 = EM_RES_REC(b, 0x3B18);
                } break;
                case 0x209:
                case 0x21F: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x3474);
                    s1 = EM_RES_REC(b, 0x3478);
                } break;
                case 0x20F:
                case 0x210:
                case 0x211:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0xF24);
                    s1 = EM_RES_REC(b, 0xF28);
                } break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x640);
                    s1 = EM_RES_REC(b, 0x644);
                } break;
                case 0x223: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x2EDC);
                    s1 = EM_RES_REC(b, 0x2EE0);
                } break;
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
                case 0x25A: {
                    int b = EM_RES(self);
                    s2 = EM_RES_REC(b, 0x13D0);
                    s1 = EM_RES_REC(b, 0x13D4);
                } break;
            }
            func_002A8578(self, s2, s1, 5, 0.0f, nb, 0);
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
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
}
