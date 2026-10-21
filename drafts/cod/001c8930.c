/* NON_MATCHING func_001C8930 (sn-2.95.3-136, -ffast-math, fp_hazard_rules sqrt): 2 differing
 * words; retail holds the work-vector address in a0 where ours picks v1. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cEmManage.h"
#include "godhand/vu0.h"

#define FLY_SPIN_STEP   0.87266463f     /* 50 degrees per frame */
#define FLY_GRAVITY     0.013f
#define FLY_FRAMES      15.0f

/* A thrown piece that flies along its velocity until its timer runs out. */
typedef struct cOmFlyPiece {
    cOmBase base;
    char unk5E0[0x30];
    cVec vel;                           /* 0x610 */
    float timer;                        /* 0x620 frames left */
} cOmFlyPiece;

typedef struct FlyFrame {
    int childNum;                       /* written by cOmBase_childAt */
    char unk04[0xC];
    cVec step;                          /* 0x10 */
    cVec work;                          /* 0x20 */
} FlyFrame;

extern float capVu0Atan2(float y, float x);
extern void func_001C8DD8(char *a0);
extern void cOmBase_dieCommon(void *self);

/* Fly the piece: face it along its velocity on the first frame, then spin the
 * collision body, move by the velocity under gravity and remove the piece when
 * its timer runs out. */
__attribute__((section(".text.func_001C8930")))
void func_001C8930(cOmFlyPiece *self)
{
    FlyFrame f __attribute__((aligned(16)));
    float rate = cEmManage_GetSpeedRate(&D_005864F0);
    cOmBase *child = cOmBase_childAt(&self->base, &f.childNum, 0);
    cVec *work;

    switch (self->base.step) {
    case 0:
        self->base.posPrev.x = -capVu0Atan2(self->vel.y,
            __builtin_sqrtf(self->vel.x * self->vel.x + self->vel.z * self->vel.z));
        self->base.posPrev.y = capVu0Atan2(self->vel.x, self->vel.z);
        self->timer = FLY_FRAMES;
        self->base.step++;
        self->base.posPrev.z = 0.0f;
    case 1:
        work = &f.work;
        if (child != 0) {
            child->posPrev.x += rate * FLY_SPIN_STEP;
        }
        VU0_LQC2(4, &self->vel, 0);
        VU0_SQC2(4, &f, 0x20);
        VU0_VSCALE_XYZ_MEM(&f, 0x20, rate);
        VU0_LQC2(4, work, 0);
        VU0_SQC2(4, &f, 0x10);
        VU0_VADD_XYZ_PTR(self->base.pos, self->base.pos, &f.step);
        self->timer -= rate;
        self->vel.y -= rate * FLY_GRAVITY;
        if (self->timer <= 0.0f) {
            func_001C8DD8((char *)self);
            cOmBase_dieCommon(self);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C8930);
#endif
