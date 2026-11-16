/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

/* func_002373B0, 784 B, sn-2.95.3-136. Wave 2026-08-30 VU0P parked + nested Duff do{}while(0) before case 1 (label 0x002374E0, 0 mod 8; dispatch beq slot filled from before so no beql), case 3 store order 2F4 2F5 2F6 2F7. */
/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);
extern char D_007474A0[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_002373B0")))
void func_002373B0(cEm00 *self)
{
    char *s1 = (char *)Getplayer();
    cVec *p;
    char *q;
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        b = (int)self->pack;
        func_002A8578(self, *(int *)(b + 0x20D8) + b, *(int *)(b + 0x20DC) + b,
                      0, 0.0f, 0, 0);
        self->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: self->unk568 = 0xF; break;
        case 2: self->unk568 = 0x14; break;
        case 3: case 4: self->unk568 = 0x19; break;
        case 5: self->unk568 = 0x1E; break;
        }
        if (*(short *)(s1 + 0x54A) < 2)
            self->unk568 = 0x19;
        self->unk56A = 0x5A;
        (self->step)++;
        /* fallthrough */
    
    
    case 1:
        if (self->unk56E == 0)
            goto join;
        (self->unk56E)--;
        p = self->pos;
    
        q = s1 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (*(short *)(s1 + 0x54A) > 0) {
            if (self->unk56A != 0) {
                self->unk56A = self->unk56A - 1;
            } else {
                func_002DB770();
                {
                    char *g = D_007474A0;
                    if ((*(int *)(g + 8) & 0xF0) != 0)
                        self->unk568 = self->unk568 - 1;
                    if ((*(int *)(g + 8) & 0xF00000) != 0)
                        self->unk568 = self->unk568 - 4;
                }
            }
            if ((self->seqFlags & 0x10) != 0) {
                if (*(short *)(s1 + 0x54A) > 0 && self->unk568 <= 0) {
                    (*(unsigned char *)(s1 + 0x2F6))++;
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
