/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cObjSimple.h"
#include "godhand/cutCmd.h"
#include "godhand/vecInline.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

#ifdef NON_MATCHING
extern char D_00586AF0[];
extern int D_003C2560[8];
extern float D_003C2580[8];
extern float D_003C25A0[8];
extern float D_003C25C0[8];
extern float D_003C25E0[8];

/* Swings one limb by push (plus the accumulated swing) and swing, clamped to
 * the limb's range. 150 words where retail has 148: the frame is 0x10 larger (the unused
 * ret_ slot), push and swing sit in f20/f21 the other way round, and the
 * swing[limb] loads are scheduled before the products. */
__attribute__((section(".text.cObjSimple_SwingLimb")))
void cObjSimple_SwingLimb(cObjSimple *self, unsigned int limb, float push, float swing)
{
    cVec ang;
    int frame[3];
    CVEC_TEMPS;

    CVEC_ZERO(ang);
    if (limb < 8) {
        cObjSimpleChild *part = cObjSimple_childAtIdx(self, frame, D_003C2560[limb]);

        if (part != 0) {
            if (cEvent_getCutFrame(D_00586AF0) == 0.0f || (self->flags & 1)) {
                swing = 0.0f;
                self->swingAccum = 0.0f;
                self->swing[limb] = 0.0f;
                push = 0.0f;
            }
            part->flags154 |= 0x100200;
            push += self->swingAccum;
            self->swing[limb] += push * (0.0f < push ? D_003C2580 : D_003C25A0)[limb];
            self->swing[limb] += swing * (0.0f < swing ? D_003C2580 : D_003C25A0)[limb];
            vec4_set_point(&tmp_.x, part->localPos.x, part->localPos.y, part->localPos.z);
            CVEC_ASSIGN_VEC(ang, tmp_);
            ang.x += self->swing[limb];
            if (ang.x < D_003C25C0[limb]) {
                ang.x = D_003C25C0[limb];
                self->swing[limb] = 0.0f;
            }
            if (D_003C25E0[limb] < ang.x) {
                ang.x = D_003C25E0[limb];
                self->swing[limb] = 0.0f;
            }
            CVEC_PUT(part->outPos, ang);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cObjSimple_SwingLimb);
#endif
