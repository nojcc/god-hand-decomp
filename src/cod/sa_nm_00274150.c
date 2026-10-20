/* NON_MATCHING func_00274150 (sn-2.95.3-136): 14 insns, same size.
 * Switch decision tree halves are laid out in the opposite order (retail falls into the > 0x260 side and branches to the low side); case 0x260 in retail shares the FindNodeByHit-failed return block. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned short D_00747A50;
extern char D_005FEA60[];
extern int FindNodeByHit_2C2490(void *mgr, void *pos, void *out);

int func_00274150(char *self)
{
    if (D_00747A50 != 0x200 && D_00747A50 != 0x204) {
        return 0;
    }
    switch (*(int *)(self + 0x564)) {
    case 0x220 ... 0x223:
    case 0x260:
    case 0x264 ... 0x265:
    case 0x26A:
        return 0;
    }
    if (*(float *)(self + 0x1734) > 0.0f) {
        return 0;
    }
    if (FindNodeByHit_2C2490(D_005FEA60, *(void **)(self + 0xF0), self + 0x6C0) == 1) {
        *(float *)(self + 0x1734) = 300.0f;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00274150);
#endif
