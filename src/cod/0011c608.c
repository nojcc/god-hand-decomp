/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_005864F0[];
extern int D_00747A24;

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"






















__attribute__((section(".text.func_0011C608")))
void func_0011C608(pl00 *self)
{
    cEm00 *s1;
    float v[4] __attribute__((aligned(16)));

    self->base.objFlags |= 0x10000;
    self->base.hitFlash = 5.0f;
    s1 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0746000037f;
        v[2] = 0.637199998f;
        v[3] = 1.0f;
        func_001299F0(self, s1, v, 0, z);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        cEm00_GetPlMotion(s1, 7, z, z);
        self->base.unk56E = 0xF;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 1:
        if (self->base.unk56E != 0 && s1 != 0) {
            cVec *q = &s1->vel;
            cVec *p;
            self->base.unk56E = self->base.unk56E - 1;
            p = self->base.pos;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(self);
        if (moveMotion(self))
            self->base.step = self->base.step + 1;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0746000037f;
        v[2] = 0.637199998f;
        v[3] = 1.0f;
        func_001299F0(self, s1, v, 0, z);
        cEm00_GetPlMotion(s1, 8, z, z);
        self->unk15B0 = 5;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 3:
        func_00124EC0(self);
        if (moveMotion(self))
            self->unk15B0 = 5;
        if (self->unk15B0 != 0) {
            int t = self->unk15B0 - 1;
            self->unk15B0 = t;
            if (t == 0) {
                if (s1 != 0)
                    func_0012C0F8(self, (int)(s1->unk76C * 10.0f));
                func_0012C348(self, 0);
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 4:
        cEm00_GetPlMotion(s1, 9, 3.0f, 0.0f);
        self->unk15B0 = 0x1E;
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
        self->base.step = self->base.step + 1;
    /* fallthrough */
    case 5:
        func_00124EC0(self);
        self->base.motionFlags = self->base.motionFlags | 8;
        if (moveMotion(self))
            D_00747A24 |= 8;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 6:
        cEm00_GetPlMotion(s1, 0xA, 3.0f, 0.0f);
        self->base.step = self->base.step + 1;
    /* fallthrough */
    case 7:
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
    default:
        break;
    }
}
