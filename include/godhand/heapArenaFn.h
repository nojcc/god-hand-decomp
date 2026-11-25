/* include/godhand/heapArenaFn.h - the heap calls whose prototypes stay out of heapArena.h.
 *
 * Some units (00149378.c among them) declare cHeap_free and _MemoryAlloc
 * themselves with their own parameter types, and others call _MemoryAlloc
 * undeclared, so these two live here for the units that take them from a
 * header.
 */
#ifndef GODHAND_HEAPARENAFN_H
#define GODHAND_HEAPARENAFN_H

#include "godhand/heapArena.h"

/* Give the block at p back to the block before it (heap is not read). */
void cHeap_free(HeapArena *heap, void *p);
/* size bytes aligned to align from heap. */
void *_MemoryAlloc(unsigned int size, unsigned int align, HeapArena *heap);

#endif /* GODHAND_HEAPARENAFN_H */
