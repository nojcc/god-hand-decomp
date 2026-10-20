/* NON_MATCHING func_003257C8 (cygnus-2.96, drop-reorder; PARK): six long stores of 1. Retail materialises each address with addiu then sd offset 0; both cygnus and sn fold the %lo into the sd. Best 21. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern long D_003C8158;
extern long D_003C8168;
extern long D_003C8178;
extern long D_003C8188;
extern long D_003C8198;
extern long D_003C81A8;

void func_003257C8(void)
{
    D_003C8158 = 1;
    D_003C8168 = 1;
    D_003C8178 = 1;
    D_003C8188 = 1;
    D_003C8198 = 1;
    D_003C81A8 = 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003257C8);
#endif
