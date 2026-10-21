/* NON_MATCHING func_00150DC8: DMA packet append.
* Computing p before the count store gives the retail entry copies and p in a3.
* Remaining: retail tests the mode parity as xori+andi+beqz; every xor spelling ((mode ^ 1) & 1, ~mode & 1, a precomputed flag) moves p to t1 and adds three a3 copies, while the !(mode & 1) forms lose the xori word. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef int TI150DC8 __attribute__((mode(TI)));
typedef unsigned long u64;

extern int D_00747A2C;
extern unsigned int D_007476B0;
extern char D_00754C80[];
extern void func_0031A650(void *queue, int kind, int id, void *start, void *end);

__attribute__((section(".text.func_00150DC8")))
int func_00150DC8(char *buf, char *obj, int ofs, int mode, int kind)
{
    int n;
    char *p;
    char *src;

    if (mode >= 0 && (D_00747A2C & 0x800))
        return -1;
    n = *(int *)(buf + 0x3C);
    if (n == 0x280)
        return -1;
    p = buf + (n * 0x180 + 0x40) + (D_007476B0 & 1) * 0xC0;
    *(int *)(buf + 0x3C) = n + 1;
    src = *(char **)(obj + 4);
    *(int *)(p + 0xC) = 0x50000005;
    *(u64 *)p = ((u64)((int)(p + 0x70) & 0x0FFFFFFF) << 32) | 0x20000005;
    *(TI150DC8 *)(p + 0x20) = *(TI150DC8 *)(src + 0x10);
    if (!(mode & 1))
        *(int *)(p + 0x24) = *(int *)(p + 0x24) + ofs;
    else
        *(int *)(p + 0x24) = ofs | 0x10000;
    *(TI150DC8 *)(p + 0x40) = *(TI150DC8 *)(src + 0x30);
    *(u64 *)(p + 0x70) = (((*(int *)(src + 0x50) & 0x7FFF) + 1) | 0x30000000)
                              | ((u64)((int)(src + 0x50) & 0x0FFFFFFF) << 32);
    *(int *)(p + 0x7C) = ((*(int *)(src + 0x50) & 0x7FFF) + 1) | 0x50000000;
    if (kind == 0 || kind == 3)
        func_0031A650(D_00754C80, 1, 0xE, p, p + 0x80);
    else if (kind == 2)
        func_0031A650(D_00754C80, 6, 8, p, p + 0x80);
    else if (kind == 1)
        func_0031A650(D_00754C80, 1, 2, p, p + 0x80);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00150DC8);
#endif
