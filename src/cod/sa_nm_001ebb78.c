/* NON_MATCHING func_001EBB78 (sn,loop-biv,inline-bool): retail keeps i-- at loop bottom (continues use bnel/beql with the decrement in the likely slot) and andi-truncates the countdown result; ours moves i-- to the top and drops the andi */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int unk0;
    int timer;
    float step;
    int v[6];
} MotParam1EBB78;

typedef struct {
    void *obj;
    int pad4;
    MotParam1EBB78 p;
    int pad2C;
    unsigned int flags;
    char pad34[0xC];
} MotEnt1EBB78;

typedef struct {
    char pad[0x5C];
    MotEnt1EBB78 ent[5];
} Obj1EBB78;

extern void cOm71_SetMotionRun(void *obj);
extern void SetMotionStep(void *obj, float step);

static inline unsigned char countDown(int *t)
{
    int r;

    if (*t != 0) {
        (*t)--;
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

void func_001EBB78(Obj1EBB78 *o)
{
    MotEnt1EBB78 *e = o->ent;
    MotParam1EBB78 p;
    int i = 4;
    long t;

    do {
        t = e->flags;
        if (((t >> 1) & 1) == 1) {
            continue;
        }
        if (countDown(&e->p.timer) == 0) {
            continue;
        }
        p = e->p;
        e->flags |= 2;
        cOm71_SetMotionRun(e->obj);
        SetMotionStep(e->obj, p.step);
    } while (e++, --i >= 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EBB78);
#endif
