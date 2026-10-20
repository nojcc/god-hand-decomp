/* Ours folds the small constant-trip loop away; retail keeps it. */
#include "include_asm.h"

#ifdef NON_MATCHING

__attribute__((section(".text.func_0036DCE8")))
void func_0036DCE8(void)
{
    int i = 0x3F;

    while (i >= 0) {
        i -= 0x20;
    }
}

#else
INCLUDE_ASM("asm/nonmatching", func_0036DCE8);
#endif
