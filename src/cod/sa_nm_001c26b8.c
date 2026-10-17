/* NON_MATCHING func_001C26B8 (sn-2.95.3-136, as=sn): 15 insns, 64 words vs 54. Retail copies the Turn_dest result (mov.s f1,f0) and builds |a| in a third register (bc1f with mov.s in the delay slot, then neg.s f2,f1); it also loads the yaw arg before a1. Inline Absf gives 26 insns at the right size. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

int func_001C26B8(char *self)
{
    char *pl = Getplayer();
    float d = capVu0MagnitudeSqXZ(*(void **)(pl + 0xF0), *(void **)(self + 0xF0));
    float a;

    if (d < 0.5f) {
        return 1;
    }
    if (d > 2.0f) {
        return 0;
    }
    a = Turn_dest(*(void **)(pl + 0xF0), *(void **)(self + 0xF0), *(float *)(pl + 0x104), 3.1415927f);
    if (ABS(a) < 0.5235988f) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C26B8);
#endif
