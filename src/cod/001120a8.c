/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void func_001268F0(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00129630(void *a0);
extern void func_0012BC00(void *a0, int a1, int a2);
extern char D_005864F0[];

__attribute__((section(".text.func_001156D8")))
void func_001156D8(pl00 *self)
{
    cVec *d;
    cVec *s;

    self->base.hitFlash = 5.0f;
    switch (self->base.step) {
    case 0: {
        char *t;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        self->base.rot.y = self->unk670;
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x4C4), EM_RES_REC(t, 0x4C8), 0, 0.0f, 0, 0);
        self->base.step += 1;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        self->flags15F4 |= 0x80;
        cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
        if (moveMotion(self) != 0) {
            self->base.step = 2;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2: {
        char *t;
        d = self->base.pos;
        s = &self->unk660;
        if (d != s) {
            d->x = self->unk660.x;
            d->y = s->y;
            d->z = s->z;
        }
        d = &self->base.posA;
        s = self->base.pos;
        if (d != s) {
            self->base.posA.x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
        self->base.rot.y = self->unk670;
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x4D4), EM_RES_REC(t, 0x4D8), 0, 0.0f, 0, 0);
        self->base.step += 1;
    }
        /* fallthrough */
    case 3:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
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
}

/* sn-2.95.3-136 matched TU. */





















/* sn-2.95.3-136 matched TU. */























__attribute__((section(".text.func_001120A8")))
void func_001120A8(pl00 *self)
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
        self->unk1684 = 1;
        func_00129578(self);
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x870), EM_RES_REC(t, 0x874),
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
            func_0012BC00(self, 0x2F, 0);
        }
    }
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
        pl00_clearMotionCam(self, 1, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
