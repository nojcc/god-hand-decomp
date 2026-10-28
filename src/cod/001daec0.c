/* sn-2.95.3-136 */
#include "godhand/Poker.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/gameWork.h"

#define PAD_CONFIRM      0x10000000L
#define PAD_CANCEL       0x20000000L
#define PAD_LEFT_RIGHT   0xCC0000C000000L
#define POKER_THROW_FRAMES 15
#define POKER_STATE_DOUBLE_UP 13
#define POKER_STATE_COLLECTED 0x14

/* Win stage: count the winnings up in tens, then offer the double-up
 * (choice 0) or take the money (choice 1). Taking it counts the winnings
 * into the gold total; doubling up throws the two cards off and starts the
 * double-up game. After two wins in a row the money is paid out without
 * the offer. Confirm or cancel skips a count. */
__attribute__((section(".text.func_001DAEC0")))
void func_001DAEC0(Poker *self)
{
    switch (self->phase) {
    case 0:
        self->unk3045++;
        self->timer = 30;
        self->phase++;
        break;
    case 1:
        if (Poker_tick(&self->timer)) {
            cSnd_SetBgmState(&D_005FEE00, 2);
            func_001DF528(POKER_UI(self), 0, 4);
            self->timer = 30;
            self->unk302C = self->bet / 10;
            self->phase++;
        }
        break;
    case 2:
        if (Poker_tick(&self->timer)) {
            if ((D_00747640 & (PAD_CONFIRM | PAD_CANCEL)) != 0 || self->unk302C == 0) {
                self->bet += self->unk302C * 10;
                func_001DEE40(POKER_UI(self), self->bet);
                if (self->unk3045 < 2) {
                    self->timer = 30;
                    self->phase++;
                } else {
                    self->payout = self->bet;
                    self->unk302C = self->bet / 10;
                    self->phase += 6;
                }
            } else {
                self->unk302C--;
                self->bet += 10;
                func_001DEE40(POKER_UI(self), self->bet);
            }
        }
        break;
    case 3:
        if (Poker_tick(&self->timer)) {
            self->choice = 0;
            UiRecord_setDispSubs6to10(POKER_UI(self), 1);
            func_001DF7D0(POKER_UI(self), 1);
            func_001DF820(POKER_UI(self), 1);
            self->timer = 5;
            self->phase++;
        }
        break;
    case 4:
        if (Poker_tick(&self->timer)) {
            self->phase++;
        }
        break;
    case 5:
        if (D_007474A0.rep & PAD_LEFT_RIGHT) {
            if (self->choice == 0) {
                self->choice = 1;
                func_001DF7D0(POKER_UI(self), 0);
            } else {
                self->choice = 0;
                func_001DF7D0(POKER_UI(self), 1);
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (D_007474A0.trg & PAD_CANCEL) {
            self->choice = 1;
            func_001DF7D0(POKER_UI(self), 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        } else if (D_007474A0.trg & PAD_CONFIRM) {
            if (self->choice == 0) {
                func_001DF528(POKER_UI(self), 0, 3);
                self->timer = 30;
                self->phase++;
            } else {
                self->payout = self->bet;
                self->unk302C = self->bet / 10;
                self->phase += 3;
            }
            UiRecord_setDispSubs6to10(POKER_UI(self), 0);
            func_001DF820(POKER_UI(self), 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        }
        break;
    case 6:
        if (Poker_tick(&self->timer)) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[0]->obj, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[1]->obj, 0, 0, 0, 0);
            self->unk302C = POKER_THROW_FRAMES;
            self->phase++;
        }
        break;
    case 7: {
        float slide = -((POKER_THROW_FRAMES - (float)self->unk302C) / POKER_THROW_FRAMES);

        self->hand[0]->obj->pos[0] = slide + D_005681C0[0][0];
        self->hand[1]->obj->pos[0] = slide + D_005681C0[1][0];
        if (self->unk302C == 0) {
            self->phase = 0;
            self->state = POKER_STATE_DOUBLE_UP;
        } else {
            self->unk302C--;
        }
        break;
    }
    case 8:
        if ((D_00747640 & (PAD_CONFIRM | PAD_CANCEL)) != 0 || self->unk302C == 0) {
            cCoreSave_addGold(&D_00569B70, self->unk302C * 10, 0);
            self->bet = 0;
            func_001DEE40(POKER_UI(self), 0);
            func_001DF528(POKER_UI(self), 0, 3);
            self->timer = 30;
            self->phase++;
        } else {
            self->unk302C--;
            cCoreSave_addGold(&D_00569B70, 10, 0);
            self->bet -= 10;
            func_001DEE40(POKER_UI(self), self->bet);
        }
        break;
    case 9:
        if (Poker_tick(&self->timer)) {
            self->phase = 0;
            self->state = POKER_STATE_COLLECTED;
        }
        break;
    }
}
