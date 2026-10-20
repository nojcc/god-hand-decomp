/* NON_MATCHING func_00376370 (sn-2.95.3-136): same size, 8 insns: layout matches; the a0 = s argument copy is hoisted into the delay slot of the preceding beq (and the second test uses beq instead of retail's beql + increment), and the & 0x1000 lands in v1 not v0.
 * Tried: for/while, do-while with signed pointer compare, f &= 0x1000, continue form, -fno-gcse, ee-2.9-991111. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_00770850[];
extern void ClearInvalidEntry_376400(char *s);
extern void func_00376438(char *s);
extern void func_00376720(char *s);
extern void UpdateSlotState_3767B0(char *s);
extern void UpdatePendingFlags_376820(char *s);

void func_00376370(void)
{
    char *s = D_00770850;

    do {
        unsigned short f = *(unsigned short *)s;

        if (f == 0)
            continue;
        if (f & 0x1000)
            ClearInvalidEntry_376400(s);
        else
            func_00376438(s);
        if (*(unsigned short *)s == 0)
            continue;
        func_00376720(s);
        UpdateSlotState_3767B0(s);
        UpdatePendingFlags_376820(s);
    } while ((int)(s += 0xE0) < (int)(D_00770850 + 0x2A00));
}
#else
INCLUDE_ASM("asm/nonmatching", func_00376370);
#endif
