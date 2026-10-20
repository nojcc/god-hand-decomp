/* NON_MATCHING func_001FC810: when the owner is active, bubble-sort its child list by ascending key, then copy up to max active children into out.
* Retail loads the child count into one register and copies it into a second that feeds the outer bound (two daddu copies plus a nop, 3 words more); a separate cnt local, an inline sort helper, unsigned cnt and a comma reload all allocate one register (82). */
#include "include_asm.h"

#ifdef NON_MATCHING
#define ENT_F_ACTIVE_MASK  0x203
#define ENT_F_ACTIVE       0x3
#define CHILD_MAX          20

typedef struct ChildEnt ChildEnt;

typedef struct ChildList {
    ChildEnt *item[CHILD_MAX];         /* 0x00 */
    float key[CHILD_MAX];               /* 0x50 */
    int count;                          /* 0xA0 */
} ChildList;

struct ChildEnt {
    int flags;                          /* 0x00 */
    char unk04[0x34];
    ChildList child;              /* 0x38 */
};

typedef struct ChildOwner {
    char unk00[0x28];
    ChildEnt *owner;                   /* 0x28 */
} ChildOwner;

static inline ChildEnt *ChildList_get(ChildList *l, unsigned int i)
{
    if (i >= l->count)
        return 0;
    return l->item[i];
}

static inline int Ent_isActive(ChildEnt *e)
{
    return (e->flags & ENT_F_ACTIVE_MASK) == ENT_F_ACTIVE;
}

__attribute__((section(".text.func_001FC810")))
void func_001FC810(ChildOwner *self, ChildEnt **out, unsigned short max)
{
    ChildEnt *p;
    ChildList *l;
    unsigned short n;
    unsigned int i;
    unsigned int j;
    int cnt;
    int k;

    p = self->owner;
    n = 0;
    if (p == 0 || !Ent_isActive(p))
        return;
    l = &p->child;
    cnt = l->count;
    if (cnt <= 0)
        return;
    if (cnt >= 2) {
        for (i = 0; i < cnt - 1; i++) {
            for (j = i; j < (cnt = l->count); j++) {
                if (l->key[i] > l->key[j]) {
                    ChildEnt *te = l->item[i];
                    float tk = l->key[i];

                    l->item[i] = l->item[j];
                    l->key[i] = l->key[j];
                    l->item[j] = te;
                    l->key[j] = tk;
                }
            }
        }
    }
    for (k = 0; k < self->owner->child.count; k++) {
        ChildEnt *e = ChildList_get(&self->owner->child, k);

        if (e != 0 && Ent_isActive(e) == 1) {
            out[n++] = e;
            if (n >= max)
                return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FC810);
#endif
