/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"
#include "godhand/cEmLinked.h"

#ifdef NON_MATCHING
/* Snap every tracked point to its part: the world position is the part's
 * matrix times the point's offset, the previous position is set to it and the
 * velocity cleared.
 * Still differs from retail: the 0xA0 record stride stays in the loop where
 * retail keeps it in $fp (the vector operator's asm stops the hoist). */
__attribute__((section(".text.func_00107C68")))
void func_00107C68(cOmBase *self, cEmLinkStep *work, cPtRec *rec)
{
    int frame[3];
    CVEC_TEMPS;
    unsigned int i;
    unsigned char *idx = work->part;

    for (i = 0; i < work->num; i++, idx++) {
        cOmBase *part;
        cPtRec *p;

        if (work->parts != 0) {
            part = work->parts[*idx];
        } else {
            part = cOmBase_childAtIdx(self, frame, *idx);
        }
        p = &rec[*idx];
        CVEC_SET_APPLY(p->pos, part->mtx, &p->local);
        CVEC_ASSIGN(p->prev, &p->pos);
        p->vel.x = 0.0f;
        p->vel.y = 0.0f;
        p->vel.z = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00107C68);
#endif
