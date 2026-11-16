/* TU: Slot2 - recovered C++ class. */
#include "godhand/criStm.h"
#include "include_asm.h"

#include "godhand/Slot2.h"

extern void InitStructSubfieldsAndFloat_1E8798(void *a0);
extern void InitStructZeroedFields_1E7960(void *a0);

__attribute__((section(".text.Slot2__ctor")))
Slot2 *Slot2__ctor(Slot2 *self) {
    Slot2Reel *q;
    int i;

    func_003A52F0(self, 0, 0x54);
    self->endFlag = 0;

    q = self->reel;
    /* closes with bne against a -1 register -> i != -1, not i >= 0 */
    for (i = 2; i != -1; i--) {
        InitStructSubfieldsAndFloat_1E8798(q);
        q++;
    }

    InitStructZeroedFields_1E7960(&self->panel);
    func_001E7118(&self->layer);

    self->slotId = 0xFFFF;
    self->menuSel = 0;
    self->camera = 0;
    return self;
}
