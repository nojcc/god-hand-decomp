/* sn-2.95.3-136: func_002F3F30, reach slot init: copy the two reach volumes to the global, scale the reach radius, validate the slot indices and latch them when in reach. */

typedef struct {
    char pad0[0x13C];
    float a[4];
    float b[4];
    float reach;                        /* 0x15C */
    char pad160[0x18C - 0x160];
    signed char idxA;                   /* 0x18C */
    signed char idxB;                   /* 0x18D */
} Sub2F3F30;

typedef struct {
    char pad0[0x110];
    Sub2F3F30 *sub;
    char pad114[0x2B0 - 0x114];
    short idxA;
    short idxB;
    char pad2B4[4];
    float reach;                        /* 0x2B8 */
} Obj2F3F30;

typedef struct {
    char pad0[0x254];
    float b[4];
    unsigned char stateB;
    char pad265[3];
    float a[4];
    unsigned char stateA;
} Glob2F3F30;

extern Glob2F3F30 *D_005CAFF0;
extern char D_0044F038[];
extern char D_0044F058[];
extern void func_002D9F68(Obj2F3F30 *o, char *fmt, int v);
extern int ReachObj_isWithinReach(Obj2F3F30 *o);

__attribute__((section(".text.func_002F3F30")))
int func_002F3F30(Obj2F3F30 *o)
{
    *(float *)((char *)D_005CAFF0 + 0x268) = o->sub->a[0];
    *(float *)((char *)D_005CAFF0 + 0x26C) = o->sub->a[1];
    *(float *)((char *)D_005CAFF0 + 0x270) = o->sub->a[2];
    *(float *)((char *)D_005CAFF0 + 0x274) = o->sub->a[3];
    *(float *)((char *)D_005CAFF0 + 0x254) = o->sub->b[0];
    *(float *)((char *)D_005CAFF0 + 0x258) = o->sub->b[1];
    *(float *)((char *)D_005CAFF0 + 0x25C) = o->sub->b[2];
    *(float *)((char *)D_005CAFF0 + 0x260) = o->sub->b[3];
    o->reach = o->sub->reach * 1000.0f;
    o->idxA = o->sub->idxA;
    o->idxB = o->sub->idxB;
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
