/* NON_MATCHING func_001F6758 (sn-2.95.3-136): 177 words, 140 differ with as sn
 * (155 without). Retail recomputes &self->idBase and i + 0x30 inside the
 * row loop; this hoists the first into a saved register and strength-reduces
 * the second, so every register from s0 up differs. -fno-gcse and
 * -fmove-all-movables don't change that. */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/JukeBox.h"
#include "godhand/globals.h"

#define JUKEBOX_LIST_ROWS   12      /* song rows on screen */

/* Show the song rows of the current list with their titles, hide the rest,
 * mark the selected song, and place the cursor entry (8 for rows 0-5, 9 for
 * rows 6-11) on its row. */
__attribute__((section(".text.func_001F6758")))
void func_001F6758(JukeBoxObj *self)
{
    int i;

    for (i = 0; i < JUKEBOX_LIST_ROWS; i++) {
        if (i < D_003BF0D0[self->unk0C]) {
            cIDBase_getIDWork(&self->idBase, i + 0x10)->flags &= ~IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, i + 0x30)->flags &= ~IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, i + 0x30)->msg = D_003BF0C0[self->unk0C][i] + 0x2000;
        } else {
            cIDBase_getIDWork(&self->idBase, i + 0x10)->flags |= IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, i + 0x30)->flags |= IDENT_FLAG_HIDDEN;
        }
        if (i == self->unk20 && self->unk01 == 1) {
            cIDBase_getIDWork(&self->idBase, i + 0x1C)->flags &= ~IDENT_FLAG_HIDDEN;
        } else {
            cIDBase_getIDWork(&self->idBase, i + 0x1C)->flags |= IDENT_FLAG_HIDDEN;
        }
    }
    if (self->unk01 == 1) {
        if (self->unk20 < 6) {
            cIDBase_getIDWork(&self->idBase, 8)->flags &= ~IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, 9)->flags |= IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, 8)->posY = self->unk20 * 40.2f + 153.0f;
        } else {
            cIDBase_getIDWork(&self->idBase, 8)->flags |= IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, 9)->flags &= ~IDENT_FLAG_HIDDEN;
            cIDBase_getIDWork(&self->idBase, 9)->posY = (self->unk20 - 6) * 40.2f + 153.0f;
        }
    } else {
        cIDBase_getIDWork(&self->idBase, 8)->flags |= IDENT_FLAG_HIDDEN;
        cIDBase_getIDWork(&self->idBase, 9)->flags |= IDENT_FLAG_HIDDEN;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F6758);
#endif
