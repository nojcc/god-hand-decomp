/* sn-2.95.3-136. Differs from retail: retail keeps the child count of the second block at sp+0x00 (sharing the offset vector's slot, 0x60-byte frame) and tests the holder child index as a byte-masked bool (andi 0xFF); ours gives each block its own frame (0xA0 bytes) and branches on the plain compare, so most of the body is offset. */
#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/vu0.h"

#define HELD_FOLLOW_CHILD   0x02        /* flags: move the parts by the child-to-child offset */
#define CMODEL_F_HIDE       0x10
#define CMODEL_F_10000      0x10000

/* A model attached to one child body of a holder model. */
typedef struct cHeldModel {
    CMODEL_FIELDS
    char unk2E4[0xC];
    int flags;                          /* 0x2F0 HELD_* */
    unsigned char mode;                 /* 0x2F4 */
    char unk2F5[0x2130 - 0x2F5];
    char work2130[0x80];                /* 0x2130 */
    struct cHeldModel *holder;          /* 0x21B0 */
    int holdChild;                      /* 0x21B4 child of the holder this model follows */
} cHeldModel;

typedef struct cHeldFrame {
    cVec ofs;                           /* 0x00 */
    int childNum;                       /* 0x10 */
    char unk14[0xC];
    cVec tmp;                           /* 0x20 */
    cVec diff;                          /* 0x30 */
} cHeldFrame;

#define HELDFRAME_OFFSET(field) ((int)&((cHeldFrame *)0)->field)

extern int D_00747A78;
extern void func_00107C68(void *self, void *a1, void *a2);
extern void cModel_calcParts(void *self);
extern void func_00276DC8(cHeldModel *self);

/* Moves the model with its holder: optional child offset, then position, rotation, alpha and the visibility flags. */
__attribute__((section(".text.func_002769A8")))
void func_002769A8(cHeldModel *self)
{
    if (D_00747A78 & 0x40000000)
        return;
    switch (self->mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        ((void (*)(void *))self->vtable[11].pfn)((char *)self + self->vtable[11].delta);
        break;
    }
    if ((self->flags & HELD_FOLLOW_CHILD) && self->holder != 0) {
        cHeldFrame f;
        cOmBase *mine;
        cOmBase *theirs;
        cParts *p;
        int i;

        VU0_SQC2_VF0(&f, HELDFRAME_OFFSET(ofs));
        mine = cOmBase_childAt((cOmBase *)self, &f.childNum, 0);
        theirs = cOmBase_childAt((cOmBase *)self->holder, &f.childNum, self->holdChild);
        if (mine != 0 && theirs != 0) {
            VU0_ZERO_VSUB_XYZ_MEM(&f, HELDFRAME_OFFSET(diff), theirs->pos, mine->pos);
            VU0_LQC2(4, &f.diff, 0);
            VU0_SQC2(4, &f, HELDFRAME_OFFSET(tmp));
            cVec_copy3(&f.ofs, &f.tmp);
            p = self->next;
            for (i = 0; i < self->partNum; i++) {
                p->mtx[12] += f.ofs.x;
                p->mtx[13] += f.ofs.y;
                p->mtx[14] += f.ofs.z;
                p = p->next;
            }
            func_00107C68(self, self->work2130, &self->unk2E4);
        }
    }
    if (self->holder != 0) {
        cHeldFrame f;
        cOmBase *part;

        part = cOmBase_childAt((cOmBase *)self->holder, &f.childNum, self->holdChild);
        cVec_copy3(self->pos, self->holder->pos);
        if (part != 0)
            cVec_copy3(cOmBase_childAt((cOmBase *)self, &f.childNum, 0)->pos, part->pos);
        cVec_copy3(&self->rot, (cVec *)((char *)part + 0x100));
        self->objFlags &= ~CMODEL_F_HIDE;
        self->tint.w = self->holder->tint.w;
        self->objFlags |= self->holder->objFlags & CMODEL_F_HIDE;
        if (self->holder->objFlags & CMODEL_F_10000)
            self->objFlags |= CMODEL_F_10000;
        else
            self->objFlags &= ~CMODEL_F_10000;
    }
    cModel_calcParts(self);
    func_00276DC8(self);
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_002769A8);
#endif
