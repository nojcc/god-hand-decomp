/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

extern long func_003AE068(void *, int, char *, int);	/* _read_r */

__attribute__((section(".text.__sread")))
int __sread(void *cookie, char *buf, int n)
{
  register FILE *fp = (FILE *) cookie;
  register int ret;

  ret = func_003AE068(fp->_data, fp->_file, buf, n);
  /* if the read succeeded, update the current offset */

  if (ret >= 0)
    fp->_offset += ret;
  else
    fp->_flags &= ~__SOFF;	/* paranoia */
  return ret;
}
