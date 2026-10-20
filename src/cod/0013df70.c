/* NON_MATCHING func_0013DF70 (sn-2.95.3-136): 17 insns, 38 words vs 39; retail builds the element pointer in v0 and copies it to s0 for the delay-slot store, ours allocates it to s0 directly. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int cIDBase_initialize(void *id, int a1, int a2);

void func_0013DF70(char *self)
{
    unsigned short i;

    for (i = 0; i < 8; i++) {
        int off = i * 0x50;
        char *p;

        cIDBase_initialize(self + (off + 0x90), 1, 0x12);
        p = off + self;
        *(float *)(p + 0xD0) = 0.00724635f;
        *(short *)(p + 0xD4) = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013DF70);
#endif
