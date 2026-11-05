/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);


extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

/* libio genops.c :: _IO_flush_all_linebuffered */
__attribute__((section(".text._IO_flush_all_linebuffered")))
void _IO_flush_all_linebuffered(void) {
    struct _IO_FILE *fp;
    for (fp = D_003F50F8; fp != 0; fp = fp->_chain)
        if ((fp->_flags & 8) == 0 && fp->_flags & 0x200)
            (*fp->vtable->__overflow.pfn)(fp, -1);
}
