/* include/godhand/IDPanelScreen.h - an 11-entry cIDBase display with a second display of
 * five CustomIDWorks; the game object holds one at offset 0. */
#ifndef GODHAND_IDPANELSCREEN_H
#define GODHAND_IDPANELSCREEN_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

typedef struct IDPanelScreen {
    cIDBaseObj base;            /* 0x000 */
    char unk48[0x90 - 0x48];
    unsigned char on;           /* 0x090 */
    char unk91;
    unsigned short step;        /* 0x092 func_0013D540's step: 0 grow, 1 func_0013D7B0, 2 wait for the child screens */
    cIDBaseEnt *ent[11];        /* 0x094 */
    char unkC0[0x10];
    cIDBaseObj base2;           /* 0x0D0 */
    char unk118[0x120 - 0x118];
    CustomIDWork cw[5];         /* 0x120 */
    signed char flashStep;      /* 0x38C step of the intro flash (func_0013DB50), 7 when done */
    char unk38D[3];
    int flashTimer;             /* 0x390 frames left in the flash step */
} IDPanelScreen;

typedef char IDPanelScreen_base2_check[((int)&((IDPanelScreen *)0)->base2 == 0xD0) ? 1 : -1];
typedef char IDPanelScreen_flash_check[((int)&((IDPanelScreen *)0)->flashTimer == 0x390) ? 1 : -1];
typedef char IDPanelScreen_cw_check[((int)&((IDPanelScreen *)0)->cw == 0x120) ? 1 : -1];

void SetupFields10And14_13D3C0(IDPanelScreen *self);
void func_0013D400(IDPanelScreen *obj);
/* Per-frame step of the panel: fill ent, run the step, hide three entries while the save flag is set, run the five CustomIDWorks and move both displays. */
void func_0013D540(IDPanelScreen *self);

#endif
