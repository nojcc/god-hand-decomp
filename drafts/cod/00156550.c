/* VU0 matrix ×4 with handwritten addi.
* flag-clear call schedule; float lhu scan; sqc2 %lo(v0) vs 0(s0) (1 word).
* table index return bnel;
* MMI psllw pack; movn pos select; dual-base jalr;
* null/vtable return shape; beql/bnel slot walk.
* RoundFloat special cvt.w.s;
* Adjust_theta handwritten add. */
#include "include_asm.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING

__attribute__((section(".text.func_0030A2E0")))
void func_0030A2E0(float *dst, float *mtx, float *src)
{
    int n = 4;

    /* incomplete: the VU0 body (lqc2 into vf8 per row) has no C form yet */
    do {
        n--;
        src += 4;
        dst += 4;
    } while (n != 0);
}

__attribute__((section(".text.func_00156550")))
void func_00156550(int *dst, int *src)
{
    *dst = *src;
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
INCLUDE_ASM("asm/nonmatching", func_00156550);
INCLUDE_ASM("asm/nonmatching", Adjust_theta);
#endif
