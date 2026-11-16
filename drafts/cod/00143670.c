/* sn-2.95.3-136 */
/* func_00143670: retail tests the mode bits at 0x1C0 with a 64-bit load (ld)
 * before its byte loads, and keeps i + 1 of the popup loop in a ninth saved
 * register; this build tests them with lbu and recomputes i + 1, one
 * instruction shorter. */
#include "include_asm.h"
#include "godhand/cCockPrintData.h"
#include "godhand/cCoreSave.h"
#include "godhand/cScenario.h"

#ifdef NON_MATCHING


#define SCENARIO_RUNNING(sc)  (*(unsigned char *)((char *)(sc) + 0x14))   /* cScenario does not name 0x14 yet */


/* Per-frame update of the gold counter: steps the shown amount toward the
 * saved gold, starts a popup for each new pickup, and fades the popups. */
__attribute__((section(".text.func_00143670")))
void func_00143670(cCockPrintData *self)
{
    unsigned short i;
    unsigned short n;

    self->ent[COCKPRINT_LABEL]->flags |= IDENT_FLAG_NO_DRAW;
    if (self->ent[COCKPRINT_COUNTER]->seed + 1000 < self->gold) {
        self->ent[COCKPRINT_COUNTER]->seed += 1000;
    } else if (self->ent[COCKPRINT_COUNTER]->seed + 100 < self->gold) {
        self->ent[COCKPRINT_COUNTER]->seed += 100;
    } else if (self->ent[COCKPRINT_COUNTER]->seed + 10 < self->gold) {
        self->ent[COCKPRINT_COUNTER]->seed += 10;
    } else {
        self->ent[COCKPRINT_COUNTER]->seed += 1;
    }
    if (self->ent[COCKPRINT_COUNTER]->seed > self->gold) {
        self->ent[COCKPRINT_COUNTER]->seed = self->gold;
    }
    if (cCoreSave_getGold(&D_00569B70) != self->gold && cCoreSave_getAddGoldNum(&D_00569B70) != 0) {
        func_002AC9B8(self, self->ent[COCKPRINT_POPUP], 0);
        n = 0;
        self->ent[COCKPRINT_POPUP]->flags &= ~IDENT_FLAG_NO_DRAW;
        for (i = 0; i < COCKPRINT_POPUP_NUM && n < cCoreSave_getAddGoldNum(&D_00569B70); i++) {
            if (self->on[i] == 0) {
                self->on[i] = 1;
                self->posYOfs[i] = (i + 1) * 20;
                self->alpha[i] = 0x80;
                self->add[i] = cCoreSave_getAddGold(&D_00569B70, n);
                self->timer[i] = 20;
                n++;
            }
        }
    }
    self->gold = cCoreSave_getGold(&D_00569B70);
    for (i = 0; i < COCKPRINT_POPUP_NUM; i++) {
        if (self->on[i] == 1) {
            if (--self->timer[i] > 0) {
                self->gold -= self->add[i];
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
        self->ent[COCKPRINT_LABEL]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->ent[COCKPRINT_LABEL]->msg = 0x3010;
        self->ent[COCKPRINT_LABEL2]->msg = 0x3010;
    }
    self->mode &= ~COCKPRINT_MODE_MASK;
    cIDBase_move(&self->base);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00143670);
#endif
