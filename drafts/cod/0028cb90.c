/* NON_MATCHING func_0028CB90 (sn-2.95.3-136, extern_jtbl D_00449B70, -ffast-math, fp_hazard_rules fdiv): 39 instructions differ. Retail loads the head-local vector as x, z, y (y straight into $f12) and stores the look copy before the sqrt; ours loads z first and moves y into $f12. Retail keeps 0.5 in $f5 and the speed rate in $f4 for the spring update and copies the look vector x, y then z; ours folds 0.5 * rate early and copies x, z, y. 0x15A0 is read as the head pitch speed; cEm00.h calls it gotoPos (a cVec), so the type needs a per-class view. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define EM_HEAD_CHILD   0x1D            /* the head body */
#define EM_HEAD_PITCH_MAX 0.52359879f   /* 30 degrees */

#define EM_PITCH_SPEED(self) ((self)->gotoPos.x)

/* The frame: the child count cOmBase_childAt leaves, the head's inverse matrix and three vectors. */
typedef struct HeadFrame {
    int childNum;
    char unk04[0xC];
    float inv[16];                      /* 0x10 */
    cVec look;                          /* 0x50 */
    cVec local;                         /* 0x60 */
    cVec target;                        /* 0x70 */
} HeadFrame;

#define HEADFRAME_OFFSET(field) ((int)&((HeadFrame *)0)->field)

extern float sqrtf(float x);
extern void MtxInverse(float *dst, float *src);
extern float capVu0Atan2(float y, float x);

/* Tilts the head of the enemies that have one toward the look target at 0x1590 with a damped spring, then moves the target along the head. */
__attribute__((section(".text.func_0028CB90")))
void func_0028CB90(cEm00 *self)
{
    HeadFrame f;
    cEm00 *head;
    float pitch;

    switch (self->emNo) {
    case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
    case 0x225:
    case 0x22C: case 0x22D: case 0x22E: case 0x22F:
    case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E:
    case 0x252:
        head = (cEm00 *)cOmBase_childAt((cOmBase *)self, &f.childNum, EM_HEAD_CHILD);
        if (head == 0)
            return;
        VU0_SQC2_VF0_MEM(&f.look, 0);
        MtxInverse(f.inv, head->mtx);
        VU0_LQC2(4, &self->unk1590, 0);
        VU0_SQC2(4, &f.target, 0);
        cVec_applyMatrix(&f.target, f.inv);
        VU0_LQC2(4, &f.target, 0);
        VU0_SQC2(4, &f, HEADFRAME_OFFSET(local));
        cVec_copy3(&f.look, &f.local);
        pitch = -capVu0Atan2(f.look.y, sqrtf(f.look.x * f.look.x + f.look.z * f.look.z));
        if (EM_HEAD_PITCH_MAX < pitch)
            pitch = EM_HEAD_PITCH_MAX;
        if (pitch < -EM_HEAD_PITCH_MAX)
            pitch = -EM_HEAD_PITCH_MAX;
        head->rot.x += pitch * 0.5f;
        head->rot.x += EM_PITCH_SPEED(self);
        if (EM_HEAD_PITCH_MAX < head->rot.x) {
            head->rot.x = EM_HEAD_PITCH_MAX;
            EM_PITCH_SPEED(self) = 0.0f;
        }
        if (head->rot.x < -EM_HEAD_PITCH_MAX) {
            head->rot.x = -EM_HEAD_PITCH_MAX;
            EM_PITCH_SPEED(self) = 0.0f;
        }
        EM_PITCH_SPEED(self) *= 1.0f - self->speedRate * 0.2f;
        f.look.x = 0.0f;
        f.look.y = 0.0f;
        f.look.z = 0.03f;
        EM_PITCH_SPEED(self) += -head->rot.x * 0.5f * self->speedRate;
        cVec_applyMatrix(&f.look, head->mtx);
        cVec_copy3(&self->unk1590, &f.look);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028CB90);
#endif
