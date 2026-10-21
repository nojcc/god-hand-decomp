/* NON_MATCHING func_002951B0 (sn-2.95.3-136, as=sn): 43 differing words. Retail converts
 * x, y and z one after another with the entry pointer in t0; here the three halfword loads
 * are hoisted together and the entry pointer sits in v1. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEmSetParam.h"
#include "godhand/cEmManage.h"
#include "godhand/vu0.h"

/* The frame: the entry data, then the scaled position and its work copy. */
typedef struct EmSetFrame {
    SET_EM_DATA data;
    char pad34[0xC];
    cVec pos;
    cVec work;
} EmSetFrame;

#define EMSETFRAME_OFFSET(field) ((int)&((EmSetFrame *)0)->field)

/* Creates the enemy of a room-file entry: converts its position and heading
 * and hands the result to the enemy manager. */
__attribute__((section(".text.func_002951B0")))
cEmActor *func_002951B0(cEmSetParam *self, cEmSetEntry *entry)
{
    EmSetFrame f;

    VU0_SQC2_VF0_MEM(&f.data.pos, 0);
    f.data.objId = entry->objNo + EMSET_OBJ_BASE;
    f.data.entryNo = 0xFF;
    cVec_set4(&f.work, entry->pos[0] * EMSET_POS_SCALE, entry->pos[1] * EMSET_POS_SCALE,
              entry->pos[2] * EMSET_POS_SCALE, 1.0f);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, EMSETFRAME_OFFSET(pos));
    cVec_copy3(&f.data.pos, &f.pos);
    f.data.rot = entry->rot * EMSET_ROT_SCALE;
    f.data.flags = entry->flags;
    f.data.seBank = entry->seBank + EMSET_OBJ_BASE;
    f.data.seNo = entry->seNo;
    f.data.appPattern = entry->appPattern;
    f.data.entryNo = entry->entryNo;
    return cEmManage_EntryEm(&D_005864F0, &f.data, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002951B0);
#endif
