/* sn-2.95.3-136. Differs from retail in register allocation only (same length, 30
 * instructions): retail keeps the collision pointer in a1 and re-reads *touch for the
 * toucher store; ours keeps a copy of it. */
#include "include_asm.h"
#include "godhand/cOmDoor.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING

/* Empties the contact list. */
static __inline__ void cObjCollision_clearTouch(cObjCollision *coll)
{
    func_003A52F0(coll->touch, 0, sizeof(coll->touch));
    coll->touchNum = 0;
}

/* Counts a player or enemy contact on the door and remembers it, then empties the contact list. */
__attribute__((section(".text.func_001BD430")))
void func_001BD430(cOmDoor *self)
{
    cObjCollision *coll = self->collision;
    cGameObj **touch;
    unsigned int i;

    if (coll != 0) {
        if (coll->touch[0] != 0) {
            touch = coll->touch;
            for (i = 0; i < coll->touchNum; i++, touch++) {
                if (cGameObj_idInRange(*touch, 0x100, 0x1FF) == 1
                    || cGameObj_idInRange(*touch, 0x200, 0x300) == 1) {
                    self->toucher = *touch;
                    self->touchedNum++;
                    break;
                }
            }
        } else {
            self->toucher = 0;
            self->touchedNum = 0;
        }
        cObjCollision_clearTouch(self->collision);
    } else {
        self->toucher = 0;
        self->touchedNum = 0;
    }
}

#else
INCLUDE_ASM("asm/nonmatching", func_001BD430);
#endif
