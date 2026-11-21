/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/gameWork.h"
#include "godhand/vu0.h"
#include "godhand/cObjBase.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"

extern unsigned char D_005864F0[];

extern void cEmManage_SetPlCatched(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern unsigned int irand(void);
extern void func_002DB7A8(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f12);
extern void cObjBase_addNullSpeed(void *a0, float f12);
extern void func_0012C348(void *a0, int a1);
extern void func_0012C0F8(void *a0, int a1);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern float SetMotionStep(void *a0, float f12);
extern void func_00124EC0(void *a0);
extern float fRand1_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void func_0010A438(void *a0);

__attribute__((section(".text.func_0011FD10")))
void func_0011FD10(pl00 *self)
{
    float buf[4];
    cEm00 *s1;
    int f1;
    int f2;
    int lim;

    self->unk648 = 0x1E;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s1 = self->unk694;
    self->held = (cGameObj *)s1;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0: {
        float v;

        pl00_clearMotionCam(self, 0, 0);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.100000001f;
        buf[2] = 1.0f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 0, v);
        switch (irand() % 3) {
        default:
        case 0: {
            char *p = self->base.pack;
            f1 = EM_RES_REC(p, 0x140);
            f2 = EM_RES_REC(p, 0x144);
            break;
        }
        case 1: {
            char *p = self->base.pack;
            f1 = EM_RES_REC(p, 0x4DC);
            f2 = EM_RES_REC(p, 0x4E0);
            break;
        }
        case 2: {
            char *p = self->base.pack;
            f1 = EM_RES_REC(p, 0x4E4);
            f2 = EM_RES_REC(p, 0x4E8);
            break;
        }
        }
        func_002A8578(self, f1, f2, 0, 0.0f, 0, 0);
        self->base.unk56A = 5;
        self->base.unk56E = 0xF;
        self->base.unk56C = 0;
        self->base.step = self->base.step + 1;
    }
    case 1:
        if (self->base.unk56E != 0 && s1 != 0) {
            cVec *p;
            cVec *q;
            p = self->base.pos;
            self->base.unk56E--;
            q = &s1->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        self->base.hitFlash = 5.0f;
        func_002DB7A8();
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (s1 != 0) {
            if ((s1->seqFlags & 3) != 0) {
                switch (irand() % 3) {
                default:
                case 0: {
                    char *p = self->base.pack;
                    f1 = EM_RES_REC(p, 0x140);
                    f2 = EM_RES_REC(p, 0x144);
                    break;
                }
                case 1: {
                    char *p = self->base.pack;
                    f1 = EM_RES_REC(p, 0x4DC);
                    f2 = EM_RES_REC(p, 0x4E0);
                    break;
                }
                case 2: {
                    char *p = self->base.pack;
                    f1 = EM_RES_REC(p, 0x4E4);
                    f2 = EM_RES_REC(p, 0x4E8);
                    break;
                }
                }
                func_002A8578(self, f1, f2, 0, 0.0f, 0, 0);
                moveMotion(self);
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
            }
            func_0012C348(self, 0);
            {
                cOmBase *e = cOmBase_childAt((cOmBase *)&self->base, (int *)buf, 4);
                if (e != 0) {
                    SetEffectPos(0x58, 0x10, 0, e->pos, -1, 1.0f);
                }
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, self, 0, 0, 0, 0);
        }
        if ((self->base.seqFlags & 1) != 0 && self->stepCount != 0) {
            self->stepCount = 0;
            func_0012C348(self, 2);
        } else {
            self->stepCount = 1;
        }
        self->base.unk56A--;
        if (self->base.unk56A > 0) {
            break;
        }
        self->base.unk56A = 0xA;
        if (s1 == 0) {
            break;
        }
        func_0012C0F8(self, (int)(s1->unk76C * 12.0f));
        break;
    case 2: {
        float v;

        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.100000001f;
        buf[2] = 1.0f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 0, v);
        if (self->base.stepArg != 0) {
            cEm00_GetPlMotion(s1, 0x26, v, v);
        } else {
            cEm00_GetPlMotion(s1, 0x27, v, v);
        }
        self->unk15B0 = 0;
        self->unk15B8 = 0;
        self->stepCount = 4;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0xA, 0, 0x2C, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x64, 0, 0x1D, 0, 0xA);
        self->base.step = self->base.step + 1;
    }
    case 3:
        self->base.hitFlash = 5.0f;
        func_002DB7A8();
        if (self->held != 0) {
            self->unk648 = 0x1E;
        }
        InvokeVirtualAtField214AndForward_124E68(self, 0.392699093f);
        if (self->unk15B8 != 0) {
            self->unk15B8 = self->unk15B8 - 1;
        }
        self->unk15B0 = self->unk15B0 + 1;
        if ((D_007474A0.padBtn & 0xF0) != 0) {
            switch (self->stepCount) {
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
                self->stepCount = self->stepCount + 1;
            }
            if (lim < self->unk15B0) {
                self->stepCount = self->stepCount - 1;
            }
            if (self->stepCount < 0) {
                self->stepCount = 0;
            }
            if (self->stepCount >= 8) {
                self->stepCount = 7;
            }
            self->unk15B0 = 0;
            self->unk15B8 = 0xA;
        } else {
            if (self->unk15B8 <= 0) {
                self->unk15B8 = 5;
                self->stepCount = self->stepCount - 1;
                if (self->stepCount < 0) {
                    self->stepCount = 0;
                }
            }
        }
        switch (self->stepCount) {
        default:
        case 0: self->base.speedRate = 1.0f; break;
        case 1: self->base.speedRate = 1.25f; break;
        case 2: self->base.speedRate = 1.5f; break;
        case 3: self->base.speedRate = 1.75f; break;
        case 4: self->base.speedRate = 2.0f; break;
        case 5: self->base.speedRate = 2.25f; break;
        case 6: self->base.speedRate = 2.5f; break;
        case 7: self->base.speedRate = 3.0f; break;
        }
        SetMotionStep(self, self->base.speedRate);
        func_00124EC0(self);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 3) == 0) {
            break;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x123, self, 0, 0, 0, 0);
        VU0_SQC2_VF0(buf, 0x0);
        buf[0] = fRand1_1() * 0.200000003f;
        buf[1] = fRand1_1() * 0.200000003f + 1.29999995f;
        buf[2] = fRand1_1() * 0.200000003f + 0.600000024f;
        sceVu0ApplyMatrix(buf, &self->base.mtx, buf);
        SetEffectPos(0, 0x40, 0, (cVec *)buf, -1, 1.0f);
        break;
    case 4: {
        buf[1] = 0.0f;
        buf[0] = -0.100000001f;
        buf[2] = 1.5f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 0, buf[1]);
        { int g1; int g2;
        if (self->base.stepArg != 0) {
            char *pa = self->base.pack;
            g1 = EM_RES_REC(pa, 0x6AC);
            g2 = EM_RES_REC(pa, 0x6B0);
        } else {
            char *pb = self->base.pack;
            g1 = EM_RES_REC(pb, 0x810);
            g2 = EM_RES_REC(pb, 0x814);
        }
        func_002A8578(self, g1, g2, 3, 0.0f, 0, 0); }
        self->base.unk56E = 0xF;
        self->base.hitFlash = 2.0f;
        self->base.step = self->base.step + 1;
    }
    case 5:
        if (self->base.unk56E != 0 && s1 != 0) {
            cVec *q = &s1->vel;
            cVec *p;
            self->base.unk56E--;
            p = self->base.pos;
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        if (self->base.unk56C != 0) {
            self->base.hitFlash = 5.0f;
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
    }
    func_0010A438(self);
}
