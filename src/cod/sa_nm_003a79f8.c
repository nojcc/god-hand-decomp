/* NON_MATCHING func_003A79F8 (sn): newlib __sccl; 1 diff: the beql into the range-fill loop targets the label before the loop-align nop (ours) instead of after it (retail); do/while and for forms keep it */
#include "include_asm.h"

#ifdef NON_MATCHING
char *func_003A79F8(char *tab, char *fmt)
{
    int c, n, v;
    char *p;

    c = *fmt++;
    if (c == '^') {
        v = 1;
        c = *fmt++;
    } else {
        v = 0;
    }
    for (n = 255, p = tab + 255; n >= 0; n--) {
        *p = v;
        p--;
    }
    if (c == 0) {
        return fmt - 1;
    }
    v = 1 - v;
    for (;;) {
        tab[c] = v;
doswitch:
        n = *fmt++;
        switch (n) {
        case 0:
            return fmt - 1;
        case '-':
            n = *fmt;
            if (n == ']' || n < c) {
                c = '-';
                break;
            }
            fmt++;
            do {
                tab[++c] = v;
            } while (c < n);
            goto doswitch;
        case ']':
            return fmt;
        default:
            c = n;
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_003A79F8);
#endif
