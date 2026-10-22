/* NON_MATCHING func_0012C000 (sn-2.95.3-136, extern_jtbl D_0041D1A0): 52 vs 53 words. Retail threads the default case straight into the call with its own copy of the count load, and ends with a branch where ours uses xori. */
/* sn-2.95.3-136: func_0012C000, whether the combo for set `set` is used up: the holder's current set at
 * 0x5E2 must be `set` (set 0 also needs D_005CB010 clear), and its count at 0x5E0 must have reached
 * cCoreSave_getComboMax for that set. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cCoreSave.h"

/* The part of the combo holder this function reads. */
typedef struct ComboHolder {
    char unk000[0x5E0];
    unsigned short count;               /* 0x5E0 */
    unsigned short set;                 /* 0x5E2 */
} ComboHolder;

extern unsigned char D_005CB010;

__attribute__((section(".text.func_0012C000")))
int func_0012C000(ComboHolder *self, unsigned int set)
{
    unsigned int cur;
    unsigned int want;
    int count;

    switch (set) {
    case 0:
    default:
        if (D_005CB010 != 0)
            return 0;
        cur = self->set;
        if (cur != 0)
            return 0;
        count = self->count;
        if (count < cCoreSave_getComboMax(&D_00569B70, cur))
            return 0;
        return 1;
    case 1:
        cur = self->set;
        want = 1;
        break;
    case 2:
        cur = self->set;
        want = 2;
        break;
    case 3:
        cur = self->set;
        want = 3;
        break;
    case 4:
        cur = self->set;
        want = 4;
        break;
    case 5:
        cur = self->set;
        want = 5;
        break;
    }
    if (cur != want)
        return 0;
    count = self->count;
    if (count < cCoreSave_getComboMax(&D_00569B70, cur))
        return 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012C000);
#endif
