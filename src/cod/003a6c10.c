/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

__attribute__((section(".text.func_003A6C10")))
int func_003A6C10(register FILE *fp)
{
  if (__srefill (fp) == 0)
    {
      fp->_r--;
      return *fp->_p++;
    }
  return EOF;
}
