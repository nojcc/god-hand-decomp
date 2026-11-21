/* sn-2.95.3-136 matched TU. */

/* func_0011D198 — 0x0011D198, 792 B — sn-2.95.3-136.
 * +0x2F6 phase machine, 0x694 object family; template src/cod/0011c348.c
 * (func_0011C348, jaccard 1.00). */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"

extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void func_00124EC0(void *a0);
extern int  moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern int  D_00747A24;
extern char D_005864F0[];

__attribute__((section(".text.func_0011D198")))
void func_0011D198(pl00 *self)
{
    cEm00 *s0;
    cVec *p;
    cVec *q;

    self->base.hitFlash = 5.0f;
    self->base.objFlags |= 0x10000;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (self->base.step) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.4165f;
        buf[2] = 1.1225f;
        buf[3] = 1.0f;
        func_001299F0(self, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x10, z, z);
        self->base.unk56E = 0xF;
        self->unk15B0 = 1;
        self->stepCount = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        (self->base.step)++;
    }
        /* fallthrough */
    
    
    case 1:
        if (self->base.unk56E == 0 || s0 == 0)
            goto join;
        (self->base.unk56E)--;
        p = self->base.pos;
    
        q = &s0->vel;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->base.hp > 0) {
                pl00_clearMotionCam(self, 0, 0);
                self->base.mode = 1;
                self->base.phase = 4;
                self->base.step = 0;
                self->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) != 0) {
            if (self->unk15B0 != 0) {
                self->unk15B0 = 0;
                if (s0 != 0) {
                    func_0012C0F8(self, (int)(s0->unk76C * 8.0f));
                }
                func_0012C348(self, 0);
            }
        } else {
            self->unk15B0 = 1;
        }
        if ((self->base.seqFlags & 2) != 0) {
            if (self->stepCount != 0) {
                self->stepCount = 0;
                if (s0 != 0) {
                    func_0012C0F8(self, (int)(s0->unk76C * 16.0f));
                }
                if (self->base.hp <= 0) {
                    cSnd *g = &D_005FEE00;

                    self->base.hp = 0;
                    cSnd_SeCall_2CBA48(g, 0, 0xD6, self, 0, 0, 0, 0);
                    cSnd_DieDemoStart(g);
                    cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                    self->base.motionFlags |= 8;
                } else {
                    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
                }
                func_0012C348(self, 2);
            }
        } else {
            self->stepCount = 1;
        }
        break;
    default:
        break;
    }
}
