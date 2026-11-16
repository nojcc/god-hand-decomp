/* sn-2.95.3-136 matched TU. */

extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_002DB7A8(void);
extern void func_00124EC0(void *a0);
extern float SetMotionStep(void *a0, float f);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f12);
extern void cObjBase_addNullSpeed(void *a0, float f12);

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cObjBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/effectPos.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/gameWork.h"
#include "godhand/motion.h"























__attribute__((section(".text.func_001179C8")))
void func_001179C8(pl00 *self)
{
    float buf[4];
    cEm00 *s2;

    self->base.hitFlash = 5.0f;
    self->base.objFlags |= 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->flags15F4 |= 0x80000;
    switch (self->base.step) {
    case 0:
    {
        float v;

        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.181799993f;
        buf[2] = 1.17859995f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x3A, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        self->base.unk56A = 1;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_002DB7A8();
        if (s2 != 0) {
            cVec *p;
            cVec *q;

            q = &s2->vel;
            p = self->base.pos;
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            (self->base.step)++;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
    {
        float v;

        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.233600006f;
        buf[2] = 1.21519995f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x3B, v, v);
        self->base.unk568 = 0x5A;
        (self->base.step)++;
        self->unk15B0 = 0;
        self->unk15B4 = 0;
        self->unk15B8 = 0;
    }
        /* fallthrough */
    case 3:
        func_002DB7A8();
        if (s2 != 0) {
            cVec *p;
            cVec *q;

            q = &s2->vel;
            p = self->base.pos;
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        if (self->base.unk568 != 0) {
            self->base.unk568 = self->base.unk568 - 1;
        }
        if (self->unk15B8 != 0) {
            self->unk15B8 = self->unk15B8 - 1;
        }
        self->unk15B0 = self->unk15B0 + 1;
        if ((D_007474A0.padBtn & 0xF0) != 0) {
            int lim;

            switch (self->unk15B4) {
            case 0: default: lim = 0x3E7; break;
            case 1: lim = 6; break;
            case 2: lim = 5; break;
            case 3: lim = 4; break;
            case 4: lim = 3; break;
            case 5: lim = 2; break;
            }
            if (self->unk15B0 < lim) {
                self->unk15B4 = self->unk15B4 + 1;
            }
            if (lim < self->unk15B0) {
                self->unk15B4 = self->unk15B4 - 1;
            }
            if (self->unk15B4 < 0) {
                self->unk15B4 = 0;
            }
            if (self->unk15B4 >= 5) {
                self->unk15B4 = 4;
            }
            self->unk15B0 = 0;
            self->unk15B8 = 0xA;
        } else {
            if (self->unk15B8 <= 0) {
                self->unk15B8 = 5;
                self->unk15B4 = self->unk15B4 - 1;
                if (self->unk15B4 < 0) {
                    self->unk15B4 = 0;
                }
            }
        }
        switch (self->unk15B4) {
        case 0: default: self->base.speedRate = 0.699999988f; break;
        case 1: self->base.speedRate = 1.0f; break;
        case 2: self->base.speedRate = 1.29999995f; break;
        case 3: self->base.speedRate = 1.60000002f; break;
        case 4: self->base.speedRate = 2.0f; break;
        }
        SetMotionStep(self, self->base.speedRate);
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.unk568 <= 0) {
                (self->base.step)++;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 4:
    {
        float v;

        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.254200011f;
        buf[2] = 1.16869998f;
        buf[3] = 1.0f;
        func_001299F0(self, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x3C, v, v);
        self->base.unk56E = 0xF;
        (self->base.step)++;
    }
        /* fallthrough */
    case 5:
        if (self->base.unk56E != 0) {
            if (s2 != 0) {
                cVec *p;
                cVec *q;

                self->base.unk56E = self->base.unk56E - 1;
                p = self->base.pos;
                 
                q = &self->base.vel;
                VU0_VADD_XYZ_IP(p, 0x0, q);
            }
        }
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
        break;
    default:
        break;
    }
    if ((self->base.seqFlags & 1) != 0) {
        if (self->base.unk56A != 0) {
            cOmBase *e = cOmBase_childAt((cOmBase *)&self->base, (int *)buf, 0x17);

            if (e != 0) {
                SetEffectPos(0, 0x4F, 0, e->pos, -1, 1.0f);
            }
            self->base.unk56A = 0;
        } else {
            self->base.unk56A = 1;
        }
    } else {
        self->base.unk56A = 1;
    }
}
