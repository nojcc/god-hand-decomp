/* NON_MATCHING func_00359628: control flow is right (ring-queue span search, hoisted pos<base / pos<wend invariants).
 * Retail holds lt=pos<s in t0 and copies it to v1, copies count to t6 after the blez, and shares one jr/return-i block; ours renumbers registers down by one (no t7 buf) and keeps the -1 return in a different slot. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { unsigned int w[4]; } __attribute__((aligned(8))) QItem;
typedef struct {
    QItem *buf;
    int cap;
    int count;
    int tail;
    int head;
} Queue;

int func_00359628(Queue *q, unsigned int pos, unsigned int base, unsigned int len)
{
    unsigned int wend = base + len;
    int cap = q->cap;
    int i = 0;
    int h = q->head;
    int n = q->count;
    QItem *buf;

    if (n <= 0)
        return -1;
    buf = q->buf;
    do {
        QItem *it = &buf[h];
        unsigned int s = it->w[2];
        unsigned int e = s + it->w[3];
        int lt = pos < s;

        if (e <= wend) {
            if (lt)
                goto next;
            if (pos < e)
                goto found;
        } else {
            if (!lt && pos < wend)
                goto found;
            if (pos >= base && pos < e - len)
                goto found;
        }
    next:
        {
            int nh = h + 1;
            i++;
            if (nh >= cap)
                nh = h - cap + 1;
            h = nh;
        }
    } while (i < n);
    return -1;
found:
    return i;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00359628);
#endif
