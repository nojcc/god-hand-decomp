/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

extern void *Getplayer(void);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);
extern char D_007474A0[];

/* sn-2.95.3-136 matched TU. */














#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_00239240")))
void func_00239240(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    switch (self->step) {
    case 0:
    {
        int p;

        self->unk1864 = 0;
        p = (int)self->pack;
        func_002A8578(self, *(int *)(p + 0x3BD8) + p, *(int *)(p + 0x3BDC) + p,
                      0, 0.0f, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: self->unk568 = 0xF; break;
        case 2: self->unk568 = 0x14; break;
        case 3: case 4: self->unk568 = 0x19; break;
        case 5: self->unk568 = 0x1E; break;
        }
        self->unk56A = 0x1E;
        self->unk56E = 0xF;
        (self->step)++;
    }
        /* fallthrough */
    case 1:
        cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
        if (self->unk56E != 0) {
            char *q;
            cVec *p0;

            (self->unk56E)--;
            p0 = self->pos;
             
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p0, 0, q);
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
            self->unk56A = self->unk56A - 1;
            func_002DB770();
            {
                char *g = D_007474A0;
                if ((*(int *)(g + 8) & 0xF0) != 0)
                    self->unk568 = self->unk568 - 1;
                if ((*(int *)(g + 8) & 0xF00000) != 0)
                    self->unk568 = self->unk568 - 4;
            }
        } else if (self->unk568 <= 0) {
            int k = 2;

            do {
                self->step = k;
                *(unsigned char *)(s1 + 0x2F6) = k;
            } while (0);
        }
        break;
    case 2:
    {
        int p;
        int one = 1;

        p = (int)self->pack;
        self->unk1864 = 0;
        func_002A8578(self, *(int *)(p + 0x3BE0) + p, *(int *)(p + 0x3BE4) + p,
                      3, 0.0f, 0, 0);
        self->timerA = one;
        self->hitFlash = 15.0f;
        self->unk568 = 0x28;
        (self->step)++;
    }
        /* fallthrough */
    case 3:
        if (self->unk568 != 0) {
            self->unk568 = self->unk568 - 1;
            cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
        }
        if (moveMotion(self) != 0) {
            func_002705D8(self);
            break;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->seqFlags & 0x1) != 0) {
            if (self->timerA != 0) {
                cGameObjVt *vt = cGameObj_vt((cGameObj *)self);

                vt->unkAC((char *)self + vt->unkA8Delta, 0xA, s1, 1, 0);
                if (self->hp <= 0)
                    self->hp = 1;
            }
        }
        break;
    default:
        break;
    }
}
