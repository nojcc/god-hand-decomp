/* sn-2.95.3-136: func_0031A6B0, distance level of a world point: its camera-space depth times ten, shifted down by
 * the owner's level shift at 0xB58; points behind the camera give 0.
 * Differs from retail: retail converts the depth in place (cvt.w.s $f0, $f0); ours converts into a second register. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cCamManager.h"
#include "godhand/sceVu0.h"

__attribute__((section(".text.func_0031A6B0")))
unsigned int func_0031A6B0(void *self, cVec *pos)
{
    cVec v;
    unsigned int level;
    float depth;

    sceVu0ApplyMatrix(&v, D_005CAFF0, pos);
    depth = v.w * 10.0f;
    level = 0;
    if (!(depth < 0.0f)) {
        level = (int)depth;
    }
    return level >> *((unsigned char *)self + 0xB58);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0031A6B0);
#endif
