/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/criStm.h"
#include "godhand/heapArenaFn.h"
#include "godhand/cMovie.h"

/* Free a block taken by func_002B5AF8 and clear its slot (a1 is not read). */
__attribute__((section(".text.FreeEntrySlot_2B5BB8")))
void FreeEntrySlot_2B5BB8(cMovie *self, int unused, void *block)
{
    cMovieAlloc *slot = func_002B4FE8(self, block);
    void *p = slot->block;
    HeapArena *heap = slot->heap;

    if (p != 0) {
        cHeap_free(heap, p);
    }
    slot->block = 0;
    slot->heap = 0;
}

__attribute__((section(".text.ClearStructFields_2C8EB0")))
void ClearStructFields_2C8EB0(int *a0) {
    a0[0] = 0;
    func_003A52F0((char *)a0 + 0x4, 0, 0xC);
    func_003A52F0((char *)a0 + 0x14, 0, 0x80);
}

/* Clears the active flag of a used BGM node and refreshes its state. */
__attribute__((section(".text.cSndBgmNode_Resume")))
void cSndBgmNode_Resume(cSndBgmNode *node) {
    if (cSndBgmNode_IsActive(node)) {
        node->flags = node->flags & 0xFFFFFFFE;
        UpdateStateAndClearFlag_3734F0(node);
    }
}

__attribute__((section(".text.ClearFlagBits_373858")))
void ClearFlagBits_373858(void *a0, unsigned int a1) {
    if (func_00373A50(a0)) {
        *(int *)((char *)a0 + 0x4C) = *(int *)((char *)a0 + 0x4C) & ~a1;
    }
}
