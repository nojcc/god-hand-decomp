/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern unsigned char D_005864F0[];
extern int D_00747A24;

/* sn-2.95.3-136 candidate. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
























__attribute__((section(".text.func_0011BF20")))
void func_0011BF20(pl00 *self)
{
    cEm00 *s0;
    cCoreSave *s2;
    cVec *q;
    float v[4];
    float z;

    self->base.objFlags |= 0x10000;
    self->base.hitFlash = 5.0f;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, self, 0, 0, 0, 0);
        v[1] = 0.0f;
        v[0] = -0.0437f;
        v[2] = 1.227f;
        v[3] = 1.0f;
        z = v[1];
        func_001299F0(self, s0, v, 0, z);
        cEm00_GetPlMotion(s0, 3, z, z);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->unk15B0 = 0x1E;
        self->base.step = self->base.step + 1;
        self->base.unk56E = 0xF;
    case 1:
        if (self->base.unk56E != 0) {
            if (s0 != 0) {
                cVec *pv = &s0->vel;
                self->base.unk56E = self->base.unk56E - 1;
                q = self->base.pos;
                VU0_VADD_XYZ_IP(q, 0x0, pv);
            }
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->base.step = self->base.step + 1;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        cEm00_GetPlMotion(s0, 4, 3.0f, 0.0f);
        self->unk15B0 = 5;
        self->base.step = self->base.step + 1;
    case 3:
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
        if (self->unk15B0 == 0) {
            break;
        }
        self->unk15B0 = self->unk15B0 - 1;
        if (self->unk15B0 != 0) {
            break;
        }
        s2 = &D_00569B70;
        cCoreSave_addGameLevelPoint(s2, -0x140);
        if (s0 != 0) {
            func_0012C0F8(self, (int)(s0->unk76C * 50.0f));
        }
        if (self->base.hp <= 0) {
            cSnd *snd = &D_005FEE00;
            self->base.hp = 0;
            cSnd_SeCall_2CBA48(snd, 0, 0xD6, self, 0, 0, 0, 0);
            cSnd_DieDemoStart(snd);
            cCoreSave_addGameLevelPoint(s2, -0x3E8);
            self->base.motionFlags = self->base.motionFlags | 8;
        } else {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
        }
        func_0012C348(self, 2);
        break;
    case 4:
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        cEm00_GetPlMotion(s0, 5, 3.0f, 0.0f);
        self->base.step = self->base.step + 1;
    case 5:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (func_00123938(self, 1) != 0 || (self->base.seqFlags & 0x20) != 0) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
}
