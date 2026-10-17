/* NON_MATCHING func_003219D0 (loop-giv): cygnus: retail keeps 3 separate d[i-1] pointer givs (+s0..s2 saves); do/for/while/key-temp variants all give 49-51 words */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Ent3219D0 {
    int unk0[2];
    int key;                    /* 0x08 */
} Ent3219D0;

typedef struct List3219D0 {
    Ent3219D0 **ent;            /* 0x00 */
    int num;                    /* 0x04 */
} List3219D0;

void func_003219D0(List3219D0 *dst, List3219D0 *src)
{
    Ent3219D0 **d;
    Ent3219D0 *e;
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
