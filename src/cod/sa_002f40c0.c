/* sn-2.95.3-136: reach slot latch (0x2F40C0). */

typedef struct {
    char pad0[0x13C];
    float a[4];
    float b[4];
} Sub2F40C0;

typedef struct {
    char pad0[0x110];
    Sub2F40C0 *sub;
    char pad114[0x2B0 - 0x114];
    short idxA;
    short idxB;
} Obj2F40C0;

typedef struct {
    char pad0[0x254];
    float b[4];
    unsigned char stateB;
    char pad265[3];
    float a[4];
    unsigned char stateA;
} Glob2F40C0;

extern Glob2F40C0 *D_005CAFF0;
extern void func_002FBED0(Obj2F40C0 *o);
extern int ReachObj_isWithinReach(Obj2F40C0 *o);
extern void UpdateObjByIndexedOp_2FBE50(Obj2F40C0 *o);

__attribute__((section(".text.func_002F40C0")))
void func_002F40C0(Obj2F40C0 *o)
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
            *(float *)((char *)D_005CAFF0 + 0x268) = o->sub->a[0];
            *(float *)((char *)D_005CAFF0 + 0x26C) = o->sub->a[1];
            *(float *)((char *)D_005CAFF0 + 0x270) = o->sub->a[2];
            *(float *)((char *)D_005CAFF0 + 0x274) = o->sub->a[3];
        }
        if (o->idxB == -1) {
            *(float *)((char *)D_005CAFF0 + 0x254) = o->sub->b[0];
            *(float *)((char *)D_005CAFF0 + 0x258) = o->sub->b[1];
            *(float *)((char *)D_005CAFF0 + 0x25C) = o->sub->b[2];
            *(float *)((char *)D_005CAFF0 + 0x260) = o->sub->b[3];
        }
    }
    if (o->idxA != -1 && o->idxB != -1) {
        UpdateObjByIndexedOp_2FBE50(o);
    }
}
