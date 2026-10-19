/* sn-2.95.3-136: append an image upload (BITBLTBUF/TRXREG/TRXDIR + IMAGE data tag) to the double-buffered
 * DMA packet list and queue it. Sibling of func_00150DC8. */
typedef unsigned long u64_151168;

extern int D_00747A2C;
extern unsigned int D_007476B0;
extern char D_00754C80[];
extern void func_0031A650(void *queue, int kind, int id, void *start, void *end);

__attribute__((section(".text.func_00151168")))
int func_00151168(char *buf, int src, int psm, int dbp, int unused, int width, int height, int mode, int kind)
{
    int n;
    char *p;
    int qwc;

    if (mode >= 0 && (D_00747A2C & 0x800))
        return -1;
    n = *(int *)(buf + 0x3C);
    if (n == 0x280)
        return -1;
    p = buf + (n * 0x180 + 0x40) + (D_007476B0 & 1) * 0xC0;
    *(int *)(buf + 0x3C) = n + 1;
    width /= 2;
    if (psm == 0x14)
        height /= 4;
    else if (psm == 0x13)
        height /= 2;
    qwc = (width * height) >> 2;
    *(u64_151168 *)p = ((u64_151168)((int)(p + 0x70) & 0x0FFFFFFF) << 32) | 0x20000006;
    *(int *)(p + 0xC) = 0x50000006;
    *(u64_151168 *)(p + 0x20) = ((u64_151168)dbp << 32) | ((u64_151168)(width / 64) << 48);
    *(u64_151168 *)(p + 0x40) = width | ((u64_151168)height << 32);
    *(u64_151168 *)(p + 0x60) = (u64_151168)(unsigned int)(qwc | 0x8000) | ((u64_151168)0x8000 << 44);
    *(u64_151168 *)(p + 0x70) = (u64_151168)(unsigned int)(qwc | 0x30000000)
                              | ((u64_151168)(src & 0x0FFFFFFF) << 32);
    *(int *)(p + 0x7C) = qwc | 0x50000000;
    if (kind == 0 || kind == 3)
        func_0031A650(D_00754C80, 1, 0xE, p, p + 0x80);
    else if (kind == 2)
        func_0031A650(D_00754C80, 6, 8, p, p + 0x80);
    else if (kind == 1)
        func_0031A650(D_00754C80, 1, 2, p, p + 0x80);
    return 0;
}
