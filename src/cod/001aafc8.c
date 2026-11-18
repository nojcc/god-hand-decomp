/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int setMotionInfo(void *a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern void KillEffect(void *a0, int a1, int a2);
extern unsigned int Rnd(void);
extern void func_0026EE40(void *a0, int a1, int a2);

/* The motion pair at offsets o1 and o2 of the enemy's resource blob into motA
 * and motB. */
#define EM_MOT_PAIR(o1, o2)                 \
    {                                       \
        int b = EM_RES(self);               \
        motA = EM_RES_REC(b, o1);           \
        motB = EM_RES_REC(b, o2);           \
    }

/* The same pair picked by enemy number: retail keeps a copy of the load in
 * every arm, so each enemy group repeats it. */
#define EM_MOT_PAIR_BY_EMNO(o1, o2)                     \
    switch (self->emNo) {                               \
        case 0x20A ... 0x20E: EM_MOT_PAIR(o1, o2) break; \
        case 0x218: EM_MOT_PAIR(o1, o2) break;          \
        case 0x245 ... 0x247: EM_MOT_PAIR(o1, o2) break; \
        case 0x24F ... 0x251: EM_MOT_PAIR(o1, o2) break; \
        case 0x278 ... 0x279: EM_MOT_PAIR(o1, o2) break; \
        default: EM_MOT_PAIR(o1, o2) break;             \
    }

/* With its solid off and the hit flash held at 3, play the blob's first motion
 * pair once, then go to mode 2, phase 1. */
__attribute__((section(".text.func_00279750")))
void func_00279750(cEm00 *self)
{
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0:
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0xC), EM_RES_REC(b, 0x10), 0, 0.0f, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 2;
                self->phase = 1;
                self->step = 0;
                self->stepArg = 0;
            } else {
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
            }
            break;
    }
}

/* Play the 0x1F78 motion pair (0x1F70 for enemy 0x24F), drawn without the
 * view test for its first 10 frames; pick the next action when it ends. */
__attribute__((section(".text.func_00247218")))
void func_00247218(cEm00 *self)
{
    self->unk617 = 1;
    switch (self->step) {
        case 0: {
            int sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int motA, motB;

            if (self->emNo == 0x24F) {
                EM_MOT_PAIR(0x1F70, 0x1F74)
            } else {
                EM_MOT_PAIR(0x1F78, 0x1F7C)
            }
            func_002A8578(self, motA, motB, 0xA, 0.0f, sel, 0);
        }
            self->unk568 = 0xA;
            self->forceShown = 1;
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->unk568 > 0) {
                self->unk568 = self->unk568 - 1;
            } else {
                self->forceShown = 0;
            }
            break;
    }
}

/* Play the blob's 0xC4C motion pair, then go to phase 0x6E; motion flag 8
 * sets emFlags bit 0x4000. */
__attribute__((section(".text.func_0023D410")))
void func_0023D410(cEm00 *self)
{
    switch (self->step) {
        case 0: {
            int sel;
            int motA, motB;

            self->unk1864 = 0;
            EM_MOT_PAIR_BY_EMNO(0xC4C, 0xC50)
            sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, motA, motB, 0xA, 0.0f, sel, 0);
        }
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6E;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (self->seqFlags & 8) {
        self->emFlags = self->emFlags | 0x4000;
    }
}

__attribute__((section(".text.func_001AAFC8")))
void func_001AAFC8(void *a0){ char *s0=(char*)a0; int v0;
 if(*(int*)(s0+0x9D4)!=0) *(int*)(s0+0x9D4)=*(int*)(s0+0x9D4)-1;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(int*)(s0+0x9D0)=*(int*)(s0+0x9D0)&0xBFFFFFFF;
  { int b=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(b+0xC)+b,*(int*)(b+0x6C)+b,0xA,0.0f,0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){
   if(*(int*)(s0+0x9D0)<0){ *(unsigned char*)(s0+0x2F7)=0; *(int*)(s0+0x9E4)=0;
    *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1; } }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  break;
 case 2:
  v0=*(int*)(s0+0x304);
  setMotionInfo(s0,*(int*)(v0+0xC)+v0,0,0,0.0f,0.0f,0);
  moveMotion(s0);
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  if((*(int*)(s0+0x9E4))++<0x12C && *(unsigned char*)(s0+0x2F7)==0){
   KillEffect(s0,0xA,2);
   *(unsigned char*)(s0+0x2F7)=*(unsigned char*)(s0+0x2F7)+1; }
  break; } }

/* Turn toward the player through two motion pairs, each left at random once
 * it ends; any weapon within 10 units sends it to phase 2. */
__attribute__((section(".text.func_00277858")))
void func_00277858(cEm00 *self)
{
    int b;

    switch (self->step) {
        case 0:
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x64), EM_RES_REC(b, 0x68), 3, 0.0f, 0, 0);
            self->step = self->step + 1;
        case 1:
            cGameObj_SetTgtTurn(self, Getplayer()->pos, self->speedRate * 0.09817477f);
            if (moveMotion(self) != 0 && (Rnd() & 1) != 0) {
                self->step = self->step + 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2:
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0xC), EM_RES_REC(b, 0x10), 3, 0.0f, 0, 0);
            self->step = self->step + 1;
        case 3:
            cGameObj_SetTgtTurn(self, Getplayer()->pos, self->speedRate * 0.09817477f);
            if (moveMotion(self) != 0 && (Rnd() & 1) != 0) {
                self->step = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (func_002DDAB0(self->pos, 0, 10.0f) != 0) {
        self->stepArg = 0;
        self->mode = 0;
        self->step = 0;
        self->phase = 2;
    }
}

/* Two motion steps picked by enemy number (0xC2C, then 0xC34 once the first
 * ends or unk16EC is positive); pick the next action after the second. Motion
 * flag 8 sets emFlags bit 0x4000. */
__attribute__((section(".text.func_0023D568")))
void func_0023D568(cEm00 *self)
{
    switch (self->step) {
        case 0: {
            int sel;
            int motA, motB;

            self->unk1864 = 0;
            EM_MOT_PAIR_BY_EMNO(0xC2C, 0xC30)
            sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, motA, motB, 0xA, 0.0f, sel, 0);
        }
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->unk16EC > 0) {
                self->step = 2;
            }
            break;
        case 2: {
            int sel;
            int motA, motB;

            EM_MOT_PAIR_BY_EMNO(0xC34, 0xC38)
            sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, motA, motB, 0xA, 0.0f, sel, 0);
        }
            self->step = self->step + 1;
        case 3:
            if (moveMotion(self) != 0) {
                func_0026EE40(self, 0, 0);
                func_002705D8(self);
                break;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (self->seqFlags & 8) {
        self->emFlags = self->emFlags | 0x4000;
    }
}
