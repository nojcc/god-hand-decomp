/* NON_MATCHING func_0013E0B0 (sn-2.95.3-136) */
#include "include_asm.h"
#include "godhand/cIDBase.h"

#ifdef NON_MATCHING
/* func_0013E0B0, steps the eight sub-objects that have a running timer: collects their eleven ID
 * works, finds the timer's segment in the D_0041E010 key table and adds that segment's slope of the D_0041DFF8
 * curve to work 0's value at 0x3C, then moves the sub-object and advances its timer. */
typedef struct IdSub {
    char pad[0x50];
} IdSub;

typedef struct IdWork {
    char pad00[0x3C];
    float value;                        /* 0x3C */
} IdWork;

typedef struct IdOwner {
    char pad000[0x90];
    IdSub sub[8];                   /* 0x090 */
    IdWork *work[11];               /* 0x310 */
    signed char timer[8];               /* 0x33C */
} IdOwner;

extern unsigned short D_0041E010[];
extern float D_0041DFF8[];

__attribute__((section(".text.func_0013E0B0")))
void func_0013E0B0(IdOwner *o)
{
    unsigned short i;
    unsigned short j;
    IdWork *w;

    for (i = 0; i < 8; i++) {
        if (o->timer[i] == -1)
            continue;
        for (j = 0; j < 11; j++)
            o->work[j] = cIDBase_getIDWork(&o->sub[i], j);
        w = o->work[0];
        for (j = 0; j < 4; j++) {
            if (o->timer[i] < D_0041E010[j])
                break;
        }
        w->value += (D_0041DFF8[j + 1] - D_0041DFF8[j]) / (float)(D_0041E010[j + 1] - D_0041E010[j]);
        cIDBase_move(&o->sub[i]);
        o->timer[i]++;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013E0B0);
#endif
