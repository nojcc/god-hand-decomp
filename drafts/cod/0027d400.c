/* NON_MATCHING func_0027D400 (sn-2.95.3-136, c_flags_add -f=-ffast-math, fp_hazard_rules "sqrt"): the size and the instruction sequence match. 54 instructions differ in float and saved-register numbering: retail keeps the clamped angle in $f2 and the speed rate in $f4, and holds &f.push in $s4 and the swing vector in $s5, where ours swaps them. Without -ffast-math, __builtin_sqrtf keeps a NaN check and a sqrtf call that retail does not have. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

/* This enemy keeps a swing vector at 0x15C0 and its angular speed at 0x15D0, over
 * the cEm00 words named stepScale and unk15C4. */
#define EM_SWING(self) ((cVec *)((char *)(self) + 0x15C0))
#define EM_SWING_SPD(self) (*(float *)((char *)(self) + 0x15D0))

#define SWING_PART  0x13
#define SWING_MAX   0.5235988f

typedef struct EmSwingFrame {
    int childNum;
    char unk04[0xC];
    float inv[16];                      /* 0x10 */
    cVec push;                          /* 0x50 */
    cVec local;                         /* 0x60 */
    cVec move;                          /* 0x70 */
} EmSwingFrame;

extern void MtxInverse(void *dst, void *src);
extern float capVu0Atan2(float y, float x);

/* Swings a hanging part: the body's movement pushes the swing vector, which tilts the part
 * about x within +-30 degrees; the tilt springs back and its speed is damped. */
__attribute__((section(".text.func_0027D400")))
void func_0027D400(cEm00 *self)
{
    EmSwingFrame f;
    cParts *part;
    float a;

    part = (cParts *)cOmBase_childAt((cOmBase *)self, &f.childNum, SWING_PART);
    if (part == 0) {
        return;
    }
    VU0_SQC2_VF0_MEM(&f.push, 0);
    VU0_ZERO_VSUB_XYZ_MEM(&f.move, 0, self->pos, &self->posA);
    VU0_LQC2_SQC2_MEM(4, &f.local, &f.move);
    f.push.x = f.local.x;
    f.push.z = f.local.z;
    f.push.y = 0.0f;
    VU0_VADD_XYZ_IP(EM_SWING(self), 0, &f.push);
    MtxInverse(f.inv, part->mtx);
    VU0_LQC2_SQC2_MEM(4, &f.move, EM_SWING(self));
    sceVu0ApplyMatrix(&f.move, f.inv, &f.move);
    VU0_LQC2_SQC2_MEM(4, &f.local, &f.move);
    f.push.x = f.local.x;
    f.push.y = f.local.y;
    f.push.z = f.local.z;
    a = -capVu0Atan2(f.local.y, __builtin_sqrtf(f.local.x * f.local.x + f.local.z * f.local.z));
    if (a > SWING_MAX) {
        a = SWING_MAX;
    }
    if (a < -SWING_MAX) {
        a = -SWING_MAX;
    }
    part->rot.x += self->speedRate * 0.5f * a;
    part->rot.x += EM_SWING_SPD(self) * self->speedRate;
    if (part->rot.x > SWING_MAX) {
        part->rot.x = SWING_MAX;
        EM_SWING_SPD(self) = 0.0f;
    }
    if (part->rot.x < -SWING_MAX) {
        part->rot.x = -SWING_MAX;
        EM_SWING_SPD(self) = 0.0f;
    }
    EM_SWING_SPD(self) *= 1.0f - self->speedRate * 0.2f;
    EM_SWING_SPD(self) += -part->rot.x * 0.5f * self->speedRate;
    f.push.x = 0.0f;
    f.push.y = 0.0f;
    f.push.z = 0.03f;
    sceVu0ApplyMatrix(&f.push, part->mtx, &f.push);
    cVec_copy3(EM_SWING(self), &f.push);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0027D400);
#endif
