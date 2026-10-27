/* sn-2.95.3-136 */
#include "godhand/Poker.h"
#include "godhand/cSnd.h"
#include "include_asm.h"

#define POKER_STEP_WAIT     30          /* frames before the card is drawn and before it turns */
#define POKER_FLAG_RIGGED   0x10        /* Poker.flags: the double-up card is chosen, not drawn */
#define POKER_STATE_DOUBLE  0x10

/* Double-up draw: wait, draw the second card (when rigged, a card of a
 * random suit below or above the first card's rank, as the player did not
 * guess), fly it into the second slot, turn it over and go on to the
 * double-up result once it is shown.
 * Differs from retail in one constant: retail clears the drawn card's
 * out-of-deck bit with addiu -2 (a signed flags word), the unsigned
 * BlackJackCard.flags gives lui/ori 0xFFFFFFFE. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_001DAB00")))
void func_001DAB00(Poker *self)
{
    switch (self->phase) {
    case 0:
        self->timer = POKER_STEP_WAIT;
        self->phase++;
        break;
    case 1:
        if (Poker_tick(&self->timer)) {
            long f = (unsigned int)self->flags;
            long rigged = f >> 4 & 1;

            if (rigged) {
                unsigned short rank = self->hand[0]->obj->rank;
                unsigned short id;
                BlackJackCard *card;

                if (self->cursorOn) {
                    id = (unsigned short)Casino_randRange(self, 0, POKER_SUIT_NUM - 1) * POKER_RANK_NUM
                       + Casino_randRange(self, 1, rank - 1);
                } else {
                    id = (unsigned short)Casino_randRange(self, 0, POKER_SUIT_NUM - 1) * POKER_RANK_NUM
                       + Casino_randRange(self, rank + 1, POKER_RANK_NUM - 1);
                }
                card = &self->deck[id];
                self->hand[1] = card;
                card->flags &= ~1;
            } else {
                func_001DBE18(self, &self->hand[1]);
            }
            func_001D6EC8(self->hand[1], 0);
            self->hand[1]->obj->flags |= 2;
            Poker_placeCard(self->hand[1]->obj, D_00568160);
            self->phase++;
        }
        break;
    case 2:
        self->hand[1]->obj->flags &= 0xFFFFFFFD;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[1]->obj, 0, 0, 0, 0);
        self->unk302C = POKER_DEAL_FRAMES;
        self->phase++;
        break;
    case 3: {
        float t = (POKER_DEAL_FRAMES - (float)self->unk302C) / POKER_DEAL_FRAMES;
        float x = t * (D_005681C0[1][0] - D_00568160[0]) + D_00568160[0];
        float y = t * (D_005681C0[1][1] - D_00568160[1]) + D_00568160[1];

        self->hand[1]->obj->pos[0] = x;
        self->hand[1]->obj->pos[1] = y;
        if (self->unk302C == 0) {
            self->timer = POKER_STEP_WAIT;
            self->phase++;
        } else {
            self->unk302C--;
        }
        break;
    }
    case 4:
        if (Poker_tick(&self->timer)) {
            func_001D6DD0(self->hand[1], 1);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, self->hand[1]->obj, 0, 0, 0, 0);
            self->phase++;
        }
        break;
    case 5: {
        long f = self->hand[1]->flags;
        long shown = f >> 3 & 1;

        if (shown) {
            SetField_56_1DEBE8(self, 6);
            self->phase = 0;
            self->state = POKER_STATE_DOUBLE;
        }
        break;
    }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001DAB00);
#endif
