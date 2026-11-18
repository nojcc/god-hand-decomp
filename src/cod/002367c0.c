#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern void func_00274FE8(void *a0);

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

/* The enemy's grab on the player: the enemy moves with the player's velocity while the player's
 * button presses wear down a counter set by the game level. When the counter runs out the player
 * takes step 6 and the enemy loses HP; if the grab motion ends with the player at 0 HP, the
 * player goes to mode 2. */
__attribute__((section(".text.func_002367C0"))) void func_002367C0(cEm00 *self)
{
    cGameObj *pl;

    pl = Getplayer();
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
        case 0: {
            int w = EM_RES(self);
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0x100C), EM_RES_REC(w, 0x1010), 0, 0.0f, 0, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
                default:
                case 0:
                    self->unk568 = 0x14;
                    break;
                case 1:
                    self->unk568 = 0x1E;
                    break;
                case 2:
                case 3:
                    self->unk568 = 0x28;
                    break;
                case 4:
                    self->unk568 = 0x32;
                    break;
            }
            self->unk56A = 4;
            self->unk56E = 0xF;
            self->step++;
        }
        /* fallthrough */
        case 1: {
            VU0_VADD_XYZ_IP(self->pos, 0, &pl->vel);
            self->hitFlash = 3.0f;
            if (moveMotion(self))
                self->step = 2;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_002DB770();
            if ((D_007474A0.padBtn & 0xF0) != 0)
                self->unk568 = self->unk568 - 1;
            if ((D_007474A0.padBtn & 0xF00000) != 0)
                self->unk568 = self->unk568 - 4;
            break;
        }
        case 2: {
            int w = EM_RES(self);
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0xFF4), EM_RES_REC(w, 0xFF8), 0, 0.0f, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 3: {
            if (self->unk56E != 0) {
                self->unk56E--;
                VU0_VADD_XYZ_IP(self->pos, 0, &pl->vel);
            }
            func_002DB770();
            if ((D_007474A0.padBtn & 0xF0) != 0)
                self->unk568 = self->unk568 - 1;
            if ((D_007474A0.padBtn & 0xF00000) != 0)
                self->unk568 = self->unk568 - 4;
            self->hitFlash = 3.0f;
            if (moveMotion(self)) {
                self->step = 4;
                if (pl->hp > 0) {
                    pl->step = 4;
                } else {
                    pl->phase = 0;
                    pl->mode = 2;
                    pl->step = 0;
                    pl->stepArg = 0;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (pl->hp > 0 && self->unk568 <= 0) {
                self->step = 6;
                pl->step = 6;
            }
            break;
        }
        case 4: {
            int w = EM_RES(self);
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0x1004), EM_RES_REC(w, 0x1008), 3, 0.0f, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 5:
            self->hitFlash = 3.0f;
            if (moveMotion(self)) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            int w = EM_RES(self);
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0xFFC), EM_RES_REC(w, 0x1000), 3, 0.0f, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 7:
            self->hitFlash = 3.0f;
            if (moveMotion(self)) {
                int hp = self->hp;
                int d = 0x14;
                switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    default:
                    case 0:
                        break;
                    case 4:
                        d = 0x12;
                        break;
                    case 5:
                        d = 0xF;
                        break;
                }
                hp = hp - d;
                if (hp <= 0)
                    hp = 0;
                if (hp >= self->hpMax)
                    self->hp = self->hpMax;
                else
                    self->hp = hp;
                if (hp <= 0) {
                    self->mode = 2;
                    self->phase = 1;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    func_00274FE8(self);
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}
