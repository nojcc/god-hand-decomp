#include "godhand/mtx.h"
extern void Obj0000_Set_D_007474A0_Fields_5D8_5E0(int a);
extern char **D_003C2384;

__attribute__((section(".text.BuildMatrixAndForward_147BB0")))
void BuildMatrixAndForward_147BB0(void *dst, void *src, float *q) {
    float m[4][4];
    MtxInitRotQuaternion(m, q);
    MtxMultiply(dst, src, m);
}

__attribute__((section(".text.MtxMulScaleVec")))
void MtxMulScaleVec(void *dst, void *src, cVec *scale) {
    float m[4][4];
    MtxInitScaleVec(m, scale);
    MtxMultiply(dst, src, m);
}

__attribute__((section(".text.ResetObjFields4C48_161780")))
void ResetObjFields4C48_161780(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0x4C) = 0;
    *(int *)(p + 0x48) = 0;
    func_00161590(a0);
}

__attribute__((section(".text.ResetObjFields3430_161CC0")))
void ResetObjFields3430_161CC0(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x30) = 0;
    func_00161590(a0);
}

__attribute__((section(".text.ResetObjFields9820_1632A0")))
void ResetObjFields9820_1632A0(int a0) {
    int *v1;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0);
    v1 = *D_003C2384;
    v1[9] = 0;
    v1[8] = 0;
    func_00161590(a0);
}
