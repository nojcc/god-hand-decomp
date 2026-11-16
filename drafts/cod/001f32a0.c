/* Colours are bitfield structs passed by value (a register), which keeps the
 * per-byte and/or masks unmerged as in retail.
* func_001F32A0: 38 insns, register choice only - retail builds col from an
 * uninitialised a3 into a2 (from/to in t0/a2); ours uses a1 and t0/a3.
* CustomIDOwner_setPanelState: 3 insns, case 3 - retail hoists lui a1,0x8000 into a beql
 * delay slot where ours puts daddu a0,s0 in a plain beq slot. */
#include "godhand/CustomIDPanel.h"
#include "include_asm.h"

#ifdef NON_MATCHING

extern void CustomIDWork_SetColorAnimNormal_2D68D8(CustomIDWork *work, int a1, CustomIDColor col, int frames);

void func_001F32A0(CustomIDPanel *self)
{
    long flags;
    CustomIDColor col, from, to;

    flags = self->flags;
    if (((flags >> 2) & 1) == 0) {
        return;
    }
    switch (self->anim[2].state) {
    case 0:
        col.r = 0x80; col.g = 0x80; col.b = 0x80; col.a = 0x80;
        CustomIDWork_SetColorAnimNormal_2D68D8(&self->work[4], 0, col, 0xF);
        SetCustomIDDispOneOrAll_1F29C0(self, 4, 1);
        self->anim[2].timer = 15;
        self->anim[2].state++;
        break;
    case 1:
        if (self->anim[2].timer == 0) {
        from.r = 0x80; from.g = 0x80; from.b = 0x80; from.a = 0x80;
        to.r = 0x80; to.g = 0x80; to.b = 0x80; to.a = 0x4D;
        CustomIDWork_SetColorAnimSin(&self->work[4], *(unsigned int *)&from, *(unsigned int *)&to, 5);
        self->anim[2].state++;
        } else {
            self->anim[2].timer--;
        }
        break;
    case 2:
        break;
    }
}

#else

INCLUDE_ASM("asm/nonmatching", func_001F32A0);

#endif
