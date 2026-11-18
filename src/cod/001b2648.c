/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_001B76D8(cOmBase *self);
extern EmPhaseTable D_003BDCF8;


__attribute__((section(".text.func_001B2648")))
void func_001B2648(cOmBase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDCF8, self, self->mode);
    func_001B76D8(self);
}
