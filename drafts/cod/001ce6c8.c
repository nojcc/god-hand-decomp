/* NON_MATCHING func_001CE6C8 (sn-2.95.3-136): retail stores the work vectors with
 * memory-operand sqc2 (0x60(sp), 0x50(sp)), which vu0.h only has for $vf0. With a
 * memory-operand VU0_SQC2_MEM it is 8 words off: a1/v1 for the work vector and the
 * position, and the order of the drop vector's x store against the a1 setup. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define SINK_HOLD_FRAMES  30.0f
#define SINK_SPIN         0.17453292f
#define SINK_DROP         -0.1f
#define SINK_FADE         0.1f

/* A dying enemy body that spins, sinks, then fades out. */
typedef struct cEmSink {
    cGameObj base;
    char unk5AC[0x640 - 0x5AC];
    cVec vel;                   /* 0x640 drift per frame */
    char unk650[0x10];
    float timer;                /* 0x660 frames before the fade starts */
} cEmSink;

extern void MtxInitRotVec(void *a0, float *a1, unsigned char order);

/* out = in * s (xyz), through a work vector. */
static __inline__ void cVec_scale3(cVec *out, cVec *in, float s)
{
    cVec work;

    VU0_LQC2(4, in, 0);
    VU0_SQC2(4, &work, 0);
    VU0_VSCALE_XYZ_MEM(&work, 0, s);
    VU0_LQC2(4, &work, 0);
    VU0_SQC2(4, out, 0);
}

/* Spins the body, drifts it down and along vel, then fades it out and ends the phase. */
__attribute__((section(".text.func_001CE6C8")))
void func_001CE6C8(cEmSink *self)
{
    float mtx[16] __attribute__((aligned(16)));
    cVec drop;
    cVec step;
    float rate;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    VU0_SQC2_VF0_MEM(&drop, 0);
    switch (self->base.step) {
    case 0:
        self->timer = SINK_HOLD_FRAMES;
        self->base.step++;
    case 1:
        self->base.rot.x += rate * SINK_SPIN;
        self->base.rot.x = Adjust_theta(self->base.rot.x);
        MtxInitRotVec(mtx, &self->base.rot.x, 0);
        drop.x = 0;
        drop.y = SINK_DROP;
        drop.z = 0;
        cVec_applyMatrix(&drop, mtx);
        cVec_scale3(&step, &drop, rate);
        VU0_VADD_XYZ_PTR(self->base.pos, self->base.pos, &step);
        cVec_scale3(&step, &self->vel, rate);
        VU0_VADD_XYZ_PTR(self->base.pos, self->base.pos, &step);
        self->timer -= rate;
        if (self->timer <= 0.0f) {
            self->base.tint.w -= rate * SINK_FADE;
            if (self->base.tint.w <= 0.0f) {
                self->base.mode = 1;
                self->base.phase = 0;
                self->base.step = 0;
                self->base.stepArg = 0;
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001CE6C8);
#endif
