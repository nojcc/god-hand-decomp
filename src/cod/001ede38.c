/* sn-2.95.3-136 matched TU. */
#include "godhand/DogRace.h"

extern void cIDBase(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001EDE38")))
DogRaceList *func_001EDE38(DogRaceList *self) {
    CustomIDWork *q;
    int i;

    self->unk000 = 0;
    cIDBase(&self->id);

    q = self->elem;
    /* `i != -1`, not `i >= 0`: retail materialises -1 in a register and closes
       this call-loop with `bne`. The idiom picks the branch instruction. */
    for (i = 0x1C; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }
    return self;
}
