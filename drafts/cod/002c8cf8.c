/* sn-2.95.3-136 */
/* cSescr_At_ck: retail keeps the area pointer in $t1 and computes the shape
 * position (self + 0x30) once before the switch, with the hit flag in $a2;
 * this build recomputes the position in each case and keeps the area
 * pointer in $a0, three instructions longer. It belongs in the
 * func_002C8B68 unit, which ends where it starts. */
#include "include_asm.h"
#include "godhand/cOmBase.h"

#ifdef NON_MATCHING
/* A sound-script trigger area: a shape around a position that starts a
 * sound while the target is inside it. */
typedef struct cSescrArea {
    char unk00[4];
    unsigned short size0;               /* 0x04 radius, or the first extent */
    unsigned short size1;               /* 0x06 second extent */
    char unk08[8];
    cVec pos;                           /* 0x10 */
    cVec dir;                           /* 0x20 */
} cSescrArea;

typedef struct cSescr {
    char unk00[0xC];
    unsigned char flags;                /* 0x0C SESCR_F_* */
    unsigned char shape;                /* 0x0D SESCR_SHAPE_* */
    char unk0E[2];
    short dist;                         /* 0x10 distance from the last check */
    char unk12[0xE];
    cSescrArea area;                    /* 0x20 */
} cSescr;

#define SESCR_F_INSIDE   0x02           /* the target was inside at the last check */

enum {
    SESCR_SHAPE_0,
    SESCR_SHAPE_1,
    SESCR_SHAPE_2,
    SESCR_SHAPE_3
};

extern int func_002DAA40(cVec *pos, cVec *dir, cVec *target, float *dist, cVec *out,
                         float size, float margin);
extern int func_002DACE8(cVec *pos, cVec *dir, cVec *target, float *dist, cVec *out,
                         float size0, float size1, float margin);
extern int func_002DAF68(cVec *pos, cVec *target, float *dist, cVec *out,
                         float size, float margin);
extern int func_002DB008(cVec *pos, cVec *target, float *dist, cVec *out,
                         float size0, float size1, float margin);








/* Tests the target against the trigger shape, keeps the distance and sets
 * or clears the inside flag; returns nonzero when the target is inside. */
__attribute__((section(".text.cSescr_At_ck")))
int cSescr_At_ck(cSescr *self, cVec *target, cVec *out, float margin)
{
    cSescrArea *area = &self->area;
    float dist;
    int hit = 0;

    switch (self->shape) {
    case SESCR_SHAPE_0:
        hit = func_002DAA40(&area->pos, &area->dir, target, &dist, out, area->size0, margin);
        break;
    case SESCR_SHAPE_1:
        hit = func_002DACE8(&area->pos, &area->dir, target, &dist, out,
                            area->size0, area->size1, margin);
        break;
    case SESCR_SHAPE_2:
        hit = func_002DAF68(&area->pos, target, &dist, out, area->size0, margin);
        break;
    case SESCR_SHAPE_3:
        hit = func_002DB008(&area->pos, target, &dist, out, area->size0, area->size1, margin);
        break;
    }
    self->flags &= ~SESCR_F_INSIDE;
    self->dist = (int)dist;
    if (hit) {
        self->flags |= SESCR_F_INSIDE;
    }
    return hit;
}
#else
INCLUDE_ASM("asm/nonmatching", cSescr_At_ck);
#endif
