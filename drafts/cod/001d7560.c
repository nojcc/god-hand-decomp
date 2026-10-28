/* sn-2.95.3-136 */
/* func_001D7560 (as: sn). Eleven instructions differ, all in the three
 * payouts that compile to movz (x8, x8, x2): retail loads the bet into $v0
 * and the constant into $v1, this the other way round. The two declarations
 * below differ from their definitions: SetBlendField1D4_1DDB10 is defined
 * with a third int its callers never pass, NoOp_1DCE60 as (void) though its
 * callers pass self. */
#include "include_asm.h"
#include "godhand/Poker.h"
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"

#ifdef NON_MATCHING
#define POKER_KEY_HELP   0x0000080000000000L  /* toggles the payout help */
#define POKER_KEY_DEAL   0x000CC0000C000000L  /* up/down (pad and stick) */
#define POKER_KEY_LEVEL  0x0003300003000000L  /* left/right (pad and stick) */
#define POKER_KEY_OK     0x10000000L
#define POKER_KEY_BACK   0x20000000L

#define POKER_HELP_ON    0x2                  /* Poker.flags: the help page is up */
#define POKER_BET_NEW    0x8                  /* Poker.flags: nothing bet yet this round */
#define POKER_BET_STEP   100
#define GAMESYS_HELP_OK  0x200                /* GameSys.unk00: the help page may open */

#define POKER_SE_MOVE    0x15F
#define POKER_SE_OK      0x15E
#define POKER_SE_BACK    0x161

extern void func_001DD770(void *a0, unsigned char a1);
extern void SetBlendField1D4_1DDB10(void *self, int on);
extern void NoOp_1DCE60(void *self);
extern void CustomIDWork_SetNumber_1DD218(void *a0, int a1);
extern void func_001DD910(void *a0, unsigned char a1);
extern void func_001DD5A0(int a0, int a1);
extern void func_001DD840(void *a0, unsigned char a1);
extern int SetCustomIDNumberIndexed_1DD648(int a0, unsigned int a1, int a2);

/* Move to a state and restart its phase. */
static __inline__ void Poker_setState(Poker *self, int state)
{
    self->phase = 0;
    self->state = state;
}

/* Betting step of the poker table: raise or lower the bet in steps of 100
 * gold, leave for the deal or the level pick, toggle the help page, and show
 * each hand's payout for the current bet. */
__attribute__((section(".text.func_001D7560")))
void func_001D7560(Poker *self)
{
    GameSys *sys;
    long flags;
    long bit;

    switch (self->phase) {
    case 0:
        func_001DD770(self, 0);
        SetBlendField1D4_1DDB10(self, 1);
        self->phase++;
    case 1:
        sys = &D_00747A2C;
        /* The game work D_007474A0 is D_00747A2C - 0x58C: retail forms it that way. */
        if ((sys->unk00 & GAMESYS_HELP_OK)
            && (((GameWork *)((char *)sys - 0x58C))->trg & POKER_KEY_HELP)) {
            flags = (unsigned int)self->flags;
            bit = flags >> 1 & 1;
            if (bit)
                self->flags &= ~POKER_HELP_ON;
            else
                self->flags |= POKER_HELP_ON;
        }
        flags = (unsigned int)self->flags;
        bit = flags >> 1 & 1;
        if (bit) {
            NoOp_1DCE60(self);
        } else if (D_007474A0.rep & POKER_KEY_DEAL) {
            func_001DD770(self, 1);
            SetBlendField1D4_1DDB10(self, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, POKER_SE_MOVE, -1, -1, 0, 0);
            if (self->bet != 0)
                Poker_setState(self, 3);
            else
                Poker_setState(self, 4);
        } else if (D_007474A0.rep & POKER_KEY_LEVEL) {
            func_001DD770(self, 1);
            SetBlendField1D4_1DDB10(self, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, POKER_SE_MOVE, -1, -1, 0, 0);
            Poker_setState(self, 2);
        } else if (D_007474A0.trg & POKER_KEY_OK) {
            if (self->bet < self->betMax && cCoreSave_getGold(&D_00569B70) >= POKER_BET_STEP) {
                cCoreSave_subGold(&D_00569B70, POKER_BET_STEP);
                self->bet += POKER_BET_STEP;
                CustomIDWork_SetNumber_1DD218(self, self->bet);
                func_001DD910(self, 1);
                func_001DD5A0((int)self, 0);
                if (self->bet >= self->betMax) {
                    func_001DD770(self, 2);
                    SetBlendField1D4_1DDB10(self, 0);
                    func_001DD840(self, 2);
                    Poker_setState(self, 3);
                }
                self->flags &= ~POKER_BET_NEW;
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, POKER_SE_OK, -1, -1, 0, 0);
        } else if (D_007474A0.trg & POKER_KEY_BACK) {
            if (self->bet > 0) {
                cCoreSave_addGold(&D_00569B70, POKER_BET_STEP, 0);
                self->bet -= POKER_BET_STEP;
                CustomIDWork_SetNumber_1DD218(self, self->bet);
                if (self->bet == 0) {
                    func_001DD910(self, 2);
                    func_001DD5A0((int)self, 1);
                }
            } else {
                func_001DD770(self, 1);
                SetBlendField1D4_1DDB10(self, 0);
                Poker_setState(self, 4);
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, POKER_SE_BACK, -1, -1, 0, 0);
        }
        break;
    }
    SetCustomIDNumberIndexed_1DD648((int)self, 0, self->bet ? self->bet * 50 : 50);
    SetCustomIDNumberIndexed_1DD648((int)self, 1, self->bet ? self->bet * 20 : 20);
    SetCustomIDNumberIndexed_1DD648((int)self, 2, self->bet ? self->bet * 15 : 15);
    SetCustomIDNumberIndexed_1DD648((int)self, 3, self->bet ? self->bet * 10 : 10);
    SetCustomIDNumberIndexed_1DD648((int)self, 4, self->bet ? self->bet * 8 : 8);
    SetCustomIDNumberIndexed_1DD648((int)self, 5, self->bet ? self->bet * 8 : 8);
    SetCustomIDNumberIndexed_1DD648((int)self, 6, self->bet ? self->bet * 3 : 3);
    SetCustomIDNumberIndexed_1DD648((int)self, 7, self->bet ? self->bet * 2 : 2);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001D7560);
#endif
