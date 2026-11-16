/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cPlCamera.h"
#include "godhand/motion.h"

extern float SetMotionStep(void *a0, float f12);
extern void cPlCamera_setCamUpdate(struct cPlCamera *self, int snap);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cEm00_startJumpSetup(void *a0);
extern float D_003BD478;
extern unsigned char D_005864F0[];
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void *Getplayer(void);
extern unsigned short D_00747A50;

/* sn-2.95.3-136 matched TU. */











__attribute__((section(".text.func_0010C930")))
void func_0010C930(pl00 *self)
{
    char *t0;
    char *v0;
    void *q;
    int p1;
    int p2;
    float v;

    if (self->base.hp <= 0) {
        self->base.hp = 1;
    }
    self->base.speedRate = 1.5f;
    SetMotionStep(self, 1.5f);
    switch (self->base.step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        if (self->unk648 >= 0xB) {
            self->unk648 = 0xA;
        }
        t0 = self->base.pack;
        q = self->sub6A0;
        p1 = EM_RES_REC(t0, 0x60);
        p2 = EM_RES_REC(t0, 0x64);
        if (q != 0) {
            func_002A8578(q, EM_RES_REC(t0, 0x374), EM_RES_REC(t0, 0x390),
                          0xA, 0.0f, 0, 0);
            v0 = self->base.pack;
            p1 = EM_RES_REC(v0, 0x354);
            p2 = EM_RES_REC(v0, 0x358);
        }
        func_002A8578(self, p1, p2, 0xA, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    case 1:
        if (self->unk61F != 0) {
            v = 3.14159274f - self->unk608 - 0.52359879f;
            if (v < 0.0f) {
                v = 0.0f;
            }
            v = v * 0.400000006f;
            if (D_003BD478 < v) {
                v = D_003BD478;
            }
            if (self->unk604 < 0.0f) {
                v = -v;
            }
            self->base.rot.y = self->base.rot.y + v;
            self->base.rot.y = Adjust_theta(self->base.rot.y);
        }
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if (func_00123938(self, 0) == 0) {
        cEm00_startJumpSetup(self);
    }
}

/* sn-2.95.3-136 matched TU. */


















#include "godhand/vu0.h"



















__attribute__((section(".text.func_00117F78")))
void func_00117F78(pl00 *self)
{
    cEm00 *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->flags15F4 = self->flags15F4 | 0x80000;

    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[0] = -0.51910001f;
        buf[1] = 0.0f;
        buf[2] = 0.0427000001f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(self, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x3D, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        if (self->base.hp <= 0)
            self->base.hp = 1;
        self->base.unk56E = 0x1E;
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (self->base.unk56E != 0 && s2 != 0) {
            cVec *d;
            cVec *e = &s2->vel;
            self->base.unk56E = self->base.unk56E - 1;
            d = self->base.pos;
            VU0_VADD_XYZ_IP(d, 0, e);
        }
        if (moveMotion(self)) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}

/* sn-2.95.3-136 matched TU. */





#include "godhand/vu0.h"

static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

/* Switch the camera to the normal zoom-out pose: take the pose in `src`, or
 * the player with the default offsets (two sets, picked by the stage state),
 * make it the current pose, restart the wait counters and place the camera. */
__attribute__((section(".text.cPlCamera_SetNormalZoomOutMode")))
void cPlCamera_SetNormalZoomOutMode(struct cPlCamera *self, cPlCamPose *src, int snap)
{
    cPlCamPose *d;
    cPlCamPose *e;
    float *m;
    int v;

    if (src != 0) {
        self->nextPose.obj = src->obj;
        cVec_copy3(&self->nextPose.ofs, &src->ofs);
        cVec_copy3(&self->nextPose.rotOfs, &src->rotOfs);
        self->nextPose.dist = src->dist;
    } else if (D_00747A50 != 0x104) {
        self->nextPose.obj = Getplayer();
        self->nextPose.ofs.x = -0.200000003f;
        self->nextPose.ofs.y = 1.05999994f;
        self->nextPose.rotOfs.x = 0.0700000003f;
        self->nextPose.dist = 4.0f;
        self->nextPose.ofs.z = 0;
        self->nextPose.rotOfs.y = 0;
        self->nextPose.rotOfs.z = 0;
    } else {
        self->nextPose.obj = Getplayer();
        self->nextPose.ofs.x = -0.200000003f;
        self->nextPose.ofs.y = 1.15999997f;
        self->nextPose.rotOfs.x = 0.0500000007f;
        self->nextPose.dist = 4.0f;
        self->nextPose.ofs.z = 0;
        self->nextPose.rotOfs.y = 0;
        self->nextPose.rotOfs.z = 0;
    }
    d = &self->pose;
    e = &self->nextPose;
    d->obj = e->obj;
    cVec_copy3(&d->ofs, &e->ofs);
    cVec_copy3(&d->rotOfs, &e->rotOfs);
    d->dist = e->dist;
    self->unk51C = 0;
    v = self->unk520;
    self->unk520 = 0;
    self->unk524 = v;
    self->flags528 = 0;
    if (snap != 0) {
        cPlCamera_setCamUpdate(self, 1);
    } else {
        cPlCamera_setCamUpdate(self, 0);
    }
    m = self->base.mtx[6];
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m, 0x30);
    VU0_SQC2(5, m, 0x20);
    VU0_SQC2(6, m, 0x10);
    VU0_SQC2(7, m, 0x0);
}
