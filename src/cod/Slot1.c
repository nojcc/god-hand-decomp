/* The constructor is a function named Slot1, as in the retail symbol table, so
 * the record type gets another name for this file. */
#define Slot1 Slot1Obj
#include "godhand/Slot1.h"
#include "godhand/criStm.h"
#undef Slot1

extern void InitStructSubfieldsAndFloatB(void *reel);
extern void InitStructZeroedFields_1E7960(void *panel);

#define SLOT1_HEAD_SIZE    0x54         /* bytes the constructor clears first, up to flags */

/* Constructor: clears the head, builds the three reels, the panel and the ui,
 * and resets the pay state. Returns the machine. */
__attribute__((section(".text.Slot1")))
Slot1Obj *Slot1(Slot1Obj *self)
{
    Slot1Reel *reel;
    int i;
    func_003A52F0(self, 0, SLOT1_HEAD_SIZE);
    self->flags = 0;
    reel = self->reel;
    for (i = SLOT1_REEL_NUM - 1; i != -1; i--) {
        InitStructSubfieldsAndFloatB(reel);
        reel++;
    }
    InitStructZeroedFields_1E7960(&self->panel);
    func_001E7118(&self->ui);
    self->unk48C = 0xFFFF;
    self->payMode = SLOT1_PAYMODE_ON;
    self->drift[0] = 0;
    self->drift[1] = 0;
    self->unk4B8 = 0;
    self->unk4BC = 0;
    self->subCam = 0;
    self->blinkTimer = 0;
    self->unkB50 = 0;
    self->unkB52 = 0;
    return self;
}
