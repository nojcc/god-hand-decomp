/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/capVu0.h"
#include "godhand/motion.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);

extern void func_00129578(void *a0);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0010A438(void *a0);

extern int D_005864F0;
__attribute__((section(".text.func_00113228")))
void func_00113228(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetBigHitEffWait(&D_005864F0, 2);
    self->flags15F4 |= 0x200;
    if (self->base.step != 0 &&
        self->unk649 == 0 &&
        func_0010B2E8(self, 1) != 0) {
        self->unk649 = 1;
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (self->base.step) {
    case 0: {
        self->comboSlot = 0;
        self->comboSet = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0xC8, 0x14, 0x26, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0xC8, 0x14, 0x26, 0, 0x123);
        self->unk1684 = 1;
        func_00129578(self);
        {
            char *v = self->base.pack;
            func_002A8578(self, EM_RES_REC(v, 0x60C), EM_RES_REC(v, 0x610), 3, 0.0f, 0, 0);
        }
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
        self->base.step += 1;
    }
    case 1: {
        float one;
        cGameObj *e;
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            func_00129630(self);
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        e = self->unk640;
        if (e != 0) {
            cGameObjVt *vt = cGameObj_vt(e);
            cVec *p = self->base.pos;
            int off = vt->getPosDelta;
            cVec *(*fp)(void *self) = vt->getPos;
            cVec *r = fp((char *)e + off);
            if (capVu0MagnitudeSqXZ(p, r) < 1.21f) {
                self->base.nullSpeed.x = 0.0f;
                self->base.nullSpeed.z = 0.0f;
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    }
    func_0010A438(self);
    if (self->base.seqFlags & 0x100) {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 1, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}
