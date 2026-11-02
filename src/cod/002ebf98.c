/* sn-2.95.3-136 matched TU. */

#include "godhand/cFxTrail.h"
#include "godhand/vu0.h"
#include "godhand/mtx.h"


extern void *StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);
extern float *CallThenReturnPlusB0_002B6420_2B61B0(void *node);

/* Set the trail up: take the segment count from the parameters (16 when it is zero or too large), build the segment records with a fading width and end weights from the direction flags, and set the life. */
__attribute__((section(".text.cFxTrail_setup")))
int cFxTrail_setup(cFxTrail *self, int arg)
{
    cVec start;
    float m[16];
    cVec zero;
    int i;
    float wA, wB;
    FxTrailParam *prm;

    self->segNum = self->param->segNum;
    if (!(self->segNum < FXTRAIL_SEG_MAX + 1 && self->segNum != 0)) {
        self->segNum = FXTRAIL_SEG_DEF;
    }
    if (func_002EBD10(self, arg, self->segNum) == 0) {
        return 0;
    }
    StoreVecFromFieldB0_2B6160(&start, self);
    for (i = 0; i < self->segNum; i++) {
        cVec_copy3(self->pts + i, &start);
        ((FxTrailSeg *)self->segA)->k60 = FXTRAIL_K60;
        ((FxTrailSeg *)self->segA)->k68 = FXTRAIL_K68;
        ((FxTrailSeg *)self->segB)->k60 = FXTRAIL_K60;
        ((FxTrailSeg *)self->segB)->k68 = FXTRAIL_K68;
        wA = 1.0f;
        if (self->flags & FXTRAIL_FLIP_A) {
            wA = -1.0f;
        }
        wB = 1.0f;
        if ((self->flags & FXTRAIL_FLIP_B) == 0) {
            wB = -1.0f;
        }
        FXTRAIL_SEG(self->segA, i)->a0 = 0;
        FXTRAIL_SEG(self->segA, i)->fade = wB * (float)i / (float)(self->segNum - 1) * self->width;
        FXTRAIL_SEG(self->segA, i)->k0A8 = FXTRAIL_K0A8;
        FXTRAIL_SEG(self->segA, i)->end0 = wA;
        FXTRAIL_SEG(self->segA, i)->end1 = FXTRAIL_SEG(self->segA, i)->fade;
        FXTRAIL_SEG(self->segA, i)->kC8 = FXTRAIL_K0A8;
        FXTRAIL_SEG(self->segB, i)->a0 = 0;
        FXTRAIL_SEG(self->segB, i)->fade = FXTRAIL_SEG(self->segA, i)->fade;
        FXTRAIL_SEG(self->segB, i)->k0A8 = FXTRAIL_K0A8;
        FXTRAIL_SEG(self->segB, i)->end0 = wA;
        FXTRAIL_SEG(self->segB, i)->end1 = FXTRAIL_SEG(self->segA, i)->fade;
        FXTRAIL_SEG(self->segB, i)->kC8 = FXTRAIL_K0A8;
    }
    MtxCopy(m, CallThenReturnPlusB0_002B6420_2B61B0(self));
    VU0_SQC2_VF0_MEM(&zero, 0);
    CopyVec3ToField30_147C40(m, (float *)&zero);
    prm = self->param;
    self->life = prm->life + 1;
    if (prm->fixedLife != 0) {
        self->flags2 |= FXTRAIL_LIFE_SET;
    }
    return 1;
}
