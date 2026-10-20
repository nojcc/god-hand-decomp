/* NON_MATCHING func_001FE748 (sn-2.95.3-136; PARK, best 70): walk the data slots from the top; for each state-8 slot that passes the 0xFFFE check, release every slot holding the same kind. The shape and calls match. Retail rebuilds 0x5C in v0 on every outer pass (and in the back-branch delay) and hoists only the inner 0x5C into s7, so the outer mult is not shared; here both share one hoisted register and every saved register after s5 shifts by one. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cDataManager.h"

extern void func_001FF110(cDataSlot *slot);
extern int func_001FF6E0(cDataSlot *slot, int kind);
extern int func_001FF710(cDataSlot *slot, int kind);

void func_001FE748(cDataManager *self)
{
    int i;
    int j;
    int kind;

    i = self->slotNum;
    for (i--; i != -1; i--) {
        func_001FF110(&self->slot[i]);
        if (func_001FF6E0(&self->slot[i], 0xFFFE) != 0 && self->slot[i].state == 8) {
        kind = self->slot[i].kind;
        func_001FF710(&self->slot[i], 0xFFFE);
        j = self->slotNum;
        for (j--; j != -1; j--) {
            if (func_001FF0D8(&self->slot[j]) != 0
                && func_001FF6E0(&self->slot[j], kind) != 0
                && func_001FF710(&self->slot[j], kind) != 0) {
                self->slot[j].useCount = 0;
                ResetSlotState_1FF2E0(&self->slot[j], 0);
            }
        }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FE748);
#endif
