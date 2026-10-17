/* NON_MATCHING func_002BAE98 (loop-pad): sn: identical except retail's short no-call unlink loop starts with a nop (errata pad); call_loop_pad/as=sn don't add it, inline nop breaks bnel */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Node2BAE98 Node2BAE98;

typedef struct VtEnt2BAE98 {
    short delta;
    short index;
    void (*fn)(void *self, int arg);
} VtEnt2BAE98;

typedef struct Vtbl2BAE98 {
    VtEnt2BAE98 ent[2];
} Vtbl2BAE98;

struct Node2BAE98 {
    unsigned int flags;         /* 0x00 */
    Node2BAE98 *next;           /* 0x04 */
    Vtbl2BAE98 *vt;             /* 0x08 */
};

typedef struct Mgr2BAE98 {
    char unk0[0xC];
    unsigned char mode;         /* 0x0C */
    Node2BAE98 *head;           /* 0x10 */
} Mgr2BAE98;

static inline int IsLive2BAE98(Node2BAE98 *n)
{
    return (n->flags & 0x201) == 1;
}

static inline void Unlink2BAE98(Mgr2BAE98 *m, Node2BAE98 *n)
{
    Node2BAE98 *p;

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

void func_002BAE98(Mgr2BAE98 *m, Node2BAE98 *n)
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
