/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"

extern unsigned char D_005864F0[];
extern int D_00747A24;
extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */






















__attribute__((section(".text.func_001205D8")))
void func_001205D8(pl00 *self)
{
    cEm00 *s0;
    float buf[4] __attribute__((aligned(16)));
    float v;

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);

    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[0] = -0.1346f;
        buf[1] = 0.0f;
        buf[2] = 0.7623f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(self, s0, buf, 0, v);
        cEm00_GetPlMotion(s0, 0x23, v, v);
        self->base.unk56E = 0x3C;
        self->unk15B0 = 1;
        self->unk15B4 = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->base.step = 4;
            if (self->base.hp <= 0) {
                self->base.hp = 1;
            }
            pl00_clearMotionCam(self, 0, 0);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) != 0 && self->unk15B4 != 0) {
            self->unk15B4 = 0;
            if (s0 != 0) {
                func_0012C0F8(self, (int)(s0->unk76C * 5.0f));
            }
            func_0012C348(self, 2);
        } else {
            self->unk15B4 = 1;
        }
        if ((self->base.seqFlags & 2) != 0 && self->unk15B0 != 0) {
            self->unk15B0 = 0;
            if (s0 != 0) {
                func_0012C0F8(self, (int)(s0->unk76C * 10.0f));
            }
            if (self->base.hp <= 0) {
                self->base.hp = 1;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                self->base.motionFlags = self->base.motionFlags | 8;
            }
            func_0012C348(self, 2);
        }
        if ((self->base.seqFlags & 0x200) != 0 && self->base.hp < 0xB) {
            self->base.step = 2;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s0, 0x25, 0.0f, 0.0f);
        self->base.hp = 0;
        func_0012C348(self, 2);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 3:
        self->base.motionFlags = self->base.motionFlags | 8;
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            D_00747A24 = D_00747A24 | 8;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 4:
        pl00_clearMotionCam(self, 1, 0);
        cEm00_GetPlMotion(s0, 0x24, 0.0f, 0.0f);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 5:
        if (moveMotion(self) != 0) {
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
