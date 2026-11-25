/* sn-2.95.3-136 */
/* func_00143670: retail tests the mode bits at 0x1C0 with a 64-bit load (ld)
 * before its byte loads, and keeps i + 1 of the popup loop in a ninth saved
 * register; this build tests them with lbu and recomputes i + 1, one
 * instruction shorter. */
#include "include_asm.h"
#include "godhand/cCockPrintData.h"
#include "godhand/cCoreSave.h"
#include "godhand/cOmBase.h"
#include "godhand/cScenario.h"

#ifdef NON_MATCHING

/* What each of the four work entries is (main's cCockPrintData.h has no names for them). */
#define COCKPRINT_COUNTER     0         /* its number is the amount drawn */
#define COCKPRINT_POPUP       1
#define COCKPRINT_LABEL       2
#define COCKPRINT_LABEL2      3
#define COCKPRINT_MODE_MASK   3
#define COCKPRINT_MODE_LABEL  1         /* show the label */
/* The popup countdowns at 0x180 (still padding in cCockPrintData). */
#define COCKPRINT_TIMER(self, i) (((short *)(self)->unk180)[i])

#define SCENARIO_RUNNING(sc)  (*(unsigned char *)((char *)(sc) + 0x14))   /* cScenario does not name 0x14 yet */


/* Per-frame update of the gold counter: steps the shown amount toward the
 * saved gold, starts a popup for each new pickup, and fades the popups. */
__attribute__((section(".text.func_00143670")))
void func_00143670(cCockPrintData *self)
{
    unsigned short i;
    unsigned short n;

    self->work[COCKPRINT_LABEL]->flags |= IDENT_FLAG_NO_DRAW;
    if (self->work[COCKPRINT_COUNTER]->number + 1000 < self->gold) {
        self->work[COCKPRINT_COUNTER]->number += 1000;
    } else if (self->work[COCKPRINT_COUNTER]->number + 100 < self->gold) {
        self->work[COCKPRINT_COUNTER]->number += 100;
    } else if (self->work[COCKPRINT_COUNTER]->number + 10 < self->gold) {
        self->work[COCKPRINT_COUNTER]->number += 10;
    } else {
        self->work[COCKPRINT_COUNTER]->number += 1;
    }
    if (self->work[COCKPRINT_COUNTER]->number > self->gold) {
        self->work[COCKPRINT_COUNTER]->number = self->gold;
    }
    if (cCoreSave_getGold(&D_00569B70) != self->gold && cCoreSave_getAddGoldNum(&D_00569B70) != 0) {
        func_002AC9B8(self, self->work[COCKPRINT_POPUP], 0);
        n = 0;
        self->work[COCKPRINT_POPUP]->flags &= ~IDENT_FLAG_NO_DRAW;
        for (i = 0; i < COCKPRINT_SLOT_NUM && n < cCoreSave_getAddGoldNum(&D_00569B70); i++) {
            if (self->on[i] == 0) {
                self->on[i] = 1;
                self->posYOfs[i] = (i + 1) * 20;
                self->alpha[i] = 0x80;
                self->number[i] = cCoreSave_getAddGold(&D_00569B70, n);
                COCKPRINT_TIMER(self, i) = 20;
                n++;
            }
        }
    }
    self->gold = cCoreSave_getGold(&D_00569B70);
    for (i = 0; i < COCKPRINT_SLOT_NUM; i++) {
        if (self->on[i] == 1) {
            if (--COCKPRINT_TIMER(self, i) > 0) {
                self->gold -= self->number[i];
            } else {
                self->posYOfs[i] *= 0.5f;
                if (self->posYOfs[i] < 0.1f) {
                    self->on[i] = 0;
                }
                self->alpha[i] = (int)(self->alpha[i] * 0.8f);
            }
        }
    }
    cCoreSave_initAddGold(&D_00569B70);
    if ((self->mode & COCKPRINT_MODE_MASK) == COCKPRINT_MODE_LABEL && SCENARIO_RUNNING(D_003C2F84) == 0) {
        self->work[COCKPRINT_LABEL]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->work[COCKPRINT_LABEL]->msg = 0x3010;
        self->work[COCKPRINT_LABEL2]->msg = 0x3010;
    }
    self->mode &= ~COCKPRINT_MODE_MASK;
    cIDBase_move(&self->base);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00143670);
#endif
