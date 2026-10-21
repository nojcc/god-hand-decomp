/* NON_MATCHING func_00134E18 (sn-2.95.3-136, -ffast-math, sqrt hazard rule): sphere against
 * box push-out. Retail keeps nothing in the sqrt.s pad, so the radius load follows the root and
 * the radius test branches over its return; ours schedules the load into the pad and inverts it. */
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

/* An oriented box: centre, three unit axes and the half length along each. */
typedef struct CollOBB {
    cVec center;                        /* 0x00 */
    cVec axis[3];                       /* 0x10 */
    char unk40[0x10];
    float halfLen[3];                   /* 0x50 */
} CollOBB;

/* A box solid with its oriented box past the common record. */
typedef struct cCollisionSolidBox {
    cCollisionSolidObj base;            /* 0x000 */
    char unk74[0x10C];
    CollOBB box;                        /* 0x180 */
} cCollisionSolidBox;

extern void func_00137670(cVec *p, CollOBB *box, cVec *out);

/* Push apart sphere unit a and box unit b in the ground plane, moving b's owner when
 * moveBox is set and a's otherwise; 0 when they do not touch. */
int func_00134E18(void *mgr, cCollUnit *ua, cCollisionSolidObj *sa, cCollUnit *ub,
                  cCollisionSolidBox *sb, int moveBox)
{
    struct {
        cVec c;                         /* 0x00 sphere centre */
        cVec q;                         /* 0x10 nearest box point */
        cVec push;                      /* 0x20 */
    } f;
    CollOBB *box;
    cVec *q;
    float dx;
    float dz;
    float d;
    float depth;
    float keep;

    VU0_LQC2(4, &sa->unk60, 0);
    VU0_SQC2(4, &f, 0x00);
    box = &sb->box;
    VU0_SQC2_VF0(&f, 0x10);
    q = &f.q;
    func_00137670(&f.c, box, q);
    dx = f.c.x - q->x;
    dz = f.c.z - q->z;
    d = __builtin_sqrtf(dx * dx + dz * dz);
    if (sa->radius < d) {
        return 0;
    }
    if (moveBox == 0) {
        if (ua->priority == 0) {
            return 1;
        }
        depth = sa->radius - d;
        if (ua->priority == ub->priority) {
            keep = ub->share;
        } else if (ub->priority < ua->priority) {
            keep = 1.0f;
        } else {
            keep = 0.0f;
        }
        sceVu0SubVector(&f.push, &f.c, q);
        sceVu0Normalize(&f.push, &f.push);
        sceVu0ScaleVector(&f.push, &f.push, depth);
        ua->owner->pos->x += f.push.x - f.push.x * (1.0f - keep);
        ua->owner->pos->z += f.push.z - f.push.z * (1.0f - keep);
    } else {
        if (ub->priority == 0) {
            return 1;
        }
        depth = sa->radius - d;
        if (ub->priority == ua->priority) {
            keep = ua->share;
        } else if (ua->priority < ub->priority) {
            keep = 1.0f;
        } else {
            keep = 0.0f;
        }
        sceVu0SubVector(&f.push, q, &f.c);
        sceVu0Normalize(&f.push, &f.push);
        sceVu0ScaleVector(&f.push, &f.push, depth);
        ub->owner->pos->x += f.push.x - f.push.x * (1.0f - keep);
        ub->owner->pos->z += f.push.z - f.push.z * (1.0f - keep);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00134E18);
#endif
