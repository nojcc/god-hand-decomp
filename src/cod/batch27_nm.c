/* Batch 27 near-misses — not registered (would collide with asm fragments).
 * 32: movn / branch-shape (lhu+slti range test).
 * 36: xor+sltiu vs bne dual-exit (0xCDCDCDCD check); closest 4-word delay/reg.
 * 40: AreaSet andi/mov.s delay-slot swap only.
 * 48: cam wrapper sd/addiu schedule; list walk missing load-delay nop;
 *     flag setter beql vs beq + store order.
 * 52: FP-frame + dead branches (C++ EH shape); float cvt f4/f1 vs in-place f0.
 * 6-attempt cap. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_001F88A8(void *o, float *s, unsigned char t, float x, float y, float z);
extern int cCamManager_isCk_CamClass(void *mgr, int cls);
extern char D_00463050[];
extern int func_0030F348(void);

__attribute__((section(".text.func_00307118")))
int func_00307118(int a0)
{
    a0 = *(int *)a0;
    if (a0 != (int)0xCDCDCDCD) {
        __asm__ volatile("");
        return 0;
    }
    __asm__ volatile("");
    return 1;
}

__attribute__((section(".text.cSceAtUnit_AreaSet")))
void cSceAtUnit_AreaSet(void *u, float *v, int n, float a, float b)
{
    unsigned char t;

    __asm__ volatile("" : "+f"(b) : "f"(a));
    t = (unsigned char)n;
    func_001F88A8((char *)u + 4, v, t, a, a, b);
}

__attribute__((section(".text.func_00123908")))
int func_00123908(void)
{
    char *s0 = D_00463050;
    int one = 1;
    int r;

    __asm__ volatile("" : "+r"(s0), "+r"(one));
    r = cCamManager_isCk_CamClass(s0, one);
    __asm__ volatile("" :: "r"(s0));
    return r;
}

__attribute__((section(".text.func_0027DB20")))
void func_0027DB20(unsigned char *a0, int a1)
{
    int v0 = 1;

    if (a1 == 0)
        goto other;
    if (a1 == 1)
        goto is_one;
other:
    v0 = 5;
    a0[0x2F7] = 0;
    goto store;
is_one:
    a0[0x2F7] = (unsigned char)a1;
    v0 = 5;
store:
    a0[0x2F5] = (unsigned char)v0;
    a0[0x2F4] = 0;
    __asm__ volatile("" ::: "memory");
    a0[0x2F6] = 0;
}

__attribute__((section(".text.func_0030F518")))
float func_0030F518(void)
{
    union {
        unsigned u;
        float f;
    } scale;
    unsigned v;
    float f1;

    v = (unsigned)func_0030F348() >> 1;
    f1 = (float)(int)v;
    scale.u = 0x30000000U;
    __asm__ volatile("" : "+f"(f1) : "r"(scale.u));
    return f1 * scale.f;
}

#else
INCLUDE_ASM("asm/nonmatching", func_00307118);
INCLUDE_ASM("asm/nonmatching", cSceAtUnit_AreaSet);
INCLUDE_ASM("asm/nonmatching", func_00123908);
INCLUDE_ASM("asm/nonmatching", func_0027DB20);
INCLUDE_ASM("asm/nonmatching", func_0030F518);
#endif
