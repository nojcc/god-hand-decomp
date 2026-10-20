/* mode switch sb schedule / shared block.
 * slot write s1/s2 arg save order (8–15 words). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int func_0015FD68(void *self);

__attribute__((section(".text.func_002831C8")))
void func_002831C8(char *self, int mode, unsigned int val)
{
    unsigned char v = (unsigned char)val;

    if (mode == 1)
        goto m1;
    if (mode == 0)
        goto m0;
    if (mode == 2)
        goto m2;
    if (mode == 3)
        goto m3;
    return;
m0:
    self[0x2F7] = v;
    self[0x2F5] = 3;
    self[0x2F4] = 0;
    self[0x2F6] = 0;
    return;
m1:
    self[0x2F7] = v;
    self[0x2F5] = 3;
    self[0x2F6] = 2;
    self[0x2F4] = 0;
    return;
m2:
    self[0x2F7] = v;
    self[0x2F5] = 3;
    self[0x2F6] = 4;
    self[0x2F4] = 0;
    return;
m3:
    self[0x2F7] = v;
    self[0x2F5] = (char)mode;
    self[0x2F6] = 6;
    self[0x2F4] = 0;
}

__attribute__((section(".text.func_0015FCB8")))
int func_0015FCB8(char *self, int a1, int a2)
{
    int idx;
    char *s0 = self;
    int s1 = a1;
    char *slot;

    idx = func_0015FD68(s0);
    if (idx < 0)
        return 0;
    slot = s0 + (idx << 3);
    *(int *)(slot + 4) = s1;
    *(int *)slot = a2;
    return 1;
}
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("asm/nonmatching", func_002831C8);
INCLUDE_ASM("asm/nonmatching", func_0015FCB8);
#endif
