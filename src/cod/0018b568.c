/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmHitHolder.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(cOmBase *self);
extern EmPhaseTable4 D_004237C8;


__attribute__((section(".text.func_0018B568")))
void func_0018B568(cOmHitHolder *self)
{
    EmPhaseTable4 buf;
    long flags;
    if (ClearField5B4IfFlagUnset_1B76B0(&self->base) == 0) return;
    flags = (unsigned int)self->base.flags0;
    if (((flags >> 2) & 1) == 0) {
        buf = D_004237C8;
        EM_PHASE_RUN(&buf, self, self->base.mode);
        func_002A87E8(self, 0);
        func_001B76D8(&self->base);
    } else {
        cOmBase_updateWithHitRecord(self);
    }
}
