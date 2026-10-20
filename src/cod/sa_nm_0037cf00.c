/* NON_MATCHING func_0037CF00 (sn-2.95.3-136; STOP near-miss 3): voice allocator over the D_0076C8C0 table. Return a free voice in [base, base+last]; otherwise steal the oldest voice at the lowest priority if the request's priority allows it (equal priority needs flag 0x20). Only diff: retail builds the loop-2 base as (D+0x1E)+base*32 with 0x1E added separately; ours folds it into the lb offset (or into %lo when written as byte arithmetic). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    unsigned short flags;
    char pad2[6];
    int node;
    unsigned int age;
    char pad10[0xE];
    signed char prio;
    char pad1F;
} Voice37CF00;

typedef struct {
    char pad0[6];
    signed char base;
    signed char last;
    signed char prio;
    char pad9[5];
    unsigned short flags;
} Req37CF00;

extern Voice37CF00 D_0076C8C0[];
extern void func_0037D8B8(int node, int arg);

Voice37CF00 *func_0037CF00(Req37CF00 *r)
{
    Voice37CF00 *v;
    Voice37CF00 *best;
    unsigned int age;
    int min;
    int i;

    for (i = 0; i <= r->last; i++) {
        v = &D_0076C8C0[r->base + i];
        if (v->flags == 0) {
            return v;
        }
    }

    min = 0x7F;
    for (i = 0; i <= r->last; i++) {
        v = &D_0076C8C0[r->base + i];
        if (v->prio <= min) {
            min = v->prio;
        }
    }

    if (r->prio < min) {
        return 0;
    }
    if (min == r->prio && !(r->flags & 0x20)) {
        return 0;
    }

    best = 0;
    age = 0;
    for (i = 0; i <= r->last; i++) {
        v = &D_0076C8C0[r->base + i];
        if (v->prio == min && v->age >= age) {
            best = v;
            age = v->age;
        }
    }

    if (best == 0) {
        return 0;
    }
    func_0037D8B8(best->node, -1);
    return best;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037CF00);
#endif
