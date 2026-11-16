/* include/godhand/cCockLoading.h - cCockLoading, the casino's loading display.
 *
 * A cIDBase display (id 2) that DispMgr sets up at 0x3A0. Field names are
 * ours; offsets are exact.
 */
#ifndef GODHAND_CCOCKLOADING_H
#define GODHAND_CCOCKLOADING_H

#include "godhand/cIDBase.h"

typedef struct cCockLoading {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0xBE - sizeof(cIDBaseObj)];
    short unkBE;                        /* 0xBE -1 after setup */
} cCockLoading;                         /* 0xC0 */

typedef char cCockLoading_size_check[sizeof(cCockLoading) == 0xC0 ? 1 : -1];

/* Set up the display (id 2) and clear unkBE to -1; returns cIDBase_initialize's result. */
int func_0013ECF0(cCockLoading *self);

#endif
