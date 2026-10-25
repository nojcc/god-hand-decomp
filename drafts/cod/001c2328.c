/* sn-2.95.3-136 */
/* NON_MATCHING func_001C2328: retail has a nop between the first slti and its
 * bnez (0x1C2340) that this build doesn't emit; everything else matches. */
#include "include_asm.h"
#include "godhand/cOmBase.h"

#ifdef NON_MATCHING
/* 1 while the object is idle in step 2, 3, 6 or 7. */
__attribute__((section(".text.func_001C2328")))
int func_001C2328(cOmBase *self)
{
    if (self->mode != 0)
        return 0;
    switch (self->step) {
    default:
        return 0;
    case 2:
    case 3:
    case 6:
    case 7:
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C2328);
#endif
