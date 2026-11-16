/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"

/* Base destructor: put the base table back, then free the body when flags bit 0 is set. */
__attribute__((section(".text.cCollisionSolid__dtor")))
void cCollisionSolid__dtor(cCollisionSolidBody *self, int flags) {
    self->vt = &D_0041D808;
    if (flags & 1) {
        __builtin_delete(self);
    }
}
