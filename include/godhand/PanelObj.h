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
    char unk00[0x60];
    CustomIDWork elem[PANEL_ELEM_NUM];  /* 0x60 */
} PanelObj;                             /* 0x89C */

/* Show (show != 0) or hide one element, or with PANEL_ELEM_ALL every element but 0. */
void func_001DEE60(PanelObj *self, int element, int show);
void PanelObj_setCursorMode(PanelObj *self, unsigned char mode);
void PanelObj_setArrowMode(PanelObj *self, unsigned char mode);
void UiRecord_setDispSubs6to10(PanelObj *self, int on);
/* Set the number shown by element 15. */
void func_001DEE40(PanelObj *self, int number);
void func_001DF528(PanelObj *self, unsigned char idx, unsigned short mode);
/* Start (enabled != 0) or stop element 8's sideways sway. */
void func_001DF820(PanelObj *self, int enabled);

#endif
