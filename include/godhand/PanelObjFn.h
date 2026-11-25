/* include/godhand/PanelObjFn.h - PanelObj methods.
 *
 * Work's prototypes that PanelObj.h on main does not carry: some clash with
 * main units' own declarations. Included by the work units that need them.
 */
#ifndef GODHAND_PANELOBJFN_H
#define GODHAND_PANELOBJFN_H

#include "godhand/PanelObj.h"

/* Show (show != 0) or hide one element, or with PANEL_ELEM_ALL every element but 0. */
void func_001DEE60(PanelObj *self, int element, int show);
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

#endif /* GODHAND_PANELOBJFN_H */
