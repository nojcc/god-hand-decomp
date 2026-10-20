/* 336 exact pair: beql switch / color-anim schedule (46 words).
* task-list walks (s0/s1/s2 alloc); table clear beql shape.
* flag-or setter frame/s1.
* sqc2 %lo(v0) vs 0(v0) + beqz delay lui (1-ish shape, 10 words). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void *func_002D50C0(void *a0);
extern char D_005FEB00[];
extern int D_0044D1A8;

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
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("asm/nonmatching", func_002C5338);
#endif
