/* sn-2.95.3-136: func_001B76D8, per-frame model update: clear the 0x40 state bit when allowed, scroll the textures,
 * recalc the parts when forced or when the position / rotation changed since the last frame, latch the current
 * position and rotation, and kill the object when it fell below y = -1000. */
extern unsigned int D_00747A84;
extern void cModel_ScrollTexture(void *self, float rate);
extern void cModel_calcParts(void *self);
extern void cOmBase_dieCommon(void *self);

#include "godhand/vecInline.h"

__attribute__((section(".text.func_001B76D8")))
void func_001B76D8(char *p)
{
    long tmp;
    long t2;
    long a;
    long b;
    long t0;

    t0 = *(unsigned int *)(p + 0x5B0);
    t0 = t0 & 1;
    if (t0 == 1) {
        t2 = *(unsigned int *)(p + 0x5B8);
        t2 = t2 >> 9;
        t2 = t2 & 1;
        if (t2 == 0 && (D_00747A84 & 0x1000000) == 0)
            *(int *)(p + 0x5B8) &= ~0x40;
    }
    cModel_ScrollTexture(p, 1.0f);
    tmp = *(unsigned int *)(p + 0x5B8);
    a = (tmp >> 4) & 1;
    if (a == 1 || (b = (tmp >> 3) & 1) == 1
        || vec4_ne((float *)(p + 0x490), *(float **)(p + 0xF0))
        || vec4_ne((float *)(p + 0x5D0), (float *)(p + 0x100))) {
        cModel_calcParts(p);
        *(int *)(p + 0x5B8) &= ~0x10;
    }
    vec3_copy((float *)(p + 0x490), *(float **)(p + 0xF0));
    vec3_copy((float *)(p + 0x5D0), (float *)(p + 0x100));
    if ((*(float **)(p + 0xF0))[1] < -1000.0f)
        cOmBase_dieCommon(p);
}
