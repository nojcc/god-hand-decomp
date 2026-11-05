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

/* libio genops.c :: _IO_default_doallocate */
__attribute__((section(".text._IO_default_doallocate")))
int _IO_default_doallocate(struct _IO_FILE *fp) {
    char *buf;

    do {
        buf = (char*)func_003A7C70(1024);
        if (buf == 0)
            return -1;
    } while (0);
    func_0038C768(fp, buf, buf+1024, 1);
    return 1;
}
