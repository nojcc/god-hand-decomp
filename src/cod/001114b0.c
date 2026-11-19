/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00262750(void *a0, int a1);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0010A438(void *a0);
extern char D_005864F0[];

__attribute__((section(".text.func_002256C8")))
void func_002256C8(cEm00 *self)
{

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        self->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(self, 0x28, 0xB, 0x42, 0, 0xF5);
        v0 = self->pack;
        a1v = EM_RES_REC(v0, 0xCE4);
        a2v = EM_RES_REC(v0, 0xCE8);
        self->timerA = 10;
        if (self->emNo == 0x250 || self->emNo == 0x251) {
            a2v = EM_RES_REC(v0, 0xCEC);
            self->timerA = 8;
        }
        func_002A8578(self, a1v, a2v, 3, 0.0f, gb, 0);
        self->timerC = 0;
        self->timer = self->rot.y;
        self->step += 1;
    }
        /* fallthrough */
    case 1: {
        if (self->timerA != 0) {
            void *s0;
            cGameObj *pl;
            float th;
            self->timerA -= 1;
            s0 = self->pos;
            pl = Getplayer();
            th = Turn_dest(s0, pl->pos, self->timer, self->speedRate * 0.19634955f);
            self->timer += th;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += th;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    }
    func_00260B30(self);
    if (self->seqFlags & 1) {
        func_00262750(self, 0);
    }
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}

__attribute__((section(".text.func_001114B0")))
void func_001114B0(pl00 *self)
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
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x2BC, 0x10, 0x1E, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x2BC, 0x10, 0x1E, 0, 0x123);
        t = self->base.pack;
        self->unk1684 = 1;
        func_002A8578(self, EM_RES_REC(t, 0x614), EM_RES_REC(t, 0x618),
                      3, 0.0f, 0, 0);
        func_00129578(self);
        cEmManage_SetSpeedRate(D_005864F0, 0.2f);
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
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
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

__attribute__((section(".text.func_001125A0")))
void func_001125A0(pl00 *self)
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
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x14, 0x1D, 0x23, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x50, 0xF, 0x1E, 0, 0x123);
        self->unk1684 = 1;
        func_00129578(self);
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x2C0), EM_RES_REC(t, 0x2C4),
                      3, 0.0f, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
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
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 1, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
