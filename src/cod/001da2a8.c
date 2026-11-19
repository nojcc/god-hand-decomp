/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/Poker.h"
#include "godhand/decCount.h"

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001DA2A8")))
void func_001DA2A8(Poker *self)
{

    switch (self->phase) {
    case 0:
        func_001DE858(self, 0xFF);
        self->timer = 1;
        self->phase += 1;
        break;
    case 1: {
        BlackJackCard **p;
        int i;
        if (DecCount(&self->timer) == 0) {
            break;
        }
        p = self->hand;
        for (i = 0; i < 5; i++) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, p[i]->obj, 0, 0, 0, 0);
        }
        self->unk302C = 0xF;
        self->phase += 1;
        break;
    }
    case 2: {
        BlackJackCard **p;
        cVec *q;
        int i;
        p = self->hand;
        q = D_00568170;
        for (i = 4; i >= 0; i--) {
            *(*p)->obj->pos =
                -((15.0f - (float)self->unk302C) / 15.0f) + q->x;
            p++;
            q++;
        }
        if (self->unk302C == 0) {
            self->phase += 1;
        } else {
            self->unk302C -= 1;
        }
        break;
    }
    case 3: {
        BlackJackCard **p;
        long fl;
        int i;
        p = self->hand;
        for (i = 4; i >= 0; i--) {
            (*p)->obj->flags |= 2;
            p++;
        }
        fl = (unsigned int)self->flags;
        if (((fl >> 2) & 1) == 1) {
            self->state = 0xC;
            self->flags &= -5;
            self->phase = 0;
        } else {
            func_001DD770(self, 2);
            func_001DD840(self, 2);
            func_001DD910(self, 2);
            func_001DD9E0(self, 2);
            self->timer = 0x1E;
            self->phase += 1;
        }
        break;
    }
    case 4: {
        if (DecCount(&self->timer) != 0) {
            self->state = 0;
            self->phase = 0;
        }
        break;
    }
    }
}
