/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDPanel.h"

extern void CustomIDWork_Main(CustomIDWork *cw);

/* Run the panel's three animations, then every work and both displays. */
__attribute__((section(".text.func_001F28F0")))
void func_001F28F0(CustomIDPanel *self) {
    CustomIDWork *q;
    cIDBaseObj *r;
    int i;
    int j;

    func_001F2D60(self);
    func_001F3118(self);
    func_001F32A0(self);

    q = self->work;
    /* call in body + closes with bgez -> i >= 0 (padded loop) */
    for (i = CIDPANEL_WORK_NUM - 1; i >= 0; i--) {
        CustomIDWork_Main(q);
        q++;
    }

    cIDBase_move(&self->id);

    r = &self->id2;
    q = self->sub;
    for (j = CIDPANEL_SUB_NUM - 1; j >= 0; j--) {
        CustomIDWork_Main(q);
        q++;
    }

    cIDBase_move(r);
}
