/* NON_MATCHING func_0037D1A8 (sn-2.95.3-136, as=sn): 28 words vs 30; the filter chain matches, but retail branches to a separate id-compare block (with two hazard nops) and falls through to return e when id is 0. Goto/nested/drop-reorder variants tried. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    unsigned short active;
    char pad02[2];
    int id;
    char pad08[4];
    unsigned char flags;
    unsigned char groups;
    char pad0E[0x50 - 0x0E];
} GrpEnt;

extern GrpEnt D_0076B9C0[48];

GrpEnt *func_0037D1A8(unsigned char groups, int id)
{
    GrpEnt *e;
    int i;

    for (i = 0; i < 48; i++) {
        e = &D_0076B9C0[i];
        if (e->active == 0)
            continue;
        if (e->flags & 0x10)
            continue;
        if ((e->groups & groups) == 0)
            continue;
        if (id == 0 || e->id == id)
            return e;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037D1A8);
#endif
