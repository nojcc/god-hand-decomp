#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);
extern void func_00129718(void *a0, void *a1, int a2);

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"
#include "godhand/gameWork.h"















/* Phase machine on the step byte, 7 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, cCoreSave_getGameLevel, VU0_VADD_XYZ_IP, moveMotion and 5 more. */
__attribute__((section(".text.func_00236190"))) void func_00236190(cEm00 *self)
{
    char *s2 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
        case 0: {
            int p;

            self->unk1864 = 0;
            p = EM_RES(self);
            func_002A8578(self, EM_RES_REC(p, 0x518), EM_RES_REC(p, 0x51C), 0, 0.0f, 0, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->unk568 = 0x5;
                    break;
                case 2:
                    self->unk568 = 0xA;
                    break;
                case 3:
                case 4:
                    self->unk568 = 0xF;
                    break;
                case 5:
                    self->unk568 = 0x14;
                    break;
            }
            self->unk56A = 4;
            self->unk56E = 0xF;
            self->unk56C = 1;
            (self->step)++;
        }
            /* fallthrough */
        case 1:
            if (self->unk56E != 0) {
                char *q;
                int p0;

                (self->unk56E)--;
                p0 = *(int *)((char *)self + 0xF0);

                q = s2 + 0x550;
                VU0_VADD_XYZ_IP(p0, 0, q);
            }
            {
                GameWork *g = &D_007474A0;
                if ((g->padBtn & 0xF0) != 0) {
                    (self->unk568)--;
                }
                if ((g->padBtn & 0xF00000) != 0) {
                    self->unk568 -= 4;
                }
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
                return;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->seqFlags & 0x10) != 0) {
                if (self->unk568 <= 0) {
                    self->mode = 1;
                    self->step = 0;
                    self->phase = 0x1D;
                    (self->stepArg)++;
                    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
                    func_00129718(s2, self, 0x1D);
                }
                func_002DB770();
                self->unk56C = 0;
            } else {
                if (self->unk56C != 0) {
                    func_002DB770();
                }
            }
            break;
        default:
            break;
    }
}
