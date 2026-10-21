/* NON_MATCHING func_0013B5F0 (sn-2.95.3-136): free look camera step. Retail loads each swing step in
 * its own arm of the branch; ours sets one before the branch and overrides it. The stick reads and
 * the copy into goal are also scheduled differently. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cPlCamera.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

#define PL_STATE_MASK  0xFFFF00000000L  /* mode (0x2F4) and phase (0x2F5) */
#define PL_STATE_FLY   0x20000000000L   /* mode 0, phase 2 */

#define STICK_DEAD     60               /* stick travel ignored around the centre */

/* The player's state word, read as one 64-bit value. */
typedef struct PlState {
    char unk000[0x2F0];
    long stateWord;                     /* 0x2F0 low word unknown, high word holds mode and phase */
} PlState;

extern void MtxInitRotVec(void *mtx, cVec *dir, int roll);
extern float capVu0Sin(float x);

static __inline__ void vecSet(cVec *d, float x, float y, float z)
{
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = 1.0f;
}

/* The right stick, -128..127 on each axis. */
#define STICK_RX  (((signed char *)&D_007474A0)[0x1F2])
#define STICK_RY  (((signed char *)&D_007474A0)[0x1F3])

/* Free look step: put the target at the followed object (bobbing while the player flies), turn the
 * view offsets with the right stick and set the eye and the up vector from them. */
void func_0013B5F0(struct cPlCamera *self)
{
    struct {
        float mtx[4][4];                /* 0x00 */
        cVec v;                         /* 0x40 */
        cVec up;                        /* 0x50 */
    } f;
    PlState *pl;
    float ax;
    float ay;
    float dx;
    float dy;
    float sw;
    float fy;

    pl = (PlState *)Getplayer();
    if (pl == 0) {
        return;
    }
    if ((pl->stateWord & PL_STATE_MASK) != 0) {
        VU0_LQC2(4, self->target->pos, 0);
        VU0_SQC2(4, &f, 0x40);
        sw = self->swing;
        if ((pl->stateWord & PL_STATE_MASK) != PL_STATE_FLY) {
            sw = sw + 0.31415927f;
        } else {
            sw = sw + 0.20943952f;
        }
        self->swing = sw;
        if (3.1415927f < sw) {
            self->swing = sw - 3.1415927f;
        }
        f.v.y += capVu0Sin(self->swing) * 0.05f;
        cVec_copy3(&self->goal, &f.v);
        MtxInitRotVec(f.mtx, (cVec *)self->target->rot, 0);
        f.mtx[3][0] = f.v.x;
        f.mtx[3][1] = f.v.y;
        f.mtx[3][2] = f.v.z;
        sceVu0ApplyMatrix(&self->base.target, f.mtx, &self->offset);
    } else {
        MtxInitRotVec(f.mtx, (cVec *)self->target->rot, 0);
        f.mtx[3][0] = self->goal.x;
        f.mtx[3][1] = self->goal.y;
        f.mtx[3][2] = self->goal.z;
        sceVu0ApplyMatrix(&self->base.target, f.mtx, &self->offset);
    }
    ax = STICK_RX;
    fy = STICK_RY;
    dx = 0.0f;
    dy = 0.0f;
    if (ax < 0.0f) {
        ax = -ax;
    }
    ay = fy < 0.0f ? -fy : fy;
    if (STICK_DEAD < ax) {
        dx = (ax - STICK_DEAD) / 68.0f;
    }
    if (STICK_DEAD < ay) {
        dy = (ay - STICK_DEAD) / 68.0f;
    }
    if (STICK_RX > STICK_DEAD) {
        self->rotOfs.y += dx * -0.04363323f;
        if (self->rotOfs.y < -0.87266463f) {
            self->rotOfs.y = -0.87266463f;
        }
    } else if (STICK_RX < -STICK_DEAD) {
        self->rotOfs.y += dx * 0.04363323f;
        if (0.87266463f < self->rotOfs.y) {
            self->rotOfs.y = 0.87266463f;
        }
    }
    if (STICK_RY > STICK_DEAD) {
        self->rotOfs.x += dy * -0.04363323f;
        if (self->rotOfs.x < -0.69813168f) {
            self->rotOfs.x = -0.69813168f;
        }
    } else if (STICK_RY < -STICK_DEAD) {
        self->rotOfs.x += dy * 0.04363323f;
        if (0.69813168f < self->rotOfs.x) {
            self->rotOfs.x = 0.69813168f;
        }
    }
    VU0_LQC2(4, &self->rotOfs, 0);
    VU0_SQC2(4, &f, 0x40);
    f.v.y = Adjust_theta(f.v.y + self->target->rot[1]);
    MtxInitRotVec(f.mtx, &f.v, 0);
    self->base.eye.x = f.mtx[2][0] + self->base.target.x;
    self->base.eye.y = f.mtx[2][1] + self->base.target.y;
    self->base.eye.z = f.mtx[2][2] + self->base.target.z;
    vecSet(&f.up, 0.0f, 1.0f, 0.0f);
    cVec_copy3(&self->up, &f.up);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013B5F0);
#endif
