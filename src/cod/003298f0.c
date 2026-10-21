/* cygnus-2.96: func_003298F0, CRI ADXT_Destroy: stop the handle, free
 * its streams, joints and amplitude meter, then clear the 0xC8-byte work. */
#include "godhand/criSj.h"
#include "godhand/criStm.h"

typedef struct {
    signed char used;           /* 0x00 */
    char pad1[2];
    signed char maxnch;         /* 0x03 */
    void *sjd;                  /* 0x04 */
    void *stm;                  /* 0x08 */
    void *rna;                  /* 0x0C */
    SjObj *sjf;              /* 0x10 */
    char pad14[4];
    SjObj *sjo[2];           /* 0x18 */
    char pad20[0x74 - 0x20];
    void *amp;                  /* 0x74 */
    SjObj *ampsji[2];        /* 0x78 */
    SjObj *ampsjo[2];        /* 0x80 */
    char pad88[0x94 - 0x88];
    void *lsc;                  /* 0x94 */
} AdxtObj;

extern char D_00452010[];
extern void func_00329848(AdxtObj *adxt);
extern void func_00329870(AdxtObj *adxt);
extern void func_00329898(AdxtObj *adxt);
extern void func_00329ED8(AdxtObj *adxt);
extern void Obj3260_TrampChain_D2D8(void *rna);
extern void func_00326718(void *sjd);
extern void func_003283E8(void *stm, int a1, int a2);
extern void func_00327D90(void *stm);
extern void func_00335500(void *lsc);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void ADXAMP_Destroy(void *amp);

__attribute__((section(".text.func_003298F0")))
void func_003298F0(AdxtObj *adxt)
{
    int i;

    if (adxt == 0) {
        func_0033F130(D_00452010);
        return;
    }
    func_00329848(adxt);
    func_00329870(adxt);
    func_00329898(adxt);
    if (adxt->used == 1)
        func_00329ED8(adxt);
    if (adxt->rna != 0) {
        void *t = adxt->rna;

        adxt->rna = 0;
        Obj3260_TrampChain_D2D8(t);
    }
    if (adxt->sjd != 0) {
        void *t = adxt->sjd;

        adxt->sjd = 0;
        func_00326718(t);
    }
    if (adxt->stm != 0) {
        void *t = adxt->stm;

        adxt->stm = 0;
        func_003283E8(t, 0, 0);
        func_00327D90(t);
    }
    if (adxt->lsc != 0) {
        void *t = adxt->lsc;

        adxt->lsc = 0;
        func_00335500(t);
    }
    Forward33B658_33E678();
    if (adxt->sjf != 0) {
        SjObj *t = adxt->sjf;

        adxt->sjf = 0;
        t->vt->destroy(t);
    }
    for (i = 0; i < adxt->maxnch; i++) {
        if (adxt->sjo[i] != 0) {
            SjObj *t = adxt->sjo[i];

            adxt->sjo[i] = 0;
            t->vt->destroy(t);
        }
        if (adxt->ampsji[i] != 0) {
            SjObj *t = adxt->ampsji[i];

            adxt->ampsji[i] = 0;
            t->vt->destroy(t);
        }
        if (adxt->ampsjo[i] != 0) {
            SjObj *t = adxt->ampsjo[i];

            adxt->ampsjo[i] = 0;
            t->vt->destroy(t);
        }
    }
    if (adxt->amp != 0) {
        void *t = adxt->amp;

        adxt->amp = 0;
        ADXAMP_Destroy(t);
    }
    func_003A52F0(adxt, 0, 0xC8);
    adxt->used = 0;
    Forward33B670_33E690();
}
