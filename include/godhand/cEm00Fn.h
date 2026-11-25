/* include/godhand/cEm00Fn.h - cEm00 methods that more than one unit calls.
 *
 * cEm00.h holds the record. Older units declare several of these themselves
 * with their own parameter types, so the prototypes live here for the units
 * that take them from a header.
 */
#ifndef GODHAND_CEM00FN_H
#define GODHAND_CEM00FN_H

#include "godhand/cEm00.h"
#include "godhand/cDamageUnit.h"

/* Free the array at 0x1630 and clear the pointer. */
void func_0028CE70(cEm00 *self);
/* func_0028CE70(self). */
void func_0028BEA8(cEm00 *self);

int func_00274150(cEm00 *self);
int func_00274F50(cEm00 *self);
/* 1 while unk17CC is positive, else 0. */
int func_0026F1D8(cEm00 *self);
/* 1 after putting the enemy in phase 0x46; force == 1 skips the game-level dice. */
int func_0020CAC8(cEm00 *self, int force);
/* 1 after restoring hp from counterVital and starting func_00274238's kind 1. */
int func_0020D140(cEm00 *self);
/* 1 when the enemy holds nothing (slots 0x6EC, 0x6F0, 0x700, 0x704) and its kind is not one of 20 listed, else 0. */
int func_002740D8(cEm00 *self);

/* Release the weapon in unk6EC: break it for enemy 0x279, drop it otherwise. */
void ReleaseField6ECByTag564_26B1E8(cEm00 *self);
void EmWeaponHolder_dropWeapons(cEm00 *self, unsigned int count, int arg);
void cEm_breakHeldWeapons(cEm00 *self);
/* Aim at a type-0xC hit unit at the enemy's position and enter phase 0x88. */
int cEm00_startHitUnitAim(cEm00 *self);

/* Nonzero for enemy 0x211 with emFlags2 bit 0x20 set. */
int func_002744B8(cEm00 *em);

/* Create weapon object type at the enemy's position (CEM00_CREATE_WEAPON); 0 when it can't. */
struct cOmWeapon *func_0026AA30(cEm00 *self, int type);
struct cOmWeapon *func_0028D048(cEm00 *self, int type);
/* Throw weapon at the player from the enemy's child idx; type is not read. */
void func_0026B240(cEm00 *self, struct cOmWeapon *weapon, int type, int idx);
/* Put weapon at the enemy's hand and let it go straight ahead. */
void func_0026BDD0(cGameObj *self, struct cOmWeapon *weapon);

/* Raise the step timer to at least time. */
void func_0027DD10(cEm00 *self, float time);

/* Set up the enemy's model for its enemy number (with its texture swaps); 0 when it has none. */
int func_0028C400(cEm00 *self);
/* Allocate and start the cloth of the enemy numbers that wear one. */
void func_0028CDD0(cEm00 *self);
/* Pin the data of the objects the enemy number creates later (weapons, children). */
void func_0028CED8(cEm00 *self);

#endif /* GODHAND_CEM00FN_H */
