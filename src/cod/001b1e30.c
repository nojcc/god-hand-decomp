/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/Poker.h"
#include "godhand/cOm71.h"

/* The card's heading: y of its rotation (0x100), 0 face up and pi face down.
 * BlackJack.h names that word unk104 as an int, so it is read here as a float. */
#define CARD_ROT_Y(card) (*(float *)&(card)->obj->unk104)

extern float Adjust_theta(float);
extern int moveMotion(int *);
extern void cObjBase_addNullSpeed_Rotation(int *, float);
extern void cObjBase_addNullSpeed(int *, float);
extern void Poker_resetDeck(Poker *self);
extern void func_001DD340(Poker *self);
extern void func_001DEE60(char *ui, int element, int show);

__attribute__((section(".text.func_001D0CE8")))
void func_001D0CE8(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    int fl;
    if (((f >> 1) & 1) == 0) {
        if (((f >> 2) & 1) == 0) return;
        CARD_ROT_Y(card) += 0.15707963705062866f;
        CARD_ROT_Y(card) = Adjust_theta(CARD_ROT_Y(card));
        if (0.0f <= CARD_ROT_Y(card)) {
            CARD_ROT_Y(card) = 0.0f;
            fl = card->flags;
            card->flags = (fl | 2) & -5;
        }
    }
}

__attribute__((section(".text.func_001D6E20")))
void func_001D6E20(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    int fl;
    if (((f >> 3) & 1) == 0) {
        if (((f >> 4) & 1) == 0) return;
        CARD_ROT_Y(card) += 0.20943951606750488f;
        CARD_ROT_Y(card) = Adjust_theta(CARD_ROT_Y(card));
        if (0.0f <= CARD_ROT_Y(card)) {
            CARD_ROT_Y(card) = 0.0f;
            fl = card->flags;
            card->flags = (fl | 8) & -0x11;
        }
    }
}

__attribute__((section(".text.func_001D0DF8")))
void func_001D0DF8(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    int fl;
    if (((f >> 1) & 1) == 0) return;
    if (((f >> 2) & 1) == 0) return;
    CARD_ROT_Y(card) += 0.15707963705062866f;
    if (3.1415927410125732f <= CARD_ROT_Y(card)) {
        CARD_ROT_Y(card) = 3.1415927410125732f;
        fl = card->flags;
        card->flags = fl & -3;
        fl = card->flags;
        card->flags = fl & -5;
    }
    CARD_ROT_Y(card) = Adjust_theta(CARD_ROT_Y(card));
}

__attribute__((section(".text.func_001D6F30")))
void func_001D6F30(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    int fl;
    if (((f >> 3) & 1) == 0) return;
    if (((f >> 4) & 1) == 0) return;
    CARD_ROT_Y(card) += 0.20943951606750488f;
    if (3.1415927410125732f <= CARD_ROT_Y(card)) {
        CARD_ROT_Y(card) = 3.1415927410125732f;
        fl = card->flags;
        card->flags = fl & -9;
        fl = card->flags;
        card->flags = fl & -0x11;
    }
    CARD_ROT_Y(card) = Adjust_theta(CARD_ROT_Y(card));
}

__attribute__((section(".text.func_001B1E30")))
void func_001B1E30(int *a0) {
    int *s0 = a0;
    long m;
    *(int *)((char *)s0 + 0x600) &= -0x101;
    if (moveMotion(s0) != 0) {
        m = *(unsigned int *)((char *)s0 + 0x600);
        if (((m >> 3) & 1) == 0) goto L88;
        *(int *)((char *)s0 + 0x600) &= -9;
        cOm71_SetMotionRun(s0);
    L88:
        *(int *)((char *)s0 + 0x600) |= 0x100;
    }
    cObjBase_addNullSpeed_Rotation(s0, 1.0f);
    m = *(unsigned int *)((char *)s0 + 0x600);
    if (((m >> 7) & 1) == 0) {
        cObjBase_addNullSpeed(s0, 1.0f);
    }
}

__attribute__((section(".text.func_001D7450")))
void func_001D7450(Poker *self)
{
    long v;

    self->bet = 0;
    self->payout = 0;
    Poker_resetDeck(self);
    func_001DD340(self);
    CustomIDWork_SetNumber_1DD218(self, self->bet);
    func_001DD238(self, cCoreSave_getGold(&D_00569B70));
    SetCustomIDNumberIndexed_1DD648(self, 0, 0x32);
    SetCustomIDNumberIndexed_1DD648(self, 1, 0x14);
    SetCustomIDNumberIndexed_1DD648(self, 2, 0xF);
    SetCustomIDNumberIndexed_1DD648(self, 3, 0xA);
    SetCustomIDNumberIndexed_1DD648(self, 4, 8);
    SetCustomIDNumberIndexed_1DD648(self, 5, 8);
    SetCustomIDNumberIndexed_1DD648(self, 6, 3);
    SetCustomIDNumberIndexed_1DD648(self, 7, 2);
    func_001DEE60(POKER_UI(self), 0x11, 0);

    v = (unsigned int)self->flags;
    if (((v >> 3) & 1) == 0) {
        self->phase = 0;
        self->state = 1;
    } else {
        self->phase = 0;
        self->state = 2;
    }
    self->flags = 0;
}
