/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/globals.h"

/* Destructor of the body kind with table D_0041D790: put its table back, then run the base destructor. */
__attribute__((section(".text.InitVtableField30Ptr_133BA0")))
void InitVtableField30Ptr_133BA0(cCollisionSolidBody *self, int flags) {
    self->vt = &D_0041D790;
    cCollisionSolid__dtor(self, flags);
}
