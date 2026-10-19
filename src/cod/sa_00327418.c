/* cygnus-2.96: same skip-and-copy as func_00327568, but pending lives at 0xA0, the probe
 * uses stream id 0, and each copied chunk is cleared before it is put on id 1. */
typedef struct SjCk327418 {
    char *data;
    int len;
} SjCk327418;

typedef struct Sj327418 Sj327418;

typedef struct SjIf327418 {
    void *fn[6];
    void (*GetChunk)(Sj327418 *sj, int id, int nbyte, SjCk327418 *ck);    /* 0x18 */
    void (*UngetChunk)(Sj327418 *sj, int id, SjCk327418 *ck);             /* 0x1C */
    void (*PutChunk)(Sj327418 *sj, int id, SjCk327418 *ck);               /* 0x20 */
} SjIf327418;

struct Sj327418 {
    SjIf327418 *vtbl;
};

typedef struct Dec327418 {
    char pad0[2];
    signed char nch;                    /* 0x02 */
    char pad3[9];
    Sj327418 *sj[(0xA0 - 0xC) / 4];     /* 0x0C */
    int pending;                        /* 0xA0 */
} Dec327418;

extern void func_003A52F0(void *p, int c, int n);

__attribute__((section(".text.func_00327418")))
void func_00327418(Dec327418 *dec)
{
    SjCk327418 ck;
    int i;
    int n;
    int half;

    n = dec->pending * 2;
    for (i = 0; i < dec->nch; i++) {
        dec->sj[i]->vtbl->GetChunk(dec->sj[i], 0, 0x7FFFFFFF, &ck);
        n = (n < ck.len) ? n : ck.len;
        dec->sj[i]->vtbl->UngetChunk(dec->sj[i], 0, &ck);
    }
    half = n / 2;
    n = half * 2;
    if (n > 0) {
        for (i = 0; i < dec->nch; i++) {
            dec->sj[i]->vtbl->GetChunk(dec->sj[i], 0, n, &ck);
            func_003A52F0(ck.data, 0, n);
            dec->sj[i]->vtbl->PutChunk(dec->sj[i], 1, &ck);
        }
        dec->pending -= half;
    }
}
