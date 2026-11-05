/* include/godhand/cDamageManage.h - cDamageManage, the pools of damage records.
 *
 * The manager holds every give record (an attack's damage) and every take
 * record (a target's hit volumes). The create calls hand out the first record
 * that is not live; when none is free they return the spare record after the
 * pools, whose type is CDAMAGE_TYPE_SPARE so the setup on it does nothing.
 * hitStop counts frames down while the hit pause runs.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail.
 */
#ifndef GODHAND_CDAMAGEMANAGE_H
#define GODHAND_CDAMAGEMANAGE_H

#include "godhand/cDamageGive.h"
#include "godhand/cDamageUnit.h"

#define CDAMAGE_GIVE_MAX  160           /* cDamageManage.give */
#define CDAMAGE_TAKE_MAX  256           /* cDamageManage.take */

typedef struct cDamageManage {
    cDamageGive give[CDAMAGE_GIVE_MAX]; /* 0x0000 */
    cDamageUnit take[CDAMAGE_TAKE_MAX]; /* 0x3C00 */
    cDamageGive giveSpare;              /* 0xAC00 handed out when every give is live */
    cDamageUnit takeSpare;              /* 0xAC60 handed out when every take is live */
    int hitStop;                        /* 0xACD0 frames of hit pause left */
} cDamageManage;

typedef char cDamageManage_hitStop_check[((int)&((cDamageManage *)0)->hitStop == 0xACD0) ? 1 : -1];

/* The damage manager. */
extern cDamageManage D_00574380;

/* Reset both pools. */
void InitPools_1FDFA8(cDamageManage *self);
/* Each frame: count the hit pause down, or update every live record. */
void func_001FDFD8(cDamageManage *self);
/* A give record for owner, set up for kind. */
cDamageGive *cDamageManage_CreateDamageGive(cDamageManage *self, int kind, void *owner);
/* Release give's volumes and reset it; 0 when give is 0. */
int cDamageManage_ReleaseDamageGive(cDamageManage *self, cDamageGive *give);
/* Release every give record. */
void InitEntryPool_1FE188(cDamageManage *self);
/* The first give that is not live, or the spare. */
cDamageGive *func_001FE1E0(cDamageManage *self);
/* A take record for owner, set up for kind. */
cDamageUnit *cDamageManage_CreateDamageTake(cDamageManage *self, void *owner, int kind);
/* Release take's volumes and reset it; 0 when take is 0. */
int ClearAndResetFields_1FE278(cDamageManage *self, cDamageUnit *take);
/* Release every take record. */
void InitNodePool_1FE2B8(cDamageManage *self);
/* The first take that is not live, or the spare. */
cDamageUnit *func_001FE310(cDamageManage *self);
/* hitStop = frames. */
void SetField_ACD0_1FE348(cDamageManage *self, int frames);
/* Nonzero while the hit pause runs. */
int cDamageManage_CkHitStop(cDamageManage *self);
/* Release every give and take record owner holds. */
void func_001FE370(cDamageManage *self, void *owner);

#endif
