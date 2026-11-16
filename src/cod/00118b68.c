/* sn-2.95.3-136 matched TU. */

/* func_00118B68, 1588 B, sn-2.95.3-136. Wave 2026-09-01 JB best + nested Duff do{}while(0) before case 4 and case 6 (0-mod-8 jtbl labels), per-site p/q locals, do{}while(0) on site-2 q, cross-block f15 for the 0xF stores. */
/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
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

__attribute__((section(".text.func_00118B68")))
void func_00118B68(pl00 *self)
{
    cEm00 *s2;
    float buf[4] __attribute__((aligned(16)));
    short f15;
    cVec *p1;
    cVec *q1;
    cVec *p2;
    cVec *q2;

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->flags15F4 = self->flags15F4 | 0x80000;
    switch (self->base.step) {
    case 0: {
        float v;
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = 0.005f;
        buf[2] = 1.5413f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x45, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        self->base.unk56A = 1;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 1:
        func_002DB7A8();
        if (s2 != 0) {
            cVec *q = &s2->vel;
            cVec *p = self->base.pos;
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
        buf[0] = -0.051f;
        buf[2] = 0.1946f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x46, v, v);
        self->base.unk568 = 0x5A;
        self->unk15B0 = 0;
        self->base.step = self->base.step + 1;
        self->unk15B4 = 0;
        self->unk15B8 = 0;
    }
    /* fallthrough */
    case 3:
        func_002DB7A8();
        if (s2 != 0) {
            cVec *q;
            cVec *p;
             p = self->base.pos;
            q = &s2->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (self->base.unk568 != 0)
            self->base.unk568--;
        if (self->unk15B8 != 0)
            self->unk15B8 = self->unk15B8 - 1;
        self->unk15B0 = self->unk15B0 + 1;
        if ((D_007474A0.padBtn & 0xF0) != 0) {
            int lim;
            switch (self->unk15B4) {
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
                self->unk15B4 = self->unk15B4 + 1;
            if (lim < self->unk15B0)
                self->unk15B4 = self->unk15B4 - 1;
            if (self->unk15B4 < 0)
                self->unk15B4 = 0;
            if (self->unk15B4 >= 5)
                self->unk15B4 = 4;
            self->unk15B0 = 0;
            self->unk15B8 = 0xA;
        } else if (self->unk15B8 <= 0) {
            int t;
            self->unk15B8 = 5;
            t = self->unk15B4 - 1;
            self->unk15B4 = t;
            if (t < 0)
                self->unk15B4 = 0;
        }
        switch (self->unk15B4) {
        default:
        case 0:
            self->base.speedRate = 0.7f;
            break;
        case 1:
            self->base.speedRate = 1.0f;
            break;
        case 2:
            self->base.speedRate = 1.3f;
            break;
        case 3:
            self->base.speedRate = 1.6f;
            break;
        case 4:
            self->base.speedRate = 2.0f;
            break;
        }
        SetMotionStep(self, self->base.speedRate);
        func_00124EC0(self);
        if (moveMotion(self) && self->base.unk568 <= 0) {
            self->base.step = 4;
            if (s2 != 0 && s2->hp < 0x1F)
                self->base.step = 6;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    
    
    case 4: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.051f;
        buf[2] = 0.2174f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x47, v, v);
        f15 = 0xF;
        self->base.unk56E = f15;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 5:
        if (self->base.unk56E == 0 || s2 == 0)
            goto join1;
        (self->base.unk56E)--;
        p1 = self->base.pos;
    
        q1 = &self->base.vel;
        VU0_VADD_XYZ_IP(p1, 0, q1);
    join1:
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
    
    
    case 6: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.051f;
        buf[2] = 0.2174f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x48, v, v);
        f15 = 0xF;
        self->base.unk56E = f15;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 7:
        if (self->base.unk56E == 0 || s2 == 0)
            goto join2;
        (self->base.unk56E)--;
        p2 = self->base.pos;
    
        q2 = &self->base.vel;
        VU0_VADD_XYZ_IP(p2, 0, q2);
    join2:
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
}
