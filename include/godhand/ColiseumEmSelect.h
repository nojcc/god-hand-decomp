/* include/godhand/ColiseumEmSelect.h - ColiseumEmSelect, the coliseum enemy pick screen.
 *
 * The screen is a large object (more than 0x37E0 bytes). The fields below
 * are the ones the recovered methods touch; the rest stays unkNNN.
 * func_001F46E0 releases the sub-object at 0x60 (a cIDBase). cardNode at
 * 0x37D8 is a heap node owned by the screen; the node's word at -0x20 is its
 * heap. Offsets are exact.
 */
#ifndef GODHAND_COLISEUMEMSELECT_H
#define GODHAND_COLISEUMEMSELECT_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/ColiseumBattle.h"

/* The global record at **D_003C2384; only the two words cleared at close are named. */
typedef struct ColiseumHost {
    char unk00[0xA8];
    int pickA;                  /* 0xA8 */
    int pickB;                  /* 0xAC */
} ColiseumHost;

#define COLISEUMEM_ITEM     0x1F    /* the seven item boxes, elements 0x1F..0x25 */
#define COLISEUMEM_ELEM_NUM 0x6F    /* display elements; SetCustomIDDispOneOrAll_1F4778 takes 0x6F for all of them */

/* The pick screen's display at 0x60: a cIDBase and the elements its methods
 * (0x1F45D8..0x1F5650) show, number and move. */
typedef struct ColiseumEmDisp {
    int unk000;                         /* 0x000 cleared by func_001F45D8 */
    char unk004[0x10 - 4];
    cIDBaseObj id;                      /* 0x010 the elements' display */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[COLISEUMEM_ELEM_NUM]; /* 0x060 */
} ColiseumEmDisp;                       /* 0x3664 */

typedef struct ColiseumEmSelect {
    char unk000[0x04];
    int vtIndex;                /* 0x04 index into the D_003BF0A8 dispatch table */
    int step;                   /* 0x08 */
    int unk0C;                  /* 0x0C */
    char unk010[0x54 - 0x10];
    unsigned int flags;         /* 0x54 COLISEUM_FLAG_* */
    char unk058[0x60 - 0x58];
    ColiseumEmDisp idBase;      /* 0x060 the display, released at close */
    char unk36C4[0x37A8 - 0x60 - sizeof(ColiseumEmDisp)];
    ColiseumRing ring;          /* 0x37A8 the ring under the cursor */
    short cursor;               /* 0x37D0 ring under the cursor */
    short row;                  /* 0x37D2 cursor row in the list, 0..6 */
    short top;                  /* 0x37D4 ring in the first row */
    short ringNum;              /* 0x37D6 rings in the list */
    int *cardNode;              /* 0x37D8 heap node, 0 when none */
} ColiseumEmSelect;

typedef char ColiseumEmSelect_cardNode_check[(int)&((ColiseumEmSelect *)0)->cardNode == 0x37D8 ? 1 : -1];

/* Stop the screen fade if one is running. */
void func_001F44E0(ColiseumEmSelect *self);
/* Whether enemy em can be picked for stage; self is not read. */
int func_001F4530(ColiseumEmSelect *self, int em, int stage);

/* ColiseumEmDisp methods. */
/* Clear word 0, construct the ID base and the 0x6F elements; returns self. */
ColiseumEmDisp *func_001F45D8(ColiseumEmDisp *self);
/* Set up the ID base (set 0x15) and the elements, then hide them all. */
void InitUiIdWorksAndShowAll(ColiseumEmDisp *self);
/* Release, move (after running the elements) or draw the ID base. */
void func_001F46E0(ColiseumEmDisp *self);
void func_001F4700(ColiseumEmDisp *self);
void func_001F4758(ColiseumEmDisp *self);
/* Show (on set) or hide element id; id COLISEUMEM_ELEM_NUM means every element. */
void SetCustomIDDispOneOrAll_1F4778(ColiseumEmDisp *self, int id, int on);
/* Hide everything, show elements 0..9, elements 0x61..0x67 and the gauge block 0x50..0x60. */
void DispMenu_open(ColiseumEmDisp *self);
/* Hide elements 0x50..0x60, then show them again when on is set. */
void func_001F4928(ColiseumEmDisp *self, int on);
/* Set element 2's number (the gold). */
void func_001F4B78(ColiseumEmDisp *self, int number);
/* Hide both marks of slot no and, if lit, show the left (right 0) or the right one. */
void Panel_showSlotMark(ColiseumEmDisp *self, unsigned short no, int right, int lit);
/* Set the number of element 0x18 + slot (slot 0..6) and show or hide it. */
void SetCustomIDSlotNumber_1F4C40(ColiseumEmDisp *self, unsigned short slot, int number, int on);
/* Set column idx (0..6, element 0x26 + idx) to a number, nudged left by its digit count, and show or hide it. */
void CustomIDOwner_setColumnNumber(ColiseumEmDisp *self, unsigned short idx, int number, int on);
/* Fill row idx (0..6) of the time table, or show its "no time" message when val is 0. */
void CustomIDOwner_setTimeRow(ColiseumEmDisp *self, unsigned short idx, int val, int show);
/* Set the number of element 0x42 + slot (slot 0..6) and show or hide it. */
void SetCustomIDSlotNumberAlt_1F5210(ColiseumEmDisp *self, unsigned short slot, int number, int on);
/* Show or hide element 0x49 + value (value 0..6). */
void func_001F5278(ColiseumEmDisp *self, unsigned short value, int on);
/* Place elements 8 and 9 at the Y of position idx (0..6) and show or hide them. */
void CustomIDWork_placeByIndex(ColiseumEmDisp *self, unsigned short idx, int on);
/* Start (on set) or stop the pulse of the selection mark, elements 8 and 9. */
void MarkObj_setPulse(ColiseumEmDisp *self, int on);
/* Show or hide elements 0x61..0x67. */
void CustomIDOwner_setAllShown(ColiseumEmDisp *self, int on);
/* Set item box idx (0..6) by mode: its UV rectangle, f68 and x position; then show or hide it. */
void func_001F4CA8(ColiseumEmDisp *self, unsigned short idx, int mode, int on);
/* Scale bar element 102 to b / a (at most 1) of element 100's f6C and start the arrows 97 and 98 bobbing. */
void func_001F5510(ColiseumEmDisp *self, int a, int b);
/* Move bar element 102 down by element 100's f6C times a3 / a1. */
void func_001F55C0(ColiseumEmDisp *self, int a1, int a2, int a3);
/* Rebuild the status panel: hide it, then show only the frame or the four gauges and `lit` of `num` pips. */
void func_001F5650(ColiseumEmDisp *self, unsigned char mode, short gauge0, short gauge1, short gauge2, short gauge3,
                   short num, short lit);

#endif
