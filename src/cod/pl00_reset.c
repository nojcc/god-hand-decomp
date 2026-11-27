/* TU: pl00_reset [player] - recovered method extracted to its own TU
   (sn-2.95.3-136 cc1 ICEs on this body inside the full pl00.c). */
#include "godhand/motion.h"
#include "godhand/cModel.h"
#include "godhand/cObj.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cEm00.h"
#include "godhand/pl00.h"
#include "godhand/player.h"

extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_00126770(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void func_001CF3A8(void *a0);
/* Player reset: clear the state bytes, restart motion 0x28/0x2C, rebuild the model
 * (move, calcParts, IK, calcWorldParts) and the weapon in hand, fix unk15F4, leave heat
 * mode and clear the catch target (unk640). */
__attribute__((section(".text.pl00_reset")))
void pl00_reset(pl00 *self)
{
    int res;

    pl00_clearMotionCam(self, 0, 0);
    func_00126770(self);
    res = (int)self->base.pack;
    self->base.mode = 0;
    self->base.phase = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
    func_002A8578(self, EM_RES_REC(res, 0x28), EM_RES_REC(res, 0x2C), 0, 0.0f, 0, 0);
    moveMotion(self);
    cModel_calcParts((cModel *)self);
    IK_InverseKinematics(self->base.ik, self);
    cModel_calcWorldParts((cModel *)self);
    if (self->sub6A8 != 0) {
        func_001CF3A8(self->sub6A8);
        cModel_calcParts((cModel *)self->sub6A8);
    }
    self->unk15F4 = (self->unk15F4 & ~0x10) | 0x20;
    cHeatSys_SetHeatMode(&D_005CB000, 0);
    self->held = 0;
}
