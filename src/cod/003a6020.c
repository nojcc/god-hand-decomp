/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/fflush.c -- fflush. */

__attribute__((section(".text.fflush")))
int fflush(register FILE *fp)
{
  register unsigned char *p;
  register int n, t;

  if (fp == 0)
    return func_003A6830 (_REENT, fflush);

  CHECK_INIT (fp);

  t = fp->_flags;
  if ((t & __SWR) == 0)
    return 0;

  if ((p = fp->_bf._base) == 0)
    return 0;

  n = fp->_p - p;		/* write this much */

  /*
   * Set these immediately to avoid problems with longjmp
   * and to allow exchange buffering (via setvbuf) in user
   * write function.
   */
  fp->_p = p;
  fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;

  while (n > 0)
    {
      t = (*fp->_write) (fp->_cookie, (char *) p, n);
      if (t <= 0)
	{
	  fp->_flags |= __SERR;
	  return EOF;
	}
      p += t;
      n -= t;
    }
  return 0;
}
