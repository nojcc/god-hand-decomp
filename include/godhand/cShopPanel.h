/* include/godhand/cShopPanel.h - the shop panels of the subscreen (reels,
 * techniques).
 *
 * Both shops draw six rows of entries from the panel's entry table and keep
 * a scroll position and a cursor into the record list. Field names come from
 * the shop draw steps (func_00169358, func_00169DF8) and the row helper
 * func_0016BCE0; unkNNN stays where nobody has named a field.
 */
#ifndef GODHAND_CSHOPPANEL_H
#define GODHAND_CSHOPPANEL_H

#include "godhand/cIDMenuPanel.h"
#include "godhand/cGameObj.h"

#define SHOP_ROWS        6
#define SHOP_INPUTS      5                     /* combo inputs shown at once */

/* Entry-table indexes; a row's entry is the base plus the row. */
#define SHOP_ROW_NAME    5
#define SHOP_ROW_PRICE   11
#define SHOP_ROW_LOCK    17
#define SHOP_SCROLLBAR   23
#define SHOP_ROW_NUMBER  24
#define SHOP_ENT_HELP    30
#define SHOP_ROW_NEW     31

typedef struct ShopPanel {
    cIDPanelHead head;                  /* 0x00 head.step is the draw step */
    char unk64[0x8C - 0x64];
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
    cIDBaseEnt *ent[38];                /* 0x120 per-row entries, SHOP_ROW_* */
    int rowReel[SHOP_ROWS];             /* 0x1B8 reel shown on each row */
    short scroll;                       /* 0x1D0 first record shown */
    short cursor;                       /* 0x1D2 */
    signed char gaugeLevel;             /* 0x1D4 */
    char unk1D5[3];
    cGameObj *player;                   /* 0x1D8 the player model the technique shop demonstrates on */
    char unk1DC[0x200 - 0x1DC];
    short combo;                        /* 0x200 technique being demonstrated */
    short itemCount;                    /* 0x202 */
    char unk204[0x260 - 0x204];
    short inputTimer[SHOP_INPUTS];      /* 0x260 frames each shown input stays up */
    char unk26A[2];
    int input[SHOP_INPUTS];             /* 0x26C input shown in each slot, 0 = none */
    unsigned short prevMotion;          /* 0x280 player's motionFlags last frame */
    unsigned short inputNum;            /* 0x282 next input of the combo */
    char unk284[0x286 - 0x284];
    unsigned char closed;               /* 0x286 */
} ShopPanel;

void func_0016BCE0(ShopPanel *self, unsigned short index);

#endif
