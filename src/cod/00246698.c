#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cEmManage.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float fRand1_1(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int irand(void);
extern void func_002744E0(void *a0);
extern char *CreateObj(int a0, int a1);
#include "godhand/cOmWeapon.h"
extern void func_001D0340(void *a0);
extern void func_001D0408(void *a0);

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"



















/* Phase machine on the step byte, 76 case labels. Calls ForwardAnimParamPairByIndex_27EA50, irand,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, fRand1_1, moveMotion and 12 more. */
__attribute__((section(".text.func_00246698"))) void func_00246698(cEm00 *self)
{
    int s2v, s1v;
    cVec grip[2];

    switch (self->step) {
        case 0: {
            int gb;
            int w;
            float fv;

            self->unk1864 = 0;
            w = self->emNo;
            w -= 0x205;
            switch (w) {
                default: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x43C);
                    s1v = EM_RES_REC(b, 0x440);
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
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x1458);
                    s1v = EM_RES_REC(b, 0x145C);
                } break;
                case 5:
                case 6:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 115:
                case 116: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0xBF8);
                    s1v = EM_RES_REC(b, 0xBFC);
                } break;
                case 75:
                case 76: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0xB84);
                    s1v = EM_RES_REC(b, 0xB88);
                } break;
                case 91: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x3038);
                    s1v = EM_RES_REC(b, 0x303C);
                } break;
                case 95: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x326C);
                    s1v = EM_RES_REC(b, 0x3270);
                } break;
                case 96: {
                    int b = EM_RES(self);
                    cEm00 *t = self->unk744;
                    s2v = EM_RES_REC(b, 0x3724);
                    s1v = EM_RES_REC(b, 0x3728);
                    if (t != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t, 0);
                    }
                } break;
                case 7:
                case 74: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0xB84);
                    s1v = EM_RES_REC(b, 0xB88);
                } break;
                case 0:
                case 2: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x17F8);
                    s1v = EM_RES_REC(b, 0x17FC);
                } break;
                case 31: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x18DC);
                    s1v = EM_RES_REC(b, 0x18E0);
                } break;
                case 60:
                    if ((irand() & 1) != 0) {
                        int b = EM_RES(self);
                        s2v = EM_RES_REC(b, 0x3B1C);
                        s1v = EM_RES_REC(b, 0x3B20);
                    } else {
                        int b = EM_RES(self);
                        s2v = EM_RES_REC(b, 0x3B24);
                        s1v = EM_RES_REC(b, 0x3B28);
                    }
                    break;
                case 1: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x1890);
                    s1v = EM_RES_REC(b, 0x1894);
                } break;
                case 3: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x1EA0);
                    s1v = EM_RES_REC(b, 0x1EA4);
                } break;
                case 4:
                case 26: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x3418);
                    s1v = EM_RES_REC(b, 0x341C);
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
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0xF94);
                    s1v = EM_RES_REC(b, 0xF98);
                } break;
                case 27:
                case 28:
                case 29: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x1BC0);
                    s1v = EM_RES_REC(b, 0x1BC4);
                } break;
                case 30: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x2D38);
                    s1v = EM_RES_REC(b, 0x2D3C);
                } break;
                case 112:
                case 113: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x3F4);
                    s1v = EM_RES_REC(b, 0x3F8);
                } break;
            }
            switch (self->entryNo & 7) {
                default:
                case 0:
                    fv = 0.0f;
                    break;
                case 1:
                    fv = 30.0f;
                    break;
                case 2:
                    fv = 15.0f;
                    break;
                case 3:
                    fv = 45.0f;
                    break;
                case 4:
                    fv = 10.0f;
                    break;
                case 5:
                    fv = 40.0f;
                    break;
                case 6:
                    fv = 5.0f;
                    break;
                case 7:
                    fv = 25.0f;
                    break;
            }
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            func_002A8578(self, s2v, s1v, 10, fv, gb & 0xFFFF, 0);
            self->timerA = 1;
            self->timer = fRand1_1() * 300.0f + 150.0f;
            self->step = self->step + 1;
        }
        case 1:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->emFlags & 0x20000000) != 0) {
                if ((self->seqFlags & 3) != 0 && self->timerA != 0) {
                    self->timerA = 0;
                    func_002744E0(self);
                }
                if (func_00294A68(&D_005864F0) != 0) {
                    self->timer = fRand1_1() * 300.0f + 150.0f;
                } else {
                    self->timer = self->timer - self->speedRate;
                    if (self->timer <= 0.0f) {
                        D_005864F0.unk540 = 10;
                        self->step = 2;
                    }
                }
            }
            break;
        case 2: {
            int gb;

            self->unk1864 = 0;
            switch (self->emNo) {
                default: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0x504);
                    s1v = EM_RES_REC(b, 0x508);
                } break;
                case 0x20A:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247: {
                    int b = EM_RES(self);
                    s2v = EM_RES_REC(b, 0xC54);
                    s1v = EM_RES_REC(b, 0xC58);
                } break;
            }
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            func_002A8578(self, s2v, s1v, 10, 0.0f, gb & 0xFFFF, 0);
            self->timerA = 1;
            self->step = self->step + 1;
        }
        case 3:
            D_005864F0.unk540 = 10;
            if (moveMotion(self) != 0) {
                self->step = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->seqFlags & 1) != 0 && self->gotoEffect == 0) {
                char *obj = CreateObj(0x3B1, 0xFFFF);
                self->gotoEffect = obj;
                if (obj != 0) {
                    char *cls;
                    int (*fn)(char *);
                    short off;
                    cVec *src;
                    cVec *src2;
                    cVec *dst;
                    cVec *d490;
                    int *p100;

                    VU0_SQC2_VF0(grip, 0x0);
                    VU0_SQC2_VF0(grip, 0x10);
                    cls = *(char **)(obj + 0x214);
                    fn = *(int (**)(char *))(cls + 0x44);
                    off = *(short *)(cls + 0x40);
                    fn(obj + off);

                    dst = *(cVec **)(self->gotoEffect + 0xF0);
                    src = self->pos;
                    if (dst != src) {
                        dst->x = src->x;
                        dst->y = src->y;
                        dst->z = src->z;
                    }
                    src2 = self->pos;
                    d490 = (cVec *)(self->gotoEffect + 0x490);
                    if (d490 != src2) {
                        d490->x = src2->x;
                        d490->y = src2->y;
                        d490->z = src2->z;
                    }
                    p100 = (int *)(self->gotoEffect + 0x100);
                    p100[0] = 0;
                    p100[1] = 0;
                    p100[2] = 0;
                    grip[0].x = 0.0f;
                    grip[0].y = -0.3f;
                    grip[0].z = 0.1f;
                    grip[1].x = 1.3f;
                    grip[1].y = 0.0f;
                    grip[1].z = 0.0f;
                    cOmWeapon_setParent((cOmWeapon *)(*(int *)((char *)self + 0x738)), (cOmBase *)self, 10, &grip[0], &grip[1]);
                }
            }
            if ((self->seqFlags & 2) != 0 && *(int *)((char *)self + 0x738) != 0) {
                func_001D0340(self->gotoEffect);
                *(int *)((char *)self + 0x738) = 0;
            }
            break;
    }
    if (cEmManage_findEma2Near(&D_005864F0, self->pos, 10.0f) == 0) {
        if (*(int *)((char *)self + 0x738) != 0) {
            func_001D0408(self->gotoEffect);
            *(int *)((char *)self + 0x738) = 0;
        }
        func_002705D8(self);
    } else if (self->slideTime > 0.0f || self->unk16EC > 0) {
        func_002705D8(self);
    }
}
