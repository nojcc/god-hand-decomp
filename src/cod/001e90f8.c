/* sn-2.95.3-136 matched TU. */
#include "godhand/criStm.h"

extern void ClearFields00And30_1EE768(void *a0);
#include "godhand/DogRace.h"

__attribute__((section(".text.DogRace__ctor")))
DogRace *DogRace__ctor(DogRace *self) {
    int i;
    int j;
    DogRaceDog *q;
    DogRaceDog **r;
    int *s;

    func_003A52F0(self, 0, 0x54);
    self->unk54 = 0;

    q = self->dog;
    /* `j != -1`, not `j >= 0`: retail materialises -1 in a register and closes
       this loop with `bne`, where the zero-fill loops below use `bgez`. The
       idiom picks the branch instruction, so normalising it breaks the match. */
    for (j = 4; j != -1; j--) {
        ClearFields00And30_1EE768(q);
        q++;
    }

    func_001ECA80(&self->result);
    func_001ED548(&self->ui1);
    func_001EDE38(&self->ui2);

    self->cam = 0;
    self->unk1B0 = 0xFFFF;

    r = self->rank;
    s = &self->scroll[10];

    for (i = 9; i >= 0; i--) {
        self->scroll[i] = 0;
    }
    for (i = 4; i >= 0; i--) {
        r[i] = 0;
    }
    for (i = 4; i >= 0; i--) {
        s[i] = 0;
    }

    return self;
}
