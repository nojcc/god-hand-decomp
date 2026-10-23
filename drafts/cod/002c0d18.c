/* NON_MATCHING cSceAtUnit_AtInit (sn-2.95.3-136): 4 instructions differ. Retail keeps param3B (a3) in s1 and actType (t0) in s4; ours swaps the two. No order of the eight stores, and neither parameter type, changes that. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criStm.h"
#include "godhand/cSceAtUnit.h"

/* Clears the unit and fills its header: enabled, no id, the given type, parameters and action type. */
__attribute__((section(".text.cSceAtUnit_AtInit")))
void cSceAtUnit_AtInit(cSceAtUnit *self, int type, int param38, int param3B, int actType)
{
    func_003A52F0(self, 0, SCEATUNIT_SIZE);
    self->type = type;
    self->actType = actType;
    self->param38 = param38;
    self->param3B = param3B;
    self->flags = SCEATUNIT_FLAGS_INIT;
    self->unk39 = 8;
    self->actArg = 0x31;
    self->id = SCEATUNIT_NO_ID;
}
#else
INCLUDE_ASM("asm/nonmatching", cSceAtUnit_AtInit);
#endif
