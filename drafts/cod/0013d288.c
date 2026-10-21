/* NON_MATCHING func_0013D288 (sn, call-arg schedule): everything matches except the first drawPolyF call's argument setup order (retail f12, f15, f13, f14 with a1=0 in the jal slot; ours a1=0 first and mov.s f14 in the slot).
* Locals for the constants, an int color and a hoisted height don't move it. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned int D_00747A84;
extern void *D_003C2FB0;
extern void cScrSpriteDraw_drawInit(void *self);
extern void cScrSpriteDraw_drawPolyF(void *self, unsigned int color, float x, float y, float w, float h);

void func_0013D288(void)
{
    unsigned int *sys = &D_00747A84;

    if (!(*sys & 0x08000000) && ((unsigned short *)sys)[-0x1A] != 0x20) {
        cScrSpriteDraw_drawInit(D_003C2FB0);
        cScrSpriteDraw_drawPolyF(D_003C2FB0, 0, 0.0f, 0.0f, 512.0f, 4.0f);
        cScrSpriteDraw_drawPolyF(D_003C2FB0, 0, 0.0f, 445.0f, 512.0f, 3.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013D288);
#endif
