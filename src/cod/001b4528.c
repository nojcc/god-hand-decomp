/* sn-2.95.3-136 */
#include "godhand/cPathMover.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cEmManage.h"
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/rand.h"

#define BLADE_CHILD     8               /* the child body that grows and shrinks */
#define BLADE_SIZE_MIN  0.2f
#define BLADE_SIZE_STEP 0.1f
#define SE_BLADE        0xAB

/* Spinning blade on a path: speed up while growing the blade child to full
 * size (its damage units switch on), wait a random time, then shrink it and
 * slow to a stop; walks the path every frame. */
__attribute__((section(".text.func_001B4528")))
void func_001B4528(PathMover *self)
{
    int frame[3];
    cOmBase *blade;
    int roll;
    int n;

    switch (self->base.phase) {
    case 0:
        self->speed = 0.0f;
        roll = Rnd();
        n = 0;
        if (roll >= 0) {
            n = roll;
        }
        if (n >= 6) {
            n = 6;
        }
        self->base.step = 2;
        self->base.phase = 1;
        self->wait = self->waitBase + (float)(n * 10);
        self->se = cSnd_SeCall_2CBA48(&D_005FEE00, 2, SE_BLADE, self, 0, 0, 0, 0);
    case 1:
        self->speed += self->accel * cEmManage_GetSpeedRate(&D_005864F0) * D_007474A0.timeScale;
        if (self->speedMax <= self->speed) {
            blade = cOmBase_childAt((cOmBase *)self, frame, BLADE_CHILD);
            blade->scale[0] += cEmManage_GetSpeedRate(&D_005864F0) * BLADE_SIZE_STEP * D_007474A0.timeScale;
            if (cOmBase_childAt((cOmBase *)self, frame, BLADE_CHILD)->scale[0] > 1.0f) {
                cOmBase_childAt((cOmBase *)self, frame, BLADE_CHILD)->scale[0] = 1.0f;
                if (self->hitA != 0) {
                    cDamageUnit_SetDamageCollActive(self->hitA, 1);
                }
                if (self->hitB != 0) {
                    cDamageUnit_SetDamageCollActive(self->hitB, 1);
                }
                self->base.phase = 2;
            }
            self->speed = self->speedMax;
        }
        break;
    case 2:
        if (self->wait <= 0.0f) {
            self->base.phase = 3;
            self->base.step = 3;
        } else {
            self->wait -= cEmManage_GetSpeedRate(&D_005864F0) * D_007474A0.timeScale;
        }
        break;
    case 3:
        cOmBase_childAt((cOmBase *)self, frame, BLADE_CHILD)->scale[0] -= BLADE_SIZE_STEP;
        if (cOmBase_childAt((cOmBase *)self, frame, BLADE_CHILD)->scale[0] < BLADE_SIZE_MIN) {
            cOmBase_childAt((cOmBase *)self, frame, BLADE_CHILD)->scale[0] = BLADE_SIZE_MIN;
            if (self->hitA != 0) {
                cDamageUnit_SetDamageCollActive(self->hitA, 0);
            }
            if (self->hitB != 0) {
                cDamageUnit_SetDamageCollActive(self->hitB, 0);
            }
        }
        self->speed -= self->decel;
        if (self->speed <= 0.0f) {
            cSnd_SeStop(&D_005FEE00, self->se);
            self->speed = 0.0f;
            self->se = 0;
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
        }
        break;
    }
    func_001B51B0(self);
}
