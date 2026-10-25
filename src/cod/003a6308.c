/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/fread.c -- fread. */

extern void *func_003A62D8(void *, const void *, unsigned int);	/* memcpy */

__attribute__((section(".text.func_003A6308")))
size_t func_003A6308(void *buf, size_t size, size_t count, register FILE *fp)
{
  register size_t resid;
  register char *p;
  register int r;
  size_t total;

  if ((resid = count * size) == 0)
    return 0;
  if (fp->_r < 0)
    fp->_r = 0;
  total = resid;
  p = buf;
  while (resid > (r = fp->_r))
    {
      (void) func_003A62D8 ((void *) p, (void *) fp->_p, (size_t) r);
      fp->_p += r;
      p += r;
      resid -= r;
      if (__srefill (fp))
	{
	  /* no more input: return partial result */
	  return (total - resid) / size;
	}
    }
  (void) func_003A62D8 ((void *) p, (void *) fp->_p, resid);
  fp->_r -= resid;
  fp->_p += resid;
  return count;
}
