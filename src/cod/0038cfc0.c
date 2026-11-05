/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);


extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */
/* libio genops.c :: _IO_init_marker */
__attribute__((section(".text._IO_init_marker")))
void _IO_init_marker(struct _IO_marker *marker, struct _IO_FILE *fp) {
    marker->_sbuf = fp;
    if (fp->_flags & 0x800)
        _IO_switch_to_get_mode(fp);
    if (fp->_flags & 0x100)
        marker->_pos = fp->_IO_read_ptr - fp->_IO_read_end;
    else
        marker->_pos = fp->_IO_read_ptr - fp->_IO_read_base;

    marker->_next = fp->_markers;
    fp->_markers = marker;
}
