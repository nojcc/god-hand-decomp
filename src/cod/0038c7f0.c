/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);


extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

/* libio genops.c :: _IO_doallocbuf */
__attribute__((section(".text.func_0038C7F0")))
void func_0038C7F0(struct _IO_FILE *fp) {
    if (fp->_IO_buf_base)
        return;
    if (!(fp->_flags & 2))
        if ((*fp->vtable->__doallocate.pfn)(fp) != -1)
            return;
    func_0038C768(fp, fp->_shortbuf, fp->_shortbuf + 1, 0);
}
