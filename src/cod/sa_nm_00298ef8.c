/* NON_MATCHING func_00298EF8 (sn-2.95.3-136): same size, 13 insns differ, all one register swap: retail keeps idx in a1 and the id/flag variable in v1; this allocates them the other way round.
 * Tried: case order (fixed the layout), shared int/unsigned/ushort id variable, int idx narrowed at use. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned char D_003C0548[];
extern unsigned char D_003C0549;
extern unsigned char D_003C054A;

void func_00298EF8(char *obj, unsigned char idx)
{
    int v;

    if (obj == 0)
        return;
    v = *(unsigned short *)(obj + 0x2FE);
    switch (v) {
    case 0x3DA:
        v = D_003C0548[idx];
        break;
    case 0x2A2:
        v = D_003C0548[0];
        break;
    case 0x2A3:
        v = D_003C0549;
        break;
    case 0x2A6:
        v = D_003C054A;
        break;
    default:
        return;
    }
    if (v == 0)
        *(int *)(obj + 0x250) |= 0x8002;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00298EF8);
#endif
