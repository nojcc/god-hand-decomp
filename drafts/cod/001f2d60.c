/* NON_MATCHING func_001F2D60 (sn-2.95.3-136): same CustomIDColor family as 001f3118.c */
#include "include_asm.h"
#include "godhand/cSnd.h"
#include "godhand/CustomIDPanel.h"
#include "godhand/cCamManager.h"
#include "godhand/cCamera.h"

#ifdef NON_MATCHING
extern void CustomIDWork_SetColorAnimNormal_2D68D8(CustomIDWork *work, CustomIDColor from, CustomIDColor to, unsigned short frames);

static inline void setCol(CustomIDColor *c, int r, int g, int b, int a)
{
    c->r = r;
    c->g = g;
    c->b = b;
    c->a = a;
}

void func_001F2D60(CustomIDPanel *self)
{
    CustomIDColor c0;
    CustomIDColor c1;
    CustomIDColor from;
    CustomIDColor to;
    long t;

    t = self->flags;
    if ((((unsigned long)t >> 0) & 1UL) != 1UL)
        return;
    switch (self->anim[0].state) {
    case 0:
        setCol(&c1, 0x80, 0x80, 0x80, 0x80);
        setCol(&c0, 0x80, 0x80, 0x80, 0);
        self->anim[0].timer = 15;
        CustomIDWork_SetColorAnimNormal_2D68D8(&self->work[0], c0, c1, self->anim[0].timer);
        SetCustomIDDispOneOrAll_1F29C0(self, 0, 1);
        setCol(&c0, 0x80, 0x80, 0x80, 0);
        setCol(&c1, 0xD0, 0xD0, 0xD0, 0x80);
        CustomIDWork_SetColorAnimNormal_2D68D8(&self->work[1], c0, c1, self->anim[0].timer);
        SetCustomIDDispOneOrAll_1F29C0(self, 1, 1);
        self->anim[0].state++;
        break;
    case 1:
        if (self->anim[0].timer != 0) {
            self->anim[0].timer--;
            break;
        }
        from.r = 0x50;
        to.r = 0xD0;
        from.g = 0x50;
        to.g = 0xD0;
        from.b = 0x50;
        to.b = 0xD0;
        from.a = 0x80;
        to.a = 0x80;
        self->anim[0].timer = 30;
        CustomIDWork_SetColorAnimSin(&self->work[1], *(unsigned int *)&to, *(unsigned int *)&from, 6);
        self->anim[0].state++;
        break;
    case 2:
        if (self->anim[0].timer != 0) {
            self->anim[0].timer--;
            break;
        }
        CustomIDWork_SetColorAnimNormal_2D6898(&self->work[0], 0xFFFFFF, 10);
        CustomIDWork_ResetColorAnim(&self->work[1]);
        CustomIDWork_SetColorAnimNormal_2D6898(&self->work[1], 0xFFFFFF, 10);
        CustomIDWork_SetScaleAnimNormal(&self->work[0], 1.0f, 2.5f, 10);
        CustomIDWork_SetScaleAnimNormal(&self->work[1], 1.0f, 2.0f, 10);
        cSnd_SeCall(&D_005FEE00, 2, 0x105, &D_005CAFF0->eye, 0, 0);
        self->anim[0].timer = 10;
        self->anim[0].state++;
        break;
    case 3:
        if (self->anim[0].timer != 0) {
            self->anim[0].timer--;
            break;
        }
        SetCustomIDDispOneOrAll_1F29C0(self, 0, 0);
        SetCustomIDDispOneOrAll_1F29C0(self, 1, 0);
        SetCustomIDDispOneOrAll_1F29C0(self, 0xB, 0);
        SetCustomIDDispOneOrAll_1F29C0(self, 0xC, 0);
        self->anim[0].state = 0;
        self->anim[0].timer = 0;
        self->flags &= ~CIDPANEL_ANIM0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F2D60);
#endif
