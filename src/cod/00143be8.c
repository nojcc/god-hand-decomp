#include "godhand/cIDScreen3.h"
#include "godhand/cIDBase.h"

extern void *Getplayer(void);

/* cIDScreen3 setup: restart every display, keep the first entries of each part, reset the colour. */
__attribute__((section(".text.func_00143BE8")))
void func_00143BE8(cIDScreen3 *obj)
{
    cIDScreen3Part *a = &obj->partA;
    cIDScreen3Part *b = &obj->partB;
    cIDScreen3Part *c = &obj->partC;
    unsigned short i = 0;

    obj->f90 = 0;
    obj->player = Getplayer();
    obj->pulse = IDSCREEN3_PULSE;
    cIDBase_play(&obj->base);
    cIDBase_play(&a->base);
    cIDBase_move(&a->base);
    cIDBase_play(&b->base);
    cIDBase_move(&b->base);
    cIDBase_play(&c->base);
    for (; i < IDSCREEN3_ENT_NUM; i++)
        obj->ent[i] = cIDBase_getIDWork(&obj->base, i);
    obj->entA = cIDBase_getIDWork(&obj->partA.base, 0);
    obj->entB = cIDBase_getIDWork(&obj->partB.base, 0);
    obj->entC = cIDBase_getIDWork(&obj->partC.base, 0);
    obj->flag5DD = 0;
    obj->color = IDSCREEN3_COLOR_GREY;
    obj->flag5DC = 0;
}
