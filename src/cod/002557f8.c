#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void func_0026ECD0(void *a0, int a1);
extern float fRand1_1(void);
extern float Adjust_theta(float f12);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00262750(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */










extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);




extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);







#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

#define FRAME ((char *)va - 0x30)

/* Phase machine on the step byte, 118 case labels. Calls VU0_LQC2, VU0_SQC2, VU0_SQC2_VF0,
 * func_002740D8, irand, Obj0000_Get_Byte_17C3_NZ_2_276468 and 17 more. */
__attribute__((section(".text.func_002557F8"))) void func_002557F8(cEm00 *self)
{
    float va[4], vb[4], vc[4], vd[4];
    cVec *p = self->pos;
    int p1, p2;

    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    self->emFlags |= 0x1000;
    switch (self->step) {
        case 0: {
            int gb, w;
            self->unk1710 = 0;
            self->home.y = 0.233999997f;
            if (func_002740D8(self) != 0) {
                if (irand() & 1) {
                    self->unk17C3 = 1;
                } else {
                    self->unk17C3 = 0;
                }
            }
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->emNo;
            w -= 0x205;
            switch (w) {
                default: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x5D0);
                    p2 = EM_RES_REC(b, 0x5D4);
                } break;
                case 81:
                case 121: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x2BF4);
                    p2 = EM_RES_REC(b, 0x2BF8);
                } break;
                case 10:
                case 11:
                case 12:
                case 33:
                case 107:
                case 108:
                case 109:
                case 110:
                case 111: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0xEC4);
                    p2 = EM_RES_REC(b, 0xEC8);
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
                case 75:
                case 76:
                case 115:
                case 116: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0xA84);
                    p2 = EM_RES_REC(b, 0xA88);
                } break;
                case 91: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0xA84);
                    p2 = EM_RES_REC(b, 0xA88);
                } break;
                case 95: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x3300);
                    p2 = EM_RES_REC(b, 0x3304);
                } break;
                case 96: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x3818);
                    p2 = EM_RES_REC(b, 0x381C);
                } break;
                case 0:
                case 1:
                case 2:
                case 3:
                case 31:
                case 60: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x1728);
                    p2 = EM_RES_REC(b, 0x172C);
                } break;
                case 4:
                case 26: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x1728);
                    p2 = EM_RES_REC(b, 0x172C);
                } break;
                case 27:
                case 28:
                case 29: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x1D10);
                    p2 = EM_RES_REC(b, 0x1D14);
                } break;
                case 30: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x2D38);
                    p2 = EM_RES_REC(b, 0x2D3C);
                } break;
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 32:
                case 39:
                case 40:
                case 41:
                case 42:
                case 67:
                case 68:
                case 71:
                case 72:
                case 73:
                case 77:
                case 85: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x12F0);
                    p2 = EM_RES_REC(b, 0x12F4);
                } break;
            }
            func_002A8578(self, p1, p2, 3, 0.0f, gb, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 4), self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xF6, self, 0, 0, 0, 0);
            self->hitFlash = 10.0f;
            self->unk16E8 += 0x3E7;
            func_0026ECD0(self, 0);
            self->timerA = 0;
            {
                cDamageTake *take = self->unk698;
                if (take != 0) {
                    cGameObj *atk = take->attacker;
                    if (atk != 0) {
                        cVec *d = &self->posB;
                        cVec *src;
                        self->timerA = 0xA;
                        src = atk->pos;
                        if (d != src) {
                            self->posB.x = src->x;
                            d->y = src->y;
                            d->z = src->z;
                        }
                    }
                }
            }
            self->rot.y = self->rot.y + fRand1_1() * 0.52359879f;
            self->rot.y = Adjust_theta(self->rot.y);
            self->step += 1;
        }
        case 1: {
            float z = 0.0f;
            float one;
            cVec *q;
            self->emFlags |= 0x10000;
            q = self->pos;
            q->y = q->y + self->home.y;
            self->home.y = self->home.y - 0.0260000005f;
            if (self->home.y <= z) {
                cVec *t = self->pos;
                va[1] = va[1] + 0.5f;
                vb[1] = t->y - 10.0f;
                if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    cVec *r = self->pos;
                    if (r->y <= vc[1] + 0.100000001f) {
                        r->y = vc[1];
                        self->step = 2;
                    }
                }
            } else {
                cVec *t;
                VU0_SQC2_VF0(FRAME, 0x60);
                t = self->pos;
                vb[1] = t->y + 10.0f;
                if (ChkLine(va, vb, vd, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    cVec *r = self->pos;
                    float h = vd[1] - 1.5f;
                    if (h < r->y) {
                        r->y = h;
                        self->home.y = z;
                    }
                }
            }
            one = 1.0f;
            self->motionFlags |= 8;
            moveMotion(self);
            self->nullSpeed.z = self->speedRate * -0.159999996f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            func_00262750(self, 4);
            break;
        }
        case 2: {
            int gb, w;
            float z;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->emNo;
            w -= 0x205;
            switch (w) {
                default: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x5D8);
                    p2 = EM_RES_REC(b, 0x5DC);
                } break;
                case 81:
                case 121: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x2BFC);
                    p2 = EM_RES_REC(b, 0x2C00);
                } break;
                case 10:
                case 11:
                case 12:
                case 33:
                case 107:
                case 108:
                case 109:
                case 110:
                case 111: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0xECC);
                    p2 = EM_RES_REC(b, 0xED0);
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
                case 75:
                case 76:
                case 115:
                case 116: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0xA8C);
                    p2 = EM_RES_REC(b, 0xA90);
                } break;
                case 91: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0xA8C);
                    p2 = EM_RES_REC(b, 0xA90);
                } break;
                case 95: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x3300);
                    p2 = EM_RES_REC(b, 0x3304);
                } break;
                case 96: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x3818);
                    p2 = EM_RES_REC(b, 0x381C);
                } break;
                case 0:
                case 1:
                case 2:
                case 3:
                case 31:
                case 60: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x1730);
                    p2 = EM_RES_REC(b, 0x1734);
                } break;
                case 4:
                case 26: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x1730);
                    p2 = EM_RES_REC(b, 0x1734);
                } break;
                case 27:
                case 28:
                case 29: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x5D8);
                    p2 = EM_RES_REC(b, 0x5DC);
                } break;
                case 30: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x2D38);
                    p2 = EM_RES_REC(b, 0x2D3C);
                } break;
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 32:
                case 39:
                case 40:
                case 41:
                case 42:
                case 67:
                case 68:
                case 71:
                case 72:
                case 73:
                case 77:
                case 85: {
                    char *b = self->pack;
                    p1 = EM_RES_REC(b, 0x12F8);
                    p2 = EM_RES_REC(b, 0x12FC);
                } break;
            }
            z = 0.0f;
            func_002A8578(self, p1, p2, 0, z, gb, 0);
            SetEffectParts(0x58, 2, self, 0, z, z, z, 1.0f, -1);
            self->step += 1;
            self->timerA = 0xA;
        }
        case 3: {
            float one;
            cGameObj *o;
            int n;
            if (moveMotion(self) != 0) {
                if (cEm00_startHitUnitAim(self) != 0) {
                    return;
                }
                func_002705D8(self);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            o = Getplayer();
            cGameObj_SetTgtTurn(self, o->pos, self->speedRate * 0.196349546f);
            n = self->timerA;
            if (n != 0) {
                self->timerA = n - 1;
            } else {
                if (cEm00_startHitUnitAim(self) != 0) {
                    return;
                }
                func_00262AA8(self);
            }
            break;
        }
    }
}
