/* sn-2.95.3-136 matched TU. */
#include "godhand/DogRace.h"

extern void CustomIDWork_Main(CustomIDWork *cw);

/* Run the 45 elements, then move the ID base. */
__attribute__((section(".text.func_001ECBF0")))
void func_001ECBF0(DogRaceResult *self) {
    CustomIDWork *q;
    int i;

    q = self->elem;
    /* `i >= 0`: retail closes this loop with `bgez` (not `bne`). The loop
       body carries a call, so ee-as omits the R5900 short-loop pad (one nop
       before the closing branch) → needs --call-loop-pad. */
    for (i = DOGRACE_RESULT_ELEM_NUM - 1; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }
    cIDBase_move(&self->id);
}
