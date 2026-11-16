/* NON_MATCHING func_0013DB50 (sn-2.95.3-136, extern_jtbl D_0041DF40): 206 of 207 words; the code after case 3 matches, shifted by one. Retail keeps case 3's third colour (on) in memory at sp+0 in a 0xB0 frame and saves fp without using it; ours keeps it in fp (0xA0 frame). Two delay slots differ as well: case 2 loads the frame count for func_002D69A8 last, and case 3 issues its first call before setting a0. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/CustomIDPanel.h"
#include "godhand/CustomIDWork.h"
#include "godhand/IDPanelScreen.h"

extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *work, unsigned int from, unsigned int to, int frames);

/* Icon screen intro: after a short wait flash panel 4 white, show panels 0 and 2 and grow panel 2, fade panel 4
 * and bring in panel 1, pulse panel 1, wait for the child screens, then fade in panel 3. Step 7 is the finished state. */
__attribute__((section(".text.func_0013DB50")))
void func_0013DB50(IDPanelScreen *self)
{
    switch (self->flashStep) {
    case 0:
        self->flashTimer = 8;
        self->flashStep++;
        break;
    case 1:
        if (self->flashTimer == 0) {
            CustomIDColor col;

            col.r = 0x80; col.g = 0x80; col.b = 0x80; col.a = 0x80;
            CustomIDWork_SetColorAnimNormal_2D6898(&self->cw[4], *(unsigned int *)&col, 1);
            CustomIDWork_SetDisp(&self->cw[4], 1);
            self->flashStep++;
        } else {
            self->flashTimer--;
        }
        break;
    case 2:
        self->flashTimer = 0x14;
        CustomIDWork_SetDisp(&self->cw[0], 1);
        CustomIDWork_SetDisp(&self->cw[2], 1);
        func_002D69A8(&self->cw[2], self->flashTimer, 1.0f, 0.0f);
        self->flashStep++;
        break;
    case 3:
        if (self->flashTimer == 0) {
            CustomIDColor from, to, on;

            from.r = 0x80; from.g = 0x80; from.b = 0x80; from.a = 0x80;
            to.r = 0xD0; to.g = 0xD0; to.b = 0xD0; to.a = 0;
            CustomIDWork_SetColorAnimNormal_2D68D8(&self->cw[4], *(unsigned int *)&from, *(unsigned int *)&to, 0xF);
            CustomIDWork_SetDisp(&self->cw[1], 1);
            on.r = 0x80; on.g = 0x80; on.b = 0x80; on.a = 0x80;
            CustomIDWork_SetColorAnimNormal_2D68D8(&self->cw[1], 0, *(unsigned int *)&on, 6);
            self->flashTimer = 6;
            self->flashStep++;
        } else {
            self->flashTimer--;
        }
        break;
    case 4:
        if (self->flashTimer == 0) {
            CustomIDColor from, to;

            from.r = 0x80; from.g = 0x80; from.b = 0x80; from.a = 0x80;
            to.r = 0xD0; to.g = 0xD0; to.b = 0xD0; to.a = 0x80;
            CustomIDWork_SetColorAnimSin(&self->cw[1], *(unsigned int *)&from, *(unsigned int *)&to, 6);
            self->flashStep++;
        } else {
            self->flashTimer--;
        }
        break;
    case 5:
        if (self->step == 2) {
            self->flashStep++;
        }
        break;
    case 6: {
        CustomIDColor from, to;

        CustomIDWork_SetDisp(&self->cw[3], 1);
        from.r = 0x80; from.g = 0x80; from.b = 0x80; from.a = 0;
        to.r = 0x80; to.g = 0x80; to.b = 0x80; to.a = 0x80;
        CustomIDWork_SetColorAnimNormal_2D68D8(&self->cw[3], *(unsigned int *)&from, *(unsigned int *)&to, 0x1E);
        self->flashStep++;
        break;
    }
    case 7:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013DB50);
#endif
