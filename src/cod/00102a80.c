#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/gameWork.h"
/* sn-2.95.3-136 matched TU. */

extern int func_002DDAB0(void *a0, int a1, float f);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float Adjust_theta(float f12);
extern void func_001034E0(void *a0);
extern void func_00260438(void *a0);
extern void func_0012B618(void *a0);

__attribute__((section(".text.func_00277C48")))
void func_00277C48(void *a0)
{
    char *s0 = (char *)a0;
    void *e;
    float one;
    int v0;

    e = (void *)func_002DDAB0(*(void **)(s0 + 0xF0), 0, 15.0f);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x5C) + v0, *(int *)(v0 + 0x60) + v0, 3, 0.0f, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            if (e != 0) {
                cOmBase_dieCommon(e);
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00246F40")))
void func_00246F40(cEm00 *self)
{
    float one;
    int v0, t;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->emFlags |= 0x20000;
    self->emFlags |= 0x10000;
    switch (self->step) {
    case 0:
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        v0 = EM_RES(self);
        func_002A8578(self, *(int *)(v0 + 0xC34) + v0, *(int *)(v0 + 0xC38) + v0, 10, 80.0f, t & 0xFFFF, 0);
        self->unk5B4 = 0x1869F;
        func_0026F120(self);
        self->step = self->step + 1;
    case 1:
        self->emFlags |= 0x20000;
        if (moveMotion(self) != 0) {
            func_00270C78(self);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_00102A80")))
void func_00102A80(void *a0)
{
    char *s0 = (char *)a0;
    cGameObj *pl = Getplayer();
    float one;
    float f;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x1C) + v0, *(int *)(v0 + 0x20) + v0, 10, 0.0f, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (*(unsigned char *)(((char *)pl + 0x61F)) != 0) {
            f = 3.1415927f - *(float *)(((char *)pl + 0x608));
            f = f - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.4f;
            if (0.0418879f < f) {
                f = 0.0418879f;
            }
            if (*(float *)(((char *)pl + 0x604)) < 0.0f) {
                f = -f;
            }
            *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + f;
            *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
        }
        one = 1.0f;
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    func_001034E0(s0);
}

__attribute__((section(".text.func_00258C40")))
void func_00258C40(cEm00 *self)
{
    float one;
    int a, c;

    self->emFlags |= 0x4000;
    switch (self->step) {
    case 0:
        switch (self->emNo) {
        default:
        {
            int b = EM_RES(self);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247:
        {
            int b = EM_RES(self);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x24F: case 0x250: case 0x251:
        {
            int b = EM_RES(self);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x278: case 0x279:
        {
            int b = EM_RES(self);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        }
        func_002A8578(self, a, c, 10, 0.0f, Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF, 0);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0x6E;
            self->step = 0;
            self->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_00246088")))
void func_00246088(cEm00 *self)
{
    char *v;
    float one;
    int flag;
    int s0v, s1v;

    flag = 1;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        if (D_007474A0.room == 0x303) {
            if ((self->emFlags2 & 0x2000000) == 0) {
                self->emFlags2 |= 0x2000000;
                self->hitFlash = 10.0f;
                flag = 0;
            }
        }
        if (flag != 0) {
            func_00260438(self);
        }
        v = self->pack;
        s0v = EM_RES_REC(v, 0xBCC);
        s1v = EM_RES_REC(v, 0xBD4);
        func_002A8578(self, s0v, s1v, 10, 0.0f, Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF, 0);
        self->unk568 = 3;
        self->step = self->step + 1;
    case 1:
        v = (char *)Getplayer();
        cGameObj_SetTgtTurn(self, *(cVec **)(v + 0xF0), self->speedRate * 0.19634954f);
        if (moveMotion(self) != 0) {
            if (--self->unk568 <= 0) {
                func_002705D8(self);
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_00110E98")))
void func_00110E98(pl00 *self)
{
    char *v;
    float one;

    self->flags15F4 |= 0x100000;
    switch (self->base.step) {
    case 0:
        self->comboSlot = 0;
        self->comboSet = 0;
        func_00124540(self, 4);
        if (self->sub6A0 != 0) {
            v = self->base.pack;
            func_002A8578(self->sub6A0, EM_RES_REC(v, 0x37C), EM_RES_REC(v, 0x398), 3, 0.0f, 0, 0);
        }
        v = self->base.pack;
        func_002A8578(self, EM_RES_REC(v, 0x364), EM_RES_REC(v, 0x368), 3, 0.0f, 0, 0);
        self->unk15B0 = 1;
        self->base.step = self->base.step + 1;
    case 1:
        if (self->unk640 != 0) {
            self->unk648 = 0x14;
        }
        InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
        if (moveMotion(self) != 0) {
            Obj0000_Clear_Fields_640_648_124E58(self);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    if (self->base.seqFlags & 1) {
        func_0012B618(self);
    }
    if (func_00123938(self, 1) != 0) {
        Obj0000_Clear_Fields_640_648_124E58(self);
    }
}
