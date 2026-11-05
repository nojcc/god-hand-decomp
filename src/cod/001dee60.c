/* sn-2.95.3-136 matched TU. */
#include "godhand/PanelObj.h"
#include "godhand/CustomIDWork.h"


__attribute__((section(".text.func_001DEE60")))
void func_001DEE60(PanelObj *self, int element, int show) {
    int i;
    if (show) {
        if (element == PANEL_ELEM_ALL) {
            for (i = 0; i < PANEL_ELEM_NUM; i++) {
                if (i != 0) {
                    CustomIDWork_SetDisp(&self->elem[i], 1);
                }
            }
        } else if (element != 0) {
            CustomIDWork_SetDisp(&self->elem[element], 1);
        }
    } else {
        if (element == PANEL_ELEM_ALL) {
            for (i = 0; i < PANEL_ELEM_NUM; i++) {
                if (i != 0) {
                    CustomIDWork_SetDisp(&self->elem[i], 0);
                }
            }
        } else if (element != 0) {
            CustomIDWork_SetDisp(&self->elem[element], 0);
        }
    }
}
