/* NON_MATCHING SearchData (sn-2.95.3-136): 6 instructions differ. Retail adds the entry offset to the pack as (offset + pack) where ours emits (pack + offset); only an int sum ((int)pack) reproduces that. The name pointer is set up before the count == 0 test in retail, after it in ours, and the two compare arguments load in the other order. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cIDManager.h"

extern int func_003A5678(char *a, char *b);

/* Finds the which-th entry named name in a data pack (a count, the entry offsets, then
 * one 4-byte name per entry) and returns its address, or 0. */
__attribute__((section(".text.SearchData")))
void *SearchData(void *pack, void *name, int which)
{
    unsigned int count;
    unsigned int i;
    int found;
    char *key;

    if (pack == 0)
        return 0;
    count = *(unsigned int *)pack;
    found = 0;
    for (i = 1, key = (char *)pack + count * 4 + 4; i <= count; i++, key += 4) {
        if (func_003A5678(key, name) == 0 && found++ == which)
            return ((int *)pack)[i] + (char *)pack;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", SearchData);
#endif
