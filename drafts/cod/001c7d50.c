/* NON_MATCHING cOmSub_setVibration (sn-2.95.3-136, as=sn): 12 differing words; retail
 * keeps the flag byte's lbu/ori/sb ahead of both int-to-float conversions and stores the
 * count before converting the period, where ours hoists both conversions. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmSub.h"

#define COMSUB_VIBRATING    8
#define COMSUB_VIB(self)    ((float *)((char *)(self) + 0x140))

/* Start the record shaking: count, period and per-axis amplitude. */
__attribute__((section(".text.cOmSub_setVibration")))
void cOmSub_setVibration(cOmSub *self, int count, int period, float x, float y, float z)
{
    self->unk03 |= COMSUB_VIBRATING;
    COMSUB_VIB(self)[0] = count;
    COMSUB_VIB(self)[1] = period;
    COMSUB_VIB(self)[2] = x;
    COMSUB_VIB(self)[3] = y;
    COMSUB_VIB(self)[4] = z;
}
#else
INCLUDE_ASM("asm/nonmatching", cOmSub_setVibration);
#endif
