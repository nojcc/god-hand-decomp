/* sn-2.95.3-136 matched TU. */
#include "godhand/SlotUi.h"

extern void CustomIDWork_Main(void *a0);

/* Run the bet marks, their display, the marks and the main display one frame. */
__attribute__((section(".text.func_001E73C0")))
void func_001E73C0(SlotUi *self) {
    CustomIDWork *q;
    int i;

    q = self->bet;
    for (i = 1; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }

    cIDBase_move(&self->id2);

    q = self->mark;
    for (i = 9; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }

    cIDBase_move(&self->id);
}
