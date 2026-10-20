/* NON_MATCHING func_0012DCB8 (sn-2.95.3-136; PARK, 117 diffs): matrix build, corner transform and copies match
 * in shape; retail's min/max loop runs one induction pointer (self + 16*(i+1), 0x110 displacements, counted down
 * from 6) where this splits it into three givs and counts up, costing s7/s8 and a 0xE0 frame. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"

typedef struct Bound12DCB8 {
    char pad00[8];
    unsigned int flags;                 /* 0x08 */
    char pad0C[4];
    cVec min;                           /* 0x10 */
    cVec max;                           /* 0x20 */
    char pad30[0x28];
    float *parent;                      /* 0x58 */
    char pad5C[4];
    cVec pos;                           /* 0x60 */
    cVec trans;                         /* 0x70 */
    cVec rot;                           /* 0x80 */
    cVec rotLocal;                      /* 0x90 */
    cVec scale;                         /* 0xA0 */
    char padB0[0x60];
    cVec corner[8];                     /* 0x110 */
} Bound12DCB8;

extern cVec D_00462F40[8];
extern void MtxInitTransVec(float *dst, cVec *pos);
extern void MtxMulRotVec(float *dst, float *src, cVec *rot, unsigned char order);
extern void MtxMulTransVec(float *dst, float *src, cVec *t);
extern void sceVu0ApplyMatrix(cVec *out, float *mtx, cVec *in);

__attribute__((section(".text.func_0012DCB8")))
void func_0012DCB8(Bound12DCB8 *self)
{
    float mtx[16];
    long t;
    cVec *c;
    cVec *u;
    int i;

    t = self->flags;
    if (((t >> 2) & 1) == 1) {
        MtxMulRotVec(mtx, self->parent, &self->rotLocal, 0);
        MtxMulTransVec(mtx, mtx, &self->trans);
    } else {
        MtxInitTransVec(mtx, &self->pos);
        MtxMulRotVec(mtx, mtx, &self->rot, 0);
        MtxMulTransVec(mtx, mtx, &self->trans);
    }
    u = D_00462F40;
    c = self->corner;
    for (i = 0; i < 8; i++) {
        c->x = u->x * self->scale.x;
        c->y = u->y * self->scale.y;
        c->z = u->z * self->scale.z;
        sceVu0ApplyMatrix(c, mtx, c);
        u++;
        c++;
    }
    cVec_copy3(&self->min, &self->corner[0]);
    cVec_copy3(&self->max, &self->min);
    for (i = 1; i < 8; i++) {
        if (self->corner[i].x < self->min.x)
            self->min.x = self->corner[i].x;
        if (self->corner[i].y < self->min.y)
            self->min.y = self->corner[i].y;
        if (self->corner[i].z < self->min.z)
            self->min.z = self->corner[i].z;
        if (self->max.x < self->corner[i].x)
            self->max.x = self->corner[i].x;
        if (self->max.y < self->corner[i].y)
            self->max.y = self->corner[i].y;
        if (self->max.z < self->corner[i].z)
            self->max.z = self->corner[i].z;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012DCB8);
#endif
