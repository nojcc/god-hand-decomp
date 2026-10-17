/* NON_MATCHING func_00306D18 (sn-2.95.3-136, as=sn): 64 insns, 70 words vs 72; loops match in shape, but retail keeps w in s1 / tail in s0, peels the first node store into the bnel slot, and reloads t.x from the stack for the z copy. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { float x, y, z, w; } PoolVec;

typedef struct PoolNode {
    struct PoolNode *next;
    int f04;
    unsigned char f08;
    unsigned char f09;
    short f0A;
    int f0C;
    short f10;
    short f12;
    int f14;
} PoolNode;

typedef struct {
    PoolNode *head;
    int f04;
    int f08;
    PoolVec *vecs;
    short nvec;
} PoolHead;

typedef struct {
    PoolNode nodes[32];
    int slots[32];
    PoolVec vecs[1000];
    PoolNode tail;
} PoolWork;

extern PoolHead *func_00306F88(PoolWork *base);

static inline void PoolNode_clear(PoolNode *n)
{
    n->next = 0;
    n->f04 = 0;
    n->f08 = 0;
    n->f09 = 0;
    n->f0A = 0;
    n->f10 = 0;
    n->f0C = 0;
    n->f12 = 0;
}

void func_00306D18(PoolWork *w)
{
    PoolNode *n;
    PoolHead *h;
    PoolVec *p;
    unsigned int i;

    p = w->vecs;
    for (i = 0; i < 1000; i++, p++) {
        PoolVec t;
        t.x = 0.0f;
        t.y = 0.0f;
        t.z = 0.0f;
        t.w = 1.0f;
        if (p != &t) {
            p->x = t.x;
            p->z = t.z;
            p->y = t.y;
        }
    }
    n = w->nodes;
    do {
        PoolNode_clear(n);
    } while (++n < &w->nodes[32]);
    for (i = 0; i < 32; i++)
        w->slots[i] = 0;
    h = func_00306F88(w);
    h->vecs = w->vecs;
    h->nvec = 1000;
    n = &w->tail;
    PoolNode_clear(n);
    n->f04 = (int)h;
    h->head = n;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00306D18);
#endif
