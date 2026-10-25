/* sn-2.95.3-136 */
/* Differs from retail (6 insns): retail returns obj from the list search
 * through the same block as the link path (beql to the exit, the return value
 * set after the two link stores), and its assembler pads the three-instruction
 * search loop with a nop before the backward bnez. The records are the views
 * src/cod/001f60d8.c keeps locally (Pool, PoolObj, the pool vtable). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct PoolObj {
    unsigned int flags;                 /* 0x00 */
    struct PoolObj *next;               /* 0x04 */
} PoolObj;

typedef struct PoolVtEntInit {
    short delta;
    short index;
    void (*pfn)(void *self, PoolObj *obj, int size, unsigned int no);
} PoolVtEntInit;

typedef struct PoolVtEntTake {
    short delta;
    short index;
    int (*pfn)(void *self, PoolObj *obj, int flag);
} PoolVtEntTake;

typedef struct PoolVt {
    char unk00[0x20];
    PoolVtEntInit init;                 /* 0x20 method 4 */
    char unk28[0x10];
    PoolVtEntTake take;                 /* 0x38 method 7 */
} PoolVt;

typedef struct Pool {
    char *objs;                         /* 0x00 */
    unsigned int num;                   /* 0x04 */
    int size;                           /* 0x08 bytes per object */
    char unk0C[4];
    PoolObj *used;                      /* 0x10 */
    char unk14[4];
    PoolVt *vt;                         /* 0x18 */
} Pool;

#define POOLOBJ_BUSY    0x603         /* any of these: the slot is taken */

/* Take the first free object of pool: set it up through methods 4 and 7
 * and put it on the used list unless it is already there. Returns it, or 0
 * when no object is free or method 7 refuses it. */
__attribute__((section(".text.create")))
PoolObj *create(Pool *pool, int flag)
{
    unsigned int i;
    PoolObj *obj;
    PoolObj *p;

    for (i = 0; i < pool->num; i++) {
        obj = (PoolObj *)(pool->objs + pool->size * i);
        if (obj->flags & POOLOBJ_BUSY) {
            continue;
        }
        pool->vt->init.pfn((char *)pool + pool->vt->init.delta, obj, pool->size, i);
        if (pool->vt->take.pfn((char *)pool + pool->vt->take.delta, obj, flag) == 0) {
            return 0;
        }
        p = pool->used;
        while (p != 0) {
            if (p == obj) {
                return obj;
            }
            p = p->next;
        }
        obj->next = pool->used;
        pool->used = obj;
        return obj;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", create);
#endif
