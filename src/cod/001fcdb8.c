#include "godhand/cDamageGive.h"

extern void ActorRec_reset(void *);

__attribute__((section(".text.func_001FCDB8")))
void func_001FCDB8(cDamageGive *self)
{
    ActorRec_reset(self);
    self->unk34 = 0;
    self->type = CDAMAGE_TYPE_GIVE;
}
