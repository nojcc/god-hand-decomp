/* Batch 29 near-misses — not registered.
 * 72: VU0 matrix ×4 with handwritten addi.
 * 76: flag-clear call schedule; float lhu scan; sqc2 %lo(v0) vs 0(s0) (1 word).
 * 80: table index return bnel; MMI psllw pack; movn pos select; dual-base jalr;
 *     null/vtable return shape; beql/bnel slot walk.
 * 84: RoundFloat special cvt.w.s; Adjust_theta handwritten add.
 * 6-attempt cap. Closest: func_002C5338 (1 word, sqc2 base). */
#include "include_asm.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
extern void cEmSetParam_updateSetDataFlag(void *set, int id, unsigned int flags);
extern char D_00586AB0[];
extern void *func_002D50C0(void *a0);
extern int D_0044D1A8;
typedef struct { unsigned char b[16]; } Quad16_b29;
extern Quad16_b29 D_005FEB00;
extern int func_00151630(void *a0);
extern void CustomIDWork_SetLocalPosX(void *a0, int x);
extern int D_00747A0C;
extern void func_001EC088(void *a0);
extern char D_003BE528[];
extern int func_0030FCC0(void *a0);
extern char D_00770850[];

__attribute__((section(".text.func_0030A2E0")))
void func_0030A2E0(float *dst, float *mtx, float *src)
{
    int n = 4;

    (void)mtx;
    do {
        __asm__ volatile(
            ".set push\n.set noreorder\n"
            "lqc2 $vf8, 0(%0)\n"
            ".set pop\n"
            :
            : "r"(src));
        (void)dst;
        n--;
        src += 4;
        dst += 4;
    } while (n != 0);
}

__attribute__((section(".text.func_002C5338")))
void func_002C5338(int enabled, unsigned int type)
{
    char *s0;

    if (type == 0xFFFF && enabled != 0) {
        s0 = (char *)&D_005FEB00;
        __asm__ __volatile__("sqc2 $vf0, %0" : : "m"(D_005FEB00) : "memory");
        s0 += 0x1C;
        func_002D50C0(s0);
        *(int **)(s0 + 0x30) = &D_0044D1A8;
    }
}

__attribute__((section(".text.func_00156550")))
void func_00156550(int *dst, int *src)
{
    *dst = *src;
}

__attribute__((section(".text.func_001DF7D0")))
void func_001DF7D0(char *self, int cond)
{
    int v = D_00747A0C;
    int a1;
    int alt;

    if (v == 0 || v < 0 || !(v < 7)) {
        a1 = 0x12;
        alt = -0x61;
    } else {
        a1 = 0x19;
        alt = -0x4F;
    }
    if (cond)
        a1 = alt;
    CustomIDWork_SetLocalPosX(self + 0x440, a1);
}

__attribute__((section(".text.Adjust_theta")))
float Adjust_theta(float th)
{
    const float invpi = 0.318309886f;
    const float pi = 3.14159265f;
    int n = (int)(th * invpi);

    return th - (float)n * pi;
}

#else
INCLUDE_ASM("asm/nonmatching", func_0030A2E0);
INCLUDE_ASM("asm/nonmatching", func_002C5338);
INCLUDE_ASM("asm/nonmatching", func_00156550);
INCLUDE_ASM("asm/nonmatching", func_001DF7D0);
INCLUDE_ASM("asm/nonmatching", Adjust_theta);
#endif
