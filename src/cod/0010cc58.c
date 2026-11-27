/* SN ProDG ee-gcc 2.95.3 matched TU. */

#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/pl00Fn.h"
#include "godhand/globals.h"
#include "godhand/cObj.h"
__attribute__((section(".text.UpdateStatePhase2F6_10CC58")))
void UpdateStatePhase2F6_10CC58(pl00 *self) {
    int v0;
    int v1;
    switch (self->base.step) {
    case 0:
        v0 = EM_RES(&self->base);
        self->comboSlot = 0;
        self->comboSet = 0;
        func_002A8578(self, EM_RES_REC(v0, 0x220), EM_RES_REC(v0, 0x278), 3, 0.0f, 0, 0);
        self->unk15B0 = 0x10;
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        self->unk15F0 = D_003BD48C;
        v1 = self->unk15B0;
        if (v1 != 0) {
            self->unk15B0 = v1 - 1;
            InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
        }
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
    func_00123938(self, 1);
}
