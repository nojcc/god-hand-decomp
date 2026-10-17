/* NON_MATCHING func_0033B878 (cygnus,loop,giv-copy,hazard-nops): best 42 (cygnus default/dr): retail keeps a second slot pointer t0 (copied each iteration) used for the name store, hoists &D_00455EF0 into t2 before the loop, puts the name!=0 store as an out-of-line stub, and has two nops between the slot lw and bnel in the loop (ours has none). ee-2.9-991111 is worse (51). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int func; /* 0x0 */
    int arg; /* 0x4 */
    char *name; /* 0x8 */
} CbEnt;
extern CbEnt D_00758620[8][6];
extern char D_00455EC8[];
extern char D_00455EF0[];
extern char D_00455EF8[];
extern void func_0033B790(char *msg);

int func_0033B878(unsigned int grp, int func, int arg, char *name)
{
    CbEnt *ent;
    int i;

    if (grp >= 8) {
        func_0033B790(D_00455EC8);
        return -1;
    }
    ent = D_00758620[grp];
    for (i = 0; i < 6; i++, ent++) {
        if (ent->func == 0) {
            ent->func = func;
            ent->arg = arg;
            if (name == 0)
                ent->name = D_00455EF0;
            else
                ent->name = name;
            break;
        }
    }
    if (i == 6) {
        func_0033B790(D_00455EF8);
        return -1;
    }
    return i;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033B878);
#endif
