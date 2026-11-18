/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vecInline.h"

extern void func_001B6FB8(cOmBase *self);
extern int func_0012EAD8(void *a0, void *a1, void *a2, float *a3, float *t0,
                         float *t1, float *t2, float *t3,
                         float *s0, float *s1, float *s2, float *s3);
extern char D_005CAE50[];

/* A map object with a solid box registered in the collision list. */
typedef struct cOmBoxColl {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    int collision;                      /* 0x600 collision handle */
} cOmBoxColl;

/* The six axis vectors a box registers with. */
typedef struct cBoxAxes {
    cVec v[6];
} cBoxAxes;

extern cBoxAxes D_00427758;

/* Register a 1.5 x 0.2 x 1.5 box with the collision list, its half extents half the height; returns 1. */
__attribute__((section(".text.func_001A83E0")))
int func_001A83E0(cOmBoxColl *self)
{
    cVec size;
    cVec center;
    cVec half;
    cVec zero;
    cBoxAxes ax;
    float *mtx;

    func_001B6FB8(&self->base);
    vec4_set_point(&size.x, 1.5f, 0.2f, 1.5f);
    vec4_set_point(&center.x, size.x, size.y, size.z);
    vec4_set_point(&half.x, 0.0f, size.y * 0.5f, 0.0f);
    vec4_set_point(&zero.x, 0.0f, 0.0f, 0.0f);
    ax = D_00427758;
    mtx = self->base.mtx;
    self->collision = func_0012EAD8(D_005CAE50, self, mtx, &half.x, &zero.x, &center.x,
                                    &ax.v[0].x, &ax.v[1].x, &ax.v[2].x, &ax.v[3].x, &ax.v[4].x, &ax.v[5].x);
    return 1;
}
