/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"

/* Sphere destructor: put the sphere table back, then run the base destructor. */
__attribute__((section(".text.InitVtableField30Alt_133A80")))
void InitVtableField30Alt_133A80(cCollisionSolidObj *self, int flags) {
    self->base.vt = &D_0041D7E0;
    cCollisionSolid__dtor(&self->base, flags);
}
