/* sn-2.95.3-136 */
/* NON_MATCHING func_0026A018 (sn-2.95.3-136, fp_hazard_rules fdiv): 4 instructions off. In the
 * subtraction retail holds head->pos in v1 and &tmp_ in v0 (this C swaps them). Writing the
 * subtraction as a block with the non-volatile VU0_ZERO_VSUB_XYZ_TO gives the registers but schedules
 * the head->pos load before the mov.s that saves yaw (2 off). The copy into dir has no self-check. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/capVu0.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"
#include "godhand/fpu.h"

#define HEAD_PART 37

/* Enemy 0x264: turn the head part toward a point 1.7 above the player, at most 45 degrees off the
 * body's back direction, by speedRate * 3 degrees a frame. */
__attribute__((section(".text.func_0026A018")))
void func_0026A018(cEm00 *self)
{
    if ((self->emNo ^ 0x264) == 0) {
        cGameObj *pl = Getplayer();
        cVec target;
        cVec dir;
        cVec ang;
        int frame[3];
        CVEC_TEMPS;
        cOmBase *head;
        float yaw;
        float len;

        CVEC_ZERO(target);
        CVEC_ZERO(dir);
        CVEC_ZERO(ang);
        CVEC_ASSIGN(target, pl->pos);
        target.y += 1.7f;
        head = cOmBase_childAt((cOmBase *)self, frame, HEAD_PART);
        if (head != 0) {
            yaw = Adjust_theta(self->rot.y + 3.1415927f);
            CVEC_SUB(&target, head->pos);
            dir.x = ret_.x;
            dir.y = ret_.y;
            dir.z = ret_.z;
            FPU_SQRT_S(len, dir.x * dir.x + dir.z * dir.z);
            ang.x = -capVu0Atan2(dir.y, len);
            ang.y = capVu0Atan2(dir.x, dir.z);
            ang.x = Turn_dest_dir(ang.x, 0.0f, 0.7853982f);
            ang.y = Turn_dest_dir(yaw, ang.y, 0.7853982f);
            head->rot.x += Turn_dest_dir(head->rot.x, ang.x, self->speedRate * 0.05235988f);
            head->extraYaw += Turn_dest_dir(head->extraYaw, ang.y, self->speedRate * 0.05235988f);
            head->partFlags |= CPARTS_EXTRA_YAW;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026A018);
#endif
