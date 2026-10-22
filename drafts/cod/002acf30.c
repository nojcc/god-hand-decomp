/* NON_MATCHING func_002ACF30 (sn-2.95.3-136):
 * Register allocation differs in 5 instructions: retail recomputes self + top * 16 for the bufNum loads and loads
 * them into the tag register; this build copies the first address and loads into v0/a0. */
#include "include_asm.h"
#include "godhand/cIDManager.h"

#ifdef NON_MATCHING

/* Give back the last buffer run: only when the newest job carries tag and its run is buf, the run at the top of the pool. */
__attribute__((section(".text.func_002ACF30")))
int func_002ACF30(cIDManager *self, char *buf, int tag)
{
    int top;

    if (self->poolUsed == 0) {
        return 0;
    }
    top = self->jobNum - 1;
    if (self->job[top].tag != tag) {
        return 0;
    }
    if (self->pool + (self->poolUsed - self->job[top].bufNum) * CIDMGR_BUF_SIZE != buf) {
        return 0;
    }
    self->jobNum = top;
    self->poolUsed -= self->job[top].bufNum;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002ACF30);
#endif
