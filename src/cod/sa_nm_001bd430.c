/* NON_MATCHING func_001BD430 (sn,inline-range,movn): range-check inline: retail branches (a2=0; if v>=lo a2=v<hi) where ours if-converts to movn; retail loop walks a1 pointer with count in t1 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad[0x2FE];
    unsigned short kind;
} Ent1BD430;

typedef struct {
    char pad0[0x34];
    Ent1BD430 *list[8];
    unsigned int count;
} List1BD430;

typedef struct {
    char pad0[0x630];
    unsigned short found;
    char pad632[2];
    Ent1BD430 *target;
    char pad638[0x644 - 0x638];
    List1BD430 *list;
} Obj1BD430;

extern void *func_003A52F0(void *dst, int c, int n);

static inline int inRange(int v, int lo, int hi)
{
    int r = 0;

    if (v >= lo) {
        r = v < hi;
    }
    return r;
}

void func_001BD430(Obj1BD430 *o)
{
    List1BD430 *l;
    unsigned int i;
    int v;

    if (o->list == 0) {
        o->found = 0;
        o->target = 0;
        return;
    }
    if (o->list->list[0] == 0) {
        o->target = 0;
        o->found = 0;
    } else {
        for (i = 0; i < o->list->count; i++) {
            v = o->list->list[i]->kind;
            if (inRange(v, 0x100, 0x1FF) == 1 || inRange(v, 0x200, 0x300) == 1) {
                o->found++;
                o->target = o->list->list[i];
                break;
            }
        }
    }
    l = o->list;
    func_003A52F0(l->list, 0, 0x20);
    l->count = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001BD430);
#endif
