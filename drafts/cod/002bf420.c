/* NON_MATCHING func_002BF420 (sn-2.95.3-136): 2 differing: retail loads the 4 for keep into the beqz delay slot before the 1 for the byte at 0xC. The permuter only closes it by holding 4 in a variable, which the rules forbid. */
/* sn-2.95.3-136: func_002BF420, reset a scenario cursor unless the system word after D_00747A84 is negative:
 * keep 4 with the byte at 0xC set when bit 6 of the game flags is on, otherwise keep 5. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/ScenarioCursor.h"

extern int D_00747A84[];                /* system flag words; [-24] is the game flags D_00747A24 */

__attribute__((section(".text.func_002BF420")))
void func_002BF420(ScenarioCursor *self)
{
    if (D_00747A84[1] >= 0) {
        unsigned long flags = D_00747A84[-24];
        unsigned long bit = (flags >> 6) & 1;

        if (bit != 0) {
            ((char *)self)[0xC] = 1;
            self->keep = 4;
            self->unk03 = 0;
        } else {
            self->unk03 = 0;
            self->keep = 5;
        }
        self->unk02 = 0;
        self->step = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BF420);
#endif
