/* include/godhand/cSubScrShopMain.h - the skill shop's main screen
 * (retail class 15cSubScrShopMain, id resource "idskillshop").
 *
 * An id display object (cIDObj head) with two more id displays, idBaseB
 * and idBaseC. func_001612C8 builds it at 0xC40 in the sub screen manager;
 * its vtable D_0041FDF8 holds func_00168560 (open) and Screen_closeCasino
 * (close). Opening takes the sub screen camera and saves the player's rot,
 * closing puts the rot back.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact; the record's size isn't known.
 */
#ifndef GODHAND_CSUBSCRSHOPMAIN_H
#define GODHAND_CSUBSCRSHOPMAIN_H

#include "godhand/cIDObj.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamManager.h"

#define SUBSCR_SHOP_ENT_NUM     19      /* entries of the main display */
#define SUBSCR_SHOP_ENTB_NUM    37      /* entries of idBaseB */

typedef struct cSubScrShopMain {
    cIDObj obj;                                     /* 0x000 */
    char unk74[0x80 - sizeof(cIDObj)];
    cIDBaseEnt *ent[SUBSCR_SHOP_ENT_NUM];           /* 0x080 */
    char unkCC[0xD0 - 0xCC];
    cIDBaseObj idBaseB;                             /* 0x0D0 */
    char unk118[0x120 - 0x118];
    cIDBaseEnt *entB[SUBSCR_SHOP_ENTB_NUM];         /* 0x120 */
    unsigned char unk1B4;                           /* 0x1B4 */
    char unk1B5[0x1D0 - 0x1B5];
    short unk1D0;                                   /* 0x1D0 */
    short unk1D2;                                   /* 0x1D2 */
    unsigned char unk1D4;                           /* 0x1D4 */
    char unk1D5[0x1D8 - 0x1D5];
    cGameObj *player;                               /* 0x1D8 */
    cGameObj *jacket;                               /* 0x1DC */
    struct cCamera *camera;                         /* 0x1E0 the sub screen camera */
    char unk1E4[0x1F0 - 0x1E4];
    cVec target;                                    /* 0x1F0 the player's rot while the screen is open */
    char unk200[0x210 - 0x200];
    cIDBaseObj idBaseC;                             /* 0x210 */
    char unk258[0x260 - 0x258];
    short unk260[5];                                /* 0x260 */
    char unk26A[0x26C - 0x26A];
    int unk26C[5];                                  /* 0x26C */
    char unk280[0x282 - 0x280];
    short unk282;                                   /* 0x282 */
    char unk284[0x286 - 0x284];
    unsigned char unk286;                           /* 0x286 */
} cSubScrShopMain;

typedef char cSubScrShopMain_idBaseB_check[(int)&((cSubScrShopMain *)0)->idBaseB == 0xD0 ? 1 : -1];
typedef char cSubScrShopMain_target_check[(int)&((cSubScrShopMain *)0)->target == 0x1F0 ? 1 : -1];
typedef char cSubScrShopMain_idBaseC_check[(int)&((cSubScrShopMain *)0)->idBaseC == 0x210 ? 1 : -1];
typedef char cSubScrShopMain_unk286_check[(int)&((cSubScrShopMain *)0)->unk286 == 0x286 ? 1 : -1];

#endif
