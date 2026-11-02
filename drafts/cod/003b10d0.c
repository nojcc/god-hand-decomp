/* ee-2.9-991111 */
#include "include_asm.h"
/* NON_MATCHING _sceSnprintf: the control flow and the jump table follow
 * retail; the registers and the frame do not. Retail keeps the width, the
 * prefix length and the running total in stack slots (0x50, 0x54, 0x58)
 * and the precision in t0, saved with sq around each call; this C keeps
 * them in t1..t3 and its frame is 0x140 bytes against 0x120. Retail's
 * buffer, prefix and n sit at 0x00, 0x20 and 0x40 (n is at 0x30 here), and
 * retail reads each format character once with lbu and sign-extends it where
 * it needs to. The signed d/i path calls func_003B8820 for v % 10, which
 * needs a __moddi3 alias in the linker script. */
/* _sceSnprintf: the printf core of the kernel library. Formats fmt with the
 * arguments at ap and sends each character to put(arg, pn, c); returns the
 * sum of put's results. Knows the flags - + 0 space #, a width, a precision
 * (also *), the sizes h and l, and d i u o x X p c s e f; any other
 * character after the % is printed as it is. A null string prints (null). */

#ifdef NON_MATCHING

typedef char *va_list;
#define va_arg(ap, type) (*(type *)((ap += 8) - 8))

#define PF_LEFT     0x001       /* - */
#define PF_PLUS     0x002       /* + */
#define PF_ZERO     0x004       /* 0 */
#define PF_SPACE    0x008       /* space */
#define PF_ALT      0x010       /* # */
#define PF_PREC     0x020       /* a precision was given */
#define PF_LONG     0x040       /* l */
#define PF_SHORT    0x080       /* h */
#define PF_CHAR     0x100       /* a character, not a number */

/* "0123456789abcdef" starts 2 bytes into this rodata object. */
extern const char D_0045FE8E[];
extern const char D_0045FEA8[];         /* "0123456789ABCDEF" */

extern float dptofp(double d);
extern int func_003B0EF8(int (*put)(void *arg, int *pn, int c), void *arg, int *pn, double d);

__attribute__((section(".text._sceSnprintf")))
int _sceSnprintf(int (*put)(void *arg, int *pn, int c), void *arg, int n, const char *fmt, va_list ap)
{
    char buf[32];
    char prefix[2];
    char *end;
    char *p;
    char *s;
    const char *digits;
    unsigned long u;
    long v;
    float f;
    int flags;
    int width;
    int prec;
    int pre;
    int total;
    int len;
    int pad;
    int i;
    char c;

    end = &buf[31];
    total = 0;
    while (*fmt != 0) {
        c = *fmt;
        flags = 0;
        width = 0;
        prec = 0;
        pre = 0;
        if (c == '%') {
            for (;;) {
                c = *++fmt;
                switch (c) {
                case '-':
                    flags |= PF_LEFT;
                    continue;
                case '+':
                    flags |= PF_PLUS;
                    continue;
                case '0':
                    flags |= PF_ZERO;
                    continue;
                case ' ':
                    flags |= PF_SPACE;
                    continue;
                case '#':
                    flags |= PF_ALT;
                    continue;
                case '1': case '2': case '3': case '4': case '5':
                case '6': case '7': case '8': case '9':
                    width = 0;
                    do {
                        width = width * 10 + c - '0';
                        c = *++fmt;
                    } while (c >= '0' && c <= '9');
                    if (c == 0)
                        break;
                    fmt--;
                    continue;
                case '.':
                    flags |= PF_PREC;
                    if (*++fmt == '*') {
                        i = va_arg(ap, int);
                        prec = i < -1 ? -1 : i;
                        continue;
                    }
                    c = *fmt;
                    i = 0;
                    while (c >= '0' && c <= '9') {
                        i = i * 10 + c - '0';
                        c = *++fmt;
                    }
                    prec = i < -1 ? -1 : i;
                    if (c == 0)
                        break;
                    fmt--;
                    continue;
                case 'l':
                    flags |= PF_LONG;
                    continue;
                case 'h':
                    flags |= PF_SHORT;
                    continue;
                case 'o':
                    if (flags & PF_LONG)
                        u = va_arg(ap, unsigned long);
                    else if (flags & PF_SHORT)
                        u = va_arg(ap, unsigned short);
                    else
                        u = va_arg(ap, unsigned int);
                    p = end;
                    if (u == 0) {
                        if (!(flags & PF_PREC) || prec != 0)
                            *p-- = '0';
                    } else {
                        do {
                            *p-- = (u & 7) + '0';
                            u >>= 3;
                        } while (u != 0);
                        if (flags & PF_ALT)
                            *p-- = '0';
                    }
                    s = p + 1;
                    len = end - p;
                    goto out;
                case 'x':
                    digits = D_0045FE8E + 2;
                    if (flags & PF_ALT) {
                        prefix[0] = '0';
                        prefix[1] = 'x';
                        pre = 2;
                    }
                    goto hex;
                case 'X':
                    digits = D_0045FEA8;
                    if (flags & PF_ALT) {
                        prefix[0] = '0';
                        prefix[1] = 'X';
                        pre = 2;
                    }
                hex:
                    if (flags & PF_LONG)
                        u = va_arg(ap, unsigned long);
                    else if (flags & PF_SHORT)
                        u = va_arg(ap, unsigned short);
                    else
                        u = va_arg(ap, unsigned int);
                    p = end;
                    if (u == 0) {
                        pre = 0;
                        if (!(flags & PF_PREC) || prec != 0)
                            *p-- = '0';
                    } else {
                        do {
                            *p-- = digits[u & 0xF];
                            u >>= 4;
                        } while (u != 0);
                    }
                    s = p + 1;
                    len = end - p;
                    goto out;
                case 'd':
                case 'i':
                    if (flags & PF_LONG)
                        v = va_arg(ap, long);
                    else if (flags & PF_SHORT)
                        v = va_arg(ap, short);
                    else
                        v = va_arg(ap, int);
                    p = end;
                    if (v < 0) {
                        prefix[0] = '-';
                        pre = 1;
                    } else if (flags & PF_PLUS) {
                        prefix[0] = '+';
                        pre = 1;
                    } else if (flags & PF_SPACE) {
                        prefix[0] = ' ';
                        pre = 1;
                    }
                    if (v == 0) {
                        if (!(flags & PF_PREC) || prec != 0)
                            *p-- = '0';
                    } else {
                        if (v < 0)
                            v = -v;
                        while (v != 0) {
                            *p-- = v % 10 + '0';
                            v /= 10;
                        }
                    }
                    s = p + 1;
                    len = end - p;
                    goto out;
                case 'u':
                    if (flags & PF_LONG)
                        u = va_arg(ap, unsigned long);
                    else if (flags & PF_SHORT)
                        u = va_arg(ap, unsigned short);
                    else
                        u = va_arg(ap, unsigned int);
                    p = end;
                    if (u == 0) {
                        if (!(flags & PF_PREC) || prec != 0)
                            *p-- = '0';
                    } else {
                        do {
                            *p-- = u % 10 + '0';
                            u /= 10;
                        } while (u != 0);
                    }
                    s = p + 1;
                    len = end - p;
                    goto out;
                case 'e':
                case 'f':
                    f = va_arg(ap, double);
                    if (f == 0.0f)
                        total += put(arg, &n, '0');
                    else
                        total += func_003B0EF8(put, arg, &n, f);
                    break;
                case 's':
                    s = va_arg(ap, char *);
                    if (s == 0) {
                        put(arg, &n, '(');
                        put(arg, &n, 'n');
                        put(arg, &n, 'u');
                        put(arg, &n, 'l');
                        put(arg, &n, 'l');
                        put(arg, &n, ')');
                        break;
                    }
                    if (flags & PF_PREC) {
                        for (len = 0; len < prec && s[len] != 0; len++)
                            ;
                    } else {
                        for (len = 0; s[len] != 0; len++)
                            ;
                    }
                    goto out;
                case 'c':
                    c = va_arg(ap, int);
                    flags |= PF_CHAR;
                    prec = 1;
                    p = end;
                    *p-- = c;
                    s = p + 1;
                    len = end - p;
                    goto out;
                case 'p':
                    u = va_arg(ap, unsigned int);
                    digits = D_0045FE8E + 2;
                    p = end;
                    if (u == 0) {
                        if (!(flags & PF_PREC) || prec != 0)
                            *p-- = '0';
                    } else {
                        do {
                            *p-- = digits[u & 0xF];
                            u >>= 4;
                        } while (u != 0);
                    }
                    prefix[0] = '0';
                    prefix[1] = 'x';
                    s = p + 1;
                    len = end - p;
                    pre = 2;
                    goto out;
                default:
                    if (c == 0)
                        break;
                    flags |= PF_CHAR;
                    prec = 1;
                    p = end;
                    *p-- = c;
                    s = p + 1;
                    len = end - p;
                out:
                    prec = len < prec ? prec - len : 0;
                    width = width - len - pre - prec;
                    p = s + len;
                    pad = ' ';
                    if (flags & PF_CHAR) {
                        if ((flags & PF_ZERO) && width > 0)
                            pad = '0';
                    } else {
                        if ((flags & (PF_ZERO | PF_PREC)) == PF_ZERO && width > 0)
                            pad = '0';
                    }
                    if (flags & PF_LEFT) {
                        for (i = 0; i < pre; i++)
                            total += put(arg, &n, prefix[i]);
                        for (i = 0; i < prec; i++)
                            total += put(arg, &n, '0');
                        while (s < p)
                            total += put(arg, &n, *s++);
                        for (i = 0; i < width; i++)
                            total += put(arg, &n, ' ');
                    } else if (flags & PF_ZERO) {
                        if (pad == '0') {
                            for (i = 0; i < pre; i++)
                                total += put(arg, &n, prefix[i]);
                            for (i = 0; i < width; i++)
                                total += put(arg, &n, pad);
                        } else {
                            for (i = 0; i < width; i++)
                                total += put(arg, &n, pad);
                            for (i = 0; i < pre; i++)
                                total += put(arg, &n, prefix[i]);
                        }
                        for (i = 0; i < prec; i++)
                            total += put(arg, &n, '0');
                        while (s < p)
                            total += put(arg, &n, *s++);
                    } else {
                        for (i = 0; i < width; i++)
                            total += put(arg, &n, pad);
                        for (i = 0; i < pre; i++)
                            total += put(arg, &n, prefix[i]);
                        for (i = 0; i < prec; i++)
                            total += put(arg, &n, '0');
                        while (s < p)
                            total += put(arg, &n, *s++);
                    }
                    break;
                }
                break;
            }
        } else if (c != 0) {
            total += put(arg, &n, c);
        }
        if (*fmt != 0)
            fmt++;
    }
    put(arg, &n, 0);
    return total;
}
#else
INCLUDE_ASM("asm/nonmatching", _sceSnprintf);
#endif
