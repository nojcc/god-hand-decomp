/* TU: cCockItem [casino] - recovered C++ class. */
#include "godhand/heapArena.h"
#include "godhand/cCockItem.h"
#include "godhand/cIDBaseFn.h"
#include "godhand/cDvd.h"
#include "include_asm.h"
#include "godhand/globals.h"

extern void cIDManager_getLocalFileName();
extern void cIDManager_setIDData();
extern int D_003C2388;
extern int *D_003C2384;

/* Read the ticket's message pack once, hand it to the ID manager and start the ticket display. */
__attribute__((section(".text.cCockItem_LoadTicket")))
void cCockItem_LoadTicket(cCockItem *self) {
    char buf[0x40];
    cIDBaseObj *id;
    int r;

    if (self->ticket != 0) {
        return;
    }
    cIDManager_getLocalFileName(D_003C2388, buf, D_0041E030, -1);
    id = &self->ticketBase;
    r = cDvd_ReadAlloc(&D_00583F20, buf, &self->ticket, &D_00754220, 0, 0, 0, 0);
    self->readId = r;
    cDvd_CheckWait(&D_00583F20, r);
    cIDManager_setIDData(*D_003C2384, 0x19, self->ticket);
    cIDBase_initialize(id, 0x19, 0);
    cIDBase_restartAnim(id);
    id->playing = 1;
}
