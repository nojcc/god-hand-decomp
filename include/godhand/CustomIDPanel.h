/* include/godhand/CustomIDPanel.h - CustomID panel helpers (0x1DE4F8.., 0x1ECE30..)
 * and the coliseum battle's panel (0x1F2708..).
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

#define CIDPANEL_WORK_NUM   0x12        /* works of the main display; also "every work" for SetCustomIDDispOneOrAll_1F29C0 */
#define CIDPANEL_SUB_NUM    3           /* works of the second display */

/* CustomIDPanel.flags: each bit runs one of the three animations, on anim[n]. */
#define CIDPANEL_ANIM0      0x01        /* func_001F2D60: fade in works 0 and 1 */
#define CIDPANEL_ANIM1      0x02        /* func_001F3118: work 2 */
#define CIDPANEL_ANIM2      0x04        /* func_001F32A0: blink work 4 */

typedef struct CustomIDPanelAnim {
    int state;
    int timer;
} CustomIDPanelAnim;

/* The coliseum battle's panel: two cIDBase displays, each driving its own CustomIDWorks. */
typedef struct CustomIDPanel {
    int flags;                                  /* 0x000 CIDPANEL_ANIM* */
    char unk004[0xC];
    cIDBaseObj id;                              /* 0x010 */
    char unk058[0x60 - 0x58];
    CustomIDWork work[CIDPANEL_WORK_NUM];       /* 0x060 */
    CustomIDPanelAnim anim[3];                  /* 0x918 */
    cIDBaseObj id2;                             /* 0x930 */
    char unk978[0x980 - 0x978];
    CustomIDWork sub[CIDPANEL_SUB_NUM];         /* 0x980 sub[2] is the title */
} CustomIDPanel;                                /* 0xAF4 */

typedef char CustomIDPanel_anim_check[((int)&((CustomIDPanel *)0)->anim == 0x918) ? 1 : -1];
typedef char CustomIDPanel_id2_check[((int)&((CustomIDPanel *)0)->id2 == 0x930) ? 1 : -1];
typedef char CustomIDPanel_size_check[(sizeof(CustomIDPanel) == 0xAF4) ? 1 : -1];

CustomIDPanel *func_001F2708(CustomIDPanel *self);
void IdUi_initWorks(CustomIDPanel *self);
void func_001F28C0(CustomIDPanel *self);
void func_001F28F0(CustomIDPanel *self);
void func_001F2990(CustomIDPanel *self);
void SetCustomIDDispOneOrAll_1F29C0(CustomIDPanel *self, int id, int disp);
void func_001F2D60(CustomIDPanel *self);
void func_001F3118(CustomIDPanel *self);
void func_001F32A0(CustomIDPanel *self);
void func_001F3260(CustomIDPanel *self);
void CustomIDOwner_setPanelState(CustomIDPanel *self, unsigned short mode);
void CustomIDOwner_setShown(CustomIDPanel *self, int on);
void CustomIDOwner_hideAll(CustomIDPanel *self);
void CustomID_setNumberAndShow(CustomIDPanel *self, int number, int on);
void CustomID_showDisplays(CustomIDPanel *self, int full);
void DigitDisplay_setNumber(CustomIDPanel *self, int on, int value);
void IdNumbers_setAndTint(CustomIDPanel *self, int show, int n0, int n1, int n2, int flag);

#endif
