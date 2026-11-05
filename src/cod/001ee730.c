#include "godhand/CustomIDWork.h"
extern void CustomIDWork_ResetMoveOffsetPos(void *);

__attribute__((section(".text.func_001EE730")))
void func_001EE730(char *self, int enabled)
{
    if (enabled)
        CustomIDWork_SetMoveOffsetPosXSin((CustomIDWork *)(self + 0xDF0), 3, 0x10);
    else
        CustomIDWork_ResetMoveOffsetPos(self + 0xDF0);
}
