/* sn-2.95.3-136: func_002F3F30, reach slot init: copy the two reach volumes to the global, scale the reach radius, validate the slot indices and latch them when in reach. */
#include "godhand/reachObj.h"

extern char D_0044F038[];
extern char D_0044F058[];
extern void func_002D9F68(ReachObj *o, char *fmt, int v);

__attribute__((section(".text.func_002F3F30")))
int func_002F3F30(ReachObj *o)
{
    *(float *)((char *)D_005CAFF0 + 0x268) = o->vol->a[0];
    *(float *)((char *)D_005CAFF0 + 0x26C) = o->vol->a[1];
    *(float *)((char *)D_005CAFF0 + 0x270) = o->vol->a[2];
    *(float *)((char *)D_005CAFF0 + 0x274) = o->vol->a[3];
    *(float *)((char *)D_005CAFF0 + 0x254) = o->vol->b[0];
    *(float *)((char *)D_005CAFF0 + 0x258) = o->vol->b[1];
    *(float *)((char *)D_005CAFF0 + 0x25C) = o->vol->b[2];
    *(float *)((char *)D_005CAFF0 + 0x260) = o->vol->b[3];
    o->reach = o->vol->reach * 1000.0f;
    o->idxA = o->vol->idxA;
    o->idxB = o->vol->idxB;
    if (o->idxA < -1) {
        func_002D9F68(o, D_0044F038, o->idxA);
        return 0;
    }
    if (o->idxB < -1) {
        func_002D9F68(o, D_0044F058, o->idxB);
        return 0;
    }
    if (ReachObj_isWithinReach(o)) {
        if (o->idxA != -1)
            D_005CAFF0->stateA = o->idxA;
        else
            D_005CAFF0->stateA = 0;
        if (o->idxB != -1)
            D_005CAFF0->stateB = o->idxB;
        else
            D_005CAFF0->stateB = 0;
    }
    return 1;
}
