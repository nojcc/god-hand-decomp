/* include/godhand/ColiseumEmSelect.h - ColiseumEmSelect, the coliseum enemy pick screen.
 *
 * The screen is a large object (more than 0x37E0 bytes). The fields below
 * are the ones the recovered methods touch; the rest stays unkNNN.
 * func_001F46E0 releases the sub-object at 0x60 (a cIDBase). cardNode at
 * 0x37D8 is a heap node owned by the screen; the node's word at -0x20 is its
 * heap. Offsets are exact.
 */
#ifndef GODHAND_COLISEUMEMSELECT_H
#define GODHAND_COLISEUMEMSELECT_H

/* The global record at **D_003C2384; only the two words cleared at close are named. */
typedef struct ColiseumHost {
    char unk00[0xA8];
    int pickA;                  /* 0xA8 */
    int pickB;                  /* 0xAC */
} ColiseumHost;

/* One entry of the coliseum enemy table D_003BE8B0 (0x28 bytes, 2-aligned). */
typedef struct ColiseumEmEntry {
    short unk00;                /* 0x00 */
    unsigned short room;        /* 0x02 room the fight runs in */
    char unk04[0x28 - 0x04];
} ColiseumEmEntry;

typedef struct ColiseumEmSelect {
    char unk000[0x04];
    int vtIndex;                /* 0x04 index into the D_003BF0A8 dispatch table */
    int step;                   /* 0x08 */
    char unk00C[0x60 - 0x0C];
    char idBase[0x10];          /* 0x60 sub-object released at close */
    char unk70[0x37A8 - 0x70];
    ColiseumEmEntry entry;      /* 0x37A8 the picked enemy's table entry */
    short emA;                  /* 0x37D0 */
    short emDiff;               /* 0x37D2 emA - emB */
    short emB;                  /* 0x37D4 */
    char unk37D6[2];
    int *cardNode;              /* 0x37D8 heap node, 0 when none */
} ColiseumEmSelect;

/* The pick handed to the fight, D_00568240. */
typedef struct ColiseumPick {
    char unk00[0x10];
    short emA;                  /* 0x10 */
    short emB;                  /* 0x12 */
    char unk14[4];
    ColiseumEmEntry entry;      /* 0x18 */
} ColiseumPick;

extern ColiseumPick D_00568240;

void ColiseumEmSelect_close(ColiseumEmSelect *self);

#endif
