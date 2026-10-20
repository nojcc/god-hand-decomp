/* NON_MATCHING func_002B4028 (sn-2.95.3-136, as=sn): 41 insns; wrap clamp compiles to movz where retail branches.
 * PadState struct global fixes the address pattern. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void cSnd_SeCallGlobal(unsigned char *, int, int, int);
extern void func_002B4768(unsigned char *, unsigned char *, unsigned char *);
typedef struct {
    char pad[0x1A0];
    long trg;
    long f1A8;
    long rep;
} PadState;

extern PadState D_007474A0;
extern unsigned char *D_003C23A4;

__attribute__((section(".text.func_002B4028")))
void func_002B4028(unsigned char *a0)
{
    unsigned char *s0;
    int old;
    int w;

    s0 = a0;
    *(int *)(s0 + 0x14) |= 0x20;
    old = *(short *)(s0 + 0x94);
    if (D_007474A0.trg & 0x1000001000000L) {
        *(short *)(s0 + 0x94) = *(unsigned short *)(s0 + 0x94) - 1;
    }
    if (D_007474A0.trg & 0x2000002000000L) {
        *(short *)(s0 + 0x94) = *(unsigned short *)(s0 + 0x94) + 1;
    }
    if (*(short *)(s0 + 0x94) != old) {
        cSnd_SeCallGlobal(s0, 0, 0x15F, 0);
    }
    {
        int n = *(short *)(s0 + 0x94);
        unsigned short u = *(unsigned short *)(s0 + 0x94);
        if (n < 0) {
            w = *(unsigned short *)(s0 + 0x96) - 1;
        } else if (*(short *)(s0 + 0x96) - 1 < n) {
            w = 0;
        } else {
            w = u;
        }
    }
    *(short *)(s0 + 0x94) = w;
    if (D_007474A0.trg & 0x10000000L) {
        *(short *)(D_003C23A4 + 0xBEC) = w;
        cSnd_SeCallGlobal(s0, 0, 0x15E, 0);
        *(int *)(s0 + 0x14) = *(int *)(s0 + 0x14) & ~1;
        *(int *)(s0 + 0x14) = *(int *)(s0 + 0x14) & ~0x20;
        *(int *)(s0 + 0x14) = *(int *)(s0 + 0x14) | 0x400;
        func_002B4768(s0, s0 + 0x90, s0 + 0x8C);
        *(char *)(s0 + 0xC) = 2;
        *(char *)(s0 + 0xD) = 0;
        *(char *)(s0 + 0xE) = 0;
        *(char *)(s0 + 0xF) = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002B4028);
#endif
