/* NON_MATCHING func_003B7400 (ee-2.9-991111): STOP: stores $gp (sw $gp,0x2C); only reachable via gp.h inline-asm GetGp, excluded by real-C rule; also flags reload after it */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Alarm3B7400 {
    int unk0;
    int unk4;
    int id;
    int flags;
    char pad10[0x10];
    long time;
    void *handler;
    void *gp;
    void *arg;
} Alarm3B7400;

typedef struct {
    char pad0[0x1C];
    int cur;
    Alarm3B7400 *head;
} Sys3B7400;

extern Sys3B7400 D_003FBE90;
extern void *_gp;
extern Alarm3B7400 *func_003B6E40(Alarm3B7400 *a);
extern void func_003B6DB8(Alarm3B7400 *a);
extern long iGetTimerSystemTime(void);
extern void SetNextComp(long t);

int func_003B7400(int id, long time, void *handler, void *arg)
{
    Alarm3B7400 *a = (Alarm3B7400 *)(((unsigned int)id >> 10) << 6);
    Alarm3B7400 *n;

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
