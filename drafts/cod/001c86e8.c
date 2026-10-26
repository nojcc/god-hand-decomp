/* sn-2.95.3-136, -ffast-math, fp_hazard_rules sqrt */
/* func_001C86E8. Retail computes &step into $a0 at the top of the step block
 * (in the delay slot of the spin test); this C computes it into $v0 just
 * before the copy, 10 instructions differ. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cEmManage.h"

/* The thrown object these phases run (phase table D_003BDE50); no header type yet. */
#ifdef NON_MATCHING
typedef struct ThrownObj {
    cGameObj base;
    char unk5AC[0x610 - 0x5AC];
    cVec vel;                           /* 0x610 */
    float life;                         /* 0x620 frames left in flight */
} ThrownObj;

typedef struct LineObjB LineObjB;

extern float capVu0Atan2(float y, float x);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void func_001C8DD8(char *a0);
extern void LineObjB_checkWaterHit(LineObjB *self);

/* Flight phase: aim along the velocity, spin, fall, and die on a hit or timeout. */
__attribute__((section(".text.func_001C86E8")))
void func_001C86E8(ThrownObj *self)
{
    cVec to;
    cVec from;
    cVec hit;
    int frame[3];
    cVec move;
    cVec step;
    float rate;
    cParts *spin;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    VU0_SQC2_VF0_MEM(&to, 0);
    VU0_LQC2_SQC2_MEM(4, &from, self->base.pos);
    VU0_SQC2_VF0_MEM(&hit, 0);
    spin = (cParts *)cOmBase_childAt((cOmBase *)self, frame, 0);

    switch (self->base.step) {
    case 0:
        self->base.rot[0] = -capVu0Atan2(self->vel.y,
            __builtin_sqrtf(self->vel.x * self->vel.x + self->vel.z * self->vel.z));
        self->base.rot[1] = capVu0Atan2(self->vel.x, self->vel.z);
        self->life = 90.0f;
        self->base.step++;
        self->base.rot[2] = 0.0f;
    case 1:
        if (spin != 0)
            spin->rot.x += rate * 0.87266463f;
        VU0_LQC2_SQC2_MEM(4, &step, &self->vel);
        VU0_VSCALE_XYZ_MEM(&step, 0, rate);
        VU0_LQC2_SQC2_MEM(4, &move, &step);
        VU0_VADD_XYZ_IP(self->base.pos, 0, &move);
        self->vel.y -= rate * 0.013f;
        cVec_copy3(&to, self->base.pos);
        if (ChkLine(&from, &to, &hit, 0, 7, 0x534, 0, 0, 0, 0, 0, 0, 1) != 0) {
            cVec_copy3(self->base.pos, &hit);
            self->base.pos->y += 0.3f;
            func_001C8DD8((char *)self);
        } else {
            self->life -= rate;
            if (self->life <= 0.0f)
                func_001C8DD8((char *)self);
            LineObjB_checkWaterHit((LineObjB *)self);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C86E8);
#endif
