/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/capVu0.h"
#include "godhand/cObjBase.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern unsigned char D_005864F0[];
extern void func_00124EC0(void *a0);
extern void func_0012CC70(void *a0);
extern void cEmManage_SetSpeedRate(void *a0, float f12);
extern void SetMotionStep(void *a0, float f12);
extern void func_00126770(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void FreeFieldObject_1267F8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.func_00114608")))
void func_00114608(pl00 *self)
{
    switch (self->base.step) {
    case 0: {
        int s2;
        cGameObj *e;
        int p1;
        int p2;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        func_00124540(self, 3);
        if (self->unk640 != 0)
            func_00124EC0(self);
        e = self->unk640;
        s2 = 0;
        if (e != 0) {
            cGameObjVt *vt = cGameObj_vt(e);
            cVec *p = self->base.pos;
            int off = vt->getPosDelta;
            cVec *(*fp)(void *self) = vt->getPos;
            cVec *r = fp((char *)e + off);
            if (64.0f < capVu0MagnitudeSqXZ(p, r))
                s2 = 1;
        }
        if (s2 != 0) {
            int w1 = (int)self->base.pack;
            p1 = *(int *)(w1 + 0x228) + w1;
            p2 = *(int *)(w1 + 0x22C) + w1;
        } else {
            int w2 = (int)self->base.pack;
            p1 = *(int *)(w2 + 0x220) + w2;
            p2 = *(int *)(w2 + 0x224) + w2;
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->unk15B0 = 0x66;
        self->unk15BC = self->unk15B4 = 1;
        self->base.unk568 = 5;
        self->unk15B8 = 0;
        self->unk165C = 0;
        self->unk161C = 0;
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 1:
        InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
        if (self->unk640 != 0) {
            self->unk648 = 0x14;
            func_0012CC70(self);
            self->flags15F4 = self->flags15F4 | 0x800000;
        }
        if (self->base.seqFlags & 0x100) {
            if (self->unk15B4 != 0) {
                if (self->unk165C == 0)
                    self->unk165C = func_00125048(self);
                if (self->unk15B0 != 0) {
                    self->unk15B0 = self->unk15B0 - 1;
                    if (self->unk161C == 0)
                        self->unk161C =
                            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 4, self, 0, 0, 0, 0);
                    cEmManage_SetSpeedRate(&D_005864F0, 0.03f);
                    self->base.speedRate = 0.03f;
                    SetMotionStep(self, 0.03f);
                    {
                        cSnd *g = &D_005FEE00;
                        g->flagsB0 = g->flagsB0 | 0x400000;
                        g->flagsAC = g->flagsAC | 0x400000;
                    }
                    if (self->unk15BC != 0) {
                        self->unk15BC = 0;
                        if (self->flags15F4 & 0x20) {
                            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
                            default:
                            case 0:
                            case 2:
                            case 4:
                            case 6:
                                SetEffect(0, 0xE, self, 0, -1, 0xFFFFFFFFU);
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                break;
                            }
                        }
                    }
                }
            }
            if (self->base.seqFlags & 0x100) {
                if (self->base.unk568 != 0) {
                    self->base.unk568 = self->base.unk568 - 1;
                } else if (self->unk626 != 0 &&
                           self->unk15B8 == 0) {
                    self->unk626 = 0;
                    self->unk621 = 0;
                    self->unk622 = 0;
                    self->unk623 = 0;
                    self->unk15B8 = 1;
                    func_00126770(self);
                    pl00_clearMotionCam(self, 1, 0);
                    self->base.step = 2;
                }
            }
        }
        if (self->unk15B0 == 0 && self->unk15B8 == 0)
            FreeFieldObject_1267F8(self);
        if (moveMotion(self)) {
            pl00_clearMotionCam(self, 1, 0);
            func_00126770(self);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->base.seqFlags & 0x100) {
            self->base.seqFlags = self->base.seqFlags | 0x800;
            self->unk674 = 0.05f;
        }
        break;
    case 2: {
        int w = (int)self->base.pack;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_002A8578(self, *(int *)(w + 0x220) + w, *(int *)(w + 0x224) + w,
                      0xA, 21.0f, 0, 0);
        self->base.step = self->base.step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(self)) {
            func_00126770(self);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }
    if (self->base.seqFlags & 0x10)
        self->flags15F4 = self->flags15F4 | 0x400000;
    if (func_00123938(self, 1)) {
        func_00126770(self);
        pl00_clearMotionCam(self, 1, 0);
    }
}
