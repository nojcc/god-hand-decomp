#ifndef GODHAND_COMENTRY_H
#define GODHAND_COMENTRY_H

#include "godhand/cOmBase.h"

/* An object with an entry in the D_00569B70 table, registered again whenever it changes. */
typedef struct cOmEntry {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x662 - 0x5E0];
    unsigned short entryId;             /* 0x662 id the entry is registered under */
    char unk664[0x675 - 0x664];
    unsigned char unk675;               /* 0x675 UpdatePhaseConditionalSync skips func_002A87E8 while set */
    unsigned char state;                /* 0x676 state bits; with bit 1 the rotation is watched too */
    unsigned char statePrev;            /* 0x677 state at the last registration */
    char unk678[0x67C - 0x678];
    int dropItemPrev;                   /* 0x67C dropItem at the last registration */
} cOmEntry;

void func_001C0450(cOmEntry *self);

#endif /* GODHAND_COMENTRY_H */
