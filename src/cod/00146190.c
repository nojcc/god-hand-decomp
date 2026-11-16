/* sn-2.95.3-136: func_00146190, closing animation of the five-row screen: shrink the
 * second entry of every row to nothing, then shrink the first entries of the first four
 * rows by a third of their base scale a frame and clear the screen once they vanish. */
#include "godhand/cIDBaseScreen.h"

__attribute__((section(".text.func_00146190")))
void func_00146190(cIDBaseScreen *self) {
    float d;
    unsigned short i;

    switch (self->step) {
    case 0:
        self->step++;
        self->scale = 1.0f;
        break;
    case 1:
        self->scale *= 0.3f;
        for (i = 0; i < SCR_ROW_NUM; i++) {
            self->tbl[i][1]->sclY = self->scale;
            self->tbl[i][1]->sclX = self->scale;
        }
        if (self->scale < 0.01f)
            self->step++;
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            d = D_0041E880[i] / 3.0f;
            self->tbl[i][0]->sclX -= d;
            self->tbl[i][0]->sclY -= d;
            if (self->tbl[i][0]->sclX < 0.001f) {
                self->flags &= ~SCR_FLAG_READY;
                self->flags &= ~SCR_FLAG_SHOWN;
                self->step = 0;
                self->phase = 0;
            }
        }
        break;
    }
}
