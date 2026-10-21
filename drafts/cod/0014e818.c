/* NON_MATCHING func_0014E818 (sn-2.95.3-136): 4 differing words. Retail loads self->pos
 * into v1 and the work vector's address into v0; here the two registers are swapped. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/vu0.h"

/* The frame: the direction to the target and the subtraction's work vector. */
typedef struct TurnFrame {
    cVec dir;
    cVec work;
} TurnFrame;

extern float capVu0Atan2(float y, float x);

/* Turns the object toward a point by at most maxStep radians. */
__attribute__((section(".text.func_0014E818")))
void func_0014E818(cGameObj *self, cVec *target, float maxStep)
{
    TurnFrame f;
    float diff;
    float step;

    VU0_ZERO_VSUB_XYZ_MEM(&f, (int)&((TurnFrame *)0)->work, target, self->pos);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, 0);
    diff = Adjust_theta(capVu0Atan2(f.dir.x, f.dir.z) - self->rot[1]);
    if (diff < -maxStep) {
        step = -maxStep;
    } else if (maxStep < diff) {
        step = maxStep;
    } else {
        step = diff;
    }
    self->rot[1] += step;
    self->rot[1] = Adjust_theta(self->rot[1]);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0014E818);
#endif
