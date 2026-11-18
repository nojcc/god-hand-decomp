/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);

/* The enemy's hold on the player, as in func_002380D0 with this enemy's motions and counts: the
 * player's button presses wear down a counter, and when it is out at a motion event the player
 * takes step 2 and the enemy plays its next motion; at its events the enemy calls its method
 * 0xAC with 0x14 and keeps its own HP at 1 or more. */
__attribute__((section(".text.func_00237078")))
void func_00237078(cEm00 *self)
{
    cGameObj *pl = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0: {
        char *p = self->pack;
        int t;

        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(p, 0x240C), EM_RES_REC(p, 0x2410),
                      0, 0.0f, 0, 0);
        self->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            t = 0xF;
            break;
        case 2:
            t = 0x14;
            break;
        case 3:
        case 4:
            t = 0x19;
            break;
        case 5:
            t = 0x1E;
            break;
        }
        self->unk568 = t;
        if (pl->hp < 2)
            self->unk568 = 0x3C;
        self->unk56A = 0x14;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
        if (self->unk56E != 0) {
            (self->unk56E)--;
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
        if (self->unk56A != 0) {
            (self->unk56A)--;
        } else {
            GameWork *g;

            func_002DB770();
            g = &D_007474A0;
            if (g->padBtn & 0xF0)
                (self->unk568)--;
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
        char *p = self->pack;

        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(p, 0x2420), EM_RES_REC(p, 0x2424),
                      0, 0.0f, 0, 0);
        self->unk56E = 0xF;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 3:
        if (self->unk56E != 0) {
            (self->unk56E)--;
            VU0_VADD_XYZ_IP(self->pos, 0, &pl->vel);
        }
        if (moveMotion(self) != 0)
            func_002705D8(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->seqFlags & 1) {
            cGameObjVt *vt = cGameObj_vt((cGameObj *)self);

            vt->unkAC((char *)self + vt->unkA8Delta, 0x14, 0, 0, 0);
            if (self->hp <= 0)
                self->hp = 1;
        }
        break;
    default:
        break;
    }
}
