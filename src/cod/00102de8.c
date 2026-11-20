/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float D_003BD488;

__attribute__((section(".text.func_00102DE8")))
void func_00102DE8(void *a0){ char *s0=(char*)a0; int p1,p2;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  switch(*(unsigned char*)(s0+0x2F7)){
  case 0: default: { char *v0=*(char**)(s0+0x304);
   p1=*(int*)(v0+0x34)+(int)v0; p2=*(int*)(v0+0x38)+(int)v0; } break;
  case 1: { char *v1=*(char**)(s0+0x304);
   p1=*(int*)(v1+0x3C)+(int)v1; p2=*(int*)(v1+0x40)+(int)v1; } break;
  case 2: { char *v2=*(char**)(s0+0x304);
   p1=*(int*)(v2+0x44)+(int)v2; p2=*(int*)(v2+0x48)+(int)v2; } break; }
  func_002A8578(s0,p1,p2,5,0.0f,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }

__attribute__((section(".text.func_0023F970")))
void func_0023F970(cEm00 *self){ char *v0; int p1,p2,t0;
 switch(self->step){
 case 0:
  v0=self->pack;
  p1=EM_RES_REC(v0,0x488); p2=EM_RES_REC(v0,0x48C);
  t0=Obj0000_Get_Byte_17C3_NZ_2_276468(self)&0xFFFF;
  func_002A8578(self,p1,p2,3,0.0f,t0,0);
  self->step=self->step+1;
 case 1:
  if(moveMotion(self)!=0){ func_002705D8(self); }
  cObjBase_addNullSpeed_Rotation(self,1.0f);
  cObjBase_addNullSpeed(self,1.0f); break; }
 if(self->unk6EC==0){
  if(self->seqFlags&1){
   cOmWeapon *a=func_002DDAB0(self->pos,1,1.5f);
   if(a!=0) func_0026AB20(self,a,a->base.actorId); } } }

typedef struct { int w[3]; } T3;
__attribute__((section(".text.func_001AB8F8")))
void func_001AB8F8(void *a0){ char *s0=(char*)a0; char *g; T3 c; T3 t;
 g=*(char**)(s0+0x304);
 t.w[0]=*(int*)(g+0x18)+(int)g;
 t.w[1]=*(int*)(g+0x24)+(int)g;
 t.w[2]=*(int*)(g+0x30)+(int)g;
 c=t;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if((*(int*)(s0+0x9D0)&0x40000000)==0){
   *(unsigned char*)(s0+0x2F7)=0;
   *(unsigned char*)(s0+0x2F4)=0;
   *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0;
   *(int*)(s0+0x9D4)=0x3C;
   break; }
  func_002A8578(s0,c.w[*(unsigned char*)(s0+0x2F7)],0,10,0.0f,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }

__attribute__((section(".text.func_00237F98")))
void func_00237F98(void *a0){ char *s0=(char*)a0; int v0;
 cCollisionSolidManage_SetActive(&D_00462FC0,(struct cGameObj *)s0,0);
 *(float*)(s0+0x54C)=3.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x146C)+v0,*(int*)(v0+0x1470)+v0,0,0.0f,0,0);
  *(float*)(*(char**)(s0+0xF0)+4)-=(*(float*)(s0+0x114)-1.0f)*1.6f;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  *(int*)(s0+0x16D0)|=0x10000;
  if(moveMotion(s0)!=0){ *(int*)(s0+0x16D0)&=0xFFFEFFFF; *(unsigned char*)(s0+0x2F5)=0x6C; *(unsigned char*)(s0+0x2F4)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }

__attribute__((section(".text.func_0010CB10")))
void func_0010CB10(pl00 *self){ char *t0; int p1,p2; void *fl;
 if(self->base.hp<=0) self->base.hp=1;
 switch(self->base.step){
 case 0:
  self->comboSlot=0; self->comboSet=0;
  Obj0000_Clear_Fields_640_648_124E58(self);
  t0=self->base.pack; fl=self->sub6A0;
  p1=*(int*)(t0+0x7C)+(int)t0; p2=*(int*)(t0+0x80)+(int)t0;
  if(fl!=0){
   func_002A8578(fl,*(int*)(t0+0x39C)+(int)t0,*(int*)(t0+0x3A0)+(int)t0,5,0.0f,0,0);
   { char *v0=self->base.pack;
   p1=*(int*)(v0+0x3A4)+(int)v0; p2=*(int*)(v0+0x3A8)+(int)v0; } }
  func_002A8578(self,p1,p2,5,0.0f,0,0);
  self->base.step=self->base.step+1;
 case 1:
  self->unk15F0=D_003BD488;
  if(moveMotion(self)!=0){ pl00_clearMotionCam(self,1,0); self->base.mode=0; self->base.phase=0;
   self->base.step=0; self->base.stepArg=0; }
  cObjBase_addNullSpeed_Rotation(self,1.0f);
  cObjBase_addNullSpeed(self,1.0f);
  func_00123938(self,1); break; } }

__attribute__((section(".text.func_00236ED0")))
void func_00236ED0(void *a0){ char *s0=(char*)a0; int v0;
 cCollisionSolidManage_SetActive(&D_00462FC0,(struct cGameObj *)s0,0);
 *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x20000;
 *(float*)(s0+0x54C)=3.0f;
 *(int*)(s0+0x250)=*(int*)(s0+0x250)|0x10000;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x1BA0)+v0,*(int*)(v0+0x1BA4)+v0,0,0.0f,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6C;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break;
 case 2: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x1BA8)+v0,*(int*)(v0+0x1BAC)+v0,0,0.0f,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6C;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }
