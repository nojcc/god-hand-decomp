/* NON_MATCHING func_003219D0: cygnus: retail keeps 3 separate d[i-1] pointer givs (+s0..s2 saves) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct KeyEnt {
    int unk0[2];
    int key;                    /* 0x08 */
} KeyEnt;

typedef struct KeyList {
    KeyEnt **ent;            /* 0x00 */
    int num;                    /* 0x04 */
} KeyList;

void func_003219D0(KeyList *dst, KeyList *src)
{
    KeyEnt **d;
    KeyEnt *e;
    int ns, nd;
    int i, j;

    ns = src->num;
    if (ns == 0)
        return;
    nd = dst->num;
    d = dst->ent;
    i = nd;
    j = ns;
    do {
        j--;
        e = src->ent[j];
        while (i != 0 && d[i - 1]->key - e->key > 0) {
            d[i + j] = d[i - 1];
            i--;
        }
        d[i + j] = e;
    } while (j != 0);
    dst->num = nd + ns;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003219D0);
#endif
