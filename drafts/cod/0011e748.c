/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cCamera.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cVec.h"
#include "godhand/gameWork.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/sceVu0.h"

#define ROOM_CATCH_A    0x303   /* the catch happens at a fixed point */
#define ROOM_CATCH_B    0x4F    /* the catch happens at the origin */
#define ROOM_CATCH_C    0x804   /* the catch happens just above the origin */

extern void CallWithAndClearField698_12AC28(char *a0);
extern void func_0012B928(char *a0);
extern void MtxInitRotY(void *a0, float angle);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *obj);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern short func_0012C0F8(void *a0, int a1);
extern void func_0012C348(int a0, unsigned int a1);
extern void cSnd_DieDemoStart(void *a0);

/* A two-hit catch of the player: step 0 puts the enemy 2.8 behind the catch
 * point (the player's position, or a fixed point in three rooms) and the
 * player in front of it facing back, and starts the first hold; step 2 the
 * second. The first motion-end bit of each hold hits the player once, for 5
 * and then 50 times the player's damage scale; the second hit kills the
 * player when it empties the hit points (death sound and demo) and plays the
 * plain hit sound otherwise.
 * Two words over retail: the second add copies &ofs and &tmp_ into new
 * registers where retail reuses the ones the first add set up. */
__attribute__((section(".text.func_0011E748")))
void func_0011E748(cEm00 *self)
{
    float mtx[16];
    cVec pos;
    cVec ofs;
    CVEC_TEMPS;
    pl00 *pl;

    pl = self->catchPl;
    CVEC_ZERO(pos);
    CVEC_ZERO(ofs);
    self->objFlags |= 0x10000;
    self->hitFlash = 5.0f;
    self->unk15F4 |= 0x2000;
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    switch (self->step) {
    case 0:
        CallWithAndClearField698_12AC28((char *)self);
        func_0012B928((char *)self);
        switch (D_007474A0.room) {
        default:
            CVEC_ASSIGN(pos, self->pos);
            break;
        case ROOM_CATCH_A:
            pos.x = 87.0f;
            pos.y = 3.0f;
            pos.z = -39.0f;
            break;
        case ROOM_CATCH_C:
            pos.x = 0.0f;
            pos.y = 1.01f;
            pos.z = 0.0f;
            break;
        case ROOM_CATCH_B:
            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.z = 0.0f;
            break;
        }
        ofs.z = -2.8f;
        ofs.x = 0.0f;
        ofs.y = 0.0f;
        MtxInitRotY(mtx, self->rot.y);
        cVec_applyMatrix(&ofs, mtx);
        CVEC_SET_ADD(*self->pos, &pos, &ofs);
        ofs.x = -0.1445f;
        ofs.z = 0.9874f;
        ofs.y = 0.0f;
        cVec_applyMatrix(&ofs, mtx);
        CVEC_SET_ADD(*pl->base.pos, self->pos, &ofs);
        pl->base.rot.y = self->rot.y + 3.1415927f;
        pl->base.rot.y = Adjust_theta(pl->base.rot.y);
        cEm00_GetPlMotion(pl, 0x19, 0.0f, 0.0f);
        self->gotoFlags = 1;
        self->followTimer = 60;
        self->step++;
        self->stepVar.count = 0;
    case 1:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if ((self->moveFlags & 1) && self->stepVar.count == 0) {
            self->stepVar.count = 1;
            cCoreSave_addGameLevelPoint(&D_00569B70, -160);
            if (pl != 0) {
                func_0012C0F8(self, (int)(pl->unk76C * 5.0f));
            }
            func_0012C348((int)self, 2);
        }
        break;
    case 2:
        cEm00_GetPlMotion(pl, 0x1A, 0.0f, 0.0f);
        self->gotoFlags = 1;
        self->stepVar.count = 0;
        self->followTimer = 60;
        cCoreSave_addGameLevelPoint(&D_00569B70, 100);
        self->step++;
    case 3:
        func_00124EC0(self);
        if (moveMotion(self) != 0) {
            if (self->vital > 0) {
                pl00_clearMotionCam(self, 0, 0);
                self->mode = 1;
                self->phase = 4;
                self->step = 0;
                self->stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if ((self->moveFlags & 1) && self->stepVar.count == 0) {
            self->stepVar.count = 1;
            cCoreSave_addGameLevelPoint(&D_00569B70, -320);
            if (pl != 0) {
                func_0012C0F8(self, (int)(pl->unk76C * 50.0f));
            }
            func_0012C348((int)self, 2);
            if (self->vital <= 0) {
                self->vital = 0;
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD6, self, 0, 0, 0, 0);
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -1000);
                self->unk434 |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
            }
        }
        break;
    }
}
