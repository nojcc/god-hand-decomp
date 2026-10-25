#include "godhand/cFont.h"

__attribute__((section(".text.func_002A58A0")))
void func_002A58A0(cFont *font, int value)
{
    *(int *)((char *)font + 0x2A060) = value;
    func_002A58D8(font, 0xFFFFFFFF);
}
