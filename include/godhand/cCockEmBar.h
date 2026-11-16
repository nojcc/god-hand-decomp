/* include/godhand/cCockEmBar.h - cCockEmBar, the cockfight enemy bar.
 *
 * cCockEmBar is a cIDBase display object (vtable 0x0041DE94) with four more
 * cIDBase displays in 0x50-byte slots. Its methods set up, reset and step
 * all five together.
 */
#ifndef GODHAND_CCOCKEMBAR_H
#define GODHAND_CCOCKEMBAR_H

#include "godhand/cIDBase.h"

#define COCKEMBAR_SUB_NUM  4

/* One sub display, a cIDBase in a 0x50-byte slot. */
typedef struct cCockEmBarSub {
    cIDBaseObj id;                      /* 0x00 */
    char pad48[0x50 - sizeof(cIDBaseObj)];
} cCockEmBarSub;

typedef struct cCockEmBar {
    cIDBaseObj base;                    /* 0x000 */
    char unk048[0xA0 - sizeof(cIDBaseObj)];
    cCockEmBarSub sub[COCKEMBAR_SUB_NUM]; /* 0x0A0 */
} cCockEmBar;

typedef char cCockEmBarSub_size_check[sizeof(cCockEmBarSub) == 0x50 ? 1 : -1];
typedef char cCockEmBar_sub_check[((int)&((cCockEmBar *)0)->sub == 0xA0) ? 1 : -1];

#endif
