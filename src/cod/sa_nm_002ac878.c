/* NON_MATCHING func_002AC878 (NEAR-MISS): sn + -ffast-math + fp_hazard_rules sqrt,fdiv; 18 diffs, retail keeps the len[i-1] load after sqrt.s (scheduling barrier we cannot reproduce in C); no matched C exists for any of the 18 retail sqrt.s sites */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Pt2AC878 {
    float x;
    float y;
} Pt2AC878;

typedef struct Src2AC878 {
    char pad0[0x6E];
    short npts;                         /* 0x6E */
} Src2AC878;

typedef struct Ent2AC878 {
    Pt2AC878 *pts;                      /* 0x00 part[0] */
    char pad4[0x18];
    Src2AC878 *src;                     /* 0x1C */
    char pad20[0x7C];
    float length;                       /* 0x9C */
} Ent2AC878;

extern float sqrtf(float x);

int func_002AC878(void *obj, float t, float *x, float *y, Ent2AC878 *ent)
{
    float len[32];
    Pt2AC878 *p;
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
