#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* Phase machine on the step byte, 6 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion, cObjBase_addNullSpeed_Rotation and 2
 * more. */
__attribute__((section(".text.func_0025A920"))) void func_0025A920(cEm00 *self)
{

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
        case 0: {
            int b = EM_RES(self);

            func_002A8578(self, EM_RES_REC(b, 0x1084), EM_RES_REC(b, 0x1088), 3, 0.0f, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            *(unsigned char *)((char *)self + 0x1866) = *(unsigned char *)((char *)self + 0x1866) + 1;
            self->step = self->step + 1;
        }
        case 1:
            if (moveMotion(self) != 0) {
                self->step = self->step + 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            int b = EM_RES(self);

            func_002A8578(self, EM_RES_REC(b, 0x107C), EM_RES_REC(b, 0x1080), 3, 0.0f, 0, 0);
            self->timer = 150.0f;
            self->step = self->step + 1;
        }
        case 3:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->timer = self->timer - self->speedRate;
            if (self->timer <= 0.0f) {
                self->step = self->step + 1;
            }
            break;
        case 4: {
            int b = EM_RES(self);

            func_002A8578(self, EM_RES_REC(b, 0x1094), EM_RES_REC(b, 0x1098), 3, 0.0f, 0, 0);
            self->hitFlash = 5.0f;
            self->step = self->step + 1;
        }
        case 5:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    self->seqFlags = self->seqFlags | 0x400;
}
