/* sn-2.95.3-136 */
/* cIDBase_getIDWork. Retail strength-reduces the loop into two pointers, the
 * entry and &entry->flags (id read at -2 from it); this C keeps one pointer
 * and reads both fields at fixed offsets, 25 words against retail's 28. */
#include "include_asm.h"
#include "godhand/cIDBase.h"

#ifdef NON_MATCHING
extern cIDBaseEnt D_005CB300;

/* Returns the active entry with this id, or the shared dummy entry. */
__attribute__((section(".text.cIDBase_getIDWork")))
cIDBaseEnt *cIDBase_getIDWork(cIDBaseObj *self, int id)
{
    int i;

    if (self->ent == 0)
        return &D_005CB300;
    for (i = 0; i < self->entNum; i++) {
        if ((self->ent[i].flags & IDENT_FLAG_ACTIVE) && self->ent[i].id == id)
            return &self->ent[i];
    }
    return &D_005CB300;
}
#else
INCLUDE_ASM("asm/nonmatching", cIDBase_getIDWork);
#endif
