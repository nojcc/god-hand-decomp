#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"

/* Unit constructor: zero the bounds, set owner, priority and 0x0C, no solids. */

__attribute__((section(".text.func_00134430")))
cCollisionSolidUnit *func_00134430(cCollisionSolidUnit *self, struct cGameObj *owner, int priority, float unk0C) {
    VU0_SQC2_VF0(self, 0x20);
    VU0_SQC2_VF0(self, 0x30);
    self->owner = owner;
    self->priority = priority;
    self->unk0C = unk0C;
    self->first = 0;
    self->next = 0;
    return self;
}
