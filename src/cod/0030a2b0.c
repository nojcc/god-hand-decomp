#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

/* sceVu0ApplyMatrix — VU0 full 4x4 matrix x 4-vector: *v0 = (mat m0) * (vec v1),
 * accumulating all four rows (vmulax/vmadday/vmaddaz/vmaddw). */

__attribute__((section(".text.sceVu0ApplyMatrix")))
void sceVu0ApplyMatrix(void *v0, void *m0, void *v1) {
    VU0_LQC2(4, m0, 0);
    VU0_LQC2(5, m0, 0x10);
    VU0_LQC2(6, m0, 0x20);
    VU0_LQC2(7, m0, 0x30);
    VU0_LQC2(8, v1, 0);
    VU0_VMULAX_XYZW(4, 8);
    VU0_VMADDAY_XYZW(5, 8);
    VU0_VMADDAZ_XYZW(6, 8);
    VU0_VMADDW_XYZW(9, 7, 8);
    VU0_SQC2(9, v0, 0);
}
