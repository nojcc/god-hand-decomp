/* TU: classFADE - recovered C++ class. sn-2.95.3-136, -O0, as=sn: retail built this object
 * unoptimised; the extra returns give retail's extra jumps to the epilogue. classFADE_start is
 * in sa_classfade_start.c. */
#include "godhand/classFADE.h"

__attribute__((section(".text.classFADE_kill")))
void classFADE_kill(register classFADE *self)
{
    self->state = 0;
    return;
    return;
}

__attribute__((section(".text.classFADE_status")))
int classFADE_status(register classFADE *self)
{
    return self->state;
    return;
    return;
}

__attribute__((section(".text.classFADE_setOt")))
void classFADE_setOt(register classFADE *self, int ot, int pri)
{
    self->otMin = ot;
    self->otMax = pri;
    return;
    return;
}
