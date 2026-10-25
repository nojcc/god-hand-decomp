/* sn-2.95.3-136 */
/* NON_MATCHING func_001F4530: the save-flag read loads the data pointer into
 * v1 and the flag word into v0 in retail; this build swaps the two. */
#include "include_asm.h"
#include "godhand/gameWork.h"
#include "godhand/cCoreSave.h"
#include "godhand/ColiseumEmSelect.h"

#ifdef NON_MATCHING
/* Whether enemy em can be picked for stage: always once the game was cleared
 * (enemy 0x33 also needs save flag 0x800000), else for enemies below 0x29
 * whose stage is cleared. self is not read. */
__attribute__((section(".text.func_001F4530")))
int func_001F4530(ColiseumEmSelect *self, int em, int stage)
{
    int r;

    if (D_00747A2C.unk00 & 0x200)
        return 1;
    if (cCoreSave_getClearNum(&D_00569B70) != 0) {
        if (em == 0x33)
            r = D_00569B70.data->flags & 0x800000;
        else
            return 1;
    } else {
        if (em >= 0x29)
            return 0;
        r = cCoreSave_ckClearStage(&D_00569B70, (unsigned short)stage);
    }
    return r != 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F4530);
#endif
