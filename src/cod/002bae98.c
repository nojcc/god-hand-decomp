#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct MgrNode MgrNode;

typedef struct MgrVtEnt {
    short delta;
    short index;
    void (*fn)(void *self, int arg);
} MgrVtEnt;

typedef struct MgrVtbl {
    MgrVtEnt ent[2];
} MgrVtbl;

struct MgrNode {
    unsigned int flags;         /* 0x00 */
    MgrNode *next;           /* 0x04 */
    MgrVtbl *vt;             /* 0x08 */
};

typedef struct NodeMgr {
    char unk0[0xC];
    unsigned char mode;         /* 0x0C */
    MgrNode *head;           /* 0x10 */
} NodeMgr;

static inline int IsLive2BAE98(MgrNode *n)
{
    return (n->flags & 0x201) == 1;
}

static inline void Unlink2BAE98(NodeMgr *m, MgrNode *n)
{
    MgrNode *p;

    p = m->head;
    if (p == n) {
        m->head = n->next;
        n->next = 0;
        return;
    }
    while (p->next != 0) {
        if (p->next == n) {
            p->next = n->next;
            n->next = 0;
            return;
        }
        p = p->next;
    }
}

void func_002BAE98(NodeMgr *m, MgrNode *n)
{
    if (n == 0)
        return;
    if (IsLive2BAE98(n))
        Unlink2BAE98(m, n);
    switch (m->mode) {
    case 0:
        if (IsLive2BAE98(n)) {
            if (n != 0)
                n->vt->ent[1].fn((char *)n + n->vt->ent[1].delta, 3);
            n->flags = 0;
        }
        break;
    case 1:
        n->flags |= 0x600;
        break;
    case 2:
        n->flags |= 0x200;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BAE98);
#endif
