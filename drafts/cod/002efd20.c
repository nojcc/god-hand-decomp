/* sn-2.95.3-136. Differs from retail in 7 instructions: in the block that
 * copies effArg and effFlags into the param, retail loads effArg into v0 and
 * effFlags into v1, then fixedSize into v0; ours swaps v0 and v1. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cObjBase.h"
#include "godhand/cObjSimple.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

static __inline__ void cVec_copy(cVec *d, cVec *s)
{
    VU0_LQC2_SQC2_MEM(4, d, s);
}

static __inline__ void cEffectParam_initAll(cEffectParam *p)
{
    cEffectParam_init(p);
    p->unk70 = 0;
    p->unk72 = 0;
    p->unk74 = 0;
    p->unk78 = 0;
}

#define EFFEMIT_SCREEN  1       /* cEffEmitter.space: the effect is placed in screen space */

/* View of the effect emitter object: the effect it starts, how often, and
 * where. */
typedef struct cEffEmitter {
    char unk000[0x104];
    int effFlags;               /* 0x104 copied to cEffectParam.flags */
    char unk108[0x110 - 0x108];
    char *data;                 /* 0x110 its set data; 0x197 nonzero keeps the default rotation */
    char unk114[0x188 - 0x114];
    cVec color;                 /* 0x188 */
    char unk198[0x224 - 0x198];
    unsigned short frame;       /* 0x224 */
    char unk226[0x23A - 0x226];
    short effKind;              /* 0x23A effect started when effGroup is -1 */
    unsigned short effId;       /* 0x23C */
    char unk23E[0x2B0 - 0x23E];
    int effGroup;               /* 0x2B0 -1: use effKind/effId */
    int effNo;                  /* 0x2B4 */
    int space;                  /* 0x2B8 EFFEMIT_SCREEN */
    unsigned short effArg;      /* 0x2BC copied to cEffectParam.unk70 */
    unsigned char interval;     /* 0x2BE frames between effects, 0 for one effect every frame */
    unsigned char onGround;     /* 0x2BF 1: drop the effect onto the ground below */
    unsigned char fixedSize;    /* 0x2C0 nonzero: don't scale size by the node scale */
    char unk2C1[3];
    float size;                 /* 0x2C4 */
} cEffEmitter;

/* Start the emitter's effect every interval frames at the node's position
 * (projected to the screen in screen space, or dropped onto the ground),
 * turned like the node and sized by its scale. */
__attribute__((section(".text.func_002EFD20")))
void func_002EFD20(cEffEmitter *self)
{
    cEffectParam param;
    cVec pos;
    cVec end;
    cVec hit;
    float mtx[16];

    if (self->interval == 0 || self->frame % self->interval == 0) {
        cEffectParam_initAll(&param);
        if (self->space == EFFEMIT_SCREEN) {
            param.scale = self->color;
            StoreVecFromFieldB0_2B6160(&pos, self);
            cCamera_getScreenPos(&end, D_005CAFF0, &pos);
            param.unk20.x = end.x;
            param.unk20.y = end.y;
            param.unk20.z = 0;
        } else {
            StoreVecFromFieldB0_2B6160(&pos, self);
            param.unk20.x = pos.x;
            param.unk20.y = pos.y;
            param.unk20.z = pos.z;
            param.scale = self->color;
            if (self->onGround == 1) {
                cVec_copy(&pos, &param.unk20);
                cVec_copy(&end, &param.unk20);
                cVec_zero(&hit);
                pos.y += 1.0f;
                end.y -= 11.0f;
                ChkLine(&pos, &end, &hit, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1);
                param.unk20.x = hit.x;
                param.unk20.y = hit.y;
                param.unk20.z = hit.z;
            }
            MtxCopy(mtx, (void *)CallThenReturnPlusB0_002B6420_2B61B0((int)self));
            cVec_zero(&pos);
            func_00147C88(&pos, mtx, 0);
            if (self->data[0x197] == 0) {
                param.unk10.x = pos.x;
                param.unk10.y = pos.y;
                param.unk10.z = pos.z;
            }
        }
        param.unk70 = self->effArg;
        param.flags = self->effFlags;
        CopyVec16From20_B62E0(&pos, (char *)self);
        if (self->fixedSize == 0) {
            param.size = self->size * pos.x;
        }
        if (self->effGroup == -1) {
            if (self->effNo != 0) {
                param.unk74 = self->effNo;
                SetEffect(self->effKind, self->effId, 0, &param, -1, 0xFFFFFFFF);
            }
        } else {
            SetEffect(self->effGroup, self->effNo + 1, 0, &param, -1, 0xFFFFFFFF);
        }
    }
    if (self->interval == 0) {
        UpdateObjByIndexedOp_2FBE50(self);
    }
    func_002FBED0(self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002EFD20);
#endif
