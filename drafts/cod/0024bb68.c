/* sn-2.95.3-136 */
/* func_0024BB68. Three instructions differ: retail negates the Turn_dest
 * result itself (neg.s $f1, $f0) where this negates the copy, and it
 * addresses the vadd at 0xB0($sp) while still building &ofs in $v1 before
 * it; through cVec_add the vadd goes through $v1. */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/gameWork.h"
#include "godhand/sceVu0.h"

#ifdef NON_MATCHING
/* cEm00 0x17D0 is padding in cEm00.h; its low 3 bits pick the frame the check runs on. */
#define EM_CHECK_SLOT(self) (*(int *)((char *)(self) + 0x17D0))

typedef struct HitPoly {
    int unk0;
    unsigned int surface;               /* 0x4 */
} HitPoly;

extern float Turn_dest(float *from, float *to, float cur, float max);
extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern float capVu0Atan2(float y, float x);
extern void MtxInitRotY(void *a0, float angle);

/* d.xyz += s.xyz, in place. */
static __inline__ void cVec_add(cVec *d, cVec *s)
{
    VU0_VADD_XYZ_IP(d, 0, s);
}

/* Facing the target, probe 0.8 ahead for a wall (surface bit 0x20); on a hit
 * keep a point 0.5 off the wall and the angle facing it, go to phase 0x75
 * and return 1. */
__attribute__((section(".text.func_0024BB68")))
int func_0024BB68(cEm00 *self)
{
    cVec from;
    cVec to;
    cVec hit;
    cVec normal;
    float mtx[16];
    cVec ofs;
    HitPoly *poly;
    float turn;
    float dist;
    float angle;

    switch (self->emNo) {
    case 0x220:
    case 0x221:
    case 0x222:
        break;
    default:
        if ((D_007474A0.frame & 7) != (EM_CHECK_SLOT(self) & 7))
            return 0;
        break;
    }
    turn = Turn_dest((float *)&self->posA, (float *)&self->unk16A0, self->rot.y, 3.1415927f);
    if (turn < 0.0f)
        dist = -turn;
    else
        dist = turn;
    if (0.5235988f < dist)
        return 0;
    cVec_zero(&from);
    cVec_zero(&to);
    cVec_zero(&hit);
    cVec_zero(&normal);
    from.x = 0.0f;
    from.y = 0.5f;
    from.z = 0.0f;
    to.x = 0.0f;
    to.y = 0.5f;
    to.z = 0.8f;
    cVec_applyMatrix(&from, self->mtx);
    cVec_applyMatrix(&to, self->mtx);
    if (ChkLine(&from, &to, &hit, &normal, 1, 0, &poly, 1, 0, 0, 0, 0, 1) == 0
        || (poly->surface & 0x20) == 0)
        return 0;
    cVec_zero(&ofs);
    angle = capVu0Atan2(-normal.x, -normal.z);
    ofs.x = 0.0f;
    ofs.y = 0.0f;
    ofs.z = -0.5f;
    MtxInitRotY(mtx, angle);
    cVec_applyMatrix(&ofs, mtx);
    cVec_add(&ofs, &hit);
    ofs.y = self->pos->y;
    cVec_copy3(&self->unk6D0, &ofs);
    self->unk6E0 = angle;
    self->mode = 0;
    self->phase = 0x75;
    self->step = 0;
    self->stepArg = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0024BB68);
#endif
