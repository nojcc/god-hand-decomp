/* sn-2.95.3-136 matched TU. */
#include "godhand/SlotUi.h"

extern void cIDBase(void *a0);

/* Construct both id bases and the twelve marks; returns self. */
__attribute__((section(".text.func_001E7118")))
SlotUi *func_001E7118(SlotUi *self) {
    CustomIDWork *q;
    int i;

    cIDBase(&self->id);
    q = self->mark;
    for (i = 9; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }

    cIDBase(&self->id2);
    q = self->bet;
    for (i = 1; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }

    return self;
}
