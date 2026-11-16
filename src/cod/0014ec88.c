#include "godhand/cCollisionSolid.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int setMotionInfo(cObjBase *self, char *motion, SEQ_DATA_HEADER_1 *seqData, unsigned int blendLen,

float step, float start, int flags);

extern unsigned int func_0031ED08(float f);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);

/* Phase 3: start the stored motion, play it until it ends and keep moving the
 * model by its null-part speed. */
__attribute__((section(".text.func_0014EC88")))
void func_0014EC88(cObjBase *self) {
    float one;
    switch (self->step) {
    case 0:
        setMotionInfo(self, self->motion, self->seqData, func_0031ED08(self->blendLeft),
                      self->motionRate, self->motionFrame, self->motionFlags);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed(self, one);
        break;
    case 2:
        moveMotion(self);
        one = 1.0f;
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_00237E90")))
void func_00237E90(cEm00 *self){ int v0; float one;
 cCollisionSolidManage_SetActive(&D_00462FC0,(struct cGameObj *)self,0);
 self->emFlags=self->emFlags|0x20000;
 self->hitFlash=3.0f;
 switch(self->step){
 case 0: v0=EM_RES(self);
  self->unk1864=0;
  func_002A8578(self,*(int*)(v0+0x1550)+v0,*(int*)(v0+0x1554)+v0,0,0.0f,0,0);
  if(self->fx0!=0) Obj1D00_SetState_6_A(&self->fx0->base);
  self->step=self->step+1;
 case 1:
  if(moveMotion(self)!=0){ self->mode=0; self->phase=0x6C;
   self->step=0; self->stepArg=0; }
  one=1.0f;
  cObjBase_addNullSpeed_Rotation(self,one);
  cObjBase_addNullSpeed(self,one); break; } }

__attribute__((section(".text.func_001ABA20")))
void func_001ABA20(void *a0){ char *s0=(char*)a0; int v0; float one;
 if(*(int*)(s0+0x9D4)!=0) (*(int*)(s0+0x9D4))--;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(int*)(s0+0x9D0)=*(int*)(s0+0x9D0)&0xBFFFFFFF;
  setMotionInfo((int)s0,*(int*)(v0+0x40)+v0,*(int*)(v0+0x68)+v0,0,0.0f,0.0f,0);
  moveMotion(s0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  one=1.0f;
  cObjBase_addNullSpeed_Rotation(s0,one);
  cObjBase_addNullSpeed(s0,one); break;
 case 2: *(unsigned char*)(s0+0x2F6)=(unsigned char)*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  one=1.0f;
  cObjBase_addNullSpeed_Rotation(s0,one);
  cObjBase_addNullSpeed(s0,one); break; } }
