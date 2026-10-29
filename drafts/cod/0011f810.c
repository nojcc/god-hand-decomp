/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/capVu0.h"
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

#define ROOM_CATCH_NEAREST  0x605   /* the player is moved to the nearer of two points */

extern void CallWithAndClearField698_12AC28(char *a0);
extern void func_0012B928(char *a0);
extern void MtxInitRotY(void *a0, float angle);
extern void func_001299F0(cGameObj *self, cGameObj *held, cVec *offset, int how, float turn);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *obj);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern short func_0012C0F8(void *a0, int a1);
extern void func_0012C348(int a0, unsigned int a1);
extern void cSnd_DieDemoStart(void *a0);

/* A one-hit catch of the player: in room 0x605 step 0 moves the player to
 * the nearer of two points and puts the enemy in front of it, facing it;
 * elsewhere func_001299F0 places the two. The player is lifted 3.78 above
 * the enemy, and for 15 frames the enemy moves with the player's velocity.
 * The first motion-end bit hits the player for 100 times its damage scale,
 * killing it (death sound and demo) when the hit points run out.
 * One word over retail: retail forms &best in a saved register where it is
 * zeroed and keeps it for the nearest-point search, which moves every saved
 * register after it; the prologue stores are scheduled differently. */
__attribute__((section(".text.func_0011F810")))
void func_0011F810(cEm00 *self)
{
    cVec pts[2];
    cVec best;
    float mtx[16];
    cVec ofs;
    cVec at;
    CVEC_TEMPS;
    pl00 *pl;
    float dist;
    float minDist;
    unsigned int i;

    CVEC_INIT_XYZ(pts[0], -0.5f, 0.0f, -11.0f);
    CVEC_INIT_XYZ(pts[1], -1.8f, 0.0f, -32.0f);
    pl = self->catchPl;
    CVEC_ZERO(best);
    CVEC_ZERO(ofs);
    self->objFlags |= 0x10000;
    self->hitFlash = 5.0f;
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    self->unk15F4 |= 0x2000;
    switch (self->step) {
    case 0:
        CallWithAndClearField698_12AC28((char *)self);
        func_0012B928((char *)self);
        if (D_007474A0.room == ROOM_CATCH_NEAREST) {
            CVEC_ASSIGN(best, &pts[0]);
            minDist = 1.0e16f;
            for (i = 0; i < 2; i++) {
                dist = capVu0MagnitudeSqXZ(pl->base.pos, &pts[i]);
                if (minDist < dist) {
                    continue;
                }
                minDist = dist;
                CVEC_ASSIGN(best, &pts[i]);
            }
            CVEC_PUT(pl->base.pos, best);
            MtxInitRotY(mtx, pl->base.rot.y);
            ofs.x = -0.2067f;
            ofs.z = 4.6215f;
            ofs.y = 0.0f;
            CVEC_APPLY(mtx, &ofs);
            CVEC_INIT_ADD(at, &ret_, pl->base.pos);
            CVEC_PUT(self->pos, at);
            self->rot.y = pl->base.rot.y + 3.1415927f;
            self->rot.y = Adjust_theta(self->rot.y);
        } else {
            CVEC_INIT_XYZ(at, -0.2067f, 0.0f, 4.6215f);
            func_001299F0((cGameObj *)self, &pl->base, &at, 0, 3.1415927f);
        }
        if (pl != 0) {
            pl->base.pos->y = self->pos->y + 3.7757f;
        }
        cEm00_GetPlMotion(pl, 0x20, 0.0f, 0.0f);
        self->gotoFlags = 1;
        self->followTimer = 15;
        self->step++;
    case 1:
        if (self->followTimer != 0 && pl != 0) {
            self->followTimer--;
            CVEC_ADD_TO(*self->pos, &pl->base.vel);
        }
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
        if ((self->moveFlags & 1) && self->gotoFlags != 0) {
            self->gotoFlags = 0;
            cCoreSave_addGameLevelPoint(&D_00569B70, -320);
            if (pl != 0) {
                func_0012C0F8(self, (int)(pl->unk76C * 100.0f));
            }
            if (self->vital <= 0) {
                self->vital = 0;
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD6, self, 0, 0, 0, 0);
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -1000);
                self->unk434 |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, self, 0, 0, 0, 0);
            }
            func_0012C348((int)self, 2);
        }
        break;
    }
}
