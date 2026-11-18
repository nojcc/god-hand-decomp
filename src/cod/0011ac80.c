/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_00262750(void *a0, int a1);

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"







__attribute__((section(".text.func_00239570")))
void func_00239570(cEm00 *self)
{
    char *s1 = (char *)Getplayer();
    float one;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
    case 0:
    {
        int p;
        self->unk1864 = 0;
        p = EM_RES(self);
        func_002A8578(self, *(int *)(p + 0x3B38) + p, *(int *)(p + 0x3B3C) + p,
                      0, 0.0f, 0, 0);
        self->unk56E = 0xF;
        (self->step)++;
    }
    case 1:
        if (self->unk56E != 0) {
            char *q;
            int p0;
            (self->unk56E)--;
            q = s1 + 0x550;
            p0 = *(int *)((char *)self + 0xF0);
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        self->hitFlash = 3.0f;
        if (moveMotion(self) != 0) {
            self->mode = 0; self->phase = 0x6C;
            self->step = 0; self->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_0011AC80")))
void func_0011AC80(pl00 *self)
{
    float one;
    switch (self->base.step) {
    case 0: {
        char *v0 = self->base.pack;
        int p1 = *(int *)(v0 + 0x878) + (int)v0;
        int p2 = *(int *)(v0 + 0x87C) + (int)v0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, self, 0, 0, 0, 0);
        self->base.hitFlash = 10.0f;
        func_002A8578(self, p1, p2, 1, 0.0f, 0, 0);
        pl00_clearMotionCam(self, 0, 0);
        func_0012C348(self, 0);
        if (irand() & 1) {
            CallWithAndClearField698_12AC28(self);
            func_0012B928(self);
        }
        self->base.step += 1;
    }
    case 1:
        if (moveMotion(self) != 0) {
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
    func_00123938(self, 1);
}

__attribute__((section(".text.func_0023A950")))
void func_0023A950(cEm00 *self)
{
    float one;
    self->emFlags = self->emFlags | 0x400;
    switch (self->step) {
    case 0: {
        int p1, p2;
        int m = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->stepArg) {
        case 0:
        default:
            switch (irand() % 3) {
            case 0:
            default: {
                char *v = self->pack;
                p1 = *(int *)(v + 0xC00) + (int)v;
                p2 = *(int *)(v + 0xC04) + (int)v;
                break; }
            case 1: {
                char *v = self->pack;
                p1 = *(int *)(v + 0xC18) + (int)v;
                p2 = *(int *)(v + 0xC1C) + (int)v;
                break; }
            case 2: {
                char *v = self->pack;
                p1 = *(int *)(v + 0xC20) + (int)v;
                p2 = *(int *)(v + 0xC24) + (int)v;
                break; }
            }
            break;
        case 1: {
            char *v = self->pack;
            p1 = *(int *)(v + 0xC20) + (int)v;
            p2 = *(int *)(v + 0xC24) + (int)v;
            break; }
        case 2: {
            char *v = self->pack;
            p1 = *(int *)(v + 0xC20) + (int)v;
            p2 = *(int *)(v + 0xC28) + (int)v;
            break; }
        }
        func_002A8578(self, p1, p2, 3, 0.0f, m, 0);
        self->step += 1;
    }
    case 1:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        } else {
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
        }
        break;
    }
    if (self->seqFlags & 1) {
        func_00262750(self, 0);
    }
}
