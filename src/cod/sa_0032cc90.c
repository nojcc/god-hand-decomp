/* cygnus-2.96 --drop-reorder: ADX end-of-stream flush: take the shortest pending chunk from every output SJ,
 * zero-fill it and hand it back, advance the written count, then stop the stream once all the queued data
 * has been played. */
typedef struct Ck32CC90 { char *data; int len; } Ck32CC90;

typedef struct OBJ OBJ;
struct OVT {
    char pad[0x18];
    void (*getChunk)(OBJ *, int, int, Ck32CC90 *);      /* 0x18 */
    void (*ungetChunk)(OBJ *, int, Ck32CC90 *);         /* 0x1C */
    void (*putChunk)(OBJ *, int, Ck32CC90 *);           /* 0x20 */
    int (*getNum)(OBJ *, int);                          /* 0x24 */
};
struct OBJ { struct OVT *vt; };

typedef struct Hn32CC90 {
    char f0;
    unsigned char stat;                 /* 0x01 */
    char pad02[2];
    void *sjd;                          /* 0x04 */
    char pad08[4];
    void *rna;                          /* 0x0C */
    char pad10[8];
    OBJ *sj[2];                         /* 0x18 */
    char pad20[0x28];
    unsigned int flush;                 /* 0x48 */
    char pad4C[0x5C];
    int written;                        /* 0xA8 */
} Hn32CC90;

extern int D_003D1468;
extern int Obj3260_Tramp_003383B0_D358(void *rna);
extern int Obj3270_GetVia4_0033CE98_77A0(void *sjd);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void func_0033ACA0(Ck32CC90 *ck, int len, Ck32CC90 *head, Ck32CC90 *tail);
extern void func_003A52F0(void *dst, int c, int n);
extern void Obj3260_Tramp_003382A0_D320(void *rna, int a);
extern void Obj3260_Tramp_00338338_D338(void *rna, int a);
extern void func_00338378(void *rna, int a);

__attribute__((section(".text.func_0032CC90")))
void func_0032CC90(Hn32CC90 *hn)
{
    Ck32CC90 ck[2];
    Ck32CC90 tail[2];
    int n;
    int i;
    unsigned int len;
    int mx;
    int v;

    i = 0;
    D_003D1468 = Obj3260_Tramp_003383B0_D358(hn->rna);
    n = Obj3270_GetVia4_0033CE98_77A0(hn->sjd);
    Forward33B658_33E678();
    len = hn->flush;
    for (; i < n; i++) {
        hn->sj[i]->vt->getChunk(hn->sj[i], 0, len * 2, &ck[i]);
        if ((unsigned int)ck[i].len / 2 < len)
            len = (unsigned int)ck[i].len / 2;
    }
    for (i = 0; i < n; i++) {
        func_0033ACA0(&ck[i], len * 2, &ck[i], &tail[i]);
        func_003A52F0(ck[i].data, 0, ck[i].len);
        hn->sj[i]->vt->putChunk(hn->sj[i], 1, &ck[i]);
        hn->sj[i]->vt->ungetChunk(hn->sj[i], 0, &tail[i]);
    }
    hn->written += len;
    Forward33B670_33E690();
    mx = 0;
    for (i = 0; i < n; i++) {
        v = (unsigned int)hn->sj[i]->vt->getNum(hn->sj[i], 1) >> 1;
        if (v >= mx)
            mx = v;
    }
    if (mx + Obj3260_Tramp_003383B0_D358(hn->rna) - hn->written <= 0) {
        Obj3260_Tramp_003382A0_D320(hn->rna, 0);
        Obj3260_Tramp_00338338_D338(hn->rna, 0);
        func_00338378(hn->rna, 1);
        hn->stat = 5;
    }
}
