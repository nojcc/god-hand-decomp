/* NON_MATCHING func_003066D0: for each of n entities (stride 0x2F0) owned by o (or unowned when o is null), resolve the target object, build a handler with func_00300458, initialise it with func_00303A30 and run its virtual check; destroy it and return 0 on failure.
* Retail compares the counter against a lui/ori 0xFFFFFFFF sentinel and advances e in the continue delay slots; unsigned n instead eliminates the counter (83). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    short delta;
    short pad;
    int (*fn)(void *self);
} HandlerVtEnt;

typedef struct {
    char pad0[0x18];
    HandlerVtEnt check;
} HandlerVtbl;

typedef struct {
    char pad0[0xF0];
    HandlerVtbl *vt;
} Handler;

typedef struct {
    char pad0[0xBE];
    signed char state;
    char padBF[0x128 - 0xBF];
    unsigned char kind;
    char pad129[0x136 - 0x129];
    unsigned char owner;
    char pad137[0x2A0 - 0x137];
    int packedId;
    char pad2A4[0x2F0 - 0x2A4];
} HandlerEnt;

typedef struct {
    char pad0[0x48];
    int flags;
    char pad4C[0x74 - 0x4C];
    unsigned char id;
} HandlerOwner;

extern void *cEvent_getObjPtrByPackedId(int id);
extern Handler *func_00300458(int kind);
extern int func_00303A30(Handler *h, HandlerEnt *e, void *obj, int a3, HandlerOwner *o, int t1, int t2, unsigned short t3);
extern void func_003005D8(Handler *h);

int func_003066D0(int n, HandlerEnt *e, void *def, int a3, HandlerOwner *o, int t1, int t2, unsigned short t3)
{
    void *obj;
    Handler *h;

    while (n-- != 0) {
        if (o != 0) {
            if (o->id != e->owner) {
                goto next;
            }
        } else if (e->owner != 0) {
            goto next;
        }
        obj = def;
        if (o != 0 && (o->flags & 8)) {
            obj = cEvent_getObjPtrByPackedId(e->packedId);
        }
        if (obj == 0 && e->state != -1 && e->state != -4) {
            return 0;
        }
        h = func_00300458(e->kind);
        if (h == 0) {
            return 0;
        }
        if (func_00303A30(h, e, obj, a3, o, t1, t2, t3) == 0 ||
            h->vt->check.fn((char *)h + h->vt->check.delta) == 0) {
            func_003005D8(h);
            return 0;
        }
    next:
        e++;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003066D0);
#endif
