/* sn-2.95.3-136 matched TU. */
#include "godhand/cCockLoading.h"

/* Set up the display (id 2) and clear unkBE to -1; returns cIDBase_initialize's result. */
__attribute__((section(".text.func_0013ECF0")))
int func_0013ECF0(cCockLoading *self)
{
    int result = cIDBase_initialize(&self->base, 1, 2);
    self->unkBE = -1;
    return result;
}
