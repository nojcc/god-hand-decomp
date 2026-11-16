#include "godhand/CustomIDPanel.h"

/* Draw both displays of the panel. */
__attribute__((section(".text.func_001F2990")))
void func_001F2990(CustomIDPanel *self)
{
    cIDBase_trans(&self->id);
    cIDBase_trans(&self->id2);
}
