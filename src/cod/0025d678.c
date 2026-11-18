/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void SetMotionStep(void *a0, float f);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/cObjBase.h"
#include "godhand/cEm00.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/effectPos.h"
#include "godhand/player.h"












__attribute__((section(".text.func_0025D678")))
void func_0025D678(cEm00 *self)
{
    float f[8] __attribute__((aligned(16)));
    char *s1 = (char *)Getplayer();
    float t;

    t = *(float *)(s1 + 0x5A8);
    self->speedRate = t;
    SetMotionStep(self, t);
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);

    switch (self->step) {
    case 0:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x31E4), EM_RES_REC(p, 0x31E8),
                      0, 0.0f, 0, 0);
        self->unk16EC = 0;
        self->unk56A = 0;
        (self->step)++;
    }
        /* fallthrough */
    case 1:
    {
        char *q;
        cVec *p0;

        q = s1 + 0x550;
        p0 = self->pos;
        VU0_VADD_XYZ_IP(p0, 0, q);
    }
        if (moveMotion(self) != 0) {
            (self->step)++;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x31EC), EM_RES_REC(p, 0x31F0),
                      0, 0.0f, 0, 0);
        self->timerA = 1;
        (self->step)++;
    }
        /* fallthrough */
    case 3:
    {
        char *q;
        cVec *p0;

        p0 = self->pos;
        q = s1 + 0x550;
        VU0_VADD_XYZ_IP(p0, 0, q);
    }
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->seqFlags & 1) {
            if (self->timerA != 0) {
                cGameObjVt *vt;
                short off;

                self->timerA = 0;
                vt = cGameObj_vt((cGameObj *)self);
                off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0xA, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
        } else {
            self->timerA = 1;
        }
        self->step = *(unsigned char *)(s1 + 0x2F6);
        break;
    case 4:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x31F4), EM_RES_REC(p, 0x31F8),
                      0, 0.0f, 0, 0);
        self->timerA = 1;
        self->unk56E = 0xF;
        (self->step)++;
    }
        /* fallthrough */
    case 5:
        if (self->unk56E != 0) {
            char *q;
            cVec *p0;

            (self->unk56E)--;
            p0 = self->pos;
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (self->seqFlags & 2) {
            if (self->timerA != 0) {
                cGameObjVt *vt;
                short off;

                self->timerA = 0;
                vt = cGameObj_vt((cGameObj *)self);
                off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0x1E, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
                if (self->hp < 2) {
                    self->hp = 1;
                }
            }
        }
        if (moveMotion(self) != 0) {
            if (self->hp < 2) {
                self->hp = 1;
            }
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 6:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x31FC), EM_RES_REC(p, 0x3200),
                      0, 0.0f, 0, 0);
        self->timerA = 1;
        self->unk56E = 0xF;
        (self->step)++;
    }
        /* fallthrough */
    case 7:
        if (self->unk56E != 0) {
            char *q;
            cVec *p0;

            (self->unk56E)--;
            q = s1 + 0x550;
            p0 = self->pos;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (self->seqFlags & 2) {
            if (self->timerA != 0) {
                self->timerA = 0;
                self->hp = 0;
            }
        }
        if (moveMotion(self) != 0) {
            self->hp = 0;
            self->mode = 2;
            self->phase = 2;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }

    if (self->seqFlags & 3) {
        if (self->unk56A != 0) {
            cOmBase *c = cOmBase_childAt((cOmBase *)self, (int *)f, 4);

            if (c != 0) {
                VU0_SQC2_VF0(f, 0x10);
                f[4] = fRand1_1() * 0.1f;
                f[5] = fRand1_1() * 0.1f + 0.1f;
                f[6] = fRand0_1() * 0.1f + 0.2f;
                { float *e = &f[4]; sceVu0ApplyMatrix(e, c->mtx, e); e = 0; }
                SetEffectPos(0, 0x4F, 0, (cVec *)&f[4], -1, 1.0f);
            }
        }
        self->unk56A = 0;
    } else {
        self->unk56A = 1;
    }
}
