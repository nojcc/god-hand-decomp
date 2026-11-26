/* NON_MATCHING func_00134CB0 (sn-2.95.3-136, fp_hazard_rules fdiv): 2 instructions off. Retail
 * takes &b->unk60 in v1 for the second centre copy, this C in v0. With CVEC_STORE for that copy
 * (the store goes through the &cb register) 6 differ. */
#include "include_asm.h"
#include "godhand/cCollisionSolid.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cVec.h"
#include "godhand/sceVu0.h"
#include "godhand/fpu.h"

/* Sphere a of unit ua against sphere b of unit ub, in the ground plane: 0 when they don't touch.
 * Else push ua's owner out by its share of the depth, unless its priority is 0, and return 1.
 * self is not read. */
__attribute__((section(".text.func_00134CB0")))
int func_00134CB0(cCollisionSolidManage *self, cCollisionSolidManageUnit *ua, cCollisionSolidObj *a,
                  cCollisionSolidManageUnit *ub, cCollisionSolidObj *b)
{
    cVec ca;
    cVec cb;
    cVec push;
    cVec *q;
    float dx;
    float dz;
    float reach;
    float distSq;
    float dist;
    float depth;
    float keep;

    VU0_LQC2(4, &a->unk60, 0);
    VU0_SQC2_MEM(4, &ca, 0);
    VU0_LQC2(4, &b->unk60, 0);
    VU0_SQC2_MEM(4, &cb, 0);
    q = &cb;
    dx = q->x - ca.x;
    dz = q->z - ca.z;
    reach = a->radius + b->radius;
    distSq = dx * dx + dz * dz;
    if (reach * reach < distSq)
        return 0;
    FPU_SQRT_S(dist, distSq);
    depth = reach - dist;
    if (ua->priority == 0)
        return 1;
    if (ua->priority == ub->priority)
        keep = ub->share;
    else if (ub->priority < ua->priority)
        keep = 1.0f;
    else
        keep = 0.0f;
    sceVu0SubVector(&push, &ca, &cb);
    sceVu0Normalize(&push, &push);
    sceVu0ScaleVector(&push, &push, depth);
    ua->owner->pos->x += push.x - push.x * (1.0f - keep);
    ua->owner->pos->z += push.z - push.z * (1.0f - keep);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00134CB0);
#endif
