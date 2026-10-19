/* sn-2.95.3-136 -ffast-math, fp_hazard_rules fdiv: func_002AC6E0, evaluate a Catmull-Rom path at normalised distance t: walk the cumulative segment lengths to the segment holding t * length, then interpolate x and y. */
typedef struct SplHdr2AC6E0 {
    char pad00[0x6E];
    short npts;                         /* 0x6E */
} SplHdr2AC6E0;

typedef struct Spl2AC6E0 {
    float (*pts)[2];                    /* 0x00 */
    char pad04[0x18];
    SplHdr2AC6E0 *hdr;                  /* 0x1C */
    char pad20[0x7C];
    float length;                       /* 0x9C */
} Spl2AC6E0;

extern float ESLib_ESCatMullRom(float t, float p0, float p1, float p2, float p3);

__attribute__((section(".text.func_002AC6E0")))
int func_002AC6E0(void *self, float t, float *ox, float *oy, Spl2AC6E0 *s)
{
    float dist[32];
    float target;
    float u;
    float dx, dy;
    float (*p0)[2], (*p1)[2], (*p2)[2], (*p3)[2];
    int i;
    int n;

    if (1.0f < t)
        return 0;
    target = 0.0f;
    n = s->hdr->npts;
    for (i = 1; i < n - 2; i++) {
        target = t * s->length;
        dx = __builtin_fabsf(s->pts[i][0] - s->pts[i + 1][0]);
        dy = __builtin_fabsf(s->pts[i][1] - s->pts[i + 1][1]);
        dx = __builtin_sqrtf(dx * dx + dy * dy);
        __asm__ volatile(""); /* retail loads dist[i - 1] only after sqrt.s */
        dist[i] = dx + dist[i - 1];
        if (target < dist[i])
            break;
    }
    if (n >= 4) {
        u = (target - dist[i - 1]) / (dist[i] - dist[i - 1]);
        p1 = (float (*)[2])(i * 8 + (int)s->pts);
        p0 = p1 - 1;
        p2 = p1 + 1;
        p3 = p1 + 2;
        *ox = ESLib_ESCatMullRom(u, (*p0)[0], (*p1)[0], (*p2)[0], (*p3)[0]);
        *oy = ESLib_ESCatMullRom(u, (*p0)[1], (*p1)[1], (*p2)[1], (*p3)[1]);
        return 1;
    }
    return 0;
}
