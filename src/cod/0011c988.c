/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern int cHeatSys_SubHeatGage(void *a0, int a1, float f12);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_005864F0[];
extern char D_005CB000[];

/* sn-2.95.3-136 matched TU. */






















#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_0011C988")))
void func_0011C988(pl00 *self)
{
    cEm00 *s2;
    float v[4] __attribute__((aligned(16)));

    self->base.hitFlash = 5.0f;
    self->base.objFlags |= 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0: {
        float z;
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0822f;
        v[2] = 0.0009f;
        v[3] = 1.0f;
        func_001299F0(self, s2, v, 0, z);
        cEm00_GetPlMotion(s2, 0xB, z, z);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            self->unk15C0 = 0.1f;
        case 2:
            self->unk15C0 = 0.2f;
        case 3:
            self->unk15C0 = 0.5f;
        case 4:
            self->unk15C0 = 0.5f;
        case 5:
            self->unk15C0 = 1.0f;
        }
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        self->unk15B0 = 0xA;
        self->base.unk56E = 0xF;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 1: {
        cVec *q = &s2->vel;
        cVec *p = self->base.pos;
        VU0_VADD_XYZ_IP(p, 0, q);
        func_00124EC0(self);
        if (moveMotion(self))
            self->base.step = self->base.step + 1;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    case 2: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0822f;
        v[2] = 0.0009f;
        v[3] = 1.0f;
        func_001299F0(self, s2, v, 0, z);
        cEm00_GetPlMotion(s2, 0xC, z, z);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            self->unk15C0 = 0.1f;
        case 2:
            self->unk15C0 = 0.2f;
        case 3:
            self->unk15C0 = 0.5f;
        case 4:
            self->unk15C0 = 0.5f;
        case 5:
            self->unk15C0 = 1.0f;
        }
        self->unk15B0 = 0xA;
        self->base.unk56E = 0xF;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 3:
        if (self->base.unk56E != 0 && s2 != 0) {
            cVec *p;
            cVec *q;
            self->base.unk56E = self->base.unk56E - 1;
            p = self->base.pos;
             
            q = &s2->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(self);
        moveMotion(self);
        cHeatSys_SubHeatGage(D_005CB000, 0, self->unk15C0);
        if (self->unk15B0 != 0) {
            self->unk15B0 = self->unk15B0 - 1;
        } else {
            self->unk15B0 = 0xA;
            if (s2 != 0) {
                float t = s2->unk76C;
                func_0012C0F8(self, (int)(t + t));
            }
            if (self->base.hp <= 0)
                self->base.hp = 1;
        }
        func_0012C348(self, 4);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 4: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = 0.1133f;
        v[2] = 0.7251f;
        v[3] = 1.0f;
        func_001299F0(self, s2, v, 1, z);
        cEm00_GetPlMotion(s2, 0xD, 3.0f, z);
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 5:
        func_00124EC0(self);
        self->base.motionFlags = self->base.motionFlags | 8;
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
    case 6: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.1007f;
        v[2] = 0.3456f;
        v[3] = 1.0f;
        func_001299F0(self, s2, v, 1, z);
        cEm00_GetPlMotion(s2, 0xE, 3.0f, z);
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
        break;
    default:
        break;
    }
}
