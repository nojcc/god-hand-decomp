/* sn-2.95.3-136 */
/* Only the R5900 short-loop pad nop between the beql and the bnel of the
 * room-table search differs: retail's assembler padded this two-exit loop,
 * ee-as and the SN assembler here don't. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cRoomSave.h"
#include "godhand/gameWork.h"
#include "godhand/criStm.h"

extern cRoomSaveRow D_003C26C0[];
extern cRoomSaveData D_005E9CB8[ROOMSAVE_PAGE_NUM];

/* Points the room save at the current room's page, or at its cleared spare
 * page when the room has none; page 0 starts cleared unless the save keeps it. */
__attribute__((section(".text.func_002BEBC8")))
void func_002BEBC8(cRoomSave *self, unsigned short room)
{
    cRoomSaveRow *row = D_003C26C0;

    while (row->room != ROOMSAVE_NO_PAGE && row->room != room) {
        row++;
    }
    if (row->page == ROOMSAVE_NO_PAGE) {
        func_003A52F0(&self->spare, 0, sizeof(cRoomSaveData));
        self->data = &self->spare;
    } else {
        self->data = &D_005E9CB8[row->page];
    }
    self->page = row->page;
    if (self->page == 0 && !(D_00747A24 & 0x4000000)) {
        func_003A52F0(self->data, 0, sizeof(cRoomSaveData));
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BEBC8);
#endif
