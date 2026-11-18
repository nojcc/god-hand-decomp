/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmSub.h"
#include "godhand/rand.h"
#include "godhand/vecInline.h"

extern int cOmSub_move(char *a0);
extern void cOmSub_setReverse(cOmSub *self, int reverse);
extern void func_001B7EE0(void *a0, float f12);
extern void cOmSub_initMove1_pos(char *dst, char *obj, int idx, int a3, void *a4, float w, float h);

/* A gimmick that trembles part 2, then drops it with its damage collision
 * flashing, and raises it again on the reversed path. */
typedef struct cOmDropper {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x608 - 0x5E0];
    cDamageUnit *coll;                  /* 0x608 */
    char unk60C[0x990 - 0x60C];
    cOmSub move;                        /* 0x990 */
    char unkAD0[0xAF0 - 0xAD0];
    short timer;                        /* 0xAF0 */
    unsigned char donePhase;            /* 0xAF2 phase to go to when the run ends */
    unsigned char moving;               /* 0xAF3 1 while func_001B7EE0 runs each frame */
    char unkAF4[0xB08 - 0xAF4];
    float restY;                        /* 0xB08 part 2's resting anchor height */
} cOmDropper;

/* Tremble part 2 for 30 frames, drop it, wait 60 frames, raise it again. */
__attribute__((section(".text.func_00194D10")))
void func_00194D10(cOmDropper *self)
{
    int frame[3];
    cVec drop;

    switch (self->base.step) {
    case 0:
        if (cOmBase_childAt(&self->base, frame, 2) != 0) {
            self->restY = cOmBase_childAt(&self->base, frame, 2)->anchor->y;
        }
        self->timer = 0x1E;
        self->base.step = 1;
        self->moving = 0;
        self->base.stepArg = 0;
        /* fallthrough */
    case 1: {
        if (cOmBase_childAt(&self->base, frame, 2) != 0) {
            cOmBase *part = cOmBase_childAt(&self->base, frame, 2);
            float d = fRand1_1() * 0.05f;

            part->anchor->y = self->restY + d;
        }
        self->timer -= 1;
        if (self->timer >= 0)
            break;
        cOmBase_childAt(&self->base, frame, 2)->anchor->y = self->restY;
        cDamageUnit_SetDamageCollFlashActive(self->coll, 1, 7);
        vec4_set_point(&drop.x, 0.0f, -2.2699999f, 0.0f);
        cOmSub_initMove1_pos((char *)&self->move, (char *)self, 2, 7, &drop, 0.2f, 0.0f);
        self->moving = 1;
        self->base.step = 2;
        self->base.stepArg = 0;
        break;
    }
    case 2: {
        cOmBase *part;

        if (cOmSub_move((char *)&self->move) != 0)
            break;
        SetEffect(0x177, 1, self, 0, -1, 0xFFFFFFFFU);
        part = cOmBase_childAt(&self->base, frame, 1);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xB6, self, 0, part, 0, 0);
        self->timer = 0x3C;
        self->base.step = 3;
        self->base.stepArg = 0;
        break;
    }
    case 3: {
        cOmSub *move;
        cOmBase *part;

        self->timer -= 1;
        if (self->timer >= 0)
            break;
        move = &self->move;
        move->unk30 = 30.0f;
        cOmSub_setReverse(move, 1);
        part = cOmBase_childAt(&self->base, frame, 1);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xB7, self, 0, part, 0, 0);
        self->base.stepArg = 0;
        self->base.step = 4;
        break;
    }
    case 4:
        if (cOmSub_move((char *)&self->move) != 0)
            break;
        self->moving = 0;
        self->base.step = 5;
        self->base.stepArg = 0;
        break;
    case 5:
        self->base.step = 0;
        self->base.phase = self->donePhase;
        self->base.stepArg = 0;
        break;
    default:
        break;
    }
    if (self->moving == 1)
        func_001B7EE0(self, 2.3f);
}
