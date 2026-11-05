/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void _IO_un_link(struct _IO_FILE *fp);

extern int _IO_sputbackc(struct _IO_FILE *fp, int c);

/* libio ioungetc.c :: _IO_ungetc */
__attribute__((section(".text.func_0038EAB0")))
int func_0038EAB0(int c, struct _IO_FILE *fp) {
    int result;
    if (c == -1)
        return -1;
    result = _IO_sputbackc(fp, (unsigned char) c);
    return result;
}
