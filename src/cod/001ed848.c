/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/CustomIDWork.h"
#include "godhand/DogRace.h"
#include "godhand/cCamManager.h"
#include "godhand/cCamera.h"

extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *a0, int a1, int a2, int a3);

/* sn-2.95.3-136 */

#define COL(x) ((((((((x) & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000)

__attribute__((section(".text.func_001ED848")))
void func_001ED848(DogRaceUi *self) {
    int c0, c1, c2, c3, c4, c5, c6, c7;
    long fl;

    fl = (unsigned int)self->flags;
    if ((fl & DOGRACE_UI_F_INTRO) == 0) {
    } else {
        switch (self->step) {
        case 0: {
            CustomIDWork *w0 = &self->elem[0];
            CustomIDWork_SetColorAnimNormal_2D68D8(w0, COL(c1), COL(c0) | 0x80000000, 0x14);
            CustomIDWork_SetScaleAnimNormal(w0, 0xA, 6.0f, 1.5f);
            CustomIDWork_SetDisp(w0, 1);
            self->step += 1;
            self->timer = 0x1E;
            break;
        }
        case 1:
            if (self->timer == 0) {
                CustomIDWork *w1;
                CustomIDWork_SetDisp(&self->elem[0], 0);
                w1 = &self->elem[1];
                CustomIDWork_SetColorAnimNormal_2D68D8(w1, COL(c2), COL(c3) | 0x80000000, 0x14);
                CustomIDWork_SetScaleAnimNormal(w1, 0xA, 6.0f, 1.5f);
                CustomIDWork_SetDisp(w1, 1);
                self->step += 1;
                self->timer = 0x1E;
            } else {
                if (self->timer == 0xF) {
                    cSnd_SeCall(&D_005FEE00, 2, 0xB0, &D_005CAFF0->eye, 0, 0);
                }
                self->timer -= 1;
            }
            break;
        case 2:
            if (self->timer == 0) {
                CustomIDWork *w2;
                CustomIDWork_SetDisp(&self->elem[1], 0);
                w2 = &self->elem[2];
                CustomIDWork_SetColorAnimNormal_2D68D8(w2, COL(c4), COL(c5) | 0x80000000, 0x14);
                CustomIDWork_SetScaleAnimNormal(w2, 0xA, 6.0f, 1.5f);
                CustomIDWork_SetDisp(w2, 1);
                self->step += 1;
                self->timer = 0x1E;
            } else {
                if (self->timer == 0xF) {
                    cSnd_SeCall(&D_005FEE00, 2, 0xB0, &D_005CAFF0->eye, 0, 0);
                }
                self->timer -= 1;
            }
            break;
        case 3:
            if (self->timer == 0) {
                CustomIDWork_SetDisp(&self->elem[2], 0);
                CustomIDWork_SetDisp(&self->elem[3], 1);
                self->step += 1;
                self->timer = 0x1E;
            } else {
                if (self->timer == 0xF) {
                    cSnd_SeCall(&D_005FEE00, 2, 0xB0, &D_005CAFF0->eye, 0, 0);
                }
                self->timer -= 1;
            }
            break;
        case 4:
            if (self->timer == 0) {
                CustomIDWork_SetColorAnimNormal_2D68D8(&self->elem[3], COL(c6) | 0x80000000, COL(c7), 0xA);
                self->step += 1;
                self->timer = 0xA;
            } else {
                if (self->timer == 0x14) {
                    cSnd_SeCall(&D_005FEE00, 2, 0xB1, &D_005CAFF0->eye, 0, 0);
                }
                self->timer -= 1;
            }
            break;
        case 5:
            if (self->timer == 0) {
                Panel_hideIcons(self);
            } else {
                self->timer -= 1;
            }
            break;
        }
    }
}
