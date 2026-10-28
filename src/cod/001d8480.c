/* sn-2.95.3-136 */
#include "godhand/Poker.h"
#include "godhand/cSnd.h"
#include "godhand/gameWork.h"

#define POKER_STATE_DRAW  6
#define POKER_DEBUG_HAND  0x200         /* D_00747A2C.unk00: deal the hand set in cardId */

/* Deal stage: draw a new hand (or the debug hand from cardId), fly the five
 * cards from the deck to their slots one after another, turn them over and
 * go on to the draw state once all five are shown. */
__attribute__((section(".text.func_001D8480")))
void func_001D8480(Poker *self)
{
    switch (self->phase) {
    case 0:
        Poker_resetDeck(self);
        func_001DBE18(self, &self->hand[0]);
        func_001DBE18(self, &self->hand[1]);
        func_001DBE18(self, &self->hand[2]);
        func_001DBE18(self, &self->hand[3]);
        func_001DBE18(self, &self->hand[4]);
        if (D_00747A2C.unk00 & POKER_DEBUG_HAND) {
            int i;

            for (i = 0; i < POKER_HAND_NUM; i++) {
                if (self->cardId[i] != POKER_CARD_NONE) {
                    self->hand[i] = &self->deck[self->cardId[i]];
                }
            }
        }
        func_001D6EC8(self->hand[0], 0);
        func_001D6EC8(self->hand[1], 0);
        func_001D6EC8(self->hand[2], 0);
        func_001D6EC8(self->hand[3], 0);
        func_001D6EC8(self->hand[4], 0);
        Poker_placeCard(self->hand[0]->obj, D_00568160);
        Poker_placeCard(self->hand[1]->obj, D_00568160);
        Poker_placeCard(self->hand[2]->obj, D_00568160);
        Poker_placeCard(self->hand[3]->obj, D_00568160);
        Poker_placeCard(self->hand[4]->obj, D_00568160);
        SetField_56_1DEBE8(self, 0);
        self->phase++;
        break;
    case 1:
        self->hand[0]->obj->flags &= 0xFFFFFFFD;
        self->unk302C = POKER_DEAL_FRAMES;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[0]->obj, 0, 0, 0, 0);
        self->phase++;
        break;
    case 2:
        Poker_moveCard(self, 0);
        if (self->unk302C != 0) {
            self->unk302C--;
        } else {
            self->hand[1]->obj->flags &= 0xFFFFFFFD;
            self->unk302C = POKER_DEAL_FRAMES;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[1]->obj, 0, 0, 0, 0);
            self->phase++;
        }
        break;
    case 3:
        Poker_moveCard(self, 1);
        if (self->unk302C != 0) {
            self->unk302C--;
        } else {
            /* from the third card on, retail restarts the timer after the sound */
            self->hand[2]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[2]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
            self->phase++;
        }
        break;
    case 4:
        Poker_moveCard(self, 2);
        if (self->unk302C != 0) {
            self->unk302C--;
        } else {
            self->hand[3]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[3]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
            self->phase++;
        }
        break;
    case 5:
        Poker_moveCard(self, 3);
        if (self->unk302C != 0) {
            self->unk302C--;
        } else {
            self->hand[4]->obj->flags &= 0xFFFFFFFD;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[4]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_DEAL_FRAMES;
            self->phase++;
        }
        break;
    case 6:
        Poker_moveCard(self, 4);
        if (self->unk302C != 0) {
            self->unk302C--;
        } else {
            self->phase++;
        }
        break;
    case 7: {
        int i;

        for (i = 0; i < POKER_HAND_NUM; i++) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, self->hand[i]->obj, 0, 0, 0, 0);
            func_001D6DD0(self->hand[i], 1);
        }
        self->phase++;
        break;
    }
    case 8: {
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
        self->phase++;
        break;
    }
    case 9:
        SetField_56_1DEBE8(self, POKER_STATE_DRAW);
        self->phase = 0;
        self->state = POKER_STATE_DRAW;
        break;
    }
}
