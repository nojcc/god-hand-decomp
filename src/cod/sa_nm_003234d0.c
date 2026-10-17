/* NON_MATCHING func_003234D0 (cygnus-2.96, -freorder-blocks dropped, as=sn): same size, 10 insns: control flow and error sharing match; with volatile stores the store order matches too, but the return copy v0 = p is scheduled early so 0x200 lands in v1 (retail: li v0, 0x200 hoisted to the top of the block and the return copy last). Without volatile the scheduler hoists the 0x2C and second byte stores. Tried: plain stores, swapped byte stores, volatile view, struct type, -fno-gcse (not kept). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char *func_00323478(void);
extern int func_00327D00(int a0, int size);
extern void func_0033F130(char *msg);
extern char D_004515E8[];
extern char D_00451620[];

char *func_003234D0(void)
{
    char *p = func_00323478();

    if (p == 0) {
        func_0033F130(D_004515E8);
        return 0;
    }
    if ((*(int *)(p + 4) = func_00327D00(0, 0x100)) == 0) {
        func_0033F130(D_00451620);
        return 0;
    }
    {
        volatile char *q = p;

        q[0] = 1;
        q[1] = 1;
        *(volatile int *)(q + 0x18) = 0;
        *(volatile int *)(q + 0x1C) = 0;
        *(volatile int *)(q + 0x20) = 0;
        q[2] = 0;
        *(volatile int *)(q + 8) = 0;
        q[3] = 0;
        *(volatile int *)(q + 0x2C) = 0x200;
    }
    return p;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003234D0);
#endif
