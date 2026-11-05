/* sn-2.95.3-136 */
#include "godhand/cCamManager.h"

/* Start on the player camera: set the mode, reset the camera and make it current. */
__attribute__((section(".text.func_00138C70")))
void func_00138C70(cCamManager *self) {
    self->mode = CAMMGR_MODE_PLAYER;
    func_00139090(&self->player);
    D_005CAFF0 = &self->player;
}
