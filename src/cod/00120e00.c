/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern int D_00747A24;
extern void cEmManage_SetPlCatched(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
























__attribute__((section(".text.func_00120E00")))
void func_00120E00(pl00 *self)
{
    cEm00 *s1;
    float buf[4] __attribute__((aligned(16)));

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s1 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    switch (self->base.step) {
    case 0: {
        float v;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, self, 0, 0, 0, 0);
        if (s1 != 0)
            func_0012C0F8(self, (int)(s1->unk76C * 30.0f));
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.07f;
        buf[2] = 1.0074f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 0, v);
        cEm00_GetPlMotion(s1, 0x28, v, v);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        self->unk15B0 = 0x1E;
        self->base.unk56E = 0xF;
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
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.07f;
        buf[2] = 0.4842f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x29, v, v);
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 3:
        func_00124EC0(self);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) && self->unk15B4 != 0) {
            self->unk15B4 = 0;
            if (s1 != 0)
                func_0012C0F8(self, (int)(s1->unk76C * 30.0f));
        } else {
            self->unk15B4 = 1;
        }
        break;
    case 4: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.066f;
        buf[2] = 0.488f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x2B, v, v);
        self->unk15B0 = 0x28;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 5:
        func_00124EC0(self);
        if (self->unk15B0 != 0) {
            int t = self->unk15B0 - 1;
            self->unk15B0 = t;
            if (t <= 0) {
                self->base.hp = 0;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                self->base.motionFlags = self->base.motionFlags | 8;
                func_0012C348(self, 2);
                D_00747A24 |= 8;
            }
        }
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 6: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.066f;
        buf[2] = 0.488f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x2A, v, v);
        self->base.step = self->base.step + 1;
    }
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
        if (func_00123938(self, 1)) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    default:
        break;
    }
}
