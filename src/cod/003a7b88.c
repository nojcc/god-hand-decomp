/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

extern void *func_003A7C70(unsigned int);	/* malloc */

__attribute__((section(".text.func_003A7B88")))
int func_003A7B88(void (*fn)(void))
{
  register struct _atexit *p;

  if ((p = _REENT->_atexit) == 0)
    _REENT->_atexit = p = &_REENT->_atexit0;
  if (p->_ind >= _ATEXIT_SIZE)
    {
      if ((p = (struct _atexit *) func_003A7C70 (sizeof *p)) == 0)
	return -1;
      p->_ind = 0;
      do { } while (0);
      *(struct _atexit * volatile *) &p->_next = _REENT->_atexit;
      do { } while (0);
      _REENT->_atexit = p;
    }
  p->_fns[p->_ind++] = fn;
  return 0;
}
