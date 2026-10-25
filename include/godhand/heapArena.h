/* include/godhand/heapArena.h - the memory arenas the allocators carve from (set up at 0x30ECF8). */
#ifndef GODHAND_HEAPARENA_H
#define GODHAND_HEAPARENA_H

struct HeapArena;

/* The header at the start of an arena's block, as func_002A94F0 lays it out. */
typedef struct HeapBlock {
    struct HeapArena *arena;    /* 0x00 owner */
    int unk04;                  /* 0x04 */
    int unk08;                  /* 0x08 */
    int size;                   /* 0x0C free bytes after the header */
    int unk10;                  /* 0x10 0x20 after a reset */
} HeapBlock;

typedef struct HeapArena {
    HeapBlock *block;           /* 0x00 start of the managed block, 0 if none */
    int size;                   /* 0x04 size in bytes */
    int user;                   /* 0x08 */
    int unk0C;
} HeapArena;                    /* 0x10 */

extern HeapArena *D_003C3CF0;   /* the default arena */
extern HeapArena D_00754200;
extern HeapArena D_00754210;
extern HeapArena D_00754220;
extern HeapArena D_00754230;
extern HeapArena D_00754240;
extern HeapArena D_00754C10;
extern HeapArena D_00754C20;

/* Set up an arena over a block; an empty block or size leaves it cleared. */
void Arena_init(HeapArena *self, void *block, int size, int user);
void func_002A9528(HeapArena *a);      /* constructor: clears the first two words */
/* Empty the arena: one free block spanning it after a 0x20-byte header. */
void func_002A94F0(HeapArena *self);

#endif /* GODHAND_HEAPARENA_H */
