/* ee-2.9-991111 matched TU. */
#include "godhand/libio.h"
#include "godhand/newlibMalloc.h"

/* libio genops.c :: _IO_free_backup_area */
__attribute__((section(".text._IO_free_backup_area")))
void _IO_free_backup_area(struct _IO_FILE *fp) {
    if (fp->_flags & _IO_IN_BACKUP) {
        _IO_switch_to_main_get_area(fp);
    }
    UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_save_base);
    fp->_IO_save_base = 0;
    fp->_IO_save_end = 0;
    fp->_IO_backup_base = 0;
}
