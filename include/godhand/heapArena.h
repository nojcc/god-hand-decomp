/* include/godhand/heapArena.h - the memory arenas the allocators carve from (set up at 0x30ECF8). */
#ifndef GODHAND_HEAPARENA_H
#define GODHAND_HEAPARENA_H

/* One block header, 0x20 bytes before the user address: a used part (header
 * plus user bytes), then free space up to the next block. */
typedef struct HeapBlk {
    struct HeapArena *heap;             /* 0x00 the arena the block came from */
    struct HeapBlk *prev;               /* 0x04 */
    struct HeapBlk *next;               /* 0x08 */
    unsigned int freeSize;              /* 0x0C free bytes after the used part */
    unsigned int usedSize;              /* 0x10 header plus user bytes */
    char unk14[0xC];
} HeapBlk;                              /* 0x20 */
typedef char HeapBlk_size_check[sizeof(HeapBlk) == 0x20 ? 1 : -1];

/* The arena the block at user address p came from. */
#define HEAP_OWNER(p) (((HeapBlk *)(p) - 1)->heap)

typedef struct HeapArena {
    HeapBlk *head;                      /* 0x00 the first block: the start of the arena's memory */
    int size;                           /* 0x04 size in bytes */
    int user;                           /* 0x08 */
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

void func_002A9528(HeapArena *self);    /* constructor: clears the first two words */

/* Set up an arena over a block; an empty block or size leaves it cleared. */
void Arena_init(HeapArena *self, void *block, int size, int user);
/* Make the arena's memory one free block. */
void func_002A94F0(HeapArena *self);

/* First fit: the user address of a new block of size bytes aligned to align, or 0. */
/* Give the block at p back to the block before it (heap is not read). */
/* Link blk after `after` and mark it as heap's. */
/* cHeap_allocFirstFit, setting up the arenas on first use. */
/* operator new[] and delete: 16-byte aligned from the default arena. */

void *cHeap_allocFirstFit(HeapArena *heap, unsigned int size, unsigned int align);
void cHeap_free(HeapArena *heap, void *p);
void func_002A9620(HeapArena *heap, HeapBlk *blk, HeapBlk *after);
void *_MemoryAlloc(unsigned int size, unsigned int align, HeapArena *heap);
void *__builtin_vec_new(unsigned int size);
void __builtin_delete(void *p);
void __builtin_vec_delete(void *p);
/* operator new: 16-byte aligned from the default arena. */
/* The same allocation as __builtin_vec_new. */
/* size bytes aligned to align from the default arena. */
/* _MemoryAlloc under another name. */
/* size bytes, 16-byte aligned, from the default arena (unused is not read). */

void *func_0030F550(unsigned int size);
void *func_0031C890(unsigned int size);
void *func_0031C8B8(unsigned int size, unsigned int align);
void *func_0031C8E0(unsigned int size, unsigned int align, HeapArena *heap);
void *func_002BADF8(void *unused, unsigned int size);

#endif /* GODHAND_HEAPARENA_H */
