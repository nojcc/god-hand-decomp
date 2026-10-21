/* NON_MATCHING func_00192588 (sn-2.95.3-136): struck object switch. Retail stores phase, step
 * and stepArg of the random-switch arm in a different order and loads the second flags word into v0. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

#define TAKE_BIT_HIT     2              /* struck this frame */
#define TAKE_BIT_CHANCE  3              /* switch over at random */
#define TAKE_BIT_STRONG  6              /* strong hit */

#define TAKE_SWITCH_CHANCE  0.8f        /* chance a struck object switches over */

/* The damage-take unit of a struck object. */
typedef struct DamageTake {
    char unk00[0x10];
    cVec hitPos;                        /* 0x10 where the last hit landed */
    char unk20[0x40];
    unsigned int flags;                 /* 0x60 TAKE_BIT_* */
} DamageTake;

/* An object that switches over when struck. */
typedef struct cOmSwitch {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    DamageTake *take;                   /* 0x604 */
} cOmSwitch;

extern float fRand0_1(void);

/* React to a hit: move the knock point to the hit and go to mode 2 (strong hit, or the random
 * chance) or mode 1. */
void func_00192588(cOmSwitch *self)
{
    cVec v;
    long flags;

    if (self->take == 0) {
        return;
    }
    VU0_LQC2(4, &self->take->hitPos, 0);
    VU0_SQC2(4, &v, 0);
    cVec_copy3(&self->base.knock, &v);
    flags = self->take->flags;
    if (((flags >> TAKE_BIT_HIT) & 1) == 1) {
        if (((flags >> TAKE_BIT_STRONG) & 1) == 1) {
            self->base.mode = 2;
            self->base.phase = 0;
            self->base.flags0 |= COMBASE_F0_ACTIVE;
        } else {
            self->base.mode = 1;
            self->base.phase = 0;
        }
        self->base.step = 0;
        self->base.stepArg = 0;
    }
    flags = self->take->flags;
    if (((flags >> TAKE_BIT_CHANCE) & 1) == 1) {
        if (fRand0_1() < TAKE_SWITCH_CHANCE) {
            self->base.mode = 2;
            self->base.phase = 0;
            self->base.flags0 |= COMBASE_F0_ACTIVE;
            self->base.step = 0;
            self->base.stepArg = 0;
        } else {
            self->base.mode = 1;
            self->base.phase = 0;
            self->base.stepArg = 0;
            self->base.step = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00192588);
#endif
