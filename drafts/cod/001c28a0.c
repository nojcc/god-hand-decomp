/* NON_MATCHING func_001C28A0: parts[] range-check idiom (also 1A6FB0, 28EBF0): pointer-param InRange(&i,&lo,&n) with && reproduces the separate index IV + zero-reg lo but adds movz; if-return form + hold[16] gives the stack store and branchy r=slt but loses the index IV (25 diffs) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct EmPart {
    char pad000[0x154];
    int flags;
} EmPart;

typedef struct EmWork {
    char pad000[0x278];
    EmPart **parts;
    char pad27C[0x2B4 - 0x27C];
    unsigned char nparts;
    char pad2B5[0x60C - 0x2B5];
    signed char nflag;
    char pad60D[3];
    short unk610;
} EmWork;

extern void cOmBase_setMeshDispFromLayer(void *self, int layer, int on);

static inline unsigned char InRange1C28A0(const int *v, const int *lo, const int *hi)
{
    if (*v < *lo) {
        return 0;
    }
    return *v < *hi;
}

static inline EmPart *Em1C28A0_part(EmWork *self, int i)
{
    char hold[16];
    int n = self->nparts;
    int lo = 0;

    *(int *)hold = n;
    if (InRange1C28A0(&i, &lo, &n)) {
        return self->parts[i];
    }
    return 0;
}

int func_001C28A0(EmWork *self)
{
    int i;

    self->unk610 = 30;
    cOmBase_setMeshDispFromLayer(self, 0, 1);
    cOmBase_setMeshDispFromLayer(self, 0x40, 0);
    for (i = 1; i < self->nflag && i < self->nparts; i++) {
        Em1C28A0_part(self, i)->flags |= 8;
        Em1C28A0_part(self, i)->flags |= 0x10;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C28A0);
#endif
