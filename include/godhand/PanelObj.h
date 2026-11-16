/* include/godhand/PanelObj.h - a menu panel: a cIDBase of on-screen ID
 * elements (at 0x10, see func_001DEE20) and the CustomIDWork that animates
 * each one.
 *
 * func_001DEE60 shows or hides one element, or every element but 0 when
 * asked for PANEL_ELEM_ALL. Offsets are exact; fields nobody has named stay
 * as unkNN padding.
 */
#ifndef GODHAND_PANELOBJ_H
#define GODHAND_PANELOBJ_H

#include "godhand/CustomIDWork.h"

#define PANEL_ELEM_NUM  0x11
#define PANEL_ELEM_ALL  0x11    /* func_001DEE60: every element but 0 */

typedef struct PanelObj {
    int unk00;                          /* 0x00 cleared by func_001DEC70 */
    char unk04[0x10 - 4];
    cIDBaseObj id;                      /* 0x10 the elements' display */
    char unk58[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[PANEL_ELEM_NUM];  /* 0x60 */
} PanelObj;                             /* 0x89C */

typedef char PanelObj_size_check[(sizeof(PanelObj) == 0x89C) ? 1 : -1];

/* Show (show != 0) or hide one element, or with PANEL_ELEM_ALL every element but 0. */
void func_001DEE60(PanelObj *self, int element, int show);
void PanelObj_setCursorMode(PanelObj *self, unsigned char mode);
void PanelObj_setArrowMode(PanelObj *self, unsigned char mode);
void UiRecord_setDispSubs6to10(PanelObj *self, int on);
/* Set the number shown by element 15. */
void func_001DEE40(PanelObj *self, int number);
/* Clear word 0, construct the ID base and the 17 elements; returns self. */
PanelObj *func_001DEC70(PanelObj *self);
/* Release the ID base. */
void func_001DEDA8(PanelObj *self);
/* Run the 17 elements, then move the ID base. */
void func_001DEDC8(PanelObj *self);
/* Draw the ID base. */
void func_001DEE20(PanelObj *self);
/* Slide element 1 vertically for state sel and show or hide element 1. */
void CustomIDOwner_setSlideStateB(PanelObj *self, unsigned char sel);
/* Move element 8 left or right (a1 set) by an offset that depends on the language. */
void func_001DF7D0(PanelObj *self, int a1);
void func_001DF528(PanelObj *self, unsigned char idx, unsigned short mode);
/* Start (enabled != 0) or stop element 8's sideways sway. */
void func_001DF820(PanelObj *self, int enabled);
/* Slide the panel in or out by mode (0..3) and show or hide its two side elements: PokerUi_slidePanel moves element 2, Panel_slideSidePanelArrows element 4. */
void PokerUi_slidePanel(PanelObj *ui, int mode);
void Panel_slideSidePanelArrows(PanelObj *ui, int mode);
/* The same for element 14, showing elements 14 and 15 in every mode but 0. */
void UiPanel_setSlideMode(PanelObj *self, unsigned char mode);
/* Set up the display (ID set 0x12) and the 17 elements, set three message numbers and hide every element but 0. */
void func_001DECE0(PanelObj *p);

#endif
