/* NON_MATCHING func_00158198 (sn-2.95.3-136): retail keeps the part-table header pointer
 * in a stack slot and reloads it every pass, reads the rotation flag as the byte at 0x155,
 * and loads all three floats of the position before storing them; five words longer. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cModel.h"

#define CPARTS_KEEP_ALL    0x001
#define CPARTS_KEEP_ROT    0x100
#define CPARTS_KEEP_POS    0x200
#define CPARTS_KEEP_SCALE  0x400

/* Put every part back in its bind pose: position from the script's part
 * table, zero rotation and unit scale, except where the part's flags keep
 * them. */
__attribute__((section(".text.func_00158198")))
void func_00158198(cModel *self)
{
    cParts *part;
    char *tbl;
    cScrHeader *hdr;
    cPartEntry *ent;
    int i;

    part = self->next;
    if (part == 0) {
        return;
    }
    tbl = self->script + ((cModelScript *)self->script)->meshOfs[0];
    hdr = (cScrHeader *)(tbl + *(int *)tbl);
    for (i = 0; part != 0; part = part->next, i++) {
        if (part->partFlags & CPARTS_KEEP_ALL) {
            continue;
        }
        ent = (cPartEntry *)((char *)hdr + hdr->partOfs) + i;
        if (!(part->partFlags & CPARTS_KEEP_POS)) {
            part->trans.x = ent->pos[0];
            part->trans.y = ent->pos[1];
            part->trans.z = ent->pos[2];
            cVec_copy3(part->anchor, &part->trans);
        }
        if (!(part->partFlags & CPARTS_KEEP_ROT)) {
            part->rot.x = part->rot.y = part->rot.z = 0.0f;
        }
        if (!(part->partFlags & CPARTS_KEEP_SCALE)) {
            part->scale.x = part->scale.y = part->scale.z = 1.0f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00158198);
#endif
