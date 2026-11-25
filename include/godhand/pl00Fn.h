/* include/godhand/pl00Fn.h - pl00 methods that more than one unit calls.
 *
 * pl00.h holds the record. Several older units still declare these
 * themselves with their own parameter types (and 000000.c defines some of
 * them on a char pointer), so the prototypes live here, apart from the
 * record, for the units that take them from a header.
 */
#ifndef GODHAND_PL00FN_H
#define GODHAND_PL00FN_H

#include "godhand/pl00.h"

/* 1 when the given bit of the flag word at 0x15F4 is set, else 0. */
int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(pl00 *self);
/* Nonzero if the player may start an attack: no action at 0x6A0, alive, not caught, and bit 8 of the flag word at 0x15F4 set. */
int pl00_ckAtkActBtnEnable(pl00 *self);
int Obj0000_IsSet_Field_15F4_Bit_1000_12C530(pl00 *self);
int Obj0000_IsSet_Field_15F4_Bit_100000_12CA48(pl00 *self);
int Obj0000_IsSet_Field_15F4_Bit_1000000_12CED8(pl00 *self);

/* Spend heat gauge through cHeatSys and switch to heat mode when the flags allow; nonzero when it switched. */
int func_00123938(pl00 *self, int mode);
/* Pick the enemy the player catches (held); returns 1 and sets unk648 when one is found. */
int func_00124540(pl00 *self, int kind);
/* 1 when one of the five slots at 0x5B0 is in a busy motion, else 0. */
int func_0010B2E8(pl00 *self, int flag);
/* Clear the catch target (held) and its flag (unk648). */
void Obj0000_Clear_Fields_640_648_124E58(pl00 *self);
/* Turn toward the catch target (held) at the given rate, when there is one. */
void InvokeVirtualAtField214AndForward_124E68(pl00 *self, float f12);

#endif /* GODHAND_PL00FN_H */
