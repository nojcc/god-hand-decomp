/* include/godhand/Slot1.h - the first slot machine.
 *
 * Slot1 is the casino slot machine game object, sibling of Slot2 (Slot2.h).
 * It runs the same state machine: `state` picks the screen, `step` walks one
 * screen through its stages, `phase` walks one stage, and `timer` counts
 * frames down. The reel records start at 0x58. The prize paid for each of the
 * six winning lines sits in prize[] at 0x3CC.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SLOT1_H
#define GODHAND_SLOT1_H

#include "godhand/SlotUi.h"

#define SLOT1_LINE_NUM     6         /* winning lines, one prize each */
#define SLOT1_PAYMODE_ON   9         /* payMode while the payout runs */
#define SLOT1_REEL_NUM     3
#define SLOT1_LINE_WEIGHTS 4

/* Each reel and the prize board run the same state/step/phase machine as
 * the machine itself. */
typedef struct Slot1Reel {
    int unk00;
    int state;                      /* 0x004 */
    int step;                       /* 0x008 */
    int phase;                      /* 0x00C */
    char unk10[0xB0];
    unsigned int doneFlag;          /* 0x0C0 bit 0 = stopped, bit 1 = settled */
    char unkC4[0x40];
    short stopMode;                 /* 0x104 2 = stop on the drawn bonus, 0x15 = free */
    char unk106[2];
} Slot1Reel;                        /* 0x108 */

typedef struct Slot1Panel {
    int unk00;
    int state;                      /* 0x04 */
    int step;                       /* 0x08 */
    int phase;                      /* 0x0C */
    char unk10[0x44];
    unsigned int doneFlag;          /* 0x54 bit 0 = the board is settled */
    char unk58[4];
} Slot1Panel;                       /* 0x5C */

/* One in n chance of each bonus. */
typedef struct Slot1Odds {
    int n[SLOT1_LINE_WEIGHTS];
} Slot1Odds;

/* The bonus kinds payMode takes before a payout. */
typedef struct Slot1BonusTbl {
    int kind[7];
} Slot1BonusTbl;

typedef struct Slot1 {
    char unk00[4];
    int state;                      /* 0x004 screen */
    int step;                       /* 0x008 stage inside the screen */
    int phase;                      /* 0x00C stage inside the step */
    int timer;                      /* 0x010 frames until the next stage */
    char unk14[0x14];
    int coinUnit;                   /* 0x028 gold per paid coin */
    int coinNum;                    /* 0x02C coins still to pay */
    char unk30[0x24];
    unsigned int endFlag;           /* 0x054 bit 0 = the game is over, bit 8 = halve the bonus odds */
    Slot1Reel reel[SLOT1_REEL_NUM]; /* 0x058 */
    Slot1Panel panel;               /* 0x370 */
    int prize[SLOT1_LINE_NUM];      /* 0x3CC prize per winning line */
    Slot1Odds bonusOdds;            /* 0x3E4 */
    char unk3F4[0x70];
    int bonusLayer0;                /* 0x464 layer shown for bonus kind 0 */
    char unk468[4];
    int bonusLayer1;                /* 0x46C layer shown for bonus kind 1 */
    char unk470[4];
    int bonusLayer8;                /* 0x474 layer shown for bonus kind 8 */
    char unk478[0x14];
    unsigned short atId;            /* 0x48C scene trigger turned back on when the machine closes */
    unsigned short markSel;         /* 0x48E */
    int payMode;                    /* 0x490 set to SLOT1_PAYMODE_ON while a prize is paid out */
    unsigned short slotId;          /* 0x494 */
    char unk496[0x2E];
    int seStart;                    /* 0x4C4 sound handle of the start lever */
    int seId;                       /* 0x4C8 sound handle of the payout loop */
    char unk4CC[4];
    SlotUi ui;                      /* 0x4D0 on-screen panel */
    char unkB4C[4];
    short debugRow;                 /* 0xB50 debug menu row, 0..1 */
    short debugReel;                /* 0xB52 debug menu reel result, 0..7 */
} Slot1;

/* Fails to compile if a field drifts from the offset retail uses. */
typedef char Slot1_prize_check[(int)&((Slot1 *)0)->prize == 0x3CC ? 1 : -1];
typedef char Slot1_payMode_check[(int)&((Slot1 *)0)->payMode == 0x490 ? 1 : -1];
typedef char Slot1_seId_check[(int)&((Slot1 *)0)->seId == 0x4C8 ? 1 : -1];
typedef char Slot1_atId_check[(int)&((Slot1 *)0)->atId == 0x48C ? 1 : -1];
typedef char Slot1_ui_check[(int)&((Slot1 *)0)->ui == 0x4D0 ? 1 : -1];
typedef char Slot1_panel_check[(int)&((Slot1 *)0)->panel == 0x370 ? 1 : -1];
typedef char Slot1_bonusLayer8_check[(int)&((Slot1 *)0)->bonusLayer8 == 0x474 ? 1 : -1];
typedef char Slot1_seStart_check[(int)&((Slot1 *)0)->seStart == 0x4C4 ? 1 : -1];
typedef char Slot1_debugRow_check[(int)&((Slot1 *)0)->debugRow == 0xB50 ? 1 : -1];


#endif
