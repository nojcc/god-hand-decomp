/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEmManage.h"
#include "godhand/cNode.h"
#include "godhand/espSys.h"
#include "godhand/newlibStdio.h"
#include "godhand/newlibMalloc.h"

extern void PushEsp(void *a0);
extern float D_00741DC0;
extern float D_00754C48;

__attribute__((section(".text.UpdateObjByIndexedOp_2FBE50")))
void UpdateObjByIndexedOp_2FBE50(EspAnim *self) {
    cNode *parent;
    parent = func_002B5E50((cNode *)self);
    func_002B5CF0((cNode *)self, parent);
    PushEsp(self);
}

__attribute__((section(".text.UpdateGlobalPtrWithParam_3A7CC0")))
void UpdateGlobalPtrWithParam_3A7CC0(void *p) {
    __malloc_lock(D_003FA62C);
    func_003ACA28(D_003FA62C, p);
    __malloc_unlock(D_003FA62C);
}

/* Sets the enemies' speed rate for this frame and copies it to the two
 * globals that hold it; Main puts it back to 1.0 at the end of the frame. */
__attribute__((section(".text.cEmManage_SetSpeedRate")))
void cEmManage_SetSpeedRate(cEmManage *self, float rate) {
    self->speedRate = rate;
    D_00741DC0 = rate;
    D_00754C48 = rate;
}
