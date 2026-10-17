/* NON_MATCHING MPV_SearchDelim (delayslot): cygnus dr: 32 diffs from one delay slot - retail fills the case-3 beq from the target (beql, q = p - 4), ours from the fall-through; the rest is the same code shifted */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned int MPV_CheckDelim(unsigned char *p);

unsigned char *MPV_SearchDelim(unsigned char *buf, int len, unsigned int mask)
{
    unsigned char *p = buf;
    unsigned char *end = p + len;
    unsigned int st = 0;
    unsigned char *q;
    signed char c;

    while (p < end) {
        c = *p++;
        switch (st) {
        case 0:
            if (c == 0)
                st = 1;
            break;
        case 1:
            st = (c != 0) ? 0 : 2;
            break;
        case 2:
            if (c == 1)
                st = 3;
            else if (c != 0)
                st = 0;
            break;
        case 3:
            q = p - 4;
            if (mask & MPV_CheckDelim(q))
                return q;
            st = 0;
            break;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", MPV_SearchDelim);
#endif
