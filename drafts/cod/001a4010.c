/* NON_MATCHING func_001A4010 (sn-2.95.3-136, fp_hazard_rules fdiv): 2 instructions differ. Retail's
 * in-place scale by 0.2 addresses the vector as 0x50(sp); here the inline helper's pointer is
 * already in v0, so the scale's lqc2/sqc2 use 0(v0). */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"


#ifdef NON_MATCHING
extern void SetEffectPos(int kind, int effNo, int a2, void *pos, int a4, float scale);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern char D_005FEE00[];

/* The method table of cOm49 (D_00427148); the pair at 0x80 is cGameObj_getPos. */
typedef struct cOm49Vt {
    char unk00[0x80];
    short getPosDelta;                  /* 0x80 */
    short pad82;
    cVec *(*getPos)(void *self);        /* 0x84 */
} cOm49Vt;

/* What cOm49's link at 0x600 points at. */
typedef struct cOm49Link {
    char unk00[0x20];
    cVec pos;                           /* 0x20 */
} cOm49Link;

typedef struct cOm49 {
    char unk000[0x214];
    cOm49Vt *vt;                        /* 0x214 */
    char unk218[0x5E4 - 0x218];
    int effNo;                          /* 0x5E4 */
    char unk5E8[0x600 - 0x5E8];
    cOm49Link *link;                    /* 0x600 */
} cOm49;

/* Work vectors of the step toward the link. */
typedef struct cOm49StepWork {
    cVec ret;                           /* 0x00 */
    cVec diff;                          /* 0x10 */
    cVec unit;                          /* 0x20 */
} cOm49StepWork;

/* *out = v with x, y and z scaled by f. */
static __inline__ void cVec_scaledOf(cVec *out, cVec *v, float f)
{
    VU0_LQC2_SQC2_MEM(4, out, v);
    VU0_VSCALE_XYZ_MEM(out, 0, f);
}

#define COM49_GETPOS(self) ((self)->vt->getPos((char *)(self) + (self)->vt->getPosDelta))

/* Start the effect a fifth of the way from the object (at the link's height) toward the link, with a sound. */
__attribute__((section(".text.func_001A4010")))
void func_001A4010(cOm49 *self)
{
    cVec from;
    cVec pos;
    cVec step;
    cOm49StepWork w;
    cVec *p;
    cVec *q;

    VU0_SQC2_VF0_MEM(&from, 0);
    if (self->link != 0) {
        VU0_LQC2_SQC2_MEM(4, &pos, &self->link->pos);
        cVec_copy3(&from, &pos);
    }
    p = COM49_GETPOS(self);
    q = COM49_GETPOS(self);
    cVec_set4(&pos, p->x, from.y, q->z, 1.0f);
    VU0_SQC2_VF0_MEM(&step, 0);
    VU0_ZERO_VSUB_XYZ_TO(&w.diff, 0, &from, &pos);
    VU0_LQC2_SQC2_MEM(4, &w.ret, &w.diff);
    cVec_copy3(&step, &w.ret);
    cVec_unitOf(&w.unit, &step);
    VU0_LQC2_SQC2_MEM(4, &w.diff, &w.unit);
    cVec_scaledOf(&w.unit, &w.diff, 0.2f);
    VU0_LQC2_SQC2_MEM(4, &w.ret, &w.unit);
    cVec_copy3(&step, &w.ret);
    VU0_VADD_XYZ_IP(&pos, 0, &step);
    SetEffectPos(1, self->effNo, 0, &pos, -1, 1.0f);
    cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, self, 0, 0, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001A4010);
#endif
