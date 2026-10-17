/* NON_MATCHING func_00307878 (sn-2.95.3-136, as=sn, -O0): 6 insns; retail keeps the != 0 result in a register (copy to v0, andi 0xFF on return); a plain local spills it to the frame and a register local reallocates the earlier temps. */
#include "include_asm.h"

#ifdef NON_MATCHING
__attribute__((section(".text.func_00307878")))
unsigned char func_00307878(register unsigned int *bits, register unsigned int n)
{
    int r = (bits[n >> 5] & (0x80000000U >> (n & 0x1F))) != 0;
    return r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00307878);
#endif
