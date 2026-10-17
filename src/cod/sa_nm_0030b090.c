/* NON_MATCHING func_0030B090 (sn-2.95.3-136): 39 insns, 40 words vs 46. Retail keeps a1 = &D_00747A2C and a0 = a1 - 0x58C as two live bases (D_00747A2C - 0x58C is the pad block D_007474A0, count at +0x5A0); GCC here folds the constant address and anchors negative offsets at a1 - 0x8000. A PadBlk struct on D_007474A0 is worse (43). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int D_00747A2C[];

#define I(p, o) ((p)[(o) / 4])

void func_0030B090(void)
{
    int *p = D_00747A2C;
    int *b;
    int c;

    if (!(I(p, 0x10) & 0x100000)) {
        return;
    }
    if (I(p, -8) & 0x8000) {
        return;
    }
    b = p - 0x58C / 4;
    if (I(p, -8) & 0x4000) {
        I(b, 0x5A0) = 0;
    }
    if ((I(p, -0x58C) & 0x90F) != 0x90F) {
        I(p, -8) &= ~0x1000;
        I(b, 0x5A0) = 0;
        return;
    }
    c = I(b, 0x5A0) + 1;
    I(b, 0x5A0) = c;
    if ((float)c >= 15.0f && !(I(p, -8) & 0x1000)) {
        I(p, -8) |= 0x8000;
        I(b, 0x5A0) = 0;
        I(p, -8) |= 0x1000;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030B090);
#endif
