/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/capVu0.h"
#include "godhand/libm.h"
#include "godhand/mtx.h"
#include "include_asm.h"

#define HALF_PI 1.5707964f

/* Arc sine with the argument clamped to [-1, 1]. */
static __inline__ float asinClamped(float x)
{
    float r;

    if (x <= -1.0f) {
        r = -HALF_PI;
    } else if (x >= 1.0f) {
        r = HALF_PI;
    } else {
        r = func_003A1B78(x);
    }
    return r;
}

/* Euler angles of mtx's rotation for one of six axis orders, with the scale
 * of each axis row divided out first; written to rot as (a, b, c, 1).
 * Differs from retail only in the nops before div.s: retail pads a run of
 * divides once with two nops (one nop where the divide reads the neg.s just
 * before it). */
#ifdef NON_MATCHING
__attribute__((section(".text.func_00147C88")))
void func_00147C88(void *rot, float *mtx, unsigned char order)
{
    cVec scale;
    float sx, sy, sz;
    float a, b, c;

    VU0_SQC2_VF0_MEM(&scale, 0);
    MtxGetScaleVec(&scale, mtx);
    sx = scale.x;
    sy = scale.y;
    sz = scale.z;
    switch (order) {
    case 0:
    default:
        a = capVu0Atan2(mtx[6] / sy, mtx[10] / sz);
        b = asinClamped(-mtx[2] / sx);
        c = capVu0Atan2(mtx[1] / sx, mtx[0] / sx);
        break;
    case 1:
        a = capVu0Atan2(-mtx[9] / sz, mtx[5] / sy);
        b = capVu0Atan2(-mtx[2] / sx, mtx[0] / sx);
        c = asinClamped(mtx[1] / sx);
        break;
    case 2:
        a = asinClamped(mtx[6] / sy);
        b = capVu0Atan2(-mtx[2] / sx, mtx[10] / sz);
        c = capVu0Atan2(-mtx[4] / sy, mtx[5] / sy);
        break;
    case 3:
        a = capVu0Atan2(mtx[6] / sy, mtx[5] / sy);
        b = capVu0Atan2(mtx[8] / sz, mtx[0] / sx);
        c = asinClamped(-mtx[4] / sy);
        break;
    case 4:
        a = asinClamped(-mtx[9] / sz);
        b = capVu0Atan2(mtx[8] / sz, mtx[10] / sz);
        c = capVu0Atan2(mtx[1] / sx, mtx[5] / sy);
        break;
    case 5:
        a = capVu0Atan2(-mtx[9] / sz, mtx[10] / sz);
        b = asinClamped(mtx[8] / sz);
        c = capVu0Atan2(-mtx[4] / sy, mtx[0] / sx);
        break;
    }
    func_00150710(rot, a, b, c);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00147C88);
#endif
