/* NON_MATCHING func_003A93F8 (sn-2.95.3-136, as=sn): strstr; the C reproduces every retail instruction, but retail has two nops at the outer loop head (branch target after the delay-slot lb of *p) that neither sn nor cygnus, with as sn or ee, emits. Matching would need two inline nops (only one is allowed). Also in asm_fix_later style: revisit if a toolchain hazard option turns up. */
#include "include_asm.h"

#ifdef NON_MATCHING
char *func_003A93F8(char *s, char *p)
{
    int i;

    if (*s == 0) {
        if (*p != 0)
            return 0;
        return s;
    }
    while (*s != 0) {
        for (i = 0; ; i++) {
            if (p[i] == 0)
                return s;
            if (p[i] != s[i])
                break;
        }
        s++;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003A93F8);
#endif
