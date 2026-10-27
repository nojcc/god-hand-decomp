/* sn-2.95.3-136 */
/* NON_MATCHING cSndMemHeap_Alloc: retail keeps the rounded size in s1 and the
 * heap in s2 (swapped here), which also reorders the new block's stores. */
#include "include_asm.h"
#include "godhand/cSnd.h"

#ifdef NON_MATCHING
/* Take size bytes, rounded up to 16, from the free space behind the first
 * block with room, in a new block linked in front of it. Returns the chunk
 * address, or 0 when no block has room or none is unused. */
__attribute__((section(".text.cSndMemHeap_Alloc")))
int cSndMemHeap_Alloc(cSndMemHeap *heap, int size)
{
    unsigned int need = (size + 15) & 0xFFFFFFF0;
    cSndMemBlk *fit;
    cSndMemBlk *blk;

    fit = cSndMemHeap_FindFitBlk(heap, need);
    if (fit != 0) {
        blk = cSndMemHeap_FindUnusedBlk(heap);
        if (blk != 0) {
            blk->prev = fit->prev;
            blk->next = fit;
            blk->size = need;
            blk->owner = heap;
            blk->freeSize = fit->freeSize - need;
            blk->top = fit->top + need;
            blk->base = fit->top;
            if (fit->prev != 0)
                fit->prev->next = blk;
            fit->prev = blk;
            fit->freeSize = 0;
            return blk->base;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", cSndMemHeap_Alloc);
#endif
