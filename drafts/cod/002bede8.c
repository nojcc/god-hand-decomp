/* sn-2.95.3-136 */
/*
 * NON_MATCHING: 71 vs 72 words. Retail keeps the em[] offset (0x0C) out of
 * the i * 0x18 induction value and adds it after the page pointer, and
 * converts the three positions in $f0 rather than $f3.
 */
#include "include_asm.h"
#include "godhand/cRoomSave.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
extern void func_002BEDC8(cRoomSave *self, int num);

/* Fill the current page's enemy records from the room file's float placements. */
__attribute__((section(".text.func_002BEDE8")))
void func_002BEDE8(cRoomSave *self, unsigned int num, cRoomSaveSrc *src)
{
    cRoomSaveEm *em;
    unsigned int i;

    func_003A52F0(self->data->em, 0, sizeof(self->data->em));
    func_002BEDC8(self, num);
    for (i = 0; i < num; i++) {
        em = &self->data->em[i];
        em->pos[0] = src[i].pos[0] * 20.0f;
        em->pos[1] = src[i].pos[1] * 20.0f;
        em->pos[2] = src[i].pos[2] * 20.0f;
        em->rot = src[i].rot * 57.2957764f;
        em->flags = src[i].flags;
        em->seNo = src[i].seNo;
        em->appPattern = src[i].appPattern;
        em->seBank = src[i].seBank;
        em->objNo = src[i].objNo;
        em->id = src[i].id;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BEDE8);
#endif
