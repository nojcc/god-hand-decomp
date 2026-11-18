/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cEmManage.h"
#include "godhand/sceVu0.h"
#include "godhand/cCamera.h"

extern unsigned int Rnd(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void KillEffect(void *a0, int a1, int a2);

/* Switch at random between two motions (the first from a random start frame
 * on first entry); go to phase 1 when the player comes within 225 units or
 * unk1560 bit 2 is set. */
__attribute__((section(".text.func_00278690")))
void func_00278690(cEm00 *self)
{
    switch (self->step) {
    case 0: {
        float start = 0.0f;
        int b;

        if (self->stepArg == 0) {
            start = (float)(int)(Rnd() % 0xF0);
        }
        b = EM_RES(self);
        self->stepArg = 1;
        func_002A8578(self, EM_RES_REC(b, 0xC), EM_RES_REC(b, 0x10), 5, start, 0, 0);
        self->step += 1;
    }
    case 1:
        if (moveMotion(self) != 0) {
            if (Rnd() & 1) {
                self->step = 2;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2: {
        int b = EM_RES(self);

        func_002A8578(self, EM_RES_REC(b, 0x14), EM_RES_REC(b, 0x18), 5, 0.0f, 0, 0);
        self->step += 1;
    }
    case 3:
        if (moveMotion(self) != 0) {
            if (Rnd() & 1) {
                self->step = 0;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if (self->playerDist < 225.0f || (self->unk1560 & 4) != 0) {
        self->stepArg = 0;
        self->mode = 0;
        self->step = 0;
        self->phase = 1;
    }
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_0011A060")))
void func_0011A060(pl00 *self)
{
    cEm00 *s2;
    cVec v __attribute__((aligned(16)));

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    self->flags15F4 = self->flags15F4 | 0x200;
    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        if (s2 != 0) {
            VU0_SQC2_VF0(&v, 0);
            v.x = 0.0f;
            v.z = 0.99630004f;
            v.y = 0.0f;
            sceVu0ApplyMatrix(&v, s2->mtx, &v);
            self->base.pos->x = v.x;
            self->base.pos->z = v.z;
            self->base.rot.y = s2->rot.y + 3.14159274f;
            self->base.rot.y = Adjust_theta(self->base.rot.y);
        }
        cEm00_GetPlMotion(s2, 0x52, 0.0f, 0.0f);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 5, 0, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 5, 0, 0x2A, 0, 0xA);
        self->unk1684 = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        self->base.step = self->base.step + 1;
    case 1:
        func_00124EC0(self);
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
    if (func_00123938(self, 1) != 0) {
        pl00_clearMotionCam(self, 0, 0);
    } else if (self->base.seqFlags & 0x100) {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
    }
}

/* Play two motions in turn (each pair picked by stepArg); after the second,
 * go to mode 2 when hp is gone, otherwise func_00270C78 or func_002705D8. */
__attribute__((section(".text.func_00248FE0")))
void func_00248FE0(cEm00 *self)
{
    int t, p1, p2;

    self->unk617 = 1;
    self->objFlags |= 0x40000;
    if (self->hp <= 0) {
        self->hitFlash = 3.0f;
    }
    switch (self->step) {
    case 0:
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        if (self->stepArg != 0) {
            int b = EM_RES(self);

            p1 = EM_RES_REC(b, 0x3978);
            p2 = EM_RES_REC(b, 0x397C);
        } else {
            int b = EM_RES(self);

            p1 = EM_RES_REC(b, 0x3990);
            p2 = EM_RES_REC(b, 0x3994);
        }
        self->unk1764 = 300.0f;
        func_002A8578(self, p1, p2, 3, 0.0f, t, 0);
        self->emFlags2 &= 0xDFFFFFFF;
        self->step += 1;
    case 1:
        self->emFlags |= 0x800000;
        if (moveMotion(self) != 0) {
            self->step = 2;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        if (self->stepArg != 0) {
            int b = EM_RES(self);

            p1 = EM_RES_REC(b, 0x3980);
            p2 = EM_RES_REC(b, 0x3984);
        } else {
            int b = EM_RES(self);

            p1 = EM_RES_REC(b, 0x3998);
            p2 = EM_RES_REC(b, 0x399C);
        }
        KillEffect(self, 1, 2);
        func_002A8578(self, p1, p2, 3, 0.0f, t, 0);
        self->step += 1;
    case 3:
        if (moveMotion(self) != 0) {
            if (self->hp <= 0) {
                self->stepArg = 0;
                self->phase = 0;
                self->step = 0;
                self->mode = 2;
                break;
            }
            if (func_0026F1D8(self) != 0) {
                func_00270C78(self);
                return;
            }
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}
