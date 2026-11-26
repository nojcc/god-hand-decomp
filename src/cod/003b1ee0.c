/* ee-2.9-991111 matched TU. */

#include "godhand/sceSnprintf.h"

typedef void *va_list;
#define va_start(ap, last) (ap = (void *)((char *)__builtin_next_arg(last) - 0x28))
#define va_end(ap)




/* snprintf: format fmt into buf, writing at most n bytes with the terminator. */
__attribute__((section(".text.func_003B1EE0")))
int func_003B1EE0(char *buf, int n, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _sceSnprintf((SceSnprintfPut)snprintf_char, &buf, n, fmt, ap);
}
