/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cSnd.h"
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_002DB770(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern char D_007474A0[];

__attribute__((section(".text.func_0011B5F8")))
void func_0011B5F8(pl00 *self)
{
    char *g;
    char *h;

    switch (self->base.step) {
    case 0: {
        int p1, p2;
        if (irand() & 1) {
            char *v0 = self->base.pack;
            p1 = *(int *)(v0 + 0x148) + (int)v0;
            p2 = *(int *)(v0 + 0x14C) + (int)v0;
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, self, 0, 0, 0, 0);
        } else {
            char *v1 = self->base.pack;
            p1 = *(int *)(v1 + 0x150) + (int)v1;
            p2 = *(int *)(v1 + 0x154) + (int)v1;
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD0, self, 0, 0, 0, 0);
        }
        pl00_clearMotionCam(self, 0, 0);
        func_002A8578(self, p1, p2, 1, 0.0f, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x8C, self, 0, 0, 0, 0);
        func_0012C348(self, 0);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->base.unk568 = 0xF;
        self->unk15B0 = 0x96;
        self->base.step += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_002DB770();
        g = D_007474A0;
        if (*(int *)(g + 8) & 0xF0) {
            self->unk15B0 -= 5;
        }
        if (*(int *)(g + 8) & 0xF00000) {
            self->unk15B0 -= 0x14;
        }
        if (moveMotion(self) != 0) {
            self->base.step = 2;
        }
        if (self->base.unk568 != 0) {
            self->base.unk568 = self->base.unk568 - 1;
        } else {
            self->base.step = 2;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    case 2: {
        char *v0 = self->base.pack;
        func_002A8578(self, *(int *)(v0 + 0x49C) + (int)v0, *(int *)(v0 + 0x4A0) + (int)v0, 0xA, 0.0f, 0, 0);
        self->base.step += 1;
    }
        /* fallthrough */
    case 3: {
        float one;
        int t;
        func_002DB770();
        moveMotion(self);
        t = self->unk15B0;
        h = D_007474A0;
        self->unk15B0 = t - 1;
        if (*(int *)(h + 8) & 0xF0) {
            self->unk15B0 = t - 6;
        }
        if (*(int *)(h + 8) & 0xF00000) {
            self->unk15B0 -= 0x14;
        }
        if (self->unk15B0 <= 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    }
}
