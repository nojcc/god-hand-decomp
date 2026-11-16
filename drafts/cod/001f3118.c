/* NON_MATCHING func_001F3118: sn; switch tree fixed by an empty case 2; remaining: lw vs lwu on the 64-bit flag test, case-0 b/a masks not folded to andi 0x7373, and case-1 uninitialized CustomIDColor locals land in a3 instead of t0 (retail register = phantom by-value param pattern under checkpoint-90 review) */
#include "godhand/CustomIDPanel.h"
#include "include_asm.h"

#ifdef NON_MATCHING
extern void CustomIDWork_SetColorAnimNormal_2D68D8(CustomIDWork *work, int a1, CustomIDColor col, int frames);

void func_001F3118(CustomIDPanel *self)
{
    CustomIDColor col;
    CustomIDColor from;
    CustomIDColor to;
    long t;

    t = self->flags;
    if ((((unsigned long)t >> 1) & 1UL) != 1UL)
        return;
    switch (self->anim[1].state) {
    case 0:
        col.r = 0x73;
        col.g = 0x73;
        col.b = 0x73;
        col.a = 0x80;
        CustomIDWork_SetColorAnimNormal_2D68D8(&self->work[2], 0, col, 15);
        SetCustomIDDispOneOrAll_1F29C0(self, 2, 1);
        self->anim[1].timer = 15;
        self->anim[1].state++;
        break;
    case 1:
        if (self->anim[1].timer != 0) {
            self->anim[1].timer--;
            break;
        }
        from.r = 0x73;
        from.g = 0x73;
        from.b = 0x73;
        from.a = 0x80;
        to.r = 0xA8;
        to.g = 0xA8;
        to.b = 0xA8;
        to.a = 0x80;
        CustomIDWork_SetColorAnimSin(&self->work[2], *(unsigned int *)&from, *(unsigned int *)&to, 3);
        self->anim[1].state++;
        break;
    case 2:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F3118);
#endif
