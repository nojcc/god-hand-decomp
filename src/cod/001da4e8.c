/* sn-2.95.3-136: func_001DA4E8, poker panel slide-in sequence. */
#include "godhand/Poker.h"

static inline unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DA4E8")))
void func_001DA4E8(Poker *self)
{
    switch (self->phase) {
    case 0:
        self->timer = 0x1E;
        self->unk3045 = 0;
        self->phase += 1;
        break;
    case 1:
        if (DecCount(&self->timer) == 0) {
            break;
        }
        Panel_slide(self, 3);
        func_001DE088(self, 3);
        func_001DE170(self, 3);
        func_001DE258(self, 3);
        func_001DE340(self, 3);
        CustomIDOwner_setSlideState(self, 3);
        PanelWork_setModeB(self, 3);
        self->timer = 0x1E;
        self->phase += 1;
        break;
    case 2: {
        PanelObj *ui;
        int v;

        if (DecCount(&self->timer) == 0) {
            break;
        }
        ui = &self->ui;
        CustomIDOwner_setSlideStateB(ui, 2);
        PokerUi_slidePanel(ui, 2);
        Panel_slideSidePanelArrows(ui, 2);
        v = self->payout;
        self->bet = v;
        func_001DEE40(ui, v);
        UiPanel_setSlideMode(ui, 2);
        self->phase = 0;
        self->state = 0xD;
        break;
    }
    }
}
