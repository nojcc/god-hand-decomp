/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

__attribute__((section(".text.func_003A6830")))
int func_003A6830(struct _reent *ptr, register int (*function)(FILE *))
{
  register FILE *fp;
  register int n, ret = 0;
  register struct _glue *g;

  for (g = &ptr->__sglue; g != 0; g = g->_next)
    for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
      if (fp->_flags != 0)
	ret |= (*function) (fp);

  return ret;
}
