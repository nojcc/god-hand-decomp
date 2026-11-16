/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void SetMotionStep(void *a0, float f12);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern char D_005CB000[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_0025CCC0")))
void func_0025CCC0(cEm00 *self)
{
    char *s1;
    float v;
    float t;

    s1 = (char *)Getplayer();
    v = *(float *)(s1 + 0x5A8);
    self->speedRate = v;
    SetMotionStep(self, v);
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);

    t = self->unk770;
    if (t > 0.0f) {
        if (t < 10.0f) {
            self->unk770 = 10.0f;
        }
    }

    switch (self->step) {
    case 0:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x14C0), EM_RES_REC(p, 0x14C4),
                      0, 0.0f, 0, 0);
        self->unk16EC = 0;
        self->timerA = 1;
        (self->step)++;
        self->timerB = 1;
    }
        /* fallthrough */
    case 1:
    {
        char *q;
        char *pa;
        cVec *pb;
        cVec *p0;

        self->emFlags |= 0x10000;
        q = s1 + 0x550;
        pa = *(char **)(s1 + 0xF0);
        pb = self->pos;
        pb->y = *(float *)(pa + 4)
                           - (self->scale.y - 1.0f) * 0.1f;
        p0 = self->pos;
        VU0_VADD_XYZ_IP(p0, 0, q);
        if (moveMotion(self) != 0) {
            (self->step)++;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    case 2:
    {
        char *p;

        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x14C8), EM_RES_REC(p, 0x14CC),
                      0, 0.0f, 0, 0);
        (self->step)++;
    }
        /* fallthrough */
    case 3:
    {
        char *q;
        char *pa;
        cVec *pb;
        cVec *p0;

        self->emFlags |= 0x10000;
        q = s1 + 0x550;
        pa = *(char **)(s1 + 0xF0);
        pb = self->pos;
        pb->y = *(float *)(pa + 4)
                           - (self->scale.y - 1.0f) * 0.1f;
        p0 = self->pos;
        VU0_VADD_XYZ_IP(p0, 0, q);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        self->step = *(unsigned char *)(s1 + 0x2F6);
        break;
    }
    case 4:
    {
        char *p;

        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x14D0), EM_RES_REC(p, 0x14D4),
                      0, 0.0f, 0, 0);
        (self->step)++;
    }
        /* fallthrough */
    case 5:
    {
        char *pa;
        cVec *pb;

        self->emFlags |= 0x10000;
        pa = *(char **)(s1 + 0xF0);
        pb = self->pos;
        pb->y = *(float *)(pa + 4)
                           - (self->scale.y - 1.0f) * 0.1f;
        if (moveMotion(self) != 0) {
            self->mode = 1;
            self->phase = 0x23;
            self->step = 0;
            self->stepArg = 0;
            return;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    default:
        break;
    }

    if (self->seqFlags & 1) {
        if (self->timerA != 0) {
            cGameObjVt *vt;
            short off;
            self->timerA = 0;
            vt = cGameObj_vt((cGameObj *)self);
            off = vt->unkA8Delta;
            vt->unkAC((char *)self + off, 6, s1, 1, 0);
            cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
        }
    } else {
        self->timerA = 1;
    }

    if ((self->seqFlags & 2) && self->timerB != 0) {
        cGameObjVt *vt;
        short off;
        self->timerB = 0;
        vt = cGameObj_vt((cGameObj *)self);
        off = vt->unkA8Delta;
        vt->unkAC((char *)self + off, 0x14, s1, 1, 0);
        cHeatSys_AddHeatGage(D_005CB000, 0, 1.0f);
    } else {
        self->timerB = 1;
    }
}
