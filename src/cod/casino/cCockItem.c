/* TU: cCockItem [casino] - recovered C++ class. */
#include "godhand/heapArena.h"
#include "godhand/cIDBase.h"
#include "godhand/cDvd.h"
#include "include_asm.h"

extern void cIDManager_getLocalFileName();
extern void cIDManager_setIDData();
extern int D_003C2388;
extern char D_0041E030[];
extern int *D_003C2384;

__attribute__((section(".text.cCockItem_LoadTicket")))
void cCockItem_LoadTicket(char *a0) {
    char buf[0x40];
    char *id;
    int r;

    if (*(int *)(a0 + 0x90) != 0) {
        return;
    }
    cIDManager_getLocalFileName(D_003C2388, buf, D_0041E030, -1);
    id = a0 + 0xB0;
    r = cDvd_ReadAlloc(&D_00583F20, buf, a0 + 0x90, &D_00754220, 0, 0, 0, 0);
    *(int *)(a0 + 0x94) = r;
    cDvd_CheckWait(&D_00583F20, r);
    cIDManager_setIDData(*D_003C2384, 0x19, *(int *)(a0 + 0x90));
    cIDBase_initialize((cIDBaseObj *)id, 0x19, 0);
    cIDBase_restartAnim((cIDBaseObj *)id);
    *(char *)(id + 0x1C) = 1;
}
