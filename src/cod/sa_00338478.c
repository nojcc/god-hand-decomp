/* cygnus-2.96, -freorder-blocks dropped: func_00338478, once every channel's stream holds a full
 * block, drain one block from each channel and restart its decoder. */
typedef struct SJ338 SJ338;
typedef struct {
    int len;
    int size;
} Ck338;
typedef struct {
    char pad00[0x18];
    void (*getChunk)(SJ338 *sj, int id, int n, Ck338 *ck);   /* 0x18 */
    char pad1C[4];
    void (*putChunk)(SJ338 *sj, int id, Ck338 *ck);          /* 0x20 */
    int (*getNum)(SJ338 *sj, int id);                        /* 0x24 */
} SJVt338;
struct SJ338 {
    SJVt338 *vt;
};
typedef struct {
    char pad0[8];
    SJ338 *sj;                  /* 0x08 */
} Ch338;
typedef struct {
    char pad00[8];
    Ch338 *ch[2];               /* 0x08 */
    void *dec[2];               /* 0x10 */
    char pad18[0x2C - 0x18];
    int blk;                    /* 0x2C */
    char pad30[0x52 - 0x30];
    signed char nch;            /* 0x52 */
    char pad53[0x58 - 0x53];
    signed char stat;           /* 0x58 */
    char pad59[2];
    char f5B;                   /* 0x5B */
} Obj338;

extern int func_00340128(void *dec);
extern void func_00340308(void *dec);

__attribute__((section(".text.func_00338478")))
void func_00338478(Obj338 *o)
{
    Ck338 ck;
    int cnt;
    int i;
    SJ338 *sj;

    if (o->stat != 1)
        return;
    cnt = 0;
    for (i = 0; i < o->nch; i++) {
        if (func_00340128(o->dec[i]) != 1) {
            sj = o->ch[i]->sj;
            if (sj->vt->getNum(sj, 0) == o->blk)
                cnt++;
        }
    }
    if (cnt != o->nch)
        return;
    for (i = 0; i < o->nch; i++) {
        sj = o->ch[i]->sj;
        sj->vt->getChunk(sj, 0, 0x7FFFFFFF, &ck);
        o->ch[i]->sj->vt->putChunk(o->ch[i]->sj, 0, &ck);
        sj = o->ch[i]->sj;
        sj->vt->getChunk(sj, 0, 0x7FFFFFFF, &ck);
        if (ck.size != o->blk)
            for (;;)
                ;
        sj = o->ch[i]->sj;
        sj->vt->putChunk(sj, 0, &ck);
        o->f5B = 0;
        func_00340308(o->dec[i]);
    }
}
