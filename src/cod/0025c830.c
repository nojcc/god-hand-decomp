/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"

extern void SetMotionStep(void *a0, float f12);

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.func_0025C830")))
void func_0025C830(cEm00 *self)
{
    char *s1;
    float t;

    s1 = (char *)Getplayer();
    t = *(float *)(s1 + 0x5A8);
    self->speedRate = t;
    SetMotionStep(self, t);
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
    case 0: {
        char *w;
        ReleaseField6ECByTag564_26B1E8(self);
        w = self->pack;
        func_002A8578(self, EM_RES_REC(w, 0x1820), EM_RES_REC(w, 0x1824),
                      0, 0.0f, 0, 0);
        self->unk16EC = 0;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1: {
        char *q = s1 + 0x550;
        cVec *d = self->pos;
        cVec *p;
        self->hitFlash = 3.0f;
        self->emFlags = self->emFlags | 0x10000;
        d->y = *(float *)(*(char **)(s1 + 0xF0) + 4);
        p = self->pos;
        VU0_VADD_XYZ_IP(p, 0, q);
        if (moveMotion(self))
            self->step = self->step + 1;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    case 2: {
        char *w;
        ReleaseField6ECByTag564_26B1E8(self);
        w = self->pack;
        func_002A8578(self, EM_RES_REC(w, 0x1828), EM_RES_REC(w, 0x182C),
                      0, 0.0f, 0, 0);
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 3: {
        char *q = s1 + 0x550;
        cVec *d = self->pos;
        cVec *p;
        self->hitFlash = 3.0f;
        self->emFlags = self->emFlags | 0x10000;
        d->y = *(float *)(*(char **)(s1 + 0xF0) + 4);
        p = self->pos;
        VU0_VADD_XYZ_IP(p, 0, q);
        if (moveMotion(self)) {
            cGameObjVt *vt = cGameObj_vt((cGameObj *)self);
            int off = vt->unkA8Delta;
            vt->unkAC((char *)self + off, 8, s1, 1, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        self->step = *(unsigned char *)(s1 + 0x2F6);
        break;
    }
    case 4: {
        char *w = self->pack;
        func_002A8578(self, EM_RES_REC(w, 0x1838), EM_RES_REC(w, 0x183C),
                      0, 0.0f, 0, 0);
        self->timerA = 1;
        self->unk56E = 0xF;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 5: {
        cVec *d;
        self->hitFlash = 3.0f;
        self->emFlags = self->emFlags | 0x10000;
        d = self->pos;
        d->y = *(float *)(*(char **)(s1 + 0xF0) + 4);
        if (self->unk56E != 0) {
            cVec *p;
            char *q;
            self->unk56E = self->unk56E - 1;
            p = self->pos;
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(self)) {
            if (self->hp <= 0) {
                func_0025FE30(self, 0x1000000, 0);
                self->mode = 2;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
                break;
            }
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->seqFlags & 1) {
            if (self->timerA != 0) {
                cGameObjVt *vt;
                int off;
                self->timerA = 0;
                vt = cGameObj_vt((cGameObj *)self);
                off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0x14, s1, 1, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
            }
        }
        if (self->seqFlags & 0x10) {
            if (self->hp > 0) {
                *(unsigned char *)(s1 + 0x2F6) = 6;
                self->step = 6;
            }
        }
        break;
    }
    case 6: {
        char *w = self->pack;
        func_002A8578(self, EM_RES_REC(w, 0x1830), EM_RES_REC(w, 0x1834),
                      0, 0.0f, 0, 0);
        self->unk56E = 0xF;
        self->hitFlash = 15.0f;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 7:
        if (self->unk56E != 0) {
            char *q = s1 + 0x550;
            cVec *p;
            self->unk56E = self->unk56E - 1;
            p = self->pos;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(self)) {
            if (self->hp > 0) {
                func_002705D8(self);
            } else {
                func_0025FE30(self, 0x1000000, 0);
                self->mode = 2;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
                break;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }
}
