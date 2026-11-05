/* sn-2.95.3-136 */
#include "godhand/cRelSys.h"

/* Unregister and clear one loaded table holder. */
__attribute__((section(".text.func_002BE670")))
void func_002BE670(cRelSlot *entry)
{
    func_002BE6C8(entry);
    entry->ok = 0;
    entry->data = 0;
}
