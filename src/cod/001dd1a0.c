/* sn-2.95.3-136 matched TU. */
#include "godhand/Poker.h"

extern void CustomIDWork_Main(void *a0);

__attribute__((section(".text.func_001DD1A0")))
void func_001DD1A0(Poker *self) {
    CustomIDWork *q;
    int i;

    q = self->elem;
    for (i = 0x4C; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }
    cIDBase_move(&self->id);
}
