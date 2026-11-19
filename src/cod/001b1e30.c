/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/Poker.h"
#include "godhand/cOm71.h"

extern float Adjust_theta(float);
extern int moveMotion(int *);
extern void cObjBase_addNullSpeed_Rotation(int *, float);
extern void cObjBase_addNullSpeed(int *, float);

__attribute__((section(".text.func_001D0CE8")))
void func_001D0CE8(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    if (((f >> 1) & 1) == 0) {
        if (((f >> 2) & 1) == 0) return;
        card->obj->rot.y += 0.15707963705062866f;
        card->obj->rot.y = Adjust_theta(card->obj->rot.y);
        if (0.0f <= card->obj->rot.y) {
            card->obj->rot.y = 0.0f;
            card->flags = (card->flags | 2) & -5;
        }
    }
}

__attribute__((section(".text.func_001D6E20")))
void func_001D6E20(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    if (((f >> 3) & 1) == 0) {
        if (((f >> 4) & 1) == 0) return;
        card->obj->rot.y += 0.20943951606750488f;
        card->obj->rot.y = Adjust_theta(card->obj->rot.y);
        if (0.0f <= card->obj->rot.y) {
            card->obj->rot.y = 0.0f;
            card->flags = (card->flags | 8) & -0x11;
        }
    }
}

__attribute__((section(".text.func_001D0DF8")))
void func_001D0DF8(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    if (((f >> 1) & 1) == 0) return;
    if (((f >> 2) & 1) == 0) return;
    card->obj->rot.y += 0.15707963705062866f;
    if (3.1415927410125732f <= card->obj->rot.y) {
        card->obj->rot.y = 3.1415927410125732f;
        card->flags &= -3;
        card->flags &= -5;
    }
    card->obj->rot.y = Adjust_theta(card->obj->rot.y);
}

__attribute__((section(".text.func_001D6F30")))
void func_001D6F30(BlackJackCard *card) {
    long f = (unsigned int)card->flags;
    if (((f >> 3) & 1) == 0) return;
    if (((f >> 4) & 1) == 0) return;
    card->obj->rot.y += 0.20943951606750488f;
    if (3.1415927410125732f <= card->obj->rot.y) {
        card->obj->rot.y = 3.1415927410125732f;
        card->flags &= -9;
        card->flags &= -0x11;
    }
    card->obj->rot.y = Adjust_theta(card->obj->rot.y);
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
    func_001DEE60(&self->ui, 0x11, 0);

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
