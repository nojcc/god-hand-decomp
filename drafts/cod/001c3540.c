/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cModel.h"
#include "godhand/vecInline.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

extern void cOmBase_setMeshDispFromLayer(void *self, int layer, int on);
extern void SetField380Bit2000ForTag_1B7300(void *a0, int a1, int a2);
extern void func_001C3090(void *self, unsigned int no, cVec *pos, cVec *vel);

/* View of the breakable object of 001c2da0_nm.c and drafts/cod/001c3090.c
 * (cOmShatter there). */
typedef struct cOmShatter {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    void *damage;                       /* 0x600 */
    void *give;                         /* 0x604 */
    char *piece;                        /* 0x608 */
    signed char pieceNum;               /* 0x60C */
} cOmShatter;

#ifdef NON_MATCHING
/* Break the object apart: switch its damage volume off, swap the intact mesh
 * layer for the broken one, hide the model, let the piece parts take their
 * own matrices, and throw each piece off with func_001C3090 from the knock-back
 * vector (scaled to 1/100, lifted by 0.1).
 * Still differs from retail: retail strength-reduces the in-range test of the
 * first loop into a second counter compared against a zero register, and
 * keeps &vel rather than &pos in a saved register. */
__attribute__((section(".text.func_001C3540")))
void func_001C3540(cOmShatter *self)
{
    int frame[3];
    cVec pos;
    cVec vel;
    int i;
    int no;

    if (self->damage != 0) {
        cDamageUnit_SetDamageCollActive(self->damage, 0);
    }
    cOmBase_setMeshDispFromLayer(self, 0, 0);
    cOmBase_setMeshDispFromLayer(self, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(self, 0, 0);
    SetField380Bit2000ForTag_1B7300(self, 0x40, 0);
    self->base.objFlags |= CMODEL_F_HIDDEN;
    for (i = 1; i < self->pieceNum && i < self->base.childNum; i++) {
        ((cParts *)cOmBase_childAtIdx(&self->base, frame, i))->partFlags &= ~CPARTS_NO_LOCAL;
        ((cParts *)cOmBase_childAtIdx(&self->base, frame, i))->partFlags &= ~CPARTS_NO_PARENT;
    }
    cModel_calcParts((cModel *)self);
    CVEC_STORE(&pos, self->base.knock);
    vec4_set_point(&vel.x, 0.0f, 0.0f, 0.0f);
    CVEC_MUL_SCALAR(pos, 0.01f);
    pos.y += 0.099999994f;
    for (no = 0; no < self->pieceNum && no < self->base.childNum; no++) {
        func_001C3090(self, no, &pos, &vel);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C3540);
#endif
