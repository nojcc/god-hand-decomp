/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"

extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_00122A50")))
void func_00122A50(pl00 *self) {
    cEm00 *o;
    cVec *d;
    cVec *s;
    float one;

    self->base.hitFlash = 5.0f;
    o = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetSlotWait(D_005864F0, 2);
    self->flags15F4 = self->flags15F4 | 0x80000;
    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        if (o != 0) {
            d = o->pos;
            s = self->base.pos;
            if (d != s) {
                d->x = s->x;
                d->y = s->y;
                d->z = s->z;
            }
            o->rot.y = self->base.rot.y;
        }
        cEm00_GetPlMotion(o, 0x54, 0.0f, 0.0f);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->base.step = self->base.step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    case 2:
        cEm00_GetPlMotion(o, 0x55, 0.0f, 0.0f);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 3:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->base.step = self->base.step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    case 4:
        cEm00_GetPlMotion(o, 0x56, 0.0f, 0.0f);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 5:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            self->base.step = self->base.step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    case 6:
        cEm00_GetPlMotion(o, 0x57, 0.0f, 0.0f);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 7:
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
        break;
    }
}
