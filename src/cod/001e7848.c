/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/SlotUi.h"
#include "godhand/cCamManager.h"
#include "godhand/DogRace.h"

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
void func_001EB718(int a0, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(&D_00463050, 0);
    *(int *)(a0 + 0x200) = (int)&D_00463050.subScr;
    dst1 = &D_00463050.subScr.eye.x;
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(*(int *)(a0 + 0x200) + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
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
