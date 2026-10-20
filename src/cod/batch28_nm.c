/* jump-table jalr reg alloc (v0/v1 swap).
 * slot scan delay-slot / loop shape; bnel count walk.
 * float bit-pack handwritten add schedule;
 * beql range predicate; halfword clamp reg alloc; beql/bltz flag test;
 * fighting-ring bit-test a2 vs a0 + andi/sll order. */
#include "include_asm.h"
#include "godhand/cCoreSave.h"

#ifdef NON_MATCHING
extern int D_0076A7AC;
extern void (*D_003F2810[])(int);
extern unsigned char D_007474A0[];
typedef struct { int a; int b; } Pair28;
extern Pair28 D_007558A8[];

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
    unsigned int b = 0x28000000;
    unsigned int c = 0x7FFF0000;
    unsigned int d;
    union { unsigned int i; float f; } u;

    a = a & a3;
    a = a + b;
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

__attribute__((section(".text.func_002FEBE8")))
void func_002FEBE8(char *a0, unsigned int a1, int a2)
{
    unsigned int cur = *(unsigned short *)(a0 + 0x22C);
    unsigned int base;
    int one;

    a1 &= 0xFFFF;
    if (cur == 0) {
        *(unsigned short *)(a0 + 0x22C) = a1;
        return;
    }
    one = 1;
    base = *(unsigned short *)(a0 + 0x224);
    if (a2 == one)
        goto store;
    if (a2 == 0 && (int)(cur - base) < (int)a1) {
store:
        *(unsigned short *)(a0 + 0x22C) = a1 + base;
    }
}

#else
INCLUDE_ASM("asm/nonmatching", func_0037D298);
INCLUDE_ASM("asm/nonmatching", func_00156508);
INCLUDE_ASM("asm/nonmatching", func_001C2328);
INCLUDE_ASM("asm/nonmatching", func_002FEBE8);
#endif
