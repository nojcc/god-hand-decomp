/* sn-2.95.3-136 matched TU. */
#include "godhand/cSubScrMenu.h"

/* Move the menu's status, item and level displays. */
__attribute__((section(".text.func_001661A0")))
void func_001661A0(cSubScrMenu *self)
{
    cIDBase_move(&self->status);
    cIDBase_move(&self->items);
    cIDBase_move(&self->level);
}
