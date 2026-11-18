/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cEmManage.h"
#include "godhand/cOmWeapon.h"
#include "godhand/player.h"
#include "godhand/angle.h"

extern void func_001D0408(cOmWeapon *self);
extern int irand(void);
extern int getItemNumInRoom(void);
extern int func_0012C4F0(void *a0);
extern int cOmBase_countGroupsInAction211(cOmBase *self);

/* Pick the next phase once a motion ends: by enemy number, the player's
 * distance and whether the player is down (func_0012C4F0), with a turn
 * (phase 8) when the player is behind and the idle phase otherwise. */
__attribute__((section(".text.func_002705D8")))
void func_002705D8(cEm00 *self)
{
    cGameObj *pl;

    pl = Getplayer();
    if (self->gotoEffect != 0) {
        func_001D0408(self->gotoEffect);
        self->gotoEffect = 0;
    }
    {
        int w = self->emNo;

        if (w == 0x279) {
            ReleaseField6ECByTag564_26B1E8(self);
            w = self->emNo;
        }
        if (w == 0x26A) {
            if (self->emFlags & 0x1000000) {
                self->mode = 0;
                self->phase = 0xA5;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            self->mode = 0;
            self->phase = 0xA1;
            self->step = 0;
            self->stepArg = 0;
            return;
        }
        if (0.0f < self->slideTime && (w ^ 0x26A) != 0) {
            self->mode = 0;
            self->phase = 0x13;
            self->step = 0;
            self->stepArg = 0;
            return;
        }
    }
    if (func_00274150(self) != 0 || 0.0f < self->unk1734) {
        self->mode = 0;
        self->phase = 0x89;
        self->step = 0;
        self->stepArg = 0;
        return;
    }
    if (func_00274F50(self) != 0) {
        return;
    }
    if (cEm00_startHitUnitAim(self) != 0) {
        return;
    }
    if (self->unk1864 != 0) {
        if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
            if (irand() & 1) {
                self->unk1864 = 0;
            }
        }
        if (self->unk16EC != 0) {
            self->unk1864 = 0;
        }
        if (1.5707964f < self->unk760) {
            self->unk1864 = 0;
        }
    }
    {
        int w2 = self->emNo;

        switch (w2) {
        case 0x220:
        case 0x221:
        case 0x222:
            if (self->unk1864 != 0) {
                self->unk1864 = 0;
                self->mode = 0;
                self->phase = 0x6B;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            if (self->playerDist < 9.0f) {
                if (D_005CB010 != 0 || self->speedRate < 1.0f) {
                    self->mode = 0;
                    self->phase = 0x6B;
                    self->step = 0;
                    self->stepArg = 0;
                    return;
                }
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    self->mode = 0;
                    self->phase = 0x12;
                    self->step = 0;
                    self->stepArg = 1;
                    return;
                }
            }
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
            return;
        case 0x211:
            if (self->emFlags2 & 0x20) {
                self->mode = 0;
                self->phase = 0x7F;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            if (cOmBase_countGroupsInAction211((cOmBase *)self) < 2 && (unsigned int)getItemNumInRoom() < 0xA) {
                self->mode = 0;
                self->phase = 0x84;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                if (func_0012C4F0(pl) != 0) {
                    if (func_00262AA8(self) != 0) {
                        return;
                    }
                }
                if (self->unk1864 != 0) {
                    self->unk1864 = 0;
                    self->mode = 0;
                    self->phase = 0x6C;
                    self->step = 0;
                    self->stepArg = 0;
                    return;
                }
                if (self->playerDist < 12.25f) {
                    self->mode = 0;
                    self->phase = 0x9E;
                    self->emFlags = self->emFlags | 0x800000;
                    self->step = 0;
                    self->stepArg = 0;
                    return;
                }
                self->mode = 0;
                self->phase = 0x9C;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            break;
        case 0x21F:
            if (9.0f < self->playerDist) {
                if (self->idleTimer <= 0.0f) {
                    if ((unsigned int)func_002919C0(&D_005864F0, self->actorId, 0x21F) < 2) {
                        self->mode = 0;
                        self->phase = 0x8B;
                        self->step = 0;
                        self->stepArg = 0;
                        return;
                    }
                }
            }
            break;
        }
    }
    if (self->unk1864 != 0) {
        self->unk1864 = 0;
        switch (self->emNo) {
        default:
            if (func_0012C4F0(pl) == 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            break;
        case 0x208:
        case 0x20B:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            if (self->playerDist < 9.0f &&
                ((irand() & 1) != 0 || func_0012C4F0(pl) != 0)) {
                if (func_00273960(self, 6.0f) != 0) {
                    return;
                }
            }
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
            return;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x209:
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x21F:
        case 0x224:
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
            if (func_0012C4F0(pl) != 0) {
                break;
            }
            if (self->playerDist < 9.0f && (irand() & 1) != 0) {
                self->mode = 0;
                self->phase = 0xA;
                self->step = 0;
                self->stepArg = 1;
                return;
            }
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
            return;
        case 0x220:
        case 0x221:
        case 0x222:
            if (func_0012C4F0(pl) != 0) {
                break;
            }
            self->mode = 0;
            self->phase = 0x12;
            self->step = 0;
            self->stepArg = 1;
            return;
        case 0x256:
        case 0x27E:
            if (func_0012C4F0(pl) != 0) {
                self->mode = 0;
                self->phase = 0x4B;
                self->step = 0;
                self->stepArg = 0;
                break;
            }
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
            return;
        case 0x223:
            if (func_0012C4F0(pl) == 0 && self->playerDist < 9.0f &&
                (irand() & 1) != 0) {
                self->mode = 0;
                self->phase = 0xA;
                self->step = 0;
                self->stepArg = 1;
                return;
            }
            break;
        case 0x279:
            if (self->playerDist < 25.0f && (irand() & 1) != 0) {
                self->mode = 0;
                self->phase = 9;
                self->step = 0;
                self->stepArg = 2;
                return;
            }
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
            return;
        }
    }
    self->unk1864 = 0;
    if (1.5707964f < Turn_dest(&self->pos->x, &self->unk16A0.x, self->rot.y,
                               3.1415927f)) {
        self->mode = 0;
        self->phase = 8;
        self->emFlags2 = self->emFlags2 | 1;
        self->step = 0;
        self->stepArg = 0;
        return;
    }
    self->mode = 0;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
}
