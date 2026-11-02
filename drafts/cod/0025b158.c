/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/cVec.h"
#include "godhand/motion.h"
#include "godhand/rand.h"

#define GAME_LEVEL_HARD         3

/* Knocked-back phase machine: start the knock-back motion, losing 100 hit
 * points and cycling the emFlags2 hit bit; when it ends with no hit points
 * left go down, else after a random wait fly back along a random drift and
 * stand up (going back to idle when the player is close), then the recover
 * motion. */
__attribute__((section(".text.func_0025B158")))
void func_0025B158(cEm00 *self)
{
    CVEC_TEMPS;
    int motA;
    int motB;
    int flags;

    self->objFlags |= 0x10000;
    switch (self->step) {
    case 0:
        func_002A8578((int)self, EM_RES_REC(EM_RES(self), 0x2374),
                      EM_RES_REC(EM_RES(self), 0x2378), 0, 0.0f, 0, 0);
        self->unk17CC = 0.0f;
        self->unk17A8 = 0;
        self->unk5B4 = 0;
        self->hp -= 100;
        if (self->hp <= 0) {
            self->hp = 0;
        }
        self->unk17BE++;
        flags = self->emFlags2 & 0xFFFEFC7F;
        self->emFlags2 = flags;
        self->unk17BE %= 3;
        switch (self->unk17BE) {
        case 0:
            break;
        case 1:
            self->emFlags2 = flags | 0x80;
            if (self->emNo == 0x276) {
                self->emFlags2 = flags | 0x280;
            }
            break;
        case 2:
            self->emFlags2 = flags | 0x100;
            if (self->emNo == 0x276) {
                self->emFlags2 = flags | 0x300;
            }
            break;
        }
        self->unk1869 = 4;
        self->timer = fRand1_1() * 45.0f + 45.0f;
        self->step++;
        /* fallthrough */
    case 1:
        self->unk617 = 1;
        self->hitFlash = 3.0f;
        self->motionFlags |= 8;
        if (moveMotion(self) != 0 && self->hp <= 0) {
            func_00273D30(self);
            cEm00_setState(self, 2, 2, 1);
            break;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f && self->hp > 0) {
            self->step++;
        }
        break;
    case 2:
        motA = EM_RES_REC(EM_RES(self), 0x237C);
        motB = EM_RES_REC(EM_RES(self), 0x2380);
        if (cCoreSave_getGameLevel(&D_00569B70) >= GAME_LEVEL_HARD) {
            motB = EM_RES_REC(EM_RES(self), 0x2384);
        }
        func_002A8578((int)self, motA, motB, 0, 0.0f, 0, 0);
        self->unk580.x = fRand1_1() * 0.2f;
        self->unk580.y = 0.0f;
        self->unk580.z = fRand1_1() * 0.2f;
        self->hitFlash = 50.0f;
        self->step++;
        /* fallthrough */
    case 3:
        if (self->hitFlash > 0.0f) {
            self->unk617 = 1;
            CVEC_INIT_MUL_ST(ret_, &self->unk580, self->speedRate);
            CVEC_ADD_TO(*self->pos, &ret_);
        }
        if (moveMotion(self) != 0) {
            if (self->playerDist < 6.25f) {
                self->hitFlash = 5.0f;
                cEm00_setState(self, 0, 10, 0);
                break;
            }
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 4:
        func_002A8578((int)self, EM_RES_REC(EM_RES(self), 0x2388),
                      EM_RES_REC(EM_RES(self), 0x238C), 0, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 5:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}
