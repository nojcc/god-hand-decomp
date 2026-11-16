/* include/godhand/Slot1.h - the first slot machine.
 *
 * Slot1 is the casino slot machine game object, sibling of Slot2 (Slot2.h).
 * It runs the same state machine: `state` picks the screen, `step` walks one
 * screen through its stages, `phase` walks one stage, and `timer` counts
 * frames down. The three reel records start at 0x58, the prize board (laid
 * out as Slot2's) at 0x370. The prize paid for each of the six winning lines
 * sits in prize[] at 0x3CC. The marks blink through flag words at 0x49C..0x4C0
 * (bit 15 armed, bit 14 shown, the low bits count frames) that show and hide
 * scroll layers.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SLOT1_H
#define GODHAND_SLOT1_H

#include "godhand/SlotUi.h"
#include "godhand/Slot2.h"     /* Slot2Panel */

struct cModel;
struct cCamera;

#define SLOT1_LINE_NUM     6         /* winning lines, one prize each */
#define SLOT1_PAYMODE_ON   9         /* payMode while the payout runs */
#define SLOT1_REEL_NUM     3
#define SLOT1_REEL_SIZE    0x108
#define SLOT1_BET_MAX      3
#define SLOT1_LAYER_NUM    35        /* scroll layer ids, 0x400..0x488 */
#define SLOT1_MARK_NUM     7         /* blink words markFlag[], 0x49C..0x4A8 */
#define SLOT1_F_DRIFT_SET   0x100  /* flags: the win stage set the drift layers up (the intro stage clears it) */
#define SLOT1_F_DRIFT       0x200  /* flags: the drift layers are shown and the objects move */
#define SLOT1_MARK_F_START_LIT 0x8000  /* markFlag[]: blink armed / start lit */
#define SLOT1_MARK_F_ON     0x4000  /* markFlag[]: shown */
#define SLOT1_MARK0_LAYER   18     /* scrollLayer[] index of markFlag[0]'s layer; marks 1 and 2 follow */
#define SLOT1_MARK6_LAYER   12     /* scrollLayer[] index of markFlag[6]'s layer */
#define SLOT1_MARK_LAYER_A  12     /* scrollLayer[] indices of a payout mark's four layers: A and B are */
#define SLOT1_MARK_LAYER_B  31     /* shared, the other two are the pair of markFlag[3], [4] or [5] */
#define SLOT1_MARK3_LAYERS  25
#define SLOT1_MARK4_LAYERS  27
#define SLOT1_MARK5_LAYERS  29

/* A reel: the same state machine head as Slot2Reel, in a larger record. */
typedef struct Slot1Reel {
    int unk00;
    int state;                      /* 0x04 */
    int step;                       /* 0x08 */
    int phase;                      /* 0x0C */
    char unk10[0xB0];
    unsigned int doneFlag;          /* 0xC0 bit 0 set once the reel stopped */
    char unkC4[SLOT1_REEL_SIZE - 0xC4];
} Slot1Reel;                        /* 0x108 */

typedef char Slot1Reel_size_check[sizeof(Slot1Reel) == SLOT1_REEL_SIZE ? 1 : -1];

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
    int flags;                      /* 0x054 bit 8 set by func_001E2EB8; bit 9: the drift layers are shown and the objects move */
    Slot1Reel reel[SLOT1_REEL_NUM]; /* 0x058 */
    Slot2Panel panel;               /* 0x370 the prize board */
    int betCost;                    /* 0x3C8 gold per bet level */
    int prize[SLOT1_LINE_NUM];      /* 0x3CC prize per winning line */
    char unk3E4[0x400 - 0x3E4];
    int scrollLayer[SLOT1_LAYER_NUM]; /* 0x400 scroll layer ids: 0..11 the scroll rows, the rest the marks */
    unsigned short unk48C;          /* 0x48C 0xFFFF after construction */
    unsigned short betLv;           /* 0x48E bet level 0..SLOT1_BET_MAX */
    int payMode;                    /* 0x490 set to SLOT1_PAYMODE_ON while a prize is paid out */
    unsigned short slotId;          /* 0x494 */
    char unk496[2];
    struct cCamera *subCam;         /* 0x498 the sub-screen camera, set by func_001E32E8 */
    unsigned short markFlag[SLOT1_MARK_NUM]; /* 0x49C mark blink words */
    unsigned short scroll;          /* 0x4AA scroll counter: bit 15 running, bit 14 shown, bits 11..13 row */
    unsigned short selFlag;         /* 0x4AC mark selector blink word, bits 11..13 the selected mark */
    char unk4AE[2];
    struct cModel *drift[2];        /* 0x4B0 two objects that drift left while flags bit 9 is set */
    int unk4B8;                     /* 0x4B8 */
    int unk4BC;                     /* 0x4BC */
    unsigned short keepFlag;        /* 0x4C0 mark blink word, bit 11 kept across the flip */
    unsigned short blinkTimer;      /* 0x4C2 frames of blinking left */
    char unk4C4[4];
    int seId;                       /* 0x4C8 sound handle of the payout loop */
    char unk4CC[4];
    SlotUi ui;                      /* 0x4D0 */
    char unkB4C[4];
    short unkB50;                   /* 0xB50 */
    short unkB52;                   /* 0xB52 */
} Slot1;                            /* at least 0xB54 */

/* Fails to compile if a field drifts from the offset retail uses. */
typedef char Slot1_prize_check[(int)&((Slot1 *)0)->prize == 0x3CC ? 1 : -1];
typedef char Slot1_payMode_check[(int)&((Slot1 *)0)->payMode == 0x490 ? 1 : -1];
typedef char Slot1_seId_check[(int)&((Slot1 *)0)->seId == 0x4C8 ? 1 : -1];
typedef char Slot1_ui_check[(int)&((Slot1 *)0)->ui == 0x4D0 ? 1 : -1];
typedef char Slot1_panel_check[(int)&((Slot1 *)0)->panel == 0x370 ? 1 : -1];
typedef char Slot1_markFlag_check[(int)&((Slot1 *)0)->markFlag == 0x49C ? 1 : -1];
typedef char Slot1_keepFlag_check[(int)&((Slot1 *)0)->keepFlag == 0x4C0 ? 1 : -1];
typedef char Slot1_betLv_check[(int)&((Slot1 *)0)->betLv == 0x48E ? 1 : -1];
typedef char Slot1_unkB50_check[(int)&((Slot1 *)0)->unkB50 == 0xB50 ? 1 : -1];

/* The marks, once a frame: while a blink word is armed, count frames, then flip
 * its shown bit and show or hide the mark's layers. */
void Slot2_blinkMarkTick(Slot1 *self);
void Slot2_blinkMarksAt4A2(Slot1 *self);
void Slot2_blinkMarks(Slot1 *self);
void Slot2_blinkMarksAt4A6(Slot1 *self);
void Slot2_updateMarkAt4A8(Slot1 *self);
void Slot2_stepMarkSelector(Slot1 *self);
void Slot2_updateMarkAt4C0(Slot1 *self);
/* Drift the two objects left while flags bit 9 is set; show layers 22 and 34 in a window of their path. */
void func_001E4610(Slot1 *self);
/* Hide the drift layers (sel 0), or hide them, put both objects back at x 0 and show the first pair (sel 1). */
void LayerScreen_hideLayers(Slot1 *self, unsigned char sel);
/* Store mark sel (below 5) in selFlag, arm it, and show only its layer (showAll) or hide all five. */
void Slot2_selectMark(Slot1 *self, unsigned int sel, int showAll, int armFlag);
/* Store row sel (below 5) in scroll, arm it, and show or hide that row's three layers and layer 11. */
void func_001E3E40(Slot1 *self, unsigned short sel, int show, int arm);
/* Set markFlag[3] (Slot2_setMarkLayersAt464), [4] (..46C) or [5] (Slot2_setMarkLayers) and show or hide its four layers. */
void Slot2_setMarkLayersAt464(Slot1 *self, int show, int startLit);
void Slot2_setMarkLayersAt46C(Slot1 *self, int show, int startLit);
void Slot2_setMarkLayers(Slot1 *self, int show, int startLit);
/* Arm keepFlag for mark (below 3) when lit, otherwise clear it and hide its layer. */
void MarkObj_setMarkFlag(Slot1 *self, unsigned short mark, int lit);
/* Set markFlag[0..2] for mark (below 3) and show or hide its layer. */
void MarkPanel_setMark(Slot1 *self, unsigned short mark, int show, int startLit);
/* Set markFlag[6] and show or hide layer 12. */
void func_001E3D78(Slot1 *self, int show, int startLit);
/* Show the five bet layers for betLv: none, the first, the first three or all five. */
void Slot2_showLayersForMode(Slot1 *self);
/* Hide every scroll layer. */
void Slot2_hideBankLayerIds(Slot1 *self);
/* Hide every scroll layer, then show layer 0 (sel) or layer 1. */
void Scroll_showLayerBySelector(Slot1 *self, int sel);
/* Per-frame update: run the state handler, blink the marks, step the reels, the board and the panel. */
void func_001E0210(Slot1 *self);
/* Switch to the sub-screen camera, keep it in subCam and copy eye and target into it. */
void func_001E32E8(Slot1 *self, float *eye, float *target);

#endif
