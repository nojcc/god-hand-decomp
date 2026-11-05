/* TU: cCamManager [camera] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cCamManager.h"

/* Make the player camera current, saving the previous camera and mode. */
__attribute__((section(".text.cCamManager_setPlCamera")))
void cCamManager_setPlCamera(cCamManager *self, unsigned char blend)
{
    if (self->mode != CAMMGR_MODE_PLAYER && self->mode != CAMMGR_MODE_HOLD) {
        if (blend) {
            func_00138CA8(self, &self->player, D_005CAFF0, blend);
        }
        self->prevMode = self->mode;
        self->prevCamera = (struct cCamera *)CAMMGR_CUR_CAMERA_WORD;
        D_005CAFF0 = &self->player;
        self->mode = CAMMGR_MODE_PLAYER;
    }
}


/* Make the motion camera current, saving the previous camera and mode. */
__attribute__((section(".text.cCamManager_setMotCamera")))
void cCamManager_setMotCamera(cCamManager *self, unsigned char blend)
{
    if (self->mode != CAMMGR_MODE_MOTION && self->mode != CAMMGR_MODE_HOLD) {
        if (blend) {
            func_00138CA8(self, &self->motion, D_005CAFF0, blend);
        }
        self->prevMode = self->mode;
        self->prevCamera = (struct cCamera *)CAMMGR_CUR_CAMERA_WORD;
        D_005CAFF0 = &self->motion;
        self->mode = CAMMGR_MODE_MOTION;
    }
}


/* Make the sub-screen camera current and reset it, saving the previous camera and mode. */
__attribute__((section(".text.cCamManager_setSubScrCamera")))
void cCamManager_setSubScrCamera(cCamManager *self, unsigned char blend)
{
    if (self->mode != CAMMGR_MODE_SUBSCR && self->mode != CAMMGR_MODE_HOLD) {
        if (blend) {
            func_00138CA8(self, &self->subScr, D_005CAFF0, blend);
        }
        self->prevMode = self->mode;
        self->prevCamera = (struct cCamera *)CAMMGR_CUR_CAMERA_WORD;
        D_005CAFF0 = &self->subScr;
        cCamera_reset(&self->subScr);
        self->mode = CAMMGR_MODE_SUBSCR;
    }
}
