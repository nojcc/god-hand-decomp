/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/Slot1.h"
#include "godhand/gameWork.h"

/* D_007474A0.rep (pad repeat bits) addressed off D_00747A2C, as retail does: the typed field loads another base. */
#define GAMESYS_PAD_REP  (*(long *)((char *)&D_00747A2C - (0x58C - 0x1B0)))
#define GAMESYS_F_DEBUG    0x200             /* D_00747A2C.unk00: the debug gold key works */
#define KEY_DEBUG_GOLD     0x33000000000L
#define KEY_BET_UP         0x400000000L
#define KEY_BET_DOWN       0x200000000L      /* leaves the machine at bet level 0 */
#define KEY_SPIN           0x2200802000000L
#define KEY_HELP           0x10000000000L
#define KEY_CLOSE          0x33F00000000L
#define SE_BET_UP          0x15F
#define SE_BET_DOWN        0x161
#define SE_HELP            0x15E
#define DEBUG_GOLD         1000
#define SLOT1_STATE_SPIN   1
#define SLOT1_STATE_LEAVE  4

/* Bet screen of the first slot machine: step 0 shows the prizes and resets the marks, the layers and the reels;
 * step 1 waits for the reels to stop, then raises or lowers the bet, spins, leaves (cancel at bet 0) or opens the
 * help panel; steps 2 to 4 open the help panel, wait for a key and close it again. */
__attribute__((section(".text.func_001E0310")))
void func_001E0310(Slot1 *self)
{
    long v;
    int done;

    switch (self->step) {
    case 0: {
        SlotUi *ui = &self->ui;
        Slot1Reel *r0;
        Slot1Reel *r1;
        Slot1Reel *r2;

        func_001E7848(ui, self->prize[0]);
        func_001E7868(ui, self->prize[1]);
        func_001E7888(ui, self->prize[2]);
        func_001E78A8(ui, self->prize[3]);
        func_001E78C8(ui, self->prize[4]);
        func_001E78E8(ui, self->prize[5]);
        self->betLv = 0;
        MarkPanel_setMark(self, 0, 0, 0);
        MarkPanel_setMark(self, 1, 0, 0);
        MarkPanel_setMark(self, 2, 0, 0);
        Slot2_selectMark(self, 0, 0, 0);
        Slot2_selectMark(self, 1, 0, 0);
        Slot2_selectMark(self, 2, 0, 0);
        Slot2_selectMark(self, 3, 0, 0);
        Slot2_selectMark(self, 4, 0, 0);
        Slot2_showLayersForMode(self);
        func_001E3D78(self, 0, 0);
        func_001E3E40(self, 0, 0, 0);
        func_001E3E40(self, 1, 0, 0);
        func_001E3E40(self, 2, 0, 0);
        func_001E3E40(self, 3, 0, 0);
        func_001E3E40(self, 4, 0, 0);
        MarkObj_setMarkFlag(self, 0, 0);
        MarkObj_setMarkFlag(self, 1, 0);
        r0 = &self->reel[0];
        r1 = &self->reel[1];
        r2 = &self->reel[2];
        r0->state = 0;
        r0->step = 0;
        r0->phase = 0;
        r1->state = 0;
        r1->step = 0;
        r1->phase = 0;
        r2->state = 0;
        r2->step = 0;
        r2->phase = 0;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
        if (D_00747A2C.unk00 & GAMESYS_F_DEBUG) {
            if (GAMESYS_PAD_REP & KEY_DEBUG_GOLD) {
                cCoreSave_addGold(&D_00569B70, DEBUG_GOLD, 0);
            }
        }
        v = self->reel[0].doneFlag;
        if ((v & 1) == 0) {
            return;
        }
        v = self->reel[1].doneFlag;
        if ((v & 1) == 0) {
            return;
        }
        v = self->reel[2].doneFlag;
        if ((v & 1) == 0) {
            return;
        }
        if (self->betLv == 0) {
            if (D_007474A0.trg & KEY_BET_DOWN) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_BET_DOWN, -1, -1, 0, 0);
                self->state = SLOT1_STATE_LEAVE;
                self->step = 0;
                self->phase = 0;
                return;
            }
        }
        {
            long f = D_007474A0.trg;

            if (f & KEY_BET_UP) {
                if (self->betLv >= SLOT1_BET_MAX) {
                    return;
                }
                if (cCoreSave_getGold(&D_00569B70) < self->betCost) {
                    return;
                }
                self->betLv += 1;
                cCoreSave_subGold(&D_00569B70, self->betCost);
                Slot2_showLayersForMode(self);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_BET_UP, -1, -1, 0, 0);
                return;
            }
            if (f & KEY_BET_DOWN) {
                if (self->betLv == 0) {
                    return;
                }
                self->betLv -= 1;
                cCoreSave_addGold(&D_00569B70, self->betCost, 0);
                Slot2_showLayersForMode(self);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_BET_DOWN, -1, -1, 0, 0);
                return;
            }
            if (self->betLv != 0 && (f & KEY_SPIN)) {
                self->state = SLOT1_STATE_SPIN;
                self->step = 0;
                self->phase = 0;
                return;
            }
        }
        if ((D_007474A0.trg & KEY_HELP) == 0) {
            return;
        }
        CustomIDOwner_setColorMode(&self->ui, 1);
        self->timer = 0xF;
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_HELP, -1, -1, 0, 0);
        self->step = self->step + 1;
        break;
    case 2:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            SetUiIdWorkDispRange(&self->ui, 1);
            self->timer = 0xA;
            self->step = self->step + 1;
        }
        break;
    case 3:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            if (D_007474A0.trg & KEY_CLOSE) {
                SlotUi *ui = &self->ui;
                SetUiIdWorkDispRange(ui, 0);
                CustomIDOwner_setColorMode(ui, 2);
                self->timer = 0xA;
                self->step = self->step + 1;
            }
        }
        break;
    case 4:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            self->step = 1;
        }
        break;
    }
}
