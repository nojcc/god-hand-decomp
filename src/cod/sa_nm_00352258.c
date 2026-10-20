/* NON_MATCHING func_00352258: 32x64 multiply by 0x55D4A80 passed to func_003B7FE0.
 * An empty barrier stops the sibling tail-call; two diffs remain, mult and sd ra swapped. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_003B7FE0(long long v);

void func_00352258(int x)
{
    func_003B7FE0((long long)x * 0x55D4A80LL);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00352258);
#endif
