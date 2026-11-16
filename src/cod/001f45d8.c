/* sn-2.95.3-136 matched TU. */
#include "godhand/ColiseumEmSelect.h"

extern void cIDBase(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001F45D8")))
ColiseumEmDisp *func_001F45D8(ColiseumEmDisp *self) {
    CustomIDWork *q;
    int i;

    self->unk000 = 0;
    cIDBase(&self->id);

    q = self->elem;
    /* `!= -1`, not `>= 0`: retail materialises -1 and closes with `bne`. */
    for (i = 0x6E; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }
    return self;
}
