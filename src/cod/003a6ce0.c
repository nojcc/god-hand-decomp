/* sn-2.95.3-136 */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/sscanf.c. */

extern unsigned int strlen(const char *s);

#define va_start(ap, last) (ap = (char *)__builtin_next_arg(last) - 0x30)

/* sscanf: scan str as a read-only stream. */
__attribute__((section(".text.func_003A6CE0")))
int func_003A6CE0(const char *str, const char *fmt, ...) {
    int ret;
    char *ap;
    FILE f;
    f._flags = __SRD;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._r = strlen(str);
    f._read = func_003A6CD8;
    f._ub._base = 0;
    f._lb._base = 0;
    f._data = _REENT;
    va_start(ap, fmt);
    ret = __svfscanf(&f, fmt, ap);
    return ret;
}
