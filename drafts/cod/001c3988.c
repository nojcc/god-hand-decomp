/* NON_MATCHING func_001C3988 (sn-2.95.3-136): the never-read stack copy of the part count
 * makes retail load the count into a temp and copy it to a second register, which the plain locals here do not;
* rest of the loop (lo kept in a register, bounds-checked part lookup) is right.
* Clears then sets part flags 0x08/0x10
 * around cModel_calcParts. */
#include "include_asm.h"
#include "godhand/cModel.h"

#ifdef NON_MATCHING
extern void func_001B7EA8(char *p, float *src);

__attribute__((section(".text.func_001C3988")))
void func_001C3988(char *p)
{
    int f[4];
    long t;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B7EA8(p);
    t = *(unsigned int *)(p + 0x5B0);
    if (((t >> 1) & 1) == 1)
        return;
    i = 1;
    if (i < *(signed char *)(p + 0x60C) && i < (b1 = *(unsigned char *)(p + 0x2B4))) {
        lo = 0;
        n = 1;
        while (1) {
            ok1 = ((f[0] = b1), (n >= lo && i < b1));
            if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
            *(int *)(obj1 + 0x154) &= ~8;
            ok2 = ((f[0] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
            if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
            *(int *)(obj2 + 0x154) &= ~0x10;
            i++;
            n++;
            if (!(i < *(signed char *)(p + 0x60C) && i < (b1 = *(unsigned char *)(p + 0x2B4))))
                break;
        }
    }
    cModel_calcParts(p);
    i = 1;
    if (i < *(signed char *)(p + 0x60C) && i < (b1 = *(unsigned char *)(p + 0x2B4))) {
        lo = 0;
        n = 1;
        while (1) {
            ok1 = ((f[0] = b1), (n >= lo && i < b1));
            if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
            *(int *)(obj1 + 0x154) |= 8;
            ok2 = ((f[0] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
            if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
            *(int *)(obj2 + 0x154) |= 0x10;
            i++;
            n++;
            if (!(i < *(signed char *)(p + 0x60C) && i < (b1 = *(unsigned char *)(p + 0x2B4))))
                break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C3988);
#endif
