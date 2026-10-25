/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

extern long func_003AE008(void *, int, long, int);	/* _lseek_r */
extern long func_003AE128(void *, int, char const *, int);	/* _write_r */

__attribute__((section(".text.__swrite")))
int __swrite(void *cookie, char const *buf, int n)
{
  register FILE *fp = (FILE *) cookie;

  if (fp->_flags & __SAPP)
    (void) func_003AE008 (fp->_data, fp->_file, (int) 0, SEEK_END);
  fp->_flags &= ~__SOFF;	/* in case FAPPEND mode is set */
  return func_003AE128 (fp->_data, fp->_file, buf, n);
}
