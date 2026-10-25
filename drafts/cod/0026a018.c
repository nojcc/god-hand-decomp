/* NON_MATCHING func_0026A018 (sn-2.95.3-136; needs c_flags_add -f=-ffast-math for the
 * bare sqrt.s): retail copies the difference into dir with no self-check (dir may be
 * a second vector type, or a set method), and loads the two Turn_dest_dir constants
 * after the first capVu0Atan2 call; this form keeps the check and hoists them.
 * The part's 0x150 angle is in cParts padding (cModel.h). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/capVu0.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"

#define HEAD_PART 37

typedef struct cPartsTurn {
    char unk000[0x100];
    cVec rot;                           /* 0x100 */
    char unk110[0x40];
    float yaw;                          /* 0x150 */
    int partFlags;                      /* 0x154 */
} cPartsTurn;

extern float Turn_dest_dir(float f12, float f13, float f14);

/* Enemy 0x264: turn the head part toward the player. */
void func_0026A018(cEm00 *self)
{
    CVEC_TEMPS;
    if ((self->emNo ^ 0x264) == 0) {
        cGameObj *pl = Getplayer();
        cVec target;
        cVec dir;
        cVec ang;
        int frame[3];
        cParts *head;
        float yaw;

        CVEC_ZERO(target);
        CVEC_ZERO(dir);
        CVEC_ZERO(ang);
        CVEC_ASSIGN(target, pl->pos);
        target.y += 1.7f;
        head = (cParts *)cOmBase_childAt((cOmBase *)self, frame, HEAD_PART);
        if (head != 0) {
            yaw = Adjust_theta(self->rot.y + 3.1415927f);
            CVEC_SET_SUB(dir, &target, head->pos);
            ang.x = -capVu0Atan2(dir.y, __builtin_sqrtf(dir.x * dir.x + dir.z * dir.z));
            ang.y = capVu0Atan2(dir.x, dir.z);
            ang.x = Turn_dest_dir(ang.x, 0.0f, 0.7853982f);
            ang.y = Turn_dest_dir(yaw, ang.y, 0.7853982f);
            ((cPartsTurn *)head)->rot.x += Turn_dest_dir(((cPartsTurn *)head)->rot.x, ang.x, self->speedRate * 0.05235988f);
            ((cPartsTurn *)head)->yaw += Turn_dest_dir(((cPartsTurn *)head)->yaw, ang.y, self->speedRate * 0.05235988f);
            head->partFlags |= 0x800;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026A018);
#endif
