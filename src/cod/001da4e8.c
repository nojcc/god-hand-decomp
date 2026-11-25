/* sn-2.95.3-136: func_001DA4E8, poker panel slide-in sequence. */
#include "godhand/Poker.h"
#include "godhand/decCount.h"
extern void func_001DE088(Poker *self, unsigned char mode);
extern void func_001DE170(Poker *self, unsigned char mode);
extern void func_001DE258(Poker *self, unsigned char mode);
extern void func_001DE340(Poker *self, unsigned char mode);
extern void CustomIDOwner_setSlideState(Poker *self, unsigned char sel);
extern void PanelWork_setModeB(Poker *self, unsigned char mode);
extern void Panel_slide(Poker *self, unsigned char mode);

extern void CustomIDOwner_setSlideStateB(void *self, unsigned char sel);
extern void PokerUi_slidePanel(void *ui, int mode);
extern void Panel_slideSidePanelArrows(void *ui, int mode);
extern void UiPanel_setSlideMode(void *self, unsigned char mode);
extern void func_001DEE40(void *self, int number);

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
        char *ui;
        int v;

        if (DecCount(&self->timer) == 0) {
            break;
        }
        ui = POKER_UI(self);
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
