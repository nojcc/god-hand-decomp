/* NON_MATCHING cOl0e_setFake (sn-2.95.3-136): body matches; retail keeps the constant 1 of the gone test in v1 and reuses it for the fake == 1 test, ours loads it again. */
/* sn-2.95.3-136: cOl0e_setFake, switch the object into the fake state (fake == 1: damage volumes off, hit
 * entry inactive, mode 1) or back out of it, unless the object is gone; either way the state bytes after
 * the mode are cleared and the animation rate goes back to 1. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOl0e.h"

extern void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);

__attribute__((section(".text.cOl0e_setFake")))
void cOl0e_setFake(cOl0e *self, int fake)
{
    long flags0 = (unsigned int)self->base.flags0;
    long gone = flags0 >> 1 & 1;

    if (gone != 1) {
        self->fake = fake;
        if (fake == 1) {
            if (self->damage != 0)
                cDamageUnit_SetDamageCollActive(self->damage, 0);
            if (self->hit != 0)
                self->hit->flags &= ~COL0E_HIT_ACTIVE;
            self->base.mode = fake;
            self->base.flags2 &= ~COL0E_FLAG2_FAKE;
        } else {
            if (self->damage != 0)
                cDamageUnit_SetDamageCollActive(self->damage, 1);
            if (self->hit != 0)
                self->hit->flags |= COL0E_HIT_ACTIVE;
            self->base.mode = 0;
            self->base.flags2 |= COL0E_FLAG2_FAKE;
        }
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        self->base.animRate = 1.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cOl0e_setFake);
#endif
