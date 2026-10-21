/* NON_MATCHING func_001C2408 (sn-2.95.3-136): 2 differing words. Retail builds the
 * address of D_003BD6E8 in v1 after the quadword copy of the position; here it uses v0.
 * The short at 0x2AC is not yet in cGameObj, and cCockGetPoint_setData's definition
 * still has no parameters. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"

#define GOLD_KIND(o) (*(short *)((char *)(o) + 0x2AC))

extern void *D_003BD6E8;
extern void cCockGetPoint_setData(void *self, cVec *pos, unsigned short point, short kind);

/* Pays out gold (doubled after a clear) and shows the amount at the object. */
__attribute__((section(".text.func_001C2408")))
void func_001C2408(cGameObj *self, int gold)
{
    cVec pos;

    if (gold <= 0) {
        return;
    }
    if (cCoreSave_getClearNum(&D_00569B70)) {
        gold *= 2;
    }
    cCoreSave_addGold(&D_00569B70, gold, 0);
    VU0_LQC2(4, self->pos, 0);
    VU0_SQC2(4, &pos, 0);
    cCockGetPoint_setData((char *)D_003BD6E8 + 0x15C0, &pos, gold, GOLD_KIND(self));
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C2408);
#endif
