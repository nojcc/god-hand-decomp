/* sn-2.95.3-136 */
#include "godhand/cIDObj.h"
#include "godhand/cIDManager.h"
#include "godhand/cDvd.h"
#include "godhand/heapArena.h"
#include "godhand/gameWork.h"

/* Clear the load and state fields. */
__attribute__((section(".text.ClearFields_1614D0")))
void ClearFields_1614D0(cIDObj *self) {
    self->busy = 0;
    self->unk59 = 0;
    self->resHandle = 0;
    self->sel = 0;
    self->state = 0;
    self->step = 0;
    self->unk5C = 0;
    self->result = -1;
    self->unk5D = 0;
}

/* Read the id resource `name` once and wait for it; returns it. */
__attribute__((section(".text.func_00161500")))
void *func_00161500(cIDObj *self, char *name) {
    char path[0x40];
    if (self->resHandle == 0) {
        int id;
        cIDManager_getLocalFileName(D_003C2388, path, name, -1);
        id = cDvd_ReadAlloc(&D_00583F20, path, &self->resHandle, &D_00754230, 0, 0, 0, 0);
        self->readId = id;
        cDvd_CheckWait(&D_00583F20, id);
    }
    return self->resHandle;
}

/* Free the id heap and forget the resource. */
__attribute__((section(".text.func_00161590")))
void func_00161590(cIDObj *self) {
    func_002A94F0(&D_00754230);
    self->sel = 0;
    self->result = -1;
    self->resHandle = 0;
}

/* Save GameWork's flags5D8/flags5E0 into the object. */
__attribute__((section(".text.Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0")))
void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(cIDObj *self) {
    self->flags5D8 = D_007474A0.flags5D8;
    self->flags5E0 = D_007474A0.flags5E0;
}

/* Put the saved flags5D8/flags5E0 back into GameWork. */
__attribute__((section(".text.Obj0000_Set_D_007474A0_Fields_5D8_5E0")))
void Obj0000_Set_D_007474A0_Fields_5D8_5E0(cIDObj *self) {
    D_007474A0.flags5D8 = self->flags5D8;
    D_007474A0.flags5E0 = self->flags5E0;
}
