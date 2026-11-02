/* sn-2.95.3-136 */

#include "godhand/cFxTrail.h"
#include "godhand/cModel.h"
#include "godhand/cObjSimple.h"
#include "godhand/mtx.h"
#include "godhand/vu0.h"

/* Set up a trail that follows one of its owner's parts: take the part (as the index of its linked part when node flag 0x80 is set) and the offset from the parameters, then build the segments as cFxTrail_setup does, with a second point per segment at the offset. Returns 0 when the owner or the part is missing. */
__attribute__((section(".text.func_002F62F8")))
int func_002F62F8(cFxTrail *self, int arg)
{
    int frame[3];
    cVec start;
    cVec start2;
    float m[16];
    cVec zero;
    int i;
    float wA, wB;
    FxTrailParam *prm;
    cParts *link;

    self->flags2 |= 0x4;
    self->attach = self->param->attach;
    self->partIdx = self->param->partIdx;
    if (self->attach != 0) {
        if (self->owner == 0 || cOmBase_childAtIdx(self->owner, frame, self->partIdx) == 0) {
            return 0;
        }
        if (self->nodeFlags & 0x80) {
            if (((cParts *)cOmBase_childAtIdx(self->owner, frame, self->partIdx))->link != 0) {
                link = ((cParts *)cOmBase_childAtIdx(self->owner, frame, self->partIdx))->link;
                self->partIdx = link - (cParts *)cOmBase_childAt(self->owner, frame, 0);
            }
        }
    }
    self->segNum = self->param->segNum;
    if (!(self->segNum < FXTRAIL_SEG_MAX + 1 && self->segNum != 0)) {
        self->segNum = FXTRAIL_SEG_DEF;
    }
    if (func_002EBD10(self, arg, self->segNum) == 0) {
        return 0;
    }
    prm = self->param;
    self->ofs.x = prm->ofs.x * 0.01f;
    self->ofs.y = prm->ofs.y * 0.01f;
    self->ofs.z = prm->ofs.z * 0.01f;
    self->unk300 = 1.0f - prm->ofs.w;
    StoreVecFromFieldB0_2B6160(&start, self);
    func_002F6258(&start2, self, &self->ofs);
    for (i = 0; i < self->segNum; i++) {
        cVec_copy3(self->pts + i, &start);
        cVec_copy3(self->pts2 + i, &start2);
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
    MtxCopy(m, (void *)CallThenReturnPlusB0_002B6420_2B61B0((int)self));
    VU0_SQC2_VF0_MEM(&zero, 0);
    CopyVec3ToField30_147C40(m, (float *)&zero);
    self->life = self->param->life + 1;
    if (self->attach != 0 && self->owner == 0) {
        return 0;
    }
    return 1;
}
