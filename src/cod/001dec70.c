/* sn-2.95.3-136 matched TU. */
#include "godhand/PanelObj.h"

extern void cIDBase(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DEC70")))
PanelObj *func_001DEC70(PanelObj *self) {
    CustomIDWork *q;
    int i;

    self->unk00 = 0;
    cIDBase(&self->id);

    q = self->elem;
    /* `i != -1`, not `i >= 0`: retail materialises -1 in a register and closes
       this call-loop with `bne`. The idiom picks the branch instruction. */
    for (i = 0x10; i != -1; i--) {
        CustomIDWork__ctor(q);
        q++;
    }
    return self;
}
