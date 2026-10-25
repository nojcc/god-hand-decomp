/* include/godhand/keySlot.h - KeySlot, a four-slot table of {key, value} pairs.
 *
 * A free slot has key 0. The lookups walk the four slots in order.
 */
#ifndef GODHAND_KEYSLOT_H
#define GODHAND_KEYSLOT_H

#define KEYSLOT_NUM 4

typedef struct KeySlot {
    int key;                            /* 0x0 key, 0 when the slot is free */
    int value;                          /* 0x4 */
} KeySlot;

/* The slot holding key, or 0. */
KeySlot *func_002BB068(KeySlot *tbl, int key);
/* The first free slot, or 0. */
KeySlot *func_002BB098(KeySlot *tbl);
/* The value stored under key, or 0. */
int func_002BB138(KeySlot *tbl, int key);

#endif
