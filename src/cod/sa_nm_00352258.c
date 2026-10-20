/* NON_MATCHING func_00352258 (cygnus-2.96, drop-reorder; NEAR-MISS): 32x64 multiply by 0x55D4A80 passed to func_003B7FE0. An empty barrier stops the sibling tail-call; two diffs remain, mult and sd ra swapped. Best 2. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_003B7FE0(long long v);

void func_00352258(int x)
{
    func_003B7FE0((long long)x * 0x55D4A80LL);
    __asm__ __volatile__("" ::: "memory");
}
#else
INCLUDE_ASM("asm/nonmatching", func_00352258);
#endif
