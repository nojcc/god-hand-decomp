/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/heapArena.h"

extern int D_00460D18;

__attribute__((section(".text.func_00134520")))
void func_00134520(cCollisionSolidUnit *unit, void *body, cVec *center, float radius) {
    cCollisionSolidBody *p;
    cCollisionSolidBody *q;

    if (unit->owner != 0) {
        if (unit->first != 0) {
            q = unit->first;
            while (q->next != 0) {
                q = q->next;
            }
            p = (cCollisionSolidBody *)cCollisionSolid_constructSphere(func_0030F550(0x80), body, center, radius);
            q->next = p;
        } else {
            p = (cCollisionSolidBody *)cCollisionSolid_constructSphere(func_0030F550(0x80), body, center, radius);
            unit->first = p;
        }
        if (p != 0) {
            D_00460D18 = D_00460D18 + 1;
        }
    }
}
