#include "godhand/vu0.h"
#include "godhand/mtx.h"

/* MtxInitScaleVec — builds a 4x4 scale matrix at a0: zero-fills the four rows
 * from $vf0 (rotated via vmr32), then writes the scale vector (a1) onto the
 * diagonal (0x0, 0x14, 0x28). */

__attribute__((section(".text.MtxInitScaleVec")))
void MtxInitScaleVec(void *a0, cVec *a1) {
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, a0, 0x30);
    VU0_SQC2(5, a0, 0x20);
    VU0_SQC2(6, a0, 0x10);
    VU0_SQC2(7, a0, 0x0);
    *(float *)((char *)a0 + 0x0) = a1->x;
    *(float *)((char *)a0 + 0x14) = a1->y;
    *(float *)((char *)a0 + 0x28) = a1->z;
}
