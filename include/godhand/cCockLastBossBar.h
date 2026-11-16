/* include/godhand/cCockLastBossBar.h - cCockLastBossBar, the final boss health bar of the cockfight.
 *
 * Same layout as cCockBossBar up to 0xA4, with four display entries at
 * 0xC0 and four flag bytes at 0x79 to 0x7C that roomInit clears.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCOCKLASTBOSSBAR_H
#define GODHAND_CCOCKLASTBOSSBAR_H

#include "godhand/cIDBase.h"

struct cGameObj;

#define COCKLASTBOSSBAR_ENT_NUM   4
#define COCKLASTBOSSBAR_MSG_PACK  0x1C  /* message pack number of the bar */

typedef struct cCockLastBossBar {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x79 - sizeof(cIDBaseObj)];
    unsigned char flag79;               /* 0x79 */
    unsigned char flag7A;               /* 0x7A */
    unsigned char flag7B;               /* 0x7B */
    unsigned char flag7C;               /* 0x7C */
    char unk7D[0x94 - 0x7D];
    void *data;                         /* 0x94 the loaded message pack, 0 before the first load */
    int readId;                         /* 0x98 disc read request */
    struct cGameObj *boss;              /* 0x9C the boss the bar is drawn for, 0 when none */
    unsigned int unkA0;                 /* 0xA0 set to 0x20000000 by roomInit */
    float unkA4;                        /* 0xA4 set to 1.0 by roomInit */
    char unkA8[0xC0 - 0xA8];
    cIDBaseEnt *ent[COCKLASTBOSSBAR_ENT_NUM];   /* 0xC0 display entries looked up by id 0..3 */
} cCockLastBossBar;

typedef char cCockLastBossBar_boss_check[(int)&((cCockLastBossBar *)0)->boss == 0x9C ? 1 : -1];
typedef char cCockLastBossBar_ent_check[(int)&((cCockLastBossBar *)0)->ent == 0xC0 ? 1 : -1];

typedef char cCockLastBossBar_size_check[sizeof(cCockLastBossBar) == 0xD0 ? 1 : -1];

/* Draw the bar while a boss with hit points is set, the ui is on and nothing holds the screen. */
void func_0013EBA0(cCockLastBossBar *self);
/* Forget the message pack and the boss. */
void ClearFields94And9C_13E7D8(cCockLastBossBar *self);

#endif
