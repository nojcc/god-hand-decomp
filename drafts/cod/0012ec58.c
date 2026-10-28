/* sn-2.95.3-136 */
#include "include_asm.h"

typedef struct ListNodeVt {
    char unk00[8];
    short dtorDelta;                    /* 0x08 */
    short pad0A;
    void (*dtor)(void *self, int flags);    /* 0x0C */
} ListNodeVt;

typedef struct ListNode {
    struct ListNode *next;              /* 0x00 */
    char unk04[0x5C - 0x04];
    ListNodeVt *vt;                     /* 0x5C */
} ListNode;

typedef struct ListOwner {
    char unk000[0x190];
    ListNode *first;                    /* 0x190 */
    int count;                          /* 0x194 */
} ListOwner;

/* Still differs from retail: retail pads the search loop with a nop after the
 * branch-likely delay slot (the R5900 short-loop pad); neither assembler adds it here. */
#ifdef NON_MATCHING
/* func_0012EC58: unlink node from the owner's list, delete it and count it out; nothing when it is not listed. */
__attribute__((section(".text.func_0012EC58")))
void func_0012EC58(ListOwner *self, ListNode *node)
{
    ListNode *prev;
    ListNode *cur;

    prev = 0;
    for (cur = self->first; cur != 0; cur = cur->next) {
        if (node == cur)
            break;
        prev = cur;
    }
    if (cur == 0)
        return;
    if (cur != self->first)
        prev->next = cur->next;
    else
        self->first = cur->next;
    if (cur != 0)
        cur->vt->dtor((char *)cur + cur->vt->dtorDelta, 3);
    self->count--;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012EC58);
#endif
