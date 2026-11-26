/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cCamManager.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"
#include "godhand/vu0.h"
#include "godhand/fpu.h"

/* Draw the object solid again. */
static __inline__ void drawSolid(cGameObj *self)
{
    self->tint.w = 1.0f;
    self->objFlags &= ~GAMEOBJ_OBJ_SEE_THROUGH;
}

/* See-through fade for an object that stands between the camera and the player in the ground plane:
 * tint.w becomes the cube of how far past 2.0 it is from the camera, and GAMEOBJ_OBJ_SEE_THROUGH
 * marks it. Objects 0x200-0x2FF stay solid when the camera looks down on ref or isn't the
 * player camera. ref is the point to test, the object's position when 0. */
__attribute__((section(".text.func_002A87E8")))
void func_002A87E8(cGameObj *self, cVec *ref)
{
    unsigned long sys = D_007474A0.flags5E4;
    cVec eye;
    struct cCamera *playerCam;
    cGameObj *player;
    float camDist;
    float refDist;
    float fade;

    if (sys & SYSFLAG_EVENT_RUNNING) {
        drawSolid(self);
        return;
    }
    if ((sys & SYSFLAG_SOFT_EVENT) || ((sys >> SYSFLAG_SOFT_EVENT_BIT) & 1) == 1) {
        drawSolid(self);
    } else {
        playerCam = &D_00463050.player.base;
        player = Getplayer();
        VU0_SQC2_VF0(&eye, 0);
        if (D_005CAFF0 == 0)
            return;
        if (ref == 0)
            ref = self->pos;
        cVec_copy3(&eye, &D_005CAFF0->eye);
        FPU_SQRT_S(camDist, (eye.x - player->pos->x) * (eye.x - player->pos->x)
                            + (eye.z - player->pos->z) * (eye.z - player->pos->z));
        FPU_SQRT_S(refDist, (eye.x - ref->x) * (eye.x - ref->x)
                            + (eye.z - ref->z) * (eye.z - ref->z));
        fade = refDist - 2.0f;
        fade = fade * (fade * fade);
        if (cGameObj_idInRange(self, 0x200, 0x300) & 0xFF) {
            if (ref->y + 1.7f < eye.y)
                fade = 1.0f;
            if (D_005CAFF0 != playerCam)
                fade = 1.0f;
        }
        if (camDist <= refDist || 1.0f <= fade) {
            drawSolid(self);
        } else if (fade < 0.15f) {
            self->tint.w = 0.0f;
            self->objFlags &= ~GAMEOBJ_OBJ_SEE_THROUGH;
        } else {
            self->tint.w = fade;
            self->objFlags |= GAMEOBJ_OBJ_SEE_THROUGH;
        }
    }
}
