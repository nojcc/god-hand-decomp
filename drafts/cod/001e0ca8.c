/* sn-2.95.3-136 (as sn) */
#include "include_asm.h"
/* NON_MATCHING: 970 words against retail's 1033. Retail tests each symbol
 * against 6 and 7 with xori/beqz on the loaded value and never merges the two
 * tests into a range check; here the constants sit in registers, and the
 * one-reel-stopped tails don't cross-jump the way retail's do. */
#include "godhand/Slot1.h"
#include "godhand/MarkPanel.h"
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/rand.h"
#include "godhand/menuKey.h"

#ifdef NON_MATCHING

#define SLOT1_KEY_STOP0     0x400000000L /* the face button that stops reel 0 */
#define SLOT1_KEY_STOP1     0x100000000L
#define SLOT1_KEY_STOP2     0x800000000L
#define SLOT1_F_STOP0       0x20        /* endFlag: reel 0 was stopped */
#define SLOT1_F_STOP1       0x40
#define SLOT1_F_STOP2       0x80
#define SLOT1_REEL_STOP     4           /* reel state that runs the stop */

/* Symbols 6 and 7 never count toward a line. */
static __inline__ unsigned char Slot1_isLineSym(const int *sym)
{
    if (*sym == 6)
        return 0;
    return *sym != 7;
}

/* Both symbols count toward a line and are the same. */
static __inline__ unsigned char Slot1_isLinePair(const int *a, const int *b)
{
    unsigned char same = 0;

    if (*a != 6) {
        if (*a != 7 && *b != 6 && *b != 7)
            same = *a == *b;
    }
    return same;
}

/* Reel n still spins (doneFlag bit 1). */
static __inline__ long Slot1_reelSpins(Slot1 *self, int n)
{
    long done = (unsigned int)self->reel[n].doneFlag;

    return done >> 1 & 1;
}

/* Reel n has settled (doneFlag bit 2). */
static __inline__ long Slot1_reelSettled(Slot1 *self, int n)
{
    long done = (unsigned int)self->reel[n].doneFlag;

    return done >> 2 & 1;
}

/* Reel n was already stopped this spin (endFlag bit 5 + n). */
static __inline__ long Slot1_reelStopped(Slot1 *self, int n)
{
    long f = (unsigned int)self->endFlag;

    return f >> (5 + n) & 1;
}

/* Start reel n's stop if it is still spinning. */
static __inline__ void Slot1_stopReel(Slot1 *self, int n)
{
    if (Slot1_reelSpins(self, n)) {
        self->reel[n].phase = 0;
        self->reel[n].state = SLOT1_REEL_STOP;
        self->reel[n].step = 0;
    }
}

/* Slot1 spin stage: show the three marks, then wait for the three stop
 * buttons. A stopped reel sets its rows to the payout mode from the reels
 * already standing (at random when none is), records the symbol the other
 * two already show on each line, starts its stop and plays the button
 * sound. Once all three reels have settled the lever sound stops and the
 * stage ends. */
__attribute__((section(".text.func_001E0CA8")))
void func_001E0CA8(Slot1 *self)
{

    switch (self->step) {
    case 0:
        self->endFlag &= ~SLOT1_F_STOP0;
        self->endFlag &= ~SLOT1_F_STOP1;
        self->endFlag &= ~SLOT1_F_STOP2;
        MarkPanel_setMark((MarkPanel *)self, 0, 1, 1);
        MarkPanel_setMark((MarkPanel *)self, 1, 1, 1);
        MarkPanel_setMark((MarkPanel *)self, 2, 1, 1);
        self->step++;
    case 1:
        if ((D_007474A0.trg & SLOT1_KEY_STOP0) && Slot1_reelSpins(self, 0)) {
            if (!Slot1_reelStopped(self, 1) && !Slot1_reelStopped(self, 2)) {
                switch ((unsigned int)irand() % 3) {
                case 0:
                default:
                    self->reel[0].unkC4[0] = self->payMode;
                    break;
                case 1:
                    self->reel[0].unkC4[2] = self->payMode;
                    self->reel[0].unkC4[0] = self->payMode;
                    break;
                case 2:
                    self->reel[0].unkC4[2] = self->payMode;
                    self->reel[0].unkC4[0] = self->payMode;
                    self->reel[0].unkC4[1] = self->payMode;
                    break;
                }
            } else if (Slot1_reelStopped(self, 1) && !Slot1_reelStopped(self, 2)) {
                if (self->reel[1].sym[0] == self->payMode) {
                    self->reel[0].unkC4[0] = self->payMode;
                } else if (self->reel[1].sym[1] == self->payMode) {
                    self->reel[0].unkC4[2] = self->payMode;
                    self->reel[0].unkC4[0] = self->payMode;
                    self->reel[0].unkC4[1] = self->payMode;
                } else if (self->reel[1].sym[2] == self->payMode) {
                    self->reel[0].unkC4[2] = self->payMode;
                }
            } else if (!Slot1_reelStopped(self, 1) && Slot1_reelStopped(self, 2)) {
                if (self->reel[2].sym[0] == self->payMode) {
                    self->reel[0].unkC4[2] = self->payMode;
                    self->reel[0].unkC4[0] = self->payMode;
                } else if (self->reel[2].sym[1] == self->payMode) {
                    self->reel[0].unkC4[1] = self->payMode;
                } else if (self->reel[2].sym[2] == self->payMode) {
                    self->reel[0].unkC4[2] = self->payMode;
                    self->reel[0].unkC4[0] = self->payMode;
                }
            } else if (Slot1_reelStopped(self, 1) && Slot1_reelStopped(self, 2)) {
                if (self->payMode == SLOT1_PAYMODE_ON) {
                    if (Slot1_isLinePair(&self->reel[1].sym[0], &self->reel[2].sym[0]))
                        self->reel[0].lineSym[0] = self->reel[1].sym[0];
                    if (Slot1_isLinePair(&self->reel[1].sym[1], &self->reel[2].sym[2]))
                        self->reel[0].lineSym[1] = self->reel[1].sym[1];
                    if (Slot1_isLinePair(&self->reel[1].sym[1], &self->reel[2].sym[1]))
                        self->reel[0].lineSym[3] = self->reel[1].sym[1];
                    if (Slot1_isLinePair(&self->reel[1].sym[2], &self->reel[2].sym[2]))
                        self->reel[0].lineSym[6] = self->reel[1].sym[2];
                    if (Slot1_isLinePair(&self->reel[1].sym[1], &self->reel[2].sym[0]))
                        self->reel[0].lineSym[7] = self->reel[1].sym[1];
                } else if (self->reel[1].sym[0] == self->payMode && self->reel[2].sym[0] == self->payMode) {
                    self->reel[0].unkC4[0] = self->payMode;
                } else if (self->reel[1].sym[1] == self->payMode) {
                    if (self->reel[2].sym[0] == self->payMode) {
                        self->reel[0].unkC4[2] = self->payMode;
                    } else if (self->reel[2].sym[1] == self->payMode) {
                        self->reel[0].unkC4[1] = self->payMode;
                    } else if (self->reel[2].sym[2] == self->payMode) {
                        self->reel[0].unkC4[0] = self->payMode;
                    } else {
                        if (Slot1_isLineSym(&self->reel[1].sym[0]))
                            self->reel[0].lineSym[0] = self->reel[1].sym[0];
                        if (Slot1_isLineSym(&self->reel[1].sym[2]))
                            self->reel[0].lineSym[6] = self->reel[1].sym[2];
                    }
                } else if (self->reel[1].sym[2] == self->payMode && self->reel[2].sym[2] == self->payMode) {
                    self->reel[0].unkC4[2] = self->payMode;
                } else {
                    if (Slot1_isLineSym(&self->reel[1].sym[0]))
                        self->reel[0].lineSym[0] = self->reel[1].sym[0];
                    if (Slot1_isLineSym(&self->reel[1].sym[1]))
                        self->reel[0].lineSym[1] = self->reel[1].sym[1];
                    if (Slot1_isLineSym(&self->reel[1].sym[1]))
                        self->reel[0].lineSym[3] = self->reel[1].sym[1];
                    if (Slot1_isLineSym(&self->reel[1].sym[1]))
                        self->reel[0].lineSym[6] = self->reel[1].sym[1];
                    if (Slot1_isLineSym(&self->reel[1].sym[2]))
                        self->reel[0].lineSym[7] = self->reel[1].sym[2];
                }
            }
            Slot1_stopReel(self, 0);
            MarkPanel_setMark((MarkPanel *)self, 0, 1, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            self->endFlag |= SLOT1_F_STOP0;
        } else if ((D_007474A0.trg & SLOT1_KEY_STOP1) && Slot1_reelSpins(self, 1)) {
            if (!Slot1_reelStopped(self, 0) && !Slot1_reelStopped(self, 2)) {
                switch ((unsigned int)irand() % 3) {
                case 0:
                default:
                    self->reel[1].unkC4[0] = self->payMode;
                    break;
                case 1:
                    self->reel[1].unkC4[2] = self->payMode;
                    self->reel[1].unkC4[0] = self->payMode;
                    break;
                case 2:
                    self->reel[1].unkC4[2] = self->payMode;
                    self->reel[1].unkC4[0] = self->payMode;
                    self->reel[1].unkC4[1] = self->payMode;
                    break;
                }
            } else if (Slot1_reelStopped(self, 0) && !Slot1_reelStopped(self, 2)) {
                if (self->reel[0].sym[0] == self->payMode) {
                    self->reel[1].unkC4[1] = self->payMode;
                    self->reel[1].unkC4[0] = self->payMode;
                } else if (self->reel[0].sym[1] == self->payMode) {
                    self->reel[1].unkC4[1] = self->payMode;
                } else if (self->reel[0].sym[2] == self->payMode) {
                    self->reel[1].unkC4[2] = self->payMode;
                    self->reel[1].unkC4[1] = self->payMode;
                }
            } else if (!Slot1_reelStopped(self, 0) && Slot1_reelStopped(self, 2)) {
                if (self->reel[2].sym[0] == self->payMode) {
                    self->reel[1].unkC4[1] = self->payMode;
                    self->reel[1].unkC4[0] = self->payMode;
                } else if (self->reel[2].sym[1] == self->payMode) {
                    self->reel[1].unkC4[1] = self->payMode;
                } else if (self->reel[2].sym[2] == self->payMode) {
                    self->reel[1].unkC4[2] = self->payMode;
                    self->reel[1].unkC4[1] = self->payMode;
                }
            } else if (Slot1_reelStopped(self, 0) && Slot1_reelStopped(self, 2)) {
                if (self->payMode == SLOT1_PAYMODE_ON) {
                    if (Slot1_isLinePair(&self->reel[0].sym[0], &self->reel[2].sym[0]))
                        self->reel[1].lineSym[0] = self->reel[0].sym[0];
                    if (Slot1_isLinePair(&self->reel[0].sym[0], &self->reel[2].sym[2]))
                        self->reel[1].lineSym[3] = self->reel[0].sym[0];
                    if (Slot1_isLinePair(&self->reel[0].sym[1], &self->reel[2].sym[1]))
                        self->reel[1].lineSym[4] = self->reel[0].sym[1];
                    if (Slot1_isLinePair(&self->reel[0].sym[2], &self->reel[2].sym[0]))
                        self->reel[1].lineSym[5] = self->reel[0].sym[2];
                    if (Slot1_isLinePair(&self->reel[0].sym[2], &self->reel[2].sym[2]))
                        self->reel[1].lineSym[6] = self->reel[0].sym[2];
                } else if (self->reel[0].sym[0] == self->payMode) {
                    if (self->reel[2].sym[0] == self->payMode)
                        self->reel[1].unkC4[0] = self->payMode;
                    else if (self->reel[2].sym[2] == self->payMode)
                        self->reel[1].unkC4[1] = self->payMode;
                } else if (self->reel[0].sym[1] == self->payMode && self->reel[2].sym[1] == self->payMode) {
                    self->reel[1].unkC4[1] = self->payMode;
                } else if (self->reel[0].sym[2] == self->payMode) {
                    if (self->reel[2].sym[0] == self->payMode)
                        self->reel[1].unkC4[1] = self->payMode;
                    else if (self->reel[2].sym[2] == self->payMode)
                        self->reel[1].unkC4[2] = self->payMode;
                } else {
                    if (Slot1_isLineSym(&self->reel[0].sym[0]))
                        self->reel[1].lineSym[0] = self->reel[0].sym[0];
                    if (Slot1_isLineSym(&self->reel[0].sym[0]))
                        self->reel[1].lineSym[3] = self->reel[0].sym[0];
                    if (Slot1_isLineSym(&self->reel[0].sym[1]))
                        self->reel[1].lineSym[4] = self->reel[0].sym[1];
                    if (Slot1_isLineSym(&self->reel[0].sym[2]))
                        self->reel[1].lineSym[5] = self->reel[0].sym[2];
                    if (Slot1_isLineSym(&self->reel[0].sym[2]))
                        self->reel[1].lineSym[6] = self->reel[0].sym[2];
                }
            }
            Slot1_stopReel(self, 1);
            MarkPanel_setMark((MarkPanel *)self, 1, 1, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            self->endFlag |= SLOT1_F_STOP1;
        } else if ((D_007474A0.trg & SLOT1_KEY_STOP2) && Slot1_reelSpins(self, 2)) {
            if (!Slot1_reelStopped(self, 0) && !Slot1_reelStopped(self, 1)) {
                switch ((unsigned int)irand() % 3) {
                case 0:
                default:
                    self->reel[2].unkC4[0] = self->payMode;
                    break;
                case 1:
                    self->reel[2].unkC4[2] = self->payMode;
                    self->reel[2].unkC4[0] = self->payMode;
                    break;
                case 2:
                    self->reel[2].unkC4[2] = self->payMode;
                    self->reel[2].unkC4[0] = self->payMode;
                    self->reel[2].unkC4[1] = self->payMode;
                    break;
                }
            } else if (!Slot1_reelStopped(self, 0) && Slot1_reelStopped(self, 1)) {
                if (self->reel[1].sym[0] == self->payMode) {
                    self->reel[2].unkC4[0] = self->payMode;
                } else if (self->reel[1].sym[1] == self->payMode) {
                    self->reel[2].unkC4[2] = self->payMode;
                    self->reel[2].unkC4[0] = self->payMode;
                    self->reel[2].unkC4[1] = self->payMode;
                } else if (self->reel[1].sym[2] == self->payMode) {
                    self->reel[2].unkC4[2] = self->payMode;
                }
            } else if (Slot1_reelStopped(self, 0) && !Slot1_reelStopped(self, 1)) {
                if (self->reel[0].sym[0] == self->payMode) {
                    self->reel[2].unkC4[2] = self->payMode;
                    self->reel[2].unkC4[0] = self->payMode;
                } else if (self->reel[0].sym[1] == self->payMode) {
                    self->reel[2].unkC4[2] = self->payMode;
                    self->reel[2].unkC4[0] = self->payMode;
                    self->reel[2].unkC4[1] = self->payMode;
                } else if (self->reel[0].sym[2] == self->payMode) {
                    self->reel[2].unkC4[2] = self->payMode;
                    self->reel[2].unkC4[0] = self->payMode;
                }
            } else if (Slot1_reelStopped(self, 0) && Slot1_reelStopped(self, 1)) {
                if (self->payMode == SLOT1_PAYMODE_ON) {
                    if (Slot1_isLinePair(&self->reel[1].sym[0], &self->reel[0].sym[0]))
                        self->reel[2].lineSym[0] = self->reel[1].sym[0];
                    if (Slot1_isLinePair(&self->reel[1].sym[1], &self->reel[0].sym[2]))
                        self->reel[2].lineSym[1] = self->reel[1].sym[1];
                    if (Slot1_isLinePair(&self->reel[1].sym[1], &self->reel[0].sym[1]))
                        self->reel[2].lineSym[3] = self->reel[1].sym[1];
                    if (Slot1_isLinePair(&self->reel[1].sym[2], &self->reel[0].sym[2]))
                        self->reel[2].lineSym[6] = self->reel[1].sym[2];
                    if (Slot1_isLinePair(&self->reel[1].sym[1], &self->reel[0].sym[0]))
                        self->reel[2].lineSym[7] = self->reel[1].sym[1];
                } else if (self->reel[1].sym[0] == self->payMode && self->reel[0].sym[0] == self->payMode) {
                    self->reel[2].unkC4[0] = self->payMode;
                } else if (self->reel[1].sym[1] == self->payMode) {
                    if (self->reel[0].sym[0] == self->payMode) {
                        self->reel[2].unkC4[2] = self->payMode;
                    } else if (self->reel[0].sym[1] == self->payMode) {
                        self->reel[2].unkC4[1] = self->payMode;
                    } else if (self->reel[0].sym[2] == self->payMode) {
                        self->reel[2].unkC4[0] = self->payMode;
                    } else {
                        if (Slot1_isLineSym(&self->reel[1].sym[0]))
                            self->reel[2].lineSym[0] = self->reel[1].sym[0];
                        if (Slot1_isLineSym(&self->reel[1].sym[2]))
                            self->reel[2].lineSym[6] = self->reel[1].sym[2];
                    }
                } else if (self->reel[1].sym[2] == self->payMode && self->reel[0].sym[2] == self->payMode) {
                    self->reel[2].unkC4[2] = self->payMode;
                } else {
                    if (Slot1_isLineSym(&self->reel[1].sym[0]))
                        self->reel[2].lineSym[0] = self->reel[1].sym[0];
                    if (Slot1_isLineSym(&self->reel[1].sym[1]))
                        self->reel[2].lineSym[1] = self->reel[1].sym[1];
                    if (Slot1_isLineSym(&self->reel[1].sym[1]))
                        self->reel[2].lineSym[3] = self->reel[1].sym[1];
                    if (Slot1_isLineSym(&self->reel[1].sym[1]))
                        self->reel[2].lineSym[6] = self->reel[1].sym[1];
                    if (Slot1_isLineSym(&self->reel[1].sym[2]))
                        self->reel[2].lineSym[7] = self->reel[1].sym[2];
                }
            }
            Slot1_stopReel(self, 2);
            MarkPanel_setMark((MarkPanel *)self, 2, 1, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            self->endFlag |= SLOT1_F_STOP2;
        }
        if (Slot1_reelSettled(self, 0) && Slot1_reelSettled(self, 1)
            && Slot1_reelSettled(self, 2)) {
            cSnd_SeStop(&D_005FEE00, self->seStart);
            self->step++;
        }
        break;
    case 2:
        self->phase = 0;
        self->state = 3;
        self->step = 0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001E0CA8);
#endif
