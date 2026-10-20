/* no matched C exists for any of the 18 retail sqrt.s sites */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct PathPt {
    float x;
    float y;
} PathPt;

typedef struct PathSrc {
    char pad0[0x6E];
    short npts;                         /* 0x6E */
} PathSrc;

typedef struct PathEnt {
    PathPt *pts;                      /* 0x00 part[0] */
    char pad4[0x18];
    PathSrc *src;                     /* 0x1C */
    char pad20[0x7C];
    float length;                       /* 0x9C */
} PathEnt;

int func_002AC878(void *obj, float t, float *x, float *y, PathEnt *ent)
{
    float len[32];
    PathPt *p;
    float d, dx, dy, r;
    int i;
    int n;

    if (t > 1.0f)
        return 0;
    i = 1;
    d = 0.0f;
    n = ent->src->npts;
    if (i < n - 2) {
        d = t * ent->length;
        for (; i < n - 2; i++) {
            dx = __builtin_fabsf(ent->pts[i].x - ent->pts[i + 1].x);
            dy = __builtin_fabsf(ent->pts[i].y - ent->pts[i + 1].y);
            len[i] = len[i - 1] + __builtin_sqrtf(dx * dx + dy * dy);
            if (d < len[i])
                break;
        }
    }
    if (n < 4)
        return 0;
    p = &ent->pts[i];
    r = (d - len[i - 1]) / (len[i] - len[i - 1]);
    *x = p[0].x + (p[1].x - p[0].x) * r;
    *y = p[0].y + (p[1].y - p[0].y) * r;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002AC878);
#endif
