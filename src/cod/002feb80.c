#include "godhand/espSys.h"

__attribute__((section(".text.func_002FEB80")))
void func_002FEB80(EspAnim *self, int a, int b)
{
    if (a == self->unk108 && b == self->unk10C)
        UpdateObjByIndexedOp_2FBE50(self);
}
