/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

__attribute__((section(".text.fclose")))
int fclose(register FILE *fp)
{
  int r;

  if (fp == 0)
    return (0);

  CHECK_INIT (fp);

  if (fp->_flags == 0)
    return (0);
  r = fp->_flags & __SWR ? fflush (fp) : 0;
  if (fp->_close != 0 && (*fp->_close) (fp->_cookie) < 0)
    r = EOF;
  fp->_flags = 0;
  return (r);
}
