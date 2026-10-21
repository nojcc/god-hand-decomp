/* NON_MATCHING func_00135040 (sn-2.95.3-136, -ffast-math, sqrt hazard rule): push-out against
 * a solid's reference point. Retail keeps nothing in the sqrt.s pad, so the reach load and the
 * zero constant follow the root and the return test is a plain bc1t; ours schedules them into
 * the pad and inverts the test into bc1fl. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cCollisionSolid.h"

extern int func_00136A88(cVec *a, cVec *b, float *reach);
extern void sceVu0SubVector(void *a0, void *a1, void *a2);
extern void sceVu0Normalize(void *a0, void *a1);
extern void sceVu0ScaleVector(void *dst, void *src, float s);

static __inline__ float cVec_dist(cVec *a, cVec *b)
{
    float dx = b->x - a->x;
    float dy = b->y - a->y;
    float dz = b->z - a->z;

    return __builtin_sqrtf(dx * dx + dy * dy + dz * dz);
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

/* Push unit a's owner out of unit b's solid in the ground plane; 0 when they do not touch. */
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
#else
INCLUDE_ASM("asm/nonmatching", func_00135040);
#endif
