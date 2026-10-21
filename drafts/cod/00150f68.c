/* NON_MATCHING func_00150F68 (sn-2.95.3-136): src param lands in s0 (0x20 frame) where retail
 * keeps it in t4 with a 0x10 frame; dead div trap on bpr placed differently.
* Sibling of sa_00151168. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef unsigned long u64;

extern int D_00747A2C;
extern unsigned int D_007476B0;
extern char D_00754C80[];
extern void func_0031A650(void *queue, int kind, int id, void *start, void *end);

__attribute__((section(".text.func_00150F68")))
int func_00150F68(char *buf, int src, int psm, int dbp, int dbw, int width, int height, int mode, int kind)
{
    int n;
    char *p;
    int bpr;
    unsigned int qwc;

    if (mode >= 0 && (D_00747A2C & 0x800))
        return -1;
    n = *(int *)(buf + 0x3C);
    if (n == 0x280)
        return -1;
    p = buf + (n * 0x180 + 0x40) + (D_007476B0 & 1) * 0xC0;
    *(int *)(buf + 0x3C) = n + 1;
    switch (psm) {
    case 0:
        bpr = width * 4;
        break;
    case 0x13:
        bpr = width;
        break;
    case 0x14:
        bpr = width / 2;
        break;
    default:
        return 0;
    }
    qwc = (unsigned int)(bpr * height) >> 4;
    *(u64 *)p = ((u64)((int)(p + 0x70) & 0x0FFFFFFF) << 32) | 0x20000006;
    *(int *)(p + 0xC) = 0x50000006;
    *(u64 *)(p + 0x20) = ((u64)dbp << 32) | ((u64)dbw << 48) | ((u64)psm << 56);
    *(u64 *)(p + 0x40) = width | ((u64)height << 32);
    *(u64 *)(p + 0x60) = (u64)(qwc | 0x8000) | ((u64)0x8000 << 44);
    *(u64 *)(p + 0x70) = (u64)(qwc | 0x30000000)
                              | ((u64)(src & 0x0FFFFFFF) << 32);
    *(int *)(p + 0x7C) = qwc | 0x50000000;
    if (kind == 0 || kind == 3)
        func_0031A650(D_00754C80, 1, 0xE, p, p + 0x80);
    else if (kind == 2)
        func_0031A650(D_00754C80, 6, 8, p, p + 0x80);
    else if (kind == 1)
        func_0031A650(D_00754C80, 1, 2, p, p + 0x80);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00150F68);
#endif
