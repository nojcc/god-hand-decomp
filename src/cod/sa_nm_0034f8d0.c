/* NM, not registered. cygnus-2.96 (no -freorder-blocks): Sofdec buffer fill check at 0x34F8D0. */
#include "include_asm.h"

#include "godhand/mwsfd.h"

#ifdef NON_MATCHING
/* Register allocation: retail keeps fill/max in a2/a3 and the limit in s0; one word longer. */
__attribute__((section(".text.func_0034F8D0")))
int func_0034F8D0(SfdHn *hn)
{
    SfdBufInf *inf = func_0034E988(hn);
    int n = hn->fill;
    SfdBufCfg *cfg = &hn->cfg;
    int max = cfg->maxFill;
    int lim;

    if (n <= 0) {
        n = (inf->minFill > 0) ? inf->minFill : max;
    }
    lim = (n < max) ? n : max;
    return !(func_0034C7F0(hn, 0) < lim);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034F8D0);
#endif
