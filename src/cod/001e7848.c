/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/SlotUi.h"
#include "godhand/cCamManager.h"
#include "godhand/DogRace.h"
#include "godhand/cCamera.h"

extern int cIDBase_release();

/* clone */


__attribute__((section(".text.func_001E7848")))
void func_001E7848(SlotUi *self, int number) { CustomIDWork_SetNumber(&self->mark[3], number); }

/* clone */


__attribute__((section(".text.func_001E7868")))
void func_001E7868(SlotUi *self, int number) { CustomIDWork_SetNumber(&self->mark[4], number); }

/* clone */


__attribute__((section(".text.func_001E7888")))
void func_001E7888(SlotUi *self, int number) { CustomIDWork_SetNumber(&self->mark[5], number); }

/* clone */


__attribute__((section(".text.func_001E78A8")))
void func_001E78A8(SlotUi *self, int number) { CustomIDWork_SetNumber(&self->mark[6], number); }

/* clone */


__attribute__((section(".text.func_001E78C8")))
void func_001E78C8(SlotUi *self, int number) { CustomIDWork_SetNumber(&self->mark[7], number); }

/* clone */


__attribute__((section(".text.func_001E78E8")))
void func_001E78E8(SlotUi *self, int number) { CustomIDWork_SetNumber(&self->mark[8], number); }

/* clone */



__attribute__((section(".text.func_001EB718")))
void func_001EB718(DogRace *self, cVec *eye, cVec *target) {
    cVec *camEye;
    cVec *camTarget;

    cCamManager_setSubScrCamera(&D_00463050, 0);
    self->cam = &D_00463050.subScr;
    camEye = &D_00463050.subScr.eye;
    if (eye != camEye) {
        camEye->x = eye->x;
        camEye->y = eye->y;
        camEye->z = eye->z;
    }
    camTarget = &self->cam->target;
    if (camTarget != target) {
        camTarget->x = target->x;
        camTarget->y = target->y;
        camTarget->z = target->z;
    }
}

/* clone */



__attribute__((section(".text.func_001EB9F8")))
void func_001EB9F8(void) {
    cCamManager_setPlCamera(&D_00463050, 0);
}

/* clone */


__attribute__((section(".text.func_001ECBD0")))
void func_001ECBD0(DogRaceResult *self) { cIDBase_release(&self->id); }

/* clone */


__attribute__((section(".text.func_001ED490")))
void func_001ED490(DogRaceResult *self, int number) { CustomIDWork_SetNumber(&self->elem[37], number); }
