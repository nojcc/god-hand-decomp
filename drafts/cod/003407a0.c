/* NON_MATCHING func_003407A0 (cygnus-2.96): 90 words vs 92. Retail keeps &bufL[pos] in two registers
 * (two extra register copies) and loads bufL before pos and bufR, so the schedule from the rear products
 * to the clamps differs. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define PAN_ROT_COS     0xDEF
#define PAN_ROT_SIN     0x7D6

/* Pan state: a two-channel delay line and the four pan distances set by func_00340970. */
typedef struct PanDelayWork {
    char pad00[0x8];
    int *bufL;                          /* 0x08 */
    int *bufR;                          /* 0x0C */
    char pad10[0x4];
    int pos;                            /* 0x14 */
    int len;                            /* 0x18 */
    int d[4];                           /* 0x1C left, right, front, rear */
} PanDelayWork;

extern int D_00456B18[];

/* Clamp to the signed 16-bit sample range. */
static __inline__ int PanDelay_clamp(int v)
{
    if (v > 0x7FFF) {
        v = 0x7FFF;
    } else if (v < -0x8000) {
        v = -0x8000;
    }
    return v;
}

/* Pan one sample: left and right gains from the pan distances, the front share straight out and the
 * rear share through the delay line, phase-rotated between the channels; advance the delay line. */
__attribute__((section(".text.func_003407A0")))
void func_003407A0(PanDelayWork *w, short in, short *outL, short *outR)
{
    int l;
    int r;
    int rl;
    int rr;
    int fl;
    int fr;

    l = in * D_00456B18[w->d[0]] >> 12;
    r = in * D_00456B18[w->d[1]] >> 12;
    rl = l * D_00456B18[w->d[3]] >> 12;
    rr = r * D_00456B18[w->d[3]] >> 12;
    fl = (l * D_00456B18[w->d[2]] >> 12) + w->bufL[w->pos];
    fr = (r * D_00456B18[w->d[2]] >> 12) + w->bufR[w->pos];
    w->bufL[w->pos] = (rl * -PAN_ROT_COS + rr * -PAN_ROT_SIN) >> 12;
    w->bufR[w->pos] = (rr * PAN_ROT_COS + rl * PAN_ROT_SIN) >> 12;
    *outL = PanDelay_clamp(fl);
    *outR = PanDelay_clamp(fr);
    if (++w->pos >= w->len) {
        w->pos = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_003407A0);
#endif
