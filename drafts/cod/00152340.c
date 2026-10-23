/* NON_MATCHING func_00152340 (sn-2.95.3-136): retail loads the alignment 8 into three
 * registers (two divisors and a divide-by-zero check), as if it were a variable; with
 * the literal the compiler shares one register, four words shorter. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/pack.h"

static inline unsigned int Pack_alignUp(unsigned int addr, unsigned int align)
{
    return addr + (align - addr % align) % align;
}

/* Index of `key` in a keyed pack's key table, or -1 when the pack has no
 * keys or the key is missing. */
__attribute__((section(".text.func_00152340")))
int func_00152340(Pack *pack, long key)
{
    long *keys;
    int i;

    keys = (long *)Pack_alignUp((unsigned int)pack + (pack->count * 4 + 0x10), 8);
    if (func_00151630(pack) != 3) {
        return -1;
    }
    for (i = 0; i < pack->count; i++) {
        if (keys[i] == key) {
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00152340);
#endif
