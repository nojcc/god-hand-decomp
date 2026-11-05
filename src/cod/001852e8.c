/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"

extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);
extern void func_00186038(char *a0, int a1);

__attribute__((section(".text.func_001852E8")))
void func_001852E8(void *self, unsigned int arg1)
{
    cOmBase_setMeshDispFromLayer(self, 1, 0);
    cOmBase_setMeshDispFromLayer(self, 2, 0);
    cOmBase_setMeshDispFromLayer(self, 3, 0);
    cOmBase_setMeshDispFromLayer(self, 4, 0);
    cOmBase_setMeshDispFromLayer(self, 6, 0);
    cOmBase_setMeshDispFromLayer(self, 7, 0);
    cOmBase_setMeshDispFromLayer(self, 8, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 1, 1);
        cOmBase_setMeshDispFromLayer(self, 6, 1);
        break;
    case 1:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 2, 1);
        cOmBase_setMeshDispFromLayer(self, 7, 1);
        break;
    case 2:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 3, 1);
        cOmBase_setMeshDispFromLayer(self, 8, 1);
        break;
    case 3:
        SetEffect(0x298, 7, self, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x112, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 4, 1);
        cOmBase_setMeshDispFromLayer(self, 8, 1);
        func_00186038(self, 0);
        func_00186038(self, 1);
        func_00186038(self, 2);
        break;
    case 4:
        SetEffect(0x298, 8, self, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x112, self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x114, self, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(self, 4, 1);
        cOmBase_setMeshDispFromLayer(self, 8, 1);
        func_00186038(self, 3);
        func_00186038(self, 4);
        func_00186038(self, 5);
        func_00186038(self, 6);
        break;
    }
}
