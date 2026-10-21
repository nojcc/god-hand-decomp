/* NON_MATCHING func_00158CD0 (sn-2.95.3-136): Hermite key-curve eval.
* Loop shape matches; ours keeps an i*4 giv in the first loop for the second, and the Hermite tail's FP regs and
 * schedule differ. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct I4 { int v[4]; } I4;

typedef struct {
    unsigned char dt;
    unsigned char val;
    unsigned char tin;
    unsigned char tout;
} Key158;

typedef struct {
    unsigned short ofsId;
    unsigned short sclId;
    unsigned short t[4];
    Key158 key[1];
} Curve158;

typedef struct {
    char pad0[2];
    unsigned short n;
    char pad4[4];
    int ofs;
} Hdr158;

extern float func_00156508(int id);
extern void func_00156550(void *out, I4 *in);

__attribute__((section(".text.func_00158CD0")))
float func_00158CD0(char *base, Hdr158 *h, float t)
{
    Curve158 *c;
    Key158 *k;
    float ofs;
    float scl;
    float acc;
    float dt;
    float prev;
    float d, d2, d3, a;
    unsigned int i;
    unsigned int j;
    unsigned int n;
    I4 cp;
    I4 r;

    acc = 0.0f;
    c = (Curve158 *)(base + h->ofs);
    k = c->key;
    ofs = func_00156508(c->ofsId);
    scl = func_00156508(c->sclId);
    n = h->n;
    for (i = 0; i < n; i++) {
        dt = (float)k[i].dt;
        acc += dt;
        if (acc == t)
            return (float)k[i].val * scl + ofs;
        if (!(acc < t))
            goto found;
    }
    return (float)k[n - 1].val * scl + ofs;
found:
    prev = acc - dt;
    j = i - 1;
    acc = prev;
    for (; i < n; i++) {
        acc += (float)k[i].dt;
        if (acc == t)
            return (float)k[i].val * scl + ofs;
        if (!(acc < t))
            goto interp;
    }
    return (float)k[j].val * scl + ofs;
interp:
    r.v[0] = c->t[0];
    r.v[1] = c->t[1];
    r.v[2] = c->t[2];
    r.v[3] = c->t[3];
    cp = r;
    func_00156550(&r, &cp);
    d = (t - prev) / (acc - prev);
    d2 = d * d;
    d3 = d2 * d;
    a = d3 + d3;
    return ((a - d2 * 3.0f) * ((float)k[j].val * scl + ofs) + ((float)k[j].val * scl + ofs))
         + ((float)k[i].val * scl + ofs) * (-a + d2 * 3.0f)
         + ((float)k[j].tout * ((float *)&r)[3] + ((float *)&r)[2]) * (d3 - d2 - d2 + d)
         + ((float)k[i].tin * ((float *)&r)[1] + ((float *)&r)[0]) * (d3 - d2);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00158CD0);
#endif
