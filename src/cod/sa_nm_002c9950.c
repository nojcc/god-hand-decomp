/* NON_MATCHING func_002C9950 (sn): 24 diffs: register allocation in both sort passes (t0/a2/a3 roles) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Item2C9950 {
    char pad0[0x14];
    short key;
    char pad16[0x24 - 0x16];
} Item2C9950;

typedef struct List2C9950 {
    Item2C9950 *items;
    char pad4[0x10 - 4];
    unsigned int count;
    signed char order[1];
} List2C9950;

void func_002C9950(List2C9950 *s)
{
    unsigned int i;
    int swapped;
    signed char t;

    if (s->items == 0 || s->count == 0)
        return;
    do {
        swapped = 0;
        for (i = 0; i < s->count - 1; i++) {
            t = s->order[i];
            if (s->items[s->order[i + 1]].key < s->items[t].key) {
                s->order[i] = s->order[i + 1];
                swapped = 1;
                s->order[i + 1] = t;
            }
        }
        if (!swapped)
            break;
        for (; i >= 2; i--) {
            t = s->order[i];
            if (s->items[t].key < s->items[s->order[i - 1]].key) {
                s->order[i] = s->order[i - 1];
                swapped = 1;
                s->order[i - 1] = t;
            }
        }
    } while (swapped);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C9950);
#endif
