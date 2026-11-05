/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cCamManager.h"
#include "godhand/heapArena.h"
#include "godhand/CustomIDWork.h"


/* clone */

/* Constructor: no object, every animation stopped. */
__attribute__((section(".text.CustomIDWork__ctor")))
CustomIDWork *CustomIDWork__ctor(CustomIDWork *self) {
    self->unk00 = 0;
    self->localFlags = 0;
    self->offsFlags = 0;
    self->colorFlags = 0;
    self->scaleFlags = 0;
    self->obj = 0;
    return self;
}

/* clone */

__attribute__((section(".text.CustomIDWork_SetColorAnimNormal_2D68D8")))
void CustomIDWork_SetColorAnimNormal_2D68D8(int a0, int a1, int a2, int a3) {
    if (*(int*)((char*)a0 + 0x4) != 0) {
        a3 = a3 & 0xFFFF;
        *(int*)((char*)a0 + 0x50) = a1;
        *(int*)((char*)a0 + 0x48) = 3;
        *(int*)((char*)a0 + 0x54) = a2;
        *(short*)((char*)a0 + 0x58) = a3;
        if (a3 == 0) {
            *(short*)((char*)a0 + 0x58) = 1;
        }
        *(short*)((char*)a0 + 0x5A) = 0;
    }
}

/* clone */


/* Destructor: frees self when bit 0 of the flags is set. */
__attribute__((section(".text.CustomIDWork__dtor")))
void CustomIDWork__dtor(CustomIDWork *self, int flags) {
    if (flags & 1) {
        __builtin_delete(self);
    }
}

/* clone */



__attribute__((section(".text.Poker_SetPokerCamera")))
void Poker_SetPokerCamera(int a0, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(&D_00463050, 0);
    *(int *)(a0 + 0x304C) = (int)&D_00463050.subScr;
    dst1 = &D_00463050.subScr.eye.x;
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(*(int *)(a0 + 0x304C) + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}

/* clone */



__attribute__((section(".text.cArea_HitCheck")))
int cArea_HitCheck(unsigned char *a0) {
    switch (a0[1]) {
    case 1:
        return func_001F85D0();
    case 2:
        return func_001F8810();
    }
    return 0;
}

/* clone */

__attribute__((section(".text.cCoreSave_setCasinoTicketNum")))
void cCoreSave_setCasinoTicketNum(cCoreSave *self, int num) {
    if (!self->data)
        return;
    self->data->casinoTicketNum = num;
    if (self->data->casinoTicketNum > CORESAVE_KEY_MAX)
        self->data->casinoTicketNum = CORESAVE_KEY_MAX;
    if (self->data->casinoTicketNum < 0)
        self->data->casinoTicketNum = 0;
}
