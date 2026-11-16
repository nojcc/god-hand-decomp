/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/Slot1.h"

extern char D_003BD6E8[];
extern long D_00747640;

#define SLOT1_WIN_WAIT     0x78
#define SLOT1_MSG_WAIT     0x1E
#define MSG_TICKET         0x1001  /* first ticket message */
#define MSG_TICKET_FULL    0x1003  /* nine tickets message */
#define CORESAVE_F_TICKET_MSG  0x8000000  /* save flag: the first-ticket message was shown */

/* Ticket win of the first slot machine: light the selected mark and mark 5 and start BGM event 0x32; after 120 frames add a
 * casino ticket (showing the first-ticket message once and the full message from nine tickets on), then return to the
 * first state. */
__attribute__((section(".text.func_001E2240")))
void func_001E2240(Slot1 *self) {
    switch (self->phase) {
    case 0:
        self->payMode = 9;
        self->timer = SLOT1_WIN_WAIT;
        self->phase = self->phase + 1;
        break;
    case 1:
        SetEffect(1, 2, 0, 0, -1, 0xFFFFFFFFU);
        Slot2_selectMark(self, self->slotId, 1, 1);
        Slot2_setMarkLayers(self, 1, 1);
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
            if ((f & CORESAVE_F_TICKET_MSG) == 0) {
                save->flags = f | CORESAVE_F_TICKET_MSG;
                UiPanel_setMessAndShow(&self->ui, MSG_TICKET, 1);
                self->phase = self->phase + 1;
            } else {
                self->phase = 4;
            }
        }
        cCoreSave_addCasinoTicket(&D_00569B70, 1);
        *(int *)(*(char **)D_003BD6E8 + 0x1A10) =
            (short)cCoreSave_getCasinoTicketNum(&D_00569B70);
        Slot2_selectMark(self, self->slotId, 0, 0);
        Slot2_setMarkLayers(self, 0, 0);
        break;
    case 3:
        if ((D_00747640 & 0xF00000000L) != 0) {
            self->timer = SLOT1_MSG_WAIT;
            UiPanel_setMessAndShow(&self->ui, MSG_TICKET, 0);
            self->phase = self->phase + 1;
        }
        break;
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
            UiPanel_setMessAndShow(&self->ui, MSG_TICKET_FULL, 1);
            self->phase = self->phase + 1;
        } else {
            self->phase = 6;
        }
        break;
    case 5:
        if ((D_00747640 & 0xF00000000L) != 0) {
            UiPanel_setMessAndShow(&self->ui, MSG_TICKET_FULL, 0);
            self->phase = self->phase + 1;
        }
        break;
    case 6:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}
