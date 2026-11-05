/* NON_MATCHING func_001346C8 (sn-2.95.3-136): find the collision unit of an owner. Retail pads the
 * loop with a short-loop nop between the owner load and bnel; the loop holds an inner branch,
 * and neither assembler pads it. The C is otherwise identical. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cCollisionSolid.h"

/* The unit owned by owner, or 0. */
cCollisionSolidUnit *func_001346C8(cCollisionSolidManage *self, struct cGameObj *owner)
{
    cCollisionSolidUnit *u;

    if (owner == 0) {
        return 0;
    }
    for (u = self->first; u != 0; u = u->next) {
        if (u->owner == owner) {
            break;
        }
    }
    return u;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001346C8);
#endif
