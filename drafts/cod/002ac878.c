/* sn-2.95.3-136 */
/* NON_MATCHING func_002AC878 (sn-2.95.3-136, fp_hazard_rules fdiv): 2 instructions off. Retail never
 * writes dist[0] and reads it as left on the stack on the first pass; writing it (dist[0] = 0) puts
 * the store in the delay slot at +0x3C, where retail has the n < 4 test. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cIDBase.h"
#include "godhand/fpu.h"

/* Point at fraction t of the entry's position path, on straight segments: sum the segment
 * lengths until they pass t * pathLen and interpolate linearly across that segment into *x, *y.
 * 0 when t > 1 or the path has fewer than 4 points. obj is not read. */
__attribute__((section(".text.func_002AC878")))
int func_002AC878(cIDBaseObj *obj, float t, float *x, float *y, cIDBaseEnt *ent)
{
    float dist[32];
    float len;
    float u;
    int n;
    int i;

    if (t > 1.0f)
        return 0;
    n = ent->src->pathNum;
    len = 0.0f;
    dist[0] = 0.0f;
    for (i = 1; i < n - 2; i++) {
        cIDPathPt *pt = cIDBaseEnt_path(ent);
        float dx, dy, d;

        len = t * ent->pathLen;
        dx = __builtin_fabsf(pt[i].x - pt[i + 1].x);
        dy = __builtin_fabsf(pt[i].y - pt[i + 1].y);
        FPU_SQRT_S(d, dx * dx + dy * dy);
        dist[i] = d + dist[i - 1];
        if (len < dist[i])
            break;
    }
    if (n >= 4) {
        cIDPathPt *pt = cIDBaseEnt_path(ent);

        u = (len - dist[i - 1]) / (dist[i] - dist[i - 1]);
        *x = pt[i].x + (pt[i + 1].x - pt[i].x) * u;
        *y = pt[i].y + (pt[i + 1].y - pt[i].y) * u;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002AC878);
#endif
