/* NON_MATCHING func_001346C8 (sn-2.95.3-136): find the collision unit of an owner. Retail pads the
 * loop with a short-loop nop between the owner load and bnel; the loop holds an inner branch,
 * and neither assembler pads it. The C is otherwise identical. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"

/* One collision unit in the manager's list. */
typedef struct cCollUnit {
    cOmBase *owner;                     /* 0x00 */
    int unk04;                          /* 0x04 */
    int priority;                       /* 0x08 */
    float share;                        /* 0x0C */
    struct cCollUnit *next;             /* 0x10 */
} cCollUnit;

typedef struct cCollUnitList {
    cCollUnit *head;                    /* 0x00 */
    int count;                          /* 0x04 */
} cCollUnitList;

/* The unit owned by owner, or 0. */
cCollUnit *func_001346C8(cCollUnitList *list, cOmBase *owner)
{
    cCollUnit *u;

    if (owner == 0) {
        return 0;
    }
    for (u = list->head; u != 0; u = u->next) {
        if (u->owner == owner) {
            break;
        }
    }
    return u;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001346C8);
#endif
