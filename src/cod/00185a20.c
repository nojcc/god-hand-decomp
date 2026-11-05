/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"

extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);
extern void func_00186038(char *a0, int a1);

__attribute__((section(".text.func_00185A20")))
void func_00185A20(void *self, unsigned int arg1)
{
    cOmBase_setMeshDispFromLayer(self, 0xB, 0);
    cOmBase_setMeshDispFromLayer(self, 0xC, 0);
    cOmBase_setMeshDispFromLayer(self, 0xD, 0);
    cOmBase_setMeshDispFromLayer(self, 0xE, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 0xB, 1);
        break;
    case 1:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 0xC, 1);
        break;
    case 2:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 0xD, 1);
        break;
    case 3:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 0xE, 1);
        break;
    case 4:
        SetEffect(0x298, 0xC, self, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x112, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 0xE, 1);
        func_00186038(self, 0xC);
        func_00186038(self, 0xD);
        break;
    }
}
