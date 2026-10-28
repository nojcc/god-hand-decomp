/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"
#include "godhand/motion.h"
#include "godhand/rand.h"

#define EMFLAG_GUARD            0x8000
#define EMFLAG2_IN_SIGHT        0x08000000
#define EMMOVE_HIT_FRAME        0x1
#define EM_PHASE_TAUNT          0x6B

/* Ends the guard: half the time taunt (phase 0x6B), else go back to idle. */
static inline void Em_leaveGuard(cEm00 *self)
{
    if (irand() & 1) {
        self->mode = 0;
        self->phase = EM_PHASE_TAUNT;
        self->step = 0;
        self->stepArg = 0;
    } else {
        func_002705D8(self);
    }
}

/* Guard phase machine: raise the guard, hold it while nothing is close, and
 * drop it when the player or another enemy comes near, the player is in
 * sight close by, or the enemy is knocked back; on the hit frame of the
 * motion, damage the cEma2 standing close. */
__attribute__((section(".text.func_0023F028")))
void func_0023F028(cEm00 *self)
{
    int motA;
    int motB;
    unsigned short sel;
    float start;

    D_005864F0.unk540 = 0xA;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        switch (self->emNo) {
        default:
            motA = EM_RES_REC(self->resource, 0x41C);
            motB = EM_RES_REC(self->resource, 0x420);
            self->unk568 = 0;
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x252:
        case 0x25A:
            motA = EM_RES_REC(self->resource, 0x1428);
            motB = EM_RES_REC(self->resource, 0x142C);
            self->unk568 = 1;
            break;
        }
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch ((unsigned int)self->unk17D0 % 3) {
        case 0:
        default:
            start = 0.0f;
            break;
        case 1:
            start = 20.0f;
            break;
        case 2:
            start = 60.0f;
            break;
        }
        if (self->unk568 != 0) {
            start = 0.0f;
        }
        func_002A8578((int)self, motA, motB, 0xA, start, sel, 0);
        self->timerA = 1;
        self->emFlags &= ~EMFLAG_GUARD;
        self->step++;
        /* fallthrough */
    case 1:
        if (moveMotion(self) != 0) {
            self->timerA = 1;
            if (cEmManage_findEma2Near(&D_005864F0, self->pos, 4.0f) == 0) {
                cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
                cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
                self->mode = 0;
                self->phase = 3;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->stepArg == 0) {
            if (self->playerDist < 64.0f && (D_007474A0.frame & 7) == (self->unk17D0 & 7)) {
                self->emFlags2 &= ~EMFLAG2_IN_SIGHT;
                func_002A74E0(self, Getplayer()->pos, 1);
                if (func_002A7CA0((cGameObj *)self, &self->unk16A0) != 0) {
                    self->emFlags2 |= EMFLAG2_IN_SIGHT;
                }
                if (self->unk510 < 8.0f) {
                    self->emFlags &= ~EMFLAG_GUARD;
                    Em_leaveGuard(self);
                    break;
                }
            }
            if (self->playerDist < 9.0f) {
                self->emFlags &= ~EMFLAG_GUARD;
                if (self->unk568 != 0) {
                    self->step = 2;
                } else {
                    Em_leaveGuard(self);
                    break;
                }
            }
            if ((D_007474A0.frame & 7) == (self->unk17D0 & 7)) {
                if (cEmManage_ckEnemyActiveNear(&D_005864F0, self->pos, 4.0f) != 0) {
                    self->emFlags &= ~EMFLAG_GUARD;
                    if (self->unk568 != 0) {
                        self->step = 2;
                    } else {
                        Em_leaveGuard(self);
                        break;
                    }
                }
                if (cEmManage_ckEmNear(&D_005864F0, self->pos, (cEmActor *)self, 3.0f) != 0) {
                    self->emFlags &= ~EMFLAG_GUARD;
                    if (self->unk568 != 0) {
                        self->step = 2;
                    } else {
                        Em_leaveGuard(self);
                        break;
                    }
                }
            }
        }
        if (self->slideTime > 0.0f) {
            self->emFlags &= ~EMFLAG_GUARD;
            if (self->unk568 != 0) {
                self->step = 2;
            } else {
                func_002705D8(self);
                break;
            }
        }
        if (self->unk16EC > 0) {
            self->emFlags &= ~EMFLAG_GUARD;
            if (self->unk568 != 0) {
                self->step = 2;
            } else {
                func_002705D8(self);
                break;
            }
        }
        break;
    case 2:
        self->unk1864 = 0;
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x1430), EM_RES_REC(self->resource, 0x1434), 0xA, 0.0f, 0, 0);
        self->timerA = 1;
        self->emFlags &= ~EMFLAG_GUARD;
        self->step++;
        /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            self->emFlags &= ~EMFLAG_GUARD;
            if (self->unk16EC > 0 || (irand() & 1)) {
                func_002705D8(self);
            } else {
                self->mode = 0;
                self->phase = EM_PHASE_TAUNT;
                self->step = 0;
                self->stepArg = 0;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    if (self->moveFlags & EMMOVE_HIT_FRAME) {
        if (self->timerA != 0) {
            self->timerA = 0;
            cEmManage_damageEma2Near(&D_005864F0, self->pos);
        }
    } else {
        self->timerA = 1;
    }
}
