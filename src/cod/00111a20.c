/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/capVu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void func_00126770(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void func_0010A438(void *a0);
extern void func_0012BC00(void *a0, int a1, int a2);
extern char D_005864F0[];
extern int D_00747A0C;

__attribute__((section(".text.func_0011B900")))
void func_0011B900(pl00 *self)
{
    float one;

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
        func_00126770(self);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->base.step += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(self) != 0) {
            if (self->base.hp <= 0) {
                goto st;
            }
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    default:
        break;
    }
    if (self->base.hp <= 0) {
        if (self->base.seqFlags & 0x10) {
        st:
            self->base.stepArg = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.mode = 2;
        }
    } else {
        func_00123938(self, 1);
    }
}

__attribute__((section(".text.func_001127F8")))
void func_001127F8(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    self->flags15F4 |= 0x200;
    switch (self->base.step) {
    case 0:
    {
        char *t;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x8C, 0x1E, 0x25, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x8C, 0x1E, 0x25, 0, 0x123);
        self->unk1684 = 1;
        cCoreSave_useGodItem(&D_00569B70);
        func_00129578(self);
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x4A4), EM_RES_REC(t, 0x4A8),
                      3, 0.0f, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        self->unk15B0 = 1;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            func_00129630(self);
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
    func_0010A438(self);
    if ((self->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if ((self->base.seqFlags & 1) != 0 && self->unk15B0 != 0) {
        self->unk15B0 = 0;
        func_0012BC00(self, 0x2E, 0);
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 1, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}

__attribute__((section(".text.func_00112A48")))
void func_00112A48(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    self->flags15F4 |= 0x200;
    switch (self->base.step) {
    case 0:
    {
        int p1, p2;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        self->unk1684 = 1;
        func_00129578(self);
        cCoreSave_useGodItem(&D_00569B70);
        if (self->base.stepArg != 0) {
            char *v0 = self->base.pack;
            p1 = EM_RES_REC(v0, 0x450);
            p2 = EM_RES_REC(v0, 0x458);
        } else {
            char *v1 = self->base.pack;
            p1 = EM_RES_REC(v1, 0x450);
            p2 = EM_RES_REC(v1, 0x454);
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        self->unk15B0 = 1;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            func_00129630(self);
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
    if ((self->base.seqFlags & 1) != 0 && self->unk15B0 != 0) {
        self->unk15B0 = 0;
        if (self->base.stepArg != 0) {
            func_0012BC00(self, 0x2D, 0);
            func_0012BC00(self, 0x2D, 1);
            func_0012BC00(self, 0x2D, 2);
        } else {
            func_0012BC00(self, 0x2C, 0);
        }
    }
    if ((self->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 1, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}


__attribute__((section(".text.func_00111A20")))
void func_00111A20(pl00 *self)
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
    }
    switch (self->base.step) {
    case 0:
    {
        int p1, p2;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        if (self->base.stepArg != 0) {
            char *v0;
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x64, 0x15, 0x21, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x32, 0x15, 0x21, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x3C, 0x15, 0x21, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x3C, 0x15, 0x21, 0, 0x123);
            }
            v0 = self->base.pack;
            p1 = EM_RES_REC(v0, 0x20C);
            p2 = EM_RES_REC(v0, 0x214);
        } else {
            char *v1;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x23, 0x15, 0x21, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x23, 0x15, 0x21, 0, 0x123);
            v1 = self->base.pack;
            p1 = EM_RES_REC(v1, 0x20C);
            p2 = EM_RES_REC(v1, 0x210);
        }
        self->unk1684 = 1;
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        func_00129578(self);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if ((self->base.seqFlags & 0x100) != 0) {
            cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
        }
        if (moveMotion(self) != 0) {
            func_00129630(self);
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        if ((self->base.seqFlags & 0x100) != 0) {
            cGameObj *e = self->unk640;
            if (e != 0) {
                cGameObjVt *vt = cGameObj_vt(e);
                cVec *pos = self->base.pos;
                cVec *r = vt->getPos((char *)e + vt->getPosDelta);
                if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                    self->base.nullSpeed.x = 0.0f;
                    self->base.nullSpeed.z = 0.0f;
                }
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    func_0010A438(self);
    if ((self->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if ((self->base.seqFlags & 3) != 0) {
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
