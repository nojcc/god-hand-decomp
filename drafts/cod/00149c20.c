/* sn-2.95.3-136 */
/* NON_MATCHING: retail keeps hdr in a stack slot at sp+0 and reloads it for every part-table access (frame 0xE0, pos at sp+0x10); this C keeps it in a callee-saved register, so 139 instructions differ. */
#include "godhand/cModel.h"
#include "godhand/vu0.h"


#ifdef NON_MATCHING
extern int func_001500C0(void);
extern cParts *cModel_getPart(cModel *self, int n);
extern void MtxInverse(void *dst, void *src);

/* Build the model's part list from the script header: allocate each part, place it,
 * hook up its parent and link, then store each part's inverse world position.
 * Returns 0 when a part can't be allocated. */
__attribute__((section(".text.func_00149C20")))
int func_00149C20(cModel *self, cScrHeader *hdr)
{
    cParts *prev;
    cParts *part;
    cPartEntry *ent;
    cVec pos;
    cVec zero;
    float m[16];
    int i;

    prev = (cParts *)self;
    self->partNum = hdr->partNum;
    for (i = 0; i < self->partNum; i++) {
        part = (cParts *)func_001500C0();
        if (part == 0) {
            return 0;
        }
        prev->next = part;
        ent = (cPartEntry *)((char *)hdr + hdr->partOfs) + i;
        pos.x = ent->pos[0];
        pos.y = ent->pos[1];
        pos.z = ent->pos[2];
        pos.w = 1.0f;
        cVec_copy3(part->anchor, &pos);
        if (ent->parent < 0) {
            part->parent = (cParts *)self;
        } else {
            part->parent = cModel_getPart(self, ent->parent);
        }
        prev = prev->next;
    }
    for (i = 0; i < self->partNum; i++) {
        part = cModel_getPart(self, i);
        ent = (cPartEntry *)((char *)hdr + hdr->partOfs) + i;
        if (ent->link < 0) {
            part->link = part;
        } else {
            part->link = cModel_getPart(self, ent->link);
        }
    }
    pos.x = self->mtxLocal[12];
    pos.y = self->mtxLocal[13];
    pos.z = self->mtxLocal[14];
    pos.w = 1.0f;
    VU0_SQC2_VF0_MEM(&zero, 0);
    cVec_copy3(self->anchor, &zero);
    cModel_calcParts(self);
    part = self->next;
    for (i = 0; i < self->partNum; i++) {
        MtxInverse(m, part->mtx);
        part->invPos.x = m[12];
        part->invPos.y = m[13];
        part->invPos.z = m[14];
        part = part->next;
    }
    cVec_copy3(self->anchor, &pos);
    return 1;
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_00149C20);
#endif
