/* sn-2.95.3-136 matched TU. */

extern unsigned char D_007474A0[];
extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern float capVu0Atan2(float y, float x);
extern float Adjust_theta(float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cSnd.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0010A438(void *a0);

/* sn-2.95.3-136 matched TU. */





















#include "godhand/vu0.h"

__attribute__((section(".text.func_0011ADD8")))
void func_0011ADD8(pl00 *self)
{
    float buf[4] __attribute__((aligned(16)));
    int s3v, s2v;

    self->base.hitFlash = 15.0f;
    switch (self->base.step) {
    case 0: {
        cSnd *g;
        char *p;

        switch (self->base.stepArg) {
        case 0: default:
            switch (irand() % 5) {
            case 0: default: {
                char *v0 = self->base.pack;
                s3v = *(int *)(v0 + 0x158) + (int)v0;
                s2v = *(int *)(v0 + 0x15C) + (int)v0;
                break;
            }
            case 1: {
                char *v0 = self->base.pack;
                s3v = *(int *)(v0 + 0x4FC) + (int)v0;
                s2v = *(int *)(v0 + 0x500) + (int)v0;
                break;
            }
            case 2: {
                char *v0 = self->base.pack;
                s3v = *(int *)(v0 + 0x164) + (int)v0;
                s2v = *(int *)(v0 + 0x168) + (int)v0;
                break;
            }
            case 3: {
                char *v0 = self->base.pack;
                s3v = *(int *)(v0 + 0x504) + (int)v0;
                s2v = *(int *)(v0 + 0x508) + (int)v0;
                break;
            }
            case 4: {
                char *v0 = self->base.pack;
                s3v = *(int *)(v0 + 0x50C) + (int)v0;
                s2v = *(int *)(v0 + 0x510) + (int)v0;
                break;
            }
            }
            break;
        case 1: {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x158) + (int)v0;
            s2v = *(int *)(v0 + 0x15C) + (int)v0;
            break;
        }
        case 2: {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x4FC) + (int)v0;
            s2v = *(int *)(v0 + 0x500) + (int)v0;
            break;
        }
        case 3: {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x514) + (int)v0;
            s2v = *(int *)(v0 + 0x518) + (int)v0;
            break;
        }
        case 4: {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x164) + (int)v0;
            s2v = *(int *)(v0 + 0x168) + (int)v0;
            break;
        }
        case 5: {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x504) + (int)v0;
            s2v = *(int *)(v0 + 0x508) + (int)v0;
            break;
        }
        case 6: {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x50C) + (int)v0;
            s2v = *(int *)(v0 + 0x510) + (int)v0;
            break;
        }
        }
        g = &D_005FEE00;
        cSnd_SeCall_2CBA48(g, 0, 0xD7, self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(g, 0, 0x123, self, 0, 0, 0, 0);
        pl00_clearMotionCam(self, 0, 0);
        func_0012C348(self, 2);
        p = self->unk678;
        if (p != 0) {
            VU0_LQC2(4, p + 0x10, 0);
            VU0_SQC2(4, buf, 0);
            self->base.rot.y = capVu0Atan2(buf[0], buf[2]) + 3.1415927f;
            self->base.rot.y = Adjust_theta(self->base.rot.y);
        }
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        func_002A8578(self, s3v, s2v, 2, 0.0f, 0, 0);
        self->unk15B0 = 0;
        self->stepCount = 0;
        self->base.step += 1;
    }
        /* fallthrough */
    case 1: {
        char *g;

        if (self->stepCount != 0) {
            self->stepCount -= 1;
        }
        g = (char *)&D_007474A0;
        if ((*(int *)(g + 8) & 0xF0) != 0) {
            self->stepCount = 0xA;
        }
        if (moveMotion(self) != 0) {
            if (self->stepCount > 0) {
                self->base.phase = 4;
                self->base.mode = 1;
                self->base.step = 0;
                self->base.stepArg = 1;
            } else {
                self->base.mode = 1;
                self->base.phase = 4;
                self->base.step = 0;
                self->base.stepArg = 0;
            }
            break;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 0x20) != 0) {
            self->unk15B0 = 1;
            if (self->unk61E != 0 || (*(int *)(g + 8) & 0xF0) != 0) {
                self->base.stepArg = 1;
                self->base.hitFlash = 5.0f;
                self->base.phase = 6;
                self->base.step = 0;
                self->base.mode = 0;
            }
            break;
        }
        if (self->unk15B0 != 0) {
            self->unk15B0 = 0;
            func_0012C0F8(self, self->unk160C);
            if (self->base.hp <= 0) {
                self->base.hp = 1;
            }
            self->unk160C = 0;
        }
        break;
    }
    case 2: {
        if (self->stepCount != 0) {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x51C) + (int)v0;
            s2v = *(int *)(v0 + 0x520) + (int)v0;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0xA, 0x17, 0x2A, 0, 0xA);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0xA, 0x17, 0x2A, 0, 0xA);
            self->unk1684 = 0;
        } else {
            char *v0 = self->base.pack;
            s3v = *(int *)(v0 + 0x174) + (int)v0;
            s2v = *(int *)(v0 + 0x178) + (int)v0;
        }
        func_002A8578(self, s3v, s2v, 0xA, 0.0f, 0, 0);
        self->base.step += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (func_00123938(self, 1) == 0) {
            func_0010A438(self);
        }
        break;
    }
}
