/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/capVu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0010A438(void *a0);

extern void SetMotionStep(void *a0, float f12);
extern void KillEffect(void *a0, int a1, int a2);
extern char *Getplayer(void);
extern int D_007474A0;


static __inline__ long inrange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

__attribute__((section(".text.func_0010E5B8")))
void func_0010E5B8(pl00 *self)
{
    int one = 1;

    if (self->base.hp <= 0)
        self->base.hp = one;
    switch (self->base.step) {
    case 0:
    {
        cGameObj *e;
        cGameObj *e2;
        char *t;

        func_00124540(self, 0);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        if (self->unk648 > 0)
            self->unk648 = 0x2D;
        e = self->unk640;
        if (e != 0) {
            if (inrange(e->actorId, 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, (int)(self->unk600 * 10.0f), 8, 0x13, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, (int)(self->unk600 * 10.0f), 8, 0x13, 0, 0xA);
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x18C), EM_RES_REC(t, 0x194), 5, 0.0f, 0, 0);
        self->unk15C0 = 1.0f;
        self->unk15C4 = 0.0f;
        self->unk15B0 = 1;
        self->unk15B8 = 1;
        self->unk1588 = 0.0f;
        self->unk15B4 = 0;
        e2 = self->unk640;
        if (e2 != 0) {
            cGameObjVt *vt = cGameObj_vt(e2);
            cVec *pos = self->base.pos;
            cVec *r = vt->getPos((char *)e2 + vt->getPosDelta);
            float d = capVu0MagnitudeXZ(pos, r) - 1.20000005f;
            if (self->unk5E0 == 0 && self->unk61F != 0) {
                if (1.0f < d) d = 1.0f;
            } else {
                if (0.5f < d) d = 0.5f;
            }
            if (0.0f < d)
                self->unk1588 = d * 0.150000006f;
        }
        self->unk5F0 = 0xA;
        self->base.unk568 = 0x32;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
    {
        if (self->base.unk568 != 0) {
            self->base.unk568 = self->base.unk568 - 1;
            InvokeVirtualAtField214AndForward_124E68(self, 0.196349546f);
        }
        if (self->unk640 != 0)
            self->unk648 = 0x14;
        self->base.speedRate = 1.0f;
        self->unk5DC = 1.0f;
        if (self->base.seqFlags & 0x80) {
            if (self->unk15B0 != 0) {
                if (self->unk15C4 <= 0.0f)
                    self->unk15C4 = 1.0f;
            }
        }
        if (self->unk15C4 > 0.0f && self->unk15B0 != 0) {
            if (self->unk15B4 == 0) {
                self->unk15B4 = 1;
                InitRenderStruct_2A8608(&self->base, 0, 0x31, 2, 2, 0);
            }
            if ((D_007474A0 & 0xD0) != 0) {
                float sp = 0.0250000004f;
                self->base.speedRate = sp;
                self->unk5DC = sp;
                self->unk15C4 = self->unk15C4 - sp;
                SetMotionStep(self, sp);
                self->unk15C0 = self->unk15C0 + 0.0500000007f;
                if (self->unk15C4 <= 0.0f)
                    self->unk15C0 = self->unk15C0 + 1.0f;
                if (self->unk15C0 >= 1.10000002f) {
                    if (self->unk15B8 != 0) {
                        self->unk15B8 = 0;
                        self->unk1620 = cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11B, self, 0, 0, 0, 0);
                    }
                }
            } else {
                self->unk15C4 = 0.0f;
                self->unk15B0 = 0;
            }
            if (self->unk15C4 <= 0.0f)
                self->unk15B0 = 0;
        } else {
            if (self->base.seqFlags & 3)
                KillEffect(Getplayer(), 2, 2);
            if (self->unk15B4 != 0) {
                self->unk15B4 = 0;
                if (self->unk15C0 >= 2.5f) {
                    KillEffect(Getplayer(), 2, 2);
                    SetEffect(0, 0x32, self, 0, -1, 0xFFFFFFFFu);
                }
                cSnd_SeStop(&D_005FEE00, self->unk1620);
                self->unk1620 = 0;
            }
        }
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        {
            cGameObj *e = self->unk640;
            if (e != 0) {
                cGameObjVt *vt = cGameObj_vt(e);
                cVec *pos = self->base.pos;
                cVec *r = vt->getPos((char *)e + vt->getPosDelta);
                if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                    self->base.nullSpeed.x = 0.0f;
                    self->base.nullSpeed.z = 0.0f;
                }
            }
        }
        self->base.nullSpeed.z = self->base.nullSpeed.z + self->unk1588;
        self->unk1588 = self->unk1588 * 0.899999976f;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    }
    self->unk1610 = self->unk15C0;
    if (2.5f < self->unk15C0) {
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x10, 8, 0x14, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x10, 8, 0x14, 0, 0xA);
    }
    func_0010A438(self);
    if (self->base.seqFlags & 0x10) {
        if (self->unk5F0 != 0) {
            self->unk5F0 = self->unk5F0 - 1;
            self->flags15F4 |= 0x20000;
        } else {
            self->unk5E0 = 0;
            self->unk5E2 = 0;
        }
    }
    if (func_00123938(self, 1) != 0)
        pl00_clearMotionCam(self, 1, 0);
}
