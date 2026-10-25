/* include/godhand/cRecordIndex.h - a pool of 0x24-byte records addressed
 * through a byte index.
 *
 * The object at D_005FEC58 holds a pointer to a table of records, a record
 * count and a byte array at +0x14 that maps an index to a record number.
 * func_002C9008 reads it and the skill-slot helpers around 0x002C9AD0 read
 * the same byte array to get a skill id. Field names are ours, taken from
 * the methods that touch them; unkNNN stays where nobody has named a field.
 */
#ifndef GODHAND_CRECORDINDEX_H
#define GODHAND_CRECORDINDEX_H

#include "godhand/cCoreSave.h"

#define RECORDINDEX_RECORD_SIZE 0x24
#define RECORDINDEX_INDEX_NUM   0x80

/* One skill record of the table. */
typedef struct cRecordIndexEntry {
    unsigned int price;             /* 0x00 shop price; the technique shop shows half */
    char unk04[8];
    int flags;                      /* 0x0C bit 0: owned from the start */
    unsigned short name;            /* 0x10 name message, added to 0x304E */
    unsigned short stage;           /* 0x12 stage whose clear unlocks it, 0 = none */
    short sortKey;                  /* 0x14 key func_002C9950 sorts the index by */
    char unk16[2];
    short id;                       /* 0x18 skill or technique number */
    short needSkill;                /* 0x1A skill that must be owned first, -1 = none */
    char unk1C[8];
} cRecordIndexEntry;                /* 0x24 */

typedef struct cRecordIndex {
    cRecordIndexEntry *table;       /* 0x00 first record, null while unloaded */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    unsigned int count;             /* 0x0C number of valid indexes */
    unsigned int limit;             /* 0x10 number of records the shops list; func_002C9008 compares it signed */
    signed char index[RECORDINDEX_INDEX_NUM]; /* 0x14 index -> record number (or skill id) */
    cCoreSaveCombo combo[CORESAVE_COMBO_SETS]; /* 0x94 copy of the saved combos */
} cRecordIndex;

extern cRecordIndex D_005FEC58;

cRecordIndexEntry *func_002C9008(cRecordIndex *self, int i);
void func_002C90A0(cRecordIndex *self, unsigned char mode);
void func_002C9950(cRecordIndex *self);
int func_002C9A90(cRecordIndex *self, int index);

#endif
