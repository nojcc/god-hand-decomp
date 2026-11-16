/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void func_00124EC0(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern int D_00747A24;
extern char D_005864F0[];
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00129630(void *a0);

__attribute__((section(".text.func_001142E0")))
void func_001142E0(pl00 *self)
{
    char *v0;
    float one;

    self->base.hitFlash = 15.0f;
    switch (self->base.step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        v0 = self->base.pack;
        func_002A8578(self, EM_RES_REC(v0, 0x18), EM_RES_REC(v0, 0x1C), 3, 0.0f, 0, 0);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 5, 0x17, 0x2A, 0, 0xA);
        self->unk1684 = 1;
        self->base.seqFlags |= 1;
        func_0010A438(self);
        self->base.step = self->base.step + 1;
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
    if (func_00123938(self, 1) != 0) {
        return;
    }
    if (self->base.seqFlags & 1) {
        self->flags15F4 = (self->flags15F4 & ~0x10) | 0x20;
    }
    self->base.seqFlags |= 0x800;
    self->unk674 = 0.05f;
}

__attribute__((section(".text.func_0011AAA0")))
void func_0011AAA0(pl00 *self)
{
    float one;
    float f;

    switch (self->base.step) {
    case 0: {
        int p1, p2;
        switch (irand() & 3) {
        case 0:
        default:
            {
            char *v0 = self->base.pack;
            p1 = EM_RES_REC(v0, 0x148);
            p2 = EM_RES_REC(v0, 0x14C);
            }
            break;
        case 1:
            {
            char *v1 = self->base.pack;
            p1 = EM_RES_REC(v1, 0x150);
            p2 = EM_RES_REC(v1, 0x154);
            }
            break;
        case 2:
            {
            char *v2 = self->base.pack;
            p1 = *(int *)(v2 + 0x4EC) + (int)v2;
            p2 = *(int *)(v2 + 0x4F0) + (int)v2;
            }
            break;
        case 3:
            {
            char *v3 = self->base.pack;
            p1 = *(int *)(v3 + 0x4F4) + (int)v3;
            p2 = *(int *)(v3 + 0x4F8) + (int)v3;
            }
            break;
        }
        func_002A8578(self, p1, p2, 1, 0.0f, 0, 0);
        if (irand() & 1) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, self, 0, 0, 0, 0);
        } else {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD0, self, 0, 0, 0, 0);
        }
        func_0012C348(self, 1);
        pl00_clearMotionCam(self, 0, 0);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->base.step += 1;
    }
        /* fallthrough */
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
        f = self->base.hitFlash;
        break;
    default:
        f = self->base.hitFlash;
        break;
    }
    if (f <= 1.0f) {
        self->base.seqFlags |= 0x40;
    }
    func_00123938(self, 1);
}

#include "godhand/vu0.h"




















__attribute__((section(".text.func_001209A0")))
void func_001209A0(pl00 *self)
{
    cEm00 *s1;
    cVec *p;
    cVec *q;

    self->base.hitFlash = 5.0f;
    self->base.objFlags |= 0x10000;
    s1 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0:
    {
        float buf[4];
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        if (s1 != 0) {
            func_0012C0F8(self, (int)(s1->unk76C * 50.0f));
        }
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        buf[1] = 0.0f;
        buf[0] = 0.0631f;
        buf[2] = 1.1214f;
        buf[3] = 1.0f;
        func_001299F0(self, s1, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s1, 0x21, 0.0f, 0.0f);
        self->unk15B0 = 1;
        self->base.unk56E = 0xF;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        if (self->base.unk56E == 0 || s1 == 0)
            goto join;
        (self->base.unk56E)--;
        p = self->base.pos;
        q = &s1->vel;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp <= 0) {
                D_00747A24 |= 8;
            } else {
                pl00_clearMotionCam(self, 1, 0);
                self->base.mode = 0;
                self->base.phase = 0;
                self->base.step = 0;
                self->base.stepArg = 0;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }
    if ((self->base.seqFlags & 1) != 0) {
        if (self->unk15B0 != 0) {
            func_0012C348(self, 2);
            self->unk15B0 = 0;
        }
    }
}

__attribute__((section(".text.func_00111210")))
void func_00111210(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    self->flags15F4 |= 0x200;
    if (self->base.step != 0 &&
        self->unk649 == 0 &&
        func_0010B2E8(self, 1) != 0) {
        self->unk649 = 1;
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (self->base.step) {
    case 0:
    {
        char *t;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x190, 0xF, 0x1E, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x190, 0xF, 0x1E, 0, 0x123);
        t = self->base.pack;
        self->unk1684 = 1;
        func_002A8578(self, EM_RES_REC(t, 0x19C), EM_RES_REC(t, 0x1A0),
                      3, 0.0f, 0, 0);
        func_00129578(self);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            func_00129630(self);
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
    if ((self->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if ((self->base.seqFlags & 1) != 0) {
        cSnd *g = &D_005FEE00;
        cSnd_SeStop(g, self->unk161C);
        self->unk161C = 0;
        g->flagsB0 &= 0xFFBFFFFF;
        g->flagsAC &= 0xFFBFFFFF;
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 0, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
