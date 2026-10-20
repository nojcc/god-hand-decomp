/* NON_MATCHING func_003356B0: CRI LSC request push.
* The second error message must pass name (keeps the two error tails from cross-jumping) and the previous-slot index needs its own local.
* Remaining: retail stores the entry fields in 0x10, 0x14, 0x1C, 0x18, 0x0C order with arg2 in s6 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct LscReq {
    int id;                             /* 0x00 */
    char *name;                         /* 0x04 */
    int sum;                            /* 0x08 */
    int arg2;                           /* 0x0C */
    int arg3;                           /* 0x10 */
    int arg4;                           /* 0x14 */
    int unk18;                          /* 0x18 */
    int unk1C;                          /* 0x1C */
} LscReq;

typedef struct LscReqQueue {
    char unk00;
    signed char state;                  /* 0x01 */
    char pad02[0x1C - 0x02];
    int tail;                           /* 0x1C */
    int pad20;
    int count;                          /* 0x24 */
    char pad28[0x38 - 0x28];
    LscReq ent[16];                  /* 0x38 */
} LscReqQueue;

extern char D_00454C18[];
extern char D_00454C48[];
extern void func_00335D40(char *fmt, ...);
extern unsigned int strlen(const char *s);

__attribute__((section(".text.func_003356B0")))
int func_003356B0(LscReqQueue *q, char *name, int arg2, int arg3, int arg4)
{
    LscReq *e;
    int prev;
    int t;
    int pi;
    int id;
    unsigned int len;
    unsigned int i;

    if (q == 0) {
        func_00335D40(D_00454C18);
        return -1;
    }
    if (q->count >= 16)
        return -1;
    if (name == 0) {
        func_00335D40(D_00454C48, name);
        return -1;
    }
    e = &q->ent[q->tail];
    e->name = name;
    pi = (q->tail + 15) % 16;
    prev = q->ent[pi].id;
    id = 0;
    if (prev != 0x7FFFFFFF)
        id = prev + 1;
    e->id = id;
    len = strlen(name);
    e->sum = 0;
    for (i = 0; i < len; i++)
        e->sum += ((unsigned char *)name)[i];
    e->arg3 = arg3;
    e->arg4 = arg4;
    e->unk1C = 0;
    e->arg2 = arg2;
    e->unk18 = 0;
    q->tail = (q->tail + 1) % 16;
    q->count++;
    if (q->state == 1)
        q->state = 2;
    return id;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003356B0);
#endif
