/* NON_MATCHING func_003AD348 (sn-2.95.3-136): 3 instructions differ from retail.
 * Retail's assembler expands `dli $r,0xffffffff` as addiu -1; dsrl32 (ee-as uses lui 0xffff), and it
 * pads the call-free short ilogb loops, which ps2eeas (as: sn) does not. The fixed-point loop
 * keeps retail's bottom test only as `n-- > 0`, giving bgtz where retail has bnez. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef union { double value; struct { unsigned int lsw; unsigned int msw; } parts; } U;

#define EXTRACT_WORDS(ix0, ix1, d)                                      \
    do { U ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)

#define INSERT_WORDS(d, ix0, ix1)                                       \
    do { U iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

extern double func_0031E348(double a, double b);    /* dpmul */
extern double func_0031E5F0(double a, double b);    /* dpdiv */

extern const double D_0045FBF8[];                   /* Zero[] = { 0.0, -0.0 } */

/* x - n*y for the integer n of x/y truncated toward zero, computed exactly on the bits. */
__attribute__((section(".text.func_003AD348")))
double func_003AD348(double x, double y)
{
    int n, hx, hy, hz, ix, iy, sx, i;
    unsigned int lx, ly, lz;

    EXTRACT_WORDS(hx, lx, x);
    EXTRACT_WORDS(hy, ly, y);
    sx = hx & 0x80000000;               /* sign of x */
    hx ^= sx;                           /* |x| */
    hy &= 0x7fffffff;                   /* |y| */

    /* purge off exception values */
    if ((hy | ly) == 0 || (hx >= 0x7ff00000) ||         /* y=0, or x not finite */
        ((hy | ((ly | -ly) >> 31)) > 0x7ff00000))       /* or y is NaN */
        return func_0031E5F0(func_0031E348(x, y), func_0031E348(x, y));
    if (hx <= hy) {
        if ((hx < hy) || (lx < ly)) return x;           /* |x|<|y| return x */
        if (lx == ly)
            return D_0045FBF8[(unsigned int)sx >> 31];  /* |x|=|y| return x*0 */
    }

    /* determine ix = ilogb(x) */
    if (hx < 0x00100000) {              /* subnormal x */
        if (hx == 0) {
            for (ix = -1043, i = lx; i > 0; i <<= 1) ix -= 1;
        } else {
            for (ix = -1022, i = (hx << 11); i > 0; i <<= 1) ix -= 1;
        }
    } else ix = (hx >> 20) - 1023;

    /* determine iy = ilogb(y) */
    if (hy < 0x00100000) {              /* subnormal y */
        if (hy == 0) {
            for (iy = -1043, i = ly; i > 0; i <<= 1) iy -= 1;
        } else {
            for (iy = -1022, i = (hy << 11); i > 0; i <<= 1) iy -= 1;
        }
    } else iy = (hy >> 20) - 1023;

    /* set up {hx,lx}, {hy,ly} and align y to x */
    if (ix >= -1022)
        hx = 0x00100000 | (0x000fffff & hx);
    else {                              /* subnormal x, shift x to normal */
        n = -1022 - ix;
        if (n <= 31) {
            hx = (hx << n) | (lx >> (32 - n));
            lx <<= n;
        } else {
            hx = lx << (n - 32);
            lx = 0;
        }
    }
    if (iy >= -1022)
        hy = 0x00100000 | (0x000fffff & hy);
    else {                              /* subnormal y, shift y to normal */
        n = -1022 - iy;
        if (n <= 31) {
            hy = (hy << n) | (ly >> (32 - n));
            ly <<= n;
        } else {
            hy = ly << (n - 32);
            ly = 0;
        }
    }

    /* fix point fmod */
    n = ix - iy;
    while (n-- > 0) {
        hz = hx - hy; lz = lx - ly; if (lx < ly) hz -= 1;
        if (hz < 0) { hx = hx + hx + (lx >> 31); lx = lx + lx; }
        else {
            if ((hz | lz) == 0)         /* return sign(x)*0 */
                return D_0045FBF8[(unsigned int)sx >> 31];
            hx = hz + hz + (lz >> 31); lx = lz + lz;
        }
    }
    hz = hx - hy; lz = lx - ly; if (lx < ly) hz -= 1;
    if (hz >= 0) { hx = hz; lx = lz; }

    /* convert back to floating value and restore the sign */
    if ((hx | lx) == 0)                 /* return sign(x)*0 */
        return D_0045FBF8[(unsigned int)sx >> 31];
    while (hx < 0x00100000) {           /* normalize x */
        hx = hx + hx + (lx >> 31); lx = lx + lx;
        iy -= 1;
    }
    if (iy >= -1022) {                  /* normalize output */
        hx = ((hx - 0x00100000) | ((iy + 1023) << 20));
        INSERT_WORDS(x, hx | sx, lx);
    } else {                            /* subnormal output */
        n = -1022 - iy;
        if (n <= 20) {
            lx = (lx >> n) | ((unsigned int)hx << (32 - n));
            hx >>= n;
        } else if (n <= 31) {
            lx = (hx << (32 - n)) | (lx >> n); hx = sx;
        } else {
            lx = hx >> (n - 32); hx = sx;
        }
        INSERT_WORDS(x, hx | sx, lx);
    }
    return x;                           /* exact output */
}
#else
INCLUDE_ASM("asm/nonmatching", func_003AD348);
#endif
