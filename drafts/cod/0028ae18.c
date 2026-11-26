/* NON_MATCHING func_0028AE18 (sn-2.95.3-136, fp_hazard_rules fdiv): same length, 45 instructions off,
 * all register choices: retail gives &tmp_ s1, the matrix s0, &dir s4 and &hitPos s5 (this C swaps each
 * pair) and keeps the pitch in $f2. The m * hitPos block is CVEC_SET_APPLY without the operator= (the
 * copy into dir has no self-check); cVec.h would need that as its own macro. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/fpu.h"

#define HEAD_PART      29
#define HEAD_TILT_MAX  0.5235988f       /* 30 degrees */

extern float D_003C0488;

/* cEm00 0x15F0 (unk15F0 in cEm00.h): the head's tilt speed for these two enemies. */
#define EM_TILT_VEL(self) (*(float *)(self)->unk15F0)                /* length of the head's aim vector */

/* Enemies 0x2A7 and 0x2AB: carry the head's aim point (hitPos) along with the body's move, tilt the
 * head part toward it within 30 degrees with a spring on tiltVel, then put the aim point back on the
 * head's forward axis. */
__attribute__((section(".text.func_0028AE18")))
void func_0028AE18(cEm00 *self)
{
    int frame[3];
    float mtx[16];
    cParts *head;
    cVec dir;
    CVEC_TEMPS;
    float len;
    float pitch;

    if (self->emNo == 0x2A7 || self->emNo == 0x2AB) {
        head = (cParts *)cOmBase_childAt((cOmBase *)self, frame, HEAD_PART);
        if (head != 0) {
            CVEC_ZERO(dir);
            CVEC_SUB(self->pos, &self->posA);
            dir.x = ret_.x;
            dir.y = 0.0f;
            dir.z = ret_.z;
            CVEC_ADD_TO(self->hitPos, &dir);
            MtxInverse(mtx, head->mtx);
            {
                cVec *a_ = &self->hitPos;
                void *m_ = mtx;
                cVec *t_ = &tmp_;

                VU0_LQC2(4, a_, 0);
                VU0_SQC2_MEM(4, &tmp_, 0);
                sceVu0ApplyMatrix(t_, m_, t_);
                VU0_LQC2(4, t_, 0);
                VU0_SQC2_MEM(4, &ret_, 0);
            }
            dir.x = ret_.x;
            dir.y = ret_.y;
            dir.z = ret_.z;
            FPU_SQRT_S(len, dir.x * dir.x + dir.z * dir.z);
            pitch = -capVu0Atan2(dir.y, len);
            if (pitch > HEAD_TILT_MAX)
                pitch = HEAD_TILT_MAX;
            if (pitch < -HEAD_TILT_MAX)
                pitch = -HEAD_TILT_MAX;
            head->rot.x += pitch * 0.5f * self->speedRate;
            head->rot.x += EM_TILT_VEL(self) * self->speedRate;
            if (head->rot.x > HEAD_TILT_MAX) {
                head->rot.x = HEAD_TILT_MAX;
                EM_TILT_VEL(self) = 0.0f;
            }
            if (head->rot.x < -HEAD_TILT_MAX) {
                head->rot.x = -HEAD_TILT_MAX;
                EM_TILT_VEL(self) = 0.0f;
            }
            EM_TILT_VEL(self) *= 1.0f - self->speedRate * 0.2f;
            EM_TILT_VEL(self) += -head->rot.x * 0.5f * self->speedRate;
            dir.x = 0.0f;
            dir.y = 0.0f;
            dir.z = D_003C0488;
            sceVu0ApplyMatrix(&dir, head->mtx, &dir);
            CVEC_PUT(&self->hitPos, dir);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028AE18);
#endif
