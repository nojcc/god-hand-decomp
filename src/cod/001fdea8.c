/* NON_MATCHING func_001FDEA8: loop3 s0/s1 swap and v1/a0 swap around c[1] flag store; inline clearC + split counters i/j/k */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad[0x60];
} PoolEntA;

typedef struct {
    char pad[0x70];
} PoolEntB;

typedef struct {
    char pad0[0x49];
    unsigned char flag;
    char pad4A[0x60 - 0x4A];
} PoolEntC;

typedef struct {
    char pad0[0x2C];
    unsigned short id;
    char pad2E[0x40 - 0x2E];
} PoolEntD;

typedef struct {
    PoolEntA a[160];
    PoolEntB b[256];
    PoolEntC c[2];
} EntPool;

extern PoolEntD D_00569B80[160];
extern PoolEntD D_0056C380[512];
extern void func_001FCDB8(PoolEntA *);
extern void ResetObjectFields_1FCDE8(PoolEntB *);
extern void ClearFields_20_24_28_30_1FC7F8(PoolEntD *);

static inline void clearC(PoolEntC *c)
{
    c->flag = 0;
}

void func_001FDEA8(EntPool *o)
{
    PoolEntA *a;
    PoolEntD *d;
    unsigned int i;
    unsigned int j;
    unsigned int k;

    a = o->a;
    do {
        func_001FCDB8(a);
        a++;
    } while (a < &o->a[160]);
    for (i = 0; i < 256; i++) {
        ResetObjectFields_1FCDE8(&o->b[i]);
    }
    clearC(&o->c[0]);
    clearC(&o->c[1]);
    for (j = 0, d = D_00569B80; j < 160; j++, d++) {
        ClearFields_20_24_28_30_1FC7F8(d);
        d->id = j;
    }
    for (k = 0, d = D_0056C380; k < 512; k++, d++) {
        ClearFields_20_24_28_30_1FC7F8(d);
        d->id = k;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FDEA8);
#endif
