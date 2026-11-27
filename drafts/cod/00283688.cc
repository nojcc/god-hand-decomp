/* sn-2.95.3-136 (C++ unit, -fno-exceptions). NON_MATCHING func_00283688: same length as retail, 4 instructions off: in the part-drag subtraction retail loads the second operand into v1 and the temporary address into v0; this swaps them. Binding orders, local orders and an inline operator were tried. */
extern "C" {

#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/cModelFn.h"
#include "godhand/cVec.h"
#include "godhand/cEmLinked.h"

#define SYS_FLAG_FREEZE   0x40000000    /* D_00747A78: enemies skip their update */
#define EMLINK_MODE_RESET 4             /* mode that runs the scenario reset each frame */
#define EMLINK_DRAG       0x02          /* unk2F0: the link's moves drag the parts along */
#define EMLINK_OBJ_INHERIT 0x10u        /* objFlags bit taken over from the link */

extern unsigned int D_00747A78;         /* system flags */

/* Per-frame update of a linked enemy: drag its parts by the link child's move,
 * then take the link child's position, rotation, alpha and hide flags. */
__attribute__((section(".text.func_00283688")))
void func_00283688(cEmLinked *self)
{
    if (D_00747A78 & SYS_FLAG_FREEZE)
        return;
    switch (self->base.mode) {
    case 0: case 1: case 2: case 3:
        break;
    case EMLINK_MODE_RESET:
        CEM00_VCALL0(&self->base, scenario);
        break;
    }
    if (self->base.unk2F0 & EMLINK_DRAG) {
        if (self->link != 0) {
            cVec ofs;
            int frame[3];
            CVEC_TEMPS;
            cOmBase *mine;
            cOmBase *held;

            CVEC_ZERO(ofs);
            mine = cOmBase_childAt((cOmBase *)self, frame, 0);
            held = cOmBase_childAtIdx((cOmBase *)self->link, frame, self->linkChild);
            if (mine != 0 && held != 0) {
                struct cParts *p;
                int i;

                CVEC_SET_SUB(ofs, held->pos, mine->pos);
                p = self->base.next;
                for (i = 0; i < self->base.partNum; i++) {
                    p->mtx[12] += ofs.x;
                    p->mtx[13] += ofs.y;
                    p->mtx[14] += ofs.z;
                    p = p->next;
                }
                func_00107C68((cOmBase *)self, &self->work, (cPtRec *)&self->base.unk5B0);
            }
        }
    }
    if (self->link != 0) {
        int frame[3];
        cOmBase *held = cOmBase_childAtIdx((cOmBase *)self->link, frame, self->linkChild);

        cVec_copy3(self->base.pos, self->link->pos);
        if (held != 0) {
            cOmBase *mine = cOmBase_childAt((cOmBase *)self, frame, 0);

            cVec_copy3(mine->pos, held->pos);
        }
        /* retail reads the rotation through held even when it is null */
        cVec_copy3(&self->base.rot, &held->rot);
        self->base.tint.w = self->link->tint.w;
        self->base.objFlags &= ~EMLINK_OBJ_INHERIT;
        self->base.objFlags |= self->link->objFlags & EMLINK_OBJ_INHERIT;
        if (self->link->objFlags & CMODEL_F_HIDDEN)
            self->base.objFlags |= CMODEL_F_HIDDEN;
        else
            self->base.objFlags &= ~CMODEL_F_HIDDEN;
    }
    cModel_calcParts((struct cModel *)self);
    func_00283AA8(self);
}

#else
INCLUDE_ASM("asm/nonmatching", func_00283688);
#endif

}
