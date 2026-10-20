/* NON_MATCHING func_00158FC8 (sn-2.95.3-136; PARK, 137 diffs): math and key decoding are right, but the search loops
 * are laid out differently: retail keeps two separate rotated loops (the second starting at the first key past x) with
 * the exact-hit returns cross-jumped into one mul/add/jr tail, while this source merges them. Evaluate a quantised
 * Hermite curve at time x (u16 time/value/in/out keys with scale/offset dequantisation, clamped to the last key). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct CurveKey {
    unsigned short t;
    unsigned short v;
    unsigned short tin;
    unsigned short tout;
} CurveKey;

typedef struct CurveData {
    float vOfs;                         /* 0x00 */
    float vScale;                       /* 0x04 */
    float tinOfs;                       /* 0x08 */
    float tinScale;                     /* 0x0C */
    float toutOfs;                      /* 0x10 */
    float toutScale;                    /* 0x14 */
    CurveKey key[1];                    /* 0x18 */
} CurveData;

typedef struct CurveHdr {
    unsigned short w00;
    unsigned short count;               /* 0x02 */
    char pad04[4];
    int offset;                         /* 0x08 */
} CurveHdr;

__attribute__((section(".text.func_00158FC8")))
float func_00158FC8(char *base, CurveHdr *h, float x)
{
    CurveData *d;
    CurveKey *k;
    unsigned int n;
    unsigned int i;
    unsigned int prev;
    float s;
    float s2;
    float s3;
    float p0;
    float p1;
    float m0;
    float m1;

    d = (CurveData *)(base + h->offset);
    k = d->key;
    n = h->count;
    for (i = 0; i < n; i++) {
        if ((float)k[i].t == x)
            return k[i].v * d->vScale + d->vOfs;
        if (!((float)k[i].t < x))
            break;
    }
    prev = i - 1;
    for (; i < n; i++) {
        if ((float)k[i].t == x)
            return k[i].v * d->vScale + d->vOfs;
        if (!((float)k[i].t < x)) {
            s = (x - (float)k[prev].t) / ((float)k[i].t - (float)k[prev].t);
            p0 = k[prev].v * d->vScale + d->vOfs;
            p1 = k[i].v * d->vScale + d->vOfs;
            m0 = k[prev].tout * d->toutScale + d->toutOfs;
            m1 = k[i].tin * d->tinScale + d->tinOfs;
            s2 = s * s;
            s3 = s2 * s;
            return (s3 + s3 - s2 * 3.0f) * p0 + p0 + p1 * (-(s3 + s3) + s2 * 3.0f)
                 + m0 * (s3 - s2 - s2 + s) + m1 * (s3 - s2);
        }
    }
    return k[prev].v * d->vScale + d->vOfs;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00158FC8);
#endif
