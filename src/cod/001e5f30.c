/* sn-2.95.3-136 matched TU. */
#include "godhand/gameWork.h"
#include "godhand/Slot2.h"
#include "godhand/cObjBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/DispMgr.h"

extern void func_001E6ED8(void *a0, int a1, int a2);
extern void func_001E6D48(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */













#define GAMEWORK_ANYBTN 0xF00000000L
#define SLOT2_CASINO_FLAG 0x8000000
/* Slot2 ticket exchange screen: pay the player a casino ticket, then show the
 * result and wait for a button before returning to the title state. */
__attribute__((section(".text.Slot2_PayoutTicket")))
void Slot2_PayoutTicket(Slot2 *self) {
    switch (self->phase) {
    case 0:
        self->timer = 0x78;
        self->phase = self->phase + 1;
        break;
    case 1:
        SetEffect(1, 2, 0, 0, -1, 0xFFFFFFFFU);
        func_001E6ED8(self, 1, 1);
        func_001E6D48(self, 1, 1);
        cSnd_BgmEventStart(&D_005FEE00, 0x32, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        {
            int done;
            int t = self->timer;
            if (t != 0) {
                self->timer = t - 1;
                done = 0;
            } else {
                done = 1;
            }
            if ((unsigned char)done == 0) break;
        }
        {
            cCoreSaveData *save = D_00569B70.data;
            int f = save->flags;
            if ((f & SLOT2_CASINO_FLAG) == 0) {
                GameWork *g = &D_007474A0;
                save->flags = f | SLOT2_CASINO_FLAG;
                if (g->language == 0 ||
                    g->room == 5) {
                    UiPanel_setMessAndShow(&self->layer, 0x1001, 1);
                } else if (g->room == 6) {
                    UiPanel_setMessAndShow(&self->layer, 0x1001, 1);
                }
                self->phase = self->phase + 1;
            } else {
                self->phase = 4;
            }
        }
        cCoreSave_addCasinoTicket(&D_00569B70, 1);
        Cockpit->item.ticketSeed =
            (short)cCoreSave_getCasinoTicketNum(&D_00569B70);
        func_001E6ED8(self, 0, 0);
        func_001E6D48(self, 0, 0);
        break;
    case 3: {
        GameWork *g = &D_007474A0;
        if ((g->trg & GAMEWORK_ANYBTN) != 0) {
            self->timer = 0x1E;
            if (g->language == 0 ||
                g->room == 5) {
                UiPanel_setMessAndShow(&self->layer, 0x1001, 0);
            } else if (g->room == 6) {
                UiPanel_setMessAndShow(&self->layer, 0x1001, 0);
            }
            self->phase = self->phase + 1;
        }
        break;
    }
    case 4:
        if (cCoreSave_getCasinoTicketNum(&D_00569B70) >= 9) {
            {
                int done;
                int t = self->timer;
                if (t != 0) {
                    self->timer = t - 1;
                    done = 0;
                } else {
                    done = 1;
                }
                if ((unsigned char)done == 0) break;
            }
            {
            GameWork *g = &D_007474A0;
            if (g->language == 0 ||
                g->room == 5) {
                UiPanel_setMessAndShow(&self->layer, 0x1002, 1);
            } else if (g->room == 6) {
                UiPanel_setMessAndShow(&self->layer, 0x1003, 1);
            }
            }
            self->phase = self->phase + 1;
        } else {
            self->phase = 6;
        }
        break;
    case 5: {
        GameWork *g = &D_007474A0;
        if ((g->trg & GAMEWORK_ANYBTN) != 0) {
            if (g->language == 0 ||
                g->room == 5) {
                UiPanel_setMessAndShow(&self->layer, 0x1002, 0);
            } else if (g->room == 6) {
                UiPanel_setMessAndShow(&self->layer, 0x1003, 0);
            }
            self->phase = self->phase + 1;
        }
        break;
    }
    case 6:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}
