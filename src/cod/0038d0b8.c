/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);


extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

/* libio genops.c :: _IO_seekmark */
__attribute__((section(".text.func_0038D0B8")))
int func_0038D0B8(struct _IO_FILE *fp, struct _IO_marker *mark, int delta) {
    if (mark->_sbuf != fp)
        return -1;
    if (mark->_pos >= 0) {
        if (fp->_flags & 0x100)
            _IO_switch_to_main_get_area(fp);
        fp->_IO_read_ptr = fp->_IO_read_base + mark->_pos;
    } else {
        if (!(fp->_flags & 0x100))
            _IO_switch_to_backup_area(fp);
        fp->_IO_read_ptr = fp->_IO_read_end + mark->_pos;
    }
    return 0;
}
