#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int Getplayer(void);
#include "godhand/cOmWeapon.h"
#include "godhand/cGameObj.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026ECD0(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */

















/* Phase machine on the step byte, 63 case labels. Calls cSnd_SeCall_2CBA48, GetSeqSEBase,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, Obj1D00_ClearState_6, Obj1D00_ClearState_7 and
 * 8 more. */
__attribute__((section(".text.func_0023B678"))) void func_0023B678(cEm00 *self)
{
    int s2;
    int s1;

    self->emFlags |= 0x400;
    switch (self->step) {
        case 0: {
            int w;
            int nb;

            self->unk1864 = 0;
            w = self->emNo;
            w -= 0x202;
            switch (w) {
                default: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x39C);
                    s1 = EM_RES_REC(p, 0x3A0);
                } break;
                case 0:
                case 1:
                case 17:
                case 20:
                case 21:
                case 39:
                case 40:
                case 73:
                case 84:
                case 124: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x7C4);
                    s1 = EM_RES_REC(p, 0x7C8);
                } break;
                case 64:
                case 65:
                case 66: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x3698);
                    s1 = EM_RES_REC(p, 0x369C);
                } break;
                case 8:
                case 11:
                case 12:
                case 22:
                case 67:
                case 68:
                case 69:
                case 118:
                case 119: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0xB74);
                    s1 = EM_RES_REC(p, 0xB78);
                } break;
                case 9: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x1E34);
                    s1 = EM_RES_REC(p, 0x1E38);
                } break;
                case 10:
                case 77: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x1F80);
                    s1 = EM_RES_REC(p, 0x1F84);
                } break;
                case 3:
                case 4:
                case 5:
                case 6:
                case 34: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x17D8);
                    s1 = EM_RES_REC(p, 0x17DC);
                } break;
                case 63: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x3AFC);
                    s1 = EM_RES_REC(p, 0x3B00);
                } break;
                case 7:
                case 29: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x345C);
                    s1 = EM_RES_REC(p, 0x3460);
                } break;
                case 78:
                case 79: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x1A18);
                    s1 = EM_RES_REC(p, 0x1A1C);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                } break;
                case 94: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x1A18);
                    s1 = EM_RES_REC(p, 0x1A1C);
                } break;
                case 98: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x326C);
                    s1 = EM_RES_REC(p, 0x3270);
                } break;
                case 99: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x3724);
                    s1 = EM_RES_REC(p, 0x3728);
                } break;
                case 30:
                case 31:
                case 32: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x1D50);
                    s1 = EM_RES_REC(p, 0x1D54);
                } break;
                case 33: {
                    char *p = self->pack;
                    s1 = EM_RES_REC(p, 0x2D74);
                    s2 = s1;
                } break;
                case 115:
                case 116: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x23A8);
                    s1 = EM_RES_REC(p, 0x23AC);
                } break;
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 35:
                case 42:
                case 43:
                case 44:
                case 45:
                case 70:
                case 71:
                case 74:
                case 75:
                case 76:
                case 80:
                case 88: {
                    char *p = self->pack;
                    s2 = EM_RES_REC(p, 0x13B8);
                    s1 = EM_RES_REC(p, 0x13BC);
                } break;
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 3, 0.0f, nb, 0);
            if (self->fx0 != 0) {
                Obj1D00_ClearState_6(&(self->fx0)->base);
            }
            if (self->fx6 != 0) {
                Obj1D00_ClearState_7(&(self->fx6)->base);
            }
            self->unk16E8 += 0x3E7;
            func_0026ECD0(self, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            int r = Getplayer();

            cGameObj_SetTgtTurn(self, *(cVec **)(r + 0xF0), self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0 || (self->seqFlags & 0x10) != 0) {
                if (func_00262AA8(self) == 0) {
                    func_002705D8(self);
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
        } break;
    }
}
