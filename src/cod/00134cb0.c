/* NON_MATCHING func_00134CB0 (sn-2.95.3-136, -ffast-math, sqrt hazard rule): sphere push-out
 * in the ground plane. Retail keeps nothing in the sqrt.s pad and branches over the first
 * return; ours fills a delay slot from the root and keeps &f.b in a0 instead of v0. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"

extern void sceVu0SubVector(void *a0, void *a1, void *a2);
extern void sceVu0Normalize(void *a0, void *a1);
extern void sceVu0ScaleVector(void *dst, void *src, float s);

/* One collision unit in the manager's list. */
typedef struct cCollUnit {
    cOmBase *owner;                     /* 0x00 */
    int unk04;                          /* 0x04 */
    int priority;                       /* 0x08 */
    float share;                        /* 0x0C */
    struct cCollUnit *next;             /* 0x10 */
} cCollUnit;

/* Push unit a's owner out of unit b's sphere in the ground plane; 0 when they do not touch. */
int func_00134CB0(void *mgr, cCollUnit *ua, cCollisionSolidObj *sa, cCollUnit *ub,
                  cCollisionSolidObj *sb)
{
    struct {
        cVec a;                         /* 0x00 */
        cVec b;                         /* 0x10 */
        cVec push;                      /* 0x20 */
    } f;
    cVec *b;
    float dx;
    float dz;
    float r;
    float distSq;
    float depth;
    float keep;

    VU0_LQC2(4, &sa->unk60, 0);
    VU0_SQC2(4, &f, 0);
    VU0_LQC2(4, &sb->unk60, 0);
    VU0_SQC2(4, &f, 0x10);
    b = &f.b;
    dx = b->x - f.a.x;
    dz = b->z - f.a.z;
    r = sa->radius + sb->radius;
    distSq = dx * dx + dz * dz;
    if (r * r < distSq) {
        return 0;
    }
    depth = r - __builtin_sqrtf(distSq);
    if (ua->priority == 0) {
        return 1;
    }
    if (ua->priority == ub->priority) {
        keep = ub->share;
    } else if (ub->priority < ua->priority) {
        keep = 1.0f;
    } else {
        keep = 0.0f;
    }
    sceVu0SubVector(&f.push, &f.a, b);
    sceVu0Normalize(&f.push, &f.push);
    sceVu0ScaleVector(&f.push, &f.push, depth);
    ua->owner->pos->x += f.push.x - f.push.x * (1.0f - keep);
    ua->owner->pos->z += f.push.z - f.push.z * (1.0f - keep);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00134CB0);
#endif
