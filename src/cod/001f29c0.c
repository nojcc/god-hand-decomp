/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/CustomIDPanel.h"

/* Show (disp nonzero) or hide work id of the panel, or every work when id is CIDPANEL_WORK_NUM. */
__attribute__((section(".text.SetCustomIDDispOneOrAll_1F29C0")))
void SetCustomIDDispOneOrAll_1F29C0(CustomIDPanel *self, int id, int disp)
{
	CustomIDWork *p;
	int i;

	if (disp != 0) {
		if (id == CIDPANEL_WORK_NUM) {
			p = self->work;
			for (i = CIDPANEL_WORK_NUM - 1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->work[id], 1);
		}
	} else {
		if (id == CIDPANEL_WORK_NUM) {
			p = self->work;
			for (i = CIDPANEL_WORK_NUM - 1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p++;
			}
		} else {
			CustomIDWork_SetDisp(&self->work[id], 0);
		}
	}
}
