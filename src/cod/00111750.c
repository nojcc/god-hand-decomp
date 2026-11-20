/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/DogRace.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/CustomIDWork.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int irand(void);
extern void cEm00_armAttackVolume(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0010A438(void *a0);
extern char D_005864F0[];
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_00227FE8")))
void func_00227FE8(cEm00 *self)
{

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        self->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        self->stepArg = (unsigned int)irand() % 3;
        v0 = self->pack;
        a1v = EM_RES_REC(v0, 0x2FEC);
        a2v = EM_RES_REC(v0, 0x2FF0);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = self->pack;
            a2v = EM_RES_REC(v1, 0x2FF4);
        }
        StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, -1, 0);
        func_002A8578(self, a1v, a2v, 3, 0.0f, gb, 0);
        self->timerA = 0x1E;
        self->timer = 20.0f;
        self->step += 1;
        self->timerB = 0;
        self->timerC = 0;
    }
        /* fallthrough */
    case 1: {
        float f1;
        if (self->timerA != 0) {
            cGameObj *pl;
            self->timerA -= 1;
            pl = Getplayer();
            cGameObj_SetTgtTurn(self, pl->pos, self->speedRate * 0.19634955f);
        }
        f1 = self->timer;
        if (f1 > 0.0f) {
            self->emFlags |= 0x2000;
            self->timer = f1 - self->speedRate;
            self->emFlags2 |= 0x2000;
        }
        if (self->emFlags2 & 0x4000) {
            self->timerC = 1;
            cEm00_armAttackVolume(self);
        }
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->seqFlags & 0x10) && self->timerC == 0) {
            self->step += 1;
        }
        break;
    }
    case 2: {
        int gb;
        char *v1;
        self->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        v1 = self->pack;
        func_002A8578(self, EM_RES_REC(v1, 0x2FF8), EM_RES_REC(v1, 0x2FFC), 3, 0.0f, gb, 0);
        self->step += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    func_00260B30(self);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001EE2E8")))
void func_001EE2E8(DogRaceList *self, int on, int sel)
{
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x1, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x2, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x3, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x4, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x5, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x6, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x7, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x8, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x9, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0xA, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0xB, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0xC, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0xD, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0xE, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0xF, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x10, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x17, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x18, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x19, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x1A, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x1B, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x11, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x12, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x13, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x14, on);
    SetCustomIDDispOneOrAll_1EE1C0(self, 0x1C, on);
    if (sel) {
        int mff = ~0xFF;
        int m24 = 0xFFFFFF;
        int hi = 0x80000000;
        int m16 = ~0xFF0000;
        int m8 = ~0xFF00;
        int b;
        int c;
        int x = ((((((((b & m24) | hi) & m16) | 0x800000) & m8) | 0x8000) & mff) | 0x80);
        int y = ((((((((c & mff) | 0xD0) & m8) | 0xD000) & m16) | 0xD00000) & m24) | hi);
        CustomIDWork_SetColorAnimSin(&self->elem[0x15], x, y, 6);
        SetCustomIDDispOneOrAll_1EE1C0(self, 0x15, on);
    } else {
        int mff = ~0xFF;
        int m24 = 0xFFFFFF;
        int hi = 0x80000000;
        int m16 = ~0xFF0000;
        int m8 = ~0xFF00;
        int b;
        int c;
        int x = ((((((((b & m24) | hi) & m16) | 0x800000) & m8) | 0x8000) & mff) | 0x80);
        int y = ((((((((c & mff) | 0xD0) & m8) | 0xD000) & m16) | 0xD00000) & m24) | hi);
        CustomIDWork_SetColorAnimSin(&self->elem[0x16], x, y, 6);
        SetCustomIDDispOneOrAll_1EE1C0(self, 0x16, on);
    }
}

/* sn-2.95.3-136 matched TU. */




























__attribute__((section(".text.func_00111750")))
void func_00111750(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    self->flags15F4 |= 0x200;
    if (self->base.step != 0 &&
        self->unk649 == 0 &&
        func_0010B2E8(self, 1) != 0) {
        self->unk649 = 1;
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (self->base.step) {
    case 0:
    {
        char *t;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->comboSlot = 0;
        self->comboSet = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, 0x82, 0x11, 0x1F, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, 0x82, 0x11, 0x1F, 0, 0x123);
        t = self->base.pack;
        self->unk1684 = 1;
        func_002A8578(self, EM_RES_REC(t, 0x1C0), EM_RES_REC(t, 0x1C4),
                      3, 0.0f, 0, 0);
        func_00129578(self);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        InvokeVirtualAtField214AndForward_124E68(self, 3.14159274f);
        self->unk15B0 = 1;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if ((self->base.seqFlags & 0x100) != 0) {
            cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
        }
        if (moveMotion(self) != 0) {
            func_00129630(self);
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
    func_0010A438(self);
    if ((self->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if ((self->base.seqFlags & 1) != 0) {
        cSnd *g = &D_005FEE00;
        cSnd_SeStop(g, self->unk161C);
        self->unk161C = 0;
        g->flagsB0 &= 0xFFBFFFFF;
        g->flagsAC &= 0xFFBFFFFF;
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 0, 0);
    } else {
        self->base.seqFlags |= 0x800;
        self->unk674 = 0.05f;
    }
}

/* sn-2.95.3-136 matched TU. */















#include "godhand/vu0.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.func_0025C5D8")))
void func_0025C5D8(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x3BFC), EM_RES_REC(p, 0x3C00),
                      0, 0.0f, 0, 0);
        self->timerA = 0x2A;
        self->timerB = 1;
        self->unk56E = 0x1E;
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

            self->timerB = 0;
            vt = cGameObj_vt((cGameObj *)self);
            vt->unkAC((char *)self + vt->unkA8Delta, 0x64, s1, 1, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, 10.0f);
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
        break;
    default:
        break;
    }
    if ((self->seqFlags & 1) != 0)
        func_00262750(self, 0);
}
