/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/DogRace.h"
#include "godhand/ColiseumEmSelect.h"

extern int cIDBase_release();

/* clone */


__attribute__((section(".text.func_001ED660")))
void func_001ED660(DogRaceUi *self) { cIDBase_release(&self->id); }

/* clone */


__attribute__((section(".text.func_001ED6E0")))
void func_001ED6E0(DogRaceUi *self) { cIDBase_trans(&self->id); }

/* clone */


__attribute__((section(".text.func_001ED700")))
void func_001ED700(DogRaceUi *self, int id, int on)
{
	CustomIDWork *p;
	int i;

	if (on != 0) {
		if (id == DOGRACE_UI_ELEM_NUM) {
			p = self->elem;
			for (i = 0x5; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->elem[id], 1);
		}
	} else {
		if (id == DOGRACE_UI_ELEM_NUM) {
			p = self->elem;
			for (i = 0x5; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->elem[id], 0);
		}
	}
}

/* clone */


__attribute__((section(".text.func_001EDF60")))
void func_001EDF60(DogRaceList *self) { cIDBase_release(&self->id); }

/* clone */


__attribute__((section(".text.func_001EE2A8")))
void func_001EE2A8(DogRaceList *self, int number) { CustomIDWork_SetNumber(&self->elem[0x12], number); }

/* clone */


__attribute__((section(".text.func_001EE2C8")))
void func_001EE2C8(DogRaceList *self, int number) { CustomIDWork_SetNumber(&self->elem[0x14], number); }

/* clone */


__attribute__((section(".text.func_001F46E0")))
void func_001F46E0(ColiseumEmDisp *self) { cIDBase_release(&self->id); }

/* clone */


__attribute__((section(".text.func_001F4758")))
void func_001F4758(ColiseumEmDisp *self) { cIDBase_trans(&self->id); }

/* clone */


__attribute__((section(".text.func_001F4B78")))
void func_001F4B78(ColiseumEmDisp *self, int number) { CustomIDWork_SetNumber(&self->elem[2], number); }

/* clone */

__attribute__((section(".text.cCoreSave_addKeyCardNum")))
/* Add to the key card count, clamped to 0..9. */
void cCoreSave_addKeyCardNum(cCoreSave *self, int n) {
    if (!self->data)
        return;
    self->data->keyCardNum += n;
    if (self->data->keyCardNum >= 0xA)
        self->data->keyCardNum = 9;
    if (self->data->keyCardNum < 0)
        self->data->keyCardNum = 0;
}
