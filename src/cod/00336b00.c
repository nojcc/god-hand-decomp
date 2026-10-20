/* NON_MATCHING func_00336B00: retail's case tree pivots on 0xCB (0xC9 left;
* 0xCD, 0x12B, 0x191 right) while gcc picks 0xCD for these five cases; the bodies match. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int func_00336AC0(int *hn);
extern int func_00336510(int *hn);

int func_00336B00(int *hn, int id)
{
    int r = 0;

    if (hn == 0)
        return 0;
    switch (id) {
    case 0xC9:
        r = func_00336AC0(hn);
        break;
    case 0xCB:
    case 0xCD:
        r = func_00336510(hn);
        break;
    case 0x12B:
        break;
    case 0x191:
        r = 1;
        break;
    default:
        return 0;
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00336B00);
#endif
