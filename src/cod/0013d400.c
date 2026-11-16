#include "godhand/IDPanelScreen.h"

extern void func_002AC9B8(void *self, cIDBaseEnt *w, int a2);
extern void CustomIDWork_Main(CustomIDWork *cw);

/* Start the panel: cache and reset its 11 entries, hide entry 4, then start the five
 * CustomIDWorks on the second display. */
__attribute__((section(".text.func_0013D400")))
void func_0013D400(IDPanelScreen *obj)
{
    unsigned short i;
    int j, k;

    obj->step = 0;
    for (i = 0; i < 11; i++) {
        cIDBase_initIDWork(obj, i);
        obj->ent[i] = cIDBase_getIDWork(&obj->base, i);
        func_002AC9B8(obj, obj->ent[i], 0);
    }
    cIDBase_restartAnim(&obj->base);
    obj->on = 1;
    obj->ent[4]->f70[2] = 0.0f;
    obj->ent[4]->sclX = 0.0f;
    cIDBase_move(&obj->base);
    cIDBase_restartAnim(&obj->base2);
    for (j = 0; j < 5; j++) {
        CustomIDWork_Initialize(&obj->cw[j], cIDBase_getIDWork(&obj->base2, j));
        CustomIDWork_SetDisp(&obj->cw[j], 0);
    }
    for (k = 0; k < 5; k++)
        CustomIDWork_Main(&obj->cw[k]);
    cIDBase_move(&obj->base2);
    obj->flashStep = 0;
}
