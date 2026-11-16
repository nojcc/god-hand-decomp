/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/IDPanelScreen.h"

extern void IconScreen_stepGrow(void *this);
extern void func_0013D7B0(void *this);
extern void IconScreen_waitChildDone(void *this);
extern void func_0013DB50(void *this);
extern void CustomIDWork_Main(void *p);

/* Per-frame step of the panel: fill ent, run the step, hide three entries while the
 * save flag is set, run the five CustomIDWorks and move both displays. */
__attribute__((section(".text.func_0013D540")))
void func_0013D540(IDPanelScreen *self) {
    unsigned short i;
    int j;
    cIDBaseObj *second;
    CustomIDWork *p;

    for (i = 0; i < 11; i++) {
        self->ent[i] = cIDBase_getIDWork(&self->base, i);
    }

    switch (self->step) {
    case 0:
        IconScreen_stepGrow(self);
        break;
    case 1:
        func_0013D7B0(self);
        break;
    case 2:
        IconScreen_waitChildDone(self);
        break;
    }

    if ((D_00569B70.data->flags & 0x04000000) != 0) {
        self->ent[1]->flags |= IDENT_FLAG_NO_DRAW;
        self->ent[4]->flags |= IDENT_FLAG_NO_DRAW;
        self->ent[0]->flags |= IDENT_FLAG_NO_DRAW;
        func_0013DB50(self);
    }

    second = &self->base2;
    p = self->cw;
    for (j = 4; j >= 0; j--) {
        CustomIDWork_Main(p);
        p++;
    }
    cIDBase_move(second);
    cIDBase_move(&self->base);
}
