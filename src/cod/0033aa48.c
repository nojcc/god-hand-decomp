/* NON_MATCHING func_0033AA48 (cygnus-2.96: ): dbr fills init-test bnez slot with sltiu as likely (bnel) vs retail non-likely */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SjMemBuf {
    int ptr;
    int len;
} SjMemBuf;

typedef struct SjMemNode {
    struct SjMemNode *next;
    int pad4;
    SjMemBuf buf;
} SjMemNode;

typedef struct SjMemLists {
    char pad0[0xC];
    SjMemNode *free;
    SjMemNode *head[4];
} SjMemLists;

typedef struct SjMemQueue {
    char pad0[4];
    signed char init;
    signed char mode;
    char pad6[2];
    SjMemLists l;
    void (*cb)(int arg, int err);
    int cbArg;
} SjMemQueue;

extern char D_00455CE8[];
extern char D_00455BD8[];
extern char D_00455CF8[];
extern char D_00455C08[];
extern void func_0033A048(char *fmt, char *fn);

void func_0033AA48(SjMemQueue *q, unsigned int ch, SjMemBuf *b)
{
    SjMemNode *n;
    int len;
    int ptr;

    if (q == 0) {
        func_0033A048(D_00455CE8, D_00455BD8);
        return;
    }
    if (q->init == 0) {
        func_0033A048(D_00455CF8, D_00455C08);
        return;
    }
    if (ch >= 4)
        goto err;
    len = b->len;
    if (len <= 0)
        return;
    ptr = b->ptr;
    if (ptr == 0)
        return;
    n = q->l.head[ch];
    if (q->mode == 1 && n != 0 && ptr + len == n->buf.ptr) {
        n->buf.ptr = ptr;
        n->buf.len += len;
        return;
    }
    n = q->l.free;
    if (n == 0) {
err:
        if (q->cb != 0)
            q->cb(q->cbArg, -3);
        return;
    }
    n->buf = *b;
    q->l.free = n->next;
    n->next = 0;
    n->next = q->l.head[ch];
    q->l.head[ch] = n;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033AA48);
#endif
