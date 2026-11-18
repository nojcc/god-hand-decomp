/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern int D_00747A24;
extern char D_005864F0[];
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);
extern int irand(void);
extern void func_00129718(void *a0, void *a1, int a2);

/* func_0011CEE8, 688 B, sn-2.95.3-136. Body: wave 21 V1 (exact with -malign-loops=2) + L1 w34 nested Duff do{}while(0). */























#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_0011CEE8")))
void func_0011CEE8(pl00 *self)
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

        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf[1] = 0.0f;
        buf[0] = 0.0463999994f;
        buf[2] = 0.625100017f;
        buf[3] = 1.0f;
        func_001299F0(self, s0, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s0, 0xF, 0.0f, 0.0f);
        self->unk15B0 = 1;
        self->base.unk56E = 0xF;
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
        if ((self->base.seqFlags & 1) != 0
            && self->unk15B0 != 0) {
            self->unk15B0 = 0;
            if (s0 != 0) {
                func_0012C0F8(self, (int)(s0->unk76C * 50.0f));
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
        break;
    default:
        break;
    }
}

/* func_00122140, 692 B, sn-2.95.3-136. Twin: func_00121E88 (src/cod/0011c348.c) + nested Duff do{}while(0). */






























#include "godhand/vu0.h"

__attribute__((section(".text.func_00122140")))
void func_00122140(pl00 *self)
{
    cEm00 *s0;
    cVec *p;
    cVec *q;

    self->base.hitFlash = 5.0f;
    s0 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(D_005864F0);
    self->base.objFlags |= 0x10000;
    switch (self->base.step) {
    case 0:
    {
        float buf[4];
        float z;

        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = 0.0174f;
        buf[2] = 0.5424f;
        buf[3] = 1.0f;
        func_001299F0(self, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x33, z, z);
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        self->unk15B0 = 1;
        self->base.unk56E = 0xF;
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
        if ((self->base.seqFlags & 1) != 0
            && self->unk15B0 != 0) {
            cCoreSave *s2 = &D_00569B70;

            self->unk15B0 = 0;
            cCoreSave_addGameLevelPoint(s2, -0x140);
            if (s0 != 0)
                func_0012C0F8(self, (int)(s0->unk76C * 30.0f));
            if (self->base.hp <= 0) {
                cSnd *g = &D_005FEE00;

                self->base.hp = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, self, 0, 0, 0, 0);
                cSnd_DieDemoStart(g);
                cCoreSave_addGameLevelPoint(s2, -0x3E8);
                self->base.motionFlags |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
            }
            func_0012C348(self, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */












#include "godhand/vu0.h"
#include "godhand/player.h"

__attribute__((section(".text.func_0025C010")))
void func_0025C010(cEm00 *self)
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
        func_002A8578(self, EM_RES_REC(p, 0x1074), EM_RES_REC(p, 0x1078),
                      0, 0.0f, 0, 0);
        self->timerA = 0x2A;
        self->unk56E = 0xF;
        (self->step)++;
        self->unk16EC = 0;
    }
        /* fallthrough */
    case 1:
        if (self->unk56E != 0) {
            cVec *p;
            char *q;

            (self->unk56E)--;
            p = self->pos;
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (self->timerA != 0) {
            if (--self->timerA <= 0) {
                cGameObjVt *vt;

                vt = cGameObj_vt((cGameObj *)self);
                vt->unkAC((char *)self + vt->unkA8Delta, 0x32, s1, 1, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 10.0f);
            }
        }
        if (moveMotion(self) != 0) {
            if (self->hp <= 0) {
                self->mode = 2;
                self->phase = 4;
                self->step = 0;
            } else {
                self->mode = 1;
                self->phase = 0x16;
                self->step = 2;
            }
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }
    self->seqFlags |= 0x400;
}
