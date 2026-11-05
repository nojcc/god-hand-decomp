/* SN ProDG ee-gcc 2.95.3 matched TU. */

#include "godhand/objField.h"
#include "godhand/cNode.h"

__attribute__((section(".text.CopyVec3ToField20_173908")))
void CopyVec3ToField20_173908(char *a0, float *a1) {
    float *v0 = (float *)(a0 + 0x20);
    if (v0 != a1) {
        *(float *)(a0 + 0x20) = a1[0];
        v0[1] = a1[1];
        v0[2] = a1[2];
    }
}

__attribute__((section(".text.CopyVec3ToField30_173938")))
void CopyVec3ToField30_173938(char *a0, float *a1) {
    float *v0 = (float *)(a0 + 0x30);
    if (v0 != a1) {
        *(float *)(a0 + 0x30) = a1[0];
        v0[1] = a1[1];
        v0[2] = a1[2];
    }
}

__attribute__((section(".text.CopyVec3ToField40_173968")))
void CopyVec3ToField40_173968(char *a0, float *a1) {
    float *v0 = (float *)(a0 + 0x40);
    if (v0 != a1) {
        *(float *)(a0 + 0x40) = a1[0];
        v0[1] = a1[1];
        v0[2] = a1[2];
    }
}

#include "godhand/vu0.h"




__attribute__((section(".text.StoreVecFromFieldB0_2B6160")))
cVec *StoreVecFromFieldB0_2B6160(cVec *dst, cNode *self) {
    cVec trans;
    VU0_SQC2_VF0(&trans, 0x0);
    cNode_updateWorldMatrix(self);
    ForwardVec3At30_147C60(&trans, (float *)self->matWorld);
    VU0_LQC2(4, &trans, 0x0);
    VU0_SQC2(4, dst, 0x0);
    return dst;
}
