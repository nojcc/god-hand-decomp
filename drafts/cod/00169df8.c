/* sn-2.95.3-136 */
/* func_00169DF8. The switch and the setup match; the row loop does not:
 * retail walks the item table with a pointer and keeps the row bases in
 * stack slots, so most of the loop differs in register use and order. */
#include "include_asm.h"
#include "godhand/gameWork.h"
#include "godhand/cCoreSave.h"
#include "godhand/cIDBase.h"

#ifdef NON_MATCHING
#define SHOP_ROWS        6
#define SHOP_ITEMS       31
#define SHOP_HIDE        0x08000000u           /* IDENT flag: entry not drawn */
#define SHOP_MSG_NAME    0x30C1
#define SHOP_MSG_INFO    0x2085                /* + item index */
#define SHOP_MSG_STAGE   0x20A3                /* + item stage */

/* One reel shop item, 20 bytes. */
typedef struct ShopItem {
    int reel;                           /* 0x00 god reel number */
    unsigned short msg;                 /* 0x04 name message */
    char unk06[0xC - 0x6];
    int price;                          /* 0x0C */
    signed char stage;                  /* 0x10 stage that unlocks it, -1 = never */
    signed char stageMsg;               /* 0x11 */
    char unk12[2];
} ShopItem;

/* The reel shop panel; 001680d8.c reads the shared panel fields through raw offsets. */
typedef struct ShopPanel {
    char unk00[0x5B];
    signed char state;                  /* 0x5B */
    char unk5C[0x8C - 0x5C];
    cIDBaseEnt *title;                  /* 0x8C */
    cIDBaseEnt *subtitle;               /* 0x90 */
    cIDBaseEnt *gauge;                  /* 0x94 */
    cIDBaseEnt *gaugeBack;              /* 0x98 */
    char unk9C[0xB0 - 0x9C];
    cIDBaseEnt *arrowUp;                /* 0xB0 */
    cIDBaseEnt *arrowDown;              /* 0xB4 */
    cIDBaseEnt *frame;                  /* 0xB8 */
    cIDBaseEnt *stageName;              /* 0xBC */
    char unkC0[0xC4 - 0xC0];
    cIDBaseEnt *stageInfo;              /* 0xC4 */
    char unkC8[0x120 - 0xC8];
    cIDBaseEnt *ent[38];                /* 0x120 per-row entries; [23] is the scroll bar */
    int rowReel[SHOP_ROWS];             /* 0x1B8 reel shown on each row */
    short scroll;                       /* 0x1D0 first item shown */
    short cursor;                       /* 0x1D2 */
    signed char gaugeLevel;             /* 0x1D4 */
    char unk1D5[0x202 - 0x1D5];
    short itemCount;                    /* 0x202 */
    char unk204[0x286 - 0x204];
    unsigned char closed;               /* 0x286 */
} ShopPanel;

#define SHOP_ROW_NAME    5
#define SHOP_ROW_PRICE   11
#define SHOP_ROW_LOCK    17
#define SHOP_SCROLLBAR   23
#define SHOP_ROW_NUMBER  24
#define SHOP_ROW_NEW     31

extern int D_00747A0C;
extern ShopItem D_0042AD58[];
extern float D_0041FE78[];

/* Draw step of the reel shop: updates the header for the current state,
 * fills the six visible rows from the item table and places the scroll bar. */
__attribute__((section(".text.func_00169DF8")))
void func_00169DF8(ShopPanel *self)
{
    short row;
    short item;
    short shown;
    int count;

    switch (self->state) {
    case 0:
        break;
    case 1:
        if (self->itemCount != 0) {
            self->stageName->flags &= ~SHOP_HIDE;
        }
        if (D_00747A0C == 0) {
            self->title->flags |= 4;
            self->subtitle->flags |= 4;
            self->stageName->flags |= 4;
            self->stageInfo->flags |= 4;
        }
        self->title->msg = 0x2000;
        self->subtitle->msg = 0x2000;
        break;
    case 2:
        if (self->itemCount != 0) {
            self->stageName->flags &= ~SHOP_HIDE;
        }
        if (D_00747A0C == 0) {
            self->stageName->flags |= 4;
            self->stageInfo->flags |= 4;
        }
        break;
    case 3:
        self->title->msg = 0x200B;
        self->subtitle->msg = 0x200B;
        self->gaugeBack->flags &= ~SHOP_HIDE;
        self->gauge->flags &= ~SHOP_HIDE;
        self->gauge->posX = D_0041FE78[self->gaugeLevel];
        break;
    case 4:
        if (self->closed) {
            self->state = 3;
        }
        break;
    }

    self->frame->flags &= ~SHOP_HIDE;
    if (self->itemCount != 0) {
        self->arrowUp->flags &= ~SHOP_HIDE;
    } else {
        self->arrowUp->flags |= SHOP_HIDE;
    }
    self->arrowUp->b8B = 3;
    self->arrowDown->flags |= SHOP_HIDE;

    item = -1;
    shown = 0;
    for (row = 0; row < SHOP_ROWS; row++) {
        item++;
        self->ent[SHOP_ROW_NUMBER + row]->seed = row + self->scroll + 1;
        self->ent[SHOP_ROW_NAME + row]->msg = SHOP_MSG_NAME;
        self->ent[SHOP_ROW_PRICE + row]->seed = 0;
        self->ent[SHOP_ROW_NAME + row]->b8B = 7;
        self->ent[SHOP_ROW_LOCK + row]->flags &= ~SHOP_HIDE;
        if (item >= SHOP_ITEMS) {
            self->ent[SHOP_ROW_NUMBER + row]->seed = 0;
            continue;
        }
        if (D_0042AD58[item].stage == -1
            || (cCoreSave_getClearNum(&D_00569B70) == 0
                && D_0042AD58[item].stage >= cCoreSave_findNextStage(&D_00569B70))
            || ++shown <= self->scroll) {
            row--;
            continue;
        }
        self->rowReel[row] = D_0042AD58[item].reel;
        self->ent[SHOP_ROW_NAME + row]->msg = D_0042AD58[item].msg;
        self->ent[SHOP_ROW_PRICE + row]->seed = D_0042AD58[item].price;
        if (self->state == 1 && row == self->cursor) {
            self->title->msg = item + SHOP_MSG_INFO;
            self->subtitle->msg = item + SHOP_MSG_INFO;
        }
        if (row == self->cursor) {
            if (D_007474A0.language == 0) {
                self->stageName->sclX = 0.7f;
            } else {
                self->stageName->sclX = 0.6f;
            }
            self->stageName->msg = D_0042AD58[item].stageMsg + SHOP_MSG_STAGE;
            self->stageInfo->msg = D_0042AD58[item].stageMsg + SHOP_MSG_STAGE;
        }
        if (!cCoreSave_ckGodReel(&D_00569B70, D_0042AD58[item].reel)
            && cCoreSave_getGold(&D_00569B70) >= (int)self->ent[SHOP_ROW_PRICE + row]->seed) {
            self->ent[SHOP_ROW_LOCK + row]->flags |= SHOP_HIDE;
            self->ent[SHOP_ROW_NAME + row]->b8B = 6;
            if (!cCoreSave_ckClearStage(&D_00569B70, (unsigned short)(D_0042AD58[item].stage + 1))
                && D_0042AD58[item].stage != -1
                && cCoreSave_getClearNum(&D_00569B70) == 0) {
                self->ent[SHOP_ROW_NEW + row]->flags &= ~SHOP_HIDE;
            }
        } else if (cCoreSave_ckGodReel(&D_00569B70, D_0042AD58[item].reel)) {
            self->ent[SHOP_ROW_LOCK + row]->flags &= ~SHOP_HIDE;
            self->ent[SHOP_ROW_NAME + row]->b8B = 7;
        } else {
            self->ent[SHOP_ROW_LOCK + row]->flags |= SHOP_HIDE;
            self->ent[SHOP_ROW_NAME + row]->b8B = 7;
            if (!cCoreSave_ckClearStage(&D_00569B70, (unsigned short)(D_0042AD58[item].stage + 1))
                && D_0042AD58[item].stage != -1
                && cCoreSave_getClearNum(&D_00569B70) == 0) {
                self->ent[SHOP_ROW_NEW + row]->flags &= ~SHOP_HIDE;
            }
        }
    }

    count = self->itemCount;
    if (count <= 5) {
        count = SHOP_ROWS;
    }
    self->ent[SHOP_SCROLLBAR]->sclY = 6.0f / count;
    self->ent[SHOP_SCROLLBAR]->posY = self->ent[SHOP_SCROLLBAR]->src->posY
        + self->ent[SHOP_SCROLLBAR]->src->f18 * (1.0f - self->ent[SHOP_SCROLLBAR]->sclY)
          * (self->scroll / (count - 6.0f));
}
#else
INCLUDE_ASM("asm/nonmatching", func_00169DF8);
#endif
