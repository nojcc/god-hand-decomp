/* NON_MATCHING func_0013DF70 (sn-2.95.3-136): same length as retail, 6 instructions differ; retail forms self + i * 0x50 once, stores f40/h44 at 0xD0/0xD4 from it and copies it to s0 for the delay-slot store, ours folds the 0x90 into s0. */
#include "include_asm.h"
#include "godhand/cCockGetPoint.h"

#ifdef NON_MATCHING

/* Set up the eight marker displays (id 0x12), each with f40 = 0.00724635 and h44 = 1. */
void func_0013DF70(cCockGetPoint *self)
{
    unsigned short i;

    for (i = 0; i < MARKER_NUM; i++) {
        cIDBase_initialize(&self->rec[i].id, 1, 0x12);
        (self->rec + i)->id.f40 = 0.00724635f;
        (self->rec + i)->id.h44 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013DF70);
#endif
