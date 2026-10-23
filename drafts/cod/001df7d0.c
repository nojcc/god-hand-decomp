/* sn-2.95.3-136 */
/* Retail tests the language as three branches (== 0, < 0, < 7); this C
 * folds the last two into one unsigned compare (3 instructions differ). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int D_00747A0C;
extern void CustomIDWork_SetLocalPosX(void *work, int x);

static inline int langBad(int lang)
{
    if (lang < 0 || lang >= 7) {
        return 1;
    }
    return 0;
}

/* Sets the work's local x from the language and whether the alternate
 * position is wanted. */
__attribute__((section(".text.func_001DF7D0")))
void func_001DF7D0(char *self, int alt)
{
    int x;

    if (D_00747A0C == 0 || langBad(D_00747A0C)) {
        x = alt ? -0x61 : 0x12;
    } else {
        x = alt ? -0x4F : 0x19;
    }
    CustomIDWork_SetLocalPosX(self + 0x440, x);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001DF7D0);
#endif
