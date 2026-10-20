/* NON_MATCHING func_002D4C20 (sn-2.95.3-136; PARK at attempt 3, score 18): DMA 16 blocks into the scratchpad. Register allocation and loop match; the scheduler pulls the loop-invariant ori's and an a0 reload ahead of the first call where retail leaves them after it. Retail's listing also tags the scratchpad pointer lui/addiu as %hi/%lo(D_70000040), a splitter false pair (0x40 is the per-block step), so the relocations cannot agree from C. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define REG(a) (*(volatile unsigned int *)(a))

extern void func_002D4DA0(int a0);

__attribute__((section(".text.func_002D4C20")))
void func_002D4C20(int a0, unsigned int src, unsigned int tadr, int stride)
{
    int i;

    REG(0x1000E020) = 0xFFFFFC00;
    REG(0x1000E010) = 0x200;
    REG(0x1000D410) = tadr;
    REG(0x1000D420) = 0x40;
    REG(0x1000D480) = 0x70000000;
    REG(0x1000E020) |= 0x200;
    REG(0x1000D400) = 0x101;
    func_002D4DA0(a0);

    for (i = 0; i < 16; i++) {
        REG(0x1000E020) = 0xFFFFFC00;
        REG(0x1000E010) = 0x100;
        REG(0x1000D010) = src + i * stride * 4;
        REG(0x1000D020) = 4;
        REG(0x1000D080) = 0x70000000 + i * 0x40;
        REG(0x1000E020) |= 0x100;
        REG(0x1000D000) = 0x100;
        func_002D4DA0(a0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002D4C20);
#endif
