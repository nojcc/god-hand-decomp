/* NON_MATCHING func_00275888 (sn-2.95.3-136): 62 differing words. Retail takes &eye into
 * s1 in the prologue and keeps self in s2 (four saved registers); here self's register
 * is reused for &eye after CopyVec3ToField30_147C40, so the frame and every register
 * shift. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define EYE_HEIGHT      0.5f
#define LINE_HIT_MASK   0x124

extern void MtxInitRotY(void *a0, float angle);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Nonzero when something blocks the line from the object's eye to dist ahead of it. */
__attribute__((section(".text.func_00275888")))
int func_00275888(cGameObj *self, float dist)
{
    cVec eye;
    cVec ahead;
    float mtx[16] __attribute__((aligned(16)));

    VU0_SQC2_VF0_MEM(&eye, 0);
    VU0_SQC2_VF0_MEM(&ahead, 0);
    MtxInitRotY(mtx, self->rot[1]);
    CopyVec3ToField30_147C40(mtx, &self->pos->x);
    eye.x = 0;
    eye.y = EYE_HEIGHT;
    eye.z = 0;
    ahead.x = 0;
    ahead.y = EYE_HEIGHT;
    ahead.z = dist;
    cVec_applyMatrix(&eye, mtx);
    cVec_applyMatrix(&ahead, mtx);
    if (ChkLine(&eye, &ahead, 0, 0, 1, LINE_HIT_MASK, 0, 1, 0, 0, 0, 0, 1) == 0) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00275888);
#endif
