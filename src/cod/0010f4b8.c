/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int irand(void);
extern void func_0027D670(void *a0, int a1, int a2);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cEmManage_SetSpeedRate(void *a0, float f12);
extern char D_005864F0[];
extern float fRand0_1(void);

/* Start motion pair 0x3DEC or, on a coin flip kept in the step argument,
 * 0x3DF4, and put the children in phase 0xD / 0xA with that argument; when it
 * ends, a counter if func_0026F1D8 allows one, else func_002705D8. */
__attribute__((section(".text.func_0025B5A8")))
void func_0025B5A8(cEm00 *self)
{
    switch (self->step) {
    case 0: {
        int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        int p1, p2;

        self->stepArg = irand() & 1;
        if (self->stepArg != 0) {
            int b = EM_RES(self);

            p1 = EM_RES_REC(b, 0x3DF4);
            p2 = EM_RES_REC(b, 0x3DF8);
        } else {
            int b = EM_RES(self);

            p1 = EM_RES_REC(b, 0x3DEC);
            p2 = EM_RES_REC(b, 0x3DF0);
        }
        self->emFlags = self->emFlags & 0xFEFFFFFF;
        func_002A8578(self, p1, p2, 2, 0.0f, nb, 0);
        if (self->sub0 != 0) {
            Obj2810_SetState_D_a1(self->sub0, self->stepArg);
        }
        if (self->sub1 != 0) {
            SetBytes2F4Mode10_2833C0(self->sub1, self->stepArg);
        }
        if (self->sub2 != 0) {
            SetBytes2F4Mode10_2833C0(self->sub2, self->stepArg);
        }
        self->step = self->step + 1;
    }
    case 1:
        if (moveMotion(self) != 0) {
            func_0026F120(self);
            if (func_0026F1D8(self) != 0) {
                func_00270C78(self);
            } else {
                func_002705D8(self);
            }
        }
        break;
    }
}

__attribute__((section(".text.func_0027C2B8")))
void func_0027C2B8(void *a0){ char *s0=(char*)a0; int v0; float f;
 *(int*)(s0+0x1560)|=3;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(unsigned char*)(s0+0x2F7)=irand()&1;
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x18)+v0,*(int*)(v0+0x1C)+v0,5,0.0f,0,0);
   InitRenderStruct_2A8608((cGameObj *)s0,0xBC,0x1E,0,2,*(void**)(s0+0x15B0)); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x20)+v0,*(int*)(v0+0x24)+v0,5,0.0f,0,0);
   InitRenderStruct_2A8608((cGameObj *)s0,0xBC,0x1F,0,2,*(void**)(s0+0x15B0)); }
  *(int*)(s0+0x5F0)=1;
  *(int*)(s0+0x600)=0;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
 }
 if(*(unsigned short*)(s0+0x3AC)&1){
  if(*(unsigned char*)(s0+0x2F7)){
   f=*(float*)(s0+0x600)-*(float*)(s0+0x5A8);
   *(float*)(s0+0x600)=f;
   if(f<=0.0f){ *(float*)(s0+0x600)=6.0f;
    func_0027D670(s0,*(unsigned char*)(s0+0x2F7),0); } }
  else if(*(int*)(s0+0x5F0)!=0){ *(int*)(s0+0x5F0)=0;
    func_0027D670(s0,*(unsigned char*)(s0+0x2F7),0); }
 } else *(int*)(s0+0x5F0)=1;
}

static __inline__ long inr(unsigned short k, int lo, int hi)
{
    long c; int t;
    c = 0;
    if (k >= lo) { t = (k < hi); c = t; }
    return c;
}
__attribute__((section(".text.func_0010F4B8")))
void func_0010F4B8(pl00 *self)
{
    switch (self->base.step) {
    case 0: {
        int p1, p2;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_00124540(self, 0);
        if (self->unk640 != 0) {
            if (inr(self->unk640->actorId, 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        if (self->base.stepArg != 0) {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, (int)(self->unk600 * 20.0f), 0x19, 0xB, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, (int)(self->unk600 * 20.0f), 0x19, 0xB, 0, 0x123);
            self->unk1684 = 0;
            p1 = EM_RES_REC(self->base.pack, 0x1C8);
            p2 = EM_RES_REC(self->base.pack, 0x1CC);
        } else {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, (int)(self->unk600 * 20.0f), 0x18, 0x1D, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, (int)(self->unk600 * 20.0f), 0x18, 0x1D, 0, 0x123);
            self->unk1684 = 0;
            p1 = EM_RES_REC(self->base.pack, 0x1A4);
            p2 = EM_RES_REC(self->base.pack, 0x1A8);
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->base.hitFlash = 15.0f;
        self->base.step += 1;
    }
    case 1:
        func_00124EC0(self);
        if (self->unk640 != 0)
            self->unk648 = 0x14;
        if (moveMotion(self) != 0) {
            if (self->base.stepArg == 0)
                Obj0000_Clear_Fields_640_648_124E58(self);
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
    func_0010A438(self);
    if (self->base.seqFlags & 0x100) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if (func_00123938(self, 1) != 0) {
        if (self->base.stepArg == 0)
            Obj0000_Clear_Fields_640_648_124E58(self);
        pl00_clearMotionCam(self, 1, 0);
    }
}

/* Sinking enemy: collision off, motion pairs 0x168 and 0x170 with 50 hp taken
 * between them; at 0 hp it sinks until y < -5, then mode 2, phase 2. Plays
 * sounds 0x60 and 0x51 on two random timers. */
__attribute__((section(".text.func_00287E50")))
void func_00287E50(cEm00 *self)
{
    int b;

    self->hitFlash = 3.0f;
    self->gotoFlags = self->gotoFlags | 0x10000;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->unk258 = self->unk258 | 0x80000000;
    switch (self->step) {
    case 0:
        b = EM_RES(self);
        func_002A8578(self, EM_RES_REC(b, 0x168), EM_RES_REC(b, 0x16C), 3, 0.0f, 0, 0);
        self->step = self->step + 1;
    case 1:
        moveMotion(self);
        break;
    case 2:
        b = EM_RES(self);
        func_002A8578(self, EM_RES_REC(b, 0x170), EM_RES_REC(b, 0x174), 3, 0.0f, 0, 0);
        self->hp = self->hp - 0x32;
        self->step = self->step + 1;
    case 3:
        if (moveMotion(self) != 0) {
            self->step = 0;
        }
        break;
    }
    if (self->hp <= 0) {
        self->pos->y = self->pos->y - self->speedRate * 0.1f;
        if (self->pos->y < -5.0f) {
            self->step = 0;
            self->mode = 2;
            self->phase = 2;
            self->stepArg = 0;
        }
    }
    self->timer = self->timer - self->speedRate;
    if (self->timer <= 0.0f) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x60, self, 0, 0, 0, 0);
        self->timer = fRand0_1() * 60.0f + 90.0f;
    }
    self->timer2 = self->timer2 - self->speedRate;
    if (self->timer2 <= 0.0f) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x51, self, 0, 0, 0, 0);
        self->timer2 = fRand0_1() * 4.0f + 8.0f;
    }
}
