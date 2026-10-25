/* sn-2.95.3-136 */
/* func_003A96C0 (libc floating-point conversion): 364 of 367 words.
 * Retail keeps fmt in its stack slot and len in fp; this C gives fmt the
 * saved register and spills len. The double operations bind dpmul, litodp
 * and dptoli, which config/symbol_addrs.txt still calls func_0031E348,
 * func_0031E8C0 and func_0031E978. */
#include "include_asm.h"

#ifdef NON_MATCHING

extern void *memcpy(void *dst, const void *src, unsigned int n);

extern double func_003AD158(double x);
extern double func_003AD348(double x, double y);
extern int RoundDigitString(char *digits, int n);
extern char *func_003A9620(int value, char *str, int base);
extern char D_0077D9E0[] __attribute__((aligned(8)));
extern const char D_0045F6F0[] __attribute__((aligned(8)));
extern const char D_0045F6F8[] __attribute__((aligned(8)));
extern const char D_0045F700[] __attribute__((aligned(8)));

typedef union { double value; long bits; } DoubleBits;

/* Convert value to ndigit digits after the point in the static buffer, in the
 * 'f' or the exponent form of fmt; flag strips the trailing zeros. A negative
 * sign goes to *sign when sign is given, else to the buffer. */
__attribute__((section(".text.func_003A96C0")))
char *func_003A96C0(double value, int ndigit, char fmt, int flag, char *sign)
{
    DoubleBits u;
    unsigned int hi;
    int lo;
    int bexp;
    int neg;
    int mant;
    int nd;
    char *p;
    int n;
    int exp;
    int last;
    int d;
    int i;
    int pos;
    int len;
    double ip;
    double eps;

    u.value = value;
    lo = (int)u.bits;
    hi = (unsigned int)(u.bits >> 32);
    neg = hi >> 20 & 0x800;
    mant = hi & 0xFFFFF;
    bexp = hi >> 20 & 0x7FF;
    if (bexp == 0x7FF) {
        if (mant != 0 || lo != 0)
            memcpy(D_0077D9E0, D_0045F700, 4);
        else if (neg != 0)
            memcpy(D_0077D9E0, D_0045F6F0, 5);
        else
            memcpy(D_0077D9E0, D_0045F6F8, 4);
        return D_0077D9E0;
    }
    nd = ndigit;
    n = 0;
    if (value < 0.0) {
        if (sign != 0) {
            *sign = '-';
            p = D_0077D9E0;
        } else {
            D_0077D9E0[0] = '-';
            p = D_0077D9E0 + 1;
        }
        value = 0.0 - value;
    } else {
        p = D_0077D9E0;
    }
    exp = 0;
    if (value >= 1.0) {
        ip = func_003AD158(value);
        value = value - ip;
        while (n < 0xA3) {
            d = (int)func_003AD348(ip, 10.0);
            p[n++] = d + '0';
            ip = (ip - d) * 0.1;
            if (ip < 1.0)
                break;
        }
        for (i = 0, last = n - 1; i < last; i++, last--) {
            char c = p[i];
            p[i] = p[last];
            p[last] = c;
        }
        exp = n;
    }
    if (exp == 0) {
        if (fmt != 'f') {
            if (value != 0.0) {
                while ((value = value * 10.0) < 1.0 && exp >= -1020)
                    exp--;
                exp--;
            }
            if (value >= 1.0) {
                value = value * 0.1;
                nd = ndigit + 1;
            }
        } else {
            p[0] = '0';
            n = 1;
        }
    }
    if (exp < 0)
        last = nd;
    else if (fmt != 'f')
        last = nd + 1;
    else
        last = nd + (exp > 0 ? exp : 1);
    eps = 5.5511151231257827e-17;
    len = last + 1;
    for (;;) {
        value = value * 10.0;
        d = (int)value;
        value = value - d;
        eps = eps * 10.0;
        if (n < last && value >= eps && value <= 1.0 - eps)
            p[n++] = d + '0';
        else
            break;
    }
    if (value >= 0.5)
        d++;
    p[n++] = d + '0';
    while (n <= last)
        p[n++] = '0';
    if (RoundDigitString(p, len) == 0) {
        p[0] = '1';
        last = len;
        exp++;
    }
    if (ndigit != 0) {
        pos = fmt == 'f' && exp > 0 ? exp : 1;
        for (i = last; i > pos; i--)
            p[i] = p[i - 1];
        p[pos] = '.';
    } else {
        last--;
    }
    if (flag != 0) {
        while (last != 0 && p[last] == '0')
            last--;
        if (p[last] == '.')
            last--;
    }
    if (fmt != 'f') {
        p[++last] = fmt;
        if (exp >= 0) {
            if (exp != 0)
                exp--;
            p[++last] = '+';
            if (exp < 10)
                p[++last] = '0';
        } else {
            p[++last] = '-';
            if (exp >= -9)
                p[++last] = '0';
            exp = -exp;
        }
        func_003A9620(exp, &p[++last], 10);
    } else {
        p[last + 1] = '\0';
    }
    return D_0077D9E0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003A96C0);
#endif
