/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define ORBIT_RADIUS     26.0f
#define ORBIT_TURN_STEP  0.012271847f

/* The frame: the rotation, the orbit point, the offset from the centre and its work copy. */
typedef struct OrbitFrame {
    float mtx[16];
    cVec at;
    cVec diff;
    cVec work;
} OrbitFrame;

#define ORBITFRAME_OFFSET(field) ((int)&((OrbitFrame *)0)->field)

extern cVec D_005850B0;
extern float capVu0Atan2(float y, float x);
extern void MtxInitRotY(void *mtx, float angle);
extern float Turn_dest_dir(float from, float to, float step);

/* Moves the object around the arena centre by angle on a fixed radius and turns it
 * to face away from the centre. */
__attribute__((section(".text.func_00249770")))
void func_00249770(cGameObj *self, float angle)
{
    OrbitFrame f;

    VU0_SQC2_VF0_MEM(&f.at, 0);
    VU0_ZERO_VSUB_XYZ_TO(&f.work, 0, self->pos, &D_005850B0);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, ORBITFRAME_OFFSET(diff));
    f.at.x = f.diff.x;
    f.at.y = f.diff.y;
    f.at.z = f.diff.z;
    angle = Adjust_theta(capVu0Atan2(f.diff.x, f.diff.z) + angle);
    MtxInitRotY(f.mtx, angle);
    f.at.x = 0.0f;
    f.at.y = 0.0f;
    f.at.z = ORBIT_RADIUS;
    cVec_applyMatrix(&f.at, f.mtx);
    VU0_VADD_XYZ_IP(&f.at, 0, &D_005850B0);
    self->pos->x = f.at.x;
    self->pos->z = f.at.z;
    self->rot[1] += Turn_dest_dir(self->rot[1], Adjust_theta(angle + 3.1415927f),
                                  self->speedRate * ORBIT_TURN_STEP);
    self->rot[1] = Adjust_theta(self->rot[1]);
}
