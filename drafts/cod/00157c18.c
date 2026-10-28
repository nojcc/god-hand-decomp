/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING: 338 words against retail's 351. Retail's frame is 0x20
 * bigger: it saves one more register and stores the clamp's upper bound,
 * frameNum - 1.0f, to 0x40(sp) without reading it back (a by-reference
 * min/max temporary). self and &unk310 trade s0/s1. */
#include "godhand/cObjBase.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/gameWork.h"
#include "godhand/cVec.h"

#define MOTION_F_HOLD      0x01         /* the frame doesn't advance */
#define MOTION_F_REVERSE   0x04
#define MOTION_F_ONCE      0x08         /* a looping motion stops at its end */
#define MOTION_F_NULLMOVE  0x10         /* the null part's step moves the first child */
#define MTB_LOOP           0x01

/* The head of an mtb3 motion. */
typedef struct cMtbHead {
    char magic[4];                      /* 0x0 "mtb3" */
    unsigned short frameNum;            /* 0x4 */
    char unk6;
    unsigned char flags;                /* 0x7 MTB_* */
} cMtbHead;

extern char D_0041EE40[];               /* "mtb3" */

int func_003A50B4(const void *a, const void *b, int n);
void Motion_seq_ctr(cObjBase *self, char *seq);
void func_00158328(cObjBase *self);
void func_00150778(float *d, float *a, float *b);
void func_00150738(float *d, float *a, float *b);
void VecRotVec(float *out, float *in, cVec *rot, int order);

#ifdef NON_MATCHING
/* Advance the object's mtb3 motion one frame: run its sequence, count down
 * the blend-in, apply the blend, move the null part's step to the first child,
 * turn the null part's speed into model space, and step the frame forward or
 * back. Returns 0 while the motion runs (or when there is none), 1 when it
 * isn't an mtb3 motion or has reached its end (wrapping a looping one). */
__attribute__((section(".text.moveMotion")))
int moveMotion(cObjBase *self)
{
    int frame[3];
    cVec rot;
    CVEC_TEMPS;
    cMtbHead *mtb;
    cOmBase *child;
    float rate;
    float step;
    float blend;
    float t;
    unsigned short flags;
    int n;

    if (self->motion == 0)
        return 0;
    if (func_003A50B4(self->motion, D_0041EE40, 4) != 0)
        return 1;
    Motion_seq_ctr(self, self->motionEnd);
    rate = D_007474A0.timeScale;
    if (D_007474A0.unk569 == 1)
        rate *= 0.5f;
    step = self->motionSpeed * self->motionRate * rate;

    if ((self->motionFlags & MOTION_F_NULLMOVE) && self->motionStart > 0.0f) {
        child = cObjBase_childAt(self, frame, 0);
        if (child != 0)
            func_00150778(&child->anchor->x, &child->anchor->x, &self->unk310.x);
        self->unk310.x = 0.0f;
        self->unk310.y = 0.0f;
        self->unk310.z = 0.0f;
    }
    t = self->motionStart - step;
    if (t < 0.0f)
        t = 0.0f;
    self->motionStart = t;
    blend = 0.0f;
    if (t > 0.0f)
        blend = t / self->motionLen;
    func_00158328(self);
    self->blend = blend;
    if (self->motionFlags & MOTION_F_NULLMOVE) {
        child = cObjBase_childAt(self, frame, 0);
        if (child != 0)
            func_00150738(&child->anchor->x, &child->anchor->x, &self->unk310.x);
        self->unk310.x = 0.0f;
        self->unk310.y = 0.0f;
        self->unk310.z = 0.0f;
    }

    CVEC_COPY(rot, (cVec *)self->quat);
    rot.y = -rot.y;
    CVEC_SET_SUB(self->nullSpeed, &self->unk310, &self->unk320);
    CVEC_ASSIGN(self->unk320, &self->unk310);
    VecRotVec(&self->nullSpeed.x, &self->nullSpeed.x, &rot, 0);
    ret_.x = self->quat[0] - self->unk350.x;
    ret_.y = self->quat[1] - self->unk350.y;
    ret_.z = self->quat[2] - self->unk350.z;
    ret_.w = self->quat[3] - self->unk350.w;
    self->nullRotSpeed.x = ret_.x;
    self->nullRotSpeed.y = ret_.y;
    self->nullRotSpeed.z = ret_.z;
    Adjust_theta_vec(&self->nullRotSpeed);
    self->unk350.x = self->quat[0];
    self->unk350.y = self->quat[1];
    self->unk350.z = self->quat[2];
    self->unk350.w = self->quat[3];
    CVEC_SET_SUB(self->unk390, &self->unk370, &self->unk380);
    CVEC_ASSIGN(self->unk380, &self->unk370);

    if (!(self->motionFlags & MOTION_F_HOLD)) {
        self->motionBlend += step;
        if (step == 1.0f)
            self->motionBlend = (int)(self->motionBlend + 0.0001f);
    }
    flags = self->motionFlags;
    mtb = (cMtbHead *)self->motion;
    if (flags & MOTION_F_REVERSE) {
        if (!(flags & MOTION_F_HOLD) ? !(self->motionBlend <= 0.0f) : !(self->motionBlend < 0.0f))
            return 0;
        if (!(mtb->flags & MTB_LOOP)) {
            self->motionBlend = 0.0f;
        } else if (flags & MOTION_F_ONCE) {
            self->motionBlend = 0.0f;
        } else {
            self->unk320.x = 0.0f;
            self->unk320.y = 0.0f;
            self->unk320.z = 0.0f;
            self->unk350.x = 0.0f;
            self->unk350.y = 0.0f;
            self->unk350.z = 0.0f;
            self->motionBlend = (float)(mtb->frameNum - 1) - self->motionRate * rate;
        }
    } else {
        n = mtb->frameNum;
        if (!(flags & MOTION_F_HOLD) ? self->motionBlend <= (float)(n - 1) : !((float)(n - 1) < self->motionBlend))
            return 0;
        if ((mtb->flags & MTB_LOOP) && !(flags & MOTION_F_ONCE)) {
            t = self->motionBlend - (float)(n - 1);
            blend = mtb->frameNum - 1.0f;
            if (t < 0.0f)
                t = 0.0f;
            if (t < blend)
                blend = t;
            self->motionBlend = blend;
            self->unk350.z = 0.0f;
            self->unk320.x = 0.0f;
            self->unk320.y = 0.0f;
            self->unk320.z = 0.0f;
            self->unk350.x = 0.0f;
            self->unk350.y = 0.0f;
        } else {
            self->motionBlend = n - 1.0f;
        }
    }
    if (self->seqSkip < 0xFF)
        self->seqSkip++;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", moveMotion);
#endif
