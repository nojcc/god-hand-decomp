/* include/godhand/ColiseumEmSelectFn.h - the ColiseumEmSelect and ColiseumEmDisp methods.
 *
 * ColiseumEmSelect.h holds the records. 001f38a0.c declares func_001F46E0
 * itself on a void pointer, so the prototypes live here for the units that
 * take them from a header. The display sits in ColiseumEmSelect at idBase.
 */
#ifndef GODHAND_COLISEUMEMSELECTFN_H
#define GODHAND_COLISEUMEMSELECTFN_H

#include "godhand/ColiseumEmSelect.h"

/* Stop the screen fade if one is running. */
void func_001F44E0(ColiseumEmSelect *self);
/* Whether enemy em can be picked for stage; self is not read. */
int func_001F4530(ColiseumEmSelect *self, int em, int stage);

/* ColiseumEmDisp methods. */
/* Clear word 0, construct the ID base and the 0x6F elements; returns self. */
ColiseumEmDisp *func_001F45D8(ColiseumEmDisp *self);
/* Set up the ID base (set 0x15) and the elements, then hide them all. */
void InitUiIdWorksAndShowAll(ColiseumEmDisp *self);
/* Release, move (after running the elements) or draw the ID base. */
void func_001F46E0(ColiseumEmDisp *self);
void func_001F4700(ColiseumEmDisp *self);
void func_001F4758(ColiseumEmDisp *self);
/* Show (on set) or hide element id; id COLISEUMEM_ELEM_NUM means every element. */
void SetCustomIDDispOneOrAll_1F4778(ColiseumEmDisp *self, int id, int on);
/* Hide everything, show elements 0..9, elements 0x61..0x67 and the gauge block 0x50..0x60. */
void DispMenu_open(ColiseumEmDisp *self);
/* Hide elements 0x50..0x60, then show them again when on is set. */
void func_001F4928(ColiseumEmDisp *self, int on);
/* Set element 2's number (the gold). */
void func_001F4B78(ColiseumEmDisp *self, int number);
/* Hide both marks of slot no and, if lit, show the left (right 0) or the right one. */
void Panel_showSlotMark(ColiseumEmDisp *self, unsigned short no, int right, int lit);
/* Set the number of element 0x18 + slot (slot 0..6) and show or hide it. */
void SetCustomIDSlotNumber_1F4C40(ColiseumEmDisp *self, unsigned short slot, int number, int on);
/* Set column idx (0..6, element 0x26 + idx) to a number, nudged left by its digit count, and show or hide it. */
void CustomIDOwner_setColumnNumber(ColiseumEmDisp *self, unsigned short idx, int number, int on);
/* Fill row idx (0..6) of the time table, or show its "no time" message when val is 0. */
void CustomIDOwner_setTimeRow(ColiseumEmDisp *self, unsigned short idx, int val, int show);
/* Set the number of element 0x42 + slot (slot 0..6) and show or hide it. */
void SetCustomIDSlotNumberAlt_1F5210(ColiseumEmDisp *self, unsigned short slot, int number, int on);
/* Show or hide element 0x49 + value (value 0..6). */
void func_001F5278(ColiseumEmDisp *self, unsigned short value, int on);
/* Place elements 8 and 9 at the Y of position idx (0..6) and show or hide them. */
void CustomIDWork_placeByIndex(ColiseumEmDisp *self, unsigned short idx, int on);
/* Start (on set) or stop the pulse of the selection mark, elements 8 and 9. */
void MarkObj_setPulse(ColiseumEmDisp *self, int on);
/* Show or hide elements 0x61..0x67. */
void CustomIDOwner_setAllShown(ColiseumEmDisp *self, int on);
/* Set item box idx (0..6) by mode: its UV rectangle, f68 and x position; then show or hide it. */
void func_001F4CA8(ColiseumEmDisp *self, unsigned short idx, int mode, int on);
/* Scale bar element 102 to b / a (at most 1) of element 100's f6C and start the arrows 97 and 98 bobbing. */
void func_001F5510(ColiseumEmDisp *self, int a, int b);
/* Move bar element 102 down by element 100's f6C times a3 / a1. */
void func_001F55C0(ColiseumEmDisp *self, int a1, int a2, int a3);
/* Rebuild the status panel: hide it, then show only the frame or the four gauges and `lit` of `num` pips. */
void func_001F5650(ColiseumEmDisp *self, unsigned char mode, short gauge0, short gauge1, short gauge2, short gauge3,
                   short num, short lit);

#endif /* GODHAND_COLISEUMEMSELECTFN_H */
