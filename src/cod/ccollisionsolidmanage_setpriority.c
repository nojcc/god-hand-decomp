/* sn-2.95.3-136 */
#include "godhand/cCollisionSolid.h"

/* Set the priority of owner's unit. */
__attribute__((section(".text.cCollisionSolidManage_SetPriority")))
void cCollisionSolidManage_SetPriority(cCollisionSolidManage *self, struct cGameObj *owner, int priority) {
    cCollisionSolidUnit *unit = func_001346C8(self, owner);
    if (unit)
        Obj0000_Set_Field_8_134648(unit, priority);
}
