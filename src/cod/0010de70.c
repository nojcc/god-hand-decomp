/* sn-2.95.3-136 matched TU. */

#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/pl00Fn.h"
#include "godhand/capVu0.h"
#include "godhand/cGameObj.h"
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0010A438(void *a0);
__attribute__((section(".text.func_0010DE70")))
void func_0010DE70(pl00 *self)
{
    if (self->base.hp <= 0)
        self->base.hp = 1;
    if (func_0010B2E8(self, 0) != 0 && self->unk15BC >= 3)
        self->unk15BC = 2;
    switch (self->base.step) {
    case 0:
    {
        int p, q;
        float f;

        func_00124540(self, 1);
        self->comboSlot = 0;
        self->comboSet = 0;
        if ((signed char)self->unk648 > 0)
            self->unk648 = 0x2D;
        switch (self->base.stepArg) {
        default:
        case 0:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, (int)(self->unk600 * 15.0f), 4, 0x1A, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, (int)(self->unk600 * 15.0f), 4, 0x1A, 0, 0x77);
            {
                int t = EM_RES(&self->base);
                f = 2.0f;
                p = EM_RES_REC(t, 0x830);
                q = EM_RES_REC(t, 0x834);
            }
            break;
        case 1:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, (int)(self->unk600 * 10.0f), 4, 0x1A, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, (int)(self->unk600 * 10.0f), 4, 0x1A, 0, 0x77);
            {
                int t = EM_RES(&self->base);
                f = 5.0f;
                p = EM_RES_REC(t, 0x61C);
                q = EM_RES_REC(t, 0x624);
            }
            break;
        case 2:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, (int)(self->unk600 * 10.0f), 3, 0x1B, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, (int)(self->unk600 * 10.0f), 3, 0x1B, 0, 0x77);
            {
                int t = EM_RES(&self->base);
                f = 2.0f;
                p = EM_RES_REC(t, 0x838);
                q = EM_RES_REC(t, 0x83C);
                self->unk1603 = 0xF;
            }
            break;
        }
        func_002A8578(self, p, q, 3, f, 0x40, 0);
        self->unk15C4 = 0.0f;
        self->unk15B0 = 1;
        self->stepCount = 0;
        self->unk1588 = 0.0f;
        self->stepScale = 1.0f;
        self->unk15B8 = 1;
        self->unk15BC = 999;
        self->base.unk568 = 10;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
    {
        cGameObj *e;

        if (self->base.unk568 != 0) {
            self->base.unk568 = self->base.unk568 - 1;
            InvokeVirtualAtField214AndForward_124E68(self, 0.392699093f);
        }
        if (self->held != 0)
            self->unk648 = 0x14;
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        e = self->held;
        if (e != 0 && self->base.stepArg != 0) {
            cGameObjVt *vt = cGameObj_vt(e);
            cVec *pos = self->base.pos;
            cVec *r = vt->getPos((char *)e + vt->getPosDelta);
            if (capVu0MagnitudeSqXZ(pos, r) < 1.95999992f) {
                self->base.nullSpeed.x = 0.0f;
                self->base.nullSpeed.z = 0.0f;
            }
        }
        if ((self->base.seqFlags & 0x200) != 0)
            self->base.nullSpeed.z = self->base.nullSpeed.z * 1.5f;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    }
    if (self->unk15BC > 0) {
        self->unk15BC = self->unk15BC - 1;
        func_0010A438(self);
    }
    if (func_00123938(self, 1) != 0)
        pl00_clearMotionCam(self, 1, 0);
}
