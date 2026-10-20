/* NON_MATCHING func_0033A8D0: 1 insn: retail fills the open-check delay slot non-annulled (bnez + sltiu), ours bnel; computing ch<4 early gives bne but in v1; void/int/variadic decls no change */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Seg33A8D0 {
    int addr;
    int size;
} Seg33A8D0;

typedef struct Node33A8D0 {
    struct Node33A8D0 *next;
    int unk04;
    Seg33A8D0 seg;
} Node33A8D0;

typedef struct Ctx33A8D0 {
    char pad00[4];
    signed char open;
    signed char merge;
    char pad06[0x14 - 6];
    Node33A8D0 *free;
    Node33A8D0 *list[4];
    void (*cb)(int arg, int err);
    int arg;
} Ctx33A8D0;

extern char D_00455BD8[];
extern char D_00455C08[];
extern char D_00455CC8[];
extern char D_00455CD8[];
extern void func_0033A048(char *fmt, char *where);

void func_0033A8D0(Ctx33A8D0 *c, unsigned int ch, Seg33A8D0 *s)
{
    Node33A8D0 **pp;
    Node33A8D0 *n;

    if (c == 0) {
        func_0033A048(D_00455CC8, D_00455BD8);
        return;
    }
    if (c->open == 0) {
        func_0033A048(D_00455CD8, D_00455C08);
        return;
    }
    if (ch >= 4) {
        goto fail;
    }
    if (s->size <= 0 || s->addr == 0) {
        return;
    }
    pp = &c->list[ch];
    n = 0;
    while (*pp != 0) {
        n = *pp;
        pp = &n->next;
    }
    if (c->merge == 1 && n != 0 && n->seg.addr + n->seg.size == s->addr) {
        n->seg.size += s->size;
        return;
    }
    n = c->free;
    if (n == 0) {
    fail:
        if (c->cb != 0) {
            c->cb(c->arg, -3);
        }
        return;
    }
    n->seg = *s;
    c->free = n->next;
    n->next = 0;
    *pp = n;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033A8D0);
#endif
