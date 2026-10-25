/* include/godhand/cSubScrMenu.h - the sub-screen menu (retail class 11cSubScrMenu).
 *
 * The status screen of the pause menu: an id display object (cIDObj head,
 * obj.state the row under the cursor, obj.step the stage picture change)
 * with three more displays: the status panel (difficulty marks and the
 * vital, life and heat gauges), the item panel (god items and reel items)
 * and the level panel. Each display keeps the entries it looks up by id.
 * The page keys pick one of the open stages; its picture is read from disc
 * into the menu's kept file (FileHolder_reload) and cross-faded in.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact.
 */
#ifndef GODHAND_CSUBSCRMENU_H
#define GODHAND_CSUBSCRMENU_H

#include "godhand/cIDObj.h"

#define SUBSCR_MENU_ENT_NUM      0x1F   /* entries of the main display */
#define SUBSCR_MENU_STATUS_NUM   10
#define SUBSCR_MENU_ITEM_NUM     0x13
#define SUBSCR_MENU_LEVEL_NUM    6

#define SUBSCR_MENU_STAGE_NUM    0x18   /* records in D_0041F718 */

#define SUBSCR_MENU_NOPAGE  0x02        /* flags: the page keys are ignored (picture being read) */
#define SUBSCR_MENU_NOOK    0x01        /* flags: OK is ignored (picture changing) */

/* One stage record: the picture file and the clear it waits for. */
typedef struct cSubScrMenuStage {
    char file[0x20];                    /* 0x00 picture shown for the stage */
    unsigned short stage;               /* 0x20 stage number */
    unsigned short limit;               /* 0x22 minutes of stage time that also unlock it */
} cSubScrMenuStage;                     /* 0x24 */

typedef struct cSubScrMenu {
    cIDObj obj;                                     /* 0x000 obj.state is the picked row */
    char unk74[0x80 - sizeof(cIDObj)];
    cIDBaseEnt *ent[SUBSCR_MENU_ENT_NUM];           /* 0x080 */
    char unkFC[4];
    cIDBaseObj status;                              /* 0x100 */
    char unk148[0x158 - 0x148];
    cIDBaseEnt *statusEnt[SUBSCR_MENU_STATUS_NUM];  /* 0x158 */
    cIDBaseObj items;                               /* 0x180 */
    char unk1C8[0x1D0 - 0x1C8];
    cIDBaseEnt *itemEnt[SUBSCR_MENU_ITEM_NUM];      /* 0x1D0 god items 0..5, reel items 7..12 */
    char unk21C[0x230 - 0x21C];
    cIDBaseObj level;                               /* 0x230 */
    char unk278[0x280 - 0x278];
    cIDBaseEnt *levelEnt[SUBSCR_MENU_LEVEL_NUM];    /* 0x280 */
    int *data;                                      /* 0x298 the file FileHolder_reload keeps (the stage picture), 0 when none */
    int jobId;                                      /* 0x29C disc job that read it */
    signed char stageSel;                           /* 0x2A0 stage picked, 0 = none, up to stageNum */
    signed char stageShown;                         /* 0x2A1 stage whose picture is up */
    unsigned char flags;                            /* 0x2A2 SUBSCR_MENU_* */
    signed char wait;                               /* 0x2A3 frames before the picture may change */
    signed char stageNum;                           /* 0x2A4 stages open */
} cSubScrMenu;

typedef char cSubScrMenu_data_check[(int)&((cSubScrMenu *)0)->data == 0x298 ? 1 : -1];
typedef char cSubScrMenu_stageNum_check[(int)&((cSubScrMenu *)0)->stageNum == 0x2A4 ? 1 : -1];
typedef char cSubScrMenuStage_size_check[sizeof(cSubScrMenuStage) == 0x24 ? 1 : -1];

extern cSubScrMenuStage D_0041F718[SUBSCR_MENU_STAGE_NUM]; /* stage n's record is [n - 1] */

/* Free the kept file, read `name` into it again and wait for the read. */
void FileHolder_reload(cSubScrMenu *self, const char *name);
/* Move the status, item and level displays. */
void func_001661A0(cSubScrMenu *self);

#endif
