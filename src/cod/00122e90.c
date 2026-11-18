/* sn-2.95.3-136 matched TU. */

#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cObj.h"
#include "godhand/pl00.h"

extern void func_0012C348(void *a0, int a1);
extern unsigned int irand(void);
extern float capVu0Atan2(float y, float x);
extern float Adjust_theta(float f12);
extern void func_00124EC0(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int D_00747A24;

/* Player death: play the death sounds, set state 3, start the die demo and take 1000 level points, pick a death
 * motion by the death kind (kind 0 picks one of five at random), turn away from the object at 0x678 and play the
 * motion; then count unk15B0 down and play the motion out, setting D_00747A24 bit 3 when either ends. */
__attribute__((section(".text.func_00122E90")))
void func_00122E90(pl00 *self)
{
    cVec dir;
    int motA;
    int motB;

    self->base.hitFlash = 30.0f;
    switch (self->base.step) {
    case 0:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD6, self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x123, self, 0, 0, 0, 0);
        func_0012C348(self, 3);
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -1000);
        switch (self->base.stepArg) {
        case 0:
        default:
            switch (irand() % 5) {
            case 0:
            default:
                motA = EM_RES_REC(EM_RES(&self->base), 0x158);
                motB = EM_RES_REC(EM_RES(&self->base), 0x15C);
                break;
            case 1:
                motA = EM_RES_REC(EM_RES(&self->base), 0x4FC);
                motB = EM_RES_REC(EM_RES(&self->base), 0x500);
                break;
            case 2:
                motA = EM_RES_REC(EM_RES(&self->base), 0x164);
                motB = EM_RES_REC(EM_RES(&self->base), 0x168);
                break;
            case 3:
                motA = EM_RES_REC(EM_RES(&self->base), 0x504);
                motB = EM_RES_REC(EM_RES(&self->base), 0x508);
                break;
            case 4:
                motA = EM_RES_REC(EM_RES(&self->base), 0x50C);
                motB = EM_RES_REC(EM_RES(&self->base), 0x510);
                break;
            }
            break;
        case 1:
            motA = EM_RES_REC(EM_RES(&self->base), 0x158);
            motB = EM_RES_REC(EM_RES(&self->base), 0x15C);
            break;
        case 2:
            motA = EM_RES_REC(EM_RES(&self->base), 0x4FC);
            motB = EM_RES_REC(EM_RES(&self->base), 0x500);
            break;
        case 3:
            motA = EM_RES_REC(EM_RES(&self->base), 0x514);
            motB = EM_RES_REC(EM_RES(&self->base), 0x518);
            break;
        case 4:
            motA = EM_RES_REC(EM_RES(&self->base), 0x164);
            motB = EM_RES_REC(EM_RES(&self->base), 0x168);
            break;
        case 5:
            motA = EM_RES_REC(EM_RES(&self->base), 0x504);
            motB = EM_RES_REC(EM_RES(&self->base), 0x508);
            break;
        case 6:
            motA = EM_RES_REC(EM_RES(&self->base), 0x50C);
            motB = EM_RES_REC(EM_RES(&self->base), 0x510);
            break;
        }
        if (self->unk678 != 0) {
            float th;

            VU0_LQC2(4, self->unk678 + 0x10, 0);
            VU0_SQC2(4, &dir, 0);
            th = capVu0Atan2(dir.x, dir.z) + 3.14159274f;
            /* retail stores the raw angle before the wrapped one */
            self->base.rot.y = th;
            self->base.rot.y = Adjust_theta(th);
        }
        func_002A8578(self, motA, motB, 2, 0.0f, 0, 0);
        self->unk15B0 = 0x28;
        self->base.step = self->base.step + 1;
    case 1:
        func_00124EC0(self);
        if (self->unk15B0 != 0) {
            self->unk15B0 = self->unk15B0 - 1;
        } else {
            D_00747A24 = D_00747A24 | 8;
        }
        if (moveMotion(self) != 0) {
            D_00747A24 = D_00747A24 | 8;
            self->base.step = self->base.step + 1;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}
