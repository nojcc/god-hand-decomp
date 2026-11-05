/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
#include "godhand/criStm.h"
#include "godhand/newlibMalloc.h"

extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

/* libio genops.c :: save_for_backup */
__attribute__((section(".text.save_for_backup")))
int save_for_backup(struct _IO_FILE *fp) {
    int least_mark = _IO_least_marker(fp);
    int needed_size = (fp->_IO_read_end - fp->_IO_read_base) - least_mark;
    int current_Bsize = fp->_IO_save_end - fp->_IO_save_base;
    int avail;
    int delta;
    struct _IO_marker *mark;
    if (needed_size > current_Bsize) {
        char *new_buffer;
        avail = 100;
        new_buffer = (char *) func_003A7C70(avail + needed_size);
        if (new_buffer == 0)
            return -1;
        if (least_mark < 0) {
            func_003A5148(new_buffer + avail,
                          fp->_IO_save_end + least_mark,
                          -least_mark);
            func_003A5148(new_buffer + avail - least_mark,
                          fp->_IO_read_base,
                          fp->_IO_read_end - fp->_IO_read_base);
        } else
            func_003A5148(new_buffer + avail,
                          fp->_IO_read_base + least_mark,
                          needed_size);
        if (fp->_IO_save_base)
            UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_save_base);
        fp->_IO_save_base = new_buffer;
        fp->_IO_save_end = new_buffer + avail + needed_size;
    } else {
        avail = current_Bsize - needed_size;
        if (least_mark < 0) {
            func_003A51F4(fp->_IO_save_base + avail,
                          fp->_IO_save_end + least_mark,
                          -least_mark);
            func_003A5148(fp->_IO_save_base + avail - least_mark,
                          fp->_IO_read_base,
                          fp->_IO_read_end - fp->_IO_read_base);
        } else if (needed_size > 0)
            func_003A5148(fp->_IO_save_base + avail,
                          fp->_IO_read_base + least_mark,
                          needed_size);
    }
    fp->_IO_backup_base = fp->_IO_save_base + avail;
    delta = fp->_IO_read_end - fp->_IO_read_base;
    for (mark = fp->_markers; mark != 0; mark = mark->_next)
        mark->_pos -= delta;
    return 0;
}
