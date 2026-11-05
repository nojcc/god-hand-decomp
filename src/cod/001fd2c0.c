#include "godhand/cDamageGive.h"
#include "godhand/cDamageUnit.h"

__attribute__((section(".text.SetObjTargetAndActivate_1FD2C0")))
int SetObjTargetAndActivate_1FD2C0(cDamageGive *self, int kind, void *owner)
{
    if (self->type == CDAMAGE_TYPE_SPARE)
        return 1;
    self->unk34 = 0;
    self->owner = owner;
    func_001FD988((cDamageUnit *)self, kind);
    self->live = 1;
    return 1;
}
