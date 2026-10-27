/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmSubGimmick.h"
#include "godhand/cSnd.h"
#include "godhand/sceVu0.h"
#include "godhand/vecInline.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

/* A gimmick that slides once along its local x axis when triggered. */
typedef struct cOmSlideGimmick {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    char move[0x760 - 0x600];           /* 0x600 cOmSub move work */
    char unk760[0x764 - 0x760];
    unsigned char triggered;            /* 0x764 set by the trigger, cleared when the slide ends */
    unsigned char sliding;              /* 0x765 1 while the slide runs */
} cOmSlideGimmick;

#ifdef NON_MATCHING
/* Slide gimmick: once triggered, move the object 0.7 back along its local
 * x axis over 10 frames with a sound, then wait for the move to end.
 * Still differs from retail: the return-slot subtraction takes &tmp_ into a
 * register after the vector code instead of before it, and two groups of
 * state-byte stores come out in a different order. */
__attribute__((section(".text.func_0017F828")))
void func_0017F828(cOmSlideGimmick *self)
{
    cVec to;
    cVec ofs;
    CVEC_TEMPS;

    switch (self->base.phase) {
    case 0:
        if (self->triggered == 0) {
            self->base.stepArg = 0;
            break;
        }
        CVEC_ZERO(to);
        vec4_set_point(&ofs.x, 0.7f, 0.0f, 0.0f);
        sceVu0ApplyMatrix(&ofs, self->base.mtx, &ofs);
        CVEC_SET_SUB(to, self->base.pos, &ofs);
        cOmSub_initMove1_pos(self->move, (char *)self, -1, 10, &to, 0.1f, 0.1f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x6B, self, 0, 0, 0, 0);
        self->base.step = 0;
        self->base.phase = 1;
        self->sliding = 1;
        self->base.stepArg = 0;
        /* fall through */
    case 1:
        if (cOmSub_move(self->move) != 0) {
            return;
        }
        self->base.stepArg = 0;
        self->triggered = 0;
        self->sliding = 0;
        break;
    default:
        return;
    }
    self->base.mode = 0;
    self->base.phase = 0;
    self->base.step = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0017F828);
#endif
