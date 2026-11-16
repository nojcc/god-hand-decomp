/* include/godhand/cCockPrintData.h - cCockPrintData, the cockfight gold counter.
 *
 * cCockPrintData is a cIDBase display object (vtable 0x0041E66C). The shown
 * amount counts toward the saved gold, and each gold pickup pops up a line
 * (drawn through `popupBase`) that rises and fades.
 */
#ifndef GODHAND_CCOCKPRINTDATA_H
#define GODHAND_CCOCKPRINTDATA_H

#include "godhand/cIDBase.h"

#define COCKPRINT_ENT_NUM     4
#define COCKPRINT_COUNTER     0         /* its seed is the number drawn */
#define COCKPRINT_POPUP       1
#define COCKPRINT_LABEL       2
#define COCKPRINT_LABEL2      3
#define COCKPRINT_POPUP_NUM   16
#define COCKPRINT_MODE_MASK   3
#define COCKPRINT_MODE_LABEL  1         /* show the label */

typedef struct cCockPrintData {
    cIDBaseObj base;                            /* 0x000 */
    char unk048[0x90 - sizeof(cIDBaseObj)];
    unsigned int gold;                          /* 0x090 amount shown */
    cIDBaseEnt *ent[COCKPRINT_ENT_NUM];         /* 0x094 entries looked up by id 0..3 */
    char unk0A4[0xB0 - 0xA4];
    cIDBaseObj popupBase;                       /* 0x0B0 draws one popup line */
    char unk0F8[0x100 - 0xB0 - sizeof(cIDBaseObj)];
    float posYOfs[COCKPRINT_POPUP_NUM];         /* 0x100 */
    unsigned int add[COCKPRINT_POPUP_NUM];      /* 0x140 amount each popup shows */
    short timer[COCKPRINT_POPUP_NUM];           /* 0x180 */
    unsigned char alpha[COCKPRINT_POPUP_NUM];   /* 0x1A0 */
    unsigned char on[COCKPRINT_POPUP_NUM];      /* 0x1B0 */
    unsigned char mode;                         /* 0x1C0 low two bits: COCKPRINT_MODE_* */
} cCockPrintData;

typedef char cCockPrintData_popupBase_check[((int)&((cCockPrintData *)0)->popupBase == 0xB0) ? 1 : -1];
typedef char cCockPrintData_mode_check[((int)&((cCockPrintData *)0)->mode == 0x1C0) ? 1 : -1];

#endif
