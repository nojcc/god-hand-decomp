/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"

extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);

__attribute__((section(".text.func_00185910")))
void func_00185910(void *self, int arg1)
{
    cOmBase_setMeshDispFromLayer(self, 0x24, 0);
    cOmBase_setMeshDispFromLayer(self, 0x25, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 0x24, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 0x25, 1);
        break;
    case 4:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x115, self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x113, self, 0, 0, 0, 0);
        SetEffect(0x298, 5, self, 0, -1, 0xFFFFFFFF);
        break;
    }
}
