/* cygnus-2.96 */
/*
 * NON_MATCHING: 200 words against retail's 198. Retail shares one
 * func_0033F130 call between the two error paths; here each error path
 * keeps its own call. The stores that set up the buffers are also
 * scheduled in a different order.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criSj.h"
#include "godhand/criStm.h"

#define ADXT_MAX_OBJ     16
#define ADXT_OBUF_SIZE   0x2000          /* samples per channel */
#define ADXT_OBUF_DIST   0x2060
#define ADXT_IBUF_XLEN   0x24
#define ADXT_SCT_SIZE    0x800

typedef struct {
    signed char used;           /* 0x00 */
    char pad1[2];
    signed char maxnch;         /* 0x03 */
    void *sjd;                  /* 0x04 */
    void *stm;                  /* 0x08 */
    void *rna;                  /* 0x0C */
    SjObj *sjf;                 /* 0x10 */
    void *sji;                  /* 0x14 */
    SjObj *sjo[2];              /* 0x18 */
    char *ibuf;                 /* 0x20 */
    int ibufbsize;              /* 0x24 */
    int ibufxlen;               /* 0x28 */
    short *obuf;                /* 0x2C */
    int obufsize;               /* 0x30 */
    int obufdist;               /* 0x34 */
    int svrfreq;                /* 0x38 */
    short maxsct;               /* 0x3C */
    short minsct;               /* 0x3E */
    short outvol;               /* 0x40 */
    short outpan[2];            /* 0x42 */
    short unk46;                /* 0x46 */
    char pad48[0x54 - 0x48];
    int unk54;                  /* 0x54 */
    int unk58;                  /* 0x58 */
    int unk5C;                  /* 0x5C */
    short unk60;                /* 0x60 */
    char pad62[2];
    int unk64;                  /* 0x64 */
    short unk68;                /* 0x68 */
    short unk6A;                /* 0x6A */
    signed char unk6C;          /* 0x6C */
    signed char unk6D;          /* 0x6D */
    char pad6E[0x72 - 0x6E];
    signed char unk72;          /* 0x72 */
    char pad73[0x88 - 0x73];
    int unk88;                  /* 0x88 */
    char pad8C[0x94 - 0x8C];
    void *lsc;                  /* 0x94 */
    char pad98[0xB0 - 0x98];
    char *ibufend;              /* 0xB0 */
    char padB4[0xC8 - 0xB4];
} AdxtObj;

extern AdxtObj D_003C7420[ADXT_MAX_OBJ];
extern char D_00451FB8[];
extern char D_00451FE0[];
extern int D_003D1410;

extern SjObj *func_003395A0(void *buf, int bsize, int xsize);
extern void *func_00327D00(SjObj *sj, int a1);
extern void *func_003265A8(SjObj *sji, int nch, SjObj **sjo);
extern void *Obj3260_Tramp_00337DE0_D2C0(SjObj **sjo, int nch);
extern void *func_003353C0(SjObj *sj);
extern void func_00335580(void *lsc, void *stm);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void func_003298F0(AdxtObj *adxt);
extern void func_0032B6A0(AdxtObj *adxt, int a1);
extern void func_0032AB20(AdxtObj *adxt, int a1);

/* CRI ADXT_Create: take a free handle and carve its output buffers (one per
 * channel) and its input ring buffer out of the work area, then build the
 * streams, decoder and renderer on them. Returns 0 on failure. */
__attribute__((section(".text.func_00329490")))
AdxtObj *func_00329490(int maxnch, void *work, int worksize)
{
    AdxtObj *adxt;
    char *buf;
    int rest;
    int no;
    int i;

    buf = (char *)(((int)work + 0x3F) & ~0x3F);
    rest = worksize - (buf - (char *)work);
    if (maxnch < 0 || work == 0 || worksize < 0) {
        func_0033F130(D_00451FB8);
        return 0;
    }
    no = 0;
    while (no < ADXT_MAX_OBJ && D_003C7420[no].used != 0) {
        no++;
    }
    if (no == ADXT_MAX_OBJ) {
        func_0033F130(D_00451FE0);
        return 0;
    }
    adxt = &D_003C7420[no];
    func_003A52F0(adxt, 0, sizeof(AdxtObj));
    adxt->maxnch = maxnch;
    adxt->obuf = (short *)buf;
    adxt->ibuf = buf + maxnch * ADXT_OBUF_DIST * 2;
    adxt->obufsize = ADXT_OBUF_SIZE;
    adxt->obufdist = ADXT_OBUF_DIST;
    adxt->ibufbsize = (rest - maxnch * ADXT_OBUF_DIST * 2 - 0x124) / ADXT_SCT_SIZE * ADXT_SCT_SIZE;
    adxt->ibufxlen = ADXT_IBUF_XLEN;
    adxt->ibufend = adxt->ibuf + (adxt->ibufbsize + adxt->ibufxlen);
    adxt->sji = 0;
    adxt->sjf = func_003395A0(adxt->ibuf, adxt->ibufbsize, ADXT_IBUF_XLEN);
    if (adxt->sjf == 0) {
        goto fail;
    }
    adxt->stm = func_00327D00(adxt->sjf, 0);
    if (adxt->stm == 0) {
        goto fail;
    }
    for (i = 0; i < maxnch; i++) {
        adxt->sjo[i] = func_003395A0(adxt->obuf + adxt->obufdist * i,
                                     adxt->obufsize * 2,
                                     (adxt->obufdist - adxt->obufsize) * 2);
        if (adxt->sjo[i] == 0) {
            goto fail;
        }
    }
    adxt->sjd = func_003265A8(adxt->sjf, maxnch, adxt->sjo);
    if (adxt->sjd == 0) {
        goto fail;
    }
    adxt->rna = Obj3260_Tramp_00337DE0_D2C0(adxt->sjo, maxnch);
    if (adxt->rna == 0) {
        goto fail;
    }
    adxt->lsc = func_003353C0(adxt->sjf);
    if (adxt->lsc == 0) {
        goto fail;
    }
    func_00335580(adxt->lsc, adxt->stm);
    Forward33B658_33E678();
    adxt->svrfreq = D_003D1410;
    adxt->maxsct = adxt->ibufbsize / ADXT_SCT_SIZE;
    adxt->minsct = adxt->maxsct * 0.85f;
    adxt->outvol = 0;
    for (i = 0; i < maxnch; i++) {
        adxt->outpan[i] = -128;
    }
    adxt->unk46 = 0;
    adxt->unk6C = 1;
    adxt->unk54 = 0;
    adxt->unk58 = 0;
    adxt->unk5C = 0;
    adxt->unk60 = 0;
    adxt->unk64 = 0;
    adxt->unk68 = 0;
    adxt->unk6A = 0;
    adxt->unk6D = 1;
    adxt->unk72 = 0;
    adxt->unk88 = 0;
    func_0032B6A0(adxt, 0);
    func_0032AB20(adxt, 1);
    adxt->used = 1;
    Forward33B670_33E690();
    return adxt;

fail:
    func_003298F0(adxt);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00329490);
#endif
