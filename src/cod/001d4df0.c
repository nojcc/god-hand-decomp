/* sn-2.95.3-136: func_001D4DF0, load the blackjack ID file, set up its 45 ID works and default display. */
#include "godhand/heapArena.h"
#include "godhand/cIDBase.h"
#include "godhand/cDvd.h"
#include "godhand/BlackJack.h"
#include "godhand/globals.h"
extern int D_003C2388;
extern char **D_003C2384;

extern int cIDManager_getLocalFileName(int mgr, char *buf, char *name, int lang);
extern void cIDManager_setIDData(void *mgr, int kind, int res);

__attribute__((section(".text.func_001D4DF0")))
void func_001D4DF0(BlackJack *self)
{
    char buf[0x40];
    int res;
    int r;
    int i;

    cIDManager_getLocalFileName(D_003C2388, buf, D_0042B190, -1);
    r = cDvd_ReadAlloc(&D_00583F20, buf, &res, &D_00754220, 0, 0, 0, 0);
    if (r != 0) {
        cDvd_CheckWait(&D_00583F20, r);
        cIDManager_setIDData(*D_003C2384, 0x13, res);
        cIDBase_initialize(&self->id, 0x13, 0);
        cIDBase_restartAnim(&self->id);
        for (i = 0; i < BLACKJACK_ELEM_NUM; i++)
            CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
        CustomIDWork_SetDisp(&self->elem[0x0], 0);
        CustomIDWork_SetNumber_1D5760(self, 0);
        func_001D5780(self, 0);
        func_001D6A30(self, 0);
        func_001D6A50(self, 0);
        BlackJackId_SetDefaultDisp(self);
    }
}
