#include "godhand/cIDBase.h"

__attribute__((section(".text.func_0013ECF0")))
int func_0013ECF0(char *p)
{
    int result = cIDBase_initialize((cIDBaseObj *)p, 1, 2);
    *(short *)(p + 0xBE) = -1;
    return result;
}
