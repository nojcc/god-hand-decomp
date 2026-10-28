#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(int a0, int a1, int a2);

__attribute__((section(".text.func_00185910")))
void func_00185910(int arg0, int arg1)
{
    cOmBase_setMeshDispFromLayer(arg0, 0x24, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0x25, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(arg0, 0x24, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(arg0, 0x25, 1);
        break;
    case 4:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x115, (void *)arg0, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x113, (void *)arg0, 0, 0, 0, 0);
        SetEffect(0x298, 5, (void *)arg0, 0, -1, 0xFFFFFFFF);
        break;
    }
}
