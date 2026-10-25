/* NON_MATCHING func_00274D18 (sn-2.95.3-136; needs c_flags_add -f=-ffast-math for the
 * bare sqrt.s and fp_hazard_rules fdiv): 10 instructions differ. Retail loads dir.x
 * before dir.z for the length and stores dir x, y, z in order. The copy of the
 * difference into dir has no self-check, so it is written out here: no cVec.h
 * operator has that shape yet. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/capVu0.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"

#define NECK_PART 31

extern float Turn_dest_dir(float f12, float f13, float f14);

/* Enemy 0x20D: tilt the neck part toward the player while bit 17 of emFlags2 is set, else back to level. */
void func_00274D18(cEm00 *self)
{
    int frame[3];
    cParts *neck;
    float pitch;

    if ((self->emNo ^ 0x20D) == 0) {
        neck = (cParts *)cOmBase_childAt((cOmBase *)self, frame, NECK_PART);
        if (neck != 0) {
            if (self->emFlags2 & 0x20000) {
                cVec dir;
                cVec target;

                CVEC_ZERO(dir);
                CVEC_ZERO(target);
                CVEC_ASSIGN(target, Getplayer()->pos);
                target.y += 1.7f;
                {
                    cVec ret_;
                    cVec tmp_;
                    cVec *a_ = &target;
                    cVec *b_ = neck->pos;
                    cVec *t_ = &tmp_;

                    VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);
                    VU0_LQC2(4, t_, 0);
                    VU0_SQC2_MEM(4, &ret_, 0);
                    dir.x = ret_.x;
                    dir.y = ret_.y;
                    dir.z = ret_.z;
                }
                pitch = -capVu0Atan2(dir.y, __builtin_sqrtf(dir.z * dir.z + dir.x * dir.x));
                neck->rot.x = Adjust_theta(neck->rot.x += Turn_dest_dir(neck->rot.x, pitch, self->speedRate * 0.09817477f));
            } else {
                neck->rot.x = Adjust_theta(neck->rot.x += Turn_dest_dir(neck->rot.x, 0.0f, self->speedRate * 0.09817477f));
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00274D18);
#endif
