/* sn-2.95.3-136 */
#include "godhand/Poker.h"
#include "godhand/cSnd.h"

#define POKER_THROW_FRAMES 15           /* frames the thrown-away cards take to leave */
#define POKER_STATE_RESULT 8

/* Draw stage: the cards not held (BlackJackCard.flags bit 1 clear) slide
 * off, new cards are drawn into their slots and fly in one after another,
 * then all five turn over and the table goes on to the result once every
 * card is shown. */
__attribute__((section(".text.func_001D94D0")))
void func_001D94D0(Poker *self)
{
    switch (self->phase) {
    case 0:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[0]->obj, 0, 0, 0, 0);
        self->unk302C = POKER_THROW_FRAMES;
        self->phase++;
        break;
    case 1: {
        int i;

        for (i = 0; i < POKER_HAND_NUM; i++) {
            long held = self->hand[i]->flags;

            if ((held >> 1 & 1) == 0) {
                self->hand[i]->obj->pos[0] =
                    -((POKER_THROW_FRAMES - (float)self->unk302C) / POKER_THROW_FRAMES) + D_00568170[i][0];
            }
        }
        if (self->unk302C == 0) {
            self->phase++;
        } else {
            self->unk302C--;
        }
        break;
    }
    case 2: {
        int i;

        for (i = 0; i < POKER_HAND_NUM; i++) {
            long held = self->hand[i]->flags;

            if ((held >> 1 & 1) == 0) {
                func_001DBE18(self, &self->hand[i]);
                func_001D6EC8(self->hand[i], 0);
                self->hand[i]->obj->flags |= 2;
                Poker_placeCard(self->hand[i]->obj, D_00568160);
            }
        }
        SetField_56_1DEBE8(self, 0);
        self->phase++;
        break;
    }
    case 3: {
        long held = self->hand[0]->flags;

        if ((held >> 1 & 1) == 0) {
            self->hand[0]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[0]->obj, 0, 0, 0, 0);
        }
        self->unk302C = POKER_DEAL_FRAMES;
        self->phase++;
        break;
    }
    case 4: {
        long held = self->hand[0]->flags;

        if ((held >> 1 & 1) == 0) {
            Poker_moveCard(self, 0);
            if (self->unk302C == 0) {
                self->phase++;
            } else {
                self->unk302C--;
            }
        } else {
            self->phase++;
        }
        break;
    }
    case 5: {
        long held = self->hand[1]->flags;

        if ((held >> 1 & 1) == 0) {
            self->hand[1]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[1]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
        }
        self->phase++;
        break;
    }
    case 6: {
        long held = self->hand[1]->flags;

        if ((held >> 1 & 1) == 0) {
            Poker_moveCard(self, 1);
            if (self->unk302C == 0) {
                self->phase++;
            } else {
                self->unk302C--;
            }
        } else {
            self->phase++;
        }
        break;
    }
    case 7: {
        long held = self->hand[2]->flags;

        if ((held >> 1 & 1) == 0) {
            self->hand[2]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[2]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
        }
        self->phase++;
        break;
    }
    case 8: {
        long held = self->hand[2]->flags;

        if ((held >> 1 & 1) == 0) {
            Poker_moveCard(self, 2);
            if (self->unk302C == 0) {
                self->phase++;
            } else {
                self->unk302C--;
            }
        } else {
            self->phase++;
        }
        break;
    }
    case 9: {
        long held = self->hand[3]->flags;

        if ((held >> 1 & 1) == 0) {
            self->hand[3]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[3]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
        }
        self->phase++;
        break;
    }
    case 10: {
        long held = self->hand[3]->flags;

        if ((held >> 1 & 1) == 0) {
            Poker_moveCard(self, 3);
            if (self->unk302C == 0) {
                self->phase++;
            } else {
                self->unk302C--;
            }
        } else {
            self->phase++;
        }
        break;
    }
    case 11: {
        long held = self->hand[4]->flags;

        if ((held >> 1 & 1) == 0) {
            self->hand[4]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[4]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
        }
        self->phase++;
        break;
    }
    case 12: {
        long held = self->hand[4]->flags;

        if ((held >> 1 & 1) == 0) {
            Poker_moveCard(self, 4);
            if (self->unk302C == 0) {
                self->unk302C = POKER_DEAL_FRAMES;
                self->phase++;
            } else {
                self->unk302C--;
            }
        } else {
            self->phase++;
        }
        break;
    }
    case 13: {
        int i;

        for (i = 0; i < POKER_HAND_NUM; i++) {
            long held = self->hand[i]->flags;

            if ((held >> 1 & 1) == 0) {
                func_001D6DD0(self->hand[i], 1);
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, self->hand[i]->obj, 0, 0, 0, 0);
        }
        self->phase++;
        break;
    }
    case 14: {
        long shown = self->hand[0]->flags;

        if ((shown >> 3 & 1) == 0) {
            break;
        }
        shown = self->hand[1]->flags;
        if ((shown >> 3 & 1) == 0) {
            break;
        }
        shown = self->hand[2]->flags;
        if ((shown >> 3 & 1) == 0) {
            break;
        }
        shown = self->hand[3]->flags;
        if ((shown >> 3 & 1) == 0) {
            break;
        }
        shown = self->hand[4]->flags;
        if ((shown >> 3 & 1) == 0) {
            break;
        }
        SetField_56_1DEBE8(self, 6);
        self->phase = 0;
        self->state = POKER_STATE_RESULT;
        break;
    }
    }
}
