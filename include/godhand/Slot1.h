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
    int endFlag;                    /* 0x054 bit 0 = the game is over */
    char reel[0x374];               /* 0x058 reel records, the first one at 0x58 */
    int prize[SLOT1_LINE_NUM];      /* 0x3CC prize per winning line */
    char unk3E4[0xA8];
    unsigned short atId;            /* 0x48C scene trigger turned back on when the machine closes */
    unsigned short markSel;         /* 0x48E */
    int payMode;                    /* 0x490 set to SLOT1_PAYMODE_ON while a prize is paid out */
    unsigned short slotId;          /* 0x494 */
    char unk496[0x32];
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
typedef char Slot1_debugRow_check[(int)&((Slot1 *)0)->debugRow == 0xB50 ? 1 : -1];

#endif
