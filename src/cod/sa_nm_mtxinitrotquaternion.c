/* NON_MATCHING MtxInitRotQuaternion (sn,fp-sched): FP scheduling/regalloc differs; zeros via mtc1 need chain assign */
#include "include_asm.h"

#ifdef NON_MATCHING
void MtxInitRotQuaternion(float m[4][4], float q[4])
{
    float x = q[0];
    float z = q[2];
    float w = q[3];
    float y = q[1];
    float xx, yy, zz, yw, xy, yz, zx, xw, zw;

    m[3][3] = 1.0f;
    xx = 2.0f * (x * x);
    zz = 2.0f * (z * z);
    zw = 2.0f * (z * w);
    xw = 2.0f * (x * w);
    xy = 2.0f * (x * y);
    yy = 2.0f * (y * y);
    yw = 2.0f * (y * w);
    yz = 2.0f * (y * z);
    zx = 2.0f * (z * x);
    m[2][0] = zx + yw;
    m[1][0] = xy - zw;
    m[2][1] = yz - xw;
    m[0][2] = zx - yw;
    m[2][2] = 1.0f - xx - yy;
    m[0][0] = 1.0f - yy - zz;
    m[1][1] = 1.0f - zz - xx;
    m[0][1] = xy + zw;
    m[1][2] = yz + xw;
    m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = m[0][3] = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatching", MtxInitRotQuaternion);
#endif
