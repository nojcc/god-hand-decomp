/* NON_MATCHING func_001FCBA0 (sn): unlink loop: retail reloads p->next in bnel slot with a nop-led loop head; rest of layout matches */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct EffVtbl1FCBA0 {
    char pad0[8];
    short delta;
    short padA;
    void (*release)(void *self, int mode);
} EffVtbl1FCBA0;

typedef struct Eff1FCBA0 {
    unsigned int flags;
    struct Eff1FCBA0 *next;
    EffVtbl1FCBA0 *vt;
} Eff1FCBA0;

typedef struct EffMgr1FCBA0 {
    char pad0[0xC];
    unsigned char mode;
    char padD[3];
    Eff1FCBA0 *head;
} EffMgr1FCBA0;

typedef struct Node1FD {
    char pad00[0x28];
    Eff1FCBA0 *eff;
    char pad2C[2];
    unsigned char busy;
} Node1FD;

extern EffMgr1FCBA0 D_005E8040;

int func_001FCBA0(Node1FD *n)
{
    Eff1FCBA0 *e = n->eff;
    Eff1FCBA0 *p;
    Eff1FCBA0 *q;
    EffMgr1FCBA0 *m = &D_005E8040;

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
