/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
#include "godhand/criStm.h"

extern int _IO_least_marker(struct _IO_FILE *fp);


extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

/* libio genops.c :: _IO_default_xsgetn */
__attribute__((section(".text._IO_default_xsgetn")))
_IO_size_t _IO_default_xsgetn(struct _IO_FILE *fp, void *data, _IO_size_t n) {
    _IO_size_t more = n;
    char *s = (char*) data;
    for (;;) {
        _IO_ssize_t count = fp->_IO_read_end - fp->_IO_read_ptr;
        if (count > 0) {
            if ((_IO_size_t) count > more)
                count = more;
            if (count > 20) {
                func_003A5148(s, fp->_IO_read_ptr, count);
                s += count;
                fp->_IO_read_ptr += count;
            } else if (count <= 0)
                count = 0;
            else {
                char *p = fp->_IO_read_ptr;
                int i = (int) count;
                while (--i >= 0)
                    *s++ = *p++;
                fp->_IO_read_ptr = p;
            }
            more -= count;
        }
        if (more == 0 || __underflow(fp) == -1)
            break;
    }
    return n - more;
}
