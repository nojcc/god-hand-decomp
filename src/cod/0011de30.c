/* sn-2.95.3-136 matched TU. */

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
extern void func_0012C348(void *a0, int a1);
extern unsigned int D_00747A24;
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */






















#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"

__attribute__((section(".text.func_0011DE30")))
void func_0011DE30(pl00 *self)
{
    cEm00 *s1;

    self->base.hitFlash = 5.0f;
    s1 = self->unk694;
    self->base.objFlags = self->base.objFlags | 0x10000;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[0] = 0.1473f;
        buf[1] = 0.0f;
        buf[2] = 1.406f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(self, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x15, z, z);
        self->unk15B0 = 1;
        self->stepCount = 0;
        self->base.unk56E = 0x3C;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        if (self->base.unk56E != 0 && s1 != 0) {
            cVec *p;
            cVec *q;

            self->base.unk56E = self->base.unk56E - 1;
            p = self->base.pos;
             
            q = &s1->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp > 0) {
                pl00_clearMotionCam(self, 0, 0);
                self->base.mode = 1;
                self->base.phase = 4;
                self->base.step = 0;
                self->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->stepCount > 0)
            self->stepCount = self->stepCount - 1;
        if ((self->base.seqFlags & 1) != 0
            && self->stepCount <= 0) {
            self->stepCount = 5;
            if (s1 != 0) {
                func_0012C0F8(self, (int)(s1->unk76C * 10.0f));
                if (self->base.hp < 2)
                    self->base.hp = 1;
            }
            func_0012C348(self, 2);
        }
        if ((self->base.seqFlags & 2) != 0
            && self->unk15B0 != 0) {
            self->unk15B0 = 0;
            cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
            if (s1 != 0)
                func_0012C0F8(self, (int)(s1->unk76C * 20.0f));
            if (self->base.hp <= 0) {
                self->base.hp = 0;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                self->base.motionFlags = self->base.motionFlags | 8;
            }
            func_0012C348(self, 2);
        }
        break;
    case 2:
        cEm00_GetPlMotion(s1, 0x16, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        (self->base.step)++;
        /* fallthrough */
    case 3:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp <= 0)
                self->base.hp = 1;
            pl00_clearMotionCam(self, 1, 0);
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
