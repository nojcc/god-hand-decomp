/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern float Adjust_theta(float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_002DB7A8(void);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void SetMotionStep(void *a0, float f12);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/gameWork.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"























__attribute__((section(".text.func_00119BF0")))
void func_00119BF0(pl00 *self)
{
    cEm00 *s2;
    float buf[4] __attribute__((aligned(16)));

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
        self->comboSlot = 0;
        self->comboSet = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        if (s2 != 0) {
            VU0_SQC2_VF0(buf, 0);
            buf[0] = -0.01001f;
            buf[2] = 0.86998f;
            buf[1] = 0.0f;
            sceVu0ApplyMatrix(buf, &s2->mtx, buf);
            self->base.pos->x = buf[0];
            self->base.pos->z = buf[2];
            self->base.rot.y = s2->rot.y + 3.14159274f;
            self->base.rot.y = Adjust_theta(self->base.rot.y);
        }
        cEm00_GetPlMotion(s2, 0x4F, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        self->base.unk56A = 1;
        self->base.step = self->base.step + 1;
    /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self))
            self->base.step = self->base.step + 1;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        cEm00_GetPlMotion(s2, 0x50, 0.0f, 0.0f);
        self->base.unk568 = 0x5A;
        self->unk15B0 = 0;
        self->base.step = self->base.step + 1;
        self->stepCount = 0;
        self->unk15B8 = 0;
    /* fallthrough */
    case 3:
        func_002DB7A8();
        if (self->base.unk568 != 0)
            self->base.unk568--;
        if (self->unk15B8 != 0)
            self->unk15B8 = self->unk15B8 - 1;
        self->unk15B0 = self->unk15B0 + 1;
        if ((D_007474A0.padBtn & 0xF0) != 0) {
            int lim;
            switch (self->stepCount) {
            default:
            case 0:
                lim = 0x3E7;
                break;
            case 1:
                lim = 6;
                break;
            case 2:
                lim = 5;
                break;
            case 3:
                lim = 4;
                break;
            case 4:
                lim = 3;
                break;
            case 5:
                lim = 2;
                break;
            }
            if (self->unk15B0 < lim)
                self->stepCount = self->stepCount + 1;
            if (lim < self->unk15B0)
                self->stepCount = self->stepCount - 1;
            if (self->stepCount < 0)
                self->stepCount = 0;
            if (self->stepCount >= 5)
                self->stepCount = 4;
            self->unk15B0 = 0;
            self->unk15B8 = 0xA;
        } else if (self->unk15B8 <= 0) {
            int t;
            self->unk15B8 = 5;
            t = self->stepCount - 1;
            self->stepCount = t;
            if (t < 0)
                self->stepCount = 0;
        }
        switch (self->stepCount) {
        default:
        case 0:
            self->base.speedRate = 0.7f;
            break;
        case 1:
            self->base.speedRate = 1.0f;
            break;
        case 2:
            self->base.speedRate = 1.5f;
            break;
        case 3:
            self->base.speedRate = 2.0f;
            break;
        case 4:
            self->base.speedRate = 2.5f;
            break;
        }
        SetMotionStep(self, self->base.speedRate);
        func_00124EC0(self);
        if (moveMotion(self) && self->base.unk568 <= 0)
            self->base.step = 4;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 4:
        cEm00_GetPlMotion(s2, 0x51, 0.0f, 0.0f);
        self->base.unk56E = 0xF;
        self->base.step = self->base.step + 1;
    /* fallthrough */
    case 5:
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
