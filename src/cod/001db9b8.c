/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/Poker.h"


/* sn-2.95.3-136 matched TU. */

static inline unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DB9B8")))
void func_001DB9B8(Poker *self)
{
    switch (self->phase) {
    case 0:
        cSnd_SetBgmState(&D_005FEE00, 0);
        self->timer = 0x1E;
        self->phase += 1;
        break;
    case 1:
        if (DecCount(&self->timer) == 0) {
            break;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[0]->obj, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, self->hand[1]->obj, 0, 0, 0, 0);
        self->unk302C = 0xF;
        self->phase += 1;
        break;
    case 2: {
        float d;
        PanelObj *ui;
        int n;
        d = -((15.0f - (float)self->unk302C) / 15.0f);
        *self->hand[0]->obj->pos = d + D_005681C0[0].x;
        *self->hand[1]->obj->pos = d + D_005681C0[1].x;
        n = self->unk302C;
        if (n == 0) {
            ui = &self->ui;
            CustomIDOwner_setSlideStateB(ui, 3);
            PokerUi_slidePanel(ui, 3);
            Panel_slideSidePanelArrows(ui, 3);
            UiPanel_setSlideMode(ui, 3);
            self->timer = 0x14;
            self->phase += 1;
        } else {
            self->unk302C = n - 1;
        }
        break;
    }
    case 3:
        if (DecCount(&self->timer) == 0) {
            break;
        }
        self->bet = 0;
        SetCustomIDNumberIndexed_1DD648(self, 0, 0x32);
        SetCustomIDNumberIndexed_1DD648(self, 1, 0x14);
        SetCustomIDNumberIndexed_1DD648(self, 2, 0xF);
        SetCustomIDNumberIndexed_1DD648(self, 3, 0xA);
        SetCustomIDNumberIndexed_1DD648(self, 4, 8);
        SetCustomIDNumberIndexed_1DD648(self, 5, 8);
        SetCustomIDNumberIndexed_1DD648(self, 6, 3);
        SetCustomIDNumberIndexed_1DD648(self, 7, 2);
        func_001DD5A0(self, 1);
        func_001DE088(self, 2);
        func_001DE170(self, 2);
        func_001DE258(self, 2);
        func_001DE340(self, 2);
        CustomIDOwner_setSlideState(self, 2);
        PanelWork_setModeB(self, 2);
        Panel_slide(self, 2);
        self->bet = 0;
        CustomIDWork_SetNumber_1DD218(self, 0);
        func_001DD770(self, 2);
        func_001DD840(self, 2);
        func_001DD910(self, 2);
        func_001DD9E0(self, 2);
        self->timer = 0x1E;
        self->phase += 1;
        break;
    case 4:
        if (DecCount(&self->timer) == 0) {
            break;
        }
        self->state = 0;
        self->phase = 0;
        break;
    }
}
