/* sn-2.95.3-136 matched TU. */

#include "godhand/cRoomSave.h"
#include "godhand/criStm.h"
#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/DogRace.h"
#include "godhand/ColiseumEmSelect.h"

extern cRoomSaveData D_005E9CB8[ROOMSAVE_PAGE_NUM];

/* Build the 0x6F custom-ID works of the coliseum pick display, then hide all of them. */







__attribute__((section(".text.InitUiIdWorksAndShowAll")))
void InitUiIdWorksAndShowAll(ColiseumEmDisp *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x15, 0);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < COLISEUMEM_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    SetCustomIDDispOneOrAll_1F4778(self, COLISEUMEM_ELEM_NUM, 0);
}

/* Build the 6 custom-ID works of a UI object, then run its three setup steps. */









__attribute__((section(".text.InitDogRaceUiIdWorks")))
void InitDogRaceUiIdWorks(DogRaceUi *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x14, 2);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < DOGRACE_UI_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    Panel_hideIcons(self);
    func_001EDC28(self, 0);
    func_001ED700(self, DOGRACE_UI_ELEM_NUM, 0);
}

/* Build the 0x1D custom-ID works of a UI object, run its setup steps, then show all of them. */









__attribute__((section(".text.InitDogRaceListIdWorks")))
void InitDogRaceListIdWorks(DogRaceList *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x14, 1);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < DOGRACE_LIST_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    func_001EE2A8(self, 0);
    func_001EE2C8(self, 0);
    CustomIDWork_SetDisp(&self->elem[0], 0);
    SetCustomIDDispOneOrAll_1EE1C0(self, DOGRACE_LIST_ELEM_NUM, 0);
}

/* Build the 0x2D custom-ID works of a UI object, set four message numbers, hide the first work and run two setup steps. */









__attribute__((section(".text.InitDogRaceResultIdWorks")))
void InitDogRaceResultIdWorks(DogRaceResult *self)
{
    int i;

    cIDBase_initialize(&self->id, 0x14, 0);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < DOGRACE_RESULT_ELEM_NUM; i++) {
        CustomIDWork_Initialize(&self->elem[i], cIDBase_getIDWork(&self->id, i));
    }
    CustomIDWork_SetMessNo(&self->elem[29], 0x101A);
    CustomIDWork_SetMessNo(&self->elem[43], 0x101A);
    CustomIDWork_SetMessNo(&self->elem[30], 0x101B);
    CustomIDWork_SetMessNo(&self->elem[44], 0x101B);
    CustomIDWork_SetDisp(&self->elem[8], 0);
    CustomIDWork_setDispAllButEight(self, DOGRACE_RESULT_ELEM_NUM, 0);
    func_001ED490(self, 0);
}

/* Boot reset: clear the seven pages, the spare page, and forget the current page. */
__attribute__((section(".text.cRoomSave_systemInit")))
void cRoomSave_systemInit(cRoomSave *self) {
    func_003A52F0(D_005E9CB8, 0, sizeof(D_005E9CB8));
    func_003A52F0(&self->spare, 0, sizeof(self->spare));
    self->data = 0;
}
