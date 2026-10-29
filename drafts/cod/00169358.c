/* sn-2.95.3-136 */
/* NON_MATCHING func_00169358 (extern_jtbl D_0041FD00): 667 vs 679 words.
 * The control flow matches; the two row loops differ in register and stack
 * slot use: retail keeps the entry table base in a register and each row's
 * name index in a stack slot, and its frame is 0x10 bytes larger. Retail also
 * keeps the entry loads after the lock-word stores at the top and in state 4. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cVec.h"
#include "godhand/cCoreSave.h"
#include "godhand/cIDManager.h"
#include "godhand/cRecordIndex.h"
#include "godhand/cShopPanel.h"
#include "godhand/cSubScr.h"
#include "godhand/pl00.h"

#define SHOP_MSG_NAME     0x30C1
#define SHOP_MSG_RECORD   0x304E                /* + record name */
#define SHOP_MSG_TITLE    0x2000
#define SHOP_MSG_TECHNIQUE 0x200C               /* + technique number */
#define SHOP_MSG_GAUGE    0x200A
#define SHOP_COLOR_OFF    7
#define SHOP_COLOR_ON     6
#define SHOP_INPUT_TIME   20

/* Show row i's new mark when its record's stage isn't cleared yet and no
 * stage is, or for the stage 9 record after exactly one clear without
 * stage 1. Retail has this check in two branches, so it is written twice. */
#define SHOP_MARK_NEW(self, i, e)                                               \
    {                                                                           \
        if ((cCoreSave_ckClearStage(&D_00569B70, (e)->stage + 1) == 0           \
             && (e)->stage != 0 && cCoreSave_getClearNum(&D_00569B70) == 0)     \
            || ((e)->stage == 9 && cCoreSave_getClearNum(&D_00569B70) == 1      \
                && cCoreSave_ckClearStage(&D_00569B70, 1) == 0))                \
            (self)->ent[SHOP_ROW_NEW + (i)]->flags &= ~IDENT_FLAG_NO_DRAW;      \
    }

extern unsigned int D_00747A80;                 /* input and event lock bits */
extern int D_003BC7D0[][SHOP_INPUTS];           /* each technique's inputs, 0-terminated */
extern float D_0041FE78[];

/* Draw step of the technique shop: replays the shown technique's inputs on
 * the player, runs the panel state, fills the six rows for the menu layout,
 * places the scroll bar and starts the demonstration of the selected
 * technique. */
__attribute__((section(".text.func_00169358")))
void func_00169358(ShopPanel *self)
{
    CVEC_TEMPS;
    cRecordIndexEntry *e;
    unsigned short i;
    unsigned short j;
    unsigned int k;
    int known;
    unsigned int n;

    CVEC_SET_XYZ(&self->player->rot.x, 0.0f, 0.0f, 0.0f);
    D_00747A80 &= ~0x00800000;
    D_00747A80 &= ~0x80000000;
    D_00747A80 &= ~0x00200000;
    self->frame->flags |= IDENT_FLAG_NO_DRAW;
    self->arrowUp->flags |= IDENT_FLAG_NO_DRAW;
    self->arrowDown->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[SHOP_ENT_HELP]->flags &= ~IDENT_FLAG_NO_DRAW;

    if (self->player->motionFlags & 3 & ~self->prevMotion) {
        self->inputTimer[self->inputNum] = SHOP_INPUT_TIME;
        self->input[self->inputNum] = D_003BC7D0[self->combo][self->inputNum];
        self->inputNum++;
        if (D_003BC7D0[self->combo][self->inputNum] == 0)
            self->inputNum = 0;
    }
    self->prevMotion = self->player->motionFlags;
    for (k = 0; k < SHOP_INPUTS; k++) {
        if (--self->inputTimer[k] < 0) {
            self->inputTimer[k] = 0;
            self->input[k] = 0;
        }
    }

    switch (self->head.step) {
    case 0:
        switch (D_003BD930->mode) {
        case 0:
            func_002C90A0(&D_005FEC58, 1);
            break;
        case 1:
            func_002C90A0(&D_005FEC58, 2);
            break;
        }
        func_002C9950(&D_005FEC58);
        break;
    case 1:
        e = func_002C9008(&D_005FEC58, self->scroll + self->cursor);
        if (e != 0) {
            if (D_005FEC58.limit != 0) {
                self->title->msg = e->id + SHOP_MSG_TECHNIQUE;
                self->subtitle->msg = e->id + SHOP_MSG_TECHNIQUE;
            } else {
                self->title->msg = SHOP_MSG_TITLE;
                self->subtitle->msg = SHOP_MSG_TITLE;
            }
        }
        break;
    case 2:
        switch (D_003BD930->mode) {
        case 0:
            self->title->msg = SHOP_MSG_TITLE + 1;
            self->subtitle->msg = SHOP_MSG_TITLE + 1;
            break;
        case 1:
            self->title->msg = SHOP_MSG_TITLE + 2;
            self->subtitle->msg = SHOP_MSG_TITLE + 2;
            break;
        }
        break;
    case 3:
        self->title->msg = SHOP_MSG_GAUGE;
        self->subtitle->msg = SHOP_MSG_GAUGE;
        self->gaugeBack->flags &= ~IDENT_FLAG_NO_DRAW;
        self->gauge->flags &= ~IDENT_FLAG_NO_DRAW;
        self->gauge->posX = D_0041FE78[self->gaugeLevel];
        break;
    case 4:
        if (self->closed != 0) {
            self->head.step = 3;
        } else {
            D_00747A80 |= 0x00800000;
            D_00747A80 |= 0x80000000;
            D_00747A80 |= 0x00200000;
            self->ent[SHOP_ENT_HELP]->flags |= IDENT_FLAG_NO_DRAW;
            pl00_SubscreenMode(self->player, 1);
        }
        break;
    }

    switch (D_003BD930->mode) {
    case 0:
        for (i = 0; i < SHOP_ROWS; i++) {
            self->ent[SHOP_ROW_NUMBER + i]->seed = self->scroll + i + 1;
            self->ent[SHOP_ROW_NAME + i]->msg = SHOP_MSG_NAME;
            self->ent[SHOP_ROW_PRICE + i]->seed = 0;
            self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_OFF;
            self->ent[SHOP_ROW_LOCK + i]->flags &= ~IDENT_FLAG_NO_DRAW;
            if (i < D_005FEC58.limit) {
                e = func_002C9008(&D_005FEC58, self->scroll + i);
                if (e != 0) {
                    self->ent[SHOP_ROW_NAME + i]->msg = e->name + SHOP_MSG_RECORD;
                    self->ent[SHOP_ROW_PRICE + i]->seed = e->price;
                    if (func_002C9A90(&D_005FEC58, self->scroll + i) == -1
                        && cCoreSave_getGold(&D_00569B70) >= self->ent[SHOP_ROW_PRICE + i]->seed) {
                        self->ent[SHOP_ROW_LOCK + i]->flags |= IDENT_FLAG_NO_DRAW;
                        self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_ON;
                        SHOP_MARK_NEW(self, i, e);
                    } else if (func_002C9A90(&D_005FEC58, self->scroll + i) != -1) {
                        self->ent[SHOP_ROW_LOCK + i]->flags &= ~IDENT_FLAG_NO_DRAW;
                        self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_OFF;
                    } else {
                        self->ent[SHOP_ROW_LOCK + i]->flags |= IDENT_FLAG_NO_DRAW;
                        self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_OFF;
                        SHOP_MARK_NEW(self, i, e);
                    }
                }
            } else {
                self->ent[SHOP_ROW_NUMBER + i]->seed = 0;
            }
        }
        break;
    case 1:
        for (i = 0; i < SHOP_ROWS; i++) {
            self->ent[SHOP_ROW_NUMBER + i]->seed = self->scroll + i + 1;
            self->ent[SHOP_ROW_LOCK + i]->flags |= IDENT_FLAG_NO_DRAW;
            self->ent[SHOP_ROW_NAME + i]->msg = SHOP_MSG_NAME;
            self->ent[SHOP_ROW_PRICE + i]->seed = 0;
            self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_OFF;
            if (i < D_005FEC58.limit) {
                e = func_002C9008(&D_005FEC58, self->scroll + i);
                if (e != 0) {
                    known = 0;
                    for (j = 0; j < cCoreSave_getComboST(&D_00569B70); j++)
                        if (e->id == cCoreSave_getCombo(&D_00569B70, 0, j))
                            known = 1;
                    for (j = 0; j < 6; j++)
                        if (e->id == cCoreSave_getCombo(&D_00569B70, j + 1, 0))
                            known = 1;
                    self->ent[SHOP_ROW_NAME + i]->msg = e->name + SHOP_MSG_RECORD;
                    self->ent[SHOP_ROW_PRICE + i]->seed = e->price >> 1;
                    if (known == 1)
                        self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_OFF;
                    else
                        self->ent[SHOP_ROW_NAME + i]->b8B = SHOP_COLOR_ON;
                }
            } else {
                self->ent[SHOP_ROW_NUMBER + i]->seed = 0;
            }
        }
        break;
    }

    n = D_005FEC58.limit;
    if (n <= 5)
        n = 6;
    self->ent[SHOP_SCROLLBAR]->sclY = 6.0f / n;
    self->ent[SHOP_SCROLLBAR]->posY = self->ent[SHOP_SCROLLBAR]->src->posY
        + self->ent[SHOP_SCROLLBAR]->src->f18 * (1.0f - self->ent[SHOP_SCROLLBAR]->sclY)
        * (self->scroll / (n - 6.0f));

    if (func_002C9008(&D_005FEC58, self->scroll + self->cursor) != 0 && self->head.step != 4) {
        if (self->player->step < 3
            || func_002C9008(&D_005FEC58, self->scroll + self->cursor)->id != self->combo) {
            if (D_005FEC58.limit != 0) {
                pl00_SubscreenMotSet(self->player,
                                     func_002C9008(&D_005FEC58, self->scroll + self->cursor)->id);
                self->combo = func_002C9008(&D_005FEC58, self->scroll + self->cursor)->id;
                func_003A52F0(self->inputTimer, 0, sizeof(self->inputTimer));
                self->inputNum = 0;
                self->prevMotion = 0;
                self->player->motionFlags = 0;
            }
        }
    }
    func_0016BCE0(self, self->scroll + self->cursor);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00169358);
#endif
