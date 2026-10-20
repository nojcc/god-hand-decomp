/* NON_MATCHING Turn_dest_Y (sn-2.95.3-136, "as": "sn", fp_hazard_rules fdiv;
 * PARK, 60 diffs): retail keeps the angle and its wrapped difference in f12 and the clamped step in f14; ours splits them differently, so the clamp branches become likely forms */
#include "include_asm.h"

#ifdef NON_MATCHING
#define PI_F 3.1415927f
#define ABS(x) ((x) > 0.0f ? (x) : -(x))

extern float func_003A1648(float x);
extern float capVu0MagnitudeXZ(void *a0, void *a1);

static inline float Absf(float x)
{
    if (x > 0.0f)
        return x;
    return -x;
}

void Turn_dest_Y(float *from, float *to, float *outY, float *outX, float curY, float curX, float maxY, float maxX)
{
    float dx = to[0] - from[0];
    float dz = to[2] - from[2];
    float dy = to[1] - from[1];
    float xz = capVu0MagnitudeXZ(from, to);
    float a, d, s, r;

    if (dz != 0.0f) {
        a = func_003A1648(dx / dz);
        if (dz < 0.0f)
            a -= PI_F;
    } else {
        a = -1.5707964f;
        if (0.0f < dx)
            a = 1.5707964f;
    }
    d = a - curY;
    if (d > PI_F) {
        d -= 6.2831855f;
    }
    if (d < -PI_F) {
        d += 6.2831855f;
    }
    s = d > 0.0f ? 1.0f : -1.0f;
    r = maxY < ABS(d) ? maxY : ABS(d);
    *outY = r * s;

    if (xz != 0.0f) {
        a = func_003A1648(dy / -xz);
        if (xz < 0.0f)
            a -= PI_F;
    } else {
        a = -1.5707964f;
        if (0.0f < dy)
            a = 1.5707964f;
    }
    d = a - curX;
    if (d > PI_F) {
        d -= 6.2831855f;
    }
    if (d < -PI_F) {
        d += 6.2831855f;
    }
    s = d > 0.0f ? 1.0f : -1.0f;
    r = maxX < ABS(d) ? maxX : ABS(d);
    *outX = r * s;
}
#else
INCLUDE_ASM("asm/nonmatching", Turn_dest_Y);
#endif
