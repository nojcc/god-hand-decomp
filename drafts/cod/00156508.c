/* jump-table jalr reg alloc (v0/v1 swap).
* slot scan delay-slot / loop shape; bnel count walk.
* float bit-pack handwritten add schedule;
* beql range predicate; halfword clamp reg alloc; beql/bltz flag test;
* fighting-ring bit-test a2 vs a0 + andi/sll order. */
#include "include_asm.h"
#include "godhand/cCoreSave.h"

#ifdef NON_MATCHING
#include "godhand/espSys.h"
extern int D_0076A7AC;
extern void (*D_003F2810[])(int);
typedef struct { int a; int b; } Pair28;

__attribute__((section(".text.func_0037D298")))
void func_0037D298(int a0)
{
    void (*fn)(int) = D_003F2810[D_0076A7AC];

    fn((char)a0);
}

__attribute__((section(".text.func_00156508")))
float func_00156508(int a0)
{
    unsigned int v0 = a0;
    unsigned int a3 = v0 << 14;
    unsigned int a = 0x1F800000;
    unsigned int c = 0x7FFF0000;
    unsigned int d;
    union { unsigned int i; float f; } u;

    a = a & a3;
    a = a + 0x28000000;
    c = c >> 8;
    c = c & a3;
    a3 = a3 << 2;
    c = c | a;
    d = 0x80000000 & a3;
    u.i = c | d;
    return u.f;
}

__attribute__((section(".text.func_001C2328")))
int func_001C2328(unsigned char *a0)
{
    int v = a0[0x2F4];

    if (v == 0)
        v = a0[0x2F6];
    else
        return 0;
    if (v < 2)
        return 0;
    if (v < 4)
        return 1;
    if (v < 8) {
        if (v < 6)
            return 0;
        return 1;
    }
    return 0;
}

/* Set the frame the animation ends at, `len` frames after the current one:
 * always for mode 1, for mode 0 only when that lengthens the run. Differs from
 * retail only in which of v0/v1 holds the end frame and the constant 1. */
__attribute__((section(".text.func_002FEBE8")))
void func_002FEBE8(EspAnim *self, unsigned short len, int mode)
{
    int end = self->frameEnd;
    int idx;
    int left;

    if (end == 0) {
        self->frameEnd = len;
        return;
    }
    idx = self->frameIdx;
    left = end - idx;
    if (mode == 1 || (mode == 0 && left < len)) {
        self->frameEnd = len + idx;
    }
}

#else
INCLUDE_ASM("asm/nonmatching", func_0037D298);
INCLUDE_ASM("asm/nonmatching", func_00156508);
INCLUDE_ASM("asm/nonmatching", func_001C2328);
INCLUDE_ASM("asm/nonmatching", func_002FEBE8);
#endif
