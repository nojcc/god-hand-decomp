#include "godhand/CustomIDWork.h"
#include "godhand/Poker.h"
extern void CustomIDWork_ResetMoveOffsetPos(void *);

__attribute__((section(".text.func_001DE050")))
void func_001DE050(Poker *self, int enabled)
{
    if (enabled)
        CustomIDWork_SetMoveOffsetPosXSin(&self->elem[0x2D], 4, 8);
    else
        CustomIDWork_ResetMoveOffsetPos(&self->elem[0x2D]);
}
