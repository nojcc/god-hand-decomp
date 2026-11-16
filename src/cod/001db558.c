/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/Poker.h"
#include "godhand/cSnd.h"

extern long D_007474A0[];
extern long D_00747640;

/* sn-2.95.3-136 candidate. */















static __inline__ unsigned char TickDown(int *p)
{
    int v;

    v = *p;
    if (v == 0) {
        return 1;
    }
    *p = v - 1;
    return 0;
}

__attribute__((section(".text.func_001DB558")))
void func_001DB558(Poker *self)
{
    unsigned char f;
    long m;
    float d;

    switch (self->phase) {
    case 0:
        self->timer = 0x1E;
        self->phase = self->phase + 1;
        break;
    case 1:
        f = TickDown(&self->timer);
        if (f) {
            func_001DF528(&self->ui, 2, 4);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        }
        break;
    case 2:
        f = TickDown(&self->timer);
        if (f) {
            PanelObj *ui = &self->ui;

            self->choice = 0;
            UiRecord_setDispSubs6to10(ui, 1);
            func_001DF7D0(ui, 1);
            func_001DF820(ui, 1);
            self->timer = 0x14;
            self->phase = self->phase + 1;
        }
        break;
    case 3:
        f = TickDown(&self->timer);
        if (f) {
            self->phase = self->phase + 1;
        }
        break;
    case 4:
        if ((D_007474A0[54] & 0xCC0000C000000L) != 0) {
            if (self->choice == 0) {
                self->choice = 1;
                func_001DF7D0(&self->ui, 0);
            } else {
                self->choice = 0;
                func_001DF7D0(&self->ui, 1);
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else {
            m = D_007474A0[52];
            if ((m & 0x20000000) != 0) {
                self->choice = 1;
                func_001DF7D0(&self->ui, 0);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            } else if ((m & 0x10000000) != 0) {
                PanelObj *ui;

                if (self->choice == 0) {
                    ui = &self->ui;
                    func_001DF528(ui, 2, 3);
                    self->timer = 0x1E;
                    self->phase = self->phase + 1;
                } else {
                    int g = self->bet;
                    int q;

                    ui = &self->ui;
                    self->payout = g;
                    q = g / 10;
                    self->phase = self->phase + 3;
                    self->unk302C = q;
                }
                UiRecord_setDispSubs6to10(ui, 0);
                func_001DF820(ui, 0);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
            }
        }
        break;
    case 5:
        f = TickDown(&self->timer);
        if (f) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0,
                               self->hand[0]->obj, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0,
                               self->hand[1]->obj, 0, 0, 0, 0);
            self->unk302C = 0xF;
            self->phase = self->phase + 1;
        }
        break;
    case 6:
        d = -((15.0f - (float)self->unk302C) / 15.0f);
        *self->hand[0]->obj->pos =
            d + D_005681C0[0].x;
        *self->hand[1]->obj->pos =
            d + D_005681C0[1].x;
        if (self->unk302C == 0) {
            self->phase = 0;
            self->state = 0xD;
        } else {
            self->unk302C = self->unk302C - 1;
        }
        break;
    case 7:
        if ((D_00747640 & 0x30000000) != 0 || self->unk302C == 0) {
            PanelObj *ui = &self->ui;

            cCoreSave_addGold(&D_00569B70, self->unk302C * 10, 0);
            self->bet = 0;
            func_001DEE40(ui, 0);
            func_001DF528(ui, 2, 3);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->unk302C = self->unk302C - 1;
            cCoreSave_addGold(&D_00569B70, 10, 0);
            self->bet = self->bet - 10;
            func_001DEE40(&self->ui, self->bet);
        }
        break;
    case 8:
        f = TickDown(&self->timer);
        if (f) {
            self->phase = 0;
            self->state = 0x14;
        }
        break;
    }
}
