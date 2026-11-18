/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* Play the enemy's motion while it moves with the player's velocity for its first 15 frames, then
 * set mode 0, phase 0x6C. */
__attribute__((section(".text.func_00239698"))) void func_00239698(cEm00 *self)
{
    cGameObj *pl = Getplayer();
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x1484), EM_RES_REC(b, 0x1488), 0, 0.0f, 0, 0);
            self->unk56E = 0xF;
            self->step++;
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
            break;
    }
}

/* As func_00239698 with another motion, keeping objFlags bit 0x40000 set while it plays. */
__attribute__((section(".text.func_00236C60"))) void func_00236C60(cEm00 *self)
{
    cGameObj *pl = Getplayer();
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x1D98), EM_RES_REC(b, 0x1D9C), 0, 0.0f, 0, 0);
            self->unk56E = 0xF;
            self->step++;
        case 1:
            self->objFlags = self->objFlags | 0x40000;
            if (self->unk56E != 0) {
                self->unk56E--;
                VU0_VADD_XYZ_IP(self->pos, 0, &pl->vel);
            }
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
