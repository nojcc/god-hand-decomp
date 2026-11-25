/* include/godhand/cOmWeaponFn.h - cOmWeapon calls that more than one unit makes.
 *
 * cOmWeapon.h holds the record. Older units declare several of these
 * themselves with their own parameter types, so the prototypes live here for
 * the units that take them from a header.
 */
#ifndef GODHAND_COMWEAPONFN_H
#define GODHAND_COMWEAPONFN_H

#include "godhand/cOmWeapon.h"

/* The nearest weapon within radius of pos that can be picked up. With any == 0
 * it also skips the weapons func_001D0AE0 rejects. */
cOmWeapon *func_002DDAB0(cVec *pos, int any, float radius);

void Obj1D00_SetState6_Variant6_a1(cOmBase *self, int arg);
void Obj1D00_SetState_6_2_a1(cOmBase *self, int arg);
void Obj1D00_SetState_6_4_a1(cOmBase *self, int arg);
void Obj1D00_SetState_6_8_a1(cOmBase *self, int arg);
void Obj1D00_SetState_6_C_a1(cOmBase *self, int arg);
void Obj1D00_SetState_6_E_a1(cOmBase *self, int arg);
void Obj1D00_SetState_7_A_a1(cOmBase *self, int arg);
void Obj1D00_SetState_7_C_a1(cOmBase *self, int arg);
void Obj1D00_SetState_7_E_a1(cOmBase *self, int arg);
void Obj1D00_SetState_7_1A_a1(cOmBase *self, int arg);
void Obj1D00_SetState_6_A(cOmBase *self);
void Obj1D00_SetState_7_2(cOmBase *self);
void Obj1D00_SetState_7_4(cOmBase *self);
void Obj1D00_SetState_7_6(cOmBase *self);
void Obj1D00_SetState_7_8(cOmBase *self);
void Obj1D00_SetState_7_10(cOmBase *self);
void Obj1D00_SetState_7_12(cOmBase *self);
void Obj1D00_SetState_7_14(cOmBase *self);
void Obj1D00_SetState_7_16(cOmBase *self);
void Obj1D00_SetState_7_18(cOmBase *self);
void Obj1D00_SetState_7_1C(cOmBase *self);
int Obj1D00_GetField_665(cOmWeapon *self);
int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(cOmBase *self);
/* Break the weapon into its debris pieces. */
void cOmWeapon_SetBreak(cOmWeapon *self);
/* Drop the weapon. */
void cOmWeapon_setFall(cOmWeapon *self);

/* Hand weapon to parent with the hold offsets of type (two loaders with the same table). */
void SetOrientByType_26AF20(cOmBase *parent, cOmWeapon *weapon, unsigned int type);
void cOmWeapon_loadEffectParamsByType(cOmBase *parent, cOmWeapon *weapon, unsigned int type);
/* Hand weapon to self's right or left hand with self's kind's grip. */
void cOmBase_attachWeaponGrip(cOmBase *self, cOmWeapon *weapon, int left);

#endif /* GODHAND_COMWEAPONFN_H */
