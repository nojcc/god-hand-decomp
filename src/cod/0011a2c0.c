/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"

extern unsigned char D_005864F0[];
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);

extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0010A438(void *a0);

extern void cEmManage_SetSpeedRate(void *a0, float a1);

__attribute__((section(".text.func_0011A2C0")))
void func_0011A2C0(pl00 *self)
{
    cEm00 *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    self->base.objFlags = self->base.objFlags | 0x10000;
    self->base.hitFlash = 5.0f;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->flags15F4 = self->flags15F4 | 0x200;
    if (func_0010B2E8(self, 0) != 0) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, self, 0, 0, 0, 0);
    }
    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[0] = 0.0f;
        buf[1] = 0.0f;
        buf[2] = 1.7999999523162842f;
        buf[3] = 1.0f;
        v = buf[0];
        func_001299F0(self, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x53, v, v);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 5, 0, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 5, 0, 0x2A, 0, 0xA);
        self->unk1684 = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        self->base.step = self->base.step + 1;
    case 1:
        func_00124EC0(self);
        if (moveMotion(self)) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    func_0010A438(self);
    if (func_00123938(self, 1)) {
        pl00_clearMotionCam(self, 0, 0);
    } else if (self->base.seqFlags & 0x100) {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
    }
}
