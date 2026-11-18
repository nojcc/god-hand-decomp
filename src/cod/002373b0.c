/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"
#include "godhand/gameWork.h"

/* Held step with the solid off: play the blob's 0x20D8 motion pair, carried by
 * the player's velocity for its first unk56E frames, while face-button presses
 * count unk568 down; once it runs out on motion flag 0x10 it and the player
 * both step on, and step 3 ends in method 0xAC (0x32) and phase 0x15. */
__attribute__((section(".text.func_002373B0")))
void func_002373B0(cEm00 *self)
{
    cGameObj *pl = Getplayer();
    cVec *p;
    cVec *q;
    char *b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        b = self->pack;
        func_002A8578(self, EM_RES_REC(b, 0x20D8), EM_RES_REC(b, 0x20DC),
                      0, 0.0f, 0, 0);
        self->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: self->unk568 = 0xF; break;
        case 2: self->unk568 = 0x14; break;
        case 3: case 4: self->unk568 = 0x19; break;
        case 5: self->unk568 = 0x1E; break;
        }
        if (pl->hp < 2)
            self->unk568 = 0x19;
        self->unk56A = 0x5A;
        (self->step)++;
        /* fallthrough */
    
    
    case 1:
        if (self->unk56E != 0) {
            (self->unk56E)--;
            p = self->pos;
            q = &pl->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (pl->hp > 0) {
            if (self->unk56A != 0) {
                self->unk56A = self->unk56A - 1;
            } else {
                func_002DB770();
                if ((D_007474A0.padBtn & 0xF0) != 0)
                    self->unk568 = self->unk568 - 1;
                if ((D_007474A0.padBtn & 0xF00000) != 0)
                    self->unk568 = self->unk568 - 4;
            }
            if ((self->seqFlags & 0x10) != 0) {
                if (pl->hp > 0 && self->unk568 <= 0) {
                    (pl->step)++;
                    (self->step)++;
                }
                self->unk56A = 0x3E7;
            }
        }
        break;
    case 2:
    {
        int k = 3;
        self->step = k;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->seqFlags & 0x1) != 0) {
            cGameObjVt *vt = cGameObj_vt((cGameObj *)self);

            vt->unkAC((char *)self + vt->unkA8Delta, 0x32, 0, 0, 0);
            if (self->hp <= 0)
                self->hp = 1;
            self->mode = 1;
            self->phase = 0x15;
            self->step = 0;
            self->stepArg = 0;
        }
        break;
    default:
        break;
    }
}
