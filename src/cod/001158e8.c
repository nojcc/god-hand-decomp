/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/vu0.h"
#include "godhand/motion.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void func_001268F0(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);

#define FRAME ((char *)&va - 0x30)

__attribute__((section(".text.func_001158E8")))
void func_001158E8(pl00 *self)
{
    cVec va, vb, vc;
    cVec *d;
    cVec *s;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    self->base.hitFlash = 5.0f;
    switch (self->base.step) {
    case 0: {
        char *t;
        self->comboSlot = 0;
        self->comboSet = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        d = &self->base.posA;
        self->base.pos->x = self->unk660.x;
        self->base.pos->z = self->unk660.z;
        s = self->base.pos;
        if (d != s) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
        self->base.rot.y = self->unk670;
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x4CC), EM_RES_REC(t, 0x4D0), 0, 0.0f, 0, 0);
        self->base.step += 1;
    }
        /* fallthrough */
    case 1: {
        func_00124EC0(self);
        self->flags15F4 |= 0x80;
        cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
        if (moveMotion(self) != 0) {
            self->base.step = 2;
        }
        self->base.nullSpeed.z = self->base.nullSpeed.z + self->base.nullSpeed.z;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->base.seqFlags & 0x10) {
            cVec *pa = &va;
            cVec *pb;
            s = &self->base.posA;
            if (pa != s) {
                va.x = s->x;
                pa->y = s->y;
                pa->z = s->z;
            }
            s = self->base.pos;
            pb = &vb;
            if (pb != s) {
                vb.x = s->x;
                vb.y = s->y;
                vb.z = s->z;
            }
            va.y = va.y + 0.5f;
            if (ChkLine(pa, pb, &vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                self->base.pos->y = vc.y;
                self->base.step = 2;
            }
        }
        break;
    }
    case 2: {
        char *t = self->base.pack;
        int p1 = EM_RES_REC(t, 0x4D4);
        int p2 = EM_RES_REC(t, 0x4D8);
        SetEffectParts(0, 0x2D, self, 0, 0.0f, 0.0f, 0.0f, 1.0f, -1);
        func_002A8578(self, p1, p2, 0, 0.0f, 0, 0);
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
