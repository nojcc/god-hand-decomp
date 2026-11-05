/* sn-2.95.3-136 */
#include "godhand/cRelSys.h"

/* Clear the slot. */
__attribute__((section(".text.func_002BE550")))
cRelSlot *func_002BE550(cRelSlot *self) {
    self->data = 0;
    self->ok = 0;
    return self;
}
