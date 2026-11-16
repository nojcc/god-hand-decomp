/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/Poker.h"
#include "godhand/PanelObj.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int D_0042B2F0[];
extern long D_007474A0[];
extern long D_00747640;

typedef struct {
    int w[8];
} Blob32;

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

__attribute__((section(".text.func_001D9D28")))
void func_001D9D28(Poker *self)
{
    unsigned char f;
    long m;

    switch (self->phase) {
    case 0: {
        int buf[8];

        *(Blob32 *)buf = *(Blob32 *)D_0042B2F0;
        self->timer = 0x3C;
        self->phase = self->phase + 1;
        self->payout = buf[self->unk3048] * self->bet;
        break;
    }
    case 1:
        f = TickDown(&self->timer);
        if (f) {
            CustomIDOwner_setScoreNumber(self, self->payout);
            func_001DE5F8(self, self->unk3048, 2);
            self->timer = 0x14;
            self->phase = self->phase + 1;
        }
        break;
    case 2:
        f = TickDown(&self->timer);
        if (f) {
            self->phase = self->phase + 1;
        }
        break;
    case 3:
        self->timer = 0x1E;
        self->phase = self->phase + 1;
        /* fallthrough */
    case 4:
        f = TickDown(&self->timer);
        if (f) {
            PanelObj *ui = &self->ui;

            self->choice = 0;
            UiRecord_setDispSubs6to10(ui, 1);
            func_001DF7D0(ui, 1);
            func_001DF820(ui, 1);
            self->phase = self->phase + 1;
        }
        break;
    case 5:
        if (D_007474A0[0x1B0 / 8] & 0xCC0000C000000L) {
            if (self->choice == 0) {
                self->choice = 1;
                func_001DF7D0(&self->ui, 0);
            } else {
                self->choice = 0;
                func_001DF7D0(&self->ui, 1);
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            return;
        }
        m = D_007474A0[0x1A0 / 8];
        if (m & 0x20000000L) {
            self->choice = 1;
            func_001DF7D0(&self->ui, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            return;
        }
        if (m & 0x10000000L) {
            PanelObj *ui;

            func_001DD910(self, 1);
            ui = &self->ui;
            UiRecord_setDispSubs6to10(ui, 0);
            func_001DF7D0(ui, 0);
            func_001DF820(ui, 0);
            func_001DE5F8(self, self->unk3048, 3);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
            self->timer = 0x14;
            self->phase = self->phase + 1;
        }
        break;
    case 6:
        f = TickDown(&self->timer);
        if (f) {
            if (self->choice == 0) {
                self->phase = self->phase + 1;
            } else {
                self->phase = self->phase + 2;
            }
        }
        break;
    case 7:
        self->flags = self->flags | 4;
        self->state = 0xB;
        self->phase = 0;
        break;
    case 8:
        self->flags = self->flags & -5;
        self->unk302C = self->payout / 0xA;
        self->phase = self->phase + 1;
        /* fallthrough */
    case 9:
        if ((D_00747640 & 0x30000000L) != 0 || self->unk302C == 0) {
            cCoreSave_addGold(&D_00569B70, self->unk302C * 0xA, 0);
            self->bet = 0;
            CustomIDWork_SetNumber_1DD218(self, 0);
            cSnd_SetBgmState(&D_005FEE00, 0);
            self->phase = 0;
            self->state = 0xB;
        } else {
            self->unk302C = self->unk302C - 1;
            cCoreSave_addGold(&D_00569B70, 0xA, 0);
        }
        break;
    }
}
