/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void SetMotionStep(void *a0, float f12);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);

extern void func_00274FE8(void *a0);
extern char D_005CB000[];

#include "godhand/vu0.h"
#include "godhand/cEm00.h"

__attribute__((section(".text.func_0025C1D0")))
void func_0025C1D0(cEm00 *self)
{
    char *s1;
    float v;

    s1 = (char *)Getplayer();
    v = *(float *)(s1 + 0x5A8);
    self->speedRate = v;
    SetMotionStep(self, v);
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);

    switch (self->step) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = (int)self->pack;
        func_002A8578(self, *(int *)(p + 0xC98) + p, *(int *)(p + 0xC9C) + p,
                      0, 0.0f, 0, 0);
        self->unk16EC = 0;
        (self->step)++;
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
        int p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = (int)self->pack;
        func_002A8578(self, *(int *)(p + 0xCA0) + p, *(int *)(p + 0xCA4) + p,
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
        if (moveMotion(self) != 0) {
            cGameObjVt *vt;
            short off;
            vt = cGameObj_vt((cGameObj *)self);
            off = vt->unkA8Delta;
            vt->unkAC((char *)self + off, 8, s1, 1, 0);
            cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        self->step = *(unsigned char *)(s1 + 0x2F6);
        break;
    }
    case 4:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = (int)self->pack;
        func_002A8578(self, *(int *)(p + 0xCA8) + p, *(int *)(p + 0xCAC) + p,
                      0, 0.0f, 0, 0);
        self->timerA = 1;
        self->unk56E = 0xF;
        (self->step)++;
    }
        /* fallthrough */
    case 5:
    {
        if ((self->seqFlags & 8) == 0) {
            char *pa;
            cVec *pb;

            self->emFlags |= 0x10000;
            pa = *(char **)(s1 + 0xF0);
            pb = self->pos;
            pb->y = *(float *)(pa + 4)
                               - (self->scale.y - 1.0f) * 0.1f;
        }
        if (self->unk56E != 0) {
            char *q;
            cVec *p0;

            p0 = self->pos;
            (self->unk56E)--;
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (self->seqFlags & 1) {
            if (self->timerA != 0) {
                cGameObjVt *vt;
                short off;
                self->timerA = 0;
                vt = cGameObj_vt((cGameObj *)self);
                off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0x14, s1, 1, 0);
                cHeatSys_AddHeatGage(D_005CB000, 0, 1.0f);
            }
        }
        if (moveMotion(self) != 0) {
            if (self->hp <= 0) {
                func_0025FE30(self, 0x1000000, 0);
                self->mode = 2;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
                break;
            } else {
                func_00274FE8(self);
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    default:
        break;
    }
}
