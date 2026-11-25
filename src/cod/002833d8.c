/* sn-2.95.3-136 matched TU. */
#include "godhand/cGameObjFn.h"

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00393F80")))
int func_00393F80(char *p) {
    if ((*(int *)p & 0xFFFFFF) != 0x524E53) return 1;
    if ((unsigned int)(*(unsigned char *)(p + 3) - 0x31) < 2)
        return (((*(int *)(p + 0x28) - 1) & (int)p) != 0) ? 4 : 0;
    return 2;
}

/* Phase 0xD at step 0, 2 or 4 for kinds 0 to 2. */
__attribute__((section(".text.func_002833D8")))
void func_002833D8(cGameObj *self, unsigned char kind)
{
    switch (kind) {
    case 0:
    default:
        self->mode = 0;
        self->phase = 0xD;
        self->step = 0;
        self->stepArg = 0;
        break;
    case 1:
        self->mode = 0;
        self->phase = 0xD;
        self->step = 2;
        self->stepArg = 0;
        break;
    case 2:
        self->mode = 0;
        self->phase = 0xD;
        self->step = 4;
        self->stepArg = 0;
        break;
    }
}

/* Phase 0xE at step 0, 2 or 4 for kinds 0 to 2. */
__attribute__((section(".text.func_00283438")))
void func_00283438(cGameObj *self, unsigned char kind)
{
    switch (kind) {
    case 0:
    default:
        self->mode = 0;
        self->phase = 0xE;
        self->step = 0;
        self->stepArg = 0;
        break;
    case 1:
        self->mode = 0;
        self->phase = 0xE;
        self->step = 2;
        self->stepArg = 0;
        break;
    case 2:
        self->mode = 0;
        self->phase = 0xE;
        self->step = 4;
        self->stepArg = 0;
        break;
    }
}
