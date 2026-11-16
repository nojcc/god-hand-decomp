/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* func_0010EE80 — 0x0010EE80, 880 B — sn-2.95.3-136.
 * +0x2F6 phase machine; template src/cod/00111750.c. */

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);

extern void func_00129578(void *a0);

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_0010A438(void *a0);

extern int  D_00747A0C;
extern char D_005864F0[];

__attribute__((section(".text.func_0010EE80")))
void func_0010EE80(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    self->flags15F4 |= 0x200;
    if (self->base.step != 0 &&
        self->unk649 == 0 &&
        func_0010B2E8(self, 1) != 0) {
        self->unk649 = 1;
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (self->base.step) {
    case 0:
    {
        int p, q;

        func_00129578(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_00124540(self, 1);
        if (self->base.stepArg != 0) {
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0xE6, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0xE6, 0xD, 0x1D, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0xC8, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0xC8, 0xD, 0x1D, 0, 0x123);
            }
            {
                int t = (int)self->base.pack;
                p = *(int *)(t + 0xD4) + t;
                q = *(int *)(t + 0xDC) + t;
            }
        } else {
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x64, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x64, 0xD, 0x1D, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x50, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x50, 0xD, 0x1D, 0, 0x123);
            }
            {
                int t = (int)self->base.pack;
                p = *(int *)(t + 0xD4) + t;
                q = *(int *)(t + 0xD8) + t;
            }
        }
        self->unk1684 = 1;
        func_002A8578(self, p, q, 3, 0.0f, 0, 0);
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        InvokeVirtualAtField214AndForward_124E68(self, 0.13089969754219055f);
        if (moveMotion(self) != 0) {
            func_00129630(self);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
            pl00_clearMotionCam(self, 1, 0);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if ((self->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    func_0010A438(self);
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 1, 0);
    } else {
        if ((self->base.seqFlags & 1) != 0) {
            cSnd *g = &D_005FEE00;
            cSnd_SeStop(g, self->unk161C);
            self->unk161C = 0;
            g->flagsB0 &= 0xFFBFFFFF;
            g->flagsAC &= 0xFFBFFFFF;
        }
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
