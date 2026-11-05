/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void _IO_un_link(struct _IO_FILE *fp);

extern int open(const char *path, int flags, int prot);  /* open */
#define EINVAL 22

/* libio fileops.c :: _IO_file_fopen */
__attribute__((section(".text.func_00392830")))
struct _IO_FILE *func_00392830(struct _IO_FILE *fp, const char *filename, const char *mode) {
  int oflags = 0, omode;
  int read_write, fdesc;
  int oprot = 0666;
  if (fp->_fileno >= 0)
    return 0;
  switch (*mode++)
    {
    case 'r':
      omode = 0;
      read_write = 8;
      break;
    case 'w':
      omode = 1;
      oflags = 0x200|0x400;
      read_write = 4;
      break;
    case 'a':
      omode = 1;
      oflags = 0x200|0x8;
      read_write = 4|0x1000;
      break;
    default:
      errno = EINVAL;
      return 0;
    }
  if (mode[0] == '+' || (mode[0] == 'b' && mode[1] == '+'))
    {
      omode = 2;
      read_write &= 0x1000;
    }
  fdesc = open(filename, omode|oflags, oprot);
  if (fdesc < 0)
    return 0;
  fp->_fileno = fdesc;
  fp->_flags = (fp->_flags & ~(4+8+0x1000)) | (read_write & (4+8+0x1000));
  if (read_write & 0x1000)
    if ((*fp->vtable->__seekoff.pfn)(fp, (_IO_ssize_t)0, 2, 1|2)
        == -1 && errno != ESPIPE)
      return 0;
  _IO_link_in (fp);
  return fp;
}
