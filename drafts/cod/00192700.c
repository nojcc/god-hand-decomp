/* NON_MATCHING func_00192700 (sn-2.95.3-136, as sn): 11 differing words, one missing nop.
 * Retail pads the three-instruction loop over the child count with a short-loop nop
 * before its bnel; neither assembler pads a loop that also has an exit branch. The loop
 * has no body in retail either. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"
#include "godhand/vu0.h"
#include "godhand/cSnd.h"

#define FADE_HOLD_FRAMES  30
#define FADE_OUT_FRAMES   15
#define FADE_EFFECT       7
#define FADE_CHILD_MAX    10

enum { FADE_START, FADE_HOLD, FADE_OUT, FADE_DONE };

/* A breakable map object that fades away after it is switched off. */
typedef struct cOmFadeBreak {
    cGameObj base;
    char unk5AC[0x600 - 0x5AC];
    short timer;                /* 0x600 */
} cOmFadeBreak;

typedef struct cOmDamaged cOmDamaged;

extern void cOmDamaged_switchOff(cOmDamaged *self);
extern void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self);

/* Switches the object off with an effect, holds, then fades its animation rate to zero. */
__attribute__((section(".text.func_00192700")))
void func_00192700(cOmFadeBreak *self)
{
    cVec pos;
    int i;

    switch (self->base.phase) {
    case FADE_START: {
        cVec *src;
        VU0_SQC2_VF0(&pos, 0);
        src = ((cVec *(*)(void *))cGameObj_vt(&self->base)->lockOn)((char *)self + cGameObj_vt(&self->base)->lockOnDelta);
        cVec_copy3(&pos, src);
        SetEffectPos(0, FADE_EFFECT, 0, &pos, -1, 1.0f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self, 0, 0, 0, 0);
        cOmDamaged_switchOff((cOmDamaged *)self);
        SetField5B0Bit2ClearBit8_1B7908((cOmBase *)self);
        self->base.phase = FADE_HOLD;
        self->timer = FADE_HOLD_FRAMES;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
    case FADE_HOLD:
        if (--self->timer > 0) {
            break;
        }
        self->timer = FADE_OUT_FRAMES;
        self->base.phase = FADE_OUT;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case FADE_OUT:
        self->base.tint.w = (float)--self->timer / 15.0f;
        if (self->timer > 0) {
            break;
        }
        self->base.phase = FADE_DONE;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case FADE_DONE:
        self->base.mode = FADE_DONE;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    }
    for (i = 0; i < FADE_CHILD_MAX && self->base.partNum != i; i++) {
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00192700);
#endif
