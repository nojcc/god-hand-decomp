/* sn-2.95.3-136, -O0, as=sn: classFADE_start. Retail built this object unoptimised (frame pointer, args spilled, self kept in s0 as a register param); the two returns give retail's two jumps to the epilogue. */
extern int D_00747A04;
extern int D_003C1180;
extern unsigned short D_00586B80;

#include "godhand/classFADE.h"

__attribute__((section(".text.classFADE_start")))
void classFADE_start(register classFADE *self, int kind, int mode, unsigned int type,
                     int col, int col2, int time)
{
    self->col = col;
    self->col2 = col2;
    self->kind = kind;
    self->state = mode | 1;
    self->time = time;
    self->time = self->time << D_00747A04;
    self->count = 0;
    self->x = (0x800 - D_003C1180 / 2) << 4;
    self->y = D_00586B80 << 4;
    self->w = 0x2000;
    self->h = 0x1C00;
    switch (type) {
    case 0:
        self->tag = 0x8000000044;
        break;
    case 1:
        self->tag = 0x8000000029;
        break;
    case 2:
        self->tag = 0x80000000A1;
        break;
    }
    classFADE_setOt(self, 7, 1);
    return;
    return;
}
