/* NON_MATCHING func_00320948 (sn-2.95.3-136): same size, 25 insns differ: block layout and the alias loop match, but retail copies i into a2 at entry (as if the loop variable were a separate local from the parameter) and keeps the entry-pointer temp in v0, so registers differ throughout.
 * Tried: index while loop, type-pointer loop, hoisted types base with an if/else result. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int base;
    char pad04[0x18 - 0x04];
    long ent[0x50];
    char pad298[0x29C - 0x298];
    signed char type[1];
} Tbl320;

extern int func_003A7B48(void);

int func_00320948(int i, Tbl320 *t)
{
    signed char *types = t->type;
    signed char *p = &types[i];
    int r;

    while (*p == 2) {
        i = (int)t->ent[i];
        p = &types[i];
    }
    if (*p == 1)
        r = t->base + *(int *)&t->ent[i];
    else
        r = func_003A7B48();
    return r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00320948);
#endif
