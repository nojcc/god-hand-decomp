/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"

extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f12);
extern void cObjBase_addNullSpeed(void *a0, float f12);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern unsigned int D_00747A24;
extern char D_005864F0[];
__attribute__((section(".text.func_00120BC0")))
void func_00120BC0(pl00 *self)
{
    cEm00 *s0;
    float buf[4];
    self->base.hitFlash = 5.0f;
    s0 = self->unk694;
    self->base.objFlags = self->base.objFlags | 0x10000;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0:
    {
        float z;
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        if (s0 != 0)
            func_0012C0F8(self, (int)(s0->unk76C * 30.0f));
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        buf[1] = 0.0f;
        buf[0] = 0.0273f;
        buf[2] = 1.369f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(self, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x22, z, z);
        if (self->base.hp <= 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD6, self, 0, 0, 0, 0);
            func_0012C348(self, 2);
        } else {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
            func_0012C348(self, 2);
        }
        self->unk15B0 = 1;
        self->base.unk56E = 0xF;
        (self->base.step)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp <= 0) {
                D_00747A24 |= 8;
            } else {
                pl00_clearMotionCam(self, 0, 0);
                self->base.mode = 1;
                self->base.phase = 4;
                self->base.step = 0;
                self->base.stepArg = 0;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}
