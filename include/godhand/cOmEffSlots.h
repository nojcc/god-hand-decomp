/* include/godhand/cOmEffSlots.h - the cOm objects with ten effect slots.
 *
 * Two classes share this layout: the one built by InitObjSlotArray_196058
 * (set up by func_00196188) and the one built by InitObjSlotArrayB_197680
 * (set up by func_001977B0). Both are allocated 0x9E0 bytes. The
 * constructors clear ten 0x60-byte effect slots from 0x610 and the word at
 * 0x9D0. Each class has a table of part groups: four (first part, part count)
 * byte pairs.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet keeps its offset as its name.
 */
#ifndef GODHAND_COMEFFSLOTS_H
#define GODHAND_COMEFFSLOTS_H

#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cDamageGive.h"

/* One group of consecutive parts of the model. */
typedef struct cOmPartGroup {
    unsigned char first;                /* 0x00 first part */
    unsigned char num;                  /* 0x01 part count */
} cOmPartGroup;

typedef struct cOmEffSlots {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageTake *take;                  /* 0x600 from cDamageManage_CreateDamageTake */
    cDamageGive *give;                  /* 0x604 from cDamageManage_CreateDamageGive */
    char unk608[0x8];
    char unk610[0x9D0 - 0x610];         /* 0x610 ten 0x60-byte effect slots */
    int unk9D0;                         /* 0x9D0 cleared by the constructors */
    char unk9D4[0x4];
    short unk9D8;                       /* 0x9D8 the setups store 1 */
    char unk9DA[0x6];
} cOmEffSlots;

typedef char cOmEffSlots_chk_size[sizeof(cOmEffSlots) == 0x9E0 ? 1 : -1];

#endif /* GODHAND_COMEFFSLOTS_H */
