/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDBase.h"
#include "godhand/fpu.h"

/* Point at fraction t of the entry's position path, on straight segments: sum the segment
 * lengths until they pass t * pathLen and interpolate linearly across that segment into *x, *y.
 * 0 when t > 1 or the path has fewer than 4 points. obj is not read, and dist[0], the length
 * before the first segment, is never written: retail reads it as left on the stack. */
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
