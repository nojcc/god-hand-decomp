/* NON_MATCHING func_00359480 (cygnus-2.96): same size, 34 insns but nearly all register renames: layout, reloads and stores match
retail also copies full (a2) into t1 at entry and keeps t + 1 in a0 with a separate n copy in a2, which shifts every register.
* Item must alias the int fields (int[4] aligned(8)) to get the cap/count reloads after the copy. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { int w[4]; } __attribute__((aligned(8))) QItem;
typedef struct {
    QItem *buf;
    int cap;
    int count;
    int tail;
} Queue;

int func_00359480(Queue *q, QItem *it, int *full)
{
    int t;
    int n;
    int t1;

    if (q->count == q->cap) {
        *full = 1;
        return -1;
    }
    t = q->tail;
    t1 = t + 1;
    q->buf[t] = *it;
    n = t1;
    if (t1 >= q->cap)
        n = t - q->cap + 1;
    q->tail = n;
    if (++q->count >= q->cap)
        *full = 1;
    else
        *full = 0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00359480);
#endif
