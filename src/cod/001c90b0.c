/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/Poker.h"
#include "godhand/PanelObj.h"
#include "godhand/BlackJack.h"
#include "godhand/cIDBase.h"

extern int ClearField5B4IfFlagUnset_1B76B0();
extern int cIDBase_release();

/* clone */



__attribute__((section(".text.func_001C90B0")))
void func_001C90B0(void *a0) {
    if (ClearField5B4IfFlagUnset_1B76B0(a0))
        func_001B76D8(a0);
}

/* clone */


__attribute__((section(".text.func_001D5780")))
void func_001D5780(BlackJack *self, int number) { CustomIDWork_SetNumber(&self->elem[0x4], number); }

/* clone */


__attribute__((section(".text.func_001D6A30")))
void func_001D6A30(BlackJack *self, int number) { CustomIDWork_SetNumber(&self->elem[0x1B], number); }

/* clone */


__attribute__((section(".text.func_001D6A50")))
void func_001D6A50(BlackJack *self, int number) { CustomIDWork_SetNumber(&self->elem[0x1D], number); }

/* clone */


__attribute__((section(".text.func_001D6BC0")))
void func_001D6BC0(BlackJack *self, int on) {
    SetFlagOnEntries7C_1D51B8(self, 0x20, on);
}

/* clone */


__attribute__((section(".text.func_001D6C70")))
void func_001D6C70(BlackJack *self, int on) {
    SetFlagOnEntries7C_1D51B8(self, 0x1F, on);
}

/* clone */


__attribute__((section(".text.func_001DD180")))
void func_001DD180(Poker *self) { cIDBase_release(&self->id); }

/* clone */


__attribute__((section(".text.func_001DD1F8")))
void func_001DD1F8(Poker *self) { cIDBase_trans(&self->id); }

/* clone */


__attribute__((section(".text.func_001DD238")))
void func_001DD238(Poker *self, int number) { CustomIDWork_SetNumber(&self->elem[0x10], number); }

/* clone */


__attribute__((section(".text.func_001DEDA8")))
void func_001DEDA8(PanelObj *self) { cIDBase_release(&self->id); }
