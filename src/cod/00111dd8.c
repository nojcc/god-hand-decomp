/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0012BC00(void *a0, int a1, int a2);
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */























__attribute__((section(".text.func_00111DD8")))
void func_00111DD8(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    self->flags15F4 |= 0x200;
    switch (self->base.step) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        self->unk1684 = 1;
        func_00129578(self);
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
        t = (int)self->base.pack;
        func_002A8578(self, *(int *)(t + 0x20) + t, *(int *)(t + 0x24) + t,
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
    if ((self->base.seqFlags & 1) != 0) {
        if (self->unk15B0 != 0) {
            self->unk15B0 = 0;
            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
            default:
            case 0:
            case 2:
            case 4:
            case 6:
                func_0012BC00(self, 0x29, 0);
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                func_0012BC00(self, 0x2A, 0);
                func_0012BC00(self, 0x2B, 0);
                break;
            }
        }
    }
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
        pl00_clearMotionCam(self, 1, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
