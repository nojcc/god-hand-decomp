/* sn-2.95.3-136 (C++ unit, -fno-exceptions, fp_hazard_rules fdiv). NON_MATCHING func_001501D0: same length as retail, 49 instructions off. self and parent swap registers (retail s2/s1), and the else arm calls through mtx where retail keeps self->mtx in s0 and copies it to s3. Calling through self->mtx gives retail's s0/s3 split but 123 words: fdiv pads the second div.s with two nops where retail has one (its operand load sits in the first slot). parent read through self in each arm: 100 off; parent declared in the else block: 109 off. */
extern "C" {

#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/mtx.h"
#include "godhand/angle.h"
#include "godhand/objField.h"

/* As its definition takes it (src/cod/00147c40.c). Not in objField.h: 30 units declare
 * it (void *, void *) themselves and include objField.h. */
extern void CopyVec3ToField30_147C40(float *a0, float *a1);

/* Build the part's world matrix: the parent's matrix times the local one, or, for flags
 * with 0x40000 set and 0x4 clear, the parent's matrix moved to the anchor, its scale
 * undone, then the part's own rotation and scale. With CPARTS_EXTRA_YAW the result is
 * then turned by extraYaw about the Y axis, keeping its translation. */
__attribute__((section(".text.func_001501D0")))
void func_001501D0(cParts *self, int flags)
{
    cParts *parent = self->parent;
    float *mtx;

    if ((flags & 0x40004) != 0x40000) {
        MtxMultiply(self->mtx, parent->mtx, self->mtxLocal);
        mtx = self->mtx;
    } else {
        cVec rot;
        cVec inv;

        rot.x = self->rot.x + self->rotAdd.x;
        rot.y = self->rot.y + self->rotAdd.y;
        rot.z = self->rot.z + self->rotAdd.z;
        rot.w = 1.0f;
        Adjust_theta_vec(&rot);
        CVEC_ZERO(inv);
        inv.x = 1.0f / parent->scaleCalc.x;
        inv.y = 1.0f / parent->scaleCalc.y;
        inv.z = 1.0f / parent->scaleCalc.z;
        inv.w = 1.0f;
        self->scaleCalc.x = parent->scaleCalc.x * self->scale.x;
        self->scaleCalc.y = parent->scaleCalc.y * self->scale.y;
        self->scaleCalc.z = parent->scaleCalc.z * self->scale.z;
        self->scaleCalc.w = 1.0f;
        mtx = self->mtx;
        MtxMulTransVec(mtx, parent->mtx, self->anchor);
        MtxMulScaleVec(mtx, mtx, &inv);
        MtxMulRotVec(mtx, mtx, &rot, 0);
        MtxMulScaleVec(mtx, mtx, &self->scaleCalc);
    }
    if (self->partFlags & CPARTS_EXTRA_YAW) {
        cVec pos;
        cVec q;
        cVec axis;
        float turn[4][4];

        CVEC_ZERO(pos);
        ForwardVec3At30_147C60(&pos, mtx);
        CVEC_COPY(axis, &D_003BD8B0);
        Quaternion_SetRotationAxis(&q, &axis, self->extraYaw);
        MtxInitRotQuaternion(turn, &q.x);
        MtxMultiply(mtx, turn, mtx);
        CopyVec3ToField30_147C40(mtx, &pos.x);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001501D0);
#endif

}
