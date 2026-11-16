/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/Poker.h"

extern void func_001DBE18(void *a0, void *a1);

static __inline__ unsigned char TickDown(int *p) {
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

/* Poker deal-one-card step machine: double the payout and reset the deck, deal a card face up and slide it
 * from the deck to the two-card row, turn it over, wait for it to face up, then go to state 14. */
__attribute__((section(".text.func_001DA670")))
void func_001DA670(Poker *self) {
    unsigned char ok;

    switch (self->phase) {
    case 0:
        self->payout = self->payout * 2;
        Poker_resetDeck(self);
        self->timer = 30;
        self->phase = self->phase + 1;
        break;
    case 1:
        ok = TickDown(&self->timer);
        if (ok) {
            self->flags = self->flags & ~0x10;
            func_001DBE18(self, &self->hand[0]);
            func_001D6EC8(self->hand[0], 0);
            self->hand[0]->obj->flags = self->hand[0]->obj->flags | 2;
            self->hand[0]->obj->vtbl[14].pfn((char *)self->hand[0]->obj + self->hand[0]->obj->vtbl[14].delta, &D_00568160.x);
            self->phase = self->phase + 1;
        }
        break;
    case 2:
        self->hand[0]->obj->flags = self->hand[0]->obj->flags & ~2;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[0]->obj, 0, 0, 0, 0);
        SetField_56_1DEBE8(self, 0);
        self->unk302C = 10;
        self->phase = self->phase + 1;
        break;
    case 3:
        {
        float t = (10.0f - (float)self->unk302C) / 10.0f;
        float r0;
        float r1;
        int n;
        r0 = t * (D_005681C0[0].x - D_00568160.x) + D_00568160.x;
        r1 = t * (D_005681C0[0].y - D_00568160.y) + D_00568160.y;
        self->hand[0]->obj->pos[0] = r0;
        self->hand[0]->obj->pos[1] = r1;
        n = self->unk302C;
        if (n == 0) {
            self->timer = 30;
            self->phase = self->phase + 1;
        } else {
            self->unk302C = n - 1;
        }
        }
        break;
    case 4:
        ok = TickDown(&self->timer);
        if (ok) {
            func_001D6DD0(self->hand[0], 1);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, self->hand[0]->obj, 0, 0, 0, 0);
            self->phase = self->phase + 1;
        }
        break;
    case 5:
        {
        long f = (unsigned int)self->hand[0]->flags;
        if (((f >> 3) & 1) == 1) {
            self->phase = self->phase + 1;
        }
        }
        break;
    case 6:
        self->phase = 0;
        self->state = 14;
        break;
    }
}
