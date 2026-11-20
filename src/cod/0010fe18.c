/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void func_001268F0(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_00126770(void *a0);
extern void func_0010A438(void *a0);
extern void func_00129EB0(void *a0);
extern unsigned char D_005864F0[];
extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEma2_startPlayerMotion(void *a0, int a1, float f12, float f13);
extern int D_00747A24;
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);

__attribute__((section(".text.func_001160A0")))
void func_001160A0(pl00 *self)
{
    cVec *d;
    cVec *s;
    self->base.hitFlash = 5.0f;
    switch (self->base.step) {
    case 0: {
        char *t;
        self->comboSlot = 0;
        self->comboSet = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        d = &self->base.posA;
        self->base.pos->x = self->unk660.x;
        self->base.pos->z = self->unk660.z;
        s = self->base.pos;
        if (d != s) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
        self->base.rot.y = self->unk670;
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x954), EM_RES_REC(t, 0x958), 0, 0.0f, 0, 0);
        self->base.step += 1;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
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

__attribute__((section(".text.func_0010FE18")))
void func_0010FE18(pl00 *self){ char *v0;
 switch(self->base.step){
 case 0:
  self->comboSlot=0; self->comboSet=0;
  Obj0000_Clear_Fields_640_648_124E58(self);
  func_00126770(self);
  pl00_clearMotionCam(self,0,0);
  Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self,0x14,0xB,0xA,0,0xA);
  Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self,0x14,0xB,0xA,0,0xA);
  v0=self->base.pack;
  self->unk1684=0;
  func_002A8578(self,EM_RES_REC(v0,0x100),EM_RES_REC(v0,0x108),3,0.0f,0,0);
  self->unk15B0=1;
  self->base.step=self->base.step+1;
 case 1:
  if(moveMotion(self)!=0){ self->base.mode=0; self->base.phase=0; self->base.step=0; self->base.stepArg=0; }
  cObjBase_addNullSpeed_Rotation(self,1.0f);
  cObjBase_addNullSpeed(self,1.0f);
 }
 func_0010A438(self);
 if((self->base.seqFlags&3)!=0 && self->unk15B0!=0){
  self->unk15B0=0; func_00129EB0(self); }
 func_00123938(self,1); }

#include "godhand/vu0.h"
__attribute__((section(".text.func_001228D8")))
void func_001228D8(pl00 *self)
{
    cEm00 *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    self->base.hitFlash = 5.0f;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    switch (self->base.step) {
    case 0:
        buf[0] = 0.5174f;
        buf[1] = 0.0f;
        buf[2] = 0.5303f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(self, s2, buf, 0, v);
        cEma2_startPlayerMotion(s2, 0, v, v);
        self->base.unk56E = 0xF;
        self->base.step = self->base.step + 1;
    case 1:
        if (self->base.unk56E != 0 && s2 != 0) {
            cVec *d;
            cVec *e = &s2->vel;
            self->base.unk56E = self->base.unk56E - 1;
            d = self->base.pos;
            VU0_VADD_XYZ_IP(d, 0, e);
        }
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
}

/* sn-2.95.3-136 matched TU. */






















/* sn-2.95.3-136 matched TU. */






















__attribute__((section(".text.func_0011F0D0")))
void func_0011F0D0(pl00 *self)
{
    cEm00 *s0;
    float buf[4] __attribute__((aligned(16)));
    float v;

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);

    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[0] = 0.0969f;
        buf[1] = 0.0f;
        buf[2] = 0.6003f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(self, s0, buf, 0, v);
        cEm00_GetPlMotion(s0, 0x1C, v, v);
        self->unk15B0 = 1;
        self->unk15B4 = 1;
        self->base.unk56E = 0x3C;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp <= 0) {
                self->base.hp = 1;
            }
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) != 0 && self->unk15B4 != 0) {
            self->unk15B4 = 0;
            if (s0 != 0) {
                func_0012C0F8(self, (int)(s0->unk76C * 3.0f));
            }
            func_0012C348(self, 2);
        } else {
            self->unk15B4 = 1;
        }
        if ((self->base.seqFlags & 2) != 0 && self->unk15B0 != 0) {
            self->unk15B0 = 0;
            if (s0 != 0) {
                func_0012C0F8(self, (int)(s0->unk76C * 8.0f));
            }
            if (self->base.hp <= 0) {
                self->base.hp = 1;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                self->base.motionFlags = self->base.motionFlags | 8;
            }
            func_0012C348(self, 2);
        }
        if ((self->base.seqFlags & 0x200) != 0 && self->base.hp < 9) {
            self->base.step = 2;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s0, 0x1D, 0.0f, 0.0f);
        self->base.hp = 0;
        func_0012C348(self, 2);
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
        self->base.step = self->base.step + 1;
    case 3:
        self->base.motionFlags = self->base.motionFlags | 8;
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            D_00747A24 = D_00747A24 | 8;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}
