/* NON_MATCHING func_00376720 (sn-2.95.3-136, as=sn): same size, 19 insns: this for-loop hoists i-- to the top and schedules ori/args ahead of the timer test.
 * The m2c goto form (f preloaded, 'if (--i >= 0) { f = e[0]; goto loop; }') reproduces the whole body exactly but inverts the loop exit (bltzl + fallthrough instead of bgezl back-edge), drops the pre-label nop and reorders the prologue saves.
 * Tried: for loop, do/break, goto loop. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_00376B80(char *slot, unsigned short *e);

void func_00376720(char *slot)
{
    unsigned short *e = (unsigned short *)(slot + 0x40);
    int i;

    for (i = 7; i >= 0; i--) {
        unsigned short f = e[0];

        if (f != 0 && !(f & 2)) {
            if (*(short *)((char *)e + 0x12) == 0) {
                e[0] = f | 2;
                func_00376B80(slot, e);
            } else {
                *(unsigned short *)((char *)e + 0x12) -= 1;
            }
        }
        e = (unsigned short *)((char *)e + 0x14);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00376720);
#endif
