/* sn-2.95.3-136 */
#include "godhand/Slot1.h"
#include "godhand/cSnd.h"
#include "godhand/gameWork.h"
#include "godhand/padWork.h"
#include "godhand/rand.h"
#include "godhand/scrollLayer.h"
#include "godhand/sceVu0.h"
#include "include_asm.h"

#define SLOT1_REEL_STOP_BONUS   2
#define SLOT1_REEL_STOP_FREE    0x15
#define SLOT1_PART_RUN          2
#define SLOT1_REEL_GAP          5          /* frames between two reel starts */

extern Slot1BonusTbl D_0042B718;

/* Starts a part of the machine: state 2, from its first step. */
#define SLOT1_PART_START(part)              \
    {                                       \
        (part)->phase = 0;                  \
        (part)->state = SLOT1_PART_RUN;     \
        (part)->step = 0;                   \
    }

/* Spin stage: draw the bonus (each kind in turn at one in n, halved while
 * bit 8 of endFlag is set) and show its layer, start the board, then the
 * three reels five frames apart, and go back to the play screen once all
 * three have settled.
 * Differs from retail in register allocation only: retail keeps the 8 and 1
 * compares in s7/s6 and the D_005E8140 address in fp; ours gives the address
 * s6 and the constants s7/fp. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_001E0840")))
void func_001E0840(Slot1 *self)
{
    switch (self->step) {
    case 0: {
        int odds[SLOT1_LINE_WEIGHTS] = { self->bonusOdds.n[0], self->bonusOdds.n[1],
                                         self->bonusOdds.n[2], self->bonusOdds.n[3] };
        Slot1BonusTbl tbl = D_0042B718;
        unsigned int i;

        if (self->payMode == SLOT1_PAYMODE_ON) {
            for (i = 0; i < SLOT1_LINE_WEIGHTS; i++) {
                int n = odds[i];
                long end = self->endFlag;
                long half = end >> 8 & 1;

                if (half != 0) {
                    n /= 2;
                }
                if ((unsigned int)irand() % n == 0) {
                    if (tbl.kind[i] == 0 || tbl.kind[i] == 8 || tbl.kind[i] == 1) {
                        self->payMode = tbl.kind[i];
                        classPAD_WORK_Pad_act_set(D_005E8140, 0x03FF0000, (10 << D_007474A0.padPort) << 16);
                    } else {
                        self->payMode = tbl.kind[(irand() & 3) + 3];
                    }
                    break;
                }
            }
            switch (self->payMode) {
            case 0:
                self->reel[2].stopMode = SLOT1_REEL_STOP_BONUS;
                self->reel[0].stopMode = SLOT1_REEL_STOP_BONUS;
                self->reel[1].stopMode = SLOT1_REEL_STOP_BONUS;
                displayScrollLayer(self->bonusLayer0, 1);
                displayScrollLayer(self->bonusLayer1, 0);
                displayScrollLayer(self->bonusLayer8, 0);
                break;
            case 1:
                self->reel[2].stopMode = SLOT1_REEL_STOP_BONUS;
                self->reel[0].stopMode = SLOT1_REEL_STOP_BONUS;
                self->reel[1].stopMode = SLOT1_REEL_STOP_BONUS;
                displayScrollLayer(self->bonusLayer1, 1);
                displayScrollLayer(self->bonusLayer0, 0);
                displayScrollLayer(self->bonusLayer8, 0);
                break;
            case 8:
                self->reel[2].stopMode = SLOT1_REEL_STOP_BONUS;
                self->reel[0].stopMode = SLOT1_REEL_STOP_BONUS;
                self->reel[1].stopMode = SLOT1_REEL_STOP_BONUS;
                displayScrollLayer(self->bonusLayer8, 1);
                displayScrollLayer(self->bonusLayer0, 0);
                displayScrollLayer(self->bonusLayer1, 0);
                break;
            case SLOT1_PAYMODE_ON:
                break;
            default:
                self->reel[2].stopMode = SLOT1_REEL_STOP_FREE;
                self->reel[0].stopMode = SLOT1_REEL_STOP_FREE;
                self->reel[1].stopMode = SLOT1_REEL_STOP_FREE;
                break;
            }
        }
    }
        {
            Slot1Panel *panel = &self->panel;
            SLOT1_PART_START(panel);
        }
        self->step++;
        /* fallthrough */
    case 1: {
        long done = self->panel.doneFlag;
        long on = done & 1;

        if (on != 0) {
            cVec pos;
            Slot1Reel *first;

            cVec_zero(&pos);
            first = &self->reel[0];
            func_001E8E48((int)first, (int)&pos);
            self->seStart = cSnd_SeCall(&D_005FEE00, 2, 1, (int)&pos, 0, 0);
            {
                long ready = self->reel[0].doneFlag;
                long go = ready & 1;

                if (go != 0) {
                    SLOT1_PART_START(first);
                }
            }
            self->timer = SLOT1_REEL_GAP;
            self->step++;
        }
        break;
    }
    case 2:
        if (Slot_tick(&self->timer)) {
            Slot1Reel *reel = &self->reel[1];
            long ready = self->reel[1].doneFlag;
            long go = ready & 1;

            if (go != 0) {
                SLOT1_PART_START(reel);
            }
            self->timer = SLOT1_REEL_GAP;
            self->step++;
        }
        break;
    case 3:
        if (Slot_tick(&self->timer)) {
            Slot1Reel *reel = &self->reel[2];
            long ready = self->reel[2].doneFlag;
            long go = ready & 1;

            if (go != 0) {
                SLOT1_PART_START(reel);
            }
            self->step++;
        }
        break;
    case 4: {
        long done = self->reel[0].doneFlag;
        long settled;

        if ((done >> 1 & 1) == 0) {
            break;
        }
        done = self->reel[1].doneFlag;
        if ((done >> 1 & 1) == 0) {
            break;
        }
        done = self->reel[2].doneFlag;
        settled = done >> 1 & 1;
        if (settled != 0) {
            self->phase = 0;
            self->state = SLOT1_PART_RUN;
            self->step = 0;
        }
        break;
    }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001E0840);
#endif
