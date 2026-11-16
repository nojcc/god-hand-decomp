/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void Owner_spawnEffect(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
#include "godhand/motion.h"
#include "godhand/pl00.h"
extern void func_00124EC0(void *a0);

extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern int D_005864F0;

__attribute__((section(".text.func_00113CF8")))
void func_00113CF8(pl00 *self)
{
    char *b;
    float one;

    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetBigHitEffWait(&D_005864F0, 2);
    self->flags15F4 |= 0x200;
    switch (self->base.step) {
    case 0:
        Owner_spawnEffect(self);
        pl00_clearMotionCam(self, 0, 0);
        Obj0000_Clear_Fields_640_648_124E58(self);
        b = self->base.pack;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_002A8578(self, EM_RES_REC(b, 0x220), EM_RES_REC(b, 0x224), 3, 21.0f, 0, 0);
        self->unk15B0 = 0xD;
        self->base.step = self->base.step + 1;
    case 1:
        moveMotion(self);
        if (self->unk15B0 != 0) {
            self->unk15B0 = self->unk15B0 - 1;
        } else {
            self->base.step = 2;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
        break;
    case 2:
        Obj0000_Clear_Fields_640_648_124E58(self);
        b = self->base.pack;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_002A8578(self, EM_RES_REC(b, 0x380), EM_RES_REC(b, 0x384), 0, 0.0f, 0, 0);
        self->base.hp = self->base.hp - 10;
        if (self->base.hp < 2) {
            self->base.hp = 1;
        }
        self->base.step = self->base.step + 1;
    case 3:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        if (func_00123938(self, 1) != 0) {
            pl00_clearMotionCam(self, 0, 0);
        }
        break;
    }
}
