/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cEmManage.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002832F8(void *a0, int a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int irand(void);
extern void func_00260278(void *a0);

/* Phase machine on the step byte, 13 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, func_002813F0, func_002832F8, moveMotion, cObjBase_addNullSpeed_Rotation and 5
 * more. */
__attribute__((section(".text.func_0024B660"))) void func_0024B660(cEm00 *self)
{
    self->emFlags |= 0x30400;
    self->idleTimer = 2700.0f;
    switch (self->step) {
        case 0: {
            int nb;
            int b;
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3E14), EM_RES_REC(b, 0x3E18), 0xA, 0.0f,
                          nb, 0);
            if (self->sub0 != 0)
                func_002813F0(self->sub0, 0);
            if (self->sub1 != 0)
                func_002832F8(self->sub1, 0);
            if (self->sub2 != 0)
                func_002832F8(self->sub2, 0);
            self->timerA = 1;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->seqFlags & 1) != 0) {
                if (self->timerA != 0) {
                    self->timerA = 0;
                    if ((irand() & 1) != 0) {
                        if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                            func_00260278(self);
                        }
                    }
                    func_00260278(self);
                }
            }
            break;
        case 2: {
            int nb;
            int b;
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3E1C), EM_RES_REC(b, 0x3E20), 0xA, 0.0f,
                          nb, 0);
            if (self->sub0 != 0)
                func_002813F0(self->sub0, 1);
            if (self->sub1 != 0)
                func_002832F8(self->sub1, 1);
            if (self->sub2 != 0)
                func_002832F8(self->sub2, 1);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->timer = 600.0f;
                    break;
                case 2:
                    self->timer = 300.0f;
                    break;
                case 3:
                    self->timer = 210.0f;
                    break;
                case 4:
                    self->timer = 210.0f;
                    break;
                case 5:
                    self->timer = 150.0f;
                    break;
            }
            self->step += 1;
        }
            /* fallthrough */
        case 3: {
            int n;
            self->unk617 = 1;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                float t = self->timer - self->speedRate;
                self->timer = t;
                if (t <= 0.0f) {
                    self->step = 6;
                }
            }
            n = func_002919C0(&D_005864F0, 0x220, 0x220);
            n += func_002919C0(&D_005864F0, 0x220, 0x221);
            n += func_002919C0(&D_005864F0, 0x220, 0x222);
            if (n == 0) {
                self->step = 4;
            }
        } break;
        case 4: {
            int nb;
            int b;
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3E24), EM_RES_REC(b, 0x3E28), 0xA, 0.0f,
                          nb, 0);
            if (self->sub0 != 0)
                func_002813F0(self->sub0, 2);
            if (self->sub1 != 0)
                func_002832F8(self->sub1, 2);
            if (self->sub2 != 0)
                func_002832F8(self->sub2, 2);
            self->step += 1;
        }
            /* fallthrough */
        case 5:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            int nb;
            int b;
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3E2C), EM_RES_REC(b, 0x3E30), 0xA, 0.0f,
                          nb, 0);
            if (self->sub0 != 0)
                func_002813F0(self->sub0, 3);
            if (self->sub1 != 0)
                func_002832F8(self->sub1, 3);
            if (self->sub2 != 0)
                func_002832F8(self->sub2, 3);
            self->step += 1;
        }
            /* fallthrough */
        case 7:
            self->unk617 = 1;
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
