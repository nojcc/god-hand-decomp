/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void _IO_un_link(struct _IO_FILE *fp);

/* libio fileops.c :: _IO_file_attach */
__attribute__((section(".text._IO_file_attach")))
struct _IO_FILE *_IO_file_attach(struct _IO_FILE *fp, int fd) {
    if (fp->_fileno >= 0)
        return 0;
    fp->_fileno = fd;
    fp->_flags &= ~(4 + 8);
    fp->_flags |= 0x40;
    fp->_offset = -1;
    if ((*fp->vtable->__seekoff.pfn)(fp, (_IO_ssize_t)0, 1, 1 | 2)
        == -1 && errno != ESPIPE)
        return 0;
    return fp;
}
