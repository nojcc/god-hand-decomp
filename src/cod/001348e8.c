/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"

#define CSOLID_FLAG_ACTIVE  0x1
#define CSOLID_FLAG_HIT     0x2         /* set on both solids of a touching pair */
#define CSOLID_KIND_SPHERE  1
#define CSOLID_KIND_BOX     3
#define CSOLID_HIT_MAX      32
#define CSOLID_BOUND        10000.0f

typedef struct cCollisionSolidVt {
    char unk00[0x18];
    short calcBoundsDelta;              /* 0x18 */
    short pad1A;
    void (*calcBounds)(void *self);     /* 0x1C refresh min/max */
} cCollisionSolidVt;

typedef struct cCollisionSolidBody {
    struct cCollisionSolidBody *next;   /* 0x00 next solid of the unit */
    int kind;                           /* 0x04 CSOLID_KIND_* */
    unsigned int flags;                 /* 0x08 CSOLID_FLAG_* */
    char unk0C[4];
    cVec min;                           /* 0x10 */
    cVec max;                           /* 0x20 */
    cCollisionSolidVt *vt;              /* 0x30 */
} cCollisionSolidBody;

typedef struct cCollisionSolidUnit {
    cGameObj *owner;                    /* 0x00 */
    cCollisionSolidBody *first;         /* 0x04 */
    char unk08[8];
    struct cCollisionSolidUnit *next;   /* 0x10 */
    char unk14[0xC];
    cVec min;                           /* 0x20 bounds of all its solids */
    cVec max;                           /* 0x30 */
} cCollisionSolidUnit;

typedef struct cCollisionSolidManage {
    cCollisionSolidUnit *first;         /* 0x00 */
    char unk04[4];
    cGameObj *hits[CSOLID_HIT_MAX];     /* 0x08 owners hit by the last check */
    unsigned int hitNum;                /* 0x88 */
} cCollisionSolidManage;

extern cCollisionSolidUnit *func_001346C8(cCollisionSolidManage *self, cGameObj *obj);
extern int func_00135250(void *unused, float *a1, float *a2, float *a3, float *t0);
extern int func_00134CB0(cCollisionSolidManage *self, cCollisionSolidUnit *ua, cCollisionSolidBody *a,
                         cCollisionSolidUnit *ub, cCollisionSolidBody *b);
extern int func_00134E18(cCollisionSolidManage *self, cCollisionSolidUnit *ua, cCollisionSolidBody *a,
                         cCollisionSolidUnit *ub, cCollisionSolidBody *b, int swapped);
extern int func_00135040(cCollisionSolidManage *self, cCollisionSolidUnit *ua, cCollisionSolidBody *a,
                         cCollisionSolidUnit *ub, cCollisionSolidBody *b);

/* cCollisionSolidManage_ChkHit: refresh the bounds of obj's unit, test each of its
 * active solids against the active solids of every other unit, flag the touching
 * pairs, list up to 32 owners hit and return 1 on any hit. */
__attribute__((section(".text.cCollisionSolidManage_ChkHit")))
int cCollisionSolidManage_ChkHit(cCollisionSolidManage *self, cGameObj *obj)
{
    cVec min;
    cVec max;
    cCollisionSolidUnit *unit;
    cCollisionSolidUnit *other;
    cCollisionSolidBody *a;
    cCollisionSolidBody *b;
    unsigned int i;
    int ret;
    int hit;
    long scr = (unsigned int)obj->scrFlags;
    long bit2 = scr >> 2 & 1;           /* scrFlags bit 2, not named yet */
    long suspended;

    if (bit2 != 0)
        return 0;
    suspended = scr >> 3 & 1;
    if (suspended != 0)
        return 0;
    ret = 0;
    for (i = 0; i < CSOLID_HIT_MAX; i++)
        self->hits[i] = 0;
    self->hitNum = 0;
    unit = func_001346C8(self, obj);
    if (unit == 0)
        return 0;
    cVec_set4(&min, CSOLID_BOUND, CSOLID_BOUND, CSOLID_BOUND, 1.0f);
    cVec_set4(&max, -CSOLID_BOUND, -CSOLID_BOUND, -CSOLID_BOUND, 1.0f);
    for (b = unit->first; b != 0; b = b->next) {
        b->vt->calcBounds((char *)b + b->vt->calcBoundsDelta);
        if (b->min.x < min.x) min.x = b->min.x;
        if (min.y > b->min.y) min.y = b->min.y;
        if (min.z > b->min.z) min.z = b->min.z;
        if (max.x < b->max.x) max.x = b->max.x;
        if (max.y < b->max.y) max.y = b->max.y;
        if (max.z < b->max.z) max.z = b->max.z;
    }
    cVec_copy3(&unit->min, &min);
    cVec_copy3(&unit->max, &max);
    for (a = unit->first; a != 0; a = a->next) {
        long active = (unsigned int)a->flags;

        if ((active & CSOLID_FLAG_ACTIVE) == 0)
            continue;
        for (other = self->first; other != 0; other = other->next) {
            long oscr;
            long osuspended;

            if (unit == other)
                continue;
            oscr = (unsigned int)other->owner->scrFlags;
            osuspended = oscr >> 3 & 1;
            if (osuspended != 0)
                continue;
            if (func_00135250(self, &unit->min.x, &unit->max.x, &other->min.x, &other->max.x) == 0)
                continue;
            for (b = other->first; b != 0; b = b->next) {
                long bactive = (unsigned int)b->flags;

                if ((bactive & CSOLID_FLAG_ACTIVE) == 0)
                    continue;
                hit = 0;
                if (a->kind == CSOLID_KIND_SPHERE) {
                    if (b->kind == CSOLID_KIND_SPHERE) {
                        if (func_00134CB0(self, unit, a, other, b) != 0)
                            hit = 1;
                    } else if (b->kind == CSOLID_KIND_BOX) {
                        if (func_00134E18(self, unit, a, other, b, 0) != 0)
                            hit = 1;
                    }
                } else if (a->kind == CSOLID_KIND_BOX) {
                    if (b->kind == CSOLID_KIND_SPHERE) {
                        if (func_00134E18(self, other, b, unit, a, 1) != 0)
                            hit = 1;
                    } else if (b->kind == CSOLID_KIND_BOX) {
                        if (func_00135040(self, unit, a, other, b) != 0)
                            hit = 1;
                    }
                }
                if (hit == 0)
                    continue;
                if (other->owner != 0 && self->hitNum < CSOLID_HIT_MAX) {
                    self->hits[self->hitNum] = other->owner;
                    self->hitNum++;
                }
                ret = 1;
                a->flags |= CSOLID_FLAG_HIT;
                b->flags |= CSOLID_FLAG_HIT;
            }
        }
    }
    return ret;
}
