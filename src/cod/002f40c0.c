/* sn-2.95.3-136: reach slot latch (0x2F40C0). */
#include "godhand/reachObj.h"

extern void func_002FBED0(ReachObj *o);
extern void UpdateObjByIndexedOp_2FBE50(ReachObj *o);

__attribute__((section(".text.func_002F40C0")))
void func_002F40C0(ReachObj *o)
{
    int changed;
    unsigned char old;

    func_002FBED0(o);
    changed = 0;
    if (o->idxA == -1 && ReachObj_isWithinReach(o)) {
        changed = D_005CAFF0->stateA != 1;
        D_005CAFF0->stateA = 2;
    }
    if (o->idxB == -1 && ReachObj_isWithinReach(o)) {
        old = D_005CAFF0->stateB;
        D_005CAFF0->stateB = 2;
        if (old != 1) {
            changed = 1;
        }
    }
    if (changed) {
        if (o->idxA == -1) {
            *(float *)((char *)D_005CAFF0 + 0x268) = o->vol->a[0];
            *(float *)((char *)D_005CAFF0 + 0x26C) = o->vol->a[1];
            *(float *)((char *)D_005CAFF0 + 0x270) = o->vol->a[2];
            *(float *)((char *)D_005CAFF0 + 0x274) = o->vol->a[3];
        }
        if (o->idxB == -1) {
            *(float *)((char *)D_005CAFF0 + 0x254) = o->vol->b[0];
            *(float *)((char *)D_005CAFF0 + 0x258) = o->vol->b[1];
            *(float *)((char *)D_005CAFF0 + 0x25C) = o->vol->b[2];
            *(float *)((char *)D_005CAFF0 + 0x260) = o->vol->b[3];
        }
    }
    if (o->idxA != -1 && o->idxB != -1) {
        UpdateObjByIndexedOp_2FBE50(o);
    }
}
