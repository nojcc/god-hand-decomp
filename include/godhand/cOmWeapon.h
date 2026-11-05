/* include/godhand/cOmWeapon.h - a weapon lying on the map or carried by a fighter.
 *
 * cOmWeapon extends cOmBase: the first 0x5E0 bytes are the cOmBase record, and
 * the weapon adds its own state from 0x600. A weapon can be held (parent set),
 * thrown, falling or broken. Its child list entry 0 is the collision body, a
 * second cOmBase that the weapon repositions every time it changes hands.
 *
 * Field offsets are exact: every body that uses this header builds
 * byte-identical to retail. A field nobody has named yet is unkNNN padding.
 */
#ifndef GODHAND_COMWEAPON_H
#define GODHAND_COMWEAPON_H

#include "godhand/cOmBase.h"

#define COMWEAPON_PIECE_NUM 7

/* One piece of debris. rot is the spin per frame, vel the launch velocity. */
typedef struct cOmWeaponPiece {
    float rot[3];                       /* 0x00 */
    float unk0C;
    float vel[3];                       /* 0x10 */
    float unk1C;
} cOmWeaponPiece;

typedef struct cOmWeapon {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cOmBase *parent;                        /* 0x600 the fighter holding it, 0 when free */
    int parentIdx;                          /* 0x604 index of the held slot on the parent */
    char unk608[0x8];
    cVec heldPos;                           /* 0x610 */
    cVec heldRot;                           /* 0x620 */
    float fallSpeed;                        /* 0x630 */
    char unk634[0xC];
    cVec vel;                               /* 0x640 launch velocity */
    char unk650[0x10];
    float life;                             /* 0x660 frames left before a dropped weapon breaks */
    unsigned char unk664;                   /* 0x664 */
    unsigned char unk665;                   /* 0x665 */
    char unk666[0x2];
    int timer;                              /* 0x668 frame countdown, see cOmWeapon_SetDamage */
    float unk66C;                           /* 0x66C */
    int throwArg;                           /* 0x670 second argument of setThrow */
    float fallVel;                          /* 0x674 vertical speed while dropping */
    char unk678[0x18];
    int target;                             /* 0x690 object the weapon was thrown at */
    float spin;                             /* 0x694 */
    char unk698[0x8];
    int unk6A0;                             /* 0x6A0 */
    float unk6A4;                           /* 0x6A4 */
    float unk6A8;                           /* 0x6A8 */
    char unk6AC[0x4];
    cOmWeaponPiece piece[COMWEAPON_PIECE_NUM];/* 0x6B0 debris pieces spawned when it breaks */
} cOmWeapon;

typedef char cOmWeapon_size_check[(sizeof(cOmWeapon) == 0x790) ? 1 : -1];

/* Attaches the weapon to body part idx of par with the hold offsets heldPos and heldRot, and starts the held state. */
void cOmWeapon_setParent(cOmWeapon *self, cOmBase *par, int idx, cVec *heldPos, cVec *heldRot);
/* Set the four state bytes to mode 0, phase 6 (or 8), step 0, stepArg 0. */
void Obj1D00_ClearState_6(cOmBase *self);
void Obj1D00_ClearState_7(cOmBase *self);
void Obj1D00_ClearState_8(cOmBase *self);
void Obj1D00_ClearState_9(cOmBase *self);
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
/* Throw the weapon with velocity pos and throw argument arg and enter state 0x11
 * (definition in 001ad818.c). */
void func_001D0140(cOmWeapon *self, cVec *pos, int arg);
/* Break the weapon into its debris pieces. */
void cOmWeapon_SetBreak(cOmWeapon *self);
/* Drop the weapon. */
void cOmWeapon_setFall(cOmWeapon *self);
/* Hand weapon to parent with the hold offsets of type (two loaders with the same table). */
void SetOrientByType_26AF20(cOmBase *parent, cOmWeapon *weapon, unsigned int type);
void cOmWeapon_loadEffectParamsByType(cOmBase *parent, cOmWeapon *weapon, unsigned int type);
/* Hand weapon to self's right or left hand with self's kind's grip. */
void cOmBase_attachWeaponGrip(cOmBase *self, cOmWeapon *weapon, int left);

#endif
