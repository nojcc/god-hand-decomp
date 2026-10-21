/* NON_MATCHING func_00133BC8 (sn-2.95.3-136): rebuild a box body's world corners and bounds.
 * Retail keeps self in s0 and the corner pointers in s2/s1, and passes a fresh sp+0x40 to
 * func_0030A548; ours keeps self in s1 and reuses the copy base register. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void func_0030A548(void *dst, void *src);

#define CBOX_FLAG_DIRTY  0x2            /* cleared once the world corners are rebuilt */

/* A box collision body: eight local corners carried by a parent matrix. */
typedef struct cCollisionBox {
    int unk00;                          /* 0x000 */
    int state;                          /* 0x004 */
    int flags;                          /* 0x008 */
    char unk0C[4];
    cVec min;                           /* 0x010 bounding box */
    cVec max;                           /* 0x020 */
    char unk30[0x10];
    float (*parent)[4];                 /* 0x040 parent matrix */
    char unk44[0xC];
    cVec pos;                           /* 0x050 position in the parent */
    cVec unk60;                         /* 0x060 */
    cVec local[8];                      /* 0x070 corners in the box frame */
    cVec world[8];                      /* 0x0F0 corners in the world */
    float radius;                       /* 0x170 bounding radius */
    char unk174[0xC];
    cVec center;                        /* 0x180 world centre */
    float mtx[4][4];                    /* 0x190 copy of the parent matrix */
    cVec unk1D0;                        /* 0x1D0 */
} cCollisionBox;

/* Rebuild the box's world corners, centre and bounding box from its parent matrix. */
void func_00133BC8(cCollisionBox *self)
{
    struct {
        float m[4][4];                  /* 0x00 parent times the box offset */
        float parent[4][4];             /* 0x40 */
    } f;
    float (*pm)[4];
    cVec *src;
    cVec *dst;
    int i;
    float r;

    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, &f, 0x30);
    VU0_SQC2(5, &f, 0x20);
    VU0_SQC2(6, &f, 0x10);
    VU0_SQC2(7, &f, 0x00);
    f.m[3][0] = self->pos.x;
    f.m[3][1] = self->pos.y;
    f.m[3][2] = self->pos.z;
    pm = self->parent;
    VU0_LQC2(4, pm, 0x00);
    VU0_LQC2(5, pm, 0x10);
    VU0_LQC2(6, pm, 0x20);
    VU0_LQC2(7, pm, 0x30);
    VU0_LQC2(8, &f, 0x00);
    VU0_LQC2(9, &f, 0x10);
    VU0_LQC2(10, &f, 0x20);
    VU0_LQC2(11, &f, 0x30);
    VU0_VMULAX_XYZW(4, 8);
    VU0_VMADDAY_XYZW(5, 8);
    VU0_VMADDAZ_XYZW(6, 8);
    VU0_VMADDW_XYZW(12, 7, 8);
    VU0_VMULAX_XYZW(4, 9);
    VU0_VMADDAY_XYZW(5, 9);
    VU0_VMADDAZ_XYZW(6, 9);
    VU0_VMADDW_XYZW(13, 7, 9);
    VU0_VMULAX_XYZW(4, 10);
    VU0_VMADDAY_XYZW(5, 10);
    VU0_VMADDAZ_XYZW(6, 10);
    VU0_VMADDW_XYZW(14, 7, 10);
    VU0_VMULAX_XYZW(4, 11);
    VU0_VMADDAY_XYZW(5, 11);
    VU0_VMADDAZ_XYZW(6, 11);
    VU0_VMADDW_XYZW(15, 7, 11);
    VU0_SQC2(12, &f, 0x00);
    VU0_SQC2(13, &f, 0x10);
    VU0_SQC2(14, &f, 0x20);
    VU0_SQC2(15, &f, 0x30);
    src = self->local;
    dst = self->world;
    for (i = 0; i < 8; i++) {
        sceVu0ApplyMatrix(dst++, f.m, src++);
    }
    sceVu0ApplyMatrix(&self->center, self->parent, &self->pos);
    pm = self->parent;
    VU0_LQC2(4, pm, 0x00);
    VU0_LQC2(5, pm, 0x10);
    VU0_LQC2(6, pm, 0x20);
    VU0_LQC2(7, pm, 0x30);
    VU0_SQC2(4, f.parent, 0x00);
    VU0_SQC2(5, f.parent, 0x10);
    VU0_SQC2(6, f.parent, 0x20);
    VU0_SQC2(7, f.parent, 0x30);
    func_0030A548(self->mtx, f.parent);
    cVec_copy3(&self->unk1D0, &self->unk60);
    r = self->radius;
    self->flags &= ~CBOX_FLAG_DIRTY;
    self->min.x = self->center.x - r;
    self->min.y = self->center.y - r;
    self->min.z = self->center.z - r;
    self->max.x = self->center.x + r;
    self->max.y = self->center.y + r;
    self->max.z = self->center.z + r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00133BC8);
#endif
