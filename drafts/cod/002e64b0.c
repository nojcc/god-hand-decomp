/* sn-2.95.3-136. Differs from retail in one delay slot: retail fills the
 * branch around cObj_setMeshValue as a branch-likely with the reload of
 * self->mot (one instruction longer); ours fills it with the lui of 0x51011. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cObjGround.h"
#include "godhand/cModel.h"
#include "godhand/espSys.h"
#include "godhand/vecInline.h"
#include "godhand/vu0.h"

extern char D_0044E438[];
extern char D_0044E460[];
extern char D_0044E498[];
extern char D_0044E4B8[];
extern char D_0044E4E0[];
extern char D_0044E518[];

/* Set up the ground effect object from its parameter block: check the
 * ground and wall effect numbers against the EST data, create the model and
 * place it at the object. Returns 0 when a setting is invalid. */
__attribute__((section(".text.func_002E64B0")))
int func_002E64B0(cObjGround *self, char *set)
{
    int *est;
    cObjSimple *mot;
    cObjSimpleVec3 v;
    cObjSimpleVec3 rot;

    self->f2E8 = *(float *)(set + 0x40);
    self->modelNo = self->param->modelNo;
    self->groundMode = self->param->groundMode;
    self->wallMode = self->param->wallMode;
    self->disabled = self->param->disabled;
    if (self->groundMode >= 3) {
        return 0;
    }
    if (self->wallMode >= 4) {
        return 0;
    }
    if (self->disabled) {
        return 0;
    }
    cVec_set4(&self->ofs, self->param->ofsX, self->param->ofsY, 0.0f, 1.0f);
    VU0_VSCALE_XYZ_MEM(&self->ofs, 0, 0.1f);
    self->gndKind = self->param->gndKind;
    self->gndNo = self->param->gndNo;
    self->wallKind = self->param->wallKind;
    self->wallNo = self->param->wallNo;
    self->fadeInit = self->param->fadeInit;
    self->c5 = self->param->c5;
    self->c6 = self->param->c6;
    if (self->gndKind != GROUND_NONE) {
        est = func_00306030(D_007419A0, self->gndKind, self->gndNo + 1);
        if (est == 0) {
            func_002D9F68(self, (int)D_0044E438, self->gndKind, self->gndNo);
            return 0;
        }
        if (*est != GROUND_EST_MAGIC) {
            func_002D9F68(self, (int)D_0044E460, self->gndKind, self->gndNo);
            return 0;
        }
    } else if (self->c5 == 0) {
        func_002D9F68(self, (int)D_0044E498, self->c5);
        return 0;
    }
    if (self->wallKind != GROUND_NONE) {
        est = func_00306030(D_007419A0, self->wallKind, self->wallNo + 1);
        if (est == 0) {
            func_002D9F68(self, (int)D_0044E4B8, self->wallKind, self->wallNo);
            return 0;
        }
        if (*est != GROUND_EST_MAGIC) {
            func_002D9F68(self, (int)D_0044E4E0, self->wallKind, self->wallNo);
            return 0;
        }
    } else if (self->c6 == 0) {
        func_002D9F68(self, (int)D_0044E518, self->c6);
        return 0;
    }
    if (self->alpha <= 0 && self->param->keepAlpha == 0) {
        self->alpha = 0xFF;
        self->ground |= 4;
    }
    if (self->fadeInit) {
        self->ground |= 4;
    }
    if (func_002E63C0((char *)self) == 0) {
        return 0;
    }
    mot = self->mot;
    if (mot == 0) {
        return 0;
    }
    self->flags &= ~0x40000000;
    StoreVecFromFieldB0_2B6160(&v, self);
    vec3_copy(&mot->parentPos->x, &v.x);
    CopyVec16From20_B62E0(&v, (char *)self);
    v.z = v.x;
    cNode_setLocalScale((int)self, (int)&v);
    vec3_copy(&self->mot->scale.x, &v.x);
    func_002B60D0(&rot, self);
    vec3_copy(&self->mot->rot.x, &rot.x);
    self->mot->vec240.x = self->color[0];
    self->mot->vec240.y = self->color[1];
    self->mot->vec240.z = self->color[2];
    self->mot->f24C = self->color[3];
    if (self->flags & 0x80000) {
        cObj_setMeshValue((cModel *)self->mot, 0x51011);
    }
    self->mot->drawFlags |= 0x8000000;
    self->mot->vtbl[10].pfn((char *)self->mot + self->mot->vtbl[10].delta);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002E64B0);
#endif
