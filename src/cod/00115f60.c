/* sn-2.95.3-136 matched TU. */

extern void func_001268F0(void *a0);
#include "godhand/motion.h"
#include "godhand/pl00.h"
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
__attribute__((section(".text.func_00115F60")))
void func_00115F60(pl00 *self) {
    int v0;
    float one;
    self->base.hitFlash = 5.0f;
    switch (self->base.step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        self->base.pos->x = self->unk660.x;
        self->base.pos->z = self->unk660.z;
        {
            cVec *d = &self->base.posA;
            cVec *p = self->base.pos;
            if (d != p) {
                d->x = p->x;
                d->y = p->y;
                d->z = p->z;
            }
        }
        self->base.rot.y = self->unk670;
        v0 = (int)self->base.pack;
        func_002A8578(self, *(int *)(v0 + 0x8B8) + v0, *(int *)(v0 + 0x8BC) + v0, 0, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0; self->base.phase = 0;
            self->base.step = 0; self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}
