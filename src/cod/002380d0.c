/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);

/* The enemy's hold on the player: the enemy moves with the player's velocity while the player's
 * button presses wear down a counter set by the game level (0x19 whenever the player's HP is
 * under 2). When the counter is out at a motion event the player takes step 2 and the enemy plays
 * its next motion, then picks its next action. */
__attribute__((section(".text.func_002380D0"))) void func_002380D0(cEm00 *self)
{
    cGameObj *pl = Getplayer();
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
        case 0:
            b = EM_RES(self);
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(b, 0x14A0), EM_RES_REC(b, 0x14A4), 0, 0.0f, 0, 0);
            self->unk56E = 0xF;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->unk568 = 0xF;
                    break;
                case 2:
                    self->unk568 = 0x14;
                    break;
                case 3:
                case 4:
                    self->unk568 = 0x19;
                    break;
                case 5:
                    self->unk568 = 0x1E;
                    break;
            }
            if (pl->hp < 2) {
                self->unk568 = 0x19;
            }
            self->unk56A = 0;
            self->step++;
            /* fallthrough */
        case 1:
            if (self->unk56E != 0) {
                self->unk56E--;
                VU0_VADD_XYZ_IP(self->pos, 0, &pl->vel);
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->unk56A > 0) {
                self->unk56A--;
            } else {
                GameWork *g;

                func_002DB770();
                g = &D_007474A0;
                if (g->padBtn & 0xF0)
                    self->unk568--;
                if (g->padBtn & 0xF00000)
                    self->unk568 -= 4;
            }
            if (self->seqFlags & 0x10) {
                if (self->unk568 <= 0) {
                    pl->step = 2;
                    self->step = 2;
                }
                self->unk56A = 0x3E7;
            }
            break;
        case 2: {
            int p = EM_RES(self);

            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(p, 0x14A8), EM_RES_REC(p, 0x14AC), 0, 0.0f, 0, 0);
            self->unk56E = 0xF;
            self->step++;
        }
        /* fallthrough */
        case 3:
            if (self->unk56E != 0) {
                self->unk56E--;
                VU0_VADD_XYZ_IP(self->pos, 0, &pl->vel);
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
