/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00Fn.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/cGameObj.h"

extern void func_0012B928(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0010A438(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cEmManage_SetSpeedRate(void *a0, float f12);
extern char D_005864F0[];
__attribute__((section(".text.func_00114120")))
void func_00114120(pl00 *self)
{
    float one;
    self->base.hitFlash = 15.0f;
    switch (self->base.step) {
    case 0: {
        char *v0;
        int p1, p2;
        self->comboSlot = 0;
        self->comboSet = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        v0 = self->base.pack;
        p1 = *(int *)(v0 + 0x10) + (int)v0;
        p2 = *(int *)(v0 + 0x14) + (int)v0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 5, 0x17, 0x2A, 0, 0xA);
        self->unk1684 = 1;
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        func_0012B928(self);
        CallWithAndClearField698_12AC28(self);
        self->base.step += 1;
    }
    case 1:
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    if (self->base.seqFlags & 1) {
        cHeatSys *hs = &D_005CB000;
        if (hs->mode == 0) {
            cHeatSys_SetHeatMode(hs, 1);
            self->unk15F4 = (self->unk15F4 | 0x10) & ~0x20;
            CallWithAndClearField698_12AC28(self);
            func_0012B928(self);
        }
    }
    func_0010A438(self);
    if (func_00123938(self, 1) == 0) {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}

__attribute__((section(".text.func_00111010")))
void func_00111010(pl00 *self)
{
    float one;
    self->base.hitFlash = 3.0f;
    switch (self->base.step) {
    case 0: {
        int p1, p2;
        self->comboSlot = 0;
        self->comboSet = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        if (self->base.stepArg != 0) {
            char *v = self->base.pack;
            p1 = *(int *)(v + 0x4BC) + (int)v;
            p2 = *(int *)(v + 0x4C0) + (int)v;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x32, 0x26, 0x1D, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x32, 0x26, 0x1D, 0, 0x123);
        } else {
            char *v = self->base.pack;
            p1 = *(int *)(v + 0x494) + (int)v;
            p2 = *(int *)(v + 0x498) + (int)v;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x32, 0x25, 0x1D, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x32, 0x25, 0x1D, 0, 0x123);
        }
        self->unk1684 = 0;
        func_002A8578(self, p1, p2, 0, 0.0f, 0, 0);
        cCoreSave_addGameLevelPoint(&D_00569B70, 100);
        self->base.hitFlash = 15.0f;
        self->base.step += 1;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    func_0010A438(self);
    if (self->base.seqFlags & 0x100) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if (func_00123938(self, 1) != 0) {
        pl00_clearMotionCam(self, 1, 0);
    }
}
