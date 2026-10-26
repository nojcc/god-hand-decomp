/* sn-2.95.3-136, fp_hazard_rules fdiv */
/* func_001B51B0. 27 instructions differ: retail builds &tmp in $s1 only after
 * the subtraction (here the helper parameter makes it early), adds the node
 * offset as (node << 4) + nodes into $v0, and reaches the return-0 exit and
 * the end-of-path branch with branch-likely delay slots. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/gameWork.h"
#include "godhand/sceVu0.h"

#ifdef NON_MATCHING
#define PATH_REVERSE 0x1                /* pathFlags: walking the nodes backward */
#define PATH_LOOP    0x2                /* pathFlags: turn around at either end */

/* An object that walks a list of path nodes; no header type yet. */
typedef struct PathMover {
    cGameObj base;
    char unk5AC[0x600 - 0x5AC];
    int pathFlags;                      /* 0x600 PATH_* */
    cVec *nodes;                        /* 0x604 */
    unsigned short nodeNum;             /* 0x608 */
    unsigned short node;                /* 0x60A the node it walks to */
    float radius;                       /* 0x60C */
    float speed;                        /* 0x610 */
} PathMover;

/* *ret = a - b (x, y, z; w zero), built in tmp first. */
static __inline__ void cVec_subTo(cVec *ret, cVec *a, cVec *b, cVec *tmp)
{
    VU0_ZERO_VSUB_XYZ_TO(tmp, 0, a, b);
    VU0_LQC2_SQC2_MEM(4, ret, tmp);
}

/* *ret = v scaled to length 1, built in tmp first. */
static __inline__ void cVec_unitTo(cVec *ret, cVec *v, cVec *tmp)
{
    cVec_unitOf(tmp, v);
    VU0_LQC2_SQC2_MEM(4, ret, tmp);
}

/* Steps toward the current node; on reaching it picks the next one and
 * returns 1. Returns 0 without nodes or while the node is still ahead. */
__attribute__((section(".text.func_001B51B0")))
int func_001B51B0(PathMover *self)
{
    cVec dir;
    cVec step;
    cVec diff;
    cVec tmp;
    cVec *goal;
    float rate;
    float dx;
    float dz;
    long flags;
    long loop;
    long reverse;

    if (self->nodes == 0)
        return 0;
    cVec_zero(&dir);
    cVec_subTo(&diff, &self->nodes[self->node], self->base.pos, &tmp);
    cVec_unitTo(&step, &diff, &tmp);
    cVec_copy3(&dir, &step);
    rate = self->speed * cEmManage_GetSpeedRate(&D_005864F0) * D_007474A0.timeScale;
    VU0_LQC2_SQC2_MEM(4, &diff, &dir);
    VU0_VSCALE_XYZ_MEM(&diff, 0, rate);
    VU0_LQC2_SQC2_MEM(4, &step, &diff);
    VU0_VADD_XYZ_IP(self->base.pos, 0, &step);
    goal = &self->nodes[self->node];
    dx = goal->x - self->base.pos->x;
    dz = goal->z - self->base.pos->z;
    if (dx * dx + dz * dz <= self->radius * self->radius * 1.5f) {
        cVec_copy3(self->base.pos, goal);
        flags = (unsigned int)self->pathFlags;
        loop = flags >> 1 & 1;
        if (loop != 0) {
            reverse = flags & PATH_REVERSE;
            if (reverse != 0) {
                if (self->node == 0) {
                    self->node++;
                    self->pathFlags &= ~PATH_REVERSE;
                } else {
                    self->node--;
                }
            } else if (self->node == self->nodeNum - 1) {
                self->pathFlags |= PATH_REVERSE;
                self->node = self->nodeNum - 2;
            } else {
                self->node++;
            }
        } else {
            reverse = flags & PATH_REVERSE;
            if (reverse != 0) {
                if (self->node != 0)
                    self->node--;
            } else if (self->node < self->nodeNum - 1) {
                self->node++;
            }
        }
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001B51B0);
#endif
