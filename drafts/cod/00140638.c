/* NON_MATCHING func_00140638: retail loads 0x80000000 into v1 in the preceding block and tests with and/beqz (ours folds to bgez); child base addiu lands in beqz delay without copy */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void cIDBase_trans(void *a0);
extern int cCoreSave_getStateBit0(void *a0);
extern int D_00747A24[];
extern char D_00569B70[];

typedef struct {
    char pad0[0x90];
    unsigned int flags;
    char pad94[0xA0 - 0x94];
    int active;
    char padA4[0x358 - 0xA4];
    unsigned char nchild;
    char pad359[3];
    void *child[1];
} ChildFlagObj;

void func_00140638(ChildFlagObj *self)
{
    int *g;
    long t;
    unsigned short i;

    if (self->active == 0) return;
    t = D_00747A24[0];
    if ((((unsigned long)t >> 3) & 1UL) == 1UL) return;
    g = D_00747A24;
    if (g[2] < 0) return;
    if ((self->flags & 0x80000000) == 0) return;
    if (cCoreSave_getStateBit0(D_00569B70) != 0) return;
    for (i = 0; i < self->nchild && self->child[i] != 0; i++) {
        cIDBase_trans(self->child[i]);
    }
    cIDBase_trans(self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00140638);
#endif
