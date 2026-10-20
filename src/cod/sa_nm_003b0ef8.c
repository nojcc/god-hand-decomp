/* NON_MATCHING func_003B0EF8 (ee-2.9-991111; PARK, 45 diffs): retail loads 0.1, 0.1 and 1e6 from the split rodata blob (D_0045FE78/80/88), which needs the per-file extern_double setting (li.d slots D_0045FE78,-,D_0045FE80,-,-,-,D_0045FE88). That setting is not on the standing-approval list. With it, what remains is the two loop-condition branches (ours bltzl/bgezl, retail plain bltz/bgez) and the "0.%d" address formed early in s0. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_003B0EF8: sce snprintf helper: print a double as "0.<6 digits>e<exp>" (sign first through
 * the put-char callback), normalising the mantissa into [0.1, 1) by powers of ten. */
extern int _sceSnprintf_pf(void *cb, void *state, int *pn, const char *fmt, ...);
extern int func_003B0E68(unsigned long long d);
extern char D_0045FE60[];
extern char D_0045FE68[];
extern char D_0045FE70[];

__attribute__((section(".text.func_003B0EF8")))
int func_003B0EF8(void (*cb)(void *, int *, int), void *state, int *pn, double d)
{
    int n;
    int e;

    n = 0;
    e = 0;
    if (*pn == 0)
        return 0;
    if (d < 0) {
        d = 0 - d;
        n = 1;
        cb(state, pn, '-');
        *pn = *pn - 1;
    }
    if (d < 0.1) {
        while (d < 0.1) {
            d = d * 10.0;
            e--;
        }
    } else if (d >= 1.0) {
        while (d >= 1.0) {
            d = d / 10.0;
            e++;
        }
    }
    n += _sceSnprintf_pf(cb, state, pn, D_0045FE60, func_003B0E68((unsigned long long)(d * 1000000.0)));
    if (e >= 0)
        n += _sceSnprintf_pf(cb, state, pn, D_0045FE68, e);
    else
        n += _sceSnprintf_pf(cb, state, pn, D_0045FE70, e);
    return n;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B0EF8);
#endif
