/* NON_MATCHING func_003780F8 (sn-2.95.3-136): 31 words vs 33; the mirrored branch matches (load c, then s, neg), but the compiler cross-jumps the two store pairs into one tail where retail keeps a jr ra per branch. Next lead: explicit return in the first branch, or differently typed stores. Tried: direct stores, locals with a shared tail, locals with per-branch stores. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    float s;
    float c;
} SinCos378;

extern SinCos378 D_0045A610[];

void func_003780F8(unsigned short ang, float *s, float *c)
{
    unsigned short r = ang % 360;
    float vs, vc;

    if ((ang / 360) & 1) {
        vc = -D_0045A610[360 - r].c;
        vs = D_0045A610[360 - r].s;
        *s = vs;
        *c = vc;
    } else {
        vs = D_0045A610[r].s;
        vc = D_0045A610[r].c;
        *s = vs;
        *c = vc;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_003780F8);
#endif
