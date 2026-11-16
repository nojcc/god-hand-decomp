/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/vu0.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void func_001268F0(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);
extern int D_00747A24;
extern void func_0012C348(void *a0, int a1);

#define FRAME ((char *)&va - 0x30)

__attribute__((section(".text.func_00115C00")))
void func_00115C00(pl00 *self)
{
    cVec va, vb, vc;
    float one;
    cVec *s;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    switch (self->base.step) {
    case 0: {
        char *t;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        self->base.rot.y = self->unk670;
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x8B0), EM_RES_REC(t, 0x8B4), 0, 0.0f, 0, 0);
        self->base.step += 1;
    }
    case 1: {
        func_00124EC0(self);
        self->flags15F4 |= 0x2080;
        cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
        self->base.motionFlags |= 8;
        if (moveMotion(self) != 0) {
            D_00747A24 |= 8;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        if (self->base.seqFlags & 0x10) {
            cVec *pa = &va;
            cVec *pb;
            s = self->base.pos;
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
            vb.y = vb.y - one;
            if (ChkLine(pa, pb, &vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                int m1 = ~0x80;
                int m2 = ~0x2000;
                self->base.pos->y = vc.y;
                self->base.step = 2;
                self->flags15F4 = self->flags15F4 & m1 & m2;
                cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 1);
                self->base.seqFlags &= 0xFFFB;
            }
        }
        if (self->base.seqFlags & 1) {
            self->base.hp = 0;
            cSnd_DieDemoStart(&D_005FEE00);
            func_0012C348(self, 2);
        }
        break;
    }
    case 2: {
        char *t = self->base.pack;
        int p1 = EM_RES_REC(t, 0x8D0);
        int p2 = EM_RES_REC(t, 0x8D4);
        SetEffectParts(0, 0x2D, self, 0, 0.0f, 0.0f, 0.0f, 1.0f, -1);
        func_002A8578(self, p1, p2, 0, 0.0f, 0, 0);
        self->base.step += 1;
    }
    case 3:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
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
