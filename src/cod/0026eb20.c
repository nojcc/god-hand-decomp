/* NON_MATCHING func_0026EB20 (sn-2.95.3-136): pitch an enemy to the ground slope. Retail keeps the
 * matrix pointer and then &back in s0 and builds &back again after the second sceVu0ApplyMatrix;
 * ours keeps both live in s0 and s1 and needs a larger frame. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/vu0.h"

#define EM_OFFSET_MTX    0x80    /* orientation matrix, not named in cEm00.h */
#define EM_PITCH(e)      (*(float *)((char *)(e) + 0x1708))  /* not named in cEm00.h */

#define EM_MOVE_GROUNDED 0x08    /* moveFlags: standing on the ground */
#define PITCH_PROBE      0.25f   /* how far ahead and behind the ground is probed */
#define PITCH_KEEP       0.9f
#define PITCH_GAIN       0.1f
#define PITCH_MIN        0.01f   /* smaller pitches snap to 0 */

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern float Pos_probeGroundBelow(cVec *pos);
extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern float capVu0Atan2(float y, float x);

/* Tilt the body to the slope of the ground under the front and the back of it. */
void func_0026EB20(cEm00 *self)
{
    float slope;
    float p;
    float a;

    if (self->moveFlags & EM_MOVE_GROUNDED) {
        cVec front;
        cVec back;
        float dy;

        VU0_SQC2_VF0(&front, 0);
        VU0_SQC2_VF0(&back, 0);
        front.x = 0.0f;
        front.y = 0.0f;
        front.z = PITCH_PROBE;
        sceVu0ApplyMatrix(&front, (char *)self + EM_OFFSET_MTX, &front);
        front.y = Pos_probeGroundBelow(&front);
        back.x = 0.0f;
        back.y = 0.0f;
        back.z = -PITCH_PROBE;
        sceVu0ApplyMatrix(&back, (char *)self + EM_OFFSET_MTX, &back);
        back.y = Pos_probeGroundBelow(&back);
        dy = front.y - back.y;
        slope = -capVu0Atan2(dy, capVu0MagnitudeXZ(&front, &back));
    } else {
        slope = 0.0f;
    }
    p = EM_PITCH(self) * PITCH_KEEP * (slope * PITCH_GAIN);
    EM_PITCH(self) = p;
    a = p < 0.0f ? -p : p;
    if (a < PITCH_MIN) {
        EM_PITCH(self) = 0.0f;
    } else {
        self->rot.x = p;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026EB20);
#endif
