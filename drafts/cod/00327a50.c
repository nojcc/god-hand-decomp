/* NON_MATCHING func_00327A50: cygnus-2.96: store order of stat/sj/size in the init block */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct AdxSj AdxSj;

typedef struct AdxSjVtbl {
    char unk0[0x24];
    int (*getNumData)(AdxSj *sj, int id);   /* 0x24 */
} AdxSjVtbl;

struct AdxSj {
    AdxSjVtbl *vt;
};

typedef struct AdxSjEnt {
    unsigned char used;     /* 0x00 */
    unsigned char stat;     /* 0x01 */
    unsigned char unk2;     /* 0x02 */
    unsigned char unk3;
    AdxSj *sj;           /* 0x04 */
    int a0;                 /* 0x08 */
    int a1;                 /* 0x0C */
    int size;               /* 0x10 */
    int nsct;               /* 0x14 */
    int dat0;               /* 0x18 */
    int dat1;               /* 0x1C */
    char unk20[0xC];
    int sctlen;             /* 0x2C */
    int nsct2;              /* 0x30 */
    char unk34[0xC];
    int dat2;               /* 0x40 */
    unsigned char unk44;    /* 0x44 */
    char unk45[0x13];
    int unk58;              /* 0x58 */
    int maxsct;             /* 0x5C */
} AdxSjEnt;

extern void Obj3290_Tramp_0033E678_9028(void);
extern void Obj3290_Tramp_0033E690_9040(void);

void func_00327A50(AdxSjEnt *e, int a0, int a1, int size, AdxSj *sj)
{
    int nsct;
    int n;

    Obj3290_Tramp_0033E678_9028();
    nsct = size / 2048;
    e->a0 = a0;
    nsct += (size - nsct * 2048) > 0;
    e->a1 = a1;
    e->sctlen = 0x200;
    e->maxsct = 0xFFFFF;
    e->unk2 = 0;
    e->stat = 1;
    e->sj = sj;
    e->nsct = nsct;
    e->nsct2 = nsct;
    e->size = size;
    e->unk58 = 0;
    if (sj != 0) {
        n = sj->vt->getNumData(sj, 0);
        n += sj->vt->getNumData(sj, 1);
        e->dat2 = n;
        e->dat0 = n;
        e->dat1 = n;
    }
    e->used = 1;
    e->unk44 = 0;
    Obj3290_Tramp_0033E690_9040();
}
#else
INCLUDE_ASM("asm/nonmatching", func_00327A50);
#endif
