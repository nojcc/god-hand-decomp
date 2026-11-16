#include "godhand/DogRace.h"
extern void CustomIDWork_ResetMoveOffsetPos(void *);

/* Start (enabled set) or stop the sideways bob of element 36. */
__attribute__((section(".text.func_001ED4B0")))
void func_001ED4B0(DogRaceResult *self, int enabled)
{
    if (enabled)
        CustomIDWork_SetMoveOffsetPosXSin(&self->elem[36], 3, 0x10);
    else
        CustomIDWork_ResetMoveOffsetPos(&self->elem[36]);
}
