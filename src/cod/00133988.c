/* cygnus-2.96 */
#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"

/* Base constructor: clear the flags, point vt at the base table, zero the bounds, the kind and the next link, then
 * set flag bit 0. Returns the body. */
__attribute__((section(".text.cCollisionSolid")))
cCollisionSolidBody *cCollisionSolid(cCollisionSolidBody *self) {
    self->flags = 0;
    self->vt = &D_0041D808;
    VU0_SQC2_VF0(self, 0x10);
    VU0_SQC2_VF0(self, 0x20);
    self->kind = 0;
    self->next = 0;
    self->flags |= 1;
    return self;
}
