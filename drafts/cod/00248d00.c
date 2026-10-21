#ifdef NON_MATCHING

#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

extern unsigned char D_005850B0[];
extern float Adjust_theta(float);
extern void MtxInitRotY(void *, float);
extern float capVu0Atan2(float, float);
extern float Turn_dest_dir(float, float, float);

__attribute__((section(".text.func_00248D00")))
void func_00248D00(char *s0, float f20)
{
    char *s1 = (char *)D_005850B0;
    char frame[0xB0] __attribute__((aligned(16)));
    void *pos;
    float th, t1, step;

    VU0_SQC2_VF0(frame, 0x40);
    pos = *(void **)(s0 + 0xF0);
    VU0_SQC2_VF0(frame, 0x60);
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x60, pos, s1);
    VU0_LQC2(4, frame, 0x60);
    VU0_SQC2(4, frame, 0x50);
    th = Adjust_theta(capVu0Atan2(*(float *)(frame + 0x50), *(float *)(frame + 0x58)) + f20);
    f20 = th;
    MtxInitRotY(frame, f20);
    *(int *)(frame + 0x40) = 0;
    *(float *)(frame + 0x48) = 26.0f;
    *(int *)(frame + 0x44) = 0;
    sceVu0ApplyMatrix(frame + 0x40, frame, frame + 0x40);
    VU0_LQC2(4, frame, 0x40);
    VU0_LQC2(5, s1, 0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x40);
    pos = *(void **)(s0 + 0xF0);
    *(float *)pos = *(float *)(frame + 0x40);
    *(float *)((char *)pos + 8) = *(float *)(frame + 0x48);
    th = Adjust_theta(f20 + 3.1415927f);
    t1 = *(float *)((char *)pos + 8);
    *(float *)((char *)pos + 8) = t1;
    step = *(float *)(s0 + 0x5A8) * 0.012271847f;
    t1 = Turn_dest_dir(*(float *)(s0 + 0x104), th, step);
    *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + t1;
    *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
}

#else
INCLUDE_ASM("nonmatching", func_00248D00);
#endif
