/* cygnus-2.96 */
/*
 * NON_MATCHING: same length as retail; 3 instructions differ. In the
 * playing branch retail adds 1 to baseCount and then adds the count; here
 * gcc sums baseCount and the count first and adds 1 last.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criSj.h"

#define ADXT_STAT_DECODING  3
#define ADXT_STAT_PREP      4
#define ADXT_STAT_PLAYING   5
#define ADXT_SYNC_LIMIT_MS  60.0f

/* The ADXT handle as the time query reads it. */
typedef struct AdxtTimeHn {
    signed char used;           /* 0x00 */
    signed char stat;           /* 0x01 */
    char pad2[2];
    void *sjd;                  /* 0x04 */
    char pad8[0x72 - 0x8];
    signed char vsyncFrozen;    /* 0x72 the vsync clock is not counting */
    char pad73[0x88 - 0x73];
    int ofs;                    /* 0x88 added to every count */
    char pad8C[0x9C - 0x8C];
    unsigned int baseCount;     /* 0x9C count at baseVsync */
    int baseVsync;              /* 0xA0 */
} AdxtTimeHn;

extern int D_003C7418;          /* vsync counter */
extern int D_003D1408;          /* the vsync clock is in use */
extern int D_003D142C;
extern int D_003D1454;          /* vsync time scale */
extern float D_003D1458;        /* audio minus vsync time, ms */
extern char D_004520B0[];

extern void func_0032A018(AdxtTimeHn *adxt, int *ncount, int *tscale);
extern int Obj3270_GetVia4_Obj33C8_18_77E8(void *sjd);
extern int Obj3270_GetVia4_Obj33C8_14_7788(void *sjd);
extern int Obj3270_GetVia4_0033CEF0_77B8(void *sjd);
extern int Obj0000_PostInc_D_003D1428_32A148(void);

/* CRI ADXT_GetTime on the vsync clock: count from the vsync counter while
 * decoding, and resynchronise to the sample clock when the two drift more
 * than 60 ms apart. */
__attribute__((section(".text.func_0032A1B0")))
void func_0032A1B0(AdxtTimeHn *adxt, int *ncount, int *tscale)
{
    int nsmpl;
    int sfreq;

    if (adxt == 0 || ncount == 0 || tscale == 0) {
        func_0033F130(D_004520B0);
        return;
    }
    if (D_003D1408 == 0) {
        func_0032A018(adxt, ncount, tscale);
        return;
    }
    D_003D1458 = 0.0f;
    if (adxt->stat == ADXT_STAT_DECODING || adxt->stat == ADXT_STAT_PREP) {
        if (adxt->vsyncFrozen == 0) {
            *ncount = (D_003C7418 - adxt->baseVsync) * 100 + adxt->baseCount;
        } else {
            *ncount = adxt->baseCount;
        }
        func_0032A018(adxt, &nsmpl, &sfreq);
        D_003D1458 = ((float)nsmpl / sfreq - (float)*ncount / D_003D1454) * 1000.0f;
        if (D_003D1458 > ADXT_SYNC_LIMIT_MS || D_003D1458 < -ADXT_SYNC_LIMIT_MS) {
            if (D_003D142C == 1) {
                int use = D_003D1408;

                D_003D1408 = 0;
                func_0032A1B0(adxt, &nsmpl, &sfreq);
                D_003D1408 = use;
                Obj0000_PostInc_D_003D1428_32A148();
            }
            adxt->baseCount = (float)nsmpl / sfreq * D_003D1454;
            adxt->baseVsync = D_003C7418;
        }
    } else if (adxt->stat == ADXT_STAT_PLAYING) {
        nsmpl = Obj3270_GetVia4_Obj33C8_18_77E8(adxt->sjd);
        sfreq = Obj3270_GetVia4_Obj33C8_14_7788(adxt->sjd);
        nsmpl = nsmpl * (16 / Obj3270_GetVia4_0033CEF0_77B8(adxt->sjd));
        *ncount = (float)nsmpl / sfreq * D_003D1454;
        *ncount = adxt->baseCount + 1 + *ncount;
    } else {
        *ncount = 0;
    }
    *ncount += adxt->ofs;
    *tscale = D_003D1454;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0032A1B0);
#endif
