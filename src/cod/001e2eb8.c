/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"
#include "godhand/effectPos.h"
#include "godhand/Slot1.h"
#include "godhand/scrollLayer.h"


/* Win stage of the first slot machine: blink for 10 frames and show the drift layers once, light the selected mark
 * and the keep mark for 120 frames, then return to the first state. */
__attribute__((section(".text.func_001E2EB8")))
void func_001E2EB8(Slot1 *self)
{
    long v;
    int done;

    switch (self->phase) {
    case 0:
        v = (unsigned int)self->flags;
        self->blinkTimer = 0xA;
        if (((v >> 8) & 1) == 0) {
            LayerScreen_hideLayers(self, 1);
            self->flags |= SLOT1_F_DRIFT_SET;
        }
        self->phase += 1;
        break;
    case 1:
        Slot2_selectMark(self, self->slotId, 1, 1);
        MarkObj_setMarkFlag(self, 0, 1);
        self->timer = 0x78;
        self->phase += 1;
        break;
    case 2:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            Slot2_selectMark(self, self->slotId, 0, 0);
            self->phase += 1;
        }
        break;
    case 3:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

#define DRIFT_LAYER_A  22      /* scrollLayer[] indices shown while the objects pass x -50..-60 */
#define DRIFT_LAYER_B  34

/* Drift the two objects left a unit a frame while flags bit 9 is set (back to 0 past -130), and show two layers while they pass x -50..-60. */
__attribute__((section(".text.func_001E4610")))
void func_001E4610(Slot1 *self)
{
    long v;

    if (self->drift[0] == 0)
        return;
    if (self->drift[1] == 0)
        return;
    v = (unsigned int)self->flags;
    if (((v >> 9) & 1) == 0)
        return;

    self->drift[0]->pos->x -= 1.0f;
    self->drift[1]->pos->x -= 1.0f;

    if (self->drift[0]->pos->x < -130.0f) {
        self->drift[0]->pos->x = 0.0f;
        self->drift[1]->pos->x = 0.0f;
    }

    if (self->drift[0]->pos->x < -50.0f &&
        self->drift[0]->pos->x > -60.0f) {
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_A], 1);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_B], 1);
    } else {
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_A], 0);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_B], 0);
    }
}

__attribute__((section(".text.func_0027BDD8")))
void func_0027BDD8(char *a0)
{
    long v;
    int obj;
    int b, lim;
    int spill[2];

    if (*(int *)(a0 + 0x564) == 0x263)
        return;
    if (*(short *)(a0 + 0x54A) <= 0)
        return;
    if (*(int *)(a0 + 0x670) == 0)
        return;
    v = *(unsigned int *)(*(int *)(a0 + 0x670) + 0x60);
    if ((v & 1) == 0)
        return;
    if (0.0f < *(float *)(a0 + 0x54C))
        return;

    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, a0, 0, 0, 0, 0);

    b = *(unsigned char *)(a0 + 0x2B4);
    spill[0] = b;
    lim = 4;
    if (lim < b)
        obj = *(int *)(*(int *)(a0 + 0x278) + 0x10);
    else
        obj = 0;
    if (obj != 0)
        SetEffectPos(0x58, 0x10, 0, (void *)*(int *)(obj + 0xF0), -1, 1.0f);

    *(float *)(a0 + 0x54C) = 3.0f;
    if (*(short *)(a0 + 0x548) <= 0)
        *(short *)(a0 + 0x54A) = *(unsigned short *)(a0 + 0x548);
    else
        *(short *)(a0 + 0x54A) = 0;
    *(char *)(a0 + 0x2F4) = 2;
    *(char *)(a0 + 0x2F5) = 0;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
}
