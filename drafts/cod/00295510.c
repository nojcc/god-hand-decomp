/* sn-2.95.3-136 (as sn). Differs from retail: retail converts and scales x, y and z first and stores all four components of the stack vector at the end; ours stores each component as soon as it is computed. */
#ifdef NON_MATCHING
#include "godhand/cEmSetParam.h"
#include "godhand/cOmBase.h"
#include "godhand/cRoomSave.h"
#include "godhand/vu0.h"

extern cVec D_00747B00;
extern cRoomSaveEm *cRoomSave_findEm(cRoomSave *self, unsigned int id);

/* Writes entry no's position (world units, w = 1) to out, or D_00747B00 when the
 * entry is missing. self is not read. */
__attribute__((section(".text.cEmSetParam_getSetDataPos")))
cVec *cEmSetParam_getSetDataPos(cVec *out, cEmSetParam *self, unsigned int no)
{
    cEmSetEntry *entry = cRoomSave_findEm(&D_005E8658, no);
    cVec pos;

    if (entry == 0) {
        VU0_LQC2(4, &D_00747B00, 0);
        VU0_SQC2(4, out, 0);
        return out;
    }
    pos.x = entry->pos[0] * EMSET_POS_SCALE;
    pos.y = entry->pos[1] * EMSET_POS_SCALE;
    pos.z = entry->pos[2] * EMSET_POS_SCALE;
    pos.w = 1.0f;
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, out, 0);
    return out;
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", cEmSetParam_getSetDataPos);
#endif
