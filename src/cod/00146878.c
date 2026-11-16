#include "godhand/idPair.h"

/* Reset the banner, empty its queue and restart the first part's animation. */
__attribute__((section(".text.func_00146878")))
void func_00146878(IdPair *self)
{
    IdPair_init(self);
    self->count = 0;
    cIDBase_restartAnim(&self->base);
    self->base.playing = 1;
}
