/* sn-2.95.3-136 matched TU. */
#include "godhand/ColiseumEmSelectFn.h"

extern void CustomIDWork_Main(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001F4700")))
void func_001F4700(ColiseumEmDisp *self) {
    CustomIDWork *q;
    int i;

    q = self->elem;
    /* `i >= 0`: retail closes this loop with `bgez` (not `bne`). The loop
       body carries a call, so ee-as omits the R5900 short-loop pad (one nop
       before the closing branch) → needs --call-loop-pad. */
    for (i = 0x6E; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }
    cIDBase_move(&self->id);
}
