/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"

extern char *Getplayer(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern char D_007474A0[];

__attribute__((section(".text.func_00237078")))
void func_00237078(cEm00 *self)
{
    char *s1 = Getplayer();
    cVec *p;
    char *q;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0: {
        int p = (int)self->pack;
        int t;

        self->unk1864 = 0;
        func_002A8578(self, *(int *)(p + 0x240C) + p, *(int *)(p + 0x2410) + p,
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
        if (*(short *)(s1 + 0x54A) < 2)
            self->unk568 = 0x3C;
        self->unk56A = 0x14;
        self->step = self->step + 1;
    }
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
        if (self->unk56A != 0) {
            (self->unk56A)--;
        } else {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if (*(int *)(g + 8) & 0xF0)
                (self->unk568)--;
            if (*(int *)(g + 8) & 0xF00000)
                self->unk568 -= 4;
        }
        if (self->seqFlags & 0x10) {
            if (self->unk568 <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = 2;
                self->step = 2;
            }
            self->unk56A = 0x3E7;
        }
        break;
    case 2: {
        int p = (int)self->pack;

        self->unk1864 = 0;
        func_002A8578(self, *(int *)(p + 0x2420) + p, *(int *)(p + 0x2424) + p,
                      0, 0.0f, 0, 0);
        self->unk56E = 0xF;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 3:
        if (self->unk56E != 0) {
            char *q;
            cVec *p0;

            (self->unk56E)--;
            q = s1 + 0x550;
            p0 = self->pos;
            VU0_VADD_XYZ_IP(p0, 0, q);
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
