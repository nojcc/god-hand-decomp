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
    char idBase[0x10];          /* 0x60 sub-object released at close */
    char unk70[0x37A8 - 0x70];
    ColiseumRing ring;          /* 0x37A8 the ring under the cursor */
    short cursor;               /* 0x37D0 ring under the cursor */
    short row;                  /* 0x37D2 cursor row in the list, 0..6 */
    short top;                  /* 0x37D4 ring in the first row */
    short ringNum;              /* 0x37D6 rings in the list */
    int *cardNode;              /* 0x37D8 heap node, 0 when none */
} ColiseumEmSelect;

typedef char ColiseumEmSelect_cardNode_check[(int)&((ColiseumEmSelect *)0)->cardNode == 0x37D8 ? 1 : -1];

#endif
