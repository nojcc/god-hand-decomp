/* 336 exact pair: beql switch / color-anim schedule (46 words).
 * task-list walks (s0/s1/s2 alloc); table clear beql shape.
 * flag-or setter frame/s1.
 * sqc2 %lo(v0) vs 0(v0) + beqz delay lui (1-ish shape, 10 words). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void CustomIDWork_ResetColorAnim(void *p);
extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *p, int c0, int c1, int frames);
extern void CustomIDWork_SetColorAnimNormal_2D6898(void *p, int c, unsigned short frames);
extern void SetFlagOnEntries7C_1D51B8(void *self, int id, int on);
extern void func_001E7470(void *self, int id, int on);
extern void func_002D5790(void *p);
extern void cTaskWork_kill(void *p);
extern void func_001B6FB8(void *self);
extern void cOl2b_setOpenFix(void *self, int mode);
extern void *func_002D50C0(void *a0);
extern int D_003F5520;
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
