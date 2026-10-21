/* NON_MATCHING func_003B7400 (ee-2.9-991111): retail stores $gp into the alarm record (sw $gp,0x2C). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct AlarmEnt {
    int unk0;
    int unk4;
    int id;
    int flags;
    char pad10[0x10];
    long time;
    void *handler;
    void *gp;
    void *arg;
} AlarmEnt;

typedef struct {
    char pad0[0x1C];
    int cur;
    AlarmEnt *head;
} AlarmSys;

extern AlarmSys D_003FBE90;
extern void *_gp;
extern AlarmEnt *func_003B6E40(AlarmEnt *a);
extern void func_003B6DB8(AlarmEnt *a);
extern long iGetTimerSystemTime(void);
extern void SetNextComp(long t);

int func_003B7400(int id, long time, void *handler, void *arg)
{
    AlarmEnt *a = (AlarmEnt *)(((unsigned int)id >> 10) << 6);
    AlarmEnt *n;

    if (id < 0 || (id & 0x3FF) != a->id)
        return 0x80008002;
    if (D_003FBE90.cur == id)
        return 0x80000010;
    if (a->flags & 2) {
        n = func_003B6E40(a);
        if (D_003FBE90.head == a)
            D_003FBE90.head = n;
    }
    a->handler = handler;
    if (handler == 0) {
        a->flags &= ~2;
    } else {
        a->time = time;
        a->flags |= 2;
        a->gp = &_gp;
        a->arg = arg;
        if (a->flags & 1)
            func_003B6DB8(a);
    }
    SetNextComp(iGetTimerSystemTime());
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B7400);
#endif
