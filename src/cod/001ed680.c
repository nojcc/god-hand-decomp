/* sn-2.95.3-136 matched TU. */
#include "godhand/DogRace.h"

extern void CustomIDWork_Main(void *a0);

__attribute__((section(".text.func_001ED680")))
void func_001ED680(DogRaceUi *self) {
    CustomIDWork *p;
    int i;

    func_001ED848(self);
    p = self->elem;
    for (i = 5; i >= 0; i--) {
        CustomIDWork_Main(p);
        p++;
    }
    cIDBase_move(&self->id);
}
