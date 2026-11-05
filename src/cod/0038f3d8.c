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

struct stat {
    unsigned int st_dev;      /* 0x00 */
    unsigned int st_mode;     /* 0x04 */
    unsigned int st_nlink;    /* 0x08 */
    unsigned int st_uid;      /* 0x0C */
    long st_size;             /* 0x10 */
    char _pad18[0x30];        /* 0x18 */
    long st_blksize;          /* 0x48 */
    char _pad50[0x20];        /* 0x50 */
};

extern void (*D_003F5518)(void);   /* _IO_cleanup_registration_needed */
extern int func_003B0448(int fd);  /* isatty */

/* libio filedoalloc.c :: _IO_file_doallocate */
__attribute__((section(".text._IO_file_doallocate")))
int _IO_file_doallocate(struct _IO_FILE *fp) {
  _IO_size_t size;
  int couldbetty;
  char *p;
  struct stat st;

  if (D_003F5518)
    (*D_003F5518) ();

  if (fp->_fileno < 0 || (*fp->vtable->__stat.pfn)(fp, &st) < 0)
    {
      couldbetty = 0;
      size = 1024;
    }
  else
    {
      couldbetty = (st.st_mode & 0xF000) == 0x2000;
      size = st.st_blksize <= 0 ? 1024 : st.st_blksize;
    }
  do {
      p = (char*)func_003A7C70(size);
      if (p == 0)
        return -1;
  } while (0);
  func_0038C768(fp, p, p + size, 1);
  if (couldbetty && func_003B0448(fp->_fileno))
    fp->_flags |= 0x200;
  return 1;
}
