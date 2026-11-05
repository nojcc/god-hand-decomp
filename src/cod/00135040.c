/* sn-2.95.3-136 */
#include "godhand/fpu.h"
#include "godhand/cOmBase.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/sceVu0.h"

extern int func_00136A88(cVec *a, cVec *b, float *reach);

static __inline__ float cVec_dist(cVec *a, cVec *b)
{
    float dx = b->x - a->x;
    float dy = b->y - a->y;
    float dz = b->z - a->z;
    float d;

    FPU_SQRT_S(d, dx * dx + dy * dy + dz * dz);
    return d;
}

/* One collision unit in the manager's list. */
typedef struct cCollUnit {
    cOmBase *owner;                     /* 0x00 */
    int unk04;                          /* 0x04 */
    int priority;                       /* 0x08 */
    float share;                        /* 0x0C */
    struct cCollUnit *next;             /* 0x10 */
} cCollUnit;

/* A solid body with its reference point past the common record. */
typedef struct cCollisionSolidPt {
    cCollisionSolidObj base;            /* 0x000 */
    char unk74[0x10C];
    cVec point;                         /* 0x180 */
} cCollisionSolidPt;

/* Push unit a's owner out of unit b's solid in the ground plane; 0 when they do not touch. The
 * root in cVec_dist is FPU_SQRT_S: with __builtin_sqrtf cc1 schedules the reach load and the
 * zero into the root's pad and inverts the return test. mgr, the collision manager its callers
 * pass, is not read. */
__attribute__((section(".text.func_00135040")))
int func_00135040(void *mgr, cCollUnit *ua, cCollisionSolidPt *sa, cCollUnit *ub,
                  cCollisionSolidPt *sb)
{
    cVec push;
    float reach;
    cVec *pa = &sa->point;
    cVec *pb = &sb->point;
    float depth;
    float keep;

    if (func_00136A88(pa, pb, &reach) == 0) {
        return 0;
    }
    depth = reach - cVec_dist(pa, pb);
    if (depth <= 0.0f) {
        return 0;
    }
    if (ua->priority == 0) {
        return 1;
    }
    sceVu0SubVector(&push, pa, pb);
    sceVu0Normalize(&push, &push);
    sceVu0ScaleVector(&push, &push, depth);
    if (ua->priority == ub->priority) {
        keep = ub->share;
    } else if (ub->priority < ua->priority) {
        keep = 1.0f;
    } else {
        keep = 0.0f;
    }
    ua->owner->pos->x += push.x - push.x * (1.0f - keep);
    ua->owner->pos->z += push.z - push.z * (1.0f - keep);
    return 1;
}
