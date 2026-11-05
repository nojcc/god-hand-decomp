/* include/godhand/CustomIDPanel.h - CustomID panel helpers (0x1DE4F8.., 0x1ECE30..).
 *
 * The panels keep 0x7C-byte CustomIDWork records from +0x60. Their slot and
 * digit tables live in rodata and are copied whole into locals (ldl/ldr,
 * sdl/sdr), so they are declared as structs. Colours are built in an
 * uninitialised bitfield struct and passed as *(unsigned int *)&col.
 * Kept apart from CustomIDWork.h because older callers declare these
 * methods with other parameter types.
 */
#ifndef GODHAND_CUSTOMIDPANEL_H
#define GODHAND_CUSTOMIDPANEL_H

#include "godhand/CustomIDWork.h"

typedef struct { int w[5]; } CustomIDSlotTbl;
typedef struct { int w[8]; } CustomIDSlotTbl8;
typedef struct { int w[5][2]; } CustomIDDigitTbl;
typedef struct { unsigned int r:8, g:8, b:8, a:8; } CustomIDColor;

extern void SetCustomIDDispOneOrAll_1DD258(char *self, int id, int disp);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int id, int disp);

#endif
