/* NON_MATCHING func_003BBEC0 (cygnus-2.96, drop-reorder;
 * PARK): backward scan of a counted string.
 * Retail sign-extends the char with sll/sra and a dead stack store, and builds -1 with lui/ori. */
#include "include_asm.h"

#ifdef NON_MATCHING
int func_003BBEC0(char **pp, int c, unsigned int n)
{
    char *s = *pp;
    int ch = (signed char)c;
    int len = *(int *)(s - 0x10);
    int i;

    if (len == 0)
        goto miss;
    i = len - 1;
    if (n < (unsigned int)i)
        i = (int)n;
    i++;
    while (i != 0) {
        i--;
        if (s[i] == ch)
            return i;
    }
miss:
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003BBEC0);
#endif
