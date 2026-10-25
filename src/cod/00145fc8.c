/* sn-2.95.3-136: func_00145FC8, pop-in phase of the ID screen: shrink the scale each frame,
 * fade in colour 0 on every row, then colour 1 on the second row's fourth entry, then stop. */
#include "godhand/cIDBaseScreen.h"

__attribute__((section(".text.func_00145FC8")))
void func_00145FC8(cIDBaseScreen *self)
{
    unsigned short i;
    float t;
    float u;

    self->scale *= 0.7f;
    switch (self->step) {
    case 0:
        self->step++;
    case 1:
        self->color0 += 0xE0000000;
        if (self->color0 == 0x808080) {
            self->scale = 1.0f;
            self->step++;
        }
        for (i = 0; i < SCR_ROW_NUM; i++) {
            self->tbl[i][2]->sclX = (t = D_0041E880[i]) * (1.0f - self->scale + 1.0f);
            t *= self->scale;
            self->tbl[i][2]->sclY = t;
            if (i != 1)
                self->tbl[i][0]->colorBase.word = self->color0;
        }
        self->tbl[1][2]->colorBase.word = self->color0;
        break;
    case 2:
        self->color1 += 0xF0000000;
        if (self->color1 == 0x808080)
            self->step++;
        self->tbl[1][3]->colorBase.word = self->color1;
        u = D_0041E880[1];
        self->tbl[1][3]->sclX = u * (1.0f - self->scale + 1.0f);
        u *= self->scale;
        self->tbl[1][3]->sclY = u;
        break;
    case 3:
        self->flags &= ~SCR_FLAG_READY;
        self->flags &= ~SCR_FLAG_SHOWN;
        self->phase = 0;
        self->step = 0;
        break;
    }
}
