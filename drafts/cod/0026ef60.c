/* NON_MATCHING func_0026EF60 (sn-2.95.3-136, as=sn): 1 differing word. Retail negates
 * the angle itself (neg.s f2,f20); here it negates the copy (neg.s f2,f2). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/vu0.h"

#define VIEW_NEAR_SQ     100.0f
#define VIEW_HALF_ANGLE  1.5707964f
#define VIEW_TURN_LIMIT  3.1415927f
#define VIEW_MOVED_SQ    0.0009f

/* The frame: the camera target, the view direction, and the eye-target difference. */
typedef struct ViewFrame {
    cVec target;
    cVec dir;
    cVec diff;
    cVec work;
} ViewFrame;

#define VIEWFRAME_OFFSET(field) ((int)&((ViewFrame *)0)->field)

extern float capVu0Atan2(float y, float x);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);

/* Nonzero while the object should stay active: busy, near the camera target, in front
 * of the camera, or moving. */
__attribute__((section(".text.func_0026EF60")))
int func_0026EF60(cGameObj *self)
{
    ViewFrame f;
    float angle;
    float off;

    VU0_SQC2_VF0_MEM(&f.target, 0);
    VU0_SQC2_VF0_MEM(&f.dir, 0);
    cVec_copy3(&f.target, &D_005CAFF0->target);
    VU0_ZERO_VSUB_XYZ_MEM(&f.work, 0, &D_005CAFF0->eye, &f.target);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, VIEWFRAME_OFFSET(diff));
    f.dir.x = f.diff.x;
    f.dir.y = f.diff.y;
    f.dir.z = f.diff.z;
    angle = capVu0Atan2(f.diff.x, f.diff.z);
    if (self->mode == 2) {
        return 1;
    }
    if (self->mode == 1) {
        return 1;
    }
    if (capVu0MagnitudeSqXZ(self->pos, &f.target) < VIEW_NEAR_SQ) {
        return 1;
    }
    angle = Turn_dest(&f.target, self->pos, angle, VIEW_TURN_LIMIT);
    if (angle < 0.0f) {
        off = -angle;
    } else {
        off = angle;
    }
    if (off < VIEW_HALF_ANGLE) {
        return 1;
    }
    if (VIEW_MOVED_SQ < capVu0MagnitudeSqXZ(self->pos, &self->posA)) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026EF60);
#endif
