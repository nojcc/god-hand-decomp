/* sn-2.95.3-136 */
#include "godhand/cIDBaseScreen.h"

extern float D_0041E898[2];

/* Per frame: run the current phase and move the rows; while open, count the timer down and spin the gauge on the extra displays. */
__attribute__((section(".text.func_00145238")))
void func_00145238(cIDBaseScreen *self)
{
    cIDBaseObj *a;
    cIDBaseObj *b;
    cIDBaseEnt *e;
    unsigned short i;
    float x;
    float y;

    switch (self->phase) {
    case 0:
        func_00145410(self);
        break;
    case 1:
        func_00145460(self);
        break;
    case 2:
        func_00145810(self);
        break;
    case 3:
        func_00145FC8(self);
        break;
    case 4:
        func_00146190(self);
        break;
    }
    for (i = 0; i < SCR_ROW_NUM; i++)
        cIDBase_move(&self->row[i].id);
    if (self->phase != 2)
        return;
    self->timer--;
    if ((short)self->timer < 0)
        self->timer = 0;
    a = &self->extraA.id;
    b = &self->extraB.id;
    e = cIDBase_getIDWork(a, 0);
    x = D_0041E898[0];
    e->posX = x;
    e = cIDBase_getIDWork(a, 0);
    y = D_0041E898[1];
    e->posY = y;
    cIDBase_getIDWork(a, 1)->rotSpeed = (float)(short)self->timer * 6.28f / (float)D_003BD70C;
    cIDBase_getIDWork(a, 2)->msg = 0x30F2;
    cIDBase_getIDWork(b, 0)->posX = x;
    cIDBase_getIDWork(b, 0)->posY = y;
    cIDBase_move(a);
    cIDBase_move(b);
}
