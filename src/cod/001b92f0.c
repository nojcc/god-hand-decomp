/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cEmManage.h"
#include "godhand/emPhaseTable.h"

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_001B76D8(cOmBase *self);

/* A phase object with two damage collision units, switched off every tick. */
typedef struct cOmCollPhase {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageUnit *collA;                 /* 0x600 */
    char unk604[4];
    cDamageUnit *collB;                 /* 0x608 */
} cOmCollPhase;

extern EmPhaseTable D_003BDDA8;

/* Phase tick: switch off the object's two damage collision units, store the global speed rate in the object, run the handler the state byte's table entry names (from a method table found through the object, or inline), then the shared post-update steps. */
__attribute__((section(".text.EmPhaseCollOff_update")))
void EmPhaseCollOff_update(cOmCollPhase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(&self->base) == 0) return;
    if (self->collA != 0) {
        cDamageUnit_SetDamageCollActive(self->collA, 0);
    }
    if (self->collB != 0) {
        cDamageUnit_SetDamageCollActive(self->collB, 0);
    }
    self->base.speedRate = cEmManage_GetSpeedRate(&D_005864F0);
    EM_PHASE_RUN(&D_003BDDA8, self, self->base.mode);
    func_001B76D8(&self->base);
}
