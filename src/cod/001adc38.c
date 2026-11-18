/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(cOmBase *self);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];
extern float D_00747A14;

#define PHASE_OBJ_STATE   0x2F4         /* state byte: index into the phase table */
#define PHASE_OBJ_RATE    0x5A8         /* speed rate float */

/* One phase entry: this-adjust, method index (or negative: inline handler), table offset in the object. */
typedef struct PhaseEnt {
    short adjust;                       /* 0x00 */
    short index;                        /* 0x02 */
    short tableOff;                     /* 0x04 */
    short unk06;
} PhaseEnt;
typedef struct PhaseTable { PhaseEnt e[1]; } PhaseTable;

extern EmPhaseTable D_003BDC50;

/* Phase tick: scale the global speed rate by D_00747A14 into the object, run the handler the state byte's table entry names (from a method table found through the object, or inline), then the shared post-update steps. */
__attribute__((section(".text.EmPhaseScroll_update")))
void EmPhaseScroll_update(cOmBase *self)
{
    float rate;
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    rate = cEmManage_GetSpeedRate(D_005864F0) * D_00747A14;
    self->speedRate = rate;
    EM_PHASE_RUN(&D_003BDC50, self, self->mode);
    func_002A87E8(self, 0);
    func_001B76D8(self);
}
