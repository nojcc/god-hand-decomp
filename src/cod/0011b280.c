/* sn-2.95.3-136 matched TU. */

#include "godhand/motion.h"
#include "godhand/pl00Fn.h"

extern void func_0010A438(void *a0);
extern int D_007474A0;
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
__attribute__((section(".text.func_0011B280")))
void func_0011B280(pl00 *self){ int s2,s1;
 self->base.hitFlash=15.0f;
 switch(self->base.step){
 case 0:
  if(self->base.stepArg!=0 || (D_007474A0&0xF0)!=0){
   { char *v0=self->base.pack;
   s2=*(int*)(v0+0x51C)+(int)v0; s1=*(int*)(v0+0x520)+(int)v0; }
   Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self,10,0x17,0x2A,0,10);
   Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self,10,0x17,0x2A,0,10);
   self->unk1684=0;
  } else {
   { char *v1=self->base.pack;
   s2=*(int*)(v1+0x174)+(int)v1; s1=*(int*)(v1+0x178)+(int)v1; } }
  func_002A8578(self,s2,s1,10,0.0f,0,0);
  self->base.step=self->base.step+1;
 case 1:
  if(moveMotion(self)!=0){ self->base.mode=0; self->base.phase=0;
   self->base.step=0; self->base.stepArg=0; }
  cObjBase_addNullSpeed_Rotation(self,1.0f);
  cObjBase_addNullSpeed(self,1.0f);
  if(func_00123938(self,1)==0) func_0010A438(self); break; } }
