/* NON_MATCHING func_002C31D0 (sn-2.95.3-136, as=sn): 24 insns, 40 words vs 44; retail loops have three nops between c.le.s/c.lt.s and bc1tl, which no C spelling here produces. */
#include "include_asm.h"

#ifdef NON_MATCHING
float func_002C31D0(float a)
{
    if (a >= 3.1415927f) {
        do {
            a -= 6.2831855f;
        } while (a >= 3.1415927f);
    } else if (a < -3.1415927f) {
        do {
            a += 6.2831855f;
        } while (a < -3.1415927f);
    }
    return a;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C31D0);
#endif
