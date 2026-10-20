/* cygnus-2.96: func_003298F0, CRI ADXT_Destroy: stop the handle, free
 * its streams, joints and amplitude meter, then clear the 0xC8-byte work. */
typedef struct Sj3298F0 Sj3298F0;

typedef struct {
    char pad0[0xC];
    void (*destroy)(Sj3298F0 *sj);
} SjVt3298F0;

struct Sj3298F0 {
    SjVt3298F0 *vt;
};

typedef struct {
    signed char used;           /* 0x00 */
    char pad1[2];
    signed char maxnch;         /* 0x03 */
    void *sjd;                  /* 0x04 */
    void *stm;                  /* 0x08 */
    void *rna;                  /* 0x0C */
    Sj3298F0 *sjf;              /* 0x10 */
    char pad14[4];
    Sj3298F0 *sjo[2];           /* 0x18 */
    char pad20[0x74 - 0x20];
    void *amp;                  /* 0x74 */
    Sj3298F0 *ampsji[2];        /* 0x78 */
    Sj3298F0 *ampsjo[2];        /* 0x80 */
    char pad88[0x94 - 0x88];
    void *lsc;                  /* 0x94 */
} Adxt3298F0;

extern char D_00452010[];
extern void func_0033F130(char *msg);
extern void func_00329848(Adxt3298F0 *adxt);
extern void func_00329870(Adxt3298F0 *adxt);
extern void func_00329898(Adxt3298F0 *adxt);
extern void func_00329ED8(Adxt3298F0 *adxt);
extern void Obj3260_TrampChain_D2D8(void *rna);
extern void func_00326718(void *sjd);
extern void func_003283E8(void *stm, int a1, int a2);
extern void func_00327D90(void *stm);
extern void func_00335500(void *lsc);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void ADXAMP_Destroy(void *amp);
extern void *func_003A52F0(void *d, int c, unsigned int n);

__attribute__((section(".text.func_003298F0")))
void func_003298F0(Adxt3298F0 *adxt)
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
        Sj3298F0 *t = adxt->sjf;

        adxt->sjf = 0;
        t->vt->destroy(t);
    }
    for (i = 0; i < adxt->maxnch; i++) {
        if (adxt->sjo[i] != 0) {
            Sj3298F0 *t = adxt->sjo[i];

            adxt->sjo[i] = 0;
            t->vt->destroy(t);
        }
        if (adxt->ampsji[i] != 0) {
            Sj3298F0 *t = adxt->ampsji[i];

            adxt->ampsji[i] = 0;
            t->vt->destroy(t);
        }
        if (adxt->ampsjo[i] != 0) {
            Sj3298F0 *t = adxt->ampsjo[i];

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
