/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_0012C540(void *a0, int a1);

/* sn-2.95.3-136 candidate. */









__attribute__((section(".text.func_0011A660")))
void func_0011A660(pl00 *self)
{
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    self->base.hitFlash = 2.0f;
    switch (self->base.step) {
    case 0:
    {
        int b = (int)self->base.pack;

        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_002A8578(self, *(int *)(b + 0x6F0) + b, *(int *)(b + 0x6F4) + b,
                      3, 0.0f, 0, 0);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->base.step = self->base.step + 1;
    }
    case 1:
        if (moveMotion(self) == 0) {
            return;
        }
        func_0012C540(self, 1);
        self->base.step = self->base.step + 1;
        self->base.objFlags = self->base.objFlags | 2;
        {
            cGameObj *p = self->unk68C;

            if (p != 0) {
                p->objFlags = p->objFlags | 2;
            }
        }
        break;
    case 2:
    {
        int b = (int)self->base.pack;

        func_002A8578(self, *(int *)(b + 0x28) + b, *(int *)(b + 0x2C) + b,
                      3, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    }
    case 3:
        moveMotion(self);
        self->flags15F4 = self->flags15F4 | 0x1000;
        self->base.objFlags = self->base.objFlags | 2;
        {
            cGameObj *p = self->unk68C;

            if (p != 0) {
                p->objFlags = p->objFlags | 2;
            }
        }
        break;
    case 4:
    {
        int b = (int)self->base.pack;

        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_002A8578(self, *(int *)(b + 0x6F8) + b, *(int *)(b + 0x6FC) + b,
                      0, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    }
    case 5:
        if (moveMotion(self) == 0) {
            return;
        }
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    }
}
