#include "include_asm.h"

#include "godhand/mwsfd.h"

#ifdef NON_MATCHING
/* Register allocation: retail keeps fill/max in a2/a3 and the limit in s0; one word longer. */
__attribute__((section(".text.sfmps_IsPrepEnd")))
int sfmps_IsPrepEnd(SfdHn *hn)
{
    SfdBufInf *inf = sfmps_GetSupSj(hn);
    int n = hn->fill;
    SfdBufCfg *cfg = &hn->cfg;
    int max = cfg->maxFill;
    int lim;

    if (n <= 0) {
        n = (inf->minFill > 0) ? inf->minFill : max;
    }
    lim = (n < max) ? n : max;
    return !(SFBUF_GetWTot(hn, 0) < lim);
}
#else
INCLUDE_ASM("asm/nonmatching", sfmps_IsPrepEnd);
#endif
