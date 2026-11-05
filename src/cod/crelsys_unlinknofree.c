/* sn-2.95.3-136 */
#include "godhand/cRelSys.h"

/* Unlink slots[idx] without freeing its data, if it is linked. */
__attribute__((section(".text.cRelSys_unlinkNoFree")))
void cRelSys_unlinkNoFree(cRelSlot *slots, int idx) {
    /* an int sum: &slots[idx] adds the two operands the other way round */
    cRelSlot *p = (cRelSlot *)(idx * 8 + (int)slots);
    if (p->ok == 1)
        func_002BE670(p);
}
