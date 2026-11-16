/* TU: BlackJackId [casino] - recovered C++ class. */
#include "godhand/cIDBase.h"
#include "godhand/BlackJack.h"
#include "include_asm.h"

extern void CustomIDWork_Main(void *a0);

__attribute__((section(".text.BlackJackId_Move")))
void BlackJackId_Move(BlackJack *self) {
    CustomIDWork *q;
    int i;

    q = self->elem;
    /* `i >= 0`: retail closes this loop with `bgez` (not `bne`), so the
       counter compares against zero, not a materialised -1. The loop body
       carries a call, so ee-as omits the R5900 short-loop pad → this needs
       --call-loop-pad to reinsert the nop before the closing branch. */
    for (i = 0x2C; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }
    cIDBase_move(&self->id);
}

__attribute__((section(".text.BlackJackId_SetDefaultDisp")))
void BlackJackId_SetDefaultDisp(BlackJack *self) {
    SetFlagOnEntries7C_1D51B8(self, 0x2D, 0);
    SetFlagOnEntries7C_1D51B8(self, 0x1, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x2, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x3, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x4, 1);
    SetFlagOnEntries7C_1D51B8(self, 0xA, 1);
    SetFlagOnEntries7C_1D51B8(self, 0xC, 1);
    SetFlagOnEntries7C_1D51B8(self, 0xF, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x22, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x19, 1);
}
