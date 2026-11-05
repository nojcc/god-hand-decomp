/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void _IO_un_link(struct _IO_FILE *fp);

/* libio fileops.c :: _IO_file_init */
__attribute__((section(".text._IO_file_init")))
void _IO_file_init(struct _IO_FILE *fp) {
    fp->_offset = -1;
    fp->_flags |= 0x240C;

    _IO_link_in(fp);
    fp->_fileno = -1;
}
