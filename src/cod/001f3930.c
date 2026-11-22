/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/gameWork.h"
#include "godhand/ColiseumEmSelect.h"
#include "godhand/globals.h"

extern void ColiseumUi_StartFade(void *a0, int a1);
extern void func_001F4068(void *a0, unsigned short a1, void *a2, int a3);
extern void func_001F4248(void *a0, int a1);


/* The ring pick step: fade in, move the cursor through the ring list with the pad, then pick a ring or back out and fade out. */
__attribute__((section(".text.func_001F3930")))
void func_001F3930(ColiseumEmSelect *self)
{
    switch (self->step) {
    case 0:
        ColiseumUi_StartFade(self, 0);
        self->step = self->step + 1;
        break;
    case 1:
        if ((D_0074748C >> 2) & 1) {
            func_001F44E0(self);
            self->step = self->step + 1;
        }
        break;
    case 2: {
        long pad = D_007474A0.rep;

        if (pad & 0x3300003000000L) {
            int i;

            if (pad & 0x1100001000000L) {
                if (--self->cursor < 0)
                    self->cursor = self->ringNum - 1;
                if (self->cursor != self->ringNum - 1) {
                    if (--self->row < 0) {
                        self->top = self->cursor;
                        self->row = 0;
                    }
                } else {
                    self->row = 6;
                    self->top = self->ringNum - 7;
                }
            } else if (pad & 0x2200002000000L) {
                if (++self->cursor >= self->ringNum)
                    self->cursor = 0;
                if (self->cursor != 0) {
                    if (++self->row >= 7) {
                        self->row = 6;
                        self->top = self->cursor - 6;
                    }
                } else {
                    self->row = 0;
                    self->top = 0;
                }
            }
            for (i = 0; i < 7; i++)
                func_001F4068(self, i, &D_003BE8B0[self->top + i], 1);
            self->ring = D_003BE8B0[self->cursor];
            func_001F4248(self, 1);
            CustomIDWork_placeByIndex(&self->idBase, self->row, 1);
            func_001F55C0(&self->idBase, self->ringNum, 7, self->top);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (D_007474A0.trg & 0x20000000) {
            ColiseumUi_StartFade(self, 1);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            self->step = self->step + 1;
        } else if (D_007474A0.trg & 0x10000000) {
            if (func_001F4530(self, self->ring.ringNo, self->ring.unk04) != 0) {
                cCoreSave_setBonus(&D_00569B70, self->cursor);
                D_00586AA4 = self->ring.unk06;
                MarkObj_setPulse(&self->idBase, 0);
                ColiseumUi_StartFade(self, 1);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                self->step = self->step + 2;
            }
        }
        break;
    }
    case 3:
        if ((D_0074748C >> 2) & 1) {
            self->step = 0;
            self->vtIndex = 1;
            self->unk0C = 0;
        }
        break;
    case 4:
        if ((D_0074748C >> 2) & 1) {
            self->step = 0;
            self->vtIndex = 2;
            self->unk0C = 0;
        }
        break;
    }
    func_001F4700(&self->idBase);
    func_001F4758(&self->idBase);
}
