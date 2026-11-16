/* sn-2.95.3-136 matched TU. */

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

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"



















__attribute__((section(".text.func_00117600")))
void func_00117600(pl00 *self)
{
    cEm00 *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;
    float d0;
    float d1;

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->flags15F4 = self->flags15F4 | 0x80000;

    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        d0 = 1.0f / s2->scale.x;
        d1 = 1.0f / s2->scale.z;
        buf[0] = d0 * -0.5842f;
        buf[1] = 0.0f;
        buf[2] = d1 * 0.1376f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(self, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x38, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        if (self->base.hp <= 0)
            self->base.hp = 1;
        self->base.unk56E = 0x1E;
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (self->base.unk56E != 0 && s2 != 0) {
            cVec *d;
            cVec *e = &s2->vel;
            self->base.unk56E = self->base.unk56E - 1;
            d = self->base.pos;
            VU0_VADD_XYZ_IP(d, 0, e);
        }
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
}
