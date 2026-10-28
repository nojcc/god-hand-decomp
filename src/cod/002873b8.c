/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/cEma2.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/capVu0.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/cVec.h"

extern void cCollisionSolidManage_SetActive(int mgr, int obj, int on);

/* |x| */
static __inline__ float absf(float x)
{
    return x < 0.0f ? -x : x;
}

#define RES(off) EM_RES_REC(self->resource, off)

/* The step machine of an enemy sent by a goto: it waits for the goto bit,
 * walks to gotoPos (steps 16 to 19 hold it while the kind 4 search finds
 * another enemy there, one at x > 0 doesn't count), turns to a fixed point,
 * waits 90 frames, walks to the player and grabs it when close, follows the
 * player's velocity while the grab motion runs, then starts over at step 2.
 * The holding steps repeat a sound every 90 to 180 frames. */
__attribute__((section(".text.func_002873B8")))
void func_002873B8(cEm00 *self)
{
    cGameObj *player = Getplayer();
    cGameObj *found;
    cVec at;
    float dy;

    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    self->unk1604 = 0;
    cVec_copy3(&self->unk1590, self->pos);
    switch (self->step) {
    case 0:
        func_002A8578((int)self, RES(0x140), RES(0x144), 10, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 1:
        moveMotion(self);
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        if (self->gotoFlags & 0x80) {
            self->step++;
        }
        break;
    case 2:
        if (self->vital < self->vitalMax) {
            if (self->emNo != 0x2A7 && self->emNo != 0x2AB) {
                func_002A8578((int)self, RES(0xB8), RES(0xBC), 10, 0.0f, 0, 0);
            } else {
                func_002A8578((int)self, RES(0x40), RES(0x44), 10, 0.0f, 0, 0);
            }
        } else if (self->emNo != 0x2A7 && self->emNo != 0x2AB) {
            if (irand() & 1) {
                func_002A8578((int)self, RES(0x38), RES(0x3C), 10, 0.0f, 0, 0);
            } else {
                func_002A8578((int)self, RES(0x40), RES(0x44), 10, 0.0f, 0, 0);
            }
        } else {
            func_002A8578((int)self, RES(0x38), RES(0x3C), 10, 0.0f, 0, 0);
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5A, self, 0, 0, 0, 0);
        self->unk15BC = fRand0_1() * 90.0f + 90.0f;
        self->step++;
        /* fallthrough */
    case 3:
        func_002A74E0(self, &self->gotoPos, 1);
        func_002A7CA0((cGameObj *)self, &self->unk1570);
        cGameObj_SetTgtTurn((cGameObj *)self, &self->unk1570, 0.0981747732f);
        moveMotion(self);
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        if (capVu0MagnitudeSqXZ(&self->gotoPos, self->pos) < 1.0f) {
            dy = self->unk1590.y - self->pos->y;
            dy = absf(dy);
            if (dy < 1.0f) {
                self->step = 4;
            }
        }
        CVEC_COPY(at, self->pos);
        found = func_00291010(&D_005864F0, &at, self->rot.y, 100.0f, 3.14159274f, 0, 4, 0);
        if (found != 0 && 0.0f < found->pos->x) {
            found = 0;
        }
        if (found != 0) {
            self->step = 0x10;
        }
        break;
    case 4:
        func_002A8578((int)self, RES(0x138), RES(0x13C), 3, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 5:
        self->home.x = -9.55799961f;
        self->home.y = 1.0f;
        self->home.z = 25.2280006f;
        cGameObj_SetTgtTurn((cGameObj *)self, &self->home, 0.0981747732f);
        if (moveMotion(self) != 0) {
            self->gotoFlags &= 0xFFFFFF7F;
            self->step++;
        }
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        break;
    case 6:
        func_002A8578((int)self, RES(0x140), RES(0x144), 10, 0.0f, 0, 0);
        self->timer = 90.0f;
        self->step++;
        /* fallthrough */
    case 7:
        moveMotion(self);
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->step++;
        }
        break;
    case 8:
        if (self->vital < self->vitalMax) {
            if (self->emNo != 0x2A7 && self->emNo != 0x2AB) {
                func_002A8578((int)self, RES(0xB8), RES(0xBC), 10, 0.0f, 0, 0);
            } else {
                func_002A8578((int)self, RES(0x40), RES(0x44), 10, 0.0f, 0, 0);
            }
        } else if (self->emNo != 0x2A7 && self->emNo != 0x2AB) {
            if (irand() & 1) {
                func_002A8578((int)self, RES(0x38), RES(0x3C), 10, 0.0f, 0, 0);
            } else {
                func_002A8578((int)self, RES(0x40), RES(0x44), 10, 0.0f, 0, 0);
            }
        } else {
            func_002A8578((int)self, RES(0x38), RES(0x3C), 10, 0.0f, 0, 0);
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5A, self, 0, 0, 0, 0);
        self->step++;
        /* fallthrough */
    case 9:
        func_002A74E0(self, Getplayer()->pos, 1);
        func_002A7CA0((cGameObj *)self, &self->unk1570);
        cGameObj_SetTgtTurn((cGameObj *)self, &self->unk1570, 0.0981747732f);
        moveMotion(self);
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        if (self->playerDist < 4.0f) {
            dy = self->unk1590.y - self->pos->y;
            dy = absf(dy);
            if (dy < 0.5f && cEma2_startHitCooldown((cEma2 *)self) != 0) {
                func_00129718(player, self, 0x28);
                self->step++;
            }
        }
        break;
    case 10:
        func_002A8578((int)self, RES(0x150), RES(0x154), 3, 0.0f, 0, 0);
        self->followTimer = 15;
        self->gotoFlags |= 0x100;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x33, self, 0, 0, 0, 0);
        self->step++;
        /* fallthrough */
    case 11:
        if (self->followTimer != 0) {
            self->followTimer--;
            CVEC_ADD_TO(*self->pos, &player->vel);
        }
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        break;
    case 12:
        func_002A8578((int)self, RES(0x158), RES(0x15C), 3, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 13:
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        break;
    case 14:
        func_002A8578((int)self, RES(0xE0), RES(0xE4), 10, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 15:
        cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * 0.0490873866f);
        cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 1);
        moveMotion(self);
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        break;
    case 16:
        func_002A8578((int)self, RES(0x48), RES(0x4C), 10, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 17:
        self->hitFlash = 3.0f;
        self->gotoFlags |= 1;
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        if (self->unk15BC <= 0.0f) {
            self->unk15BC = fRand0_1() * 90.0f + 90.0f;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5A, self, 0, 0, 0, 0);
        }
        break;
    case 18:
        func_002A8578((int)self, RES(0x28), RES(0x2C), 10, 0.0f, 0, 0);
        self->unk568 = 15;
        self->step++;
        /* fallthrough */
    case 19:
        self->hitFlash = 3.0f;
        moveMotion(self);
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        CVEC_COPY(at, self->pos);
        found = func_00291010(&D_005864F0, &at, self->rot.y, 100.0f, 3.14159274f, 0, 4, 0);
        if (found != 0 && 0.0f < found->pos->x) {
            found = 0;
        }
        if (found == 0) {
            if (--self->unk568 <= 0) {
                self->step++;
            }
        } else {
            self->unk568 = 15;
        }
        if (self->unk15BC <= 0.0f) {
            self->unk15BC = fRand0_1() * 90.0f + 90.0f;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5A, self, 0, 0, 0, 0);
        }
        break;
    case 20:
        func_002A8578((int)self, RES(0x30), RES(0x34), 10, 0.0f, 0, 0);
        self->step++;
        /* fallthrough */
    case 21:
        if (moveMotion(self) != 0) {
            self->step = 2;
        }
        cModel_calcNullPart((cModel *)self);
        Add_nullspeed((cGameObj *)self);
        break;
    }
}
