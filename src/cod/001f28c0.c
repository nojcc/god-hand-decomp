#include "godhand/CustomIDPanel.h"

extern int cIDBase_release(void *);

/* Release both displays of the panel, the second one first. */
__attribute__((section(".text.func_001F28C0")))
void func_001F28C0(CustomIDPanel *self)
{
    cIDBase_release(&self->id2);
    cIDBase_release(&self->id);
}
