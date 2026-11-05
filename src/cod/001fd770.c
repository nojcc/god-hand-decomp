/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

extern void func_001FCCC0(void *a0);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.cDamageUnit_UpdateDamageCollFlash")))
void cDamageUnit_UpdateDamageCollFlash(cDamageUnit *self) {
    cDamageNode *p = self->nodes;
    while (p) {
        func_001FCCC0(p);
        p = p->next;
    }
}
