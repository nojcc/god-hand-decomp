/* NON_MATCHING func_001FCBA0: unlink loop: retail reloads p->next in bnel slot with a nop-led loop head; rest of layout matches */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct EffVtbl {
    char pad0[8];
    short delta;
    short padA;
    void (*release)(void *self, int mode);
} EffVtbl;

typedef struct EffNode {
    unsigned int flags;
    struct EffNode *next;
    EffVtbl *vt;
} EffNode;

typedef struct EffMgr {
    char pad0[0xC];
    unsigned char mode;
    char padD[3];
    EffNode *head;
} EffMgr;

typedef struct Node1FD {
    char pad00[0x28];
    EffNode *eff;
    char pad2C[2];
    unsigned char busy;
} Node1FD;

extern EffMgr D_005E8040;

int func_001FCBA0(Node1FD *n)
{
    EffNode *e = n->eff;
    EffNode *p;
    EffNode *q;
    EffMgr *m = &D_005E8040;

    if (e != 0) {
        if (((e->flags & 0x201) ^ 1) == 0) {
            p = m->head;
            if (p == e) {
                m->head = e->next;
                e->next = 0;
            } else {
                goto test;
            found:
                p->next = e->next;
                e->next = 0;
                goto done;
            loop:
                q = p->next;
                if (q == e)
                    goto found;
                p = q;
            test:
                if (p->next != 0)
                    goto loop;
            }
        }
    done:
        switch (m->mode) {
        case 1:
            e->flags |= 0x600;
            break;
        case 0:
            if (((e->flags & 0x201) ^ 1) == 0) {
                if (e != 0)
                    e->vt->release((char *)e + e->vt->delta, 3);
                e->flags = 0;
            }
            break;
        case 2:
            e->flags |= 0x200;
            break;
        }
    }
    n->busy = 0;
    n->eff = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FCBA0);
#endif
