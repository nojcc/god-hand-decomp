/* sn-2.95.3-136 */
/*
 * NON_MATCHING: same length as retail (616 words), 14 instructions differ,
 * all in reload register choice. Retail reloads the spilled part count
 * (0x10(sp)) and materializes the 0x800000 and 0x100000 masks of the first
 * part-flag tests into $a1; here they go to $v0/$v1, so reorg can't skip the
 * redundant count reload at the two scale-skip branches to the loop latch
 * (retail fills those delay slots with the i + 1 move instead).
 * The handler calls read prm for the table index and pass prm++ in one
 * expression; the inline evaluator form is 12 words longer.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cObjBase.h"
#include "godhand/cModel.h"
#include "godhand/motion.h"

/* The table's handlers read the frame in $f12 (func_00158CD0). */
typedef float (*MotionParamTimeFn)(MotionData *mot, MotionParam *prm, float t);

/* MotionParam.sub: the channel a parameter drives. */
#define MOTION_CH_POS_X    0U
#define MOTION_CH_POS_Y    1U
#define MOTION_CH_POS_Z    2U
#define MOTION_CH_ROT_X    3U
#define MOTION_CH_ROT_Y    4U
#define MOTION_CH_ROT_Z    5U
#define MOTION_CH_SCALE_X  6U
#define MOTION_CH_SCALE_Y  7U
#define MOTION_CH_SCALE_Z  8U

#define PART_CURVE(p, n) ((char *)(p) + 0x1B4 + (n) * 0x20)

float func_00159AD0(void *curve, char *motion, MotionParam *prm, float t);


/* cOmBase_childAtIdx (cOmBase.h) for a cObjBase. */
static __inline__ struct cOmBase *cObjBase_childAtIdx(struct cObjBase *b, int *frame, int idx)
{
    int n;
    long in = 0;

    *frame = n = b->partNum;
    if (idx >= 0) {
        int below = idx < n;

        in = below;
    }
    if (in & 0xFF) {
        return b->children[idx];
    }
    return 0;
}

/* Evaluates the playing motion at the current frame: the root's translation,
 * rotation and scale, then the position, rotation and scale channels of each
 * part (mirrored when motion flag 2 is set). */
void func_00158328(cObjBase *self)
{
    int frame[3];
    char *mot;
    MotionParam *prm;
    float t;
    float v;
    int mirror;
    int i;
    int n;
    cParts *part;
    cParts *dst;
    int flip;
    int flipRot;

    mot = self->motion;
    mirror = (self->motionFlags >> 1) & 1;
    prm = ((MotionData *)mot)->param;
    t = self->motionFrame;

    if (prm->kind == -1 && prm->sub == MOTION_CH_POS_X) {
        v = func_00159AD0(PART_CURVE(self, 0), mot, prm++, t);
    } else {
        v = 0.0f;
    }
    self->unk310.x = v;
    if (mirror)
        self->unk310.x = -v;
    if (prm->kind == -1 && prm->sub == MOTION_CH_POS_Y) {
        v = func_00159AD0(PART_CURVE(self, 1), mot, prm++, t);
    } else {
        v = 0.0f;
    }
    self->unk310.y = v;
    if (prm->kind == -1 && prm->sub == MOTION_CH_POS_Z) {
        v = func_00159AD0(PART_CURVE(self, 2), mot, prm++, t);
    } else {
        v = 0.0f;
    }
    self->unk310.z = v;

    if (prm->kind == -1 && prm->sub == MOTION_CH_ROT_X) {
        v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
    } else {
        v = 0.0f;
    }
    self->quat[0] = v;
    if (prm->kind == -1 && prm->sub == MOTION_CH_ROT_Y) {
        v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
    } else {
        v = 0.0f;
    }
    self->quat[1] = v;
    if (prm->kind == -1 && prm->sub == MOTION_CH_ROT_Z) {
        v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
    } else {
        v = 0.0f;
    }
    self->quat[2] = v;
    Adjust_theta_vec((cVec *)self->quat);
    if (mirror) {
        self->quat[1] = -self->quat[1];
        self->quat[2] = -self->quat[2];
    }

    if (prm->kind == -1 && prm->sub == MOTION_CH_SCALE_X) {
        v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
    } else {
        v = 1.0f;
    }
    self->unk370.x = v;
    if (prm->kind == -1 && prm->sub == MOTION_CH_SCALE_Y) {
        v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
    } else {
        v = 1.0f;
    }
    self->unk370.y = v;
    if (prm->kind == -1 && prm->sub == MOTION_CH_SCALE_Z) {
        v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
    } else {
        v = 1.0f;
    }
    self->unk370.z = v;

    n = self->partNum;
    for (i = 0; i < n; i++) {
        part = (cParts *)cObjBase_childAtIdx(self, frame, i);
        dst = part;
        if (dst->partFlags & 0x2000)
            dst->partFlags |= 0x400000;
        if (dst->partFlags & CPARTS_ZERO_UNKEYED_ROT)
            dst->partFlags |= 0x200000;
        flip = mirror && dst->link != 0 && !(dst->partFlags & 0x800000);
        flipRot = 0;
        if (mirror && part->link != 0 && !(part->partFlags & 0x800000)) {
            if (!(part->partFlags & 0x2000000))
                if (!(part->partFlags & 0x1000000))
                    flipRot = 1;
        }
        if (flip)
            dst = part->link;
        dst->partFlags &= ~CPARTS_MOTION_SET;

        if (dst->partFlags & CPARTS_NO_MOTION) {
            while (prm->kind == i)
                prm++;
            continue;
        }

        if (!(dst->partFlags & CPARTS_NO_MOTION_POS)) {
            if (prm->kind == i && prm->sub == MOTION_CH_POS_X) {
                v = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
                dst->anchor->x = flip ? -v : v;
                dst->partFlags |= CPARTS_MOTION_SET;
            } else if (self->blend > 0.0f && !(dst->partFlags & CPARTS_NO_BLEND)) {
                dst->anchor->x = dst->trans.x;
            }
            if (prm->kind == i && prm->sub == MOTION_CH_POS_Y) {
                dst->anchor->y = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
                dst->partFlags |= CPARTS_MOTION_SET;
            } else if (self->blend > 0.0f && !(dst->partFlags & CPARTS_NO_BLEND)) {
                dst->anchor->y = dst->trans.y;
            }
            if (prm->kind == i && prm->sub == MOTION_CH_POS_Z) {
                dst->anchor->z = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
                dst->partFlags |= CPARTS_MOTION_SET;
            } else if (self->blend > 0.0f && !(dst->partFlags & CPARTS_NO_BLEND)) {
                dst->anchor->z = dst->trans.z;
            }
        } else {
            if (prm->kind == i && prm->sub == MOTION_CH_POS_X)
                prm++;
            if (prm->kind == i && prm->sub == MOTION_CH_POS_Y)
                prm++;
            if (prm->kind == i && prm->sub == MOTION_CH_POS_Z)
                prm++;
        }

        if (!(((unsigned char *)&dst->partFlags)[1] & 1)) {
            unsigned long b;

            if (prm->kind == i && prm->sub == MOTION_CH_ROT_X) {
                dst->rot.x = func_00159AD0(PART_CURVE(dst, 0), mot, prm++, t);
                dst->partFlags |= CPARTS_MOTION_SET;
            } else {
                b = ((unsigned char *)&dst->partFlags)[1];
                if (b >> 7)
                    dst->rot.x = 0.0f;
            }
            if (prm->kind == i && prm->sub == MOTION_CH_ROT_Y) {
                dst->rot.y = func_00159AD0(PART_CURVE(dst, 1), mot, prm++, t);
                if (flipRot)
                    dst->rot.y = -dst->rot.y;
                dst->partFlags |= CPARTS_MOTION_SET;
            } else {
                b = ((unsigned char *)&dst->partFlags)[1];
                if (b >> 7)
                    dst->rot.y = 0.0f;
            }
            if (prm->kind == i && prm->sub == MOTION_CH_ROT_Z) {
                dst->rot.z = func_00159AD0(PART_CURVE(dst, 2), mot, prm++, t);
                if (flipRot)
                    dst->rot.z = -dst->rot.z;
                dst->partFlags |= CPARTS_MOTION_SET;
            } else {
                b = ((unsigned char *)&dst->partFlags)[1];
                if (b >> 7)
                    dst->rot.z = 0.0f;
            }
        } else {
            if (prm->kind == i && prm->sub == MOTION_CH_ROT_X)
                prm++;
            if (prm->kind == i && prm->sub == MOTION_CH_ROT_Y)
                prm++;
            if (prm->kind == i && prm->sub == MOTION_CH_ROT_Z)
                prm++;
        }

        if (!(dst->partFlags & CPARTS_NO_MOTION_SCALE)) {
            if (prm->kind == i && prm->sub == MOTION_CH_SCALE_X) {
                dst->scale.x = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
                dst->partFlags |= CPARTS_MOTION_SET;
            }
            if (prm->kind == i && prm->sub == MOTION_CH_SCALE_Y) {
                dst->scale.y = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
                dst->partFlags |= CPARTS_MOTION_SET;
            }
            if (prm->kind == i && prm->sub == MOTION_CH_SCALE_Z) {
                dst->scale.z = ((MotionParamTimeFn)D_003BD910[prm->func])((MotionData *)mot, prm++, t);
                dst->partFlags |= CPARTS_MOTION_SET;
            }
        } else {
            if (prm->kind == i && prm->sub == MOTION_CH_SCALE_X)
                prm++;
            if (prm->kind == i && prm->sub == MOTION_CH_SCALE_Y)
                prm++;
            if (prm->kind == i && prm->sub == MOTION_CH_SCALE_Z)
                prm++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00158328);
#endif
