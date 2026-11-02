/* sn-2.95.3-136 */
#include "godhand/idPair.h"

/* Resets the banner, empties its queue and starts its animation. */
__attribute__((section(".text.func_00146878")))
void func_00146878(IdPair *self)
{
    IdPair_init(self);
    self->count = 0;
    cIDBase_play(&self->base);
}
