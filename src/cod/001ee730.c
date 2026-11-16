#include "godhand/DogRace.h"
extern void CustomIDWork_ResetMoveOffsetPos(void *);

/* Start (enabled set) or stop the sideways bob of element 28. */
__attribute__((section(".text.func_001EE730")))
void func_001EE730(DogRaceList *self, int enabled)
{
    if (enabled)
        CustomIDWork_SetMoveOffsetPosXSin(&self->elem[28], 3, 0x10);
    else
        CustomIDWork_ResetMoveOffsetPos(&self->elem[28]);
}
