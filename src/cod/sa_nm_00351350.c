/* NON_MATCHING sfmpv_BsearchDelim (cygnus-2.96, -freorder-blocks dropped; PARK 78 at attempt 2): backward twin of sfmpv_SearchDelim (sa_nm_003511f8.c, same unsolved shape): search the second ring half from its end, then a delimiter straddling the wrap (3+3 bytes copied to a stack buffer), then the first half. Logic matches; retail allocates r=s2/p=s1 and places the straddle-hit block right after `b hit` (a barrier before the straddle code). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SfRing351350 {
    unsigned char *p0;  /* 0x00 */
    int n0;             /* 0x04 */
    unsigned char *p1;  /* 0x08 */
    int n1;             /* 0x0C */
} SfRing351350;

extern unsigned char *MPV_BsearchDelim(unsigned char *end, int n, int mask);
extern int MPV_CheckDelim(unsigned char *p);
extern void *func_003A5148(void *d, const void *s, unsigned int n);

unsigned char *sfmpv_BsearchDelim(SfRing351350 *r, int mask, int *found)
{
    unsigned char buf[16];
    unsigned char *p;
    int n0, n1, lim, i, d;

    *found = 0;
    if (r->n1 == 0)
        goto first;
    p = MPV_BsearchDelim(r->p1 + r->n1, r->n1, mask);
    if (p == 0) {
        n0 = r->n0;
        if (n0 >= 4)
            n0 = 3;
        n1 = r->n1;
        if (n1 >= 4)
            n1 = 3;
        func_003A5148(buf, r->p0 + r->n0 - n0, n0);
        func_003A5148(buf + n0, r->p1, n1);
        lim = n0 + n1 - 3;
        for (i = 0; i < lim; i++) {
            d = MPV_CheckDelim(buf + i);
            if (d & mask) {
                *found = d;
                return r->p0 + r->n0 - n0 + i;
            }
        }
first:
        p = MPV_BsearchDelim(r->p0 + r->n0, r->n0, mask);
        if (p == 0)
            return p;
    }
    *found = MPV_CheckDelim(p);
    return p;
}
#else
INCLUDE_ASM("asm/nonmatching", sfmpv_BsearchDelim);
#endif
