/* sn-2.95.3-136: player sub-screen predicates (0x12BAB8).
* Both: 5 differing insns in the subSel range tail.
* Retail keeps
 * slti/nop/beqz/nop/bltz back to the shared return-0 block
 * nested ifs, switch, goto, early returns, inlining. */
#include "include_asm.h"
#include "godhand/player.h"

#ifdef NON_MATCHING
/* pl00_CkSubScreen's INCLUDE_ASM stays in 000000.c. */
int pl00_CkSubScreen(PlSub *pl)
{
    int sel;

    if (pl->subOpen != 0) {
        return 0;
    }
    sel = pl->subSel;
    if (sel < 4) {
        if (sel >= 0) {
            return 1;
        }
    }
    return 0;
}

int func_0012BAF0(PlSub *pl)
{
    int sel;

    if (pl->flags15F4 & 0x400) {
        return 1;
    }
    if (pl->subOpen != 0) {
        return 0;
    }
    sel = pl->subSel;
    if (sel < 4) {
        if (sel >= 0) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012BAF0);
#endif
