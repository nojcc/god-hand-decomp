/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

extern long func_003AE008(void *, int, long, int);	/* _lseek_r */

__attribute__((section(".text.__sseek")))
long __sseek(void *cookie, long offset, int whence)
{
  register FILE *fp = (FILE *) cookie;
  register long ret;

  ret = func_003AE008 (fp->_data, fp->_file, (long) offset, whence);
  if (ret == -1L)
    fp->_flags &= ~__SOFF;
  else
    {
      fp->_flags |= __SOFF;
      fp->_offset = ret;
    }
  return ret;
}
