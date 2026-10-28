/* sn-2.95.3-136 */
/* func_00143670: retail reads the mode bits at 0x1C0 as a 64-bit word but
 * clears them with a byte store (lbu, andi 0xFC, sb), and keeps i + 1 of the
 * popup loop in a ninth saved register; this build clears them with ld/sd
 * and recomputes i + 1, one instruction shorter. */
#include "include_asm.h"
#include "godhand/cIDBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/cScenario.h"

#ifdef NON_MATCHING

#define GOLD_POPUP_NUM   16

/* The gold counter display: the shown amount counts toward the saved gold,
 * and each gold pickup pops up a line that rises and fades. */
typedef struct GoldScreen {
    cIDBaseObj base;                    /* 0x000 */
    char unk048[0x90 - 0x48];
    unsigned int gold;                  /* 0x090 amount shown */
    cIDBaseEnt *counter;                /* 0x094 its seed is the number drawn */
    cIDBaseEnt *popup;                  /* 0x098 */
    cIDBaseEnt *label;                  /* 0x09C */
    cIDBaseEnt *label2;                 /* 0x0A0 */
    char unk0A4[0x100 - 0xA4];
    float posYOfs[GOLD_POPUP_NUM];      /* 0x100 */
    unsigned int add[GOLD_POPUP_NUM];   /* 0x140 amount each popup shows */
    short timer[GOLD_POPUP_NUM];        /* 0x180 */
    unsigned char alpha[GOLD_POPUP_NUM]; /* 0x1A0 */
    unsigned char on[GOLD_POPUP_NUM];   /* 0x1B0 */
    unsigned long flags;                /* 0x1C0 low two bits: 1 = show the label */
} GoldScreen;

#define SCENARIO_RUNNING(sc)  (*(unsigned char *)((char *)(sc) + 0x14))   /* cScenario does not name 0x14 yet */


/* Per-frame update of the gold counter: steps the shown amount toward the
 * saved gold, starts a popup for each new pickup, and fades the popups. */
__attribute__((section(".text.func_00143670")))
void func_00143670(GoldScreen *self)
{
    unsigned short i;
    unsigned short n;

    self->label->flags |= IDENT_FLAG_NO_DRAW;
    if (self->counter->seed + 1000 < self->gold) {
        self->counter->seed += 1000;
    } else if (self->counter->seed + 100 < self->gold) {
        self->counter->seed += 100;
    } else if (self->counter->seed + 10 < self->gold) {
        self->counter->seed += 10;
    } else {
        self->counter->seed += 1;
    }
    if (self->counter->seed > self->gold) {
        self->counter->seed = self->gold;
    }
    if (cCoreSave_getGold(&D_00569B70) != self->gold && cCoreSave_getAddGoldNum(&D_00569B70) != 0) {
        func_002AC9B8(self, self->popup, 0);
        n = 0;
        self->popup->flags &= ~IDENT_FLAG_NO_DRAW;
        for (i = 0; i < GOLD_POPUP_NUM && n < cCoreSave_getAddGoldNum(&D_00569B70); i++) {
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
    for (i = 0; i < GOLD_POPUP_NUM; i++) {
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
    if ((self->flags & 3) == 1 && SCENARIO_RUNNING(D_003C2F84) == 0) {
        self->label->flags &= ~IDENT_FLAG_NO_DRAW;
        self->label->msg = 0x3010;
        self->label2->msg = 0x3010;
    }
    self->flags &= ~3;
    cIDBase_move(self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00143670);
#endif
