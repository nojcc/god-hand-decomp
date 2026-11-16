/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void func_00129578(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern int D_005864F0;

__attribute__((section(".text.func_00113A20")))
void func_00113A20(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetBigHitEffWait(&D_005864F0, 2);
    self->flags15F4 |= 0x200;
    switch (self->base.step) {
    case 0: {
        int p1, p2;
        int s2;
        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_00129578(self);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 5, 0x17, 0x2A, 0, 0xA);
        self->unk1684 = 1;
        self->base.seqFlags |= 1;
        func_0010A438(self);
        if (self->base.stepArg) {
            char *q = self->base.pack;
            p1 = *(int *)(q + 0x294) + (int)q;
            p2 = *(int *)(q + 0x29C) + (int)q;
        } else {
            char *r = self->base.pack;
            p1 = *(int *)(r + 0x294) + (int)r;
            p2 = *(int *)(r + 0x298) + (int)r;
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        if (self->base.stepArg) {
            s2 = self->base.hpMax;
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
        } else {
            s2 = (int)(self->base.hpMax * 0.3f);
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
        }
        self->base.hp += s2;
        if (self->base.hpMax < self->base.hp) {
            self->base.hp = self->base.hpMax;
        }
        self->base.step += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_00124EC0(self);
        if (self->base.seqFlags & 0x100) {
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
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 0, 0);
    } else {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
