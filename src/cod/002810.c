/* ee-2.9-991111 matched TU. */
#include "godhand/cEm00.h"

/* Mode, phase, step and step argument all 0. */
__attribute__((section(".text.func_00281260")))
void func_00281260(cGameObj *self)
{
    self->mode = 0;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
}

/* Phase 1 at step 0 with the step argument. */
__attribute__((section(".text.Obj2810_SetState_1_a1")))
void Obj2810_SetState_1_a1(cGameObj *self, int arg)
{
    cGameObj_setState(self, 1, 0, arg);
}

/* Phase 2 at step 0 with the step argument. */
__attribute__((section(".text.Obj2810_SetState_2_a1")))
void Obj2810_SetState_2_a1(cGameObj *self, int arg)
{
    cGameObj_setState(self, 2, 0, arg);
}

/* Starts phase 3 at the step for `kind`: 0, 2, 4 or 6 for kinds 0 to 3. */
__attribute__((section(".text.cGameObj_startPhase3")))
void cGameObj_startPhase3(cGameObj *self, unsigned int kind, unsigned char arg)
{
    switch (kind) {
    default:
    case 0:
        cGameObj_setState(self, 3, 0, arg);
        break;
    case 1:
        cGameObj_setState(self, 3, 2, arg);
        break;
    case 2:
        cGameObj_setState(self, 3, 4, arg);
        break;
    case 3:
        cGameObj_setState(self, 3, 6, arg);
        break;
    }
}

/* Phase 4 at step 0. */
__attribute__((section(".text.Obj2810_ClearState_4")))
void Obj2810_ClearState_4(cGameObj *self)
{
    self->mode = 0;
    self->phase = 4;
    self->step = 0;
    self->stepArg = 0;
}

/* Phase 5 at step 0. */
__attribute__((section(".text.Obj2810_ClearState_5")))
void Obj2810_ClearState_5(cGameObj *self)
{
    self->mode = 0;
    self->phase = 5;
    self->step = 0;
    self->stepArg = 0;
}

/* Phase 6 at step 0. */
__attribute__((section(".text.Obj2810_ClearState_6")))
void Obj2810_ClearState_6(cGameObj *self)
{
    self->mode = 0;
    self->phase = 6;
    self->step = 0;
    self->stepArg = 0;
}

/* Phase 7 at step 0, 2 or 4 for kinds 0 to 2. */
__attribute__((section(".text.func_00281368")))
void func_00281368(cGameObj *self, int kind)
{
    if (kind == 1) goto a1;
    if (kind == 0) goto def;
    if (kind == 2) goto a2;
def: /* a switch or an if-chain instead changes the block order */
    self->mode = 0; self->phase = 7; self->step = 0; self->stepArg = 0;
    return;
a1:
    self->phase = 7; self->step = 2; self->mode = 0; self->stepArg = 0;
    return;
a2:
    self->phase = 7; self->step = 4; self->mode = 0; self->stepArg = 0;
}

/* Phase 8 at step 0 with the step argument. */
__attribute__((section(".text.Obj2810_SetState_8_a1")))
void Obj2810_SetState_8_a1(cGameObj *self, int arg)
{
    cGameObj_setState(self, 8, 0, arg);
}

/* Phase 9 at step 0 with the step argument. */
__attribute__((section(".text.Obj2810_SetState_9_a1")))
void Obj2810_SetState_9_a1(cGameObj *self, int arg)
{
    cGameObj_setState(self, 9, 0, arg);
}

/* Phase 0xA at step 0, 2, 4 or 6 for kinds 0 to 3. */
__attribute__((section(".text.func_002813F0")))
void func_002813F0(cGameObj *self, int kind)
{
    if (kind == 1) goto a1;
    if (kind == 0) goto def;
    if (kind == 2) goto a2;
    if (kind == 3) goto a3;
def: /* a switch or an if-chain instead changes the block order */
    self->mode = 0; self->phase = 0xA; self->step = 0; self->stepArg = 0;
    return;
a1:
    self->phase = 0xA; self->step = 2; self->mode = 0; self->stepArg = 0;
    return;
a2:
    self->phase = 0xA; self->step = 4; self->mode = 0; self->stepArg = 0;
    return;
a3:
    self->phase = 0xA; self->step = 6; self->mode = 0; self->stepArg = 0;
}

/* Phase 0xE at step 0 with the step argument. */
__attribute__((section(".text.Obj2810_SetState_E_a1")))
void Obj2810_SetState_E_a1(cGameObj *self, int arg)
{
    cGameObj_setState(self, 0xE, 0, arg);
}

/* Phase 0xF at step 0 or 2 for kinds 0 and 1. */
__attribute__((section(".text.func_00281470")))
void func_00281470(cGameObj *self, unsigned char kind)
{
    switch (kind) {
    case 0:
        self->mode = 0;
        self->phase = 0xF;
        self->step = 0;
        self->stepArg = 0;
        break;
    case 1:
        self->mode = 0;
        self->phase = 0xF;
        self->step = 2;
        self->stepArg = 0;
        break;
    default:
        self->mode = 0;
        self->phase = 0xF;
        self->step = 0;
        self->stepArg = 0;
        break;
    }
}

/* Phase 0xB at step 0. */
__attribute__((section(".text.Obj2810_ClearState_B")))
void Obj2810_ClearState_B(cGameObj *self)
{
    self->mode = 0;
    self->phase = 0xB;
    self->step = 0;
    self->stepArg = 0;
}

/* Phase 0xC at step 0. */
__attribute__((section(".text.Obj2810_ClearState_C")))
void Obj2810_ClearState_C(cGameObj *self)
{
    self->mode = 0;
    self->phase = 0xC;
    self->step = 0;
    self->stepArg = 0;
}

/* Phase 0xD at step 0 with the step argument. */
__attribute__((section(".text.Obj2810_SetState_D_a1")))
void Obj2810_SetState_D_a1(cGameObj *self, int arg)
{
    cGameObj_setState(self, 0xD, 0, arg);
}

/* Phase 0x10 at step 0, 2 or 4 for kinds 0 to 2. */
__attribute__((section(".text.func_00281500")))
void func_00281500(cGameObj *self, unsigned char kind)
{
    switch (kind) {
    default:
    case 0:
        self->mode = 0;
        self->phase = 0x10;
        self->step = 0;
        self->stepArg = 0;
        break;
    case 1:
        self->mode = 0;
        self->phase = 0x10;
        self->step = 2;
        self->stepArg = 0;
        break;
    case 2:
        self->mode = 0;
        self->phase = 0x10;
        self->step = 4;
        self->stepArg = 0;
        break;
    }
}

/* Phase 0x11 at step 0, 2 or 4 for kinds 0 to 2. */
__attribute__((section(".text.func_00281560")))
void func_00281560(cGameObj *self, unsigned char kind)
{
    switch (kind) {
    default:
    case 0:
        self->mode = 0;
        self->phase = 0x11;
        self->step = 0;
        self->stepArg = 0;
        break;
    case 1:
        self->mode = 0;
        self->phase = 0x11;
        self->step = 2;
        self->stepArg = 0;
        break;
    case 2:
        self->mode = 0;
        self->phase = 0x11;
        self->step = 4;
        self->stepArg = 0;
        break;
    }
}

/* Bit 0 of unk1560. */
__attribute__((section(".text.Obj2810_GetField1560_Bit0")))
int Obj2810_GetField1560_Bit0(cEm00 *self)
{
    return self->unk1560 & 1;
}

/* 1 when bit 1 of unk1560 is set. */
__attribute__((section(".text.func_002815D0")))
int func_002815D0(cEm00 *self)
{
    return (self->unk1560 & 2) > 0;
}
