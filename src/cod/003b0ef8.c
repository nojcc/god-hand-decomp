/* ee-2.9-991111 */
#include "godhand/sceSnprintf.h"

extern char D_0045FE60[];           /* "0.%d" */
extern char D_0045FE68[];           /* "e+%d" */
extern char D_0045FE70[];           /* "e%d" */

/* Print d through put as a sign, "0." and six mantissa digits, then "e" and the
 * decimal exponent; returns the number of characters. The mantissa goes to ftoi
 * converted to an integer, which ftoi then reads as the bits of a double. */
__attribute__((section(".text.printfloat")))
int printfloat(SceSnprintfPut put, void *arg, int *pn, double d)
{
    int n = 0;
    int exp = 0;
    int digits;

    if (*pn == 0)
        return 0;
    if (d < 0.0) {
        n = 1;
        d = -d;
        put(arg, pn, '-');
        *pn = *pn - 1;
    }
    if (d < 0.1) {
        while (d < 0.1) {
            exp--;
            d = d * 10.0;
        }
    } else if (d >= 1.0) {
        while (d >= 1.0) {
            exp++;
            d = d / 10.0;
        }
    }
    digits = ftoi(d * 1000000.0);
    n += _sceSnprintf_pf(put, arg, pn, D_0045FE60, digits);
    if (exp >= 0)
        n += _sceSnprintf_pf(put, arg, pn, D_0045FE68, exp);
    else
        n += _sceSnprintf_pf(put, arg, pn, D_0045FE70, exp);
    return n;
}
