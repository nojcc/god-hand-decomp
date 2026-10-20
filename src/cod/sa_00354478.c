/* cygnus-2.96: func_00354478, find the next MPEG delimiter in the stream's ring, advance by the
 * bytes before it, and count them as data when any of the first three is nonzero. */
typedef struct SfRing354478 {
    unsigned char *p0;  /* 0x00 */
    int n0;             /* 0x04 */
    unsigned char *p1;  /* 0x08 */
    int n1;             /* 0x0C */
    int pad10[2];
} SfRing354478;

typedef struct Sf354478 {
    char pad0[0x9A8];
    long total;         /* 0x9A8 */
    long data;          /* 0x9B0 */
    char pad9B8[0x1FC8 - 0x9B8];
    int sj;             /* 0x1FC8 */
} Sf354478;

extern int func_0034C2B8(Sf354478 *sf, int sj, SfRing354478 *r);
extern unsigned char *sfmpv_SearchDelim(SfRing354478 *r, int mask, int *found);
extern void func_003545D8(Sf354478 *sf, int n);

__attribute__((section(".text.func_00354478")))
int func_00354478(Sf354478 *sf, int unused, int mask)
{
    SfRing354478 r;
    int found;
    unsigned char *p;
    int n;
    int i;
    int nz;
    unsigned char *q;

    if (func_0034C2B8(sf, sf->sj, &r) != 0)
        return 0;
    if (r.n0 == 0)
        return 0;
    p = sfmpv_SearchDelim(&r, mask, &found);
    if (p == 0) {
        n = r.n0 + r.n1 - 3;
        if (n < 0)
            n = 0;
    } else if (p >= r.p0 && p < r.p0 + r.n0) {
        n = p - r.p0;
    } else if (p >= r.p1 && p < r.p1 + r.n1) {
        n = p - r.p1 + r.n0;
    } else {
        n = 0;
    }
    func_003545D8(sf, n);
    nz = 0;
    for (i = 0; i < (n < 4 ? n : 3); i++) {
        if (i < r.n0)
            q = r.p0 + i;
        else
            q = r.p1 + (i - r.n0);
        if (*(signed char *)q != 0) {
            nz = 1;
            break;
        }
    }
    if (nz)
        sf->data += n;
    sf->total += n;
    return n;
}
