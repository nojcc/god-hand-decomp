/* include/godhand/IdScreen4.h - IdScreen4, a cIDBase display with four entries.
 *
 * Its vtable sits at 0x0041DC94: func_0013C220 builds it and
 * IdScreen4_refillEntries restarts it. Field names are ours.
 */
#ifndef GODHAND_IDSCREEN4_H
#define GODHAND_IDSCREEN4_H

#include "godhand/cIDBase.h"

#define IDSCREEN4_ENT_NUM 4

typedef struct IdScreen4 {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x90 - sizeof(cIDBaseObj)];
    int unk90;                          /* 0x90 */
    int sel;                            /* 0x94 */
    cIDBaseEnt *ent[IDSCREEN4_ENT_NUM]; /* 0x98 */
} IdScreen4;

typedef char IdScreen4_ent_check[((int)&((IdScreen4 *)0)->ent == 0x98) ? 1 : -1];

/* Build the display (id 0xA) and cache its four entries. */
void func_0013C220(IdScreen4 *self);
/* Restart the animation and refill the four entries. */
void IdScreen4_refillEntries(IdScreen4 *self);

#endif
