/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/gameWork.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern void func_00124EC0(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_002DB7A8(void);
extern float SetMotionStep(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern char D_005864F0[];
extern int D_00747A24;

/* sn-2.95.3-136 matched TU. */


























__attribute__((section(".text.func_001162C0")))
void func_001162C0(pl00 *self) {
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    self->flags15F4 = self->flags15F4 | 0x200;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    switch (self->base.step) {
    case 0: {
        char *b;

        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        b = self->base.pack;
        func_002A8578(self, EM_RES_REC(b, 0x8E0), EM_RES_REC(b, 0x8E4),
                      0, 0.0f, 0, 0);
        moveMotion(self);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xF5, self, 0, 0, 0, 0);
        self->base.step = self->base.step + 1;
    }
        /* fallthrough */
    case 1: {
        float r = Turn_dest(&self->base.unk580, self->base.rot.y,
                            self->base.speedRate * 0.39269909f,
                            self->base.pos);

        self->base.rot.y = self->base.rot.y + r;
        self->base.rot.y = Adjust_theta(self->base.rot.y);
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->base.step = self->base.step + 1;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        self->base.nullSpeed.z = -0.1f;
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    case 2: {
        char *b = self->base.pack;

        func_002A8578(self, EM_RES_REC(b, 0x8E8), EM_RES_REC(b, 0x8EC),
                      0, 0.0f, 0, 0);
        self->base.unk568 = 10;
        self->unk15C0 = 30.0f;
        self->base.step = self->base.step + 1;
        self->unk15B0 = 0;
        self->unk15B4 = 0;
        self->unk15B8 = 0;
    }
        /* fallthrough */
    case 3: {
        float rate;
        float mag;
        float mag2;
        float r;
        int lim;

        func_002DB7A8();
        if (self->unk15B8 != 0) {
            self->unk15B8 = self->unk15B8 - 1;
        }
        self->unk15B0 = self->unk15B0 + 1;
        if ((D_007474A0.padBtn & 0xF0) != 0) {
            switch (self->unk15B4) {
            default:
            case 0: lim = 9; break;
            case 1: lim = 8; break;
            case 2: lim = 7; break;
            case 3: lim = 6; break;
            case 4: lim = 5; break;
            case 5: lim = 4; break;
            case 6: lim = 3; break;
            case 7: lim = 2; break;
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
            if (self->unk15B4 >= 8) {
                self->unk15B4 = 7;
            }
            self->unk15B0 = 0;
            self->unk15B8 = 10;
        } else if (self->unk15B8 <= 0) {
            self->unk15B8 = 5;
            self->unk15B4 = self->unk15B4 - 1;
            if (self->unk15B4 < 0) {
                self->unk15B4 = 0;
            }
        }
        switch (self->unk15B4) {
        default:
        case 0: self->base.speedRate = 1.0f; break;
        case 1: self->base.speedRate = 1.2f; break;
        case 2: self->base.speedRate = 1.4f; break;
        case 3: self->base.speedRate = 1.6f; break;
        case 4: self->base.speedRate = 1.8f; break;
        case 5: self->base.speedRate = 2.0f; break;
        case 6: self->base.speedRate = 2.2f; break;
        case 7: self->base.speedRate = 2.5f; break;
        }
        SetMotionStep(self, self->base.speedRate);
        rate = (self->base.speedRate - 1.5f) * 0.1f;
        mag = capVu0MagnitudeSqXZ(self->base.pos, &self->base.unk580);
        if (mag < 0.09f) {
            if (rate < 0.0f) {
                rate = 0.0f;
            }
        }
        r = Turn_dest(&self->base.unk580, self->base.rot.y,
                      self->base.speedRate * 0.39269909f,
                      self->base.pos);
        self->base.rot.y = self->base.rot.y + r;
        self->base.rot.y = Adjust_theta(self->base.rot.y);
        func_00124EC0(self);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        self->base.nullSpeed.z = rate;
        cObjBase_addNullSpeed(self, 1.0f);
        if (0.0f < self->unk15C0) {
            self->unk15C0 =
                self->unk15C0 - self->base.speedRate;
        }
        mag2 = capVu0MagnitudeSqXZ(self->base.pos, &self->base.unk580);
        if (mag2 < 0.25f) {
            if (self->unk15C0 <= 0.0f) {
                self->base.step = 4;
                break;
            }
        }
        if (self->base.unk590.z * self->base.unk590.z < mag2) {
            self->base.step = 6;
            break;
        }
        self->base.unk568--;
        if (self->base.unk568 <= 0) {
            self->base.unk568 = 10;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xF6, self, 0, 0, 0, 0);
        }
        break;
    }
    case 4: {
        char *b = self->base.pack;

        func_002A8578(self, EM_RES_REC(b, 0x8F8), EM_RES_REC(b, 0x8FC),
                      0, 0.0f, 0, 0);
        cSnd_DieDemoStart(&D_005FEE00);
        func_0012C348(self, 2);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xF7, self, 0, 0, 0, 0);
        self->base.step = self->base.step + 1;
    }
        /* fallthrough */
    case 5:
        self->base.motionFlags = self->base.motionFlags | 8;
        if (moveMotion(self) != 0) {
            self->base.hp = 0;
            D_00747A24 = D_00747A24 | 8;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 6: {
        char *b = self->base.pack;

        func_002A8578(self, EM_RES_REC(b, 0x8F0), EM_RES_REC(b, 0x8F4),
                      0, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    }
        /* fallthrough */
    case 7:
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
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
