/* NON_MATCHING func_0024BDA0 (sn-2.95.3-136): 89 differing words. gcc folds the
 * 0x220..0x222 range test into one unsigned compare where retail keeps two slti
 * branches, which shifts everything after it; the |turn| tests also negate the copy
 * (neg.s f1,f1) where retail negates the original. The int at 0x17D0 is not yet in cEm00. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/gameWork.h"
#include "godhand/cCamera.h"
#include "godhand/vu0.h"

#define EM_NO_ANY_ROOM_LO   0x220
#define EM_NO_ANY_ROOM_HI   0x223
#define ROOM_NO_JUMP        0x100
#define JUMP_FACE_LIMIT     0.5235988f
#define JUMP_TURN_LIMIT     0.7853982f
#define PHASE_JUMP          0x74

#define EM_FRAME_PARITY(e)  (*(int *)((char *)(e) + 0x17D0))

/* The frame: the jump point and its heading. */
typedef struct JumpFrame {
    cVec point;
    float heading;
} JumpFrame;

extern char D_005FEA60[];
extern float Turn_dest(void *from, void *to, float angle, float limit);
extern float Turn_dest_dir(float from, float to, float step);
extern int cSceAtManager_findJumpPoint(void *a0, cVec *pos, cVec *point, float *heading);

/* Starts a jump when the enemy faces its target and a jump point lies ahead of it.
 * Returns 1 when the jump starts. */
__attribute__((section(".text.func_0024BDA0")))
int func_0024BDA0(cEm00 *self)
{
    JumpFrame f;
    float turn;
    float off;

    if (self->emNo >= EM_NO_ANY_ROOM_HI || self->emNo < EM_NO_ANY_ROOM_LO) {
        if ((D_007474A0.frame & 7) != (EM_FRAME_PARITY(self) & 7)) {
            return 0;
        }
    }
    if (D_007474A0.room == ROOM_NO_JUMP) {
        return 0;
    }
    VU0_SQC2_VF0_MEM(&f.point, 0);
    turn = Turn_dest(&self->posA, &self->unk16A0, self->rot.y, 3.1415927f);
    if (turn < 0.0f) {
        off = -turn;
    } else {
        off = turn;
    }
    if (JUMP_FACE_LIMIT < off) {
        return 0;
    }
    if (!cSceAtManager_findJumpPoint(D_005FEA60, self->pos, &f.point, &f.heading)) {
        return 0;
    }
    turn = Turn_dest_dir(self->rot.y, f.heading, 3.1415927f);
    if (turn < 0.0f) {
        off = -turn;
    } else {
        off = turn;
    }
    if (JUMP_TURN_LIMIT < off) {
        return 0;
    }
    cVec_copy3(&self->unk6D0, &f.point);
    self->unk6E0 = f.heading;
    self->phase = PHASE_JUMP;
    self->stepArg = 0;
    self->mode = 0;
    self->step = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0024BDA0);
#endif
