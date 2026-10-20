/* NON_MATCHING func_00159300 (sn-2.95.3-136 with as sn; PARK 107 at attempt 3): keyframe curve sample, Hermite segment between the bracketing keys. The first search loop matches; retail's second loop keeps three separate induction pointers (frame load, equal-key return, i*16 for the segment) and builds the segment address after the loop, mine merges them. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Key159300 {
    unsigned short frame;               /* 0x00 */
    char pad02[2];
    float val;                          /* 0x04 */
    float tin;                          /* 0x08 */
    float tout;                         /* 0x0C */
} Key159300;

typedef struct Curve159300 {
    char pad00[2];
    unsigned short nkey;                /* 0x02 */
    char pad04[4];
    int ofs;                            /* 0x08 key table offset from base */
} Curve159300;

__attribute__((section(".text.func_00159300")))
float func_00159300(char *base, Curve159300 *c, float t)
{
    Key159300 *k = (Key159300 *)(base + c->ofs);
    Key159300 *k0;
    Key159300 *k1;
    unsigned int i;
    unsigned int prev;
    unsigned int n;
    float s, s2, s3;

    n = c->nkey;
    i = 0;
    if (n != 0) {
        do {
            if ((float)k[i].frame == t)
                return k[i].val;
            if (!((float)k[i].frame < t))
                goto found;
            i++;
        } while (i < n);
    }
    return k[n - 1].val;
found:
    prev = i - 1;
    for (; i < n; i++) {
        if ((float)k[i].frame == t)
            return k[i].val;
        if (!((float)k[i].frame < t))
            goto interp;
    }
    return k[prev].val;
interp:
    k0 = &k[prev];
    k1 = &k[i];
    s = (t - (float)k0->frame) / ((float)k1->frame - (float)k0->frame);
    s2 = s * s;
    s3 = s2 * s;
    return (s3 + s3 - s2 * 3.0f) * k0->val + k0->val
         + (-(s3 + s3) + s2 * 3.0f) * k1->val
         + (s3 - s2 - s2 + s) * k0->tout
         + (s3 - s2) * k1->tin;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00159300);
#endif
