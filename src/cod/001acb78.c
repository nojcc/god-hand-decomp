/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmBase.h"

extern int irand(void);

/* A gimmick that flaps two parts open and shut a random number of times,
 * then opens wide and flashes its damage collision. */
typedef struct cOmFlapPair {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x618 - 0x5E0];
    int unk618;                         /* 0x618 cleared when the run ends */
    char unk61C[0x61E - 0x61C];
    short timer;                        /* 0x61E */
    signed char rounds;                 /* 0x620 flaps done */
    char unk621[0x628 - 0x621];
    cDamageUnit *coll;                  /* 0x628 */
    char unk62C[0x794 - 0x62C];
    float angle;                        /* 0x794 part 1 turns to -angle, part 2 to angle */
} cOmFlapPair;

/* Turn part 1 to -angle and part 2 to angle. A macro: as an inline function
 * the code grows by four words. */
#define FLAP_SET_PARTS(self, frame)                                             \
    {                                                                           \
        if (cOmBase_childAt(&(self)->base, (frame), 1) != 0)                    \
            cOmBase_childAt(&(self)->base, (frame), 1)->rot.y = -(self)->angle; \
        if (cOmBase_childAt(&(self)->base, (frame), 2) != 0)                    \
            cOmBase_childAt(&(self)->base, (frame), 2)->rot.y = (self)->angle;  \
    }

/* Flap both parts: random wait, flaps of 5 degrees until the timer runs out,
 * then a wide opening with the damage flash, then close and repeat or stop. */
__attribute__((section(".text.func_001ACB78")))
void func_001ACB78(cOmFlapPair *self)
{
    int frame[3];
    int r;

    switch (self->base.step) {
    case 0:
        self->angle = 0.0f;
        r = irand();
        self->base.step = 1;
        self->timer = (r & 0xF) + 0xF;
        self->rounds = 0;
        self->base.stepArg = 0;
        /* fall through */
    case 1:
        self->timer -= 1;
        if (self->timer > 0)
            break;
        self->timer = 8;
        self->base.step = 2;
        self->rounds = self->rounds + 1;
        self->base.stepArg = 0;
        break;
    case 2:
        self->angle = self->angle + 0.0872664601f;
        FLAP_SET_PARTS(self, frame)
        self->base.stepArg = 0;
        self->base.step = 3;
        break;
    case 3:
        self->angle = self->angle - 0.0872664601f;
        FLAP_SET_PARTS(self, frame)
        self->timer -= 1;
        if (self->timer > 0) {
            self->base.stepArg = 0;
            self->base.step = 2;
            break;
        }
        self->base.stepArg = 0;
        self->base.step = 4;
        break;
    case 4:
        self->angle = self->angle + 0.34906584f;
        FLAP_SET_PARTS(self, frame)
        if (1.57079637f <= self->angle) {
            if (self->coll != 0) {
                cDamageUnit_SetDamageCollFlashActive(self->coll, 1, 2);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x111, self, 0, 0, 0, 0);
            }
            self->base.stepArg = 0;
            self->base.step = 5;
        }
        break;
    case 5:
        self->angle = self->angle - 0.0872664601f;
        FLAP_SET_PARTS(self, frame)
        if (self->angle <= 0.0f) {
            if (cOmBase_childAt(&self->base, frame, 1) != 0)
                cOmBase_childAt(&self->base, frame, 1)->rot.y = 0.0f;
            if (cOmBase_childAt(&self->base, frame, 2) != 0)
                cOmBase_childAt(&self->base, frame, 2)->rot.y = 0.0f;
            if ((irand() & 1) != 0 || self->rounds >= 2) {
                self->base.stepArg = 0;
                self->base.step = 6;
                break;
            }
            self->timer = 4;
            self->base.step = 1;
            self->angle = 0.0f;
            self->base.stepArg = 0;
        }
        break;
    case 6:
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        self->unk618 = 0;
        break;
    }
}
