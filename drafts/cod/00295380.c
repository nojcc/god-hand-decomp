/* cCollisionSolid_updateBounds add/sub/store schedule vs retail interleave with & -3.
* cEmSetParam_updateSetDataPos cvt.w.s $f0 vs SN cvt.w.s $f2. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void *cRoomSave_findEm(void *save, unsigned int id);
extern char D_005E8658[];

__attribute__((section(".text.cEmSetParam_updateSetDataPos")))
void cEmSetParam_updateSetDataPos(void *unused0, void *unused1, float *pos)
{
    short *em;
    float *s0 = pos;

    em = (short *)cRoomSave_findEm(D_005E8658);
    if (em != 0) {
        em[0] = (short)(int)(s0[0] * 20.0f);
        em[1] = (short)(int)(s0[1] * 20.0f);
        em[2] = (short)(int)(s0[2] * 20.0f);
    }
}
#endif

INCLUDE_ASM("asm/nonmatching", cEmSetParam_updateSetDataPos);
