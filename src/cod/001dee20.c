/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot1.h"
#include "godhand/cCamManager.h"
#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/PanelObj.h"


/* clone */


__attribute__((section(".text.func_001DEE20")))
void func_001DEE20(PanelObj *self) { cIDBase_trans(&self->id); }

/* clone */


__attribute__((section(".text.func_001DEE40")))
void func_001DEE40(PanelObj *self, int number) { CustomIDWork_SetNumber(&self->elem[15], number); }

/* clone */



__attribute__((section(".text.func_001DF048")))
void func_001DF048(PanelObj *self, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin(&self->elem[0x2], x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim(&self->elem[0x2]);
    }
}

/* clone */



__attribute__((section(".text.func_001DF0F0")))
void func_001DF0F0(PanelObj *self, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin(&self->elem[0x4], x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim(&self->elem[0x4]);
    }
}

/* Switch to the sub-screen camera, keep it in the first slot machine's subCam and copy eye and target into it. */
__attribute__((section(".text.func_001E32E8")))
void func_001E32E8(Slot1 *self, float *eye, float *target) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(&D_00463050, 0);
    self->subCam = &D_00463050.subScr;
    dst1 = &D_00463050.subScr.eye.x;
    if (eye != dst1) {
        dst1[0] = eye[0];
        dst1[1] = eye[1];
        dst1[2] = eye[2];
    }
    dst2 = &self->subCam->target.x;
    if (dst2 != target) {
        dst2[0] = target[0];
        dst2[1] = target[1];
        dst2[2] = target[2];
    }
}

/* clone */



__attribute__((section(".text.func_001E3388")))
void func_001E3388(void) {
    cCamManager_setPlCamera(&D_00463050, 0);
}

/* clone */



/* Slot2 camera set-up: switch to the sub-screen camera, remember its record
 * and copy the two view positions into it. */
__attribute__((section(".text.func_001E6870")))
void func_001E6870(Slot2 *self, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(&D_00463050, 0);
    self->camera = (int)&D_00463050.subScr;
    dst1 = &D_00463050.subScr.eye.x;
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(self->camera + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}

/* clone */



__attribute__((section(".text.func_001E6910")))
void func_001E6910(void) {
    cCamManager_setPlCamera(&D_00463050, 0);
}

/* clone */


__attribute__((section(".text.func_001E7470")))
void func_001E7470(SlotUi *self, int no, int show)
{
	CustomIDWork *p;
	int i;

	if (show != 0) {
		if (no == SLOTUI_MARK_NUM) {
			p = self->mark;
			for (i = SLOTUI_MARK_NUM - 1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->mark[no], 1);
		}
	} else {
		if (no == SLOTUI_MARK_NUM) {
			p = self->mark;
			for (i = SLOTUI_MARK_NUM - 1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->mark[no], 0);
		}
	}
}

/* clone */


__attribute__((section(".text.func_001E7538")))
void func_001E7538(SlotUi *self, int no, int show)
{
	CustomIDWork *p;
	int i;

	if (show != 0) {
		if (no == SLOTUI_BET_NUM) {
			p = self->bet;
			for (i = SLOTUI_BET_NUM - 1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->bet[no], 1);
		}
	} else {
		if (no == SLOTUI_BET_NUM) {
			p = self->bet;
			for (i = SLOTUI_BET_NUM - 1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->bet[no], 0);
		}
	}
}
