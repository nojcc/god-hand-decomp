/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void func_001268F0(void *a0);
#include "godhand/motion.h"
#include "godhand/pl00.h"
extern void func_00124EC0(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.UpdateAttackState2F6_1161E0")))
void UpdateAttackState2F6_1161E0(pl00 *self) {
    int v0;
    float one;
    self->base.hitFlash = 5.0f;
    self->flags15F4 = self->flags15F4 | 0x2080;
    switch (self->base.step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        v0 = (int)self->base.pack;
        func_002A8578(self, *(int *)(v0 + 0x8D8) + v0, *(int *)(v0 + 0x8DC) + v0, 0, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        one = 1.0f;
        func_00124EC0(self);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}
