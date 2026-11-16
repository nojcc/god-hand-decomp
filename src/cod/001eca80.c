/* sn-2.95.3-136 matched TU. */
#include "godhand/DogRace.h"

extern void cIDBase(void *a0);

/* Clear the flags, construct the ID base and the 45 elements; returns self. */
__attribute__((section(".text.func_001ECA80")))
DogRaceResult *func_001ECA80(DogRaceResult *self) {
    CustomIDWork *q;
    int i;

    self->flags = 0;
    cIDBase(&self->id);

    q = self->elem;
    /* `i != -1`, not `i >= 0`: retail materialises -1 in a register and closes
       this call-loop with `bne`. The idiom picks the branch instruction. */
    for (i = DOGRACE_RESULT_ELEM_NUM - 1; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }
    return self;
}
