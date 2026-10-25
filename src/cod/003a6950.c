/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/makebuf.c -- __smakebuf. */

extern int func_003ADFA8(void *, int, void *);	/* _fstat_r */

__attribute__((section(".text.__smakebuf")))
void __smakebuf(register FILE *fp)
{
  struct stat st;

  if (fp->_flags & __SNBF)
    {
      fp->_bf._base = fp->_p = fp->_nbuf;
      fp->_bf._size = 1;
      return;
    }
  if (fp->_file < 0 || func_003ADFA8 (fp->_data, fp->_file, &st) < 0)
    {
      /* do not try to optimise fseek() */
      fp->_flags |= __SNPT;
    }
  else
    {
      if (S_ISREG (st.st_mode) && fp->_seek == __sseek)
	{
	  fp->_flags |= __SOPT;
	  fp->_blksize = BUFSIZ;
	}
      else
	fp->_flags |= __SNPT;
    }

  fp->_flags |= __SNBF;
  fp->_bf._base = fp->_p = fp->_nbuf;
  fp->_bf._size = 1;
}
