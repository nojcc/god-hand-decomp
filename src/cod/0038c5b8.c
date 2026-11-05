/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);


extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */
__attribute__((section(".text.__underflow")))

/* libio genops.c :: __underflow */
int __underflow(struct _IO_FILE *fp) {
    if (fp->_flags & 0x800)
        if (_IO_switch_to_get_mode(fp) == -1)
            return -1;
    if (fp->_IO_read_ptr < fp->_IO_read_end)
        return *(unsigned char *) fp->_IO_read_ptr;
    if (fp->_flags & 0x100) {
        _IO_switch_to_main_get_area(fp);
        if (fp->_IO_read_ptr < fp->_IO_read_end)
            return *(unsigned char *) fp->_IO_read_ptr;
    }
    if (fp->_markers != 0) {
        if (save_for_backup(fp))
            return -1;
    } else if (fp->_IO_save_base != 0)
        _IO_free_backup_area(fp);
    return (*fp->vtable->__underflow.pfn)(fp);
}
