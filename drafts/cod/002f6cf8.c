/* sn-2.95.3-136. Differs from retail: retail loads the seed word at 0x220 after both fabs stores and keeps the data byte in a0; ours hoists the 0x220 load to the top, so the first eleven instructions after the prologue are scheduled differently. */
#ifdef NON_MATCHING
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* The frame: the jittered point, then the copy handed to cNode_setTranslationFromWorld. */
typedef struct JitterFrame {
    cVec pos;
    cVec arg;
} JitterFrame;

#define JITTERFRAME_OFFSET(field) ((int)&((JitterFrame *)0)->field)

extern float func_0031D168(unsigned int *seed, float minimum, float maximum);
extern void cNode_setTranslationFromWorld(void *self, void *v);

/* Places the node at the camera's eye (or target) plus a random offset of up to the
 * data's range on each axis, seeded from 0x220. */
__attribute__((section(".text.func_002F6CF8")))
int func_002F6CF8(char *self)
{
    char *data = *(char **)(self + 0x110);
    JitterFrame f;
    float dx, dy, dz;
    int fromEye;

    *(float *)(self + 0x2B8) = __builtin_fabsf(*(float *)(data + 0x13C));
    *(float *)(self + 0x2BC) = __builtin_fabsf(*(float *)(data + 0x140));
    fromEye = *(unsigned char *)(data + 0x18C);
    *(unsigned int *)(self + 0x2B4) = *(unsigned int *)(self + 0x220);
    *(int *)(self + 0x2B0) = fromEye;
    VU0_SQC2_VF0(&f, JITTERFRAME_OFFSET(pos));
    if (fromEye) {
        cVec_copy3(&f.pos, &D_005CAFF0->eye);
    } else {
        cVec_copy3(&f.pos, &D_005CAFF0->target);
    }
    dx = func_0031D168((unsigned int *)(self + 0x2B4), -*(float *)(self + 0x2B8), *(float *)(self + 0x2B8));
    dy = func_0031D168((unsigned int *)(self + 0x2B4), -*(float *)(self + 0x2B8), *(float *)(self + 0x2B8));
    dz = func_0031D168((unsigned int *)(self + 0x2B4), -*(float *)(self + 0x2B8), *(float *)(self + 0x2B8));
    f.pos.x += dx;
    f.pos.y += dy;
    f.pos.z += dz;
    VU0_LQC2(4, &f, JITTERFRAME_OFFSET(pos));
    VU0_SQC2(4, &f, JITTERFRAME_OFFSET(arg));
    cNode_setTranslationFromWorld(self, &f.arg);
    return 1;
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_002F6CF8);
#endif
