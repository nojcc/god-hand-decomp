/* sn-2.95.3-136 */
#include "godhand/vu0.h"
#include "godhand/mtx.h"

/* a1 = the matrix at a0+0x80 times a translation by the vector at a0+0xC0. */


__attribute__((section(".text.func_001503B8")))
void func_001503B8(void *a0, void *a1) {
    unsigned char buf[64] __attribute__((aligned(16)));
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, buf, 0x30);
    VU0_SQC2(5, buf, 0x20);
    VU0_SQC2(6, buf, 0x10);
    VU0_SQC2(7, buf, 0x0);
    *(float *)(buf + 0x30) = *(float *)((char *)a0 + 0xC0);
    *(float *)(buf + 0x34) = *(float *)((char *)a0 + 0xC4);
    *(float *)(buf + 0x38) = *(float *)((char *)a0 + 0xC8);
    MtxMultiply(a1, (char *)a0 + 0x80, buf);
}
