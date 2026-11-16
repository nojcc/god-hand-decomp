/* sn-2.95.3-136: draw the object's ID base, then redraw the second one once per active slot (0x143998). */
#include "godhand/cIDBase.h"
#include "godhand/cCockPrintData.h"

/* A cIDBase display with a second one at 0xB0 that is drawn once per active slot. */


__attribute__((section(".text.func_00143998")))
void func_00143998(cCockPrintData *obj)
{
    unsigned short i;
    cIDBaseEnt *w;

    cIDBase_trans(&obj->base);
    i = 0;
    w = cIDBase_getIDWork(&obj->popupBase, 0);
    for (; i < 16; i++) {
        if (obj->on[i] == 1) {
            w->posY = w->src->posY + obj->posYOfs[i];
            w->colorBase.c[3] = obj->alpha[i];
            w->seed = obj->add[i];
            cIDBase_move(&obj->popupBase);
            cIDBase_trans(&obj->popupBase);
        }
    }
}
