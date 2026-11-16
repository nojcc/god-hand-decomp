/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern int D_00747A24;
extern char D_005864F0[];
extern void *Getplayer(void);
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
extern void cHeatSys_AddHeatGage(void *a0, int a1, float a2);
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);
extern int irand(void);
extern void func_00129718(void *a0, void *a1, int a2);
extern char D_005CB000[];

/* sn-2.95.3-136 matched TU. */






















#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

__attribute__((section(".text.func_00121E88")))
void func_00121E88(pl00 *self)
{
    cEm00 *s0;

    self->base.hitFlash = 5.0f;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    self->base.objFlags |= 0x10000;
    switch (self->base.step) {
    case 0:
    {
        float buf[4];

        buf[0] = -0.416f;
        buf[1] = 0.0f;
        buf[2] = -0.4255f;
        buf[3] = 1.0f;
        func_001299F0(self, s0, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s0, 0x32, 0.0f, 0.0f);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->unk15B0 = 1;
        self->base.unk56E = 0xF;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        if (self->base.unk56E != 0 && s0 != 0) {
            cVec *p;
            cVec *q;

            (self->base.unk56E)--;
            p = self->base.pos;
             
            q = &s0->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp > 0) {
                pl00_clearMotionCam(self, 0, 0);
                self->base.mode = 1;
                self->base.phase = 4;
                self->base.step = 0;
                self->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) != 0
            && self->unk15B0 != 0) {
            cCoreSave *s2 = &D_00569B70;

            self->unk15B0 = 0;
            cCoreSave_addGameLevelPoint(s2, -0x140);
            if (s0 != 0)
                func_0012C0F8(self, (int)(s0->unk76C * 30.0f));
            if (self->base.hp <= 0) {
                cSnd *g = &D_005FEE00;

                self->base.hp = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, self, 0, 0, 0, 0);
                cSnd_DieDemoStart(g);
                cCoreSave_addGameLevelPoint(s2, -0x3E8);
                self->base.motionFlags |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
            }
            func_0012C348(self, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */






















#include "godhand/vu0.h"

__attribute__((section(".text.func_0011C348")))
void func_0011C348(pl00 *self)
{
    cEm00 *s0;

    self->base.hitFlash = 5.0f;
    self->base.objFlags |= 0x10000;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0:
    {
        float buf[4];
        float z;

        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.5068f;
        buf[2] = 0.1395f;
        buf[3] = 1.0f;
        func_001299F0(self, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 6, z, z);
        self->unk15B0 = 1;
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->base.unk56E = 0xF;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        if (self->base.unk56E != 0 && s0 != 0) {
            cVec *p;
            cVec *q;

            (self->base.unk56E)--;
            p = self->base.pos;
             
            q = &s0->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp > 0) {
                pl00_clearMotionCam(self, 0, 0);
                self->base.mode = 1;
                self->base.phase = 4;
                self->base.step = 0;
                self->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) != 0
            && self->unk15B0 != 0) {
            self->unk15B0 = 0;
            if (s0->emNo != 0x23B) {
                if (s0 != 0)
                    func_0012C0F8(self, (int)(s0->unk76C * 50.0f));
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
            }
            if (self->base.hp <= 0) {
                cSnd *g = &D_005FEE00;

                self->base.hp = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, self, 0, 0, 0, 0);
                cSnd_DieDemoStart(g);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                self->base.motionFlags |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
            }
            func_0012C348(self, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

















#include "godhand/vu0.h"

__attribute__((section(".text.func_0025BCC0")))
void func_0025BCC0(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0:
    {
        cGameObjVt *vt;
        short saved;
        int p;

        ReleaseField6ECByTag564_26B1E8(self);
        vt = cGameObj_vt((cGameObj *)self);
        saved = self->hp;
        vt->unkAC((char *)self + vt->unkA8Delta, 0x32, s1, 1, 0);
        if (self->hp <= 0) {
            p = (int)self->pack;
            func_002A8578(self, *(int *)(p + 0x530) + p, *(int *)(p + 0x534) + p,
                          0, 0.0f, 0, 0);
            self->unk568 = 1;
        } else {
            p = (int)self->pack;
            func_002A8578(self, *(int *)(p + 0x528) + p, *(int *)(p + 0x52C) + p,
                          0, 0.0f, 0, 0);
            self->unk568 = 0;
        }
        self->hp = saved;
        self->timerA = 0x2A;
        self->timerB = 1;
        self->unk56E = 0x1E;
        self->unk56A = 0xF;
        (self->step)++;
        self->unk16EC = 0;
    }
        /* fallthrough */
    case 1:
        if ((self->seqFlags & 8) == 0) {
            self->emFlags |= 0x10000;
            self->pos->y =
                *(float *)(*(char **)(s1 + 0xF0) + 4)
                - (self->scale.y - 1.0f) * 0.1f;
        }
        if (self->unk56E != 0) {
            cVec *p;
            char *q;

            (self->unk56E)--;
            p = self->pos;
             
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if ((self->seqFlags & 2) != 0
            && self->timerB != 0) {
            cGameObjVt *vt;

            vt = cGameObj_vt((cGameObj *)self);
            self->timerB = 0;
            vt->unkAC((char *)self + vt->unkA8Delta, 0x32, s1, 1, 0);
            if (self->unk568 != 0)
                self->hp = 0;
            cHeatSys_AddHeatGage(D_005CB000, 0, 10.0f);
        }
        if (moveMotion(self) != 0) {
            if (self->hp <= 0) {
                if ((self->flags1644 & 0x800000) != 0) {
                    self->mode = 2;
                    self->phase = 3;
                    self->step = 0;
                    self->stepArg = 0;
                    return;
                } else {
                    func_0025FE30(self, 0x1000000, 0);
                    self->mode = 2;
                    self->phase = 2;
                    self->step = 0;
                    self->stepArg = 0;
                }
            } else {
                func_00274FE8(self);
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->unk56A != 0) {
            self->unk56A = self->unk56A - 1;
        } else {
            self->unk56A = 0x3E7;
            if (self->unk186B >= 5
                && self->stepArg == 1
                && (irand() & 1) != 0) {
                unsigned char t = self->stepArg;

                self->mode = 0;
                self->step = 0;
                self->phase = 0x4D;
                self->stepArg = t;
                func_00129718(s1, self, 2);
            }
        }
        break;
    default:
        break;
    }
    if ((self->seqFlags & 1) != 0)
        func_00262750(self, 0);
}
