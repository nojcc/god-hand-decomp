/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
#include "godhand/newlibMalloc.h"

extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void _IO_un_link(struct _IO_FILE *fp);

/* libio genops.c :: _IO_default_finish */
__attribute__((section(".text.func_0038CC88")))
void func_0038CC88(struct _IO_FILE *fp, int dummy) {
    struct _IO_marker *mark;
    if (fp->_IO_buf_base && !(fp->_flags & 1)) {
        UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_buf_base);
        fp->_IO_buf_base = fp->_IO_buf_end = 0;
    }

    for (mark = fp->_markers; mark != 0; mark = mark->_next)
        mark->_sbuf = 0;

    if (fp->_IO_save_base) {
        UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_save_base);
        fp->_IO_save_base = 0;
    }

    _IO_un_link(fp);
}
