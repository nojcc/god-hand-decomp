/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cOm60.h"
#include "godhand/cVec.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

extern void SetEntryParams_1B1928(void *a0, int a1, short a2);
extern void func_001B15C8(void *a0, int a1, int a2, float *a3, float *t0);

/* Create a held object (kind 0x364) in hand slot no: slot 1 in part 16,
 * slot 0 in part 10, at a small offset from the part.
 * Still differs from retail: retail tests no >= 2 as a set-flag value
 * (slti, xori, bnez), copies self and no to saved registers first and
 * gives each early return its own epilogue entry. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_0026A638")))
void func_0026A638(cEm00 *self, int no)
{
    cVec ofs;
    cVec rot;
    int frame[3];
    int part;
    cOmBase *hand;
    cOm60 *obj;

    CVEC_ZERO(ofs);
    CVEC_ZERO(rot);
    if (no >= 2) {
        return;
    }
    if (self->held[no] != 0) {
        return;
    }
    switch (no) {
    default:
    case 0:
        ofs.x = -0.1f;
        part = 10;
        break;
    case 1:
        ofs.x = 0.1f;
        part = 16;
        break;
    }
    ofs.y = -0.2f;
    ofs.z = -0.05f;
    hand = cOmBase_childAtIdx((cOmBase *)self, frame, part);
    if (hand == 0) {
        return;
    }
    obj = (cOm60 *)CreateObj(0x364, 0xFFFF);
    self->held[no] = obj;
    if (obj == 0) {
        return;
    }
    cGameObj_vt(&obj->base)->unk44((char *)obj + cGameObj_vt(&obj->base)->unk40Delta);
    cVec_copy3(obj->base.pos, hand->pos);
    cVec_copy3(&obj->base.posA, obj->base.pos);
    vec3_set(&obj->base.rot.x, 0.0f, 0.0f, 0.0f);
    SetEntryParams_1B1928(obj, 1, GetSeqSEBase((int *)self) + 0x11);
    rot.x = 0.0f;
    rot.y = 0.0f;
    rot.z = 0.0f;
    func_001B15C8(obj, (int)self, part, &ofs.x, &rot.x);
    self->unk1714 = 150.0f;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026A638);
#endif
