/* NON_MATCHING sfmpv_SearchDelim (cygnus-2.96, -freorder-blocks dropped;
 * PARK 79): searches both ring-buffer halves for an MPEG delimiter, including one that straddles the wrap (up to 3 tail bytes + 3 head bytes copied to a stack buffer).
 * Logic matches; retail allocates r=s2/p=s1 and places the in-buffer hit block right after the first search.
 * A goto layout compiles identically. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SfRing3511F8 {
    unsigned char *p0;  /* 0x00 */
    int n0;             /* 0x04 */
    unsigned char *p1;  /* 0x08 */
    int n1;             /* 0x0C */
} SfRing3511F8;

extern unsigned char *MPV_SearchDelim(unsigned char *p, int n, int mask);
extern int MPV_CheckDelim(unsigned char *p);
extern void *func_003A5148(void *d, const void *s, unsigned int n);

unsigned char *sfmpv_SearchDelim(SfRing3511F8 *r, int mask, int *found)
{
    unsigned char buf[16];
    unsigned char *p;
    int n0, n1, lim, i, d;

    *found = 0;
    p = MPV_SearchDelim(r->p0, r->n0, mask);
    if (p == 0) {
        if (r->n1 == 0)
            return p;
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
    p = MPV_SearchDelim(r->p1, r->n1, mask);
    if (p == 0)
        return p;
    }
    *found = MPV_CheckDelim(p);
    return p;
}
#else
INCLUDE_ASM("asm/nonmatching", sfmpv_SearchDelim);
#endif
