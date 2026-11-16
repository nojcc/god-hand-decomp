/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/BlackJack.h"

extern void cIDBase(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001D4D80")))
BlackJack *func_001D4D80(BlackJack *self) {
    CustomIDWork *q;
    int i;

    self->unk0000 = 0;
    cIDBase(&self->id);

    q = self->elem;
    /* `i != -1`, not `i >= 0`: retail materialises -1 in a register and closes
       this call-loop with `bne`. The idiom picks the branch instruction. */
    for (i = 0x2C; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }
    return self;
}
