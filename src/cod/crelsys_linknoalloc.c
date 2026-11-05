/* sn-2.95.3-136 */
#include "godhand/cRelSys.h"

/* Link data, already in memory, into slots[idx] and return ok; unused is not read. */
__attribute__((section(".text.cRelSys_linkNoAlloc")))
unsigned char cRelSys_linkNoAlloc(cRelSlot *slots, void *data, void *unused, int idx) {
    return SetValueAndValidate_2BE630(&slots[idx], data);
}
