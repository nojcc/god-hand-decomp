/* sn-2.95.3-136: Slot2_StopReels (extern_jtbl D_0042B960 D_0042B980 D_0042B9A0 D_0042B9C0).
 * Differs from retail: the jackpotLine = 9 store is scheduled before the weight copy instead of after it, and the
 * reels' done-flag loads go through the reel pointer instead of self (retail's 001e5268.c shape, a reel pointer plus a
 * read through self, fixes the loads but swaps s0 and s1). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/Slot2.h"

extern float frand(float a0, float a1);
extern int irand(void);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005FEE00[];

#define SLOT2_LINE_NONE    9         /* no prize line drawn: the reels stop freely */

/* The prize line each draw stands for: draws 0..2 give lines 0, 8 and 1, the last draw one of lines 2..5. */
typedef struct Slot2LineTbl {
    int line[7];
} Slot2LineTbl;

extern Slot2LineTbl D_0042B938;

/* Count the timer down; nonzero once it has run out. */
#define SLOT2_TIMER_DONE(self, done)        \
    if ((self)->timer != 0) {               \
        (self)->timer = (self)->timer - 1;  \
        done = 0;                           \
    } else {                                \
        done = 1;                           \
    }

/* Tell a reel which line to stop on and how. */
static inline void Slot2Reel_setStop(Slot2Reel *reel, int line, int mode)
{
    reel->stopMode = mode;
    reel->stopLine = line;
}

/* Bit `bit` of a reel's done flags. */
static inline long Slot2Reel_doneBit(Slot2Reel *reel, int bit)
{
    long v = (unsigned int)reel->doneFlag;

    return v >> bit & 1;
}

/* Move a reel to another screen, from its first step. */
static inline void Slot2Reel_setState(Slot2Reel *reel, int state)
{
    reel->state = state;
    reel->step = 0;
    reel->phase = 0;
}

/* Nonzero when a prize line was drawn. */
static inline unsigned char Slot2_lineDrawn(Slot2 *self)
{
    return self->jackpotLine != SLOT2_LINE_NONE;
}

/* Slot2 reel stop: draw the prize line from the line weights and a reel pattern, then stop the three reels one
 * after another, each told which line to land on, and stop the reel sound once all three have settled. */
__attribute__((section(".text.Slot2_StopReels")))
void Slot2_StopReels(Slot2 *self)
{
    int done;

    switch (self->step) {
    case 0: {
        int weight[4] = { self->lineWeight[0], self->lineWeight[1], self->lineWeight[2], self->lineWeight[3] };
        Slot2LineTbl lines;
        int i;

        self->jackpotLine = SLOT2_LINE_NONE;
        lines = D_0042B938;
        for (i = 0; i < sizeof(weight) / sizeof(weight[0]); i++) {
            if ((int)frand(0.0f, weight[i]) == 0) {
                if (i < 3) {
                    self->jackpotLine = lines.line[i];
                } else {
                    self->jackpotLine = lines.line[(irand() & 3) + 3];
                }
                self->pattern = (unsigned int)irand() % 5;
                break;
            }
        }
        self->timer = 60;
        self->step = self->step + 1;
    }
    case 1:
        SLOT2_TIMER_DONE(self, done);
        if ((done & 0xFF) == 0) {
            break;
        }
        if (Slot2_lineDrawn(self)) {
            switch (self->pattern) {
            case 0:
                Slot2Reel_setStop(&self->reel[0], self->jackpotLine, 1);
                break;
            case 1:
            case 3:
                Slot2Reel_setStop(&self->reel[0], self->jackpotLine, 0);
                break;
            case 2:
            case 4:
                Slot2Reel_setStop(&self->reel[0], self->jackpotLine, 2);
                break;
            }
        }
        if (Slot2Reel_doneBit(&self->reel[0], 1) != 0) {
            Slot2Reel_setState(&self->reel[0], 4);
        }
        self->timer = 60;
        self->step = self->step + 1;
        break;
    case 2:
        SLOT2_TIMER_DONE(self, done);
        if ((done & 0xFF) == 0) {
            break;
        }
        if (Slot2_lineDrawn(self)) {
            switch (self->pattern) {
            case 1:
                Slot2Reel_setStop(&self->reel[1], self->jackpotLine, 0);
                break;
            case 2:
                Slot2Reel_setStop(&self->reel[1], self->jackpotLine, 2);
                break;
            case 0:
            case 3:
            case 4:
                Slot2Reel_setStop(&self->reel[1], self->jackpotLine, 1);
                break;
            }
        }
        if (Slot2Reel_doneBit(&self->reel[1], 1) != 0) {
            Slot2Reel_setState(&self->reel[1], 4);
        }
        self->timer = 60;
        self->step = self->step + 1;
        break;
    case 3:
        SLOT2_TIMER_DONE(self, done);
        if ((done & 0xFF) == 0) {
            break;
        }
        if (Slot2_lineDrawn(self)) {
            switch (self->pattern) {
            case 0:
                Slot2Reel_setStop(&self->reel[2], self->jackpotLine, 1);
                break;
            case 2:
            case 3:
                Slot2Reel_setStop(&self->reel[2], self->jackpotLine, 2);
                break;
            case 1:
            case 4:
                Slot2Reel_setStop(&self->reel[2], self->jackpotLine, 0);
                break;
            }
        } else {
            self->reel[2].unkCC[0] = self->reel[1].unkD8[0];
            self->reel[2].unkCC[1] = self->reel[1].unkD8[1];
            self->reel[2].unkCC[2] = self->reel[1].unkD8[2];
        }
        if (Slot2Reel_doneBit(&self->reel[2], 1) != 0) {
            Slot2Reel_setState(&self->reel[2], 4);
        }
        self->step = self->step + 1;
        break;
    case 4:
        if (Slot2Reel_doneBit(&self->reel[0], 2) != 0 && Slot2Reel_doneBit(&self->reel[1], 2) != 0
            && Slot2Reel_doneBit(&self->reel[2], 2) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId[0]);
            self->step = self->step + 1;
        }
        break;
    case 5:
        self->state = 3;
        self->step = 0;
        self->phase = 0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", Slot2_StopReels);
#endif
