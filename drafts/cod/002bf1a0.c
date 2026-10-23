/* NON_MATCHING cSaveLoad_openSave (sn-2.95.3-136, belongs in src/cod/system/cSaveLoad.c): 10 instructions differ, all in the tail after the slot store. Retail sets the return value 1 and the phase 1 before the busy-flag store and holds the flag word in a0 and the mask in v1; ours uses v1/v0 and stores arg2 before arg3. No statement order closes it. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cSaveLoad.h"

#ifdef NON_MATCHING
extern cSaveLoadGlobals D_00747A2C;
extern int D_005E6908;
extern int func_002BF700(cSaveLoad *self);
extern void func_002BF170(cSaveLoad *self);
/* Start a save: with no stage or the card locked just drop the busy bit; otherwise reset the
 * card, keep slot unless it is -1, raise the busy bit and write the request bytes. */
__attribute__((section(".text.cSaveLoad_openSave")))
int cSaveLoad_openSave(cSaveLoad *self, int slot)
{
    cSaveLoadGlobals *g = &D_00747A2C;

    if (g->stage < 0 || (g->flags & SAVELOAD_FLAG_LOCK) != 0) {
        g->stateFlags &= ~SAVELOAD_FLAG_BUSY;
        return 1;
    }
    if (func_002BF700(self) == 0)
        return 0;
    func_002BF170(self);
    if (slot != -1)
        D_005E6908 = slot;
    g->stateFlags |= SAVELOAD_FLAG_BUSY;
    self->mode = SAVELOAD_MODE_SAVE;
    self->phase = 1;
    self->arg3 = 0;
    self->arg2 = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", cSaveLoad_openSave);
#endif
