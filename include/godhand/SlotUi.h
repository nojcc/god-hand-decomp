/* include/godhand/SlotUi.h - SlotUi, the slot machine's on-screen panel.
 *
 * SlotUi is a cIDBase whose display entries are CustomIDWork records
 * (0x7C bytes each): ten at 0x50 (the reel and line marks) and two at 0x580
 * (the bet marks). A second cIDBase sits at 0x530. The panel owns a heap node
 * at 0x678. Slot1 (at 0x4D0) and Slot2 (at 0x400) embed it: func_001E7118
 * constructs it, func_001E71B8 loads it, func_001E73C0 and func_001E7440 run
 * and draw it, and SlotUi_release releases it.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SLOTUI_H
#define GODHAND_SLOTUI_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

#define SLOTUI_MARK_NUM      10         /* entries at markBase */
#define SLOTUI_BET_NUM       2          /* entries at betBase */

/* The global record at **D_003C2384; only the two words cleared at release are named. */
typedef struct SlotUiHost {
    char unk00[0x88];
    int pickA;                          /* 0x88 */
    int pickB;                          /* 0x8C */
} SlotUiHost;

typedef struct SlotUi {
    cIDBaseObj id;                      /* 0x000 the marks' display */
    char unk048[0x50 - sizeof(cIDBaseObj)];
    CustomIDWork mark[SLOTUI_MARK_NUM]; /* 0x050 the reel and line marks; mark[0] shows the gold */
    char unk528[0x530 - 0x50 - SLOTUI_MARK_NUM * sizeof(CustomIDWork)];
    cIDBaseObj id2;                     /* 0x530 the bet marks' display */
    char unk578[0x580 - 0x530 - sizeof(cIDBaseObj)];
    CustomIDWork bet[SLOTUI_BET_NUM];   /* 0x580 the bet marks; bet[1] shows a message */
    int *node;                          /* 0x678 heap node, 0 when none; word -8 is its heap */
} SlotUi;                               /* 0x67C */

typedef char SlotUi_node_check[(int)&((SlotUi *)0)->node == 0x678 ? 1 : -1];

/* Construct both id bases and the twelve marks; returns self. */
SlotUi *func_001E7118(SlotUi *self);
/* Load the panel's data (id set 0x11) and set up both displays with id `id`; the gold reads 0. */
void func_001E71B8(SlotUi *self, int id);
/* Run the marks and both displays one frame. */
void func_001E73C0(SlotUi *self);
/* Draw both displays. */
void func_001E7440(SlotUi *self);
/* Show (show set) or hide mark no; SLOTUI_MARK_NUM means every mark. */
void func_001E7470(SlotUi *self, int no, int show);
/* Show or hide bet mark no; SLOTUI_BET_NUM means both. */
void func_001E7538(SlotUi *self, int no, int show);
/* Set the number of marks 3..8 (one function each). */
void func_001E7848(SlotUi *self, int number);
void func_001E7868(SlotUi *self, int number);
void func_001E7888(SlotUi *self, int number);
void func_001E78A8(SlotUi *self, int number);
void func_001E78C8(SlotUi *self, int number);
void func_001E78E8(SlotUi *self, int number);
/* Hide every mark and bet mark, then show the first and last mark. */
void SlotUi_showEndMarks(SlotUi *self);
/* Release both id bases, clear the host's two pick words and free the heap node. */
void SlotUi_release(SlotUi *self);
/* Show or hide marks 2..8. */
void SetUiIdWorkDispRange(SlotUi *self, int show);
/* Put message messNo on bet mark 1, then show or hide both bet marks. */
void UiPanel_setMessAndShow(SlotUi *self, int messNo, int on);
/* Colour mark 1: mode 0 clears it, 1 fades between two greys, 2 sets one grey; then show it (hide for 0). */
void CustomIDOwner_setColorMode(SlotUi *self, unsigned char mode);

#endif
